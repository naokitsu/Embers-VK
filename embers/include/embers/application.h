//
// Created by Naokitsu on 3/24/2024.
//

#ifndef EMBERS_APPLICATION_H_
#define EMBERS_APPLICATION_H_

#include "platform_detection.h"
#include "embers/assertions.h"

// Cherno, Ozzadar and Travis Vroman prefer define main function in the entry.h (or similar file)
// Probably they know it better, but I'm not a fan of this approach
// Going to try to make it the way i prefer until fail :lul:
namespace embers::window { class Window; }

namespace embers::application {
class Application {
 protected:
  const char *name_ = "Embers Application"; /// Does not take ownership, make sure it outlives the class
  bool valid;
public:
  Application();
  virtual ~Application();
  Application(const Application &) = delete;
  Application(Application &&other) noexcept;

    Application &operator=(const Application &) = delete;
    Application &operator=(Application &&other) noexcept;

  virtual void Run() = 0;

  friend window::Window;
};

} // embers

#endif //EMBERS_APPLICATION_H_
