
#include <lib/vdso-constants.h>

// This is in assembly so that the LTO compiler cannot see the
// initializer values and decide it's OK to optimize away references.

.section .rodata.vdso_constants,"a",%progbits
    .balign VDSO_CONSTANTS_ALIGN
    .global DATA_CONSTANTS
    .hidden DATA_CONSTANTS
    .type DATA_CONSTANTS, %object
    .size DATA_CONSTANTS, VDSO_CONSTANTS_SIZE
DATA_CONSTANTS:
    .fill VDSO_CONSTANTS_SIZE / 4, 4, 0xdeadbeef
