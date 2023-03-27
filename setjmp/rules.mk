LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS += $(LOCAL_DIR)/setjmp.c
MODULE_SRCS += $(LOCAL_DIR)/longjmp.c
MODULE_SRCS += $(LOCAL_DIR)/test.c

include make/module.mk
