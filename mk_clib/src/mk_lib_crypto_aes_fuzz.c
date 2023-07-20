#include "mk_lib_crypto_aes_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_crash.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_app.h"
#include "mk_win_advapi.h"
#include "mk_win_base.h"
#include "mk_win_bcrypt.h"


#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_crash(); } ((void)(0))
#define check_len(x) if(!(d && s >= (x))) { return; } ((void)(0))
#define advance(x) { d += (x); s -= (x); } ((void)(0))


static mk_lib_crypto_app_t g_app;


mk_lang_jumbo void mk_lib_crypto_aes_fuzz_my(mk_lang_types_bool_t const cpuida, mk_lang_types_bool_t const cpuidb, mk_lib_crypto_app_id_alg_t const alg_id, mk_lib_crypto_app_id_padding_t const padding_id, mk_lib_crypto_app_id_mode_t const mode_id, mk_lang_types_uchar_pct const key, mk_lang_types_uchar_pct const iv, mk_lang_types_uchar_pct const msg, mk_lang_types_uint_t const msg_len, mk_lang_types_uchar_pt const out, mk_lang_types_uint_pt const padding_len) mk_lang_noexcept
{
	int i;
	mk_lang_types_ssize_t ra;
	mk_lang_types_ssize_t rb;

	if(cpuida){ mk_lang_cpuid_init(); }else{ mk_lang_cpuid_reset(); }
	g_app.m_id_alg = alg_id;
	g_app.m_id_padding = padding_id;
	g_app.m_id_mode = mode_id;
	for(i = 0; i != 32; ++i){ ((mk_lang_types_uchar_pt)(&g_app.m_key))[i] = key[i]; }
	for(i = 0; i != 16; ++i){ ((mk_lang_types_uchar_pt)(&g_app.m_mode))[i] = iv[i]; }
	for(i = 0; i != msg_len; ++i){ ((mk_lang_types_uchar_pt)(&g_app.m_buffer))[i] = msg[i]; }
	ra = mk_lib_crypto_app_encrypt_finish(&g_app, msg_len); test(ra >= 0 && ra <= 16);
	for(i = 0; i != msg_len + ra; ++i){ out[i] = ((mk_lang_types_uchar_pt)(&g_app.m_buffer))[i]; }
	*padding_len = ((mk_lang_types_uint_t)(ra));
	if(cpuidb){ mk_lang_cpuid_init(); }else{ mk_lang_cpuid_reset(); }
	for(i = 0; i != 16; ++i){ ((mk_lang_types_uchar_pt)(&g_app.m_mode))[i] = iv[i]; }
	rb = mk_lib_crypto_app_decrypt_finish(&g_app, msg_len + ra); test(rb >= 0 && rb <= 16); test(rb == ra);
	for(i = 0; i != msg_len; ++i){ test(((mk_lang_types_uchar_pt)(&g_app.m_buffer))[i] == msg[i]); }
}

mk_lang_jumbo void mk_lib_crypto_aes_fuzz_win(mk_lang_types_bool_t const cpuida, mk_lang_types_bool_t const cpuidb, mk_lib_crypto_app_id_alg_t const alg_id, mk_lib_crypto_app_id_padding_t const padding_id, mk_lib_crypto_app_id_mode_t const mode_id, mk_lang_types_uchar_pct const key, mk_lang_types_uchar_pct const iv, mk_lang_types_uchar_pct const msg, mk_lang_types_uint_t const msg_len, mk_lang_types_uchar_pt const out, mk_lang_types_uint_pct const padding_len) mk_lang_noexcept
{
	struct aes_128_key_blob_s
	{
		mk_win_advapi_blob_header_t m_header;
		mk_win_base_dword_t m_len;
		mk_lang_types_uchar_t m_data[16];
	};
	typedef struct aes_128_key_blob_s aes_128_key_blob_t;
	typedef aes_128_key_blob_t const aes_128_key_blob_ct;
	typedef aes_128_key_blob_t* aes_128_key_blob_pt;
	typedef aes_128_key_blob_t const* aes_128_key_blob_pct;
	struct aes_192_key_blob_s
	{
		mk_win_advapi_blob_header_t m_header;
		mk_win_base_dword_t m_len;
		mk_lang_types_uchar_t m_data[24];
	};
	typedef struct aes_192_key_blob_s aes_192_key_blob_t;
	typedef aes_192_key_blob_t const aes_192_key_blob_ct;
	typedef aes_192_key_blob_t* aes_192_key_blob_pt;
	typedef aes_192_key_blob_t const* aes_192_key_blob_pct;
	struct aes_256_key_blob_s
	{
		mk_win_advapi_blob_header_t m_header;
		mk_win_base_dword_t m_len;
		mk_lang_types_uchar_t m_data[32];
	};
	typedef struct aes_256_key_blob_s aes_256_key_blob_t;
	typedef aes_256_key_blob_t const aes_256_key_blob_ct;
	typedef aes_256_key_blob_t* aes_256_key_blob_pt;
	typedef aes_256_key_blob_t const* aes_256_key_blob_pct;
	union aes_key_blob_u
	{
		aes_128_key_blob_t m_aes_128;
		aes_192_key_blob_t m_aes_192;
		aes_256_key_blob_t m_aes_256;
	};
	typedef union aes_key_blob_u aes_key_blob_t;
	typedef aes_key_blob_t const aes_key_blob_ct;
	typedef aes_key_blob_t* aes_key_blob_pt;
	typedef aes_key_blob_t const* aes_key_blob_pct;

	mk_lang_types_bool_t good;
	aes_key_blob_t win_key_data;
	mk_lang_types_sint_t i;
	mk_win_base_dword_t win_key_data_len;
	mk_win_base_bool_t b;
	mk_win_handle_advapi_prov_t csp;
	mk_win_handle_advapi_key_t win_key;
	mk_win_base_dword_t win_mode;
	mk_win_base_dword_t win_padding;
	mk_win_base_dword_t win_feedback_bits;
	mk_win_base_dword_t win_msg_len;
	mk_lang_types_uint_t check_len;

	good = mk_lang_true;
	switch(mode_id)
	{
		case mk_lib_crypto_app_id_mode_e_cbc:     good = good && mk_lang_true;  break;
		case mk_lib_crypto_app_id_mode_e_cfb_128: good = good && mk_lang_false; break;
		case mk_lib_crypto_app_id_mode_e_cfb_8:   good = good && mk_lang_true;  break;
		case mk_lib_crypto_app_id_mode_e_ctr_be:  good = good && mk_lang_false; break;
		case mk_lib_crypto_app_id_mode_e_ecb:     good = good && mk_lang_true;  break;
		case mk_lib_crypto_app_id_mode_e_ofb:     good = good && mk_lang_false; break;
		default: mk_lang_assert(0); break;
	}
	switch(padding_id)
	{
		case mk_lib_crypto_app_id_padding_e_pkcs7:      good = good && mk_lang_true;  break;
		case mk_lib_crypto_app_id_padding_e_iso9797pm2: good = good && mk_lang_false; break;
		default: mk_lang_assert(0); break;
	}
	if(!good)
	{
		return;
	}
	switch(alg_id)
	{
		case mk_lib_crypto_app_id_alg_e_aes_128: win_key_data.m_aes_128.m_header.m_type = mk_win_advapi_plaintextkeyblob; win_key_data.m_aes_128.m_header.m_version = mk_win_advapi_cur_blob_version; win_key_data.m_aes_128.m_header.m_reserved = 0; win_key_data.m_aes_128.m_header.m_alg_id = mk_win_advapi_calg_aes_128; win_key_data.m_aes_128.m_len = 16; for(i = 0; i != 16; ++i){ win_key_data.m_aes_128.m_data[i] = key[i]; } win_key_data_len = ((mk_win_base_dword_t)(sizeof(win_key_data.m_aes_128))); break;
		case mk_lib_crypto_app_id_alg_e_aes_192: win_key_data.m_aes_192.m_header.m_type = mk_win_advapi_plaintextkeyblob; win_key_data.m_aes_192.m_header.m_version = mk_win_advapi_cur_blob_version; win_key_data.m_aes_192.m_header.m_reserved = 0; win_key_data.m_aes_192.m_header.m_alg_id = mk_win_advapi_calg_aes_192; win_key_data.m_aes_192.m_len = 24; for(i = 0; i != 24; ++i){ win_key_data.m_aes_192.m_data[i] = key[i]; } win_key_data_len = ((mk_win_base_dword_t)(sizeof(win_key_data.m_aes_192))); break;
		case mk_lib_crypto_app_id_alg_e_aes_256: win_key_data.m_aes_256.m_header.m_type = mk_win_advapi_plaintextkeyblob; win_key_data.m_aes_256.m_header.m_version = mk_win_advapi_cur_blob_version; win_key_data.m_aes_256.m_header.m_reserved = 0; win_key_data.m_aes_256.m_header.m_alg_id = mk_win_advapi_calg_aes_256; win_key_data.m_aes_256.m_len = 32; for(i = 0; i != 32; ++i){ win_key_data.m_aes_256.m_data[i] = key[i]; } win_key_data_len = ((mk_win_base_dword_t)(sizeof(win_key_data.m_aes_256))); break;
		default: mk_lang_assert(0); break;
	}
	switch(mode_id)
	{
		case mk_lib_crypto_app_id_mode_e_cbc:   win_mode = mk_win_advapi_crypt_mode_cbc; break;
		case mk_lib_crypto_app_id_mode_e_cfb_8: win_mode = mk_win_advapi_crypt_mode_cfb; break;
		case mk_lib_crypto_app_id_mode_e_ecb:   win_mode = mk_win_advapi_crypt_mode_ecb; break;
		default: mk_lang_assert(0); break;
	}
	win_padding = mk_win_advapi_pkcs5_padding;
	win_feedback_bits = 8;
	b = CryptAcquireContextA(&csp, mk_lang_null, mk_win_advapi_ms_enh_rsa_aes_prov_a, mk_win_advapi_prov_rsa_aes, mk_win_advapi_crypt_verifycontext | mk_win_advapi_crypt_silent); test(b != 0); test(csp);
	b = CryptImportKey(csp, ((mk_lang_types_uchar_pct)(&win_key_data)), win_key_data_len, mk_lang_null, 0, &win_key); test(b != 0); test(win_key);
	b = CryptSetKeyParam(win_key, mk_win_advapi_kp_mode, &win_mode, 0); test(b != 0);
	b = CryptSetKeyParam(win_key, mk_win_advapi_kp_padding, &win_padding, 0); test(b != 0);
	b = CryptSetKeyParam(win_key, mk_win_advapi_kp_mode_bits, &win_feedback_bits, 0); test(b != 0);
	if(mode_id != mk_lib_crypto_app_id_mode_e_ecb)
	{
		b = CryptSetKeyParam(win_key, mk_win_advapi_kp_iv, &iv[0], 0); test(b != 0);
	}
	win_msg_len = msg_len;
	for(i = 0; i != msg_len; ++i){ ((mk_lang_types_uchar_pt)(&g_app.m_buffer))[i] = msg[i]; }
	b = CryptEncrypt(win_key, mk_lang_null, mk_win_base_true, 0, ((mk_lang_types_uchar_pt)(&g_app.m_buffer)), &win_msg_len, msg_len + 0x10); test(b != 0); test(win_msg_len == msg_len + *padding_len || mode_id == mk_lib_crypto_app_id_mode_e_cfb_8);
	check_len = msg_len + *padding_len;
	if(mode_id == mk_lib_crypto_app_id_mode_e_cfb_8){ check_len = msg_len; }
	for(i = 0; i != check_len; ++i){ test(((mk_lang_types_uchar_pt)(&g_app.m_buffer))[i] == out[i]); }
	b = CryptDestroyKey(win_key); test(b != 0);
	b = CryptReleaseContext(csp, 0); test(b != 0);
}

mk_lang_jumbo void mk_lib_crypto_aes_fuzz_winng(mk_lang_types_bool_t const cpuida, mk_lang_types_bool_t const cpuidb, mk_lib_crypto_app_id_alg_t const alg_id, mk_lib_crypto_app_id_padding_t const padding_id, mk_lib_crypto_app_id_mode_t const mode_id, mk_lang_types_uchar_pct const key, mk_lang_types_uchar_pct const iv, mk_lang_types_uchar_pct const msg, mk_lang_types_uint_t const msg_len, mk_lang_types_uchar_pt const out, mk_lang_types_uint_pct const padding_len) mk_lang_noexcept
{
	union aligned_key_u
	{
		mk_lang_types_uchar_t m_uchars[1024];
		mk_lang_types_ulllong_t m_ulllong;
	};
	typedef union aligned_key_u aligned_key_t;
	struct key_s
	{
		aligned_key_t m_data;
	};
	typedef struct key_s key_t;

	mk_lang_types_uchar_pct win_mode;
	mk_lang_types_ulong_t win_mode_len;
	mk_win_base_dword_t win_feedback_bytes;
	mk_lang_types_sint_t i;
	mk_lang_types_uchar_t win_iv[0x10];
	mk_lang_types_ulong_t win_iv_len;
	mk_lang_types_uchar_pt win_piv;
	mk_lang_types_ulong_t key_len;
	mk_lang_types_ulong_t win_out_len;
	mk_win_base_ntstatus_t st;
	mk_win_handle_bcrypt_alg_t alg;
	mk_win_base_dword_t len;
	mk_lang_types_ulong_t len_real;
	mk_win_handle_bcrypt_key_t hkey;
	key_t win_key;
	mk_lang_types_uchar_t win_out[0xff + 0x10];
	mk_lang_types_ulong_t win_out_len_real;
	mk_lang_types_sint_t check_len;

	win_mode = mk_lang_null;
	win_mode_len = 0;
	switch(mode_id)
	{
		case mk_lib_crypto_app_id_mode_e_cbc:     win_mode = ((mk_lang_types_uchar_pct)(mk_win_bcrypt_bcrypt_chain_mode_cbc)); win_mode_len = ((mk_lang_types_ulong_t)(sizeof(mk_win_bcrypt_bcrypt_chain_mode_cbc))); win_feedback_bytes =  0; break;
		case mk_lib_crypto_app_id_mode_e_cfb_128: win_mode = ((mk_lang_types_uchar_pct)(mk_win_bcrypt_bcrypt_chain_mode_cfb)); win_mode_len = ((mk_lang_types_ulong_t)(sizeof(mk_win_bcrypt_bcrypt_chain_mode_cfb))); win_feedback_bytes = 16; break;
		case mk_lib_crypto_app_id_mode_e_cfb_8:   win_mode = ((mk_lang_types_uchar_pct)(mk_win_bcrypt_bcrypt_chain_mode_cfb)); win_mode_len = ((mk_lang_types_ulong_t)(sizeof(mk_win_bcrypt_bcrypt_chain_mode_cfb))); win_feedback_bytes =  1; break;
		case mk_lib_crypto_app_id_mode_e_ctr_be:  win_mode = ((mk_lang_types_uchar_pct)(mk_lang_null));                        win_mode_len = ((mk_lang_types_ulong_t)(0));                                           win_feedback_bytes =  0; break;
		case mk_lib_crypto_app_id_mode_e_ecb:     win_mode = ((mk_lang_types_uchar_pct)(mk_win_bcrypt_bcrypt_chain_mode_ecb)); win_mode_len = ((mk_lang_types_ulong_t)(sizeof(mk_win_bcrypt_bcrypt_chain_mode_ecb))); win_feedback_bytes =  0; break;
		case mk_lib_crypto_app_id_mode_e_ofb:     win_mode = ((mk_lang_types_uchar_pct)(mk_lang_null));                        win_mode_len = ((mk_lang_types_ulong_t)(0));                                           win_feedback_bytes =  0; break;
		default: mk_lang_assert(0); break;
	}
	if(!win_mode || win_mode_len == 0)
	{
		return;
	}
	if(padding_id != mk_lib_crypto_app_id_padding_e_pkcs7)
	{
		return;
	}
	for(i = 0; i != 0x10; ++i){ win_iv[i] = iv[i]; }
	win_iv_len = mode_id != mk_lib_crypto_app_id_mode_e_ecb ? 0x10 : 0x00;
	win_piv = mode_id != mk_lib_crypto_app_id_mode_e_ecb ? &win_iv[0] : mk_lang_null;
	switch(alg_id)
	{
		case mk_lib_crypto_app_id_alg_e_aes_128: key_len = 16; break;
		case mk_lib_crypto_app_id_alg_e_aes_192: key_len = 24; break;
		case mk_lib_crypto_app_id_alg_e_aes_256: key_len = 32; break;
		default: mk_lang_assert(0); break;
	}
	win_out_len = ((mk_lang_types_ulong_t)(sizeof(win_out) / sizeof(win_out[0])));
	st = BCryptOpenAlgorithmProvider(&alg, mk_win_bcrypt_bcrypt_aes_algorithm, mk_win_bcrypt_ms_primitive_provider, 0); test(st == 0);
	st = BCryptGetProperty(((mk_win_handle_bcrypt_handle_t)(alg)), mk_win_bcrypt_bcrypt_object_length, ((mk_lang_types_uchar_pt)(&len)), ((mk_lang_types_ulong_t)(sizeof(len))), &len_real, 0); test(st == 0); test(len_real == ((mk_lang_types_ulong_t)(sizeof(len)))); test(len != 0); test(len <= ((mk_win_base_dword_t)(sizeof(win_key))));
	st = BCryptSetProperty(((mk_win_handle_bcrypt_handle_t)(alg)), mk_win_bcrypt_bcrypt_chaining_mode, win_mode, win_mode_len, 0);
	st = BCryptGenerateSymmetricKey(alg, &hkey, ((mk_lang_types_uchar_pt)(&win_key)), ((mk_lang_types_ulong_t)(sizeof(win_key))), key, key_len, 0); test(st == 0);
	if(win_feedback_bytes != 0)
	{
		st = BCryptSetProperty(((mk_win_handle_bcrypt_handle_t)(hkey)), mk_win_bcrypt_bcrypt_message_block_length, ((mk_lang_types_uchar_pct)(&win_feedback_bytes)), ((mk_lang_types_ulong_t)(sizeof(win_feedback_bytes))), 0); test(st == 0);
	}
	st = BCryptEncrypt(hkey, msg, msg_len, mk_lang_null, win_piv, win_iv_len, &win_out[0], win_out_len, &win_out_len_real, mk_win_bcrypt_bcrypt_block_padding); test(st == 0); test(win_out_len_real == msg_len + *padding_len || mode_id == mk_lib_crypto_app_id_mode_e_cfb_8);
	check_len = msg_len + *padding_len;
	if(mode_id == mk_lib_crypto_app_id_mode_e_cfb_8){ check_len = msg_len; }
	for(i = 0; i != check_len; ++i){ test(win_out[i] == out[i]); }
	st = BCryptDestroyKey(hkey); test(st == 0);
	st = BCryptCloseAlgorithmProvider(alg, 0); test(st == 0);
}


mk_lang_jumbo void mk_lib_crypto_aes_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t cpuida;
	mk_lang_types_uint_t cpuidb;
	mk_lang_types_uint_t alg_id;
	mk_lang_types_uint_t padding_id;
	mk_lang_types_uint_t mode_id;
	mk_lang_types_sint_t i;
	mk_lang_types_uchar_t key[32];
	mk_lang_types_uchar_t iv[16];
	mk_lang_types_uint_t msg_len;
	mk_lang_types_uchar_t msg[0xff];
	mk_lib_crypto_app_id_alg_t alg_e;
	mk_lib_crypto_app_id_padding_t padding_e;
	mk_lib_crypto_app_id_mode_t mode_e;
	mk_lang_types_uchar_t out[0xff + 0x10];
	mk_lang_types_uint_t padding_len;

	d = data;
	s = size;
	check_len(1); cpuida = d[0] % 2; advance(1);
	check_len(1); cpuidb = d[0] % 2; advance(1);
	check_len(1); alg_id = d[0] % 3; advance(1);
	check_len(1); padding_id = d[0] % 2; advance(1);
	check_len(1); mode_id = d[0] % 6; advance(1);
	check_len(32); for(i = 0; i != 32; ++i){ key[i] = d[i]; } advance(32);
	check_len(16); for(i = 0; i != 16; ++i){ iv[i] = d[i]; } advance(16);
	check_len(1); msg_len = d[0]; advance(1);
	check_len(msg_len); for(i = 0; i != msg_len; ++i){ msg[i] = d[i]; } advance(msg_len);
	alg_e = ((mk_lib_crypto_app_id_alg_t)(alg_id));
	padding_e = ((mk_lib_crypto_app_id_padding_t)(padding_id));
	mode_e = ((mk_lib_crypto_app_id_mode_t)(mode_id));
	mk_lib_crypto_aes_fuzz_my   (cpuida != 0, cpuidb != 0, alg_e, padding_e, mode_e, key, iv, msg, msg_len, out, &padding_len);
	mk_lib_crypto_aes_fuzz_win  (cpuida != 0, cpuidb != 0, alg_e, padding_e, mode_e, key, iv, msg, msg_len, out, &padding_len);
	mk_lib_crypto_aes_fuzz_winng(cpuida != 0, cpuidb != 0, alg_e, padding_e, mode_e, key, iv, msg, msg_len, out, &padding_len);
}


#undef test
#undef check_len
#undef advance
