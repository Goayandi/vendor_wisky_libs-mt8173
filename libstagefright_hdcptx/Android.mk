LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE = libstagefright_hdcptx
LOCAL_MODULE_CLASS = SHARED_LIBRARIES
LOCAL_MODULE_OWNER = mtk
LOCAL_MODULE_SUFFIX = .so
LOCAL_PROPRIETARY_MODULE = true
LOCAL_MODULE_TAGS = optional
LOCAL_SHARED_LIBRARIES_64 = libstagefright libstagefright_foundation libgralloc_extra libcrypto libbinder libpowermanager libtz_uree liburee_meta_drmkeyinstall_v2 libgui libhardware libc++
LOCAL_MULTILIB = 64
LOCAL_SRC_FILES_64 = arm64/libstagefright_hdcptx.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE = libstagefright_hdcptx
LOCAL_MODULE_CLASS = SHARED_LIBRARIES
LOCAL_MODULE_OWNER = mtk
LOCAL_MODULE_SUFFIX = .so
LOCAL_PROPRIETARY_MODULE = true
LOCAL_MODULE_TAGS = optional
LOCAL_SHARED_LIBRARIES = libstagefright libstagefright_foundation libgralloc_extra libcrypto libbinder libpowermanager libtz_uree liburee_meta_drmkeyinstall_v2 libgui libhardware libc++
LOCAL_MULTILIB = 32
LOCAL_SRC_FILES_32 = arm/libstagefright_hdcptx.so
include $(BUILD_PREBUILT)
