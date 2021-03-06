
#pragma once

#include <stddef.h>
#include <stdint.h>
#include <zircon/compiler.h>

__BEGIN_CDECLS;

/* do a hex dump against stdout 32bits and 8bits at a time */
void hexdump_ex(const void* ptr, size_t len, uint64_t disp_addr);
void hexdump8_ex(const void* ptr, size_t len, uint64_t disp_addr);

static inline void hexdump(const void* ptr, size_t len) {
    hexdump_ex(ptr, len, (uint64_t)((uintptr_t)ptr));
}

static inline void hexdump8(const void* ptr, size_t len) {
    hexdump8_ex(ptr, len, (uint64_t)((uintptr_t)ptr));
}

__END_CDECLS;
