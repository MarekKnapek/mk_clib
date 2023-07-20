#ifndef mk_include_guard_mk_win_bcrypt
#define mk_include_guard_mk_win_bcrypt


#include "mk_lang_concat.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_win_base_make_handle(bcrypt_handle);
mk_win_base_make_handle(bcrypt_alg);
mk_win_base_make_handle(bcrypt_key);


#define mk_win_bcrypt_bcrypt_rsa_algorithm               L"RSA"
#define mk_win_bcrypt_bcrypt_rsa_sign_algorithm          L"RSA_SIGN"
#define mk_win_bcrypt_bcrypt_dh_algorithm                L"DH"
#define mk_win_bcrypt_bcrypt_dsa_algorithm               L"DSA"
#define mk_win_bcrypt_bcrypt_rc2_algorithm               L"RC2"
#define mk_win_bcrypt_bcrypt_rc4_algorithm               L"RC4"
#define mk_win_bcrypt_bcrypt_aes_algorithm               L"AES"
#define mk_win_bcrypt_bcrypt_des_algorithm               L"DES"
#define mk_win_bcrypt_bcrypt_desx_algorithm              L"DESX"
#define mk_win_bcrypt_bcrypt_3des_algorithm              L"3DES"
#define mk_win_bcrypt_bcrypt_3des_112_algorithm          L"3DES_112"
#define mk_win_bcrypt_bcrypt_md2_algorithm               L"MD2"
#define mk_win_bcrypt_bcrypt_md4_algorithm               L"MD4"
#define mk_win_bcrypt_bcrypt_md5_algorithm               L"MD5"
#define mk_win_bcrypt_bcrypt_sha1_algorithm              L"SHA1"
#define mk_win_bcrypt_bcrypt_sha256_algorithm            L"SHA256"
#define mk_win_bcrypt_bcrypt_sha384_algorithm            L"SHA384"
#define mk_win_bcrypt_bcrypt_sha512_algorithm            L"SHA512"
#define mk_win_bcrypt_bcrypt_aes_gmac_algorithm          L"AES-GMAC"
#define mk_win_bcrypt_bcrypt_aes_cmac_algorithm          L"AES-CMAC"
#define mk_win_bcrypt_bcrypt_ecdsa_p256_algorithm        L"ECDSA_P256"
#define mk_win_bcrypt_bcrypt_ecdsa_p384_algorithm        L"ECDSA_P384"
#define mk_win_bcrypt_bcrypt_ecdsa_p521_algorithm        L"ECDSA_P521"
#define mk_win_bcrypt_bcrypt_ecdh_p256_algorithm         L"ECDH_P256"
#define mk_win_bcrypt_bcrypt_ecdh_p384_algorithm         L"ECDH_P384"
#define mk_win_bcrypt_bcrypt_ecdh_p521_algorithm         L"ECDH_P521"
#define mk_win_bcrypt_bcrypt_rng_algorithm               L"RNG"
#define mk_win_bcrypt_bcrypt_rng_fips186_dsa_algorithm   L"FIPS186DSARNG"
#define mk_win_bcrypt_bcrypt_rng_dual_ec_algorithm       L"DUALECRNG"
#define mk_win_bcrypt_bcrypt_sp800108_ctr_hmac_algorithm L"SP800_108_CTR_HMAC" /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_bcrypt_bcrypt_sp80056a_concat_algorithm   L"SP800_56A_CONCAT"   /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_bcrypt_bcrypt_pbkdf2_algorithm            L"PBKDF2"             /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_bcrypt_bcrypt_capi_kdf_algorithm          L"CAPI_KDF"           /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_bcrypt_bcrypt_tls1_1_kdf_algorithm        L"TLS1_1_KDF"         /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_bcrypt_bcrypt_tls1_2_kdf_algorithm        L"TLS1_2_KDF"         /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_bcrypt_bcrypt_ecdsa_algorithm             L"ECDSA"              /* NTDDI_VERSION >= NTDDI_WINTHRESHOLD */
#define mk_win_bcrypt_bcrypt_ecdh_algorithm              L"ECDH"               /* NTDDI_VERSION >= NTDDI_WINTHRESHOLD */
#define mk_win_bcrypt_bcrypt_xts_aes_algorithm           L"XTS-AES"            /* NTDDI_VERSION >= NTDDI_WINTHRESHOLD */
#define mk_win_bcrypt_bcrypt_hkdf_algorithm              L"HKDF"               /* NTDDI_VERSION >= NTDDI_WIN10_RS4 */
#define mk_win_bcrypt_bcrypt_chacha20_poly1305_algorithm L"CHACHA20_POLY1305"  /* NTDDI_VERSION >= NTDDI_WIN10_FE */

#define mk_win_bcrypt_ms_primitive_provider       L"Microsoft Primitive Provider"
#define mk_win_bcrypt_ms_platform_crypto_provider L"Microsoft Platform Crypto Provider"

#define mk_win_bcrypt_bcrypt_prov_dispatch        0x00000001ul
#define mk_win_bcrypt_bcrypt_alg_handle_hmac_flag 0x00000008ul
#define mk_win_bcrypt_bcrypt_hash_reusable_flag   0x00000020ul

#define mk_win_bcrypt_bcrypt_object_length                 L"ObjectLength"
#define mk_win_bcrypt_bcrypt_algorithm_name                L"AlgorithmName"
#define mk_win_bcrypt_bcrypt_provider_handle               L"ProviderHandle"
#define mk_win_bcrypt_bcrypt_chaining_mode                 L"ChainingMode"
#define mk_win_bcrypt_bcrypt_block_length                  L"BlockLength"
#define mk_win_bcrypt_bcrypt_key_length                    L"KeyLength"
#define mk_win_bcrypt_bcrypt_key_object_length             L"KeyObjectLength"
#define mk_win_bcrypt_bcrypt_key_strength                  L"KeyStrength"
#define mk_win_bcrypt_bcrypt_key_lengths                   L"KeyLengths"
#define mk_win_bcrypt_bcrypt_block_size_list               L"BlockSizeList"
#define mk_win_bcrypt_bcrypt_effective_key_length          L"EffectiveKeyLength"
#define mk_win_bcrypt_bcrypt_hash_length                   L"HashDigestLength"
#define mk_win_bcrypt_bcrypt_hash_oid_list                 L"HashOIDList"
#define mk_win_bcrypt_bcrypt_padding_schemes               L"PaddingSchemes"
#define mk_win_bcrypt_bcrypt_signature_length              L"SignatureLength"
#define mk_win_bcrypt_bcrypt_hash_block_length             L"HashBlockLength"
#define mk_win_bcrypt_bcrypt_auth_tag_length               L"AuthTagLength"
#define mk_win_bcrypt_bcrypt_primitive_type                L"PrimitiveType"        /* NTDDI_VERSION >= NTDDI_WIN7 */
#define mk_win_bcrypt_bcrypt_is_keyed_hash                 L"IsKeyedHash"          /* NTDDI_VERSION >= NTDDI_WIN7 */
#define mk_win_bcrypt_bcrypt_is_reusable_hash              L"IsReusableHash"       /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_bcrypt_bcrypt_message_block_length          L"MessageBlockLength"   /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_bcrypt_bcrypt_public_key_length             L"PublicKeyLength"      /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_bcrypt_bcrypt_pcp_platform_type_property    L"PCP_PLATFORM_TYPE"
#define mk_win_bcrypt_bcrypt_pcp_provider_version_property L"PCP_PROVIDER_VERSION"
#define mk_win_bcrypt_bcrypt_multi_object_length           L"MultiObjectLength"    /* NTDDI_VERSION > NTDDI_WINBLUE || (NTDDI_VERSION == NTDDI_WINBLUE && definedmk_win_bcrypt_( )) */
#define mk_win_bcrypt_bcrypt_is_ifx_tpm_weak_key           L"IsIfxTpmWeakKey"      /* NTDDI_VERSION >= NTDDI_WIN10_RS4 */
#define mk_win_bcrypt_bcrypt_hkdf_hash_algorithm           L"HkdfHashAlgorithm"    /* NTDDI_VERSION >= NTDDI_WIN10_RS4 */
#define mk_win_bcrypt_bcrypt_hkdf_salt_and_finalize        L"HkdfSaltAndFinalize"  /* NTDDI_VERSION >= NTDDI_WIN10_RS4 */
#define mk_win_bcrypt_bcrypt_hkdf_prk_and_finalize         L"HkdfPrkAndFinalize"   /* NTDDI_VERSION >= NTDDI_WIN10_RS4 */

#define mk_win_bcrypt_bcrypt_chain_mode_na  L"ChainingModeN/A"
#define mk_win_bcrypt_bcrypt_chain_mode_cbc L"ChainingModeCBC"
#define mk_win_bcrypt_bcrypt_chain_mode_ecb L"ChainingModeECB"
#define mk_win_bcrypt_bcrypt_chain_mode_cfb L"ChainingModeCFB"
#define mk_win_bcrypt_bcrypt_chain_mode_ccm L"ChainingModeCCM"
#define mk_win_bcrypt_bcrypt_chain_mode_gcm L"ChainingModeGCM"

#define mk_win_bcrypt_bcrypt_block_padding 0x00000001ul


mk_lang_extern_c mk_win_base_dllimport mk_win_base_ntstatus_t mk_win_base_stdcall BCryptOpenAlgorithmProvider(mk_win_handle_bcrypt_alg_pt const alg, mk_win_base_wchar_pct const alg_id, mk_win_base_wchar_pct const implementation, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dllimport mk_win_base_ntstatus_t mk_win_base_stdcall BCryptCloseAlgorithmProvider(mk_win_handle_bcrypt_alg_t const alg, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dllimport mk_win_base_ntstatus_t mk_win_base_stdcall BCryptGetProperty(mk_win_handle_bcrypt_handle_t const handle, mk_win_base_wchar_pct const property, mk_lang_types_uchar_pt const data, mk_lang_types_ulong_t const data_len, mk_lang_types_ulong_pt const data_len_real, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dllimport mk_win_base_ntstatus_t mk_win_base_stdcall BCryptSetProperty(mk_win_handle_bcrypt_handle_t const handle, mk_win_base_wchar_pct const property, mk_lang_types_uchar_pct const data, mk_lang_types_ulong_t const data_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dllimport mk_win_base_ntstatus_t mk_win_base_stdcall BCryptGenerateSymmetricKey(mk_win_handle_bcrypt_alg_t const alg, mk_win_handle_bcrypt_key_pt const key, mk_lang_types_uchar_pt const key_obj, mk_lang_types_ulong_t const key_obj_len, mk_lang_types_uchar_pct const secret, mk_lang_types_ulong_t const secret_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dllimport mk_win_base_ntstatus_t mk_win_base_stdcall BCryptDestroyKey(mk_win_handle_bcrypt_key_t const key) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dllimport mk_win_base_ntstatus_t mk_win_base_stdcall BCryptEncrypt(mk_win_handle_bcrypt_key_t const key, mk_lang_types_uchar_pct const msg, mk_lang_types_ulong_t const msg_len, mk_lang_types_uchar_pct const padding, mk_lang_types_uchar_pt const iv, mk_lang_types_ulong_t const iv_len, mk_lang_types_uchar_pt const out, mk_lang_types_ulong_t const out_len, mk_lang_types_ulong_pt const out_len_real, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dllimport mk_win_base_ntstatus_t mk_win_base_stdcall BCryptDecrypt(mk_win_handle_bcrypt_key_t const key, mk_lang_types_uchar_pct const msg, mk_lang_types_ulong_t const msg_len, mk_lang_types_uchar_pct const padding, mk_lang_types_uchar_pt const iv, mk_lang_types_ulong_t const iv_len, mk_lang_types_uchar_pt const out, mk_lang_types_ulong_t const out_len, mk_lang_types_ulong_pt const out_len_real, mk_lang_types_ulong_t const flags) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_bcrypt.c"
#endif
#endif
