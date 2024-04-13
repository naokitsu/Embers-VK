//
// Created by Naokitsu on 3/25/2024.
//

#ifndef EMBERS_SRC_WINDOW_H_
#define EMBERS_SRC_WINDOW_H_

#include "embers/platform_detection.h"
#include "embers/application.h"
#include "embers/primitives.h"
#include "embers/glfw_reexport.h"

#include <memory>

namespace embers::window {

class Window {
public:
    class Builder {
        u32f x_ = 0;
        u32f y_ = 0;
        u32f width_ = 800;
        u32f height_ = 600;
        const char *name_ = "Embers Application";
    public:
        Builder();
        Builder &Location(u32f x, u32f y);
        Builder &Dimensions(u32f height, u32f width);
        Builder &Name(const char *name);
        std::unique_ptr<Window> Build(application::Application &application);

    };
private:
  u32f x_;
  u32f y_;
  u32f width_;
  u32f height_;
  const char *name_ = "Embers Application";
  void *glfw_window_; // not a fan of static casts, but i don't want to leak glfw into the user namespace
  bool valid_;
public:
  Window();
  Window(const application::Application &application, u32f x, u32f y, u32f width, u32f height, const char *name);
    Window(const Window &other) = delete;
    Window(Window &&other) noexcept;

    Window &operator=(const Window &other) = delete;
    Window &operator=(Window &&other) noexcept;

    ~Window();
  bool Update();
};
}


#endif //EMBERS_SRC_WINDOW_H_
