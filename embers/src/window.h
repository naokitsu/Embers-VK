//
// Created by Naokitsu on 3/25/2024.
//

#ifndef EMBERS_SRC_WINDOW_H_
#define EMBERS_SRC_WINDOW_H_

#include <windows.h>

#include "platform_detection.h"
#include "embers/application.h"
#include "primitives.h"

#ifdef EMBERS_PLATFORM_LINUX
#error "not implemented"
#endif

namespace embers::window {

class Window {
  HICON icon_;
  HWND window_;
  u32 x_;
  u32 y_;
  u32 width_;
  u32 height_;

 public:
  Window(const Application &application, u32 x, u32 y, u32 width, u32 height);

  void Update();
};
}


#endif //EMBERS_SRC_WINDOW_H_
