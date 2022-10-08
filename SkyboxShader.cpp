#include "SkyboxShader.h"

using namespace Shader;

constexpr auto VERTEX_PATH = "shaders/skyboxVertexShader.glsl",
	FRAGMENT_PATH = "shaders/skyboxFragmentShader.glsl";

SkyboxShader::SkyboxShader()
	: ShaderProgram(VERTEX_PATH, FRAGMENT_PATH)
{
	GetUniformLocations();
}

void SkyboxShader::GetUniformLocations()
{
	m_uniforms["modelMatrix"] = GetUniformLocation("modelMatrix");
}

void SkyboxShader::LoadModelMatrix(const glm::mat4& matrix)
{
	LoadUniform(m_uniforms["modelMatrix"], matrix);
}