//
// Created by Naokitsu on 3/24/2024.
//

#ifndef EMBERS_APPLICATION_H_
#define EMBERS_APPLICATION_H_

// Cherno, Ozzadar and Travis Vroman prefer define main function in the entry.h (or similar file)
// Probably they know it better, but I'm not a fan of this approach
// Going to try to make it the way i prefer until fail :lul:

namespace embers {

class Application {
 public:
  virtual ~Application() = default;

  virtual void Run() = 0;

};

} // embers

#endif //EMBERS_APPLICATION_H_
