
/*
 * This is an input linker script used in linking libdriver.so.
 * The linker is pulling in our symbols from an archive, thus they won't get
 * pulled in unless they are referenced. 
 * This file injects synthetic references to keep the symbols alive.
 *
 * TODO(ZX-2884): Some of these might go away. And some symbols that aren't
 * here may still be exported due to being referenced somewhere (these need
 * to either be removed, renamed to something internal, or be added here).
 */

/* Context acquire/release. */
EXTERN(trace_acquire_context)
EXTERN(trace_acquire_context_for_category)
EXTERN(trace_release_context)

/* Basic events. */
EXTERN(trace_context_write_async_begin_event_record)
EXTERN(trace_context_write_async_end_event_record)
EXTERN(trace_context_write_async_instant_event_record)
EXTERN(trace_context_write_counter_event_record)
EXTERN(trace_context_write_duration_begin_event_record)
EXTERN(trace_context_write_duration_end_event_record)
EXTERN(trace_context_write_duration_event_record)
EXTERN(trace_context_write_flow_begin_event_record)
EXTERN(trace_context_write_flow_end_event_record)
EXTERN(trace_context_write_flow_step_event_record)
EXTERN(trace_context_write_instant_event_record)

/* Misc. */
EXTERN(trace_generate_nonce)
EXTERN(trace_is_category_enabled)
EXTERN(trace_context_is_category_enabled)
EXTERN(trace_context_begin_write_blob_record)
EXTERN(trace_context_write_blob_record)
EXTERN(trace_context_register_vthread)

/* The observer API. */
EXTERN(trace_register_observer)
EXTERN(trace_unregister_observer)
EXTERN(trace_notify_observer_updated)
