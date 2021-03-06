
#pragma once

#include <arch/x86/page_tables/constants.h>

/* top level defines for the x86 mmu */
/* NOTE: the top part can be included from assembly */

#define X86_EPT_R                 (1u << 0) /* R    Read     */
#define X86_EPT_W                 (1u << 1) /* W    Write    */
#define X86_EPT_X                 (1u << 2) /* X    Execute  */
#define X86_EPT_A                 (1u << 8) /* A    Accessed */
#define X86_EPT_D                 (1u << 9) /* D    Dirty    */

/* From Volume 3, Section 28.2.6: EPT and Memory Typing */
#define X86_EPT_MEMORY_TYPE_MASK  (7u << 3)
#define X86_EPT_UC                (0u << 3) /* UC   Uncached memory type        */
#define X86_EPT_WC                (1u << 3) /* WC   Write-combining memory type */
#define X86_EPT_WT                (4u << 3) /* WT   Write-through memory type   */
#define X86_EPT_WP                (5u << 3) /* WP   Write-protected memory type */
#define X86_EPT_WB                (6u << 3) /* WB   Write-back memory type      */

/* Page Attribute Table memory types, defined in Table 11-10 of Intel 3A */
#define X86_PAT_UC                0x00 /* Uncached */
#define X86_PAT_WC                0x01 /* Write-combining */
#define X86_PAT_WT                0x04 /* Write-through */
#define X86_PAT_WP                0x05 /* Write protected */
#define X86_PAT_WB                0X06 /* Write-back */
#define X86_PAT_UC_               0x07 /* Weakly Uncached (can be overridden by a WC MTRR setting) */

/* Our configuration for the PAT indexes.  This must be kept in sync with the
 * selector definitions below it.  For safety, it is important to ensure that
 * the default mode is less cached than our substitution.  This ensures that
 * any mappings defined before we switch all CPUs to this new map will still
 * function correctly. */
#define X86_PAT_INDEX0  X86_PAT_WB  /* default */
#define X86_PAT_INDEX1  X86_PAT_WT  /* default */
#define X86_PAT_INDEX2  X86_PAT_UC_ /* default */
#define X86_PAT_INDEX3  X86_PAT_UC  /* default */
#define X86_PAT_INDEX4  X86_PAT_WB  /* default */
#define X86_PAT_INDEX5  X86_PAT_WT  /* default */
#define X86_PAT_INDEX6  X86_PAT_UC_ /* default */
#define X86_PAT_INDEX7  X86_PAT_WC  /* UC by default */

/* These assume our defined PAT entries.  We need to update these if we decide
 * to change them PAT entries */
#define X86_MMU_PTE_PAT_WRITEBACK               X86_PAT_PTE_SELECTOR(0)
#define X86_MMU_PTE_PAT_WRITETHROUGH            X86_PAT_PTE_SELECTOR(1)
#define X86_MMU_PTE_PAT_UNCACHABLE              X86_PAT_PTE_SELECTOR(3)
#define X86_MMU_PTE_PAT_WRITE_COMBINING         X86_PAT_PTE_SELECTOR(7)
#define X86_MMU_LARGE_PAT_WRITEBACK             X86_PAT_LARGE_SELECTOR(0)
#define X86_MMU_LARGE_PAT_WRITETHROUGH          X86_PAT_LARGE_SELECTOR(1)
#define X86_MMU_LARGE_PAT_UNCACHABLE            X86_PAT_LARGE_SELECTOR(3)
#define X86_MMU_LARGE_PAT_WRITE_COMBINING       X86_PAT_LARGE_SELECTOR(7)

/* default flags for inner page directory entries */
#define X86_KERNEL_PD_FLAGS (X86_MMU_PG_RW | X86_MMU_PG_P)

/* default flags for 2MB/4MB/1GB page directory entries */
#define X86_KERNEL_PD_LP_FLAGS (X86_MMU_PG_G | X86_MMU_PG_PS | X86_MMU_PG_RW | X86_MMU_PG_P)

#define X86_MMU_PG_NX           (1UL << 63)

#define X86_PAGING_LEVELS       4

#define MMU_GUEST_SIZE_SHIFT    48

/* page fault error code flags */
#define PFEX_P      (1<<0)
#define PFEX_W      (1<<1)
#define PFEX_U      (1<<2)
#define PFEX_RSV    (1<<3)
#define PFEX_I      (1<<4)
#define PFEX_PK     (1<<5)
#define PFEX_SGX    (1<<15)

/* C defines below */
#ifndef __ASSEMBLER__

#include <sys/types.h>
#include <zircon/compiler.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

__BEGIN_CDECLS

struct map_range {
    vaddr_t start_vaddr;
    paddr_t start_paddr; /* Physical address in the PAE mode is 32 bits wide */
    size_t size;
};

bool x86_is_vaddr_canonical(vaddr_t vaddr);
bool x86_mmu_check_paddr(paddr_t paddr);

void x86_mmu_percpu_init(void);
void x86_mmu_early_init(void);
void x86_mmu_init(void);

paddr_t x86_kernel_cr3(void);

__END_CDECLS

#endif // !__ASSEMBLER__
