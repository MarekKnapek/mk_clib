#include "mk_clib_app_crypt.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_gapp.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"

#include <stdio.h> /* printf FILE fopen fread fwrite fclose */
#include <stdlib.h> /* srand rand */
#include <time.h> /* time_t time */


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_crypt_arg_name_dir[] = "/direction";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_crypt_arg_name_alg[] = "/alg";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_crypt_arg_name_padding[] = "/padding";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_crypt_arg_name_mode[] = "/mode";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_crypt_arg_name_kdf[] = "/kdf";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_crypt_arg_name_password[] = "/password";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_crypt_arg_name_salt[] = "/salt";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_crypt_arg_name_cost[] = "/cost";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_crypt_arg_name_input[] = "/input";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_crypt_arg_name_output[] = "/output";

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_crypt_arg_name_dir_enc[] = "encrypt";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_crypt_arg_name_dir_dec[] = "decrypt";

mk_lang_constexpr_static_inline mk_lang_types_pchar_pct const s_mk_clib_app_crypt_arg_names[] =
{
	s_mk_clib_app_crypt_arg_name_dir,
	s_mk_clib_app_crypt_arg_name_alg,
	s_mk_clib_app_crypt_arg_name_padding,
	s_mk_clib_app_crypt_arg_name_mode,
	s_mk_clib_app_crypt_arg_name_kdf,
	s_mk_clib_app_crypt_arg_name_password,
	s_mk_clib_app_crypt_arg_name_salt,
	s_mk_clib_app_crypt_arg_name_cost,
	s_mk_clib_app_crypt_arg_name_input,
	s_mk_clib_app_crypt_arg_name_output,
};
mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_clib_app_crypt_arg_namelens[] =
{
	((mk_lang_types_uchar_t)(sizeof(s_mk_clib_app_crypt_arg_name_dir) / sizeof(s_mk_clib_app_crypt_arg_name_dir[0]) - 1)),
	((mk_lang_types_uchar_t)(sizeof(s_mk_clib_app_crypt_arg_name_alg) / sizeof(s_mk_clib_app_crypt_arg_name_alg[0]) - 1)),
	((mk_lang_types_uchar_t)(sizeof(s_mk_clib_app_crypt_arg_name_padding) / sizeof(s_mk_clib_app_crypt_arg_name_padding[0]) - 1)),
	((mk_lang_types_uchar_t)(sizeof(s_mk_clib_app_crypt_arg_name_mode) / sizeof(s_mk_clib_app_crypt_arg_name_mode[0]) - 1)),
	((mk_lang_types_uchar_t)(sizeof(s_mk_clib_app_crypt_arg_name_kdf) / sizeof(s_mk_clib_app_crypt_arg_name_kdf[0]) - 1)),
	((mk_lang_types_uchar_t)(sizeof(s_mk_clib_app_crypt_arg_name_password) / sizeof(s_mk_clib_app_crypt_arg_name_password[0]) - 1)),
	((mk_lang_types_uchar_t)(sizeof(s_mk_clib_app_crypt_arg_name_salt) / sizeof(s_mk_clib_app_crypt_arg_name_salt[0]) - 1)),
	((mk_lang_types_uchar_t)(sizeof(s_mk_clib_app_crypt_arg_name_cost) / sizeof(s_mk_clib_app_crypt_arg_name_cost[0]) - 1)),
	((mk_lang_types_uchar_t)(sizeof(s_mk_clib_app_crypt_arg_name_input) / sizeof(s_mk_clib_app_crypt_arg_name_input[0]) - 1)),
	((mk_lang_types_uchar_t)(sizeof(s_mk_clib_app_crypt_arg_name_output) / sizeof(s_mk_clib_app_crypt_arg_name_output[0]) - 1)),
};

enum mk_clib_app_crypt_param_id_e
{
	mk_clib_app_crypt_param_id_e_dir,
	mk_clib_app_crypt_param_id_e_alg,
	mk_clib_app_crypt_param_id_e_padding,
	mk_clib_app_crypt_param_id_e_mode,
	mk_clib_app_crypt_param_id_e_kdf,
	mk_clib_app_crypt_param_id_e_password,
	mk_clib_app_crypt_param_id_e_salt,
	mk_clib_app_crypt_param_id_e_cost,
	mk_clib_app_crypt_param_id_e_input,
	mk_clib_app_crypt_param_id_e_output,
	mk_clib_app_crypt_param_id_e_dummy_end
};
typedef enum mk_clib_app_crypt_param_id_e mk_clib_app_crypt_param_id_t;

union mk_clib_app_crypt_aligned_buff_u
{
	mk_lang_types_uchar_t m_uchars[4 * 1024];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_clib_app_crypt_aligned_buff_u mk_clib_app_crypt_aligned_buff_t;

struct mk_clib_app_crypt_buff_s
{
	mk_clib_app_crypt_aligned_buff_t m_data;
};
typedef struct mk_clib_app_crypt_buff_s mk_clib_app_crypt_buff_t;
typedef mk_clib_app_crypt_buff_t* mk_clib_app_crypt_buff_pt;


#if defined NDEBUG
#define mk_clib_app_crypt_check(x) if(!(x)) return 1; ((mk_lang_types_void_t)(0))
#else
#define mk_clib_app_crypt_check(x) if(!(x)) return ((mk_lang_types_sint_t)(__LINE__)); ((mk_lang_types_void_t)(0))
#endif


mk_lang_nodiscard static mk_lang_inline char const* mk_clib_app_crypt_args_get_exe_name(char const* const arg) mk_lang_noexcept
{
	char const* r;
	char const* p;

	r = arg;
	for(p = r; *p; ++p)
	{
		if(*p == '/' || *p == '\\')
		{
			r = p + 1;
		}
	}
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_cui_uint8_pct mk_clib_app_crypt_usage_strs(mk_sl_cui_uint8_pct const ptr) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p;
	int s;
	int n;
	int i;
	int m;

	mk_lang_assert(ptr);

	p = ptr;
	s = 0;
	mk_sl_cui_uint8_to_bi_sint(&p[0], &n); p += 1;
	p += n;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_sint(&p[i], &m);
		printf("%.*s ", m, ((mk_lang_types_pchar_pct)(p + n + s)));
		s += m;
	}
	p += n + s;
	s = 0;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_sint(&p[i], &m);
		s += m;
	}
	p += n + s;
	return p;
}

mk_lang_nodiscard static mk_lang_inline int mk_clib_app_crypt_usage(int const argc, char const* const* const argv) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data;
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_ssize_t r;

	((void)(argc));
	mk_lang_assert(argv);
	mk_lang_assert(argv[0]);

	printf("Example usage:\n\n");
	printf("%s /direction encrypt /alg aes_128 /padding pkcs7 /mode cbc /kdf pbkdf2_sha2_512_256 /password Hunter2 /salt cryptor /cost 1000 /input secret.txt /output secret.dat\n\n", mk_clib_app_crypt_args_get_exe_name(argv[0]));
	printf("%s /direction decrypt /alg aes_128 /padding pkcs7 /mode cbc /kdf pbkdf2_sha2_512_256 /password Hunter2 /salt cryptor /cost 1000 /input secret.dat /output secret.txt\n\n", mk_clib_app_crypt_args_get_exe_name(argv[0]));
	data = mk_lib_crypto_gapp_get_data_addr(); mk_clib_app_crypt_check(data);
	r = mk_lib_crypto_gapp_get_names(); mk_clib_app_crypt_check(r >= 1 && r <= 4 * 1024);
	ptr = data;
	printf("Possible values:\n\n");
	ptr = mk_clib_app_crypt_usage_strs(ptr); mk_clib_app_crypt_check(ptr); printf("\n"); printf("\n");
	ptr = mk_clib_app_crypt_usage_strs(ptr); mk_clib_app_crypt_check(ptr); printf("\n"); printf("\n");
	ptr = mk_clib_app_crypt_usage_strs(ptr); mk_clib_app_crypt_check(ptr); printf("\n"); printf("\n");
	ptr = mk_clib_app_crypt_usage_strs(ptr); mk_clib_app_crypt_check(ptr); printf("\n"); printf("\n");
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_clib_app_crypt_strlen(char const* const str) mk_lang_noexcept
{
	mk_lang_types_pchar_pct p;
	mk_lang_types_usize_t len;

	mk_lang_assert(str);

	p = str;
	while(*p)
	{
		++p;
	}
	len = ((mk_lang_types_usize_t)(p - str));
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_cui_uint8_pt mk_clib_app_crypt_append_cod(mk_sl_cui_uint8_pt const ptr, mk_lang_types_pchar_pct const str) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt p;
	mk_lang_types_usize_t len;
	int n;
	int i;

	mk_lang_assert(ptr);
	mk_lang_assert(str);

	p = ptr;
	len = mk_clib_app_crypt_strlen(str); if(!(len >= 0x01 && len <= 0xff)) return mk_lang_null;
	mk_sl_cui_uint8_from_bi_usize(&p[0], &len); p += 1;
	n = ((int)(len));
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&p[i], &str[i]);
	}
	p += n;
	return p;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_cui_uint8_pt mk_clib_app_crypt_append_u32(mk_sl_cui_uint8_pt const ptr, mk_sl_cui_uint32_pct const u32) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt p;

	mk_lang_assert(ptr);
	mk_lang_assert(u32);

	p = ptr;
	mk_sl_uint_32_to_8_le(u32, &p[0]); p += 32 / 8;
	return p;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_cui_uint8_pt mk_clib_app_crypt_append_str(mk_sl_cui_uint8_pt const ptr, mk_lang_types_pchar_pct const str) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt p;
	mk_lang_types_usize_t len;
	mk_sl_cui_uint32_t u32;
	int n;
	int i;

	mk_lang_assert(ptr);
	mk_lang_assert(str);

	p = ptr;
	len = mk_clib_app_crypt_strlen(str); if(!(len >= 0 && len <= 4 * 1024)) return mk_lang_null;
	mk_sl_cui_uint32_from_bi_usize(&u32, &len);
	p = mk_clib_app_crypt_append_u32(p, &u32); if(!p) return mk_lang_null;
	n = ((int)(len));
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&p[i], &str[i]);
	}
	p += n;
	return p;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_cui_uint8_pt mk_clib_app_crypt_append_rnd(mk_sl_cui_uint8_pt const ptr, mk_lang_types_ssize_t const iv_len, mk_sl_cui_uint8_pct* const iv, mk_lang_types_bool_t const direction, mk_lang_types_uchar_pct const ivread) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt p;
	time_t t;
	int n;
	int i;
	int r;

	mk_lang_assert(ptr);
	mk_lang_assert(iv_len >= 0x00 && iv_len <= 0xff);
	mk_lang_assert(iv);
	mk_lang_assert(ivread);

	p = ptr;
	if(direction)
	{
		*iv = p;
		t = time(mk_lang_null); if(t == ((time_t)(-1))) return mk_lang_null;
		srand(((unsigned)(t)));
		n = ((int)(iv_len));
		for(i = 0; i != n; ++i)
		{
			r = rand();
			r &= 0xff;
			mk_sl_cui_uint8_from_bi_sint(&p[i], &r);
		}
		p += n;
	}
	else
	{
		*iv = p;
		n = ((int)(iv_len));
		for(i = 0; i != n; ++i)
		{
			mk_sl_cui_uint8_from_bi_uchar(&p[i], &ivread[i]);
		}
		p += n;
	}
	return p;
}

mk_lang_nodiscard static mk_lang_inline int mk_clib_app_crypt_work(int const argc, char const* const* const argv) mk_lang_noexcept
{
	int c;
	char const* const* v;
	int n;
	int i;
	mk_lang_types_pchar_pct params[((int)(mk_clib_app_crypt_param_id_e_dummy_end))];
	int m;
	int j;
	mk_lang_types_pchar_pct dir_str;
	mk_lang_types_usize_t dir_str_len;
	mk_lang_types_bool_t direction_found;
	mk_lang_types_bool_t direction;
	mk_lang_types_pchar_pct cost_str;
	mk_lang_types_usize_t cost_str_len;
	mk_sl_cui_uint32_t cost_32;
	mk_sl_cui_uint8_pt data;
	mk_lang_types_ssize_t iv_len_max;
	mk_sl_cui_uint8_pt ptr;
	mk_sl_cui_uint8_pct iv;
	mk_lang_types_ssize_t r;
	int iv_len;
	FILE* inputf;
	FILE* outputf;
	mk_lang_types_usize_t read;
	mk_lang_types_usize_t written;
	int block_len;
	mk_lang_types_usize_t read_a;
	mk_lang_types_usize_t read_b;
	mk_clib_app_crypt_buff_t buff_a;
	mk_clib_app_crypt_buff_t buff_b;
	mk_lang_types_usize_pt read_pa;
	mk_lang_types_usize_pt read_pb;
	mk_lang_types_usize_pt read_pc;
	mk_clib_app_crypt_buff_pt buff_pa;
	mk_clib_app_crypt_buff_pt buff_pb;
	mk_clib_app_crypt_buff_pt buff_pc;
	int closed;

	mk_lang_static_assert(sizeof(s_mk_clib_app_crypt_arg_names) / sizeof(s_mk_clib_app_crypt_arg_names[0]) == sizeof(s_mk_clib_app_crypt_arg_namelens) / sizeof(s_mk_clib_app_crypt_arg_namelens[0]));

	c = argc;
	v = argv;
	mk_lang_cpuid_init();
	mk_clib_app_crypt_check(c >= 1 + ((int)(mk_clib_app_crypt_param_id_e_dummy_end)) * 2);
	c -= 1;
	v += 1;
	n = ((int)(mk_clib_app_crypt_param_id_e_dummy_end));
	for(i = 0; i != n; ++i)
	{
		params[i] = mk_lang_null;
	}
	while(c != 0)
	{
		mk_clib_app_crypt_check(c >= 2);
		n = ((int)(sizeof(s_mk_clib_app_crypt_arg_names) / sizeof(s_mk_clib_app_crypt_arg_names[0])));
		for(i = 0; i != n; ++i)
		{
			m = s_mk_clib_app_crypt_arg_namelens[i];
			for(j = 0; j != m; ++j)
			{
				if((v[0][j] == '\0') || ((j != 0 && v[0][j] != s_mk_clib_app_crypt_arg_names[i][j]) || (j == 0 && v[0][j] != '-' && v[0][j] != '/')))
				{
					break;
				}
			}
			if(!v[0][j] && j == m)
			{
				break;
			}
		}
		mk_clib_app_crypt_check(i != n);
		mk_lang_assert(i >= 0 && i < n);
		params[i] = v[1];
		c -= 2;
		v += 2;
	}
	for(i = 0; i != n; ++i)
	{
		mk_clib_app_crypt_check(params[i]);
	}
	dir_str = params[mk_clib_app_crypt_param_id_e_dir];
	dir_str_len = mk_clib_app_crypt_strlen(dir_str);
	direction_found = mk_lang_false;
	if(!direction_found && dir_str_len == sizeof(s_mk_clib_app_crypt_arg_name_dir_enc) / sizeof(s_mk_clib_app_crypt_arg_name_dir_enc[0]) - 1){ n = ((int)(dir_str_len)); for(i = 0; i != n; ++i){ if(dir_str[i] != s_mk_clib_app_crypt_arg_name_dir_enc[i]){ break; } } if(i == n){ direction_found = mk_lang_true; direction = mk_lang_true; } }
	if(!direction_found && dir_str_len == sizeof(s_mk_clib_app_crypt_arg_name_dir_dec) / sizeof(s_mk_clib_app_crypt_arg_name_dir_dec[0]) - 1){ n = ((int)(dir_str_len)); for(i = 0; i != n; ++i){ if(dir_str[i] != s_mk_clib_app_crypt_arg_name_dir_dec[i]){ break; } } if(i == n){ direction_found = mk_lang_true; direction = mk_lang_false; } }
	mk_clib_app_crypt_check(direction_found);
	cost_str = params[mk_clib_app_crypt_param_id_e_cost];
	cost_str_len = mk_clib_app_crypt_strlen(cost_str);
	mk_clib_app_crypt_check(cost_str_len <= mk_sl_cui_uint32_strlendec_v);
	n = mk_sl_cui_uint32_from_str_dec_n(&cost_32, cost_str, ((int)(cost_str_len))); mk_clib_app_crypt_check(n == ((int)(cost_str_len)));
	data = mk_lib_crypto_gapp_get_data_addr();
	mk_lang_assert(data);
	iv_len_max = mk_lib_crypto_gapp_get_iv_size_max(); mk_clib_app_crypt_check(iv_len_max >= 0x00 && iv_len_max <= 0xff);
	inputf = fopen(params[mk_clib_app_crypt_param_id_e_input], "rb"); mk_clib_app_crypt_check(inputf);
	if(!direction)
	{
		read = fread(&buff_a.m_data.m_uchars[0], 1, iv_len_max, inputf); mk_clib_app_crypt_check(read <= ((mk_lang_types_usize_t)(iv_len_max)));
	}
	ptr = data;
	ptr = mk_clib_app_crypt_append_cod(ptr, params[mk_clib_app_crypt_param_id_e_alg]); mk_clib_app_crypt_check(ptr);
	ptr = mk_clib_app_crypt_append_cod(ptr, params[mk_clib_app_crypt_param_id_e_padding]); mk_clib_app_crypt_check(ptr);
	ptr = mk_clib_app_crypt_append_cod(ptr, params[mk_clib_app_crypt_param_id_e_mode]); mk_clib_app_crypt_check(ptr);
	ptr = mk_clib_app_crypt_append_cod(ptr, params[mk_clib_app_crypt_param_id_e_kdf]); mk_clib_app_crypt_check(ptr);
	ptr = mk_clib_app_crypt_append_rnd(ptr, iv_len_max, &iv, direction, &buff_a.m_data.m_uchars[0]); mk_clib_app_crypt_check(ptr);
	ptr = mk_clib_app_crypt_append_u32(ptr, &cost_32); mk_clib_app_crypt_check(ptr);
	ptr = mk_clib_app_crypt_append_str(ptr, params[mk_clib_app_crypt_param_id_e_password]); mk_clib_app_crypt_check(ptr);
	ptr = mk_clib_app_crypt_append_str(ptr, params[mk_clib_app_crypt_param_id_e_salt]); mk_clib_app_crypt_check(ptr);
	r = mk_lib_crypto_gapp_init(); mk_clib_app_crypt_check(r >= 0x00 && r <= iv_len_max);
	iv_len = ((int)(r));
	if(!direction)
	{
		mk_clib_app_crypt_check(((int)(read)) >= iv_len);
		if(((int)(read)) > iv_len)
		{
			n = fseek(inputf, iv_len - ((int)(read)), SEEK_CUR); mk_clib_app_crypt_check(n == 0);
		}
	}
	outputf = fopen(params[mk_clib_app_crypt_param_id_e_output], "wb"); mk_clib_app_crypt_check(outputf);
	if(direction && iv_len != 0)
	{
		written = fwrite(iv, 1, iv_len, outputf); mk_clib_app_crypt_check(written == ((mk_lang_types_usize_t)(iv_len)));
	}
	block_len = ((int)(sizeof(buff_a.m_data.m_uchars) / sizeof(buff_a.m_data.m_uchars[0])));
	buff_pa = &buff_a;
	buff_pb = &buff_b;
	read_pa = &read_a;
	read_pb = &read_b;
	*read_pa = fread(&buff_pa->m_data.m_uchars[0], 1, block_len, inputf);
	for(;;)
	{
		*read_pb = fread(&buff_pb->m_data.m_uchars[0], 1, block_len, inputf);
		if(*read_pb != 0)
		{
			n = ((int)(*read_pa));
			mk_clib_app_crypt_check(n == block_len);
			for(i = 0; i != n; ++i){ mk_sl_cui_uint8_from_bi_uchar(&data[i], &buff_pa->m_data.m_uchars[i]); }
			if(direction)
			{
				r = mk_lib_crypto_gapp_encrypt_append(n); mk_clib_app_crypt_check(r == 0);
			}
			else
			{
				r = mk_lib_crypto_gapp_decrypt_append(n); mk_clib_app_crypt_check(r == 0);
			}
			written = fwrite(data, 1, *read_pa, outputf); mk_clib_app_crypt_check(written == ((mk_lang_types_usize_t)(n)));
			read_pc = read_pa; read_pa = read_pb; read_pb = read_pc;
			buff_pc = buff_pa; buff_pa = buff_pb; buff_pb = buff_pc;
		}
		else
		{
			n = ((int)(*read_pa));
			for(i = 0; i != n; ++i){ mk_sl_cui_uint8_from_bi_uchar(&data[i], &buff_pa->m_data.m_uchars[i]); }
			if(direction)
			{
				r = mk_lib_crypto_gapp_encrypt_finish(n); mk_clib_app_crypt_check(r >= 0x01 && r <= iv_len_max);
				written = fwrite(data, 1, n + r, outputf); mk_clib_app_crypt_check(written == ((mk_lang_types_usize_t)(n + r)));
			}
			else
			{
				r = mk_lib_crypto_gapp_decrypt_finish(n); mk_clib_app_crypt_check(r >= 0x01 && r <= iv_len_max);
				written = fwrite(data, 1, n - r, outputf); mk_clib_app_crypt_check(written == ((mk_lang_types_usize_t)(n - ((int)(r)))));
			}
			break;
		}
	}
	closed = fclose(inputf); mk_clib_app_crypt_check(closed == 0);
	closed = fclose(outputf); mk_clib_app_crypt_check(closed == 0);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo int mk_clib_app_crypt_args(int const argc, char const* const* const argv) mk_lang_noexcept
{
	if(argc == 1)
	{
		return mk_clib_app_crypt_usage(argc, argv);
	}
	else
	{
		return mk_clib_app_crypt_work(argc, argv);
	}
}


#undef check
