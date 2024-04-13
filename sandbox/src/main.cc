//
// Created by Naokitsu on 3/22/2024.
//

#include "iostream"
#include "embers/window.h"

#define EMBERS_ENABLE_DEBUG
#include <embers/logger.h>
#include <embers/assertions.h>
#include <embers/application.h>

class Sandbox : public embers::application::Application {
  std::unique_ptr<embers::window::Window> window_;
  std::unique_ptr<embers::window::Window> window2_;
public:
    Sandbox() : embers::application::Application() {
        auto builder = embers::window::Window::Builder()
                .Name("Sandbox")
                .Location(200,200);

        window_ = builder.Build(*this);
        window2_ = builder.Build(*this);
      name_ = "Sandbox"; // It shall be 'static, so outlive anyway
    };
    ~Sandbox() override = default;

    void Run() override {
        while (true) {
          window_->Update();
          window2_->Update();
        }
    }
};


int main() {
  Sandbox app;
  app.Run();
  return 0;
}
























