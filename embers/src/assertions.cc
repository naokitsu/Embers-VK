//
// Created by Naokitsu on 3/24/2024.
//

#include "embers/assertions.h"
#include "embers/logger.h"

void embers::processFailedAssertion(const char *file, int line, const char *message, const char *expr) {
  EMBERS_LOG_WARN(
      "Failed Assertion: %s\n"
      "- File: %s\n"
      "- Line: %d\n"
      "- Message: %s", expr, file, line, message
  );
}

void embers::processFailedAssertion(const char *file, int line, const char *expr) {
  EMBERS_LOG_WARN(
      "Failed Assertion: %s\n"
      "- File: %s\n"
      "- Line: %d", expr, file, line
  );
}