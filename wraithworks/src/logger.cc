//
// Created by Naokitsu on 3/23/2024.
//

#include <cstdarg>
#include <cstdio>
#include "wraithworks/logger.h"

namespace wraithworks::logger {
void log(LogLevel level, const char *message, ...) {
  char buffer[1024];
  va_list args;
  va_start(args, message);
  vsnprintf(buffer, sizeof(buffer), message, args);
  va_end(args);

  printf("[%s%s\033[0m] %s\n", level.AnsiColor() ,level.ToString(), buffer);
}

} // wraithworks