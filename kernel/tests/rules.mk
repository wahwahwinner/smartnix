
LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS += \
    $(LOCAL_DIR)/alloc_checker_tests.cpp \
    $(LOCAL_DIR)/benchmarks.cpp \
    $(LOCAL_DIR)/cache_tests.cpp \
    $(LOCAL_DIR)/clock_tests.cpp \
    $(LOCAL_DIR)/fibo.cpp \
    $(LOCAL_DIR)/lock_dep_tests.cpp \
    $(LOCAL_DIR)/mem_tests.cpp \
    $(LOCAL_DIR)/mp_hotplug_tests.cpp \
    $(LOCAL_DIR)/preempt_disable_tests.cpp \
    $(LOCAL_DIR)/printf_tests.cpp \
    $(LOCAL_DIR)/resource_tests.cpp \
    $(LOCAL_DIR)/sleep_tests.cpp \
    $(LOCAL_DIR)/string_tests.cpp \
    $(LOCAL_DIR)/sync_ipi_tests.cpp \
    $(LOCAL_DIR)/tests.cpp \
    $(LOCAL_DIR)/thread_tests.cpp \
    $(LOCAL_DIR)/timer_tests.cpp \
    $(LOCAL_DIR)/uart_tests.cpp \

MODULE_DEPS += \
    kernel/lib/crypto \
    kernel/lib/header_tests \
    kernel/lib/fbl \
    kernel/lib/unittest \

MODULE_COMPILEFLAGS += -fno-builtin

include make/module.mk
