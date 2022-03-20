#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "core/base.h"

#include "graphics/shadertypes.h"
#include "graphics/buffer/buffer.h"
#include "graphics/buffer/vertexbuffer.h"
#include "graphics/buffer/indexbuffer.h"
#include "graphics/buffer/vertexarray.h"
#include "graphics/shader.h"
#include "graphics/renderer.h"
#include "graphics/texture.h"

#include "utils/fileloader.h"

#include "core/window.h"
#include "core/application.h"