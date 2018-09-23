LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE = libdrmmtkutil
LOCAL_MODULE_CLASS = SHARED_LIBRARIES
LOCAL_MODULE_OWNER = mtk
LOCAL_MODULE_SUFFIX = .so
LOCAL_PROPRIETARY_MODULE = true
LOCAL_MODULE_TAGS = optional
LOCAL_SHARED_LIBRARIES_64 = libicui18n libicuuc libcrypto libssl libdrmframework libdrmmtkwhitelist libbinder libnvramagentclient libmtk_drvb libc++
LOCAL_MULTILIB = 64
LOCAL_SRC_FILES_64 = arm64/libdrmmtkutil.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE = libdrmmtkutil
LOCAL_MODULE_CLASS = SHARED_LIBRARIES
LOCAL_MODULE_OWNER = mtk
LOCAL_MODULE_SUFFIX = .so
LOCAL_PROPRIETARY_MODULE = true
LOCAL_MODULE_TAGS = optional
LOCAL_SHARED_LIBRARIES = libicui18n libicuuc libcrypto libssl libdrmframework libdrmmtkwhitelist libbinder libnvramagentclient libmtk_drvb libc++
LOCAL_MULTILIB = 32
LOCAL_SRC_FILES_32 = arm/libdrmmtkutil.so
include $(BUILD_PREBUILT)
