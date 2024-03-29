#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "core/ref.h"

#include "utils/log.h"
#include "utils/fileloader.h"
#include "utils/event.h"

#include "graphics/texture.h"

#include "graphics/shader/shaderdata.h"
#include "graphics/shader/shadersource.h"
#include "graphics/shader/shader.h"
#include "graphics/shader/shadertypes.h"

#include "graphics/buffer/buffer.h"
#include "graphics/buffer/buffertypes.h"
#include "graphics/buffer/vertexarray.h"
#include "graphics/buffer/framebuffer.h"

#include "graphics/renderer.h"

#include "core/window.h"
#include "core/application.h"
