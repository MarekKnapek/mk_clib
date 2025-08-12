#ifndef mk_include_guard_mk_lib_iip_cp_destination_c
#define mk_include_guard_mk_lib_iip_cp_destination_c
#include "mk_lib_iip_cp_destination.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_debug_break.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_static_param.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha2_256.h"
#include "mk_lib_iip_base32_encoder.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


enum mk_lib_iip_cp_destination_file_format_certificate_type_e
{
	mk_lib_iip_cp_destination_file_format_certificate_type_e_null      = 0,
	mk_lib_iip_cp_destination_file_format_certificate_type_e_hash_cash = 1,
	mk_lib_iip_cp_destination_file_format_certificate_type_e_hidden    = 2,
	mk_lib_iip_cp_destination_file_format_certificate_type_e_signed    = 3,
	mk_lib_iip_cp_destination_file_format_certificate_type_e_multiple  = 4,
	mk_lib_iip_cp_destination_file_format_certificate_type_e_key       = 5,
	mk_lib_iip_cp_destination_file_format_certificate_type_e_dummy_end
};
typedef enum mk_lib_iip_cp_destination_file_format_certificate_type_e mk_lib_iip_cp_destination_file_format_certificate_type_t;
mk_lang_typedef(mk_lib_iip_cp_destination_file_format_certificate_type);

enum mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e
{
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_dsa_sha1               =  0,
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_ecdsa_sha256_p256      =  1,
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_ecdsa_sha384_p384      =  2,
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_ecdsa_sha512_p521      =  3,
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_rsa_sha256_2048        =  4,
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_rsa_sha384_3072        =  5,
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_rsa_sha512_4096        =  6,
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_eddsa_sha512_ed25519   =  7,
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_eddsa_sha512_ed25519ph =  8,
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_gost_a                 =  9,
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_gost_b                 = 10,
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_reddsa_sha512_ed25519  = 11,
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_dummy_end
};
typedef enum mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_t;
mk_lang_typedef(mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type);

enum mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e
{
	mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_elgamal = 0,
	mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_p256    = 1,
	mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_p384    = 2,
	mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_p521    = 3,
	mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_x25519  = 4,
	mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_dummy_end
};
typedef enum mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_t;
mk_lang_typedef(mk_lib_iip_cp_destination_file_format_certificate_key_enc_type);

enum mk_lib_iip_cp_destination_signature_len_e
{
	mk_lib_iip_cp_destination_signature_len_e_dsa_sha1               =  40,
	mk_lib_iip_cp_destination_signature_len_e_ecdsa_sha256_p256      =  64,
	mk_lib_iip_cp_destination_signature_len_e_ecdsa_sha384_p384      =  96,
	mk_lib_iip_cp_destination_signature_len_e_ecdsa_sha512_p521      = 132,
	mk_lib_iip_cp_destination_signature_len_e_rsa_sha256_2048        = 256,
	mk_lib_iip_cp_destination_signature_len_e_rsa_sha384_3072        = 384,
	mk_lib_iip_cp_destination_signature_len_e_rsa_sha512_4096        = 512,
	mk_lib_iip_cp_destination_signature_len_e_eddsa_sha512_ed25519   =  64,
	mk_lib_iip_cp_destination_signature_len_e_eddsa_sha512_ed25519ph =  64,
	mk_lib_iip_cp_destination_signature_len_e_gost_a                 =  32,
	mk_lib_iip_cp_destination_signature_len_e_gost_b                 =  64,
	mk_lib_iip_cp_destination_signature_len_e_reddsa_sha512_ed25519  =  64,
	mk_lib_iip_cp_destination_signature_len_e_dummy_end
};
typedef enum mk_lib_iip_cp_destination_signature_len_e mk_lib_iip_cp_destination_signature_len_t;
mk_lang_typedef(mk_lib_iip_cp_destination_signature_len);

enum mk_lib_iip_cp_destination_key_len_sgn_e
{
	mk_lib_iip_cp_destination_key_len_sgn_e_dsa_sha1               = 128,
	mk_lib_iip_cp_destination_key_len_sgn_e_ecdsa_sha256_p256      =  64,
	mk_lib_iip_cp_destination_key_len_sgn_e_ecdsa_sha384_p384      =  96,
	mk_lib_iip_cp_destination_key_len_sgn_e_ecdsa_sha512_p521      = 132,
	mk_lib_iip_cp_destination_key_len_sgn_e_rsa_sha256_2048        = 256,
	mk_lib_iip_cp_destination_key_len_sgn_e_rsa_sha384_3072        = 384,
	mk_lib_iip_cp_destination_key_len_sgn_e_rsa_sha512_4096        = 512,
	mk_lib_iip_cp_destination_key_len_sgn_e_eddsa_sha512_ed25519   =  32,
	mk_lib_iip_cp_destination_key_len_sgn_e_eddsa_sha512_ed25519ph =  32,
	mk_lib_iip_cp_destination_key_len_sgn_e_gost_a                 =  64,
	mk_lib_iip_cp_destination_key_len_sgn_e_gost_b                 = 128,
	mk_lib_iip_cp_destination_key_len_sgn_e_reddsa_sha512_ed25519  =  32,
	mk_lib_iip_cp_destination_key_len_sgn_e_dummy_end
};
typedef enum mk_lib_iip_cp_destination_key_len_sgn_e mk_lib_iip_cp_destination_key_len_sgn_t;
mk_lang_typedef(mk_lib_iip_cp_destination_key_len_sgn);

enum mk_lib_iip_cp_destination_key_len_enc_e
{
	mk_lib_iip_cp_destination_key_len_enc_e_elgamal = 256,
	mk_lib_iip_cp_destination_key_len_enc_e_p256    =  64,
	mk_lib_iip_cp_destination_key_len_enc_e_p384    =  96,
	mk_lib_iip_cp_destination_key_len_enc_e_p521    = 132,
	mk_lib_iip_cp_destination_key_len_enc_e_x25519  =  32,
	mk_lib_iip_cp_destination_key_len_enc_e_dummy_end
};
typedef enum mk_lib_iip_cp_destination_key_len_enc_e mk_lib_iip_cp_destination_key_len_enc_t;
mk_lang_typedef(mk_lib_iip_cp_destination_key_len_enc);

enum mk_lib_iip_cp_destination_key_additional_len_worst_sgn_e
{
	mk_lib_iip_cp_destination_key_additional_len_worst_sgn_v = mk_lang_max(1,
		mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(0,
		mk_lib_iip_cp_destination_key_len_sgn_e_dsa_sha1),
		mk_lib_iip_cp_destination_key_len_sgn_e_ecdsa_sha256_p256),
		mk_lib_iip_cp_destination_key_len_sgn_e_ecdsa_sha384_p384),
		mk_lib_iip_cp_destination_key_len_sgn_e_ecdsa_sha512_p521),
		mk_lib_iip_cp_destination_key_len_sgn_e_rsa_sha256_2048),
		mk_lib_iip_cp_destination_key_len_sgn_e_rsa_sha384_3072),
		mk_lib_iip_cp_destination_key_len_sgn_e_rsa_sha512_4096),
		mk_lib_iip_cp_destination_key_len_sgn_e_eddsa_sha512_ed25519),
		mk_lib_iip_cp_destination_key_len_sgn_e_eddsa_sha512_ed25519ph),
		mk_lib_iip_cp_destination_key_len_sgn_e_gost_a),
		mk_lib_iip_cp_destination_key_len_sgn_e_gost_b),
		mk_lib_iip_cp_destination_key_len_sgn_e_reddsa_sha512_ed25519),
		0) - 128)
};
typedef enum mk_lib_iip_cp_destination_key_additional_len_worst_sgn_e mk_lib_iip_cp_destination_key_additional_len_worst_sgn_t;
mk_lang_typedef(mk_lib_iip_cp_destination_key_additional_len_worst_sgn);

enum mk_lib_iip_cp_destination_key_additional_len_worst_enc_e
{
	mk_lib_iip_cp_destination_key_additional_len_worst_enc_v = mk_lang_max(0,
		mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(0,
		mk_lib_iip_cp_destination_key_len_enc_e_elgamal),
		mk_lib_iip_cp_destination_key_len_enc_e_p256),
		mk_lib_iip_cp_destination_key_len_enc_e_p384),
		mk_lib_iip_cp_destination_key_len_enc_e_p521),
		mk_lib_iip_cp_destination_key_len_enc_e_x25519),
		0) - 256)
};
typedef enum mk_lib_iip_cp_destination_key_additional_len_worst_enc_e mk_lib_iip_cp_destination_key_additional_len_worst_enc_t;
mk_lang_typedef(mk_lib_iip_cp_destination_key_additional_len_worst_enc);


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_iip_cp_destination_k_b32_suffix[] = ".b32.i2p";


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_destination_file_format_certificate_type_t mk_lib_iip_cp_destination_file_format_certificate_type_from_sint(mk_lang_types_sint_t const sint) mk_lang_noexcept
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lib_iip_cp_destination_file_format_certificate_type_t format_certificate_type mk_lang_constexpr_init;

	switch(sint)
	{
		case mk_lib_iip_cp_destination_file_format_certificate_type_e_null  : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_type_e_hidden: gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_type_e_signed: gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_type_e_key   : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_type_e_dummy_end: gud = mk_lang_false; break;
		default: gud = mk_lang_false; break;
	}
	if(gud)
	{
		format_certificate_type = ((mk_lib_iip_cp_destination_file_format_certificate_type_t)(sint));
	}
	else
	{
		format_certificate_type = mk_lib_iip_cp_destination_file_format_certificate_type_e_dummy_end;
	}
	return format_certificate_type;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_destination_file_format_certificate_type_t mk_lib_iip_cp_destination_cert_type_to_file_format(mk_lib_iip_cp_destination_cert_type_t const my_cert_type) mk_lang_noexcept
{
	mk_lib_iip_cp_destination_file_format_certificate_type_t file_format_cert_type mk_lang_constexpr_init;

	mk_lang_assert(my_cert_type >= 0);
	mk_lang_assert(my_cert_type < mk_lib_iip_cp_destination_cert_type_e_dummy_end);

	switch(my_cert_type)
	{
		case mk_lib_iip_cp_destination_cert_type_e_null   : file_format_cert_type = mk_lib_iip_cp_destination_file_format_certificate_type_e_null  ; break;
		case mk_lib_iip_cp_destination_cert_type_e_hidden : file_format_cert_type = mk_lib_iip_cp_destination_file_format_certificate_type_e_hidden; break;
		case mk_lib_iip_cp_destination_cert_type_e_signeda: file_format_cert_type = mk_lib_iip_cp_destination_file_format_certificate_type_e_signed; break;
		case mk_lib_iip_cp_destination_cert_type_e_signedb: file_format_cert_type = mk_lib_iip_cp_destination_file_format_certificate_type_e_signed; break;
		case mk_lib_iip_cp_destination_cert_type_e_key    : file_format_cert_type = mk_lib_iip_cp_destination_file_format_certificate_type_e_key   ; break;
		#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
		case mk_lib_iip_cp_destination_cert_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
		#include "mk_lang_warning_clang_pop.h"
	}
	mk_lang_clobber(&file_format_cert_type);
	return file_format_cert_type;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_t mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_from_sint(mk_lang_types_sint_t const sint) mk_lang_noexcept
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_t file_format_certificate_key_sgn_type mk_lang_constexpr_init;

	switch(sint)
	{
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_dsa_sha1              : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_ecdsa_sha256_p256     : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_ecdsa_sha384_p384     : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_ecdsa_sha512_p521     : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_rsa_sha256_2048       : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_rsa_sha384_3072       : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_rsa_sha512_4096       : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_eddsa_sha512_ed25519  : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_eddsa_sha512_ed25519ph: gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_gost_a                : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_gost_b                : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_reddsa_sha512_ed25519 : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_dummy_end: gud = mk_lang_false; break;
		default: gud = mk_lang_false; break;
	}
	if(gud)
	{
		file_format_certificate_key_sgn_type = ((mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_t)(sint));
	}
	else
	{
		file_format_certificate_key_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_dummy_end;
	}
	return file_format_certificate_key_sgn_type;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_destination_certificate_key_sgn_type_t mk_lib_iip_cp_destination_certificate_key_sgn_type_from_file_format(mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_t const file_format_sgn_type) mk_lang_noexcept
{
	mk_lib_iip_cp_destination_certificate_key_sgn_type_t my_sgn_type mk_lang_constexpr_init;

	switch(file_format_sgn_type)
	{
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_dsa_sha1              : my_sgn_type = mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dsa_sha1              ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_ecdsa_sha256_p256     : my_sgn_type = mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha256_p256     ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_ecdsa_sha384_p384     : my_sgn_type = mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha384_p384     ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_ecdsa_sha512_p521     : my_sgn_type = mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha512_p521     ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_rsa_sha256_2048       : my_sgn_type = mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha256_2048       ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_rsa_sha384_3072       : my_sgn_type = mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha384_3072       ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_rsa_sha512_4096       : my_sgn_type = mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha512_4096       ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_eddsa_sha512_ed25519  : my_sgn_type = mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519  ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_eddsa_sha512_ed25519ph: my_sgn_type = mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519ph; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_gost_a                : my_sgn_type = mk_lib_iip_cp_destination_certificate_key_sgn_type_e_gost_a                ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_gost_b                : my_sgn_type = mk_lib_iip_cp_destination_certificate_key_sgn_type_e_gost_b                ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_reddsa_sha512_ed25519 : my_sgn_type = mk_lib_iip_cp_destination_certificate_key_sgn_type_e_reddsa_sha512_ed25519 ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&my_sgn_type);
	return my_sgn_type;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_t mk_lib_iip_cp_destination_certificate_key_sgn_type_to_file_format(mk_lib_iip_cp_destination_certificate_key_sgn_type_t const my_sgn_type) mk_lang_noexcept
{
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_t file_format_sgn_type mk_lang_constexpr_init;

	mk_lang_assert(my_sgn_type >= 0);
	mk_lang_assert(my_sgn_type < mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end);

	switch(my_sgn_type)
	{
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dsa_sha1              : file_format_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_dsa_sha1              ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha256_p256     : file_format_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_ecdsa_sha256_p256     ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha384_p384     : file_format_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_ecdsa_sha384_p384     ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha512_p521     : file_format_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_ecdsa_sha512_p521     ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha256_2048       : file_format_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_rsa_sha256_2048       ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha384_3072       : file_format_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_rsa_sha384_3072       ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha512_4096       : file_format_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_rsa_sha512_4096       ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519  : file_format_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_eddsa_sha512_ed25519  ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519ph: file_format_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_eddsa_sha512_ed25519ph; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_gost_a                : file_format_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_gost_a                ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_gost_b                : file_format_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_gost_b                ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_reddsa_sha512_ed25519 : file_format_sgn_type = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_reddsa_sha512_ed25519 ; break;
		#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
		#include "mk_lang_warning_clang_pop.h"
	}
	mk_lang_clobber(&file_format_sgn_type);
	return file_format_sgn_type;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_t mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_from_sint(mk_lang_types_sint_t const sint) mk_lang_noexcept
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_t file_format_certificate_key_enc_type mk_lang_constexpr_init;

	switch(sint)
	{
		case mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_elgamal: gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_p256   : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_p384   : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_p521   : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_x25519 : gud = mk_lang_true; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_dummy_end: gud = mk_lang_false; break;
		default: gud = mk_lang_false; break;
	}
	if(gud)
	{
		file_format_certificate_key_enc_type = ((mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_t)(sint));
	}
	else
	{
		file_format_certificate_key_enc_type = mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_dummy_end;
	}
	return file_format_certificate_key_enc_type;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_destination_certificate_key_enc_type_t mk_lib_iip_cp_destination_certificate_key_enc_type_from_file_format(mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_t const file_format_enc_type) mk_lang_noexcept
{
	mk_lib_iip_cp_destination_certificate_key_enc_type_t my_enc_type mk_lang_constexpr_init;

	switch(file_format_enc_type)
	{
		case mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_elgamal: my_enc_type = mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_p256   : my_enc_type = mk_lib_iip_cp_destination_certificate_key_enc_type_e_p256   ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_p384   : my_enc_type = mk_lib_iip_cp_destination_certificate_key_enc_type_e_p384   ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_p521   : my_enc_type = mk_lib_iip_cp_destination_certificate_key_enc_type_e_p521   ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_x25519 : my_enc_type = mk_lib_iip_cp_destination_certificate_key_enc_type_e_x25519 ; break;
		case mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&my_enc_type);
	return my_enc_type;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_t mk_lib_iip_cp_destination_certificate_key_enc_type_to_file_format(mk_lib_iip_cp_destination_certificate_key_enc_type_t const my_enc_type) mk_lang_noexcept
{
	mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_t file_format_enc_type mk_lang_constexpr_init;

	mk_lang_assert(my_enc_type >= 0);
	mk_lang_assert(my_enc_type < mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end);

	switch(my_enc_type)
	{
		case mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal: file_format_enc_type = mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_elgamal; break;
		case mk_lib_iip_cp_destination_certificate_key_enc_type_e_p256   : file_format_enc_type = mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_p256   ; break;
		case mk_lib_iip_cp_destination_certificate_key_enc_type_e_p384   : file_format_enc_type = mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_p384   ; break;
		case mk_lib_iip_cp_destination_certificate_key_enc_type_e_p521   : file_format_enc_type = mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_p521   ; break;
		case mk_lib_iip_cp_destination_certificate_key_enc_type_e_x25519 : file_format_enc_type = mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_x25519 ; break;
		#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
		case mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
		#include "mk_lang_warning_clang_pop.h"
	}
	mk_lang_clobber(&file_format_enc_type);
	return file_format_enc_type;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_destination_get_key_len_sgn(mk_lib_iip_cp_destination_certificate_key_sgn_type_t const key_type) mk_lang_noexcept
{
	mk_lang_types_sint_t res mk_lang_constexpr_init;

	switch(key_type)
	{
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dsa_sha1              : res = mk_lib_iip_cp_destination_key_len_sgn_e_dsa_sha1              ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha256_p256     : res = mk_lib_iip_cp_destination_key_len_sgn_e_ecdsa_sha256_p256     ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha384_p384     : res = mk_lib_iip_cp_destination_key_len_sgn_e_ecdsa_sha384_p384     ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha512_p521     : res = mk_lib_iip_cp_destination_key_len_sgn_e_ecdsa_sha512_p521     ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha256_2048       : res = mk_lib_iip_cp_destination_key_len_sgn_e_rsa_sha256_2048       ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha384_3072       : res = mk_lib_iip_cp_destination_key_len_sgn_e_rsa_sha384_3072       ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha512_4096       : res = mk_lib_iip_cp_destination_key_len_sgn_e_rsa_sha512_4096       ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519  : res = mk_lib_iip_cp_destination_key_len_sgn_e_eddsa_sha512_ed25519  ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519ph: res = mk_lib_iip_cp_destination_key_len_sgn_e_eddsa_sha512_ed25519ph; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_gost_a                : res = mk_lib_iip_cp_destination_key_len_sgn_e_gost_a                ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_gost_b                : res = mk_lib_iip_cp_destination_key_len_sgn_e_gost_b                ; break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_reddsa_sha512_ed25519 : res = mk_lib_iip_cp_destination_key_len_sgn_e_reddsa_sha512_ed25519 ; break;
		#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
		#include "mk_lang_warning_clang_pop.h"
	}
	mk_lang_clobber(&res);
	return res;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_destination_get_key_additional_len_sgn(mk_lib_iip_cp_destination_certificate_key_sgn_type_t const key_type) mk_lang_noexcept
{
	mk_lang_types_sint_t res mk_lang_constexpr_init;

	switch(key_type)
	{
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dsa_sha1              : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_sgn_e_dsa_sha1               - 128); break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha256_p256     : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_sgn_e_ecdsa_sha256_p256      - 128); break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha384_p384     : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_sgn_e_ecdsa_sha384_p384      - 128); break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha512_p521     : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_sgn_e_ecdsa_sha512_p521      - 128); break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha256_2048       : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_sgn_e_rsa_sha256_2048        - 128); break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha384_3072       : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_sgn_e_rsa_sha384_3072        - 128); break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha512_4096       : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_sgn_e_rsa_sha512_4096        - 128); break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519  : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_sgn_e_eddsa_sha512_ed25519   - 128); break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519ph: res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_sgn_e_eddsa_sha512_ed25519ph - 128); break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_gost_a                : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_sgn_e_gost_a                 - 128); break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_gost_b                : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_sgn_e_gost_b                 - 128); break;
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_reddsa_sha512_ed25519 : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_sgn_e_reddsa_sha512_ed25519  - 128); break;
		#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
		case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
		#include "mk_lang_warning_clang_pop.h"
	}
	mk_lang_clobber(&res);
	return res;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_destination_get_key_additional_len_enc(mk_lib_iip_cp_destination_certificate_key_enc_type_t const key_type) mk_lang_noexcept
{
	mk_lang_types_sint_t res mk_lang_constexpr_init;

	switch(key_type)
	{
		case mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal: res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_enc_e_elgamal - 256); break;
		case mk_lib_iip_cp_destination_certificate_key_enc_type_e_p256   : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_enc_e_p256    - 256); break;
		case mk_lib_iip_cp_destination_certificate_key_enc_type_e_p384   : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_enc_e_p384    - 256); break;
		case mk_lib_iip_cp_destination_certificate_key_enc_type_e_p521   : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_enc_e_p521    - 256); break;
		case mk_lib_iip_cp_destination_certificate_key_enc_type_e_x25519 : res = mk_lang_max(0, mk_lib_iip_cp_destination_key_len_enc_e_x25519  - 256); break;
		#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
		case mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
		#include "mk_lang_warning_clang_pop.h"
	}
	mk_lang_clobber(&res);
	return res;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_destination_file_format_certificate_type_t mk_lib_iip_cp_destination_remote_prrw_get_certificate_type(mk_lib_iip_cp_destination_remote_pct const remote_destination) mk_lang_noexcept
{
	mk_lib_iip_cp_destination_file_format_certificate_type_t res mk_lang_constexpr_init;

	mk_lang_assert(remote_destination);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type >= 0);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type < mk_lib_iip_cp_destination_cert_type_e_dummy_end);

	switch(remote_destination->m_certificate.m_cert_type)
	{
		case mk_lib_iip_cp_destination_cert_type_e_null   : res = mk_lib_iip_cp_destination_file_format_certificate_type_e_null  ; break;
		case mk_lib_iip_cp_destination_cert_type_e_hidden : res = mk_lib_iip_cp_destination_file_format_certificate_type_e_hidden; break;
		case mk_lib_iip_cp_destination_cert_type_e_signeda: res = mk_lib_iip_cp_destination_file_format_certificate_type_e_signed; break;
		case mk_lib_iip_cp_destination_cert_type_e_signedb: res = mk_lib_iip_cp_destination_file_format_certificate_type_e_signed; break;
		case mk_lib_iip_cp_destination_cert_type_e_key    : res = mk_lib_iip_cp_destination_file_format_certificate_type_e_key   ; break;
		case mk_lib_iip_cp_destination_cert_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&res);
	return res;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_destination_remote_prrw_from_bytes(mk_lib_iip_cp_destination_remote_pt const remote_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t cert_type_num mk_lang_constexpr_init;
	mk_lib_iip_cp_destination_file_format_certificate_type_t cert_type_id mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16 mk_lang_constexpr_init;
	mk_lang_types_sint_t cert_len mk_lang_constexpr_init;
	mk_lang_types_sint_t sgn_type_num mk_lang_constexpr_init;
	mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_t sgn_ff_type_id mk_lang_constexpr_init;
	mk_lib_iip_cp_destination_certificate_key_sgn_type_t sgn_my_type_id mk_lang_constexpr_init;
	mk_lang_types_sint_t enc_type_num mk_lang_constexpr_init;
	mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_t enc_ff_type_id mk_lang_constexpr_init;
	mk_lib_iip_cp_destination_certificate_key_enc_type_t enc_my_type_id mk_lang_constexpr_init;
	mk_lang_types_sint_t sgn_additional_data_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct sgn_additional_data_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t enc_additional_data_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct enc_additional_data_buf mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_pub_key) == mk_lib_iip_cp_destination_key_additional_len_worst_sgn_v);
	mk_lang_static_assert(mk_lib_iip_cp_destination_key_additional_len_worst_enc_v == 0);

	mk_lang_assert(remote_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(succeeded);
	mk_lang_assert(*succeeded == mk_lang_true);
	mk_lang_assert(consumed);

	ptr = data_buf;
	rem = data_len;

	tlen = mk_lang_countof(remote_destination->m_basic_buffer.m_enc_pub_key.m_bytes);
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	mk_sl_cui_uint8_memcpy_fn(&remote_destination->m_basic_buffer.m_enc_pub_key.m_bytes[0], ptr, ((mk_lang_types_usize_t)(tlen)));
	ptr += tlen;
	rem -= tlen;

	tlen = mk_lang_countof(remote_destination->m_basic_buffer.m_sgn_pub_key.m_bytes);
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	mk_sl_cui_uint8_memcpy_fn(&remote_destination->m_basic_buffer.m_sgn_pub_key.m_bytes[0], ptr, ((mk_lang_types_usize_t)(tlen)));
	ptr += tlen;
	rem -= tlen;

	tlen = mk_sl_cui_uint8_size_bytes_v;
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	mk_sl_cui_uint8_to_bi_sint(ptr, &cert_type_num);
	ptr += tlen;
	rem -= tlen;

	cert_type_id = mk_lib_iip_cp_destination_file_format_certificate_type_from_sint(cert_type_num);
	if(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_dummy_end)
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	if
	(!(
		(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_null) ||
		(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_hidden) ||
		(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_signed) ||
		(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_key) ||
		(mk_lang_false)
	))
	{
		/* todo */
		*succeeded = mk_lang_false;
		return 0;
	}

	tlen = mk_sl_cui_uint16_size_bytes_v;
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	mk_sl_uint_convert_16_8_be_to_big(&tu16, ptr);
	mk_sl_cui_uint16_to_bi_sint(&tu16, &cert_len);
	ptr += tlen;
	rem -= tlen;

	if
	(!(
		(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_null && cert_len == 0) ||
		(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_hidden && cert_len == 0) ||
		(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_signed && (cert_len == mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signeda.m_dsa_signature) || cert_len == mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signeda.m_dsa_signature) + mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signing_destination_hash))) ||
		(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_key && cert_len >= 2 * mk_sl_cui_uint16_size_bytes_v) ||
		(mk_lang_false)
	))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	tlen = cert_len;
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}

	if(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_null)
	{
		remote_destination->m_certificate.m_cert_type = mk_lib_iip_cp_destination_cert_type_e_null;
	}
	else if(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_hidden)
	{
		remote_destination->m_certificate.m_cert_type = mk_lib_iip_cp_destination_cert_type_e_hidden;
	}
	else if(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_signed)
	{
		if(cert_len == mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signeda.m_dsa_signature))
		{
			remote_destination->m_certificate.m_cert_type = mk_lib_iip_cp_destination_cert_type_e_signeda;
			tlen = mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signeda.m_dsa_signature); mk_sl_cui_uint8_memcpy_fn(&remote_destination->m_certificate.m_cert_data.m_data.m_signeda.m_dsa_signature[0], ptr, ((mk_lang_types_usize_t)(tlen))); ptr += tlen; rem -= tlen;
		}
		else if(cert_len == mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signeda.m_dsa_signature) + mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signing_destination_hash))
		{
			remote_destination->m_certificate.m_cert_type = mk_lib_iip_cp_destination_cert_type_e_signedb;
			tlen = mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signeda.m_dsa_signature ); mk_sl_cui_uint8_memcpy_fn(&remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signeda.m_dsa_signature [0], ptr, ((mk_lang_types_usize_t)(tlen))); ptr += tlen; rem -= tlen;
			tlen = mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signing_destination_hash); mk_sl_cui_uint8_memcpy_fn(&remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signing_destination_hash[0], ptr, ((mk_lang_types_usize_t)(tlen))); ptr += tlen; rem -= tlen;
		}
		else
		{
			mk_lang_assert_false();
		}
	}
	else if(cert_type_id == mk_lib_iip_cp_destination_file_format_certificate_type_e_key)
	{
		remote_destination->m_certificate.m_cert_type = mk_lib_iip_cp_destination_cert_type_e_key;
		tlen = mk_sl_cui_uint16_size_bytes_v;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		mk_sl_uint_convert_16_8_be_to_big(&tu16, ptr);
		mk_sl_cui_uint16_to_bi_sint(&tu16, &sgn_type_num);
		ptr += tlen;
		rem -= tlen;

		sgn_ff_type_id = mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_from_sint(sgn_type_num);
		if(sgn_ff_type_id == mk_lib_iip_cp_destination_file_format_certificate_key_sgn_type_e_dummy_end)
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		sgn_my_type_id = mk_lib_iip_cp_destination_certificate_key_sgn_type_from_file_format(sgn_ff_type_id);

		tlen = mk_sl_cui_uint16_size_bytes_v;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		mk_sl_uint_convert_16_8_be_to_big(&tu16, ptr);
		mk_sl_cui_uint16_to_bi_sint(&tu16, &enc_type_num);
		ptr += tlen;
		rem -= tlen;

		enc_ff_type_id = mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_from_sint(enc_type_num);
		if(enc_ff_type_id == mk_lib_iip_cp_destination_file_format_certificate_key_enc_type_e_dummy_end)
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		enc_my_type_id = mk_lib_iip_cp_destination_certificate_key_enc_type_from_file_format(enc_ff_type_id);

		sgn_additional_data_len = mk_lib_iip_cp_destination_get_key_additional_len_sgn(sgn_my_type_id);
		tlen = sgn_additional_data_len;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		sgn_additional_data_buf = ptr;
		ptr += tlen;
		rem -= tlen;

		enc_additional_data_len = mk_lib_iip_cp_destination_get_key_additional_len_enc(enc_my_type_id);
		tlen = enc_additional_data_len;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		enc_additional_data_buf = ptr;
		ptr += tlen;
		rem -= tlen;

		if(!(2 * mk_sl_cui_uint16_size_bytes_v + sgn_additional_data_len + enc_additional_data_len == cert_len))
		{
			*succeeded = mk_lang_false;
			return 0;
		}

		remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type = enc_my_type_id;
		remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type = sgn_my_type_id;
		mk_sl_cui_uint8_memcpy_fn(&remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_pub_key[0], sgn_additional_data_buf, ((mk_lang_types_usize_t)(sgn_additional_data_len)));
		/*mk_sl_cui_uint8_memcpy_fn(&remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_pub_key[0], enc_additional_data_buf, ((mk_lang_types_usize_t)(enc_additional_data_len)));*/
	}
	else
	{
		mk_lang_assert_false();
	}

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_destination_remote_prro_to_bytes(mk_lib_iip_cp_destination_remote_pct const remote_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lib_iip_cp_destination_file_format_certificate_type_t cert_type_id mk_lang_constexpr_init;
	mk_lang_types_sint_t cert_type_num mk_lang_constexpr_init;
	mk_lang_types_sint_t cert_len mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16 mk_lang_constexpr_init;
	mk_lang_types_sint_t sgn_additional_data_len mk_lang_constexpr_init;
	mk_lang_types_sint_t enc_additional_data_len mk_lang_constexpr_init;
	mk_lang_types_sint_t sgn_type_num mk_lang_constexpr_init;
	mk_lang_types_sint_t enc_type_num mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_pub_key) == mk_lib_iip_cp_destination_key_additional_len_worst_sgn_v);
	mk_lang_static_assert(mk_lib_iip_cp_destination_key_additional_len_worst_enc_v == 0);

	mk_lang_assert(remote_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(succeeded);
	mk_lang_assert(*succeeded == mk_lang_true);
	mk_lang_assert(consumed);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type >= 0);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type < mk_lib_iip_cp_destination_cert_type_e_dummy_end);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type >= 0));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type < mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type >= 0));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type < mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end));

	ptr = data_buf;
	rem = data_len;

	tlen = mk_lang_countof(remote_destination->m_basic_buffer.m_enc_pub_key.m_bytes);
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	mk_sl_cui_uint8_memcpy_fn(ptr, &remote_destination->m_basic_buffer.m_enc_pub_key.m_bytes[0], ((mk_lang_types_usize_t)(tlen)));
	ptr += tlen;
	rem -= tlen;

	tlen = mk_lang_countof(remote_destination->m_basic_buffer.m_sgn_pub_key.m_bytes);
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	mk_sl_cui_uint8_memcpy_fn(ptr, &remote_destination->m_basic_buffer.m_sgn_pub_key.m_bytes[0], ((mk_lang_types_usize_t)(tlen)));
	ptr += tlen;
	rem -= tlen;

	tlen = mk_sl_cui_uint8_size_bytes_v;
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	cert_type_id = mk_lib_iip_cp_destination_remote_prrw_get_certificate_type(remote_destination);
	cert_type_num = ((mk_lang_types_sint_t)(cert_type_id));
	mk_sl_cui_uint8_from_bi_sint(ptr, &cert_type_num);
	ptr += tlen;
	rem -= tlen;

	switch(remote_destination->m_certificate.m_cert_type)
	{
		case mk_lib_iip_cp_destination_cert_type_e_null:
		{
			tlen = mk_sl_cui_uint16_size_bytes_v;
			if(!(rem >= tlen))
			{
				*succeeded = mk_lang_false;
				return 0;
			}
			cert_len = 0;
			mk_sl_cui_uint16_from_bi_sint(&tu16, &cert_len);
			mk_sl_uint_convert_16_8_be_to_sml(&tu16, ptr);
			ptr += tlen;
			rem -= tlen;
		}
		break;
		case mk_lib_iip_cp_destination_cert_type_e_hidden:
		{
			tlen = mk_sl_cui_uint16_size_bytes_v;
			if(!(rem >= tlen))
			{
				*succeeded = mk_lang_false;
				return 0;
			}
			cert_len = 0;
			mk_sl_cui_uint16_from_bi_sint(&tu16, &cert_len);
			mk_sl_uint_convert_16_8_be_to_sml(&tu16, ptr);
			ptr += tlen;
			rem -= tlen;
		}
		break;
		case mk_lib_iip_cp_destination_cert_type_e_signeda:
		{
			tlen = mk_sl_cui_uint16_size_bytes_v;
			if(!(rem >= tlen))
			{
				*succeeded = mk_lang_false;
				return 0;
			}
			cert_len = mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signeda.m_dsa_signature);
			mk_sl_cui_uint16_from_bi_sint(&tu16, &cert_len);
			mk_sl_uint_convert_16_8_be_to_sml(&tu16, ptr);
			ptr += tlen;
			rem -= tlen;
			tlen = mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signeda.m_dsa_signature);
			if(!(rem >= tlen))
			{
				*succeeded = mk_lang_false;
				return 0;
			}
			mk_sl_cui_uint8_memcpy_fn(ptr, &remote_destination->m_certificate.m_cert_data.m_data.m_signeda.m_dsa_signature[0], tlen);
			ptr += tlen;
			rem -= tlen;
		}
		break;
		case mk_lib_iip_cp_destination_cert_type_e_signedb:
		{
			tlen = mk_sl_cui_uint16_size_bytes_v;
			if(!(rem >= tlen))
			{
				*succeeded = mk_lang_false;
				return 0;
			}
			cert_len = mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signeda.m_dsa_signature) + mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signing_destination_hash);
			mk_sl_cui_uint16_from_bi_sint(&tu16, &cert_len);
			mk_sl_uint_convert_16_8_be_to_sml(&tu16, ptr);
			ptr += tlen;
			rem -= tlen;
			tlen = mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signeda.m_dsa_signature);
			if(!(rem >= tlen))
			{
				*succeeded = mk_lang_false;
				return 0;
			}
			mk_sl_cui_uint8_memcpy_fn(ptr, &remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signeda.m_dsa_signature[0], tlen);
			ptr += tlen;
			rem -= tlen;
			tlen = mk_lang_countof(remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signing_destination_hash);
			if(!(rem >= tlen))
			{
				*succeeded = mk_lang_false;
				return 0;
			}
			mk_sl_cui_uint8_memcpy_fn(ptr, &remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signing_destination_hash[0], tlen);
			ptr += tlen;
			rem -= tlen;
		}
		break;
		case mk_lib_iip_cp_destination_cert_type_e_key:
		{
			tlen = mk_sl_cui_uint16_size_bytes_v;
			if(!(rem >= tlen))
			{
				*succeeded = mk_lang_false;
				return 0;
			}
			sgn_additional_data_len = mk_lib_iip_cp_destination_get_key_additional_len_sgn(remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type);
			enc_additional_data_len = mk_lib_iip_cp_destination_get_key_additional_len_enc(remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type);
			cert_len = 2 * mk_sl_cui_uint16_size_bytes_v + sgn_additional_data_len + enc_additional_data_len;
			mk_sl_cui_uint16_from_bi_sint(&tu16, &cert_len);
			mk_sl_uint_convert_16_8_be_to_sml(&tu16, ptr);
			ptr += tlen;
			rem -= tlen;
			tlen = mk_sl_cui_uint16_size_bytes_v;
			if(!(rem >= tlen))
			{
				*succeeded = mk_lang_false;
				return 0;
			}
			sgn_type_num = ((mk_lang_types_sint_t)(mk_lib_iip_cp_destination_certificate_key_sgn_type_to_file_format(remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type)));
			mk_sl_cui_uint16_from_bi_sint(&tu16, &sgn_type_num);
			mk_sl_uint_convert_16_8_be_to_sml(&tu16, ptr);
			ptr += tlen;
			rem -= tlen;
			tlen = mk_sl_cui_uint16_size_bytes_v;
			if(!(rem >= tlen))
			{
				*succeeded = mk_lang_false;
				return 0;
			}
			enc_type_num = ((mk_lang_types_sint_t)(mk_lib_iip_cp_destination_certificate_key_enc_type_to_file_format(remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type)));
			mk_sl_cui_uint16_from_bi_sint(&tu16, &enc_type_num);
			mk_sl_uint_convert_16_8_be_to_sml(&tu16, ptr);
			ptr += tlen;
			rem -= tlen;
			tlen = sgn_additional_data_len;
			if(!(rem >= tlen))
			{
				*succeeded = mk_lang_false;
				return 0;
			}
			mk_sl_cui_uint8_memcpy_fn(ptr, &remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_pub_key[0], tlen);
			ptr += tlen;
			rem -= tlen;
			tlen = enc_additional_data_len;
			if(!(rem >= tlen))
			{
				*succeeded = mk_lang_false;
				return 0;
			}
			/*mk_sl_cui_uint8_memcpy_fn(ptr, &remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_pub_key[0], tlen);*/
			ptr += tlen;
			rem -= tlen;
		}
		break;
		case mk_lib_iip_cp_destination_cert_type_e_dummy_end:
		{
			mk_lang_assert_false();
		}
		break;
		default:
		{
			mk_lang_assert_false();
		}
		break;
	}

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_destination_remote_prro_enc_to_bytes(mk_lib_iip_cp_destination_remote_pct const remote_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(remote_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(succeeded);
	mk_lang_assert(*succeeded == mk_lang_true);
	mk_lang_assert(consumed);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type >= 0);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type < mk_lib_iip_cp_destination_cert_type_e_dummy_end);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type >= 0));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type < mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type >= 0));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type < mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end));

	ptr = data_buf;
	rem = data_len;
	tlen = mk_lang_countof(remote_destination->m_basic_buffer.m_enc_pub_key.m_bytes);
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	mk_lang_assert((remote_destination->m_certificate.m_cert_type == mk_lib_iip_cp_destination_cert_type_e_null) || (remote_destination->m_certificate.m_cert_type == mk_lib_iip_cp_destination_cert_type_e_key && remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal)); /* todo */
	mk_sl_cui_uint8_memcpy_fn(ptr, &remote_destination->m_basic_buffer.m_enc_pub_key.m_bytes[0], ((mk_lang_types_usize_t)(tlen)));
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_destination_get_key_len_sgn_2(mk_lib_iip_cp_destination_remote_pct const remote_destination) mk_lang_noexcept
{
	mk_lang_types_sint_t res mk_lang_constexpr_init;

	mk_lang_assert(remote_destination);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type >= 0);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type < mk_lib_iip_cp_destination_cert_type_e_dummy_end);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type >= 0));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type < mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type >= 0));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type < mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end));

	switch(remote_destination->m_certificate.m_cert_type)
	{
		case mk_lib_iip_cp_destination_cert_type_e_null   : res = mk_lib_iip_cp_destination_key_len_sgn_e_dsa_sha1; break;
		case mk_lib_iip_cp_destination_cert_type_e_hidden : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_destination_cert_type_e_signeda: mk_lang_check_todo(); break;
		case mk_lib_iip_cp_destination_cert_type_e_signedb: mk_lang_check_todo(); break;
		case mk_lib_iip_cp_destination_cert_type_e_key    : res = mk_lib_iip_cp_destination_get_key_len_sgn(remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type); break;
		case mk_lib_iip_cp_destination_cert_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&res);
	return res;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_destination_remote_prro_sgn_to_bytes(mk_lib_iip_cp_destination_remote_pct const remote_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(remote_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(succeeded);
	mk_lang_assert(*succeeded == mk_lang_true);
	mk_lang_assert(consumed);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type >= 0);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type < mk_lib_iip_cp_destination_cert_type_e_dummy_end);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type >= 0));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type < mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type >= 0));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type < mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end));

	ptr = data_buf;
	rem = data_len;
	tlen = mk_lib_iip_cp_destination_get_key_len_sgn_2(remote_destination);
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	mk_lang_assert(tlen <= mk_lang_countof(remote_destination->m_basic_buffer.m_sgn_pub_key.m_bytes)); /* todo */
	mk_sl_cui_uint8_memcpy_fn(ptr, &remote_destination->m_basic_buffer.m_sgn_pub_key.m_bytes[0], ((mk_lang_types_usize_t)(tlen)));
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_destination_remote_prro_to_b32(mk_lib_iip_cp_destination_remote_pct const remote_destination, mk_lang_static_param(mk_lang_types_pchar_t, str_buf, 52), mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_sl_cui_uint8_t dst_buf[2 * 1024] mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha2_256_t hasher mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha2_256_digest_t digest mk_lang_constexpr_init;

	mk_lang_assert(remote_destination);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(consumed);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type >= 0);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type < mk_lib_iip_cp_destination_cert_type_e_dummy_end);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type >= 0));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type < mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type >= 0));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type < mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end));

	ptr = str_buf;
	rem = str_len;
	if(rem >= mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5))
	{
		gud = mk_lang_true;
		err = mk_lib_iip_cp_destination_remote_prro_to_bytes(remote_destination, &dst_buf[0], mk_lang_countof(dst_buf), &gud, &tlen); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(tlen >= 256 + 128 + 1 + 2); mk_lang_assert(tlen <= mk_lang_countof(dst_buf));
		mk_lib_crypto_hash_stream_sha2_256_init(&hasher);
		mk_lib_crypto_hash_stream_sha2_256_append_u8s(&hasher, &dst_buf[0], ((mk_lang_types_usize_t)(tlen)));
		mk_lib_crypto_hash_stream_sha2_256_finish(&hasher, &digest);
		mk_lib_iip_base32_encoder_fn(&digest.m_data.m_uint8s[0], mk_lib_crypto_hash_block_sha2_256_digest_len_v, ptr, rem, &tlen); mk_lang_assert(tlen == mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5)); ptr += tlen; rem -= tlen;
		tlen = mk_lang_countstr(mk_lib_iip_cp_destination_k_b32_suffix);
		if(rem >= tlen){ mk_lang_string_memcpy_pc_fn(ptr, &mk_lib_iip_cp_destination_k_b32_suffix[0], tlen); ptr += tlen; rem -= tlen; }
		if(rem >= 1){ ptr[0] = '\0'; ptr += 1; rem -= 1; }
	}
	tlen = str_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_destination_remote_prro_get_signature_len(mk_lib_iip_cp_destination_remote_pct const remote_destination) mk_lang_noexcept
{
	mk_lang_types_sint_t res mk_lang_constexpr_init;

	mk_lang_assert(remote_destination);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type >= 0);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type < mk_lib_iip_cp_destination_cert_type_e_dummy_end);
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type >= 0));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type < mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type >= 0));
	mk_lang_assert(remote_destination->m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type < mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end));

	switch(remote_destination->m_certificate.m_cert_type)
	{
		case mk_lib_iip_cp_destination_cert_type_e_null   : res = 40; break;
		case mk_lib_iip_cp_destination_cert_type_e_hidden : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_destination_cert_type_e_signeda: mk_lang_check_todo(); break;
		case mk_lib_iip_cp_destination_cert_type_e_signedb: mk_lang_check_todo(); break;
		case mk_lib_iip_cp_destination_cert_type_e_key:
		{
			switch(remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type)
			{
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dsa_sha1              : mk_lang_check_todo(); break;
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha256_p256     : res = 64; break;
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha384_p384     : mk_lang_check_todo(); break;
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha512_p521     : mk_lang_check_todo(); break;
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha256_2048       : mk_lang_check_todo(); break;
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha384_3072       : mk_lang_check_todo(); break;
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_rsa_sha512_4096       : mk_lang_check_todo(); break;
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519  : res = 64; break;
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519ph: mk_lang_check_todo(); break;
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_gost_a                : mk_lang_check_todo(); break;
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_gost_b                : mk_lang_check_todo(); break;
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_reddsa_sha512_ed25519 : mk_lang_check_todo(); break;
				case mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end: mk_lang_assert_false(); break;
				default: mk_lang_assert_false(); break;
			}
		}
		break;
		case mk_lib_iip_cp_destination_cert_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&res);
	return res;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_destination_local_prro_enc_to_bytes(mk_lib_iip_cp_destination_local_pct const local_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(local_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(succeeded);
	mk_lang_assert(*succeeded == mk_lang_true);
	mk_lang_assert(consumed);
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type >= 0);
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type < mk_lib_iip_cp_destination_cert_type_e_dummy_end);
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (local_destination->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type >= 0));
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (local_destination->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type < mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end));
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (local_destination->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type >= 0));
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (local_destination->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type < mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end));

	ptr = data_buf;
	rem = data_len;
	tlen = mk_lang_countof(local_destination->m_basic_buffer.m_enc_pri_key.m_bytes);
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	mk_sl_cui_uint8_memcpy_fn(ptr, &local_destination->m_basic_buffer.m_enc_pri_key.m_bytes[0], ((mk_lang_types_usize_t)(tlen)));
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_destination_local_prro_sgn_to_bytes(mk_lib_iip_cp_destination_local_pct const local_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(local_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(succeeded);
	mk_lang_assert(*succeeded == mk_lang_true);
	mk_lang_assert(consumed);
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type >= 0);
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type < mk_lib_iip_cp_destination_cert_type_e_dummy_end);
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (local_destination->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type >= 0));
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (local_destination->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type < mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end));
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (local_destination->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type >= 0));
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (local_destination->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type < mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end));

	ptr = data_buf;
	rem = data_len;
	tlen = mk_lang_countof(local_destination->m_basic_buffer.m_sgn_pri_key.m_bytes);
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	mk_sl_cui_uint8_memcpy_fn(ptr, &local_destination->m_basic_buffer.m_sgn_pri_key.m_bytes[0], ((mk_lang_types_usize_t)(tlen)));
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_cp_destination_local_prro_eq_enc(mk_lib_iip_cp_destination_local_pct const a, mk_lib_iip_cp_destination_local_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t eq mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a->m_remote_destination.m_certificate.m_cert_type >= 0);
	mk_lang_assert(a->m_remote_destination.m_certificate.m_cert_type < mk_lib_iip_cp_destination_cert_type_e_dummy_end);
	mk_lang_assert(a->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (a->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type >= 0));
	mk_lang_assert(a->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (a->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type < mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end));
	mk_lang_assert(a->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (a->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type >= 0));
	mk_lang_assert(a->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (a->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type < mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end));
	mk_lang_assert(b->m_remote_destination.m_certificate.m_cert_type >= 0);
	mk_lang_assert(b->m_remote_destination.m_certificate.m_cert_type < mk_lib_iip_cp_destination_cert_type_e_dummy_end);
	mk_lang_assert(b->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (b->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type >= 0));
	mk_lang_assert(b->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (b->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type < mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dummy_end));
	mk_lang_assert(b->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (b->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type >= 0));
	mk_lang_assert(b->m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_key || (b->m_remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type < mk_lib_iip_cp_destination_certificate_key_enc_type_e_dummy_end));

	eq = mk_lang_true;
	eq = eq && (a->m_remote_destination.m_certificate.m_cert_type == b->m_remote_destination.m_certificate.m_cert_type);
	eq = eq && (mk_sl_cui_uint8_memcmp_fn(&a->m_basic_buffer.m_enc_pri_key.m_bytes[0], &b->m_basic_buffer.m_enc_pri_key.m_bytes[0], mk_lang_countof(a->m_basic_buffer.m_enc_pri_key.m_bytes)) == 0);
	eq = eq && (mk_sl_cui_uint8_memcmp_fn(&a->m_remote_destination.m_basic_buffer.m_enc_pub_key.m_bytes[0], &b->m_remote_destination.m_basic_buffer.m_enc_pub_key.m_bytes[0], mk_lang_countof(a->m_remote_destination.m_basic_buffer.m_enc_pub_key.m_bytes)) == 0);
	return eq;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_destination_remote_rw_from_bytes(mk_lib_iip_cp_destination_remote_pt const remote_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_cp_destination_remote_prrw_from_bytes(remote_destination, data_buf, data_len, succeeded, consumed);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_destination_remote_ro_to_bytes(mk_lib_iip_cp_destination_remote_pct const remote_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_cp_destination_remote_prro_to_bytes(remote_destination, data_buf, data_len, succeeded, consumed);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_destination_remote_ro_enc_to_bytes(mk_lib_iip_cp_destination_remote_pct const remote_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_cp_destination_remote_prro_enc_to_bytes(remote_destination, data_buf, data_len, succeeded, consumed);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_destination_remote_ro_sgn_to_bytes(mk_lib_iip_cp_destination_remote_pct const remote_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_cp_destination_remote_prro_sgn_to_bytes(remote_destination, data_buf, data_len, succeeded, consumed);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_destination_remote_ro_to_b32(mk_lib_iip_cp_destination_remote_pct const remote_destination, mk_lang_static_param(mk_lang_types_pchar_t, str_buf, 52), mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_cp_destination_remote_prro_to_b32(remote_destination, str_buf, str_len, consumed);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_destination_remote_ro_get_signature_len(mk_lib_iip_cp_destination_remote_pct const remote_destination) mk_lang_noexcept
{
	return mk_lib_iip_cp_destination_remote_prro_get_signature_len(remote_destination);
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_destination_local_ro_enc_to_bytes(mk_lib_iip_cp_destination_local_pct const local_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_cp_destination_local_prro_enc_to_bytes(local_destination, data_buf, data_len, succeeded, consumed);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_destination_local_ro_sgn_to_bytes(mk_lib_iip_cp_destination_local_pct const local_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_cp_destination_local_prro_sgn_to_bytes(local_destination, data_buf, data_len, succeeded, consumed);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_destination_local_ro_eq_enc(mk_lib_iip_cp_destination_local_pct const a, mk_lib_iip_cp_destination_local_pct const b) mk_lang_noexcept
{
	return mk_lib_iip_cp_destination_local_prro_eq_enc(a, b);
}


#endif
