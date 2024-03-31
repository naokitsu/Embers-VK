//
// Created by Naokitsu on 3/24/2024.
//

#ifndef EMBERS_ASSERTIONS_H_
#define EMBERS_ASSERTIONS_H_

#ifdef EMBERS_ENABLE_DEBUG
#if _MSC_VER
#include <intrin.h>
#define __DBG_BREAK() __debugbreak()
#else
#define __DBG_BREAK() __builtin_trap()
#endif
#else
#define __DBG_BREAK() {}
#endif

namespace embers {

void processFailedAssertion(const char *file, int line, const char *expr, const char *message, ...);
void processFailedAssertion(const char *file, int line, const char *expr);

}

#define __EMBERS_ASSERT_GET_MACRO(_1,_2,NAME,...) NAME
#define EMBERS_ASSERT(...) __EMBERS_ASSERT_GET_MACRO(__VA_ARGS__, EMBERS_ASSERT_MSG, __EMBERS_ASSERT_WITHOUT_MSG)(__VA_ARGS__)

#define EMBERS_ASSERT_MSG(x, msg, ...) \
{                             \
  if (!(x)) { \
    embers::processFailedAssertion(__FILE__, __LINE__, #x, msg, __VA_ARGS__); \
    __DBG_BREAK();             \
  }                            \
}

#define __EMBERS_ASSERT_WITHOUT_MSG(x) \
{                             \
  if (!(x)) { \
    embers::processFailedAssertion(__FILE__, __LINE__, #x); \
    __DBG_BREAK();              \
  }                            \
}

#endif //EMBERS_ASSERTIONS_H_
