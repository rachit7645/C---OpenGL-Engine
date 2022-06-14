#ifndef TERRAIN_SHADER_H
#define TERRAIN_SHADER_H

#include <unordered_map>

#include "GLM.h"
#include "Shader.h"
#include "Camera.h"
#include "Maths.h"
#include "Light.h"
#include "Material.h"
#include "Terrain.h"

namespace Shader
{
	constexpr auto TERRAIN_VERTEX_SHADER_PATH = "shaders/terrainVertexShader.glsl",
		TERRAIN_FRAGMENT_SHADER_PATH = "shaders/terrainFragmentShader.glsl";

	class TerrainShader : public ShaderProgram
	{
	public:
		TerrainShader();

		// Matrix loading functions
		void LoadTransformationMatrix(const glm::mat4& matrix);

		// Material and object loading functions
		void LoadMaterials(const Renderer::Material& material);
		void LoadSkyColour(const glm::vec4& skyColour);
		void ConnectTextureUnits();

		void GetUniformLocations() override;
	private:
		std::unordered_map<const char*, u32> uniforms;
	};
}

#endif