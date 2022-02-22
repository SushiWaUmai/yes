#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

int main(void)
{
    glfwInit();
    gladLoadGL();

    glfwTerminate();

    return 0;
}
