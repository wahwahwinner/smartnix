
#include <poll.h>
#include <stdbool.h>
#include <stdlib.h>

#include <zircon/syscalls.h>
#include <lib/fdio/io.h>

#include "private.h"

typedef struct mxwio mxwio_t;
struct mxwio {
    // base fdio io object
    fdio_t io;

    // arbitrary handle
    zx_handle_t h;

    // signals that cause POLLIN
    zx_signals_t signals_in;

    // signals that cause POLLOUT
    zx_signals_t signals_out;

    // if true, don't close handle on close() op
    bool shared_handle;
};

static zx_status_t mxwio_close(fdio_t* io) {
    mxwio_t* wio = (mxwio_t*)io;
    zx_handle_t h = wio->h;
    wio->h = ZX_HANDLE_INVALID;
    if (!wio->shared_handle) {
        zx_handle_close(h);
    }
    return ZX_OK;
}

static void mxwio_wait_begin(fdio_t* io, uint32_t events, zx_handle_t* handle,
                             zx_signals_t* _signals) {
    mxwio_t* wio = (void*)io;
    *handle = wio->h;
    zx_signals_t signals = 0;
    if (events & POLLIN) {
        signals |= wio->signals_in;
    }
    if (events & POLLOUT) {
        signals |= wio->signals_out;
    }
    *_signals = signals;
}

static void mxwio_wait_end(fdio_t* io, zx_signals_t signals, uint32_t* _events) {
    mxwio_t* wio = (void*)io;
    uint32_t events = 0;
    if (signals & wio->signals_in) {
        events |= POLLIN;
    }
    if (signals & wio->signals_out) {
        events |= POLLOUT;
    }
    *_events = events;
}

static fdio_ops_t fdio_waitable_ops = {
    .read = fdio_default_read,
    .read_at = fdio_default_read_at,
    .write = fdio_default_write,
    .write_at = fdio_default_write_at,
    .seek = fdio_default_seek,
    .misc = fdio_default_misc,
    .close = mxwio_close,
    .open = fdio_default_open,
    .clone = fdio_default_clone,
    .ioctl = fdio_default_ioctl,
    .unwrap = fdio_default_unwrap,
    .wait_begin = mxwio_wait_begin,
    .wait_end = mxwio_wait_end,
    .posix_ioctl = fdio_default_posix_ioctl,
    .get_token = fdio_default_get_token,
    .get_attr = fdio_default_get_attr,
    .set_attr = fdio_default_set_attr,
    .sync = fdio_default_sync,
    .readdir = fdio_default_readdir,
    .rewind = fdio_default_rewind,
    .unlink = fdio_default_unlink,
    .truncate = fdio_default_truncate,
    .rename = fdio_default_rename,
    .link = fdio_default_link,
    .get_flags = fdio_default_get_flags,
    .set_flags = fdio_default_set_flags,
    .recvfrom = fdio_default_recvfrom,
    .sendto = fdio_default_sendto,
    .recvmsg = fdio_default_recvmsg,
    .sendmsg = fdio_default_sendmsg,
    .shutdown = fdio_default_shutdown,
};

fdio_t* fdio_waitable_create(zx_handle_t h, zx_signals_t signals_in,
                             zx_signals_t signals_out, bool shared_handle) {
    mxwio_t* wio = fdio_alloc(sizeof(*wio));
    if (wio == NULL) {
        if (!shared_handle) {
            zx_handle_close(h);
        }
        return NULL;
    }
    wio->io.ops = &fdio_waitable_ops;
    wio->io.magic = FDIO_MAGIC;
    wio->io.refcount = 1;
    wio->io.ioflag |= IOFLAG_WAITABLE;
    wio->h = h;
    wio->signals_in = signals_in;
    wio->signals_out = signals_out;
    wio->shared_handle = shared_handle;
    return &wio->io;
}
