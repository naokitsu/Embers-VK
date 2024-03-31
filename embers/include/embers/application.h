//
// Created by Naokitsu on 3/24/2024.
//

#ifndef EMBERS_APPLICATION_H_
#define EMBERS_APPLICATION_H_

#include <windows.h>

// Cherno, Ozzadar and Travis Vroman prefer define main function in the entry.h (or similar file)
// Probably they know it better, but I'm not a fan of this approach
// Going to try to make it the way i prefer until fail :lul:

namespace embers::window { class Window; }


namespace embers {



class Application {
 protected:
  HINSTANCE hinstance_;
  const char *name_ = "Embers Application";
 public:
  Application() {
    hinstance_ = GetModuleHandleA(NULL);
  }
  virtual ~Application() = default;

  virtual void Run() = 0;

  friend window::Window;
};

} // embers

#endif //EMBERS_APPLICATION_H_
