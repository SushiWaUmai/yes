#pragma once
#include "graphics/shader/shadersource.h"

namespace yes
{
    template class ShaderSource<GL_VERTEX_SHADER>;
    template class ShaderSource<GL_FRAGMENT_SHADER>;
    template class ShaderSource<GL_GEOMETRY_SHADER>;
    template class ShaderSource<GL_COMPUTE_SHADER>;

    typedef ShaderSource<GL_VERTEX_SHADER> VertexShader;
    typedef ShaderSource<GL_FRAGMENT_SHADER> FragmentShader;
    typedef ShaderSource<GL_GEOMETRY_SHADER> GeometryShader;
    typedef ShaderSource<GL_COMPUTE_SHADER> ComputeShader;
} // namespace yes
