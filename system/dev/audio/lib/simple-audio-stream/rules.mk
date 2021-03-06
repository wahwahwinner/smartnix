
LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := userlib

MODULE_SRCS += \
    $(LOCAL_DIR)/simple-audio-stream.cpp

MODULE_STATIC_LIBS := \
    system/ulib/audio-driver-proto \
    system/ulib/ddk \
    system/ulib/ddktl \
    system/ulib/audio-proto-utils \
    system/ulib/dispatcher-pool \
    system/ulib/fbl \
    system/ulib/zx \

include make/module.mk
