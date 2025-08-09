#ifndef mk_include_guard_mk_lib_iip_cp_remote_destination_h
#define mk_include_guard_mk_lib_iip_cp_remote_destination_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


struct mk_lib_iip_cp_remote_destination_basic_buffer_s
{
	mk_sl_cui_uint8_t m_enc_pub_key[256];
	mk_sl_cui_uint8_t m_sgn_pub_key[128];
};
typedef struct mk_lib_iip_cp_remote_destination_basic_buffer_s mk_lib_iip_cp_remote_destination_basic_buffer_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_basic_buffer);

enum mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e
{
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_dsa_sha1,
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_ecdsa_sha256_p256,
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_ecdsa_sha384_p384,
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_ecdsa_sha512_p521,
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_rsa_sha256_2048,
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_rsa_sha384_3072,
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_rsa_sha512_4096,
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519,
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519ph,
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_gost_a,
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_gost_b,
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_reddsa_sha512_ed25519,
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e_dummy_end
};
typedef enum mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_e mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_certificate_key_sgn_type);

enum mk_lib_iip_cp_remote_destination_certificate_key_enc_type_e
{
	mk_lib_iip_cp_remote_destination_certificate_key_enc_type_e_elgamal,
	mk_lib_iip_cp_remote_destination_certificate_key_enc_type_e_p256,
	mk_lib_iip_cp_remote_destination_certificate_key_enc_type_e_p384,
	mk_lib_iip_cp_remote_destination_certificate_key_enc_type_e_p521,
	mk_lib_iip_cp_remote_destination_certificate_key_enc_type_e_x25519,
	mk_lib_iip_cp_remote_destination_certificate_key_enc_type_e_dummy_end
};
typedef enum mk_lib_iip_cp_remote_destination_certificate_key_enc_type_e mk_lib_iip_cp_remote_destination_certificate_key_enc_type_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_certificate_key_enc_type);

enum mk_lib_iip_cp_remote_destination_signature_len_e
{
	mk_lib_iip_cp_remote_destination_signature_len_e_dsa_sha1               =  40,
	mk_lib_iip_cp_remote_destination_signature_len_e_ecdsa_sha256_p256      =  64,
	mk_lib_iip_cp_remote_destination_signature_len_e_ecdsa_sha384_p384      =  96,
	mk_lib_iip_cp_remote_destination_signature_len_e_ecdsa_sha512_p521      = 132,
	mk_lib_iip_cp_remote_destination_signature_len_e_rsa_sha256_2048        = 256,
	mk_lib_iip_cp_remote_destination_signature_len_e_rsa_sha384_3072        = 384,
	mk_lib_iip_cp_remote_destination_signature_len_e_rsa_sha512_4096        = 512,
	mk_lib_iip_cp_remote_destination_signature_len_e_eddsa_sha512_ed25519   =  64,
	mk_lib_iip_cp_remote_destination_signature_len_e_eddsa_sha512_ed25519ph =  64,
	mk_lib_iip_cp_remote_destination_signature_len_e_gost_a                 =   1, /* todo */
	mk_lib_iip_cp_remote_destination_signature_len_e_gost_b                 =   1, /* todo */
	mk_lib_iip_cp_remote_destination_signature_len_e_reddsa_sha512_ed25519  =  64,
	mk_lib_iip_cp_remote_destination_signature_len_e_dummy_end
};
typedef enum mk_lib_iip_cp_remote_destination_signature_len_e mk_lib_iip_cp_remote_destination_signature_len_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_signature_len);

enum mk_lib_iip_cp_remote_destination_key_len_sgn_e
{
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_dsa_sha1               = 128,
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_ecdsa_sha256_p256      =  64,
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_ecdsa_sha384_p384      =  96,
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_ecdsa_sha512_p521      = 132,
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_rsa_sha256_2048        = 256,
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_rsa_sha384_3072        = 384,
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_rsa_sha512_4096        = 512,
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_eddsa_sha512_ed25519   =  32,
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_eddsa_sha512_ed25519ph =  32,
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_gost_a                 =  64,
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_gost_b                 = 128,
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_reddsa_sha512_ed25519  =  32,
	mk_lib_iip_cp_remote_destination_key_len_sgn_e_dummy_end
};
typedef enum mk_lib_iip_cp_remote_destination_key_len_sgn_e mk_lib_iip_cp_remote_destination_key_len_sgn_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_key_len_sgn);

enum mk_lib_iip_cp_remote_destination_key_len_enc_e
{
	mk_lib_iip_cp_remote_destination_key_len_enc_e_elgamal = 256,
	mk_lib_iip_cp_remote_destination_key_len_enc_e_p256    =  64,
	mk_lib_iip_cp_remote_destination_key_len_enc_e_p384    =  96,
	mk_lib_iip_cp_remote_destination_key_len_enc_e_p521    = 132,
	mk_lib_iip_cp_remote_destination_key_len_enc_e_x25519  =  32,
	mk_lib_iip_cp_remote_destination_key_len_enc_e_dummy_end
};
typedef enum mk_lib_iip_cp_remote_destination_key_len_enc_e mk_lib_iip_cp_remote_destination_key_len_enc_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_key_len_enc);

enum mk_lib_iip_cp_remote_destination_key_additional_len_worst_sgn_e
{
	mk_lib_iip_cp_remote_destination_key_additional_len_worst_sgn_v = mk_lang_max(1,
		mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(0,
		mk_lib_iip_cp_remote_destination_key_len_sgn_e_dsa_sha1),
		mk_lib_iip_cp_remote_destination_key_len_sgn_e_ecdsa_sha256_p256),
		mk_lib_iip_cp_remote_destination_key_len_sgn_e_ecdsa_sha384_p384),
		mk_lib_iip_cp_remote_destination_key_len_sgn_e_ecdsa_sha512_p521),
		mk_lib_iip_cp_remote_destination_key_len_sgn_e_rsa_sha256_2048),
		mk_lib_iip_cp_remote_destination_key_len_sgn_e_rsa_sha384_3072),
		mk_lib_iip_cp_remote_destination_key_len_sgn_e_rsa_sha512_4096),
		mk_lib_iip_cp_remote_destination_key_len_sgn_e_eddsa_sha512_ed25519),
		mk_lib_iip_cp_remote_destination_key_len_sgn_e_eddsa_sha512_ed25519ph),
		mk_lib_iip_cp_remote_destination_key_len_sgn_e_gost_a),
		mk_lib_iip_cp_remote_destination_key_len_sgn_e_gost_b),
		mk_lib_iip_cp_remote_destination_key_len_sgn_e_reddsa_sha512_ed25519),
		0) - 128)
};
typedef enum mk_lib_iip_cp_remote_destination_key_additional_len_worst_sgn_e mk_lib_iip_cp_remote_destination_key_additional_len_worst_sgn_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_key_additional_len_worst_sgn);

enum mk_lib_iip_cp_remote_destination_key_additional_len_worst_enc_e
{
	mk_lib_iip_cp_remote_destination_key_additional_len_worst_enc_v = mk_lang_max(1,
		mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(0,
		mk_lib_iip_cp_remote_destination_key_len_enc_e_elgamal),
		mk_lib_iip_cp_remote_destination_key_len_enc_e_p256),
		mk_lib_iip_cp_remote_destination_key_len_enc_e_p384),
		mk_lib_iip_cp_remote_destination_key_len_enc_e_p521),
		mk_lib_iip_cp_remote_destination_key_len_enc_e_x25519),
		0) - 256)
};
typedef enum mk_lib_iip_cp_remote_destination_key_additional_len_worst_enc_e mk_lib_iip_cp_remote_destination_key_additional_len_worst_enc_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_key_additional_len_worst_enc);

struct mk_lib_iip_cp_remote_destination_cert_signeda_s
{
	mk_sl_cui_uint8_t m_dsa_signature[40];
};
typedef struct mk_lib_iip_cp_remote_destination_cert_signeda_s mk_lib_iip_cp_remote_destination_cert_signeda_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_cert_signeda);

struct mk_lib_iip_cp_remote_destination_cert_signedb_s
{
	mk_lib_iip_cp_remote_destination_cert_signeda_t m_signeda;
	mk_sl_cui_uint8_t m_signing_destination_hash[32];
};
typedef struct mk_lib_iip_cp_remote_destination_cert_signedb_s mk_lib_iip_cp_remote_destination_cert_signedb_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_cert_signedb);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_remote_destination_cert_key_s
{
	mk_lib_iip_cp_remote_destination_certificate_key_sgn_type_t m_sgn_type;
	mk_lib_iip_cp_remote_destination_certificate_key_enc_type_t m_enc_type;
	mk_sl_cui_uint8_t m_sgn_pub_key[mk_lib_iip_cp_remote_destination_key_additional_len_worst_sgn_v];
	mk_sl_cui_uint8_t m_enc_pub_key[mk_lib_iip_cp_remote_destination_key_additional_len_worst_enc_v];
};
typedef struct mk_lib_iip_cp_remote_destination_cert_key_s mk_lib_iip_cp_remote_destination_cert_key_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_cert_key);
#include "mk_lang_warning_msvc_pop.h"

enum mk_lib_iip_cp_remote_destination_cert_type_e
{
	mk_lib_iip_cp_remote_destination_cert_type_e_null,
	mk_lib_iip_cp_remote_destination_cert_type_e_hidden,
	mk_lib_iip_cp_remote_destination_cert_type_e_signeda,
	mk_lib_iip_cp_remote_destination_cert_type_e_signedb,
	mk_lib_iip_cp_remote_destination_cert_type_e_key,
	mk_lib_iip_cp_remote_destination_cert_type_e_dummy_end
};
typedef enum mk_lib_iip_cp_remote_destination_cert_type_e mk_lib_iip_cp_remote_destination_cert_type_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_cert_type);

union mk_lib_iip_cp_remote_destination_cert_data_u
{
	mk_lib_iip_cp_remote_destination_cert_signeda_t m_signeda;
	mk_lib_iip_cp_remote_destination_cert_signedb_t m_signedb;
	mk_lib_iip_cp_remote_destination_cert_key_t m_key;
};
typedef union mk_lib_iip_cp_remote_destination_cert_data_u mk_lib_iip_cp_remote_destination_cert_data_t;
struct mk_lib_iip_cp_remote_destination_cert_s
{
	mk_lib_iip_cp_remote_destination_cert_data_t m_data;
};
typedef struct mk_lib_iip_cp_remote_destination_cert_s mk_lib_iip_cp_remote_destination_cert_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_cert);

struct mk_lib_iip_cp_remote_destination_certificate_s
{
	mk_lib_iip_cp_remote_destination_cert_type_t m_cert_type;
	mk_lib_iip_cp_remote_destination_cert_t m_cert_data;
};
typedef struct mk_lib_iip_cp_remote_destination_certificate_s mk_lib_iip_cp_remote_destination_certificate_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination_certificate);

struct mk_lib_iip_cp_remote_destination_s
{
	mk_lib_iip_cp_remote_destination_basic_buffer_t m_basic_buffer;
	mk_lib_iip_cp_remote_destination_certificate_t m_certificate;
};
typedef struct mk_lib_iip_cp_remote_destination_s mk_lib_iip_cp_remote_destination_t;
mk_lang_typedef(mk_lib_iip_cp_remote_destination);


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_rw_from_bytes(mk_lib_iip_cp_remote_destination_pt const remote_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_rw_to_bytes(mk_lib_iip_cp_remote_destination_pct const remote_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_remote_destination.c"
#endif
#endif
