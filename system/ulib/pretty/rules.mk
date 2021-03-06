
LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := userlib

MODULE_COMPILEFLAGS += -fvisibility=hidden

MODULE_SRCS += \
    $(LOCAL_DIR)/hexdump.c \
    $(LOCAL_DIR)/sizes.c

MODULE_LIBS := \
    system/ulib/fdio \
    system/ulib/c

MODULE_PACKAGE := static

include make/module.mk

MODULE := $(LOCAL_DIR).test

MODULE_TYPE := usertest

MODULE_SRCS += \
    $(LOCAL_DIR)/test.c

MODULE_NAME := pretty-test

MODULE_LIBS := \
    system/ulib/unittest \
    system/ulib/fdio \
    system/ulib/c

MODULE_STATIC_LIBS := \
    system/ulib/pretty

include make/module.mk

MODULE := $(LOCAL_DIR).hostlib

MODULE_TYPE := hostlib

MODULE_SRCS += \
    $(LOCAL_DIR)/hexdump.c \
    $(LOCAL_DIR)/sizes.c

include make/module.mk
