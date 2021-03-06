
LOCAL_DIR := $(GET_LOCAL_DIR)
MODULE := $(LOCAL_DIR)
MODULE_TYPE := userlib

MODULE_SRCS = \
    $(LOCAL_DIR)/new.cpp \
    $(LOCAL_DIR)/pure_virtual.cpp \
    $(LOCAL_DIR)/thread_atexit.cpp \

MODULE_STATIC_LIBS += system/ulib/c

# Make sure a shared library built with zxcpp doesn't export zxcpp symbols.
MODULE_COMPILEFLAGS := -fvisibility=hidden

MODULE_PACKAGE := src

include make/module.mk
