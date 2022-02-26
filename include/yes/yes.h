#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <iostream>

#include "../../src/core/base.h"
#include "../../src/core/window.h"
#include "../../src/core/application.h"

#include "../../src/graphics/buffer/buffer.h"
#include "../../src/graphics/buffer/vertexbuffer.h"
#include "../../src/graphics/buffer/indexbuffer.h"
#include "../../src/graphics/buffer/vertexarray.h"
#include "../../src/graphics/shadertypes.h"
#include "../../src/graphics/shader.h"

#include "../../src/utils/fileloader.h"