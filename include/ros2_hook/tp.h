#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER ros2_hook

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "ros2_hook/tp.h"

#if !defined(_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TP_H

#include <lttng/tracepoint.h>
#include <lttng/tracepoint-event.h>


TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,
  take_type_erased,
  TP_ARGS(
    const uint64_t, stamp_arg,
    const void *, message_addr_arg
  ),
  TP_FIELDS(
    ctf_integer(const uint64_t, stamp, stamp_arg)
    ctf_integer_hex(const void *, message_addr, message_addr_arg)
  )
)

TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,
  on_data_available,
  TP_ARGS(
    const uint64_t, stamp_arg
  ),
  TP_FIELDS(
    ctf_integer(const uint64_t, stamp, stamp_arg)
  )
)

TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,
  dds_write,
  TP_ARGS(
    const void *, message_addr_arg
  ),
  TP_FIELDS(
    ctf_integer_hex(const void *, message_addr, message_addr_arg)
  )
)

TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,
  dds_bind_addr_to_stamp,
  TP_ARGS(
    const void *, addr_from_arg,
    const uint64_t, stamp_to_arg
  ),
  TP_FIELDS(
    ctf_integer_hex(const void *, addr_from, addr_from_arg)
    ctf_integer(const uint64_t *, stamp_to, stamp_to_arg)
  )
)

TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,
  dds_bind_addr_to_addr,
  TP_ARGS(
    const void *, addr_from_arg,
    const void *, addr_to_arg
  ),
  TP_FIELDS(
    ctf_integer_hex(const void *, addr_from, addr_from_arg)
    ctf_integer_hex(const void *, addr_to, addr_to_arg)
  )
)

#endif /* _TP_H */