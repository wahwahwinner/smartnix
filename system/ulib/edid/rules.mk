
LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := userlib

MODULE_COMPILEFLAGS += -fvisibility=hidden

MODULE_SRCS := $(LOCAL_DIR)/edid.cpp $(LOCAL_DIR)/timings.cpp $(LOCAL_DIR)/eisa_vid_lut.cpp
MODULE_STATIC_LIBS := system/ulib/hwreg system/ulib/ddk system/ulib/ddktl system/ulib/zx
MODULE_LIBS := system/ulib/fbl

include make/module.mk
