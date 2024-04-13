//
// Created by Naokitsu on 4/1/2024.
//

#include "embers/application.h"

#include <GLFW/glfw3.h>
#include <stdexcept>

namespace embers::application {
    Application::Application() {
        int ret = glfwInit();
        if (ret != GLFW_TRUE) {
            glfwTerminate();
            // deconstructor won't be called
            throw std::runtime_error("Couldn't initialize glfw");
        }
        valid = true;
    }

    Application::~Application() {
        if (valid) {
            glfwTerminate();
        }
    }

    Application::Application(embers::application::Application &&other) noexcept {
        name_ = other.name_;
        valid = true;
        other.valid = false;
    }

    Application &Application::operator=(embers::application::Application &&other) noexcept {
        name_ = other.name_;
        valid = true;
        other.valid = false;
        return *this;
    }
}



