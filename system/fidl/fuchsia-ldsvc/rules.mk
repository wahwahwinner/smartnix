
LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := fidl

MODULE_PACKAGE := fidl

MODULE_FIDL_LIBRARY := fuchsia.ldsvc

MODULE_SRCS += $(LOCAL_DIR)/ldsvc.fidl

include make/module.mk
