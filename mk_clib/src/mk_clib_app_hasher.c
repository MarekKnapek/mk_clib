#ifndef mk_include_guard_mk_clib_app_hasher_c
#define mk_include_guard_mk_clib_app_hasher_c
#include "mk_clib_app_hasher.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_exe_name.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_any1.h"
#include "mk_lib_crypto_hash_stream_any2.h"
#include "mk_sl_cui_uint8.h"

#include <stdio.h> /* printf FILE fopen fread fclose */


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_hasher_k_uc[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_hasher_k_lc[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };


#define mk_clib_app_hasher_buff_size 4 * 1024
#define mk_clib_app_hasher_buff_algn 4 * 1024
union mk_clib_app_hasher_buff_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_lang_roundup_add(mk_clib_app_hasher_buff_size, mk_clib_app_hasher_buff_algn)];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_clib_app_hasher_buff_data_u mk_clib_app_hasher_buff_data_t;
struct mk_clib_app_hasher_buff_s
{
	mk_lang_alignas(mk_clib_app_hasher_buff_algn) mk_clib_app_hasher_buff_data_t m_data;
};
typedef struct mk_clib_app_hasher_buff_s mk_clib_app_hasher_buff_t;
mk_lang_typedef(mk_clib_app_hasher_buff);


mk_lang_nodiscard static mk_lang_inline mk_lang_types_pchar_t mk_clib_app_hasher_to_lower(mk_lang_types_pchar_t const pc) mk_lang_noexcept
{
	mk_lang_types_pchar_t res;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_static_assert(mk_lang_countof(mk_clib_app_hasher_k_uc) == mk_lang_countof(mk_clib_app_hasher_k_lc));

	res = pc;
	n = mk_lang_countof(mk_clib_app_hasher_k_uc);
	for(i = 0; i != n; ++i)
	{
		if(pc == mk_clib_app_hasher_k_uc[i])
		{
			res = mk_clib_app_hasher_k_lc[i];
			break;
		}
	}
	return res;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_clib_app_hasher_match(mk_lang_types_pchar_pct const a, mk_lang_types_pchar_pct const b, mk_lang_types_sint_t const c) mk_lang_noexcept
{
	mk_lang_types_bool_t res;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c >= 1);

	res = mk_lang_false;
	n = c;
	for(i = 0; i != n; ++i)
	{
		if(mk_clib_app_hasher_to_lower(a[i]) != mk_clib_app_hasher_to_lower(b[i]))
		{
			break;
		}
	}
	if(i == n)
	{
		res = a[i] == '\0' || b[i] == '\0';
	}
	return res;
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_hasher_print(mk_lib_crypto_hash_stream_any1_id_t const id, mk_sl_cui_uint8_pct const digest) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t str[((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_any1_digest_max_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))];

	mk_lang_assert(id >= 0 && id < mk_lib_crypto_hash_stream_any1_id_e_dummy_end);
	mk_lang_assert(digest);

	n = mk_lib_crypto_hash_stream_any1_get_digest_len(id); mk_lang_assert(mk_lang_countof(str) >= n * mk_sl_cui_uint8_strlen_hex_v);
	for(i = 0; i != n; ++i)
	{
		len = mk_sl_cui_uint8_to_str_hexf_n(&digest[i], &str[i * mk_sl_cui_uint8_strlen_hex_v], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
	}
	len = printf("%.*s\n", n * mk_sl_cui_uint8_strlen_hex_v, &str[0]); mk_lang_assert(len >= n * mk_sl_cui_uint8_strlen_hex_v);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hasher_work(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pct const* const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t c;
	mk_lang_types_pchar_pcpct v;
	mk_lang_types_pchar_pct arg_hash;
	mk_lang_types_pchar_pct arg_file;
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t len;
	mk_lib_crypto_hash_stream_any1_id_t id;
	mk_lib_crypto_hash_stream_any2_t hasher;
	FILE* inputf;
	mk_lang_types_usize_t read;
	mk_clib_app_hasher_buff_t buff;
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t closed;
	mk_sl_cui_uint8_t digest[mk_lib_crypto_hash_stream_any1_digest_max_len_v];

	mk_lang_assert(argc == 3);
	mk_lang_assert(argv);
	mk_lang_assert(argv[0]);

	c = argc;
	v = argv;
	n = c;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(v[i]);
		mk_lang_assert(v[i][0] != '\0');
	}
	arg_hash = v[1];
	arg_file = v[2];
	mk_lang_cpuid_init();
	n = mk_lib_crypto_hash_stream_any1_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		id = ((mk_lib_crypto_hash_stream_any1_id_t)(i));
		str = mk_lib_crypto_hash_stream_any1_get_str_buf(id); mk_lang_assert(str); mk_lang_assert(str[0] != '\0');
		len = mk_lib_crypto_hash_stream_any1_get_str_len(id); mk_lang_assert(len >= 1); mk_lang_assert(len <= 0xff);
		if(mk_clib_app_hasher_match(arg_hash, str, len))
		{
			break;
		}
	}
	mk_lang_check_return(i != mk_lib_crypto_hash_stream_any1_id_e_dummy_end);
	mk_lib_crypto_hash_stream_any2_init(&hasher, id);
	ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(&buff.m_data.m_uchars[0], mk_clib_app_hasher_buff_algn)));
	inputf = fopen(arg_file, "rb"); mk_lang_check_return(inputf);
	for(;;)
	{
		read = fread(ptr, 1, mk_clib_app_hasher_buff_size, inputf);
		if(read == 0)
		{
			break;
		}
		mk_lib_crypto_hash_stream_any2_append_u8s(&hasher, ptr, read);
	}
	closed = fclose(inputf); mk_lang_check_return(closed == 0);
	mk_lib_crypto_hash_stream_any2_finish(&hasher, &digest[0]);
	mk_clib_app_hasher_print(id, &digest[0]);
	return 0;
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_hasher_usage_strs(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_crypto_hash_stream_any1_id_t id;
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t tsi;

	n = mk_lib_crypto_hash_stream_any1_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		id = ((mk_lib_crypto_hash_stream_any1_id_t)(i));
		str = mk_lib_crypto_hash_stream_any1_get_str_buf(id); mk_lang_assert(str); mk_lang_assert(str[0] != '\0');
		len = mk_lib_crypto_hash_stream_any1_get_str_len(id); mk_lang_assert(len >= 1); mk_lang_assert(len <= 0xff);
		tsi = printf("%.*s ", len, str); mk_lang_assert(tsi >= 1);
	}
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hasher_usage(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_pchar_pct exe_name;

	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != '\0');

	exe_name = mk_lang_exe_name_get_n(argv[0]); mk_lang_assert(exe_name); mk_lang_assert(exe_name[0] != '\0');
	printf("Example usage:\n");
	printf("%s SHA-1 message.txt\n", exe_name);
	printf("%s SHA3-512 video.avi\n", exe_name);
	printf("Available algorithms: ");
	mk_clib_app_hasher_usage_strs();
	printf("\n");
	return 0;
}


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_hasher_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	if(argc == 1)
	{
		err = mk_clib_app_hasher_usage(argc, argv); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc == 3);
		err = mk_clib_app_hasher_work(argc, argv); mk_lang_check_rereturn(err);
	}
	return 0;
}


#endif
