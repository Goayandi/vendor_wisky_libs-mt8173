LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE = libwvdrmengine
LOCAL_MODULE_CLASS = SHARED_LIBRARIES
LOCAL_MODULE_OWNER = widevine
LOCAL_MODULE_RELATIVE_PATH = mediadrm
LOCAL_MODULE_SUFFIX = .so
LOCAL_PROPRIETARY_MODULE = true
LOCAL_MODULE_TAGS = optional
LOCAL_SHARED_LIBRARIES = libprotobuf-cpp-lite libstagefright_foundation libc++
LOCAL_MULTILIB = 32
LOCAL_SRC_FILES_32 = arm/libwvdrmengine.so
include $(BUILD_PREBUILT)
