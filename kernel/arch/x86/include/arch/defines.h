
#pragma once

#define PAGE_SIZE 4096
#define PAGE_SIZE_SHIFT 12
#define PAGE_MASK (PAGE_SIZE - 1)

#define MAX_CACHE_LINE 64

#define ARCH_DEFAULT_STACK_SIZE 8192

#define ARCH_PHYSMAP_SIZE (0x1000000000) // 64GB

