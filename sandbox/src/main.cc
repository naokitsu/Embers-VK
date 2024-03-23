//
// Created by Naokitsu on 3/22/2024.
//

#include "iostream"
#define WW_DEBUG
#include <wraithworks/logger.h>

int main() {
  LOG_FATAL("fatal");
  LOG_ERROR("error");
  LOG_WARN("warning %d", 1);
  LOG_INFO("info");
  LOG_DEBUG("debug");
}