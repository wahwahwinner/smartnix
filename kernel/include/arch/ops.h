
#pragma once

/* #defines for the cache routines below */
#define ICACHE 1
#define DCACHE 2
#define UCACHE (ICACHE|DCACHE)

#ifndef __ASSEMBLER__

#include <arch/defines.h>
#include <kernel/atomic.h>
#include <kernel/cpu.h>
#include <zircon/compiler.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

__BEGIN_CDECLS

/* fast routines that most arches will implement inline */
static void arch_enable_ints(void);
static void arch_disable_ints(void);
static bool arch_ints_disabled(void);

static uint64_t arch_cycle_count(void);

static cpu_num_t arch_curr_cpu_num(void);
static uint arch_max_num_cpus(void);
static uint arch_cpu_features(void);

void arch_disable_cache(uint flags);
void arch_enable_cache(uint flags);

void arch_clean_cache_range(addr_t start, size_t len);
void arch_clean_invalidate_cache_range(addr_t start, size_t len);
void arch_invalidate_cache_range(addr_t start, size_t len);
void arch_sync_cache_range(addr_t start, size_t len);

/* Used to suspend work on a CPU until it is further shutdown.
 * This will only be invoked with interrupts disabled.  This function
 * must not re-enter the scheduler.
 * flush_done should be signaled after state is flushed. */
typedef struct event event_t;
void arch_flush_state_and_halt(event_t *flush_done) __NO_RETURN;

int arch_idle_thread_routine(void*) __NO_RETURN;

/* function to call in spinloops to idle */
static void arch_spinloop_pause(void);

/* arch optimized version of a page zero routine against a page aligned buffer */
void arch_zero_page(void *);

/* give the specific arch a chance to override some routines */
#include <arch/arch_ops.h>

/* The arch_blocking_disallowed() flag is used to check that in-kernel interrupt
 * handlers do not do any blocking operations.  This is a per-CPU flag.
 * Various blocking operations, such as mutex_acquire(), contain assertions
 * that arch_blocking_disallowed() is false.
 *
 * arch_blocking_disallowed() should only be true when interrupts are
 * disabled. */
static inline bool arch_blocking_disallowed(void) {
    return READ_PERCPU_FIELD32(blocking_disallowed);
}

static inline void arch_set_blocking_disallowed(bool value) {
    WRITE_PERCPU_FIELD32(blocking_disallowed, value);
}

__END_CDECLS

#endif // !__ASSEMBLER__
