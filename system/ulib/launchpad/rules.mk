
LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := userlib

MODULE_SRCS += \
    $(LOCAL_DIR)/elf.c \
    $(LOCAL_DIR)/launchpad.c \
    $(LOCAL_DIR)/fdio.c \
    $(LOCAL_DIR)/vmo.c

MODULE_SO_NAME := launchpad

MODULE_STATIC_LIBS := \
    system/ulib/elfload \
    system/ulib/ldmsg \

MODULE_LIBS := \
    system/ulib/fdio \
    system/ulib/zircon \
    system/ulib/c

include make/module.mk
