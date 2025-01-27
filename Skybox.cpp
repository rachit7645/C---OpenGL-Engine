#include "Skybox.h"

#include <vector>
#include <array>
#include <string_view>

using namespace Entities;

using Renderer::VertexArray;
using Renderer::Texture;

using VAO = Skybox::VAO;

constexpr f32 SKYBOX_SIZE = 500.0f;

Skybox::Skybox()
    : vao(Skybox::LoadVAO())
{
    constexpr std::array<const std::string_view, 6> SKYBOX_TEXTURE_FILES =
    {
        "gfx/right.png",
        "gfx/left.png",
        "gfx/top.png",
        "gfx/bottom.png",
        "gfx/back.png",
        "gfx/front.png"
    };

    cubeMap = std::make_shared<Texture>(SKYBOX_TEXTURE_FILES);
}

Skybox::Skybox(TxPtr texture)
    : vao(Skybox::LoadVAO()),
      cubeMap(std::move(texture))
{
}

VAO Skybox::LoadVAO()
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

    return std::make_shared<VertexArray>(3, SKYBOX_VERTICES);
}