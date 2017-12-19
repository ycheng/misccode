LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := pthread_structure_size.c

LOCAL_CFLAGS := -g -W -Wall -DBIONIC -D_32BIT_

LOCAL_MODULE := pthread_structure_size
LOCAL_MODULE_TAGS :=
LOCAL_SYSTEM_SHARED_LIBRARIES := libc
LOCAL_32_BIT_ONLY := true

include $(BUILD_EXECUTABLE)
