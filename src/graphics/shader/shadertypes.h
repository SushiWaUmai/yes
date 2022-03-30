#pragma once

namespace yes
{
    template class ShaderSource<GL_VERTEX_SHADER>;
    template class ShaderSource<GL_FRAGMENT_SHADER>;

    typedef ShaderSource<GL_VERTEX_SHADER> VertexShader;
    typedef ShaderSource<GL_FRAGMENT_SHADER> FragmentShader;
} // namespace yes
