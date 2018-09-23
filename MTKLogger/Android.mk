LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE = MTKLogger
LOCAL_MODULE_CLASS = APPS
LOCAL_MODULE_OWNER = mtk
LOCAL_MODULE_SUFFIX = .apk
LOCAL_PROPRIETARY_MODULE = true
LOCAL_MODULE_TAGS = optional
LOCAL_CERTIFICATE = platform
LOCAL_SRC_FILES = $(call get-prebuilt-src-arch,arm arm64)/MTKLogger.apk
include $(BUILD_PREBUILT)
