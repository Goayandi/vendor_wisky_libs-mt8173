LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE = mobile_log_d
LOCAL_MODULE_CLASS = EXECUTABLES
LOCAL_MODULE_OWNER = mtk
LOCAL_PROPRIETARY_MODULE = true
LOCAL_SHARED_LIBRARIES = libselinux libmtk_drvb libaed libc++
LOCAL_MULTILIB = 32
LOCAL_SRC_FILES_32 = arm/mobile_log_d
include $(BUILD_PREBUILT)
