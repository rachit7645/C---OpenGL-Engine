#ifndef MATRIX_BUFFER_H
#define MATRIX_BUFFER_H

#include "GLM.h"
#include "UniformBuffer.h"
#include "Camera.h"

namespace Renderer
{
	class MatrixBuffer : public UniformBuffer
	{
	public:
		MatrixBuffer();

		void LoadView(const Entities::Camera& camera);
		void LoadProjection(const glm::mat4& projection);
	};

	namespace Detail
	{
		struct MatrixBufferGLSL
		{
			alignas(16) glm::mat4 projectionMatrix;
			alignas(16) glm::mat4 viewMatrix;
		};
	}
}

#endif