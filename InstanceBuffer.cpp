#include "InstanceBuffer.h"

#include "Util.h"
#include "Maths.h"

using namespace Renderer;

using Detail::InstancedDataGLSL;
using Entities::Entity;

using DataVector = InstanceBuffer::DataVector;

InstanceBuffer::InstanceBuffer()
	: ShaderStorageBuffer(4, NUM_MAX_ENTITIES * sizeof(InstancedDataGLSL), GL_DYNAMIC_DRAW)
{
}

void InstanceBuffer::LoadInstanceData(const EntityVector& entities)
{
	auto data = GenerateData(entities);

	glBindBuffer(GL_SHADER_STORAGE_BUFFER, id);
	glBufferSubData
	(
		GL_SHADER_STORAGE_BUFFER,
		static_cast<GLintptr>(0),
		GetSize(data),
		reinterpret_cast<const void*>(&data[0])
	);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

GLsizeiptr InstanceBuffer::GetSize(const DataVector& data)
{
	return static_cast<GLsizeiptr>(data.size() * sizeof(InstancedDataGLSL));
}

DataVector InstanceBuffer::GenerateData(const EntityVector& entities)
{
	DataVector data(entities.size());

	for (usize i = 0; i < entities.size(); ++i)
	{
		data[i].modelMatrix = Maths::CreateModelMatrix
		(
			entities[i]->position,
			entities[i]->rotation,
			entities[i]->scale
		);
	}

	return data;
}