
#include <fbl/unique_fd.h>
#include <zircon/types.h>

// Opens a connection to the xdc host or device, and registers the stream id.
// If successful, returns ZX_OK and stores the xdc file descriptor in out_fd.
zx_status_t configure_xdc(uint32_t stream_id, fbl::unique_fd* out_fd);
