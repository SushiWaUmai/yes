#pragma once

namespace yes
{
    template class ShaderSource<GL_VERTEX_SHADER>;
    template class ShaderSource<GL_FRAGMENT_SHADER>;
    template class ShaderSource<GL_GEOMETRY_SHADER>;

    typedef ShaderSource<GL_VERTEX_SHADER> VertexShader;
    typedef ShaderSource<GL_FRAGMENT_SHADER> FragmentShader;
    typedef ShaderSource<GL_GEOMETRY_SHADER> GeometryShader;
} // namespace yes
