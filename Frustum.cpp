#include "Frustum.h"

#include <algorithm>

#include "RenderConstants.h"
#include "Maths.h"
#include "Log.h"

// Using namespaces
using namespace Maths;

// Usings
using Entities::Entity;
using Entities::Camera;
using Maths::AABB;
using Maths::Plane;

// TODO: Only update frustum if camera changes

Frustum::Frustum()
{
	// Create projection matrix (must be the same as the one used for rendering)
	m_projection = glm::perspective
	(
		glm::radians(Renderer::FOV),
		Renderer::ASPECT_RATIO,
		Renderer::NEAR_PLANE,
		Renderer::FAR_PLANE
	);
}

bool Frustum::IsVisible(const Entity& entity, const Camera& camera)
{
	// Get meshes
	const auto& meshes = entity.model->meshes;
	// Update frustum
	Update(entity, camera);
	// Return true if any meshes are visible
	return std::any_of(meshes.begin(), meshes.end(), [this] (const auto& mesh)
	{
		// Return true if mesh is visible
		return IsInFrustum(mesh.aabb.Transform(m_model));
	});
}

bool Frustum::IsInFrustum(const AABB& aabb) const
{
    // For each plane
	for (const auto& plane : m_planes)
    {
        // Check plane intersection
        if
        (
            IsCornerNotInPlane(0, plane, aabb) &&
            IsCornerNotInPlane(1, plane, aabb) &&
            IsCornerNotInPlane(2, plane, aabb) &&
            IsCornerNotInPlane(3, plane, aabb) &&
            IsCornerNotInPlane(4, plane, aabb) &&
            IsCornerNotInPlane(5, plane, aabb) &&
            IsCornerNotInPlane(6, plane, aabb) &&
            IsCornerNotInPlane(7, plane, aabb)
        )
        {
            // AABB is not visible
            return false;
        }
    }

    // AABB is (potentially) visible
    return true;
}

bool Frustum::IsCornerNotInPlane(usize corner, const Plane& plane, const AABB& aabb) const
{
    // Intersection test
    return glm::dot(plane.equation, glm::vec4(aabb.corners[corner], 1.0f)) < 0.0f;
}

void Frustum::Update(const Entity& entity, const Camera& camera)
{
	// Create model matrix
	m_model = Maths::CreateModelMatrix(entity.position, entity.rotation, entity.scale);
	// Create view matrix
	m_view = Maths::CreateViewMatrix(camera);

	// Combine matrices (transpose to left-handed)
	auto matrix = glm::transpose(m_projection * m_view);

	// Calculate planes
	m_planes[PLANE_LEFT]   = Maths::Plane(matrix[3] + matrix[0]);
	m_planes[PLANE_RIGHT]  = Maths::Plane(matrix[3] - matrix[0]);
	m_planes[PLANE_BOTTOM] = Maths::Plane(matrix[3] + matrix[1]);
	m_planes[PLANE_TOP]    = Maths::Plane(matrix[3] - matrix[1]);
	m_planes[PLANE_NEAR]   = Maths::Plane(matrix[3] + matrix[2]);
	m_planes[PLANE_FAR]    = Maths::Plane(matrix[3] - matrix[2]);
}