
//
// Default weak implementation of integration routines appropriate for
// userspace. The kernel has its own versions of these symbols that
// override this implementation.
//

#include <zircon/compiler.h>

#include <lockdep/lockdep.h>

namespace lockdep {

// Default implementation of the runtime functions supporting the thread-local
// ThreadLockState. These MUST be overridden in environments that do not support
// the C++ thread_local TLS mechanism.

__WEAK ThreadLockState* SystemGetThreadLockState() {
    thread_local ThreadLockState thread_lock_state{};
    return &thread_lock_state;
}

__WEAK void SystemInitThreadLockState(ThreadLockState* state) {}

} // namespace fbl
