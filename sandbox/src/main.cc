//
// Created by Naokitsu on 3/22/2024.
//

#include "iostream"
#define WW_DEBUG
#include <embers/logger.h>
#include <embers/assertions.h>
#include <embers/application.h>

class Sandbox : public embers::Application {
public:
    Sandbox() = default;
    ~Sandbox() override = default;

    void Run() override {
        while (true) {
          LOG_DEBUG("tick");
        }
    }
};

int main() {
  LOG_FATAL("fatal");
  LOG_ERROR("error");
  LOG_WARN("warning %d", 1);
  LOG_INFO("info");
  LOG_DEBUG("debug");

  //EMBERS_ASSERT(0 != 0, "0 is equal to 0");

  Sandbox sandbox;
  sandbox.Run();

}