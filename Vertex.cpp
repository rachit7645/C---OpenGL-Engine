#include "Vertex.h"

using namespace Renderer;

Vertex::Vertex(const glm::vec3& position, const glm::vec2& txCoord, const glm::vec3& normal)
	: position(position),
	  txCoord(txCoord),
	  normal(normal)
{
}