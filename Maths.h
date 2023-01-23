#ifndef MATHS_H
#define MATHS_H

#include "GLM.h"
#include "Camera.h"
#include "Util.h"

namespace Maths
{
	// Create standard model matrix
	glm::mat4 CreateModelMatrix(const glm::vec3& translation, const glm::vec3& rotation, f32 scale);
	// Create model matrix with only translation
	glm::mat4 CreateModelMatrixT(const glm::vec3& translation);
	// Create model matrix with only rotation
	glm::mat4 CreateModelMatrixR(const glm::vec3& rotation);
	// Create model matrix with translation and scale
	glm::mat4 CreateModelMatrixTS(const glm::vec3& translation, f32 scale);
	// Create 2D model matrix
	glm::mat4 CreateModelMatrix2D(const glm::vec2& translation, const glm::vec2& scale);
	// Create view matrix from camera
	glm::mat4 CreateViewMatrix(const Entities::Camera& camera);
	// Linear interpolation
	template <typename T>
	T Lerp(T a, T b, T f)
	{
		// Return
		return a + f * (b - a);
	}
}

#endif