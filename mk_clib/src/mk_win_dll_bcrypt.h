#ifndef mk_include_guard_mk_win_dll_bcrypt_h
#define mk_include_guard_mk_win_dll_bcrypt_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_win_base_make_handle(mk_win_dll_bcrypt_handle)
mk_win_base_make_handle(mk_win_dll_bcrypt_hash)
mk_win_base_make_handle(mk_win_dll_bcrypt_key)
mk_win_base_make_handle(mk_win_dll_bcrypt_provider)


#define mk_win_dll_bcrypt_k_algorithm_rsa               L"RSA"
#define mk_win_dll_bcrypt_k_algorithm_rsa_sign          L"RSA_SIGN"
#define mk_win_dll_bcrypt_k_algorithm_dh                L"DH"
#define mk_win_dll_bcrypt_k_algorithm_dsa               L"DSA"
#define mk_win_dll_bcrypt_k_algorithm_rc2               L"RC2"
#define mk_win_dll_bcrypt_k_algorithm_rc4               L"RC4"
#define mk_win_dll_bcrypt_k_algorithm_aes               L"AES"
#define mk_win_dll_bcrypt_k_algorithm_des               L"DES"
#define mk_win_dll_bcrypt_k_algorithm_desx              L"DESX"
#define mk_win_dll_bcrypt_k_algorithm_3des              L"3DES"
#define mk_win_dll_bcrypt_k_algorithm_3des_112          L"3DES_112"
#define mk_win_dll_bcrypt_k_algorithm_md2               L"MD2"
#define mk_win_dll_bcrypt_k_algorithm_md4               L"MD4"
#define mk_win_dll_bcrypt_k_algorithm_md5               L"MD5"
#define mk_win_dll_bcrypt_k_algorithm_sha1              L"SHA1"
#define mk_win_dll_bcrypt_k_algorithm_sha256            L"SHA256"
#define mk_win_dll_bcrypt_k_algorithm_sha384            L"SHA384"
#define mk_win_dll_bcrypt_k_algorithm_sha512            L"SHA512"
#define mk_win_dll_bcrypt_k_algorithm_aes_gmac          L"AES-GMAC"
#define mk_win_dll_bcrypt_k_algorithm_aes_cmac          L"AES-CMAC"
#define mk_win_dll_bcrypt_k_algorithm_ecdsa_p256        L"ECDSA_P256"
#define mk_win_dll_bcrypt_k_algorithm_ecdsa_p384        L"ECDSA_P384"
#define mk_win_dll_bcrypt_k_algorithm_ecdsa_p521        L"ECDSA_P521"
#define mk_win_dll_bcrypt_k_algorithm_ecdh_p256         L"ECDH_P256"
#define mk_win_dll_bcrypt_k_algorithm_ecdh_p384         L"ECDH_P384"
#define mk_win_dll_bcrypt_k_algorithm_ecdh_p521         L"ECDH_P521"
#define mk_win_dll_bcrypt_k_algorithm_rng               L"RNG"
#define mk_win_dll_bcrypt_k_algorithm_rng_fips186_dsa   L"FIPS186DSARNG"
#define mk_win_dll_bcrypt_k_algorithm_rng_dual_ec       L"DUALECRNG"
#define mk_win_dll_bcrypt_k_algorithm_sp800108_ctr_hmac L"SP800_108_CTR_HMAC" /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_dll_bcrypt_k_algorithm_sp80056a_concat   L"SP800_56A_CONCAT"   /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_dll_bcrypt_k_algorithm_pbkdf2            L"PBKDF2"             /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_dll_bcrypt_k_algorithm_capi_kdf          L"CAPI_KDF"           /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_dll_bcrypt_k_algorithm_tls1_1_kdf        L"TLS1_1_KDF"         /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_dll_bcrypt_k_algorithm_tls1_2_kdf        L"TLS1_2_KDF"         /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_dll_bcrypt_k_algorithm_ecdsa             L"ECDSA"              /* NTDDI_VERSION >= NTDDI_WINTHRESHOLD */
#define mk_win_dll_bcrypt_k_algorithm_ecdh              L"ECDH"               /* NTDDI_VERSION >= NTDDI_WINTHRESHOLD */
#define mk_win_dll_bcrypt_k_algorithm_xts_aes           L"XTS-AES"            /* NTDDI_VERSION >= NTDDI_WINTHRESHOLD */
#define mk_win_dll_bcrypt_k_algorithm_hkdf              L"HKDF"               /* NTDDI_VERSION >= NTDDI_WIN10_RS4 */
#define mk_win_dll_bcrypt_k_algorithm_chacha20_poly1305 L"CHACHA20_POLY1305"  /* NTDDI_VERSION >= NTDDI_WIN10_FE */

#define mk_win_dll_bcrypt_k_provider_ms_primitive       L"Microsoft Primitive Provider"
#define mk_win_dll_bcrypt_k_provider_ms_platform_crypto L"Microsoft Platform Crypto Provider"

#define mk_win_dll_bcrypt_k_flag_none            0x00000000ul
#define mk_win_dll_bcrypt_k_flag_prov_dispatch   0x00000001ul
#define mk_win_dll_bcrypt_k_flag_alg_handle_hmac 0x00000008ul
#define mk_win_dll_bcrypt_k_flag_hash_reusable   0x00000020ul

#define mk_win_dll_bcrypt_k_flag_rng_use_entropy_in_buffer 0x00000001ul
#define mk_win_dll_bcrypt_k_flag_use_system_preferred_rng  0x00000002ul

#define mk_win_dll_bcrypt_k_object_length                 L"ObjectLength"
#define mk_win_dll_bcrypt_k_algorithm_name                L"AlgorithmName"
#define mk_win_dll_bcrypt_k_provider_handle               L"ProviderHandle"
#define mk_win_dll_bcrypt_k_chaining_mode                 L"ChainingMode"
#define mk_win_dll_bcrypt_k_block_length                  L"BlockLength"
#define mk_win_dll_bcrypt_k_key_length                    L"KeyLength"
#define mk_win_dll_bcrypt_k_key_object_length             L"KeyObjectLength"
#define mk_win_dll_bcrypt_k_key_strength                  L"KeyStrength"
#define mk_win_dll_bcrypt_k_key_lengths                   L"KeyLengths"
#define mk_win_dll_bcrypt_k_block_size_list               L"BlockSizeList"
#define mk_win_dll_bcrypt_k_effective_key_length          L"EffectiveKeyLength"
#define mk_win_dll_bcrypt_k_hash_length                   L"HashDigestLength"
#define mk_win_dll_bcrypt_k_hash_oid_list                 L"HashOIDList"
#define mk_win_dll_bcrypt_k_padding_schemes               L"PaddingSchemes"
#define mk_win_dll_bcrypt_k_signature_length              L"SignatureLength"
#define mk_win_dll_bcrypt_k_hash_block_length             L"HashBlockLength"
#define mk_win_dll_bcrypt_k_auth_tag_length               L"AuthTagLength"
#define mk_win_dll_bcrypt_k_primitive_type                L"PrimitiveType"       /* NTDDI_VERSION >= NTDDI_WIN7 */
#define mk_win_dll_bcrypt_k_is_keyed_hash                 L"IsKeyedHash"         /* NTDDI_VERSION >= NTDDI_WIN7 */
#define mk_win_dll_bcrypt_k_is_reusable_hash              L"IsReusableHash"      /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_dll_bcrypt_k_message_block_length          L"MessageBlockLength"  /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_dll_bcrypt_k_public_key_length             L"PublicKeyLength"     /* NTDDI_VERSION >= NTDDI_WIN8 */
#define mk_win_dll_bcrypt_k_multi_object_length           L"MultiObjectLength"   /* NTDDI_VERSION > NTDDI_WINBLUE || (NTDDI_VERSION == NTDDI_WINBLUE && defined(WINBLUE_KBSPRING14)) */
#define mk_win_dll_bcrypt_k_is_ifx_tpm_weak_key           L"IsIfxTpmWeakKey"     /* NTDDI_VERSION >= NTDDI_WIN10_RS4 */
#define mk_win_dll_bcrypt_k_hkdf_hash_algorithm           L"HkdfHashAlgorithm"   /* NTDDI_VERSION >= NTDDI_WIN10_RS4 */
#define mk_win_dll_bcrypt_k_hkdf_salt_and_finalize        L"HkdfSaltAndFinalize" /* NTDDI_VERSION >= NTDDI_WIN10_RS4 */
#define mk_win_dll_bcrypt_k_hkdf_prk_and_finalize         L"HkdfPrkAndFinalize"  /* NTDDI_VERSION >= NTDDI_WIN10_RS4 */
#define mk_win_dll_bcrypt_k_pcp_platform_type_property    L"PCP_PLATFORM_TYPE"
#define mk_win_dll_bcrypt_k_pcp_provider_version_property L"PCP_PROVIDER_VERSION"

#define mk_win_dll_bcrypt_k_chain_mode_na  L"ChainingModeN/A"
#define mk_win_dll_bcrypt_k_chain_mode_cbc L"ChainingModeCBC"
#define mk_win_dll_bcrypt_k_chain_mode_ecb L"ChainingModeECB"
#define mk_win_dll_bcrypt_k_chain_mode_cfb L"ChainingModeCFB"
#define mk_win_dll_bcrypt_k_chain_mode_ccm L"ChainingModeCCM"
#define mk_win_dll_bcrypt_k_chain_mode_gcm L"ChainingModeGCM"

#define mk_win_dll_bcrypt_k_block_padding 0x00000001ul


struct mk_win_dll_bcrypt_key_lengths_s
{
	mk_win_base_ulong_t m_min;
	mk_win_base_ulong_t m_max;
	mk_win_base_ulong_t m_increment;
};
typedef struct mk_win_dll_bcrypt_key_lengths_s mk_win_dll_bcrypt_key_lengths_t;
mk_lang_typedef(mk_win_dll_bcrypt_key_lengths);

struct mk_win_dll_bcrypt_buffer_description_s
{
	mk_win_base_ulong_t m_bytes_count;
	mk_win_base_ulong_t m_type;
	mk_win_base_void_pt m_bytes_array;
};
typedef struct mk_win_dll_bcrypt_buffer_description_s mk_win_dll_bcrypt_buffer_description_t;
mk_lang_typedef(mk_win_dll_bcrypt_buffer_description);

struct mk_win_dll_bcrypt_buffers_descriptions_s
{
	mk_win_base_ulong_t m_version;
	mk_win_base_ulong_t m_buffers_count;
	mk_win_dll_bcrypt_buffer_description_pt m_buffers_array;
};
typedef struct mk_win_dll_bcrypt_buffers_descriptions_s mk_win_dll_bcrypt_buffers_descriptions_t;
mk_lang_typedef(mk_win_dll_bcrypt_buffers_descriptions);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_win_dll_bcrypt_authenticated_cipher_mode_info_s
{
	mk_win_base_ulong_t m_size;
	mk_win_base_ulong_t m_version;
	mk_win_base_uchar_pt m_nonce;
	mk_win_base_ulong_t m_nonce_len;
	mk_win_base_uchar_pt m_aad;
	mk_win_base_ulong_t m_aad_len;
	mk_win_base_uchar_pt m_tag;
	mk_win_base_ulong_t m_tag_len;
	mk_win_base_uchar_pt m_mac_ctx;
	mk_win_base_ulong_t m_mac_ctx_len;
	mk_win_base_ulong_t m_aad_ctx_len;
	mk_win_base_ulong_t m_data_ctx_len_lo;
	mk_win_base_ulong_t m_data_ctx_len_hi;
	mk_win_base_ulong_t m_flags;
};
typedef struct mk_win_dll_bcrypt_authenticated_cipher_mode_info_s mk_win_dll_bcrypt_authenticated_cipher_mode_info_t;
mk_lang_typedef(mk_win_dll_bcrypt_authenticated_cipher_mode_info);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_open_algorithm_provider(mk_win_dll_bcrypt_provider_pt const provider, mk_win_base_wchar_pct const alg_id, mk_win_base_wchar_pct const implementation, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_close_algorithm_provider(mk_win_dll_bcrypt_provider_t const provider, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_gen_random(mk_win_dll_bcrypt_provider_t const provider, mk_lang_types_void_pt const data_buf, mk_lang_types_ulong_t const data_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_get_property(mk_win_dll_bcrypt_handle_t const handle, mk_win_base_wchar_pct const property, mk_lang_types_void_pt const data_buf, mk_lang_types_ulong_t const data_len_provided, mk_lang_types_ulong_pt const data_len_real, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_set_property(mk_win_dll_bcrypt_handle_t const handle, mk_win_base_wchar_pct const property, mk_lang_types_void_pct const data_buf, mk_lang_types_ulong_t const data_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_create_hash(mk_win_dll_bcrypt_provider_t const provider, mk_win_dll_bcrypt_hash_pt const hasher, mk_lang_types_void_pt const obj_buf, mk_lang_types_ulong_t const obj_len, mk_lang_types_void_pct const secret_buf, mk_lang_types_ulong_t const secret_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_destroy_hash(mk_win_dll_bcrypt_hash_t const hasher) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_hash_data(mk_win_dll_bcrypt_hash_t const hasher, mk_lang_types_void_pct const data_buf, mk_lang_types_ulong_t const data_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_finish_hash(mk_win_dll_bcrypt_hash_t const hasher, mk_lang_types_void_pt const digest_buf, mk_lang_types_ulong_t const digest_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_generate_symmetric_key(mk_win_dll_bcrypt_provider_t const provider, mk_win_dll_bcrypt_key_pt const key_obj, mk_lang_types_void_pt const key_buf, mk_lang_types_ulong_t const key_len, mk_lang_types_void_pct const secret_buf, mk_lang_types_ulong_t const secret_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_destroy_key(mk_win_dll_bcrypt_key_t const key) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_key_derivation(mk_win_dll_bcrypt_key_t const key, mk_win_dll_bcrypt_buffers_descriptions_pt const parameter_list, mk_lang_types_void_pt const key_buf, mk_lang_types_ulong_t const key_len, mk_lang_types_ulong_pt const out_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_pbkdf2(mk_win_dll_bcrypt_provider_t const prf, mk_win_base_void_pct const password_buf, mk_win_base_ulong_t const password_len, mk_win_base_void_pct const salt_buf, mk_win_base_ulong_t const salt_len, mk_win_base_ullong_t const iterations, mk_win_base_void_pt const key_buf, mk_win_base_ulong_t const key_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_encrypt(mk_win_dll_bcrypt_key_t const key, mk_lang_types_void_pct const msg_buf, mk_lang_types_ulong_t const msg_len, mk_lang_types_void_pct const padding, mk_lang_types_void_pt const iv_buf, mk_lang_types_ulong_t const iv_len, mk_lang_types_void_pt const out_buf, mk_lang_types_ulong_t const out_len_provided, mk_lang_types_ulong_pt const out_len_real, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_decrypt(mk_win_dll_bcrypt_key_t const key, mk_lang_types_void_pct const msg_buf, mk_lang_types_ulong_t const msg_len, mk_lang_types_void_pct const padding, mk_lang_types_void_pt const iv_buf, mk_lang_types_ulong_t const iv_len, mk_lang_types_void_pt const out_buf, mk_lang_types_ulong_t const out_len_provided, mk_lang_types_ulong_pt const out_len_real, mk_lang_types_ulong_t const flags) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_win_dll_bcrypt.c"
#endif
#endif
