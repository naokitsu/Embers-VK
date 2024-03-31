//
// Created by Naokitsu on 3/24/2024.
//

#include <cstdarg>
#include <cstdio>
#include "embers/assertions.h"
#include "embers/logger.h"

void embers::processFailedAssertion(const char *file, int line, const char *expr, const char *message, ...) {
  char buffer[1024];
  va_list args;
  va_start(args, expr);
  vsnprintf(buffer, sizeof(buffer), message, args);
  va_end(args);

  EMBERS_LOG_WARN(
      "Failed Assertion: %s\n"
      "- File    - %s\n"
      "- Line    - %d\n"
      "- Message - %s", expr, file, line, buffer
  );
}

void embers::processFailedAssertion(const char *file, int line, const char *expr) {
  EMBERS_LOG_WARN(
      "Failed Assertion: %s\n"
      "- File: %s\n"
      "- Line: %d", expr, file, line
  );
}