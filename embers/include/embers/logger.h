//
// Created by Naokitsu on 3/23/2024.
//

#ifndef EMBERS_LOGGER_H
#define EMBERS_LOGGER_H

#ifdef WW_DEBUG
#define LOG_FATAL_ENABLE 1
#define LOG_ERROR_ENABLE 1
#define LOG_WARN_ENABLE 1
#define LOG_INFO_ENABLE 1
#define LOG_DEBUG_ENABLE 1
#else
#define LOG_FATAL_ENABLE 1
#define LOG_ERROR_ENABLE 1
#define LOG_WARN_ENABLE 1
#define LOG_INFO_ENABLE 0
#define LOG_DEBUG_ENABLE 0
#endif

namespace embers::logger {

class LogLevel {
  // https://stackoverflow.com/questions/21295935/can-a-c-enum-class-have-methods
 public:
  enum Value {
    FATAL = 0,
    ERROR,
    WARN,
    INFO,
    DEBUG
  };

  LogLevel() = default;
  constexpr LogLevel(Value value) : value_(value) {} // NOLINT(*-explicit-constructor)

  constexpr operator Value() const { return value_; } // NOLINT(*-explicit-constructor)

  explicit operator bool() const = delete;

  [[nodiscard]] constexpr const char* ToString() const {
    switch (value_) {
      case FATAL:
        return "FATAL";
      case ERROR:
        return "ERROR";
      case WARN:
        return "WARN";
      case INFO:
        return "INFO";
      case DEBUG:
        return "DEBUG";
    }
  }

  [[nodiscard]] constexpr const char* AnsiColor() const {
      switch (value_) {
          case FATAL:
              return "\033[30;41;4;1m";
          case ERROR:
              return "\033[30;41m";
          case WARN:
              return "\033[30;43m";
          case INFO:
              return "\033[30;42m";
          case DEBUG:
              return "\033[30;46m";
      }
  }

 private:
  Value value_;
};

void log(LogLevel level, const char *message, ...);

#if LOG_FATAL_ENABLE == 1
#define LOG_FATAL(message, ...) embers::logger::log(embers::logger::LogLevel::FATAL, message, ##__VA_ARGS__)
#endif

#if LOG_ERROR_ENABLE == 1
#define LOG_ERROR(message, ...) embers::logger::log(embers::logger::LogLevel::ERROR, message, ##__VA_ARGS__)
#endif

#if LOG_WARN_ENABLE == 1
#define LOG_WARN(message, ...) embers::logger::log(embers::logger::LogLevel::WARN, message, ##__VA_ARGS__)
#endif

#if LOG_INFO_ENABLE == 1
#define LOG_INFO(message, ...) embers::logger::log(embers::logger::LogLevel::INFO, message, ##__VA_ARGS__)
#endif

#if LOG_DEBUG_ENABLE == 1
#define LOG_DEBUG(message, ...) embers::logger::log(embers::logger::LogLevel::DEBUG, message, ##__VA_ARGS__)
#endif
} // embers::logger

#endif //EMBERS_LOGGER_H
