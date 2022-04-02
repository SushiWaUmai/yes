#pragma once

namespace yes
{
    class Window
    {
    public:
        void Init(const char *title, int width, int height);
        void Update();
        void Destroy();
        void Close();

        void ChangeTitle(const char *title);

        static Window *GetWindow(GLFWwindow *window);
        static Window *GetCurrent();

        inline bool shouldClose() const { return glfwWindowShouldClose(window); }

        Event<void(int, const char *)> OnErrorEvent;
        Event<void(int, int)> OnRepositionEvent;
        Event<void(int, int)> OnResizeEvent;
        Event<void()> OnCloseEvent;
        Event<void()> OnRefreshEvent;
        Event<void(bool)> OnFocusEvent;
        Event<void(bool)> OnIconifyEvent;
        Event<void(bool)> OnMaximizeEvent;
        Event<void(int, int)> OnFramebufferResizeEvent;
        Event<void(float, float)> OnContentRescaleEvent;

    protected:
        GLFWwindow *window;
        int width, height;
        const char *title;

        virtual void OnError(int error, const char *description);

        virtual void OnReposition(int x, int y);
        virtual void OnResize(int width, int height);
        virtual void OnClose();
        virtual void OnRefresh();
        virtual void OnFocus(bool focus);
        virtual void OnIconify(bool iconified);
        virtual void OnMaximize(bool maximized);
        virtual void OnFramebufferResize(int width, int height);
        virtual void OnContentRescale(float xscale, float yscale);

    private:
        static void error_callback(int error, const char *description);

        static void window_position_callback(GLFWwindow *window, int x, int y);
        static void window_size_callback(GLFWwindow *window, int width, int height);
        static void window_close_callback(GLFWwindow *window);
        static void window_refresh_callback(GLFWwindow *window);
        static void window_focus_callback(GLFWwindow *window, int focused);
        static void window_iconify_callback(GLFWwindow *window, int iconified);
        static void window_maximize_callback(GLFWwindow *window, int maximized);
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
        static void content_scale_callback(GLFWwindow *window, float xscale, float yscale);
    };
}
