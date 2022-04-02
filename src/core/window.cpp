#include "core.h"

namespace yes
{
    void Window::Init(const char *title, int width, int height)
    {
        if (!glfwInit())
        {
            Logger::Error(CORE_LOGGER, "[GLFW] Failed to initialize GLFW");
            return;
        }

        glfwSetErrorCallback(error_callback);

        glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

        // OpenGL
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);

        if (!window)
        {
            Logger::Error(CORE_LOGGER, "[GLFW] Failed to create window");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);

        this->width = width;
        this->height = height;
        this->title = title;

        glfwSetWindowUserPointer(window, this);

        glfwSetWindowPosCallback(window, window_position_callback);
        glfwSetWindowSizeCallback(window, window_size_callback);
        glfwSetWindowCloseCallback(window, window_close_callback);
        glfwSetWindowRefreshCallback(window, window_refresh_callback);
        glfwSetWindowFocusCallback(window, window_focus_callback);
        glfwSetWindowIconifyCallback(window, window_iconify_callback);
        glfwSetWindowMaximizeCallback(window, window_maximize_callback);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        glfwSetWindowContentScaleCallback(window, content_scale_callback);
    }

    void Window::Update()
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void Window::Destroy()
    {
        glfwDestroyWindow(window);
    }

    void Window::Close()
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    void Window::ChangeTitle(const char *targetTitle)
    {
        glfwSetWindowTitle(window, targetTitle);
        title = targetTitle;
    }

    Window *Window::GetWindow(GLFWwindow *window)
    {
        if (!window)
            return NULL;

        return static_cast<Window *>(glfwGetWindowUserPointer(window));
    }

    Window *Window::GetCurrent()
    {
        GLFWwindow *window = glfwGetCurrentContext();
        return GetWindow(window);
    }

    void Window::OnError(int error, const char *description)
    {
        Logger::Error(CORE_LOGGER, "[GLFW] Window: \"{}\"\n{}", title, description);
        OnErrorEvent(error, description);
    }

    void Window::OnReposition(int x, int y)
    {
        Logger::Trace(CORE_LOGGER, "[GLFW] Window: \"{}\" Position: ({}, {})", title, x, y);
        OnRepositionEvent(x, y);
    }

    void Window::OnResize(int width, int height)
    {
        this->width = width;
        this->height = height;
        OnResizeEvent(width, height);
        
        Logger::Trace(CORE_LOGGER, "[GLFW] Window: \"{}\" Size: {}x{}", title, width, height);
    }

    void Window::OnClose()
    {
        OnCloseEvent();
        Logger::Trace(CORE_LOGGER, "[GLFW] Window: \"{}\" closed", title);
    }

    void Window::OnRefresh()
    {
        OnRefreshEvent();
        Logger::Trace(CORE_LOGGER, "[GLFW] Window: \"{}\" Refresh", title);
    }

    void Window::OnFocus(bool focus)
    {
        OnFocusEvent(focus);
        Logger::Trace(CORE_LOGGER, "[GLFW] Window: \"{}\" focus: {}", title, focus);
    }

    void Window::OnIconify(bool iconified)
    {
        OnIconifyEvent(iconified);
        Logger::Trace(CORE_LOGGER, "[GLFW] Window: \"{}\" iconified: {}", title, iconified);
    }

    void Window::OnMaximize(bool maximized)
    {
        OnMaximizeEvent(maximized);
        Logger::Trace(CORE_LOGGER, "[GLFW] Window: \"{}\" maximized: {}", title, maximized);
    }

    void Window::OnFramebufferResize(int width, int height)
    {
        OnFramebufferResizeEvent(width, height);
        Logger::Trace(CORE_LOGGER, "[GLFW] Window: \"{}\" framebuffer resize: {}x{}", title, width, height);
    }

    void Window::OnContentRescale(float xscale, float yscale)
    {
        OnContentRescaleEvent(xscale, yscale);
        Logger::Trace(CORE_LOGGER, "[GLFW] Window: \"{}\" content rescale: {}x{}", title, xscale, yscale);
    }

    void Window::error_callback(int error, const char *description)
    {
        Window *window = GetCurrent();
        if (!window)
        {
            Logger::Error(CORE_LOGGER, "[GLFW] {}", description);
            return;
        }

        window->OnError(error, description);
    }

    void Window::window_position_callback(GLFWwindow *window, int x, int y)
    {
        Window *w = GetWindow(window);
        w->OnReposition(x, y);
    }

    void Window::window_size_callback(GLFWwindow *window, int width, int height)
    {
        Window *userwindow = GetWindow(window);
        userwindow->OnResize(width, height);
    }

    void Window::window_close_callback(GLFWwindow *window)
    {
        Window *userwindow = GetWindow(window);
        userwindow->OnClose();
    }

    void Window::window_refresh_callback(GLFWwindow *window)
    {
        Window *userwindow = GetWindow(window);
        userwindow->OnRefresh();
    }

    void Window::window_focus_callback(GLFWwindow *window, int focused)
    {
        Window *userwindow = GetWindow(window);
        userwindow->OnFocus(focused);
    }

    void Window::window_iconify_callback(GLFWwindow *window, int iconified)
    {
        Window *userwindow = GetWindow(window);
        userwindow->OnIconify(iconified);
    }

    void Window::window_maximize_callback(GLFWwindow *window, int maximized)
    {
        Window *userwindow = GetWindow(window);
        userwindow->OnMaximize(maximized);
    }

    void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height)
    {
        Window *userwindow = GetWindow(window);
        userwindow->OnFramebufferResize(width, height);
    }

    void Window::content_scale_callback(GLFWwindow *window, float xscale, float yscale)
    {
        Window *userwindow = GetWindow(window);
        userwindow->OnContentRescale(xscale, yscale);
    }
}
