#version 420 core

layout (location = 0) in vec3 position;

layout(std140, binding = 0) uniform Matrices
{
	uniform mat4 projectionMatrix;
	uniform mat4 viewMatrix;
};
uniform mat4 modelMatrix;

out vec3 textureCoords;

void main()
{
	mat4 editedView = viewMatrix;
	// Disable translation
	editedView[3][0] = 0.0f;
	editedView[3][1] = 0.0f;
	editedView[3][2] = 0.0f;
	// Set the z position to the w position
	// This makes it so that during perspective division z / w = w / w = 1.0f
	// This means that the driver will (hopefully) use early depth test
	gl_Position = (projectionMatrix * editedView * modelMatrix * vec4(position, 1.0f)).xyww;
	textureCoords = position;
}