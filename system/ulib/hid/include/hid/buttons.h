
#pragma once

#include <zircon/types.h>

__BEGIN_CDECLS

// clang-format off
#define BUTTONS_RPT_ID_INPUT       0x01
// clang-format on

// TODO(andresoportus): Remove bitfields.
typedef struct buttons_input_rpt {
    uint8_t rpt_id;
#if __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t volume : 2;
    uint8_t padding : 6;
#else
    uint8_t padding : 6;
    uint8_t volume : 2;
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t mute : 1;
    uint8_t padding2 : 7;
#else
    uint8_t padding2 : 7;
    uint8_t mute : 1;
#endif
} __PACKED buttons_input_rpt_t;

size_t get_buttons_report_desc(const uint8_t** buf);

__END_CDECLS
