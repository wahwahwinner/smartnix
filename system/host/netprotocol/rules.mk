
LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR).netruncmd

MODULE_TYPE := hostapp

MODULE_SRCS += $(LOCAL_DIR)/netruncmd.c $(LOCAL_DIR)/netprotocol.c

MODULE_NAME := netruncmd

MODULE_PACKAGE := bin

include make/module.mk

MODULE := $(LOCAL_DIR).netcp

MODULE_TYPE := hostapp

MODULE_SRCS += $(LOCAL_DIR)/netcp.c $(LOCAL_DIR)/netprotocol.c

MODULE_HOST_LIBS := system/ulib/tftp

MODULE_NAME := netcp

MODULE_PACKAGE := bin

include make/module.mk

MODULE := $(LOCAL_DIR).netls

MODULE_TYPE := hostapp

MODULE_SRCS += $(LOCAL_DIR)/netls.c $(LOCAL_DIR)/netprotocol.c

MODULE_NAME := netls

MODULE_PACKAGE := bin

include make/module.mk

MODULE := $(LOCAL_DIR).netaddr

MODULE_TYPE := hostapp

MODULE_SRCS += $(LOCAL_DIR)/netaddr.c $(LOCAL_DIR)/netprotocol.c

MODULE_NAME := netaddr

MODULE_PACKAGE := bin

include make/module.mk
