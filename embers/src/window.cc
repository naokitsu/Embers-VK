//
// Created by Naokitsu on 3/25/2024.
//

#include "window.h"
#include "embers/logger.h"

LRESULT CALLBACK win32_process_message(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param) {
  switch (msg) {
    case WM_ERASEBKGND:
      return 1;
  }
  return DefWindowProcA(hwnd, msg, w_param, l_param);
}

embers::window::Window::Window(const Application &application, u32 x, u32 y, u32 width, u32 height) {

  icon_ = LoadIcon(application.hinstance_, IDI_APPLICATION);

  WNDCLASSA window_class;
  memset(&window_class, 0, sizeof(window_class));
  window_class.style = CS_DBLCLKS;
  window_class.lpfnWndProc = win32_process_message;
  window_class.cbClsExtra = 0;
  window_class.cbWndExtra = 0;
  window_class.hInstance = application.hinstance_;
  window_class.hIcon = icon_;
  window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
  window_class.hbrBackground = NULL;
  window_class.lpszClassName = "embers_window";

  RegisterClassA(&window_class);

  UINT window_style = WS_OVERLAPPEDWINDOW;
  UINT window_ex_style = WS_EX_APPWINDOW;

  RECT border = {0,0,0,0};
  AdjustWindowRectEx(&border, window_style, false, window_ex_style);

  x_ = x + border.left;
  y_ = y + border.top;
  width_ = width - border.left - border.right;
  height_ = height - border.top + border.bottom;

  window_ = CreateWindowExA(
      window_ex_style,
      "embers_window",
      application.name_,
      window_style,
      x_,
      y_,
      width_,
      height_,
      NULL,
      NULL,
      application.hinstance_,
      NULL
  );

  if (window_ == NULL) {
    EMBERS_LOG_ERROR("Failed to create window: %d", GetLastError());
    exit(1);
  }

  ShowWindow(window_, SW_SHOW);

}

void embers::window::Window::Update() {
  UpdateWindow(window_);
}