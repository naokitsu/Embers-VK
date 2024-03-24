//
// Created by Naokitsu on 3/22/2024.
//

#include "iostream"

#include <windows.h>

#define EMBERS_ENABLE_DEBUG
#include <embers/logger.h>
#include <embers/assertions.h>
#include <embers/application.h>

class Sandbox : public embers::Application {
public:
    Sandbox() = default;
    ~Sandbox() override = default;

    void Run() override {
        while (true) {
          EMBERS_LOG_DEBUG("tick");
        }
    }
};

struct State {
  HINSTANCE instance;
  HWND hwnd;
};

LRESULT CALLBACK win32_process_message(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param) {
  EMBERS_LOG_DEBUG("msg: %d, w_param: %d, l_param: %d", msg, w_param, l_param);
  return DefWindowProcA(hwnd, msg, w_param, l_param);
}


int main() {
  EMBERS_LOG_FATAL("fatal");
  EMBERS_LOG_ERROR("error");
  EMBERS_LOG_WARN("warning %d", 1);
  EMBERS_LOG_INFO("info");
  EMBERS_LOG_DEBUG("debug");

  //EMBERS_ASSERT(0 != 0, "0 is equal to 0");

  State state;
  state.instance = GetModuleHandle(NULL);
  state.hwnd = NULL;

  HICON icon = LoadIcon(state.instance, IDI_APPLICATION);
  WNDCLASSA wc;
  memset(&wc, 0, sizeof(wc));
  wc.style = CS_DBLCLKS;
  wc.lpfnWndProc = win32_process_message;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = state.instance;
  wc.hIcon = icon;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = NULL;
  wc.lpszClassName = "Embers";
  if (!RegisterClassA(&wc)) {
    EMBERS_LOG_FATAL("Failed to register window class");
  };

  UINT client_x = 100;
  UINT client_y = 100;
  UINT client_width = 400;
  UINT client_height = 300;

  UINT window_x = client_x;
  UINT window_y = client_y;
  UINT window_width = client_width;
  UINT window_height = client_height;

  UINT window_style = WS_OVERLAPPEDWINDOW;
  UINT window_ex_style = WS_EX_APPWINDOW;

  RECT border = {0,0,0,0};
  AdjustWindowRectEx(&border, window_style, false, window_ex_style);

  window_x += border.left;
  window_y += border.top;
  window_width -= border.left + border.right;
  window_height -= border.top + border.bottom;

  HWND hwnd = CreateWindowExA(
      window_ex_style,
      "Embers",
      "Embers",
      window_style,
      window_x,
      window_y,
      window_width,
      window_height,
      NULL,
      NULL,
      state.instance,
      NULL
      );
  if (!hwnd) {
    EMBERS_LOG_FATAL("Failed to create window");
  }
  ShowWindow(hwnd, SW_SHOW);
  while (true) {

    UpdateWindow(hwnd);
  }


  /*Sandbox sandbox;


  sandbox.Run();
*/
}