//
// Copyright 2013 Google Inc. All Rights Reserved.
//

#ifndef WV_MAP_ERRORS_H_
#define WV_MAP_ERRORS_H_

#include "media/stagefright/MediaErrors.h"
#include "utils/Errors.h"
#include "wv_cdm_types.h"
#include "WVErrors.h"

namespace wvdrm {

static android::status_t mapCdmResponseType(wvcdm::CdmResponseType res) {
  switch (res) {
    case wvcdm::NO_ERROR:
    case wvcdm::KEY_ADDED:
    case wvcdm::KEY_MESSAGE:
    case wvcdm::KEY_CANCELED:
      // KEY_ADDED, KEY_MESSAGE, and KEY_CANCELLED are all alternative
      // success messages for certain CDM methods instead of NO_ERROR.
      return android::OK;
    case wvcdm::NEED_KEY:
      return android::ERROR_DRM_NO_LICENSE;
    case wvcdm::NEED_PROVISIONING:
      return android::ERROR_DRM_NOT_PROVISIONED;
    case wvcdm::DEVICE_REVOKED:
      return android::ERROR_DRM_DEVICE_REVOKED;
    case wvcdm::INSUFFICIENT_CRYPTO_RESOURCES:
      return android::ERROR_DRM_RESOURCE_BUSY;
    case wvcdm::ADD_KEY_ERROR:
      return kAddKeyError;
    case wvcdm::CERT_PROVISIONING_GET_KEYBOX_ERROR_1:
      return kCertProvisioningGetKeyboxError1;
    case wvcdm::CERT_PROVISIONING_GET_KEYBOX_ERROR_2:
      return kCertProvisioningGetKeyboxError2;
    case wvcdm::CERT_PROVISIONING_INVALID_CERT_TYPE:
      return kCertProvisioningInvalidCertType;
    case wvcdm::CERT_PROVISIONING_REQUEST_ERROR_1:
      return kCertProvisioningRequestError1;
    case wvcdm::CERT_PROVISIONING_REQUEST_ERROR_2:
      return kCertProvisioningRequestError2;
    case wvcdm::CERT_PROVISIONING_REQUEST_ERROR_3:
      return kCertProvisioningRequestError3;
    case wvcdm::CERT_PROVISIONING_REQUEST_ERROR_4:
      return kCertProvisioningRequestError4;
    case wvcdm::CERT_PROVISIONING_RESPONSE_ERROR_1:
      return kCertProvisioningResponseError1;
    case wvcdm::CERT_PROVISIONING_RESPONSE_ERROR_2:
      return kCertProvisioningResponseError2;
    case wvcdm::CERT_PROVISIONING_RESPONSE_ERROR_3:
      return kCertProvisioningResponseError3;
    case wvcdm::CERT_PROVISIONING_RESPONSE_ERROR_4:
      return kCertProvisioningResponseError4;
    case wvcdm::CERT_PROVISIONING_RESPONSE_ERROR_5:
      return kCertProvisioningResponseError5;
    case wvcdm::CERT_PROVISIONING_RESPONSE_ERROR_6:
      return kCertProvisioningResponseError6;
    case wvcdm::CERT_PROVISIONING_RESPONSE_ERROR_7:
      return kCertProvisioningResponseError7;
    case wvcdm::CERT_PROVISIONING_RESPONSE_ERROR_8:
      return kCertProvisioningResponseError8;
    case wvcdm::CRYPTO_SESSION_OPEN_ERROR_1:
      return kCryptoSessionOpenError1;
    case wvcdm::CRYPTO_SESSION_OPEN_ERROR_2:
      return kCryptoSessionOpenError2;
    case wvcdm::CRYPTO_SESSION_OPEN_ERROR_3:
      return kCryptoSessionOpenError3;
    case wvcdm::CRYPTO_SESSION_OPEN_ERROR_4:
      return kCryptoSessionOpenError4;
    case wvcdm::CRYPTO_SESSION_OPEN_ERROR_5:
      return kCryptoSessionOpenError5;
    case wvcdm::DECRYPT_NOT_READY:
      return kDecyrptNotReady;
    case wvcdm::DEVICE_CERTIFICATE_ERROR_1:
      return kDeviceCertificateError1;
    case wvcdm::DEVICE_CERTIFICATE_ERROR_2:
      return kDeviceCertificateError2;
    case wvcdm::DEVICE_CERTIFICATE_ERROR_3:
      return kDeviceCertificateError3;
    case wvcdm::DEVICE_CERTIFICATE_ERROR_4:
      return kDeviceCertificateError4;
    case wvcdm::EMPTY_KEY_DATA_1:
      return kEmptyKeyData1;
    case wvcdm::EMPTY_KEY_DATA_2:
      return kEmptyKeyData2;
    case wvcdm::EMPTY_KEYSET_ID:
      return kEmptyKeySetId;
    case wvcdm::EMPTY_KEYSET_ID_ENG_1:
      return kEmptyKeySetIdEng1;
    case wvcdm::EMPTY_KEYSET_ID_ENG_2:
      return kEmptyKeySetIdEng2;
    case wvcdm::EMPTY_KEYSET_ID_ENG_3:
      return kEmptyKeySetIdEng3;
    case wvcdm::EMPTY_KEYSET_ID_ENG_4:
      return kEmptyKeySetIdEng4;
    case wvcdm::EMPTY_LICENSE_RENEWAL:
      return kEmptyLicenseRenewal;
    case wvcdm::EMPTY_LICENSE_RESPONSE_1:
      return kEmptyLicenseResponse1;
    case wvcdm::EMPTY_LICENSE_RESPONSE_2:
      return kEmptyLicenseResponse2;
    case wvcdm::EMPTY_PROVISIONING_CERTIFICATE_1:
      return kEmptyProvisioningCertificate1;
    case wvcdm::EMPTY_PROVISIONING_RESPONSE:
      return kEmptyProvisioningResponse;
    case wvcdm::EMPTY_SESSION_ID:
      return kEmptySessionId;
    case wvcdm::GENERATE_DERIVED_KEYS_ERROR:
      return kGenerateDerivedKeysError;
    case wvcdm::LICENSE_RENEWAL_NONCE_GENERATION_ERROR:
      return kLicenseRenewalNonceGenerationError;
    case wvcdm::GENERATE_USAGE_REPORT_ERROR:
      return kGenerateUsageReportError;
    case wvcdm::GET_LICENSE_ERROR:
      return kGetLicenseError;
    case wvcdm::GET_RELEASED_LICENSE_ERROR:
      return kGetReleasedLicenseError;
    case wvcdm::GET_USAGE_INFO_ERROR_1:
      return kGetUsageInfoError1;
    case wvcdm::GET_USAGE_INFO_ERROR_2:
      return kGetUsageInfoError2;
    case wvcdm::GET_USAGE_INFO_ERROR_3:
      return kGetUsageInfoError3;
    case wvcdm::GET_USAGE_INFO_ERROR_4:
      return kGetUsageInfoError4;
    case wvcdm::INIT_DATA_NOT_FOUND:
      return kInitDataNotFound;
    case wvcdm::INVALID_CRYPTO_SESSION_1:
      return kInvalidCryptoSession1;
    case wvcdm::INVALID_CRYPTO_SESSION_2:
      return kInvalidCryptoSession2;
    case wvcdm::INVALID_CRYPTO_SESSION_3:
      return kInvalidCryptoSession3;
    case wvcdm::INVALID_CRYPTO_SESSION_4:
      return kInvalidCryptoSession4;
    case wvcdm::INVALID_CRYPTO_SESSION_5:
      return kInvalidCryptoSession5;
    case wvcdm::INVALID_DECRYPT_PARAMETERS_ENG_1:
      return kInvalidDecryptParametersEng1;
    case wvcdm::INVALID_DECRYPT_PARAMETERS_ENG_2:
      return kInvalidDecryptParametersEng2;
    case wvcdm::INVALID_DECRYPT_PARAMETERS_ENG_3:
      return kInvalidDecryptParametersEng3;
    case wvcdm::INVALID_DECRYPT_PARAMETERS_ENG_4:
      return kInvalidDecryptParametersEng4;
    case wvcdm::SESSION_NOT_FOUND_FOR_DECRYPT:
      return android::ERROR_DRM_SESSION_NOT_OPENED;
    case wvcdm::INVALID_DEVICE_CERTIFICATE_TYPE:
      return kInvalidDeviceCertificateType;
    case wvcdm::INVALID_KEY_SYSTEM:
      return kInvalidKeySystem;
    case wvcdm::INVALID_LICENSE_RESPONSE:
      return kInvalidLicenseResponse;
    case wvcdm::INVALID_LICENSE_TYPE:
      return kInvalidLicenseType;
    case wvcdm::INVALID_PARAMETERS_ENG_1:
      return kInvalidParametersEng1;
    case wvcdm::INVALID_PARAMETERS_ENG_2:
      return kInvalidParametersEng2;
    case wvcdm::INVALID_PARAMETERS_ENG_3:
      return kInvalidParametersEng3;
    case wvcdm::INVALID_PARAMETERS_ENG_4:
      return kInvalidParametersEng4;
    case wvcdm::INVALID_PARAMETERS_ENG_5:
      return kInvalidParametersEng5;
    case wvcdm::INVALID_PARAMETERS_LIC_1:
      return kInvalidParametersLic1;
    case wvcdm::INVALID_PARAMETERS_LIC_2:
      return kInvalidParametersLic2;
    case wvcdm::INVALID_PROVISIONING_PARAMETERS_1:
      return kInvalidProvisioningParam1;
    case wvcdm::INVALID_PROVISIONING_PARAMETERS_2:
      return kInvalidProvisioningParam2;
    case wvcdm::INVALID_PROVISIONING_REQUEST_PARAM_1:
      return kInvalidProvisioningReqParam1;
    case wvcdm::INVALID_PROVISIONING_REQUEST_PARAM_2:
      return kInvalidProvisioningReqParam2;
    case wvcdm::INVALID_QUERY_KEY:
      return kInvalidQueryKey;
    case wvcdm::INVALID_SESSION_ID:
      return kInvalidSessionId;
    case wvcdm::KEY_REQUEST_ERROR_1:
      return kKeyRequestError1;
    case wvcdm::KEY_SIZE_ERROR:
      return kKeySizeError;
    case wvcdm::KEYSET_ID_NOT_FOUND_1:
      return kKeySetIdNotFound1;
    case wvcdm::KEYSET_ID_NOT_FOUND_2:
      return kKeySetIdNotFound2;
    case wvcdm::KEYSET_ID_NOT_FOUND_3:
      return kKeySetIdNotFound3;
    case wvcdm::LICENSE_ID_NOT_FOUND:
      return kLicenseIdNotFound;
    case wvcdm::LICENSE_PARSER_INIT_ERROR:
      return kLicenseParserInitError;
    case wvcdm::LICENSE_PARSER_NOT_INITIALIZED_1:
      return kLicenseParserNotInitialized1;
    case wvcdm::LICENSE_PARSER_NOT_INITIALIZED_2:
      return kLicenseParserNotInitialized2;
    case wvcdm::LICENSE_PARSER_NOT_INITIALIZED_3:
      return kLicenseParserNotInitialized3;
    case wvcdm::LICENSE_RESPONSE_NOT_SIGNED:
      return kLicenseResponseNotSigned;
    case wvcdm::LICENSE_RESPONSE_PARSE_ERROR_1:
      return kLicenseResponseParseError1;
    case wvcdm::LICENSE_RESPONSE_PARSE_ERROR_2:
      return kLicenseResponseParseError2;
    case wvcdm::LICENSE_RESPONSE_PARSE_ERROR_3:
      return kLicenseResponseParseError3;
    case wvcdm::LOAD_KEY_ERROR:
      return kLoadKeyError;
    case wvcdm::NO_CONTENT_KEY:
      return kNoContentKey;
    case wvcdm::REFRESH_KEYS_ERROR:
      return kRefreshKeysError;
    case wvcdm::RELEASE_ALL_USAGE_INFO_ERROR_1:
      return kReleaseAllUsageInfoError1;
    case wvcdm::RELEASE_ALL_USAGE_INFO_ERROR_2:
      return kReleaseAllUsageInfoError2;
    case wvcdm::RELEASE_KEY_ERROR:
      return kReleaseKeyError;
    case wvcdm::RELEASE_KEY_REQUEST_ERROR:
      return kReleaseKeyRequestError;
    case wvcdm::RELEASE_LICENSE_ERROR_1:
      return kReleaseLicenseError1;
    case wvcdm::RELEASE_LICENSE_ERROR_2:
      return kReleaseLicenseError2;
    case wvcdm::RELEASE_USAGE_INFO_ERROR:
      return kReleaseUsageInfoError;
    case wvcdm::RENEW_KEY_ERROR_1:
      return kRenewKeyError1;
    case wvcdm::RENEW_KEY_ERROR_2:
      return kRenewKeyError2;
    case wvcdm::LICENSE_RENEWAL_SIGNING_ERROR:
      return kLicenseRenewalSigningError;
    case wvcdm::RESTORE_OFFLINE_LICENSE_ERROR_2:
      return kRestoreOfflineLicenseError2;
    case wvcdm::SESSION_INIT_ERROR_2:
      return kSessionInitError2;
    case wvcdm::SESSION_INIT_GET_KEYBOX_ERROR:
      return kSessionInitGetKeyboxError;
    case wvcdm::SESSION_NOT_FOUND_1:
      return kSessionNotFound1;
    case wvcdm::SESSION_NOT_FOUND_2:
      return kSessionNotFound2;
    case wvcdm::SESSION_NOT_FOUND_3:
      return kSessionNotFound3;
    case wvcdm::SESSION_NOT_FOUND_4:
      return kSessionNotFound4;
    case wvcdm::SESSION_NOT_FOUND_5:
      return kSessionNotFound5;
    case wvcdm::SESSION_NOT_FOUND_6:
      return kSessionNotFound6;
    case wvcdm::SESSION_NOT_FOUND_7:
      return kSessionNotFound7;
    case wvcdm::SESSION_NOT_FOUND_8:
      return kSessionNotFound8;
    case wvcdm::SESSION_NOT_FOUND_9:
      return kSessionNotFound9;
    case wvcdm::SESSION_NOT_FOUND_10:
      return kSessionNotFound10;
    case wvcdm::SESSION_KEYS_NOT_FOUND:
      return kSessionKeysNotFound;
    case wvcdm::SIGNATURE_NOT_FOUND:
      return kSignatureNotFound;
    case wvcdm::STORE_LICENSE_ERROR_1:
      return kStoreLicenseError1;
    case wvcdm::STORE_LICENSE_ERROR_2:
      return kStoreLicenseError2;
    case wvcdm::STORE_USAGE_INFO_ERROR:
      return kStoreUsageInfoError;
    case wvcdm::UNPROVISION_ERROR_1:
      return kUnprovisioningError1;
    case wvcdm::UNPROVISION_ERROR_2:
      return kUnprovisioningError2;
    case wvcdm::UNPROVISION_ERROR_3:
      return kUnprovisioningError3;
    case wvcdm::UNPROVISION_ERROR_4:
      return kUnprovisioningError4;
    case wvcdm::UNSUPPORTED_INIT_DATA:
      return kUnsupportedInitData;
    case wvcdm::USAGE_INFO_NOT_FOUND:
      return kUsageInfoNotFound;
    case wvcdm::LICENSE_RENEWAL_SERVICE_CERTIFICATE_GENERATION_ERROR:
      return kLicenseRenewalServiceCertificateGenerationError;
    case wvcdm::PARSE_SERVICE_CERTIFICATE_ERROR:
      return kParseServiceCertificateError;
    case wvcdm::SERVICE_CERTIFICATE_TYPE_ERROR:
      return kServiceCertificateTypeError;
    case wvcdm::CLIENT_ID_GENERATE_RANDOM_ERROR:
      return kClientIdGenerateRandomError;
    case wvcdm::CLIENT_ID_AES_INIT_ERROR:
      return kClientIdAesInitError;
    case wvcdm::CLIENT_ID_AES_ENCRYPT_ERROR:
      return kClientIdAesEncryptError;
    case wvcdm::CLIENT_ID_RSA_INIT_ERROR:
      return kClientIdRsaInitError;
    case wvcdm::CLIENT_ID_RSA_ENCRYPT_ERROR:
      return kClientIdRsaEncryptError;
    case wvcdm::KEY_ERROR:
      // KEY_ERROR is used by the CDM to mean just about any kind of error, not
      // just license errors, so it is mapped to the generic response.
      return kErrorCDMGeneric;
    case wvcdm::INVALID_QUERY_STATUS:
      return kInvalidQueryStatus;
    case wvcdm::EMPTY_PROVISIONING_CERTIFICATE_2:
      return kEmptyProvisioningCertificate2;
    case wvcdm::LICENSE_PARSER_NOT_INITIALIZED_4:
      return kLicenseParserNotInitialized4;
    case wvcdm::INVALID_PARAMETERS_LIC_3:
      return kInvalidParametersLic3;
    case wvcdm::INVALID_PARAMETERS_LIC_4:
      return kInvalidParametersLic4;
    case wvcdm::INVALID_PARAMETERS_LIC_6:
      return kInvalidParametersLic6;
    case wvcdm::INVALID_PARAMETERS_LIC_7:
      return kInvalidParametersLic7;
    case wvcdm::LICENSE_REQUEST_SERVICE_CERTIFICATE_GENERATION_ERROR:
      return kLicenseRequestServiceCertificateGenerationError;
    case wvcdm::CENC_INIT_DATA_UNAVAILABLE:
      return kCencInitDataUnavailable;
    case wvcdm::PREPARE_CENC_CONTENT_ID_FAILED:
      return kPrepareCencContentIdFailed;
    case wvcdm::WEBM_INIT_DATA_UNAVAILABLE:
      return kWebmInitDataUnavailable;
    case wvcdm::PREPARE_WEBM_CONTENT_ID_FAILED:
      return kPrepareWebmContentIdFailed;
    case wvcdm::UNSUPPORTED_INIT_DATA_FORMAT:
      return kUnsupportedInitDataFormat;
    case wvcdm::LICENSE_REQUEST_NONCE_GENERATION_ERROR:
      return kLicenseRequestNonceGenerationError;
    case wvcdm::LICENSE_REQUEST_SIGNING_ERROR:
      return kLicenseRequestSigningError;
    case wvcdm::EMPTY_LICENSE_REQUEST:
      return kEmptyLicenseRequest;
    case wvcdm::DUPLICATE_SESSION_ID_SPECIFIED:
      return kDuplicateSessionIdSpecified;
    case wvcdm::LICENSE_RENEWAL_PROHIBITED:
      return kLicenseRenewalProhibited;
    case wvcdm::OFFLINE_LICENSE_PROHIBITED:
      return kOfflineLicenseProhibited;
    case wvcdm::STORAGE_PROHIBITED:
      return kStorageProhibited;
    case wvcdm::EMPTY_KEYSET_ID_ENG_5:
      return kEmptyKeySetIdEng5;
    case wvcdm::SESSION_NOT_FOUND_11:
      return kSessionNotFound11;
    case wvcdm::LOAD_USAGE_INFO_FILE_ERROR:
      return kLoadUsageInfoFileError;
    case wvcdm::LOAD_USAGE_INFO_MISSING:
      return kLoadUsageInfoMissing;
    case wvcdm::SESSION_FILE_HANDLE_INIT_ERROR:
      return kSessionFileHandleInitError;
    case wvcdm::INCORRECT_CRYPTO_MODE:
      return kIncorrectCryptoMode;
    case wvcdm::UNKNOWN_ERROR:
      return android::ERROR_DRM_UNKNOWN;
    case wvcdm::SECURE_BUFFER_REQUIRED:
      return android::ERROR_DRM_CANNOT_HANDLE;
    case wvcdm::DECRYPT_ERROR:
      return android::ERROR_DRM_CANNOT_HANDLE;
    case wvcdm::INSUFFICIENT_OUTPUT_PROTECTION:
      return android::ERROR_DRM_INSUFFICIENT_OUTPUT_PROTECTION;
    case wvcdm::UNUSED_1:
    case wvcdm::UNUSED_2:
    case wvcdm::UNUSED_3:
    case wvcdm::UNUSED_4:
    case wvcdm::UNUSED_5:
    case wvcdm::UNUSED_6:
      return android::UNKNOWN_ERROR;
  }

  // Return here instead of as a default case so that the compiler will warn
  // us if we forget to include an enum member in the switch statement.
  return android::UNKNOWN_ERROR;
}

static inline bool isCdmResponseTypeSuccess(wvcdm::CdmResponseType res) {
  return mapCdmResponseType(res) == android::OK;
}

} // namespace wvdrm

#endif // WV_MAP_ERRORS_H_
