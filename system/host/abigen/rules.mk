
LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := hostapp

MODULE_SRCS += \
    $(LOCAL_DIR)/abigen.cpp \
    $(LOCAL_DIR)/abigen_generator.cpp \
    $(LOCAL_DIR)/generator.cpp \
    $(LOCAL_DIR)/header_generator.cpp \
    $(LOCAL_DIR)/json_generator.cpp \
    $(LOCAL_DIR)/kernel_wrapper_generator.cpp \
    $(LOCAL_DIR)/rust_binding_generator.cpp \
    $(LOCAL_DIR)/syscall_parser.cpp \
    $(LOCAL_DIR)/types.cpp \
    $(LOCAL_DIR)/vdso_wrapper_generator.cpp \
    $(LOCAL_DIR)/parser/parser.cpp \

include make/module.mk