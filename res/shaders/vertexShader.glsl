#version 330 core

in vec3 position;
in vec2 textureCoords;
in vec3 normals;

uniform mat4 modelMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

uniform vec3 lightPosition;

out vec2 pass_textureCoords;
out vec3 surfaceNormal;
out vec3 toLightVector;

void main() 
{
	vec4 worldPosition = modelMatrix * vec4(position, 1.0f);
	gl_Position = projectionMatrix * viewMatrix * worldPosition;
	pass_textureCoords = textureCoords;
	
	surfaceNormal = (modelMatrix * vec4(normals, 0.0f)).xyz;
	toLightVector = lightPosition - worldPosition.xyz;
}