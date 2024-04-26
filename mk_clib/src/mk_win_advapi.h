#ifndef mk_include_guard_mk_win_advapi
#define mk_include_guard_mk_win_advapi


#include "mk_lang_concat.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


typedef mk_lang_types_uint_t mk_win_advapi_algid_t;
typedef mk_win_advapi_algid_t const mk_win_advapi_algid_ct;
typedef mk_win_advapi_algid_t* mk_win_advapi_algid_pt;
typedef mk_win_advapi_algid_t const* mk_win_advapi_algid_pct;

struct mk_win_advapi_blob_header_s
{
	mk_lang_types_uchar_t m_type;
	mk_lang_types_uchar_t m_version;
	mk_win_base_word_t m_reserved;
	mk_win_advapi_algid_t m_alg_id;
};
typedef struct mk_win_advapi_blob_header_s mk_win_advapi_blob_header_t;
typedef mk_win_advapi_blob_header_t const mk_win_advapi_blob_header_ct;
typedef mk_win_advapi_blob_header_t* mk_win_advapi_blob_header_pt;
typedef mk_win_advapi_blob_header_t const* mk_win_advapi_blob_header_pct;

mk_win_base_make_handle(mk_win_handle_advapi_prov)
mk_win_base_make_handle(mk_win_handle_advapi_key)
mk_win_base_make_handle(mk_win_handle_advapi_hash)

#define mk_win_advapi_ms_def_prov_a              "Microsoft Base Cryptographic Provider v1.0"
#define mk_win_advapi_ms_enhanced_prov_a         "Microsoft Enhanced Cryptographic Provider v1.0"
#define mk_win_advapi_ms_strong_prov_a           "Microsoft Strong Cryptographic Provider"
#define mk_win_advapi_ms_def_rsa_sig_prov_a      "Microsoft RSA Signature Cryptographic Provider"
#define mk_win_advapi_ms_def_rsa_schannel_prov_a "Microsoft RSA SChannel Cryptographic Provider"
#define mk_win_advapi_ms_def_dss_prov_a          "Microsoft Base DSS Cryptographic Provider"
#define mk_win_advapi_ms_def_dss_dh_prov_a       "Microsoft Base DSS and Diffie-Hellman Cryptographic Provider"
#define mk_win_advapi_ms_enh_dss_dh_prov_a       "Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider"
#define mk_win_advapi_ms_def_dh_schannel_prov_a  "Microsoft DH SChannel Cryptographic Provider"
#define mk_win_advapi_ms_scard_prov_a            "Microsoft Base Smart Card Crypto Provider"
#define mk_win_advapi_ms_enh_rsa_aes_prov_a      "Microsoft Enhanced RSA and AES Cryptographic Provider"
#define mk_win_advapi_ms_enh_rsa_aes_prov_xp_a   "Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"

#define mk_win_advapi_ms_def_prov_w              mk_lang_concat(L, mk_win_advapi_ms_def_prov_a             )
#define mk_win_advapi_ms_enhanced_prov_w         mk_lang_concat(L, mk_win_advapi_ms_enhanced_prov_a        )
#define mk_win_advapi_ms_strong_prov_w           mk_lang_concat(L, mk_win_advapi_ms_strong_prov_a          )
#define mk_win_advapi_ms_def_rsa_sig_prov_w      mk_lang_concat(L, mk_win_advapi_ms_def_rsa_sig_prov_a     )
#define mk_win_advapi_ms_def_rsa_schannel_prov_w mk_lang_concat(L, mk_win_advapi_ms_def_rsa_schannel_prov_a)
#define mk_win_advapi_ms_def_dss_prov_w          mk_lang_concat(L, mk_win_advapi_ms_def_dss_prov_a         )
#define mk_win_advapi_ms_def_dss_dh_prov_w       mk_lang_concat(L, mk_win_advapi_ms_def_dss_dh_prov_a      )
#define mk_win_advapi_ms_enh_dss_dh_prov_w       mk_lang_concat(L, mk_win_advapi_ms_enh_dss_dh_prov_a      )
#define mk_win_advapi_ms_def_dh_schannel_prov_w  mk_lang_concat(L, mk_win_advapi_ms_def_dh_schannel_prov_a )
#define mk_win_advapi_ms_scard_prov_w            mk_lang_concat(L, mk_win_advapi_ms_scard_prov_a           )
#define mk_win_advapi_ms_enh_rsa_aes_prov_w      mk_lang_concat(L, mk_win_advapi_ms_enh_rsa_aes_prov_a     )
#define mk_win_advapi_ms_enh_rsa_aes_prov_xp_w   mk_lang_concat(L, mk_win_advapi_ms_enh_rsa_aes_prov_xp_a  )

#define mk_win_advapi_prov_rsa_full      1
#define mk_win_advapi_prov_rsa_sig       2
#define mk_win_advapi_prov_dss           3
#define mk_win_advapi_prov_fortezza      4
#define mk_win_advapi_prov_ms_exchange   5
#define mk_win_advapi_prov_ssl           6
#define mk_win_advapi_prov_rsa_schannel  12
#define mk_win_advapi_prov_dss_dh        13
#define mk_win_advapi_prov_ec_ecdsa_sig  14
#define mk_win_advapi_prov_ec_ecnra_sig  15
#define mk_win_advapi_prov_ec_ecdsa_full 16
#define mk_win_advapi_prov_ec_ecnra_full 17
#define mk_win_advapi_prov_dh_schannel   18
#define mk_win_advapi_prov_spyrus_lynks  20
#define mk_win_advapi_prov_rng           21
#define mk_win_advapi_prov_intel_sec     22
#define mk_win_advapi_prov_replace_owf   23 /* NTDDI_VERSION >= NTDDI_WINXP */
#define mk_win_advapi_prov_rsa_aes       24 /* NTDDI_VERSION >= NTDDI_WINXP */

#define mk_win_advapi_crypt_verifycontext              0xf0000000ul
#define mk_win_advapi_crypt_newkeyset                  0x00000008ul
#define mk_win_advapi_crypt_deletekeyset               0x00000010ul
#define mk_win_advapi_crypt_machine_keyset             0x00000020ul
#define mk_win_advapi_crypt_silent                     0x00000040ul
#define mk_win_advapi_crypt_default_container_optional 0x00000080ul /* NTDDI_VERSION >= NTDDI_VISTA */

#define mk_win_advapi_simpleblob           0x1
#define mk_win_advapi_publickeyblob        0x6
#define mk_win_advapi_privatekeyblob       0x7
#define mk_win_advapi_plaintextkeyblob     0x8
#define mk_win_advapi_opaquekeyblob        0x9
#define mk_win_advapi_publickeyblobex      0xa
#define mk_win_advapi_symmetricwrapkeyblob 0xb
#define mk_win_advapi_keystateblob         0xc /* NTDDI_VERSION >= NTDDI_WS03 */

#define mk_win_advapi_cur_blob_version 2

#define mk_win_advapi_alg_class_any          (0 << 13)
#define mk_win_advapi_alg_class_signature    (1 << 13)
#define mk_win_advapi_alg_class_msg_encrypt  (2 << 13)
#define mk_win_advapi_alg_class_data_encrypt (3 << 13)
#define mk_win_advapi_alg_class_hash         (4 << 13)
#define mk_win_advapi_alg_class_key_exchange (5 << 13)
#define mk_win_advapi_alg_class_all          (7 << 13)

#define mk_win_advapi_alg_type_any           (0 << 9)
#define mk_win_advapi_alg_type_dss           (1 << 9)
#define mk_win_advapi_alg_type_rsa           (2 << 9)
#define mk_win_advapi_alg_type_block         (3 << 9)
#define mk_win_advapi_alg_type_stream        (4 << 9)
#define mk_win_advapi_alg_type_dh            (5 << 9)
#define mk_win_advapi_alg_type_securechannel (6 << 9)
#define mk_win_advapi_alg_type_ecdh          (7 << 9) /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_alg_type_thirdparty    (8 << 9) /* NTDDI_VERSION >= NTDDI_WIN10_RS1 */

#define mk_win_advapi_alg_sid_any                   0
#define mk_win_advapi_alg_sid_thirdparty_any        0 /* NTDDI_VERSION >= NTDDI_WIN10_RS1 */
#define mk_win_advapi_alg_sid_rsa_any               0
#define mk_win_advapi_alg_sid_rsa_pkcs              1
#define mk_win_advapi_alg_sid_rsa_msatwork          2
#define mk_win_advapi_alg_sid_rsa_entrust           3
#define mk_win_advapi_alg_sid_rsa_pgp               4
#define mk_win_advapi_alg_sid_dss_any               0
#define mk_win_advapi_alg_sid_dss_pkcs              1
#define mk_win_advapi_alg_sid_dss_dms               2
#define mk_win_advapi_alg_sid_ecdsa                 3 /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_alg_sid_des                   1
#define mk_win_advapi_alg_sid_3des                  3
#define mk_win_advapi_alg_sid_desx                  4
#define mk_win_advapi_alg_sid_idea                  5
#define mk_win_advapi_alg_sid_cast                  6
#define mk_win_advapi_alg_sid_safersk64             7
#define mk_win_advapi_alg_sid_safersk128            8
#define mk_win_advapi_alg_sid_3des_112              9
#define mk_win_advapi_alg_sid_cylink_mek           12
#define mk_win_advapi_alg_sid_rc5                  13
#define mk_win_advapi_alg_sid_aes_128              14 /* NTDDI_VERSION >= NTDDI_WINXP */
#define mk_win_advapi_alg_sid_aes_192              15 /* NTDDI_VERSION >= NTDDI_WINXP */
#define mk_win_advapi_alg_sid_aes_256              16 /* NTDDI_VERSION >= NTDDI_WINXP */
#define mk_win_advapi_alg_sid_aes                  17 /* NTDDI_VERSION >= NTDDI_WINXP */
#define mk_win_advapi_alg_sid_skipjack             10
#define mk_win_advapi_alg_sid_tek                  11
#define mk_win_advapi_crypt_mode_cbci               6
#define mk_win_advapi_crypt_mode_cfbp               7
#define mk_win_advapi_crypt_mode_ofbp               8
#define mk_win_advapi_crypt_mode_cbcofm             9
#define mk_win_advapi_crypt_mode_cbcofmi           10
#define mk_win_advapi_alg_sid_rc2                   2
#define mk_win_advapi_alg_sid_rc4                   1
#define mk_win_advapi_alg_sid_seal                  2
#define mk_win_advapi_alg_sid_dh_sandf              1
#define mk_win_advapi_alg_sid_dh_ephem              2
#define mk_win_advapi_alg_sid_agreed_key_any        3
#define mk_win_advapi_alg_sid_kea                   4
#define mk_win_advapi_alg_sid_ecdh                  5 /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_alg_sid_ecdh_ephem            6 /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_alg_sid_md2                   1
#define mk_win_advapi_alg_sid_md4                   2
#define mk_win_advapi_alg_sid_md5                   3
#define mk_win_advapi_alg_sid_sha                   4
#define mk_win_advapi_alg_sid_sha1                  4
#define mk_win_advapi_alg_sid_mac                   5
#define mk_win_advapi_alg_sid_ripemd                6
#define mk_win_advapi_alg_sid_ripemd160             7
#define mk_win_advapi_alg_sid_ssl3shamd5            8
#define mk_win_advapi_alg_sid_hmac                  9
#define mk_win_advapi_alg_sid_tls1prf              10
#define mk_win_advapi_alg_sid_hash_replace_owf     11 /* NTDDI_VERSION >= NTDDI_WINXP */
#define mk_win_advapi_alg_sid_sha_256              12 /* NTDDI_VERSION > NTDDI_WINXPSP2 */
#define mk_win_advapi_alg_sid_sha_384              13 /* NTDDI_VERSION > NTDDI_WINXPSP2 */
#define mk_win_advapi_alg_sid_sha_512              14 /* NTDDI_VERSION > NTDDI_WINXPSP2 */
#define mk_win_advapi_alg_sid_ssl3_master           1
#define mk_win_advapi_alg_sid_schannel_master_hash  2
#define mk_win_advapi_alg_sid_schannel_mac_key      3
#define mk_win_advapi_alg_sid_pct1_master           4
#define mk_win_advapi_alg_sid_ssl2_master           5
#define mk_win_advapi_alg_sid_tls1_master           6
#define mk_win_advapi_alg_sid_schannel_enc_key      7
#define mk_win_advapi_alg_sid_ecmqv                 1 /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_alg_sid_example              80

#define mk_win_advapi_calg_md2                     (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_md2                  )
#define mk_win_advapi_calg_md4                     (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_md4                  )
#define mk_win_advapi_calg_md5                     (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_md5                  )
#define mk_win_advapi_calg_sha                     (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_sha                  )
#define mk_win_advapi_calg_sha1                    (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_sha1                 )
#define mk_win_advapi_calg_mac                     (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_mac                  ) /* deprecated */
#define mk_win_advapi_calg_rsa_sign                (mk_win_advapi_alg_class_signature    | mk_win_advapi_alg_type_rsa           | mk_win_advapi_alg_sid_rsa_any              )
#define mk_win_advapi_calg_dss_sign                (mk_win_advapi_alg_class_signature    | mk_win_advapi_alg_type_dss           | mk_win_advapi_alg_sid_dss_any              )
#define mk_win_advapi_calg_no_sign                 (mk_win_advapi_alg_class_signature    | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_any                  ) /* NTDDI_VERSION >= NTDDI_WINXP */
#define mk_win_advapi_calg_rsa_keyx                (mk_win_advapi_alg_class_key_exchange | mk_win_advapi_alg_type_rsa           | mk_win_advapi_alg_sid_rsa_any              )
#define mk_win_advapi_calg_des                     (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_des                  )
#define mk_win_advapi_calg_3des_112                (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_3des_112             )
#define mk_win_advapi_calg_3des                    (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_3des                 )
#define mk_win_advapi_calg_desx                    (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_desx                 )
#define mk_win_advapi_calg_rc2                     (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_rc2                  )
#define mk_win_advapi_calg_rc4                     (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_stream        | mk_win_advapi_alg_sid_rc4                  )
#define mk_win_advapi_calg_seal                    (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_stream        | mk_win_advapi_alg_sid_seal                 )
#define mk_win_advapi_calg_dh_sf                   (mk_win_advapi_alg_class_key_exchange | mk_win_advapi_alg_type_dh            | mk_win_advapi_alg_sid_dh_sandf             )
#define mk_win_advapi_calg_dh_ephem                (mk_win_advapi_alg_class_key_exchange | mk_win_advapi_alg_type_dh            | mk_win_advapi_alg_sid_dh_ephem             )
#define mk_win_advapi_calg_agreedkey_any           (mk_win_advapi_alg_class_key_exchange | mk_win_advapi_alg_type_dh            | mk_win_advapi_alg_sid_agreed_key_any       )
#define mk_win_advapi_calg_kea_keyx                (mk_win_advapi_alg_class_key_exchange | mk_win_advapi_alg_type_dh            | mk_win_advapi_alg_sid_kea                  )
#define mk_win_advapi_calg_hughes_md5              (mk_win_advapi_alg_class_key_exchange | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_md5                  )
#define mk_win_advapi_calg_skipjack                (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_skipjack             )
#define mk_win_advapi_calg_tek                     (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_tek                  )
#define mk_win_advapi_calg_cylink_mek              (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_cylink_mek           ) /* deprecated */
#define mk_win_advapi_calg_ssl3_shamd5             (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_ssl3shamd5           )
#define mk_win_advapi_calg_ssl3_master             (mk_win_advapi_alg_class_msg_encrypt  | mk_win_advapi_alg_type_securechannel | mk_win_advapi_alg_sid_ssl3_master          )
#define mk_win_advapi_calg_schannel_master_hash    (mk_win_advapi_alg_class_msg_encrypt  | mk_win_advapi_alg_type_securechannel | mk_win_advapi_alg_sid_schannel_master_hash )
#define mk_win_advapi_calg_schannel_mac_key        (mk_win_advapi_alg_class_msg_encrypt  | mk_win_advapi_alg_type_securechannel | mk_win_advapi_alg_sid_schannel_mac_key     )
#define mk_win_advapi_calg_schannel_enc_key        (mk_win_advapi_alg_class_msg_encrypt  | mk_win_advapi_alg_type_securechannel | mk_win_advapi_alg_sid_schannel_enc_key     )
#define mk_win_advapi_calg_pct1_master             (mk_win_advapi_alg_class_msg_encrypt  | mk_win_advapi_alg_type_securechannel | mk_win_advapi_alg_sid_pct1_master          )
#define mk_win_advapi_calg_ssl2_master             (mk_win_advapi_alg_class_msg_encrypt  | mk_win_advapi_alg_type_securechannel | mk_win_advapi_alg_sid_ssl2_master          )
#define mk_win_advapi_calg_tls1_master             (mk_win_advapi_alg_class_msg_encrypt  | mk_win_advapi_alg_type_securechannel | mk_win_advapi_alg_sid_tls1_master          )
#define mk_win_advapi_calg_rc5                     (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_rc5                  )
#define mk_win_advapi_calg_hmac                    (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_hmac                 )
#define mk_win_advapi_calg_tls1prf                 (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_tls1prf              )
#define mk_win_advapi_calg_hash_replace_owf        (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_hash_replace_owf     ) /* NTDDI_VERSION >= NTDDI_WINXP */
#define mk_win_advapi_calg_aes_128                 (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_aes_128              ) /* NTDDI_VERSION >= NTDDI_WINXP */
#define mk_win_advapi_calg_aes_192                 (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_aes_192              ) /* NTDDI_VERSION >= NTDDI_WINXP */
#define mk_win_advapi_calg_aes_256                 (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_aes_256              ) /* NTDDI_VERSION >= NTDDI_WINXP */
#define mk_win_advapi_calg_aes                     (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_block         | mk_win_advapi_alg_sid_aes                  ) /* NTDDI_VERSION >= NTDDI_WINXP */
#define mk_win_advapi_calg_sha_256                 (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_sha_256              ) /* NTDDI_VERSION > NTDDI_WINXPSP2 */
#define mk_win_advapi_calg_sha_384                 (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_sha_384              ) /* NTDDI_VERSION > NTDDI_WINXPSP2 */
#define mk_win_advapi_calg_sha_512                 (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_sha_512              ) /* NTDDI_VERSION > NTDDI_WINXPSP2 */
#define mk_win_advapi_calg_ecdh                    (mk_win_advapi_alg_class_key_exchange | mk_win_advapi_alg_type_dh            | mk_win_advapi_alg_sid_ecdh                 ) /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_calg_ecdh_ephem              (mk_win_advapi_alg_class_key_exchange | mk_win_advapi_alg_type_ecdh          | mk_win_advapi_alg_sid_ecdh_ephem           ) /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_calg_ecmqv                   (mk_win_advapi_alg_class_key_exchange | mk_win_advapi_alg_type_any           | mk_win_advapi_alg_sid_ecmqv                ) /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_calg_ecdsa                   (mk_win_advapi_alg_class_signature    | mk_win_advapi_alg_type_dss           | mk_win_advapi_alg_sid_ecdsa                ) /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_calg_nullcipher              (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_any           | 0                                          ) /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_calg_thirdparty_key_exchange (mk_win_advapi_alg_class_key_exchange | mk_win_advapi_alg_type_thirdparty    | mk_win_advapi_alg_sid_thirdparty_any       ) /* NTDDI_VERSION >= NTDDI_WIN10_RS1 */
#define mk_win_advapi_calg_thirdparty_signature    (mk_win_advapi_alg_class_signature    | mk_win_advapi_alg_type_thirdparty    | mk_win_advapi_alg_sid_thirdparty_any       ) /* NTDDI_VERSION >= NTDDI_WIN10_RS1 */
#define mk_win_advapi_calg_thirdparty_cipher       (mk_win_advapi_alg_class_data_encrypt | mk_win_advapi_alg_type_thirdparty    | mk_win_advapi_alg_sid_thirdparty_any       ) /* NTDDI_VERSION >= NTDDI_WIN10_RS1 */
#define mk_win_advapi_calg_thirdparty_hash         (mk_win_advapi_alg_class_hash         | mk_win_advapi_alg_type_thirdparty    | mk_win_advapi_alg_sid_thirdparty_any       ) /* NTDDI_VERSION >= NTDDI_WIN10_RS1 */

#define mk_win_advapi_pp_enumalgs               1
#define mk_win_advapi_pp_enumcontainers         2
#define mk_win_advapi_pp_imptype                3
#define mk_win_advapi_pp_name                   4
#define mk_win_advapi_pp_version                5
#define mk_win_advapi_pp_container              6
#define mk_win_advapi_pp_change_password        7
#define mk_win_advapi_pp_keyset_sec_descr       8
#define mk_win_advapi_pp_certchain              9
#define mk_win_advapi_pp_key_type_subtype      10
#define mk_win_advapi_pp_provtype              16
#define mk_win_advapi_pp_keystorage            17
#define mk_win_advapi_pp_appli_cert            18
#define mk_win_advapi_pp_sym_keysize           19
#define mk_win_advapi_pp_session_keysize       20
#define mk_win_advapi_pp_ui_prompt             21
#define mk_win_advapi_pp_enumalgs_ex           22
#define mk_win_advapi_pp_enummandroots         25
#define mk_win_advapi_pp_enumelectroots        26
#define mk_win_advapi_pp_keyset_type           27
#define mk_win_advapi_pp_admin_pin             31
#define mk_win_advapi_pp_keyexchange_pin       32
#define mk_win_advapi_pp_signature_pin         33
#define mk_win_advapi_pp_sig_keysize_inc       34
#define mk_win_advapi_pp_keyx_keysize_inc      35
#define mk_win_advapi_pp_unique_container      36
#define mk_win_advapi_pp_sgc_info              37
#define mk_win_advapi_pp_use_hardware_rng      38
#define mk_win_advapi_pp_keyspec               39
#define mk_win_advapi_pp_enumex_signing_prot   40
#define mk_win_advapi_pp_crypt_count_key_use   41 /* NTDDI_VERSION >= NTDDI_WS03 */
#define mk_win_advapi_pp_user_certstore        42 /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_pp_smartcard_reader      43 /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_pp_smartcard_guid        45 /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_pp_root_certstore        46 /* NTDDI_VERSION >= NTDDI_VISTA */
#define mk_win_advapi_pp_smartcard_reader_icon 47 /* NTDDI_VERSION >= NTDDI_WIN8 */

#define mk_win_advapi_kp_iv                1
#define mk_win_advapi_kp_salt              2
#define mk_win_advapi_kp_padding           3
#define mk_win_advapi_kp_mode              4
#define mk_win_advapi_kp_mode_bits         5
#define mk_win_advapi_kp_permissions       6
#define mk_win_advapi_kp_algid             7
#define mk_win_advapi_kp_blocklen          8
#define mk_win_advapi_kp_keylen            9
#define mk_win_advapi_kp_salt_ex          10
#define mk_win_advapi_kp_p                11
#define mk_win_advapi_kp_g                12
#define mk_win_advapi_kp_q                13
#define mk_win_advapi_kp_x                14
#define mk_win_advapi_kp_y                15
#define mk_win_advapi_kp_ra               16
#define mk_win_advapi_kp_rb               17
#define mk_win_advapi_kp_info             18
#define mk_win_advapi_kp_effective_keylen 19
#define mk_win_advapi_kp_schannel_alg     20
#define mk_win_advapi_kp_client_random    21
#define mk_win_advapi_kp_server_random    22
#define mk_win_advapi_kp_rp               23
#define mk_win_advapi_kp_precomp_md5      24
#define mk_win_advapi_kp_precomp_sha      25
#define mk_win_advapi_kp_certificate      26
#define mk_win_advapi_kp_clear_key        27
#define mk_win_advapi_kp_pub_ex_len       28
#define mk_win_advapi_kp_pub_ex_val       29
#define mk_win_advapi_kp_keyval           30
#define mk_win_advapi_kp_admin_pin        31
#define mk_win_advapi_kp_keyexchange_pin  32
#define mk_win_advapi_kp_signature_pin    33
#define mk_win_advapi_kp_prehash          34
#define mk_win_advapi_kp_rounds           35 /* NTDDI_VERSION >= NTDDI_WS03 */
#define mk_win_advapi_kp_oaep_params      36
#define mk_win_advapi_kp_cms_key_info     37
#define mk_win_advapi_kp_cms_dh_key_info  38
#define mk_win_advapi_kp_pub_params       39
#define mk_win_advapi_kp_verify_params    40
#define mk_win_advapi_kp_highest_version  41
#define mk_win_advapi_kp_get_use_count    42 /* NTDDI_VERSION >= NTDDI_WS03 */
#define mk_win_advapi_kp_pin_id           43
#define mk_win_advapi_kp_pin_info         44

#define mk_win_advapi_pkcs5_padding  1
#define mk_win_advapi_random_padding 2
#define mk_win_advapi_zero_padding   3

#define mk_win_advapi_crypt_mode_cbc 1
#define mk_win_advapi_crypt_mode_ecb 2
#define mk_win_advapi_crypt_mode_ofb 3
#define mk_win_advapi_crypt_mode_cfb 4
#define mk_win_advapi_crypt_mode_cts 5


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CryptAcquireContextA(mk_win_handle_advapi_prov_pt const csp, mk_lang_types_pchar_pct const container, mk_lang_types_pchar_pct const provider, mk_win_base_dword_t const provider_type, mk_win_base_dword_t const flags) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CryptAcquireContextW(mk_win_handle_advapi_prov_pt const csp, mk_win_base_wchar_pct const container, mk_win_base_wchar_pct const provider, mk_win_base_dword_t const provider_type, mk_win_base_dword_t const flags) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CryptReleaseContext(mk_win_handle_advapi_prov_t const csp, mk_win_base_dword_t const flags) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CryptImportKey(mk_win_handle_advapi_prov_t const csp, mk_lang_types_uchar_pct const data, mk_win_base_dword_t const data_len, mk_win_handle_advapi_key_pct const pub_key, mk_win_base_dword_t const flags, mk_win_handle_advapi_key_pt const key) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CryptDestroyKey(mk_win_handle_advapi_key_t const key) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CryptSetKeyParam(mk_win_handle_advapi_key_t const key, mk_win_base_dword_t const param, mk_lang_types_uchar_pct const data, mk_win_base_dword_t const flags) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CryptEncrypt(mk_win_handle_advapi_key_t const key, mk_win_handle_advapi_hash_t const hash, mk_win_base_bool_t const final, mk_win_base_dword_t const flags, mk_lang_types_uchar_pt const data, mk_win_base_dword_pt const data_len, mk_win_base_dword_t const buff_len) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CryptDecrypt(mk_win_handle_advapi_key_t const key, mk_win_handle_advapi_hash_t const hash, mk_win_base_bool_t const final, mk_win_base_dword_t const flags, mk_lang_types_uchar_pt const data, mk_win_base_dword_pt const data_len) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_advapi.c"
#endif
#endif
