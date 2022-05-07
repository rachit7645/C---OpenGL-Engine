#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 textureCoords;
layout(location = 2) in vec3 normal;

uniform mat4 modelMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform vec3 lightPosition;
uniform int useFakeLighting;

out vec2 pass_textureCoords;
out vec3 surfaceNormal;
out vec3 toLightVector;
out vec3 toCameraVector;

void main() 
{
	vec4 worldPosition = modelMatrix * vec4(position, 1.0f);
	gl_Position = projectionMatrix * viewMatrix * worldPosition;
	pass_textureCoords = textureCoords;
	
	vec3 actualNormal = normal;
	if (useFakeLighting == 1)
		actualNormal = vec3(0.0f, 1.0f, 0.0f);

	surfaceNormal = (modelMatrix * vec4(actualNormal, 0.0f)).xyz;
	toLightVector = lightPosition - worldPosition.xyz;
	toCameraVector = (inverse(viewMatrix) * vec4(0.0f, 0.0f, 0.0f, 1.0f)).xyz - worldPosition.xyz;
}