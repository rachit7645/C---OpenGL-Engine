#ifndef RACHIT_GL_H
#define RACHIT_GL_H

#include <GL/glew.h>

#include "GLM.h"

// Quick wrappers around OpenGL calls
namespace GL
{
	GLint GetIntegerv(GLenum param);

	// glDebugMessageCallback Function
	void CheckErrors
	(
		GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* userParam
	);

	// Initialize OpenGL info
	void Init(const glm::ivec2& dimensions);
	// Log debug information
	void LogDebugInfo();
}

#endif