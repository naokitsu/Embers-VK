//
// Created by Naokitsu on 3/24/2024.
//

#ifndef EMBERS_ASSERTIONS_H_
#define EMBERS_ASSERTIONS_H_

#if _MSC_VER
#include <intrin.h>
#define DBG_BREAK() __debugbreak()
#else
#define DBG_BREAK() __builtin_trap()
#endif

namespace embers {

void processFailedAssertion(const char *expr, const char *file, int line, const char *message);

}
#define EMBERS_ASSERT(x, msg) { if (!(x)) { embers::processFailedAssertion(#x, __FILE__, __LINE__, msg) ; DBG_BREAK(); } }

#endif //EMBERS_ASSERTIONS_H_
