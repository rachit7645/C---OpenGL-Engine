#ifndef TEXTURE_H
#define TEXTURE_H

#include <array>
#include <string_view>
#include <GL/glew.h>

#include "Util.h"

namespace Renderer
{
	constexpr auto TEXTURE_LOD_BIAS = -0.5f;

	// Note: This class can be constructed in a pipeline-like form
	class Texture
	{
	public:
		// Default constructor
		Texture() = default;
		// Loads a texture into memory, then an OpenGL object
		explicit Texture(const std::string_view path);
		// Loads a cube map texture
		explicit Texture(const std::array<const std::string_view, 6>& files);
		// Destructor 
		virtual ~Texture();

		void Bind()   const;
		void Unbind() const;

		GLuint id   = 0;
		GLenum type = GL_TEXTURE_2D;

		int width    = 0;
		int height   = 0;
		int depth    = 0;
		int channels = 0;
	protected:
		void CreateTexture();

		void SetPixelParameter(GLenum name, GLint param);

		void SetParameter(GLenum name, GLint param);
		void SetParameter(GLenum name, GLfloat param);
		void SetParameter(GLenum name, const GLfloat* param);

		void LoadImageData(u8* data, GLint internalFormat, GLint format, GLint dataType, GLenum target = 0);
		void LoadImageData3D(u8* data, GLint internalFormat, GLint format, GLint dataType, GLenum target = 0);

		void GenerateMipmaps();

		u8* LoadImage(const std::string_view path);
		f32* LoadImageHDR(const std::string_view path);
	public:
		friend class FrameBuffer;
		friend class IBLMaps;
	};
}
#endif