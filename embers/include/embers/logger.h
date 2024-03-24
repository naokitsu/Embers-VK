//
// Created by Naokitsu on 3/23/2024.
//

#ifndef EMBERS_LOGGER_H
#define EMBERS_LOGGER_H

#ifdef EMBERS_ENABLE_DEBUG
#define EMBERS_LOG_FATAL_ENABLE 1
#define EMBERS_LOG_ERROR_ENABLE 1
#define EMBERS_LOG_WARN_ENABLE 1
#define EMBERS_LOG_INFO_ENABLE 1
#define EMBERS_LOG_DEBUG_ENABLE 1
#else
#define EMBERS_LOG_FATAL_ENABLE 1
#define EMBERS_LOG_ERROR_ENABLE 1
#define EMBERS_LOG_WARN_ENABLE 1
#define EMBERS_LOG_INFO_ENABLE 0
#define EMBERS_LOG_DEBUG_ENABLE 0
#endif

namespace embers::logger {

class LogLevel {
  // https://stackoverflow.com/questions/21295935/can-a-c-enum-class-have-methods
 public:
  enum Value {
    kLogLevelFatal = 0,
    kLogLevelError = 1,
    kLogLevelWarn = 2,
    kLogLevelInfo = 3,
    kLogLevelDebug = 4
  };

  LogLevel() = default;
  constexpr LogLevel(Value value) : value_(value) {} // NOLINT(*-explicit-constructor)

  constexpr operator Value() const { return value_; } // NOLINT(*-explicit-constructor)

  explicit operator bool() const = delete;

  [[nodiscard]] constexpr const char* ToString() const {
    switch (value_) {
      case kLogLevelFatal:
        return "Fatal";
      case kLogLevelError:
        return "Error";
      case kLogLevelWarn:
        return "Warn";
      case kLogLevelInfo:
        return "Info";
      case kLogLevelDebug:
        return "Debug";
    }
    return "Unknown";
  }

  [[nodiscard]] constexpr const char* AnsiColor() const {
      switch (value_) {
          case kLogLevelFatal:
              return "\033[30;41;4;1m";
          case kLogLevelError:
              return "\033[30;41m";
          case kLogLevelWarn:
              return "\033[30;43m";
          case kLogLevelInfo:
              return "\033[30;42m";
          case kLogLevelDebug:
              return "\033[30;46m";
      }
    return "\033[30;46m";
  }

 private:
  Value value_;
};

void log(LogLevel level, const char *message, ...);

#if EMBERS_LOG_FATAL_ENABLE == 1
#define EMBERS_LOG_FATAL(message, ...) embers::logger::log(embers::logger::LogLevel::kLogLevelFatal, message, ##__VA_ARGS__)
#endif

#if EMBERS_LOG_ERROR_ENABLE == 1
#define EMBERS_LOG_ERROR(message, ...) embers::logger::log(embers::logger::LogLevel::kLogLevelError, message, ##__VA_ARGS__)
#endif

#if EMBERS_LOG_WARN_ENABLE == 1
#define EMBERS_LOG_WARN(message, ...) embers::logger::log(embers::logger::LogLevel::kLogLevelWarn, message, ##__VA_ARGS__)
#endif

#if EMBERS_LOG_INFO_ENABLE == 1
#define EMBERS_LOG_INFO(message, ...) embers::logger::log(embers::logger::LogLevel::kLogLevelInfo, message, ##__VA_ARGS__)
#endif

#if EMBERS_LOG_DEBUG_ENABLE == 1
#define EMBERS_LOG_DEBUG(message, ...) embers::logger::log(embers::logger::LogLevel::kLogLevelDebug, message, ##__VA_ARGS__)
#endif
} // embers::logger

#endif //EMBERS_LOGGER_H
