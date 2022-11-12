#ifndef DIFFUSE_IBL_H
#define DIFFUSE_IBL_H

#include <memory>

#include "FrameBuffer.h"
#include "Texture.h"
#include "VertexArray.h"
#include "GLM.h"

namespace Renderer
{
	class DiffuseIBL
	{
	public:
		// Usings
		using VAO   = std::shared_ptr<VertexArray>;
		using TxPtr = std::shared_ptr<Texture>;
		using FbPtr = std::shared_ptr<FrameBuffer>;
		// Main constructor
		DiffuseIBL();
		// Data
		FbPtr cubeMap;
		FbPtr irradiance;
	private:
		void ConvertToCubeMap();

		void CreateCubeMapFBO(FbPtr& FBO, const glm::ivec2& dimensions);
		void PrepareRender(FbPtr& FBO, VAO& cube);
		void RenderCubeFace(FbPtr& FBO, VAO& cube, usize face);
		void UnbindRender(FbPtr& FBO);

		TxPtr LoadHDRMap();
		VAO   LoadCube();
	};
}

#endif
