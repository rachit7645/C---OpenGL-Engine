#include "LightingShader.h"

// Using namespaces
using namespace Shader;

// Constants
constexpr auto VERTEX_PATH = "shaders/LightingVS.glsl",
	FRAGMENT_PATH = "shaders/LightingFS.glsl";

LightingShader::LightingShader()
	: ShaderProgram(VERTEX_PATH, FRAGMENT_PATH)
{
	// Query uniform locations
	GetUniformLocations();
}

void LightingShader::GetUniformLocations()
{
	// Uniforms
	m_uniforms["gNormal"]       = GetUniformLocation("gNormal");
	m_uniforms["gAlbedo"]       = GetUniformLocation("gAlbedo");
	m_uniforms["gEmmisive"]     = GetUniformLocation("gEmmisive");
	m_uniforms["gMaterial"]     = GetUniformLocation("gMaterial");
	m_uniforms["gDepth"]        = GetUniformLocation("gDepth");
	m_uniforms["shadowMap"]     = GetUniformLocation("shadowMap");
	m_uniforms["irradianceMap"] = GetUniformLocation("irradianceMap");
	m_uniforms["prefilterMap"]  = GetUniformLocation("prefilterMap");
	m_uniforms["brdfLUT"]       = GetUniformLocation("brdfLUT");
}

void LightingShader::ConnectTextureUnits()
{
	// Connect texture units
	LoadUniform(m_uniforms["gNormal"],       0);
	LoadUniform(m_uniforms["gAlbedo"],       1);
	LoadUniform(m_uniforms["gEmmisive"],     2);
	LoadUniform(m_uniforms["gMaterial"],     3);
	LoadUniform(m_uniforms["gDepth"],        4);
	LoadUniform(m_uniforms["shadowMap"],     5);
	LoadUniform(m_uniforms["irradianceMap"], 6);
	LoadUniform(m_uniforms["prefilterMap"],  7);
	LoadUniform(m_uniforms["brdfLUT"],       8);
}