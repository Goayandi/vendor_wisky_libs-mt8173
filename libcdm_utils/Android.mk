LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE = libcdm_utils
LOCAL_MODULE_CLASS = STATIC_LIBRARIES
LOCAL_MODULE_OWNER = mtk
LOCAL_MODULE_SUFFIX = .a
LOCAL_PROPRIETARY_MODULE = true
LOCAL_UNINSTALLABLE_MODULE = true
LOCAL_MULTILIB = 32
LOCAL_SRC_FILES_32 = arm/libcdm_utils.a
include $(BUILD_PREBUILT)
