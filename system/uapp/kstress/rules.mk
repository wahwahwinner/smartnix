
LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := userapp
MODULE_GROUP := misc

MODULE_SRCS += \
    $(LOCAL_DIR)/main.cpp \
    $(LOCAL_DIR)/stress_test.cpp \
    $(LOCAL_DIR)/vmstress.cpp

MODULE_LIBS := \
    system/ulib/c \
    system/ulib/fdio \
    system/ulib/zircon \

MODULE_STATIC_LIBS := \
    system/ulib/fbl \
    system/ulib/zx \
    system/ulib/zxcpp \

MODULE_FIDL_LIBS := \
    system/fidl/fuchsia-sysinfo \

include make/module.mk
