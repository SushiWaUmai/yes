#pragma once
#include "graphics/buffer/buffer.h"

namespace yes
{
    template class Buffer<GL_ARRAY_BUFFER>;
    template class Buffer<GL_ELEMENT_ARRAY_BUFFER>;
    template class Buffer<GL_SHADER_STORAGE_BUFFER>;

    typedef Buffer<GL_ARRAY_BUFFER> VertexBuffer;
    typedef Buffer<GL_ELEMENT_ARRAY_BUFFER> IndexBuffer;
    typedef Buffer<GL_SHADER_STORAGE_BUFFER> ShaderStorageBuffer;
} // namespace yes
