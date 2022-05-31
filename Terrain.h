#ifndef TERRAIN_H
#define TERRAIN_H

#include <memory>
#include <vector>
#include <string>

#include "GLM.h"
#include "Util.h"
#include "VertexArray.h"
#include "Material.h"
#include "TerrainTextures.h"
#include "Image.h"

namespace Terrains
{
	constexpr auto SIZE = 500;
	constexpr f32 MAX_HEIGHT = 37.0f;
	constexpr u32 MAX_PIXEL_COLOR = 0 << 24 | 255 << 16 | 255 << 8 | 255;

	class Terrain
	{
	public:
		Terrain(const std::string& hMapPath, const glm::vec2& position, const TerrainTextures& textures,
			const Renderer::Material& material = Renderer::Material());

		glm::vec2 position;
		TerrainTextures textures;
		Renderer::Material material;
		std::shared_ptr<Renderer::VertexArray> vao;
		s32 vertexCount;
	private:
		f32 CalculateHeight(Util::Image2D& hMap, int x, int z);
		glm::vec3 CalculateNormal(Util::Image2D& hMap, int x, int z);
	};
}

#endif // TERRAIN_H