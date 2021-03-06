
LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := userlib

MODULE_COMPILEFLAGS += -fvisibility=hidden

MODULE_SRCS += \
    $(LOCAL_DIR)/loader-service.c \

MODULE_STATIC_LIBS := \
    system/ulib/async-loop \
    system/ulib/async \
    system/ulib/ldmsg \

MODULE_LIBS := \
    system/ulib/fdio \
    system/ulib/zircon \
    system/ulib/c

MODULE_PACKAGE := static

include make/module.mk
