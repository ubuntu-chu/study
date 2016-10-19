LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
                                ZxTask.cpp \
                                ZxTaskService.cpp


LOCAL_C_INCLUDES := \
                                system/core/include \
                                frameworks/native/include



LOCAL_SHARED_LIBRARIES := \
                                                libbinder \
                                                libutils \


LOCAL_MODULE:= libzxtask

include $(BUILD_SHARED_LIBRARY)