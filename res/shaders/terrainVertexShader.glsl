#version 420 core

const float FOG_DENSITY	   = 0.0035f;
const float FOG_GRADIENT   = 1.5f;
const int   MAX_LIGHTS     = 4; 

struct Light
{
	vec4 position;
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	vec4 attenuation;
};

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 textureCoords;
layout(location = 2) in vec3 normal;

layout(std140, binding = 0) uniform Matrices
{
	uniform mat4 projectionMatrix;
	uniform mat4 viewMatrix;
	uniform vec4 cameraPos;
};

layout(std140, binding = 1) uniform Lights
{
	Light lights[MAX_LIGHTS];
};

uniform mat4 modelMatrix;

out float visibility;
out vec2  txCoords;
out vec3  unitNormal;
out vec3  unitCameraVector;
out vec4  worldPosition;
out vec3  unitLightVector[MAX_LIGHTS];

void CalculateLighting();
void CalculateVisibility(vec4 positionRelativeToCamera);

void main() 
{
	worldPosition = modelMatrix * vec4(position, 1.0f);
	vec4 positionRelativeToCamera = viewMatrix * worldPosition;
	gl_Position = projectionMatrix * positionRelativeToCamera;
	txCoords = textureCoords;
	
	CalculateLighting();
	CalculateVisibility(positionRelativeToCamera);
}

void CalculateLighting()
{
	unitNormal = normalize((modelMatrix * vec4(normal, 0.0f)).xyz);
	unitCameraVector = normalize(cameraPos.xyz - worldPosition.xyz);

	for (int i = 0; i < MAX_LIGHTS; ++i)
	{
		unitLightVector[i] = normalize(lights[i].position.xyz - worldPosition.xyz);
	}
}

void CalculateVisibility(vec4 positionRelativeToCamera)
{
	float distance = length(positionRelativeToCamera.xyz);
	visibility = exp(-pow((distance * FOG_DENSITY), FOG_GRADIENT));
	visibility = clamp(visibility, 0.0f, 1.0f);
}