//
// Created by Naokitsu on 3/25/2024.
//

#include "embers/window.h"
#include "embers/logger.h"

#include <GLFW/glfw3.h>

namespace embers::window {
    Window::Builder::Builder() = default;
    Window::Builder &Window::Builder::Location(u32f x, u32f y) {
        x_ = x;
        y_ = y;
        return *this;
    }

    Window::Builder &Window::Builder::Dimensions(u32f height, u32f width) {
        width_ = width;
        height_ = height;
        return *this;
    }

    Window::Builder &Window::Builder::Name(const char *name) {
        name_ = name;
        return *this;
    }

    std::unique_ptr<Window> Window::Builder::Build(application::Application &application) {
        return std::make_unique<Window>(
                application,
                x_,
                y_,
                width_,
                height_,
                name_
                );
    }
}

namespace embers::window {
    Window::Window() :x_(0), y_(0), height_(0), width_(0), glfw_window_(nullptr), valid_(false) {}

    Window::Window(const application::Application &application, u32f x, u32f y, u32f width, u32f height,
                   const char *name) : x_(x), y_(y), width_(width), height_(height), name_(name) {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfw_window_ = glfwCreateWindow(width, height, name, nullptr, nullptr);
        valid_ = true;
    }
    Window::~Window() {
        glfwDestroyWindow(static_cast<GLFWwindow *>(glfw_window_));
    }

    Window::Window(embers::window::Window &&other) noexcept {
        x_ = other.x_;
        y_ = other.y_;
        height_ = other.height_;
        width_ = other.width_;
        name_ = other.name_;
        glfw_window_ = other.glfw_window_;

        valid_ = other.valid_;
        other.valid_ = false;
    }

    Window &Window::operator=(embers::window::Window &&other) noexcept {
        x_ = other.x_;
        y_ = other.y_;
        height_ = other.height_;
        width_ = other.width_;
        name_ = other.name_;
        glfw_window_ = other.glfw_window_;

        valid_ = other.valid_;
        other.valid_ = false;
        return *this;
    }
}

bool embers::window::Window::Update() {
    glfwPollEvents();
    return true;
}
