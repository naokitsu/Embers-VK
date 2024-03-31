//
// Created by Naokitsu on 3/22/2024.
//

#include "iostream"
#include "../../embers/src/window.h"

#include <windows.h>

#define EMBERS_ENABLE_DEBUG
#include <embers/logger.h>
#include <embers/assertions.h>
#include <embers/application.h>

class Sandbox : public embers::Application {
  embers::window::Window window_;
  embers::window::Window window2_;
public:
    Sandbox()
    : embers::Application()
        , window_(*this, 100, 100,  600, 400, "Sandbox 1", "sandbox1")
        , window2_(*this, 500, 500,  600, 400, "Sandbox 2", "sandbox2")
    {
      name_ = "Sandbox"; // It shall be 'static, so outlive anyway
      hinstance_ = GetModuleHandle(NULL);
    };
    ~Sandbox() override = default;

    void Run() override {
        while (true) {
          window_.Update();
          window2_.Update();
        }
    }
};


int main() {
  Sandbox app;
  app.Run();
  return 0;
}