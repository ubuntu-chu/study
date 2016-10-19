LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
                                main.cpp \



LOCAL_C_INCLUDES := frameworks/base/zxTask


LOCAL_MODULE:= zxtaskclient

LOCAL_SHARED_LIBRARIES := libzxtask libutils libbinder

include $(BUILD_EXECUTABLE)