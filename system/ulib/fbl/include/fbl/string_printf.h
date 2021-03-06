
#pragma once

#include <stdarg.h>

#include <zircon/compiler.h>
#include <fbl/string.h>

namespace fbl {

// Formats |printf()|-like input and returns it as an |fbl::String|.
String StringPrintf(const char* format, ...)
    __PRINTFLIKE(1, 2) __WARN_UNUSED_RESULT;

// Formats |vprintf()|-like input and returns it as an |fbl::String|.
String StringVPrintf(const char* format, va_list ap)
    __WARN_UNUSED_RESULT;

} // namespace fbl
