
LOCAL_DIR := $(GET_LOCAL_DIR)

fit_srcs := \
    $(LOCAL_DIR)/empty.c \

#
# Userspace library.
#

MODULE_COMPILEFLAGS += -fvisibility=hidden

MODULE := $(LOCAL_DIR)
MODULE_TYPE := userlib
MODULE_PACKAGE := src
MODULE_SRCS := $(fit_srcs)

include make/module.mk

#
# Host library.
#

MODULE := $(LOCAL_DIR).hostlib
MODULE_TYPE := hostlib
MODULE_SRCS := $(fit_srcs)

include make/module.mk

# Clear local variables.

fit_srcs :=
