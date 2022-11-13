#include "Skybox.h"

#include <vector>
#include <array>
#include <string_view>

using namespace Entities;

using Renderer::VertexArray;
using Renderer::Texture;

constexpr f32 SKYBOX_SIZE = 500.0f;

Skybox::Skybox()
{
	const std::vector<f32> SKYBOX_VERTICES =
	{
		-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,

		-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
		-SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,

		SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,

		-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
		-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,

		-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,

		-SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE
	};

	constexpr std::array<const std::string_view, 6> SKYBOX_TEXTURE_FILES =
	{
		"gfx/right.png",
		"gfx/left.png",
		"gfx/top.png",
		"gfx/bottom.png",
		"gfx/back.png",
		"gfx/front.png"
	};

	vao     = std::make_shared<VertexArray>(3, SKYBOX_VERTICES);
	cubeMap = std::make_shared<Texture>(SKYBOX_TEXTURE_FILES);
}

Skybox::Skybox(TxPtr texture)
	: cubeMap(std::move(texture))
{
	const std::vector<f32> SKYBOX_VERTICES =
	{
		-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,

		-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
		-SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,

		SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,

		-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
		-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,

		-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
		-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,

		-SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
		-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
		SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE
	};

	vao = std::make_shared<VertexArray>(3, SKYBOX_VERTICES);
}