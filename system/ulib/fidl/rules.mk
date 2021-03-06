
LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := userlib

MODULE_SRCS += \
    $(LOCAL_DIR)/bind.c \
    $(LOCAL_DIR)/builder.cpp \
    $(LOCAL_DIR)/decoding.cpp \
    $(LOCAL_DIR)/encoding.cpp \
    $(LOCAL_DIR)/epitaph.c \
    $(LOCAL_DIR)/formatting.cpp \
    $(LOCAL_DIR)/message_buffer.cpp \
    $(LOCAL_DIR)/message_builder.cpp \
    $(LOCAL_DIR)/message.cpp \
    $(LOCAL_DIR)/validating.cpp \

MODULE_LIBS := \
    system/ulib/async \
    system/ulib/zircon \

MODULE_PACKAGE := src

include make/module.mk
