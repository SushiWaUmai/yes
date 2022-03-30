#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "core/ref.h"

#include "utils/fileloader.h"

#include "graphics/texture.h"

#include "graphics/shader/shaderdata.h"
#include "graphics/shader/shadersource.h"
#include "graphics/shader/shader.h"

#include "graphics/buffer/buffer.h"
#include "graphics/buffer/vertexbuffer.h"
#include "graphics/buffer/indexbuffer.h"
#include "graphics/buffer/vertexarray.h"
#include "graphics/buffer/framebuffer.h"

#include "graphics/renderer.h"

#include "core/window.h"
#include "core/application.h"
