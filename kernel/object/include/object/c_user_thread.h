
#pragma once

// N.B. This file is included by C code.

__BEGIN_CDECLS

// This is the interface for LK's thread_owner_name to return the
// name of the thread's process.
void get_user_thread_process_name(const void* user_thread,
                                  char out_name[THREAD_NAME_LENGTH]);

__END_CDECLS
