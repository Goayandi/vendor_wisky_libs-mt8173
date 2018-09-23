LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE = liburee_meta_drmkeyinstall_v2
LOCAL_MODULE_CLASS = SHARED_LIBRARIES
LOCAL_MODULE_OWNER = mtk
LOCAL_MODULE_SUFFIX = .so
LOCAL_PROPRIETARY_MODULE = true
LOCAL_SHARED_LIBRARIES_64 = libnetutils libtz_uree libc++
LOCAL_MULTILIB = 64
LOCAL_SRC_FILES_64 = arm64/liburee_meta_drmkeyinstall_v2.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE = liburee_meta_drmkeyinstall_v2
LOCAL_MODULE_CLASS = SHARED_LIBRARIES
LOCAL_MODULE_OWNER = mtk
LOCAL_MODULE_SUFFIX = .so
LOCAL_PROPRIETARY_MODULE = true
LOCAL_SHARED_LIBRARIES = libnetutils libtz_uree libc++
LOCAL_MULTILIB = 32
LOCAL_SRC_FILES_32 = arm/liburee_meta_drmkeyinstall_v2.so
include $(BUILD_PREBUILT)
