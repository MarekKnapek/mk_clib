#include "mk_clib_app_hash.h"

#include "mk_lang_alignas.h"
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
#include "mk_lib_crypto_hash_stream_blake2b_256.h"
#include "mk_lib_crypto_hash_stream_blake2b_384.h"
#include "mk_lib_crypto_hash_stream_blake2b_512.h"
#include "mk_lib_crypto_hash_stream_blake2s_128.h"
#include "mk_lib_crypto_hash_stream_blake2s_160.h"
#include "mk_lib_crypto_hash_stream_blake2s_224.h"
#include "mk_lib_crypto_hash_stream_blake2s_256.h"
#include "mk_lib_crypto_hash_stream_blake3.h"
#include "mk_lib_crypto_hash_stream_md2.h"
#include "mk_lib_crypto_hash_stream_md4.h"
#include "mk_lib_crypto_hash_stream_md5.h"
#include "mk_lib_crypto_hash_stream_sha0.h"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_lib_crypto_hash_stream_sha2_224.h"
#include "mk_lib_crypto_hash_stream_sha2_256.h"
#include "mk_lib_crypto_hash_stream_sha2_384.h"
#include "mk_lib_crypto_hash_stream_sha2_512.h"
#include "mk_lib_crypto_hash_stream_sha2_512_224.h"
#include "mk_lib_crypto_hash_stream_sha2_512_256.h"
#include "mk_lib_crypto_hash_stream_sha3_224.h"
#include "mk_lib_crypto_hash_stream_sha3_256.h"
#include "mk_lib_crypto_hash_stream_sha3_384.h"
#include "mk_lib_crypto_hash_stream_sha3_512.h"
#include "mk_lib_crypto_hash_stream_streebog_256.h"
#include "mk_lib_crypto_hash_stream_streebog_512.h"
#include "mk_lib_crypto_hash_stream_tiger2_128.h"
#include "mk_lib_crypto_hash_stream_tiger2_160.h"
#include "mk_lib_crypto_hash_stream_tiger2_192.h"
#include "mk_lib_crypto_hash_stream_tiger_128.h"
#include "mk_lib_crypto_hash_stream_tiger_160.h"
#include "mk_lib_crypto_hash_stream_tiger_192.h"
#include "mk_lib_crypto_hash_stream_whirlpool.h"
#include "mk_sl_uint8.h"

#include <stdio.h> /* printf FILE fopen fread fclose */


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_hash_uc[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_hash_lc[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_hash_alg_pretty_name_strs[] =
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_256_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_384_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_512_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_128_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_160_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_224_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_256_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake3_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_md2_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_md4_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_md5_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha0_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha1_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha2_224_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha2_256_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha2_384_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha2_512_224_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha2_512_256_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha2_512_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha3_224_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha3_256_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha3_384_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha3_512_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_streebog_256_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_streebog_512_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_tiger2_128_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_tiger2_160_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_tiger2_192_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_tiger_128_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_tiger_160_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_tiger_192_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_whirlpool_name_def)
;

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_clib_app_hash_alg_pretty_name_lens[] =
{
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_256_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_384_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_512_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_128_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_160_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_224_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_256_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake3_name_def      )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_md2_name_def         )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_md4_name_def         )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_md5_name_def         )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha0_name_def        )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha1_name_def        )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha2_224_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha2_256_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha2_384_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha2_512_224_name_def)) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha2_512_256_name_def)) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha2_512_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha3_224_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha3_256_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha3_384_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha3_512_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_streebog_256_name_def)) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_streebog_512_name_def)) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_tiger2_128_name_def  )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_tiger2_160_name_def  )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_tiger2_192_name_def  )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_tiger_128_name_def   )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_tiger_160_name_def   )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_tiger_192_name_def   )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_whirlpool_name_def   )) - 1)))),
};

enum mk_clib_app_hash_alg_id_e
{
	mk_clib_app_hash_alg_id_e_blake2b_256_alg ,
	mk_clib_app_hash_alg_id_e_blake2b_384_alg ,
	mk_clib_app_hash_alg_id_e_blake2b_512_alg ,
	mk_clib_app_hash_alg_id_e_blake2s_128_alg ,
	mk_clib_app_hash_alg_id_e_blake2s_160_alg ,
	mk_clib_app_hash_alg_id_e_blake2s_224_alg ,
	mk_clib_app_hash_alg_id_e_blake2s_256_alg ,
	mk_clib_app_hash_alg_id_e_blake3_alg      ,
	mk_clib_app_hash_alg_id_e_md2_alg         ,
	mk_clib_app_hash_alg_id_e_md4_alg         ,
	mk_clib_app_hash_alg_id_e_md5_alg         ,
	mk_clib_app_hash_alg_id_e_sha0_alg        ,
	mk_clib_app_hash_alg_id_e_sha1_alg        ,
	mk_clib_app_hash_alg_id_e_sha2_224_alg    ,
	mk_clib_app_hash_alg_id_e_sha2_256_alg    ,
	mk_clib_app_hash_alg_id_e_sha2_384_alg    ,
	mk_clib_app_hash_alg_id_e_sha2_512_224_alg,
	mk_clib_app_hash_alg_id_e_sha2_512_256_alg,
	mk_clib_app_hash_alg_id_e_sha2_512_alg    ,
	mk_clib_app_hash_alg_id_e_sha3_224_alg    ,
	mk_clib_app_hash_alg_id_e_sha3_256_alg    ,
	mk_clib_app_hash_alg_id_e_sha3_384_alg    ,
	mk_clib_app_hash_alg_id_e_sha3_512_alg    ,
	mk_clib_app_hash_alg_id_e_streebog_256_alg,
	mk_clib_app_hash_alg_id_e_streebog_512_alg,
	mk_clib_app_hash_alg_id_e_tiger2_128_alg  ,
	mk_clib_app_hash_alg_id_e_tiger2_160_alg  ,
	mk_clib_app_hash_alg_id_e_tiger2_192_alg  ,
	mk_clib_app_hash_alg_id_e_tiger_128_alg   ,
	mk_clib_app_hash_alg_id_e_tiger_160_alg   ,
	mk_clib_app_hash_alg_id_e_tiger_192_alg   ,
	mk_clib_app_hash_alg_id_e_whirlpool_alg   ,
	mk_clib_app_hash_alg_id_e_dummy_end
};
typedef enum mk_clib_app_hash_alg_id_e mk_clib_app_hash_alg_id_t;

union mk_clib_app_hash_hasher_u
{
	mk_lib_crypto_hash_stream_blake2b_256_t  m_blake2b_256;
	mk_lib_crypto_hash_stream_blake2b_384_t  m_blake2b_384;
	mk_lib_crypto_hash_stream_blake2b_512_t  m_blake2b_512;
	mk_lib_crypto_hash_stream_blake2s_128_t  m_blake2s_128;
	mk_lib_crypto_hash_stream_blake2s_160_t  m_blake2s_160;
	mk_lib_crypto_hash_stream_blake2s_224_t  m_blake2s_224;
	mk_lib_crypto_hash_stream_blake2s_256_t  m_blake2s_256;
	mk_lib_crypto_hash_stream_blake3_t       m_blake3;
	mk_lib_crypto_hash_stream_md2_t          m_md2;
	mk_lib_crypto_hash_stream_md4_t          m_md4;
	mk_lib_crypto_hash_stream_md5_t          m_md5;
	mk_lib_crypto_hash_stream_sha0_t         m_sha0;
	mk_lib_crypto_hash_stream_sha1_t         m_sha1;
	mk_lib_crypto_hash_stream_sha2_224_t     m_sha2_224;
	mk_lib_crypto_hash_stream_sha2_256_t     m_sha2_256;
	mk_lib_crypto_hash_stream_sha2_384_t     m_sha2_384;
	mk_lib_crypto_hash_stream_sha2_512_224_t m_sha2_512_224;
	mk_lib_crypto_hash_stream_sha2_512_256_t m_sha2_512_256;
	mk_lib_crypto_hash_stream_sha2_512_t     m_sha2_512;
	mk_lib_crypto_hash_stream_sha3_224_t     m_sha3_224;
	mk_lib_crypto_hash_stream_sha3_256_t     m_sha3_256;
	mk_lib_crypto_hash_stream_sha3_384_t     m_sha3_384;
	mk_lib_crypto_hash_stream_sha3_512_t     m_sha3_512;
	mk_lib_crypto_hash_stream_streebog_256_t m_streebog_256;
	mk_lib_crypto_hash_stream_streebog_512_t m_streebog_512;
	mk_lib_crypto_hash_stream_tiger2_128_t   m_tiger2_128;
	mk_lib_crypto_hash_stream_tiger2_160_t   m_tiger2_160;
	mk_lib_crypto_hash_stream_tiger2_192_t   m_tiger2_192;
	mk_lib_crypto_hash_stream_tiger_128_t    m_tiger_128;
	mk_lib_crypto_hash_stream_tiger_160_t    m_tiger_160;
	mk_lib_crypto_hash_stream_tiger_192_t    m_tiger_192;
	mk_lib_crypto_hash_stream_whirlpool_t    m_whirlpool;
};
typedef union mk_clib_app_hash_hasher_u mk_clib_app_hash_hasher_t;
typedef mk_clib_app_hash_hasher_t* mk_clib_app_hash_hasher_pt;

union mk_clib_app_hash_digest_u
{
	mk_lib_crypto_hash_block_blake2b_256_digest_t  m_blake2b_256;
	mk_lib_crypto_hash_block_blake2b_384_digest_t  m_blake2b_384;
	mk_lib_crypto_hash_block_blake2b_512_digest_t  m_blake2b_512;
	mk_lib_crypto_hash_block_blake2s_128_digest_t  m_blake2s_128;
	mk_lib_crypto_hash_block_blake2s_160_digest_t  m_blake2s_160;
	mk_lib_crypto_hash_block_blake2s_224_digest_t  m_blake2s_224;
	mk_lib_crypto_hash_block_blake2s_256_digest_t  m_blake2s_256;
	mk_lib_crypto_hash_block_blake3_digest_t       m_blake3;
	mk_lib_crypto_hash_block_md2_digest_t          m_md2;
	mk_lib_crypto_hash_block_md4_digest_t          m_md4;
	mk_lib_crypto_hash_block_md5_digest_t          m_md5;
	mk_lib_crypto_hash_block_sha0_digest_t         m_sha0;
	mk_lib_crypto_hash_block_sha1_digest_t         m_sha1;
	mk_lib_crypto_hash_block_sha2_224_digest_t     m_sha2_224;
	mk_lib_crypto_hash_block_sha2_256_digest_t     m_sha2_256;
	mk_lib_crypto_hash_block_sha2_384_digest_t     m_sha2_384;
	mk_lib_crypto_hash_block_sha2_512_224_digest_t m_sha2_512_224;
	mk_lib_crypto_hash_block_sha2_512_256_digest_t m_sha2_512_256;
	mk_lib_crypto_hash_block_sha2_512_digest_t     m_sha2_512;
	mk_lib_crypto_hash_block_sha3_224_digest_t     m_sha3_224;
	mk_lib_crypto_hash_block_sha3_256_digest_t     m_sha3_256;
	mk_lib_crypto_hash_block_sha3_384_digest_t     m_sha3_384;
	mk_lib_crypto_hash_block_sha3_512_digest_t     m_sha3_512;
	mk_lib_crypto_hash_block_streebog_256_digest_t m_streebog_256;
	mk_lib_crypto_hash_block_streebog_512_digest_t m_streebog_512;
	mk_lib_crypto_hash_block_tiger2_128_digest_t   m_tiger2_128;
	mk_lib_crypto_hash_block_tiger2_160_digest_t   m_tiger2_160;
	mk_lib_crypto_hash_block_tiger2_192_digest_t   m_tiger2_192;
	mk_lib_crypto_hash_block_tiger_128_digest_t    m_tiger_128;
	mk_lib_crypto_hash_block_tiger_160_digest_t    m_tiger_160;
	mk_lib_crypto_hash_block_tiger_192_digest_t    m_tiger_192;
	mk_lib_crypto_hash_block_whirlpool_digest_t    m_whirlpool;
};
typedef union mk_clib_app_hash_digest_u mk_clib_app_hash_digest_t;
typedef mk_clib_app_hash_digest_t* mk_clib_app_hash_digest_pt;

union mk_clib_app_hash_aligned_buff_u
{
	mk_lang_types_uchar_t m_uchars[4 * 1024];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_clib_app_hash_aligned_buff_u mk_clib_app_hash_aligned_buff_t;

struct mk_clib_app_hash_buff_s
{
	mk_lang_alignas(64) mk_clib_app_hash_aligned_buff_t m_data;
};
typedef struct mk_clib_app_hash_buff_s mk_clib_app_hash_buff_t;
typedef mk_clib_app_hash_buff_t* mk_clib_app_hash_buff_pt;


#if defined NDEBUG
#define mk_clib_app_hash_check(x) if(!(x)) return 1; ((mk_lang_types_void_t)(0))
#else
#define mk_clib_app_hash_check(x) if(!(x)) return ((mk_lang_types_sint_t)(__LINE__)); ((mk_lang_types_void_t)(0))
#endif
#define mk_clib_app_hash_count_of(x) ((mk_lang_types_sint_t)(sizeof(x) / sizeof((x)[0])))


mk_lang_nodiscard static mk_lang_inline mk_lang_types_pchar_pct mk_clib_app_hash_args_get_exe_name(mk_lang_types_pchar_pct const arg) mk_lang_noexcept
{
	mk_lang_types_pchar_pct r;
	mk_lang_types_pchar_pct p;

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

static mk_lang_inline mk_lang_types_void_t mk_clib_app_hash_usage_strs(mk_lang_types_pchar_pct const strs, mk_lang_types_uchar_pct const lens, mk_lang_types_sint_t const count) mk_lang_noexcept
{
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t len;

	mk_lang_assert(strs);
	mk_lang_assert(lens);
	mk_lang_assert(count >= 1);

	str = strs;
	n = count;
	for(i = 0; i != n - 1; ++i)
	{
		len = lens[i];
		printf("%.*s", len, str);
		str += len;
		printf(" ");
	}
	len = lens[i];
	printf("%.*s", len, str);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hash_usage(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pct const* const argv) mk_lang_noexcept
{
	mk_lang_types_pchar_pct exe_name;

	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(argv[0]);

	exe_name = mk_clib_app_hash_args_get_exe_name(argv[0]);
	printf("Example usage:\n");
	printf("%s SHA-1 message.txt\n", exe_name);
	printf("%s SHA3-512 video.avi\n", exe_name);
	printf("Possible values: ");
	mk_clib_app_hash_usage_strs(s_mk_clib_app_hash_alg_pretty_name_strs, s_mk_clib_app_hash_alg_pretty_name_lens, mk_clib_app_hash_alg_id_e_dummy_end); printf("\n");
	return 0;
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_hash_init(mk_clib_app_hash_hasher_pt const hasher, mk_clib_app_hash_alg_id_t const alg_id) mk_lang_noexcept
{
	mk_lang_assert(hasher);

	switch(alg_id)
	{
		case mk_clib_app_hash_alg_id_e_blake2b_256_alg:  mk_lib_crypto_hash_stream_blake2b_256_init (&hasher->m_blake2b_256 ); break;
		case mk_clib_app_hash_alg_id_e_blake2b_384_alg:  mk_lib_crypto_hash_stream_blake2b_384_init (&hasher->m_blake2b_384 ); break;
		case mk_clib_app_hash_alg_id_e_blake2b_512_alg:  mk_lib_crypto_hash_stream_blake2b_512_init (&hasher->m_blake2b_512 ); break;
		case mk_clib_app_hash_alg_id_e_blake2s_128_alg:  mk_lib_crypto_hash_stream_blake2s_128_init (&hasher->m_blake2s_128 ); break;
		case mk_clib_app_hash_alg_id_e_blake2s_160_alg:  mk_lib_crypto_hash_stream_blake2s_160_init (&hasher->m_blake2s_160 ); break;
		case mk_clib_app_hash_alg_id_e_blake2s_224_alg:  mk_lib_crypto_hash_stream_blake2s_224_init (&hasher->m_blake2s_224 ); break;
		case mk_clib_app_hash_alg_id_e_blake2s_256_alg:  mk_lib_crypto_hash_stream_blake2s_256_init (&hasher->m_blake2s_256 ); break;
		case mk_clib_app_hash_alg_id_e_blake3_alg:       mk_lib_crypto_hash_stream_blake3_init      (&hasher->m_blake3      ); break;
		case mk_clib_app_hash_alg_id_e_md2_alg:          mk_lib_crypto_hash_stream_md2_init         (&hasher->m_md2         ); break;
		case mk_clib_app_hash_alg_id_e_md4_alg:          mk_lib_crypto_hash_stream_md4_init         (&hasher->m_md4         ); break;
		case mk_clib_app_hash_alg_id_e_md5_alg:          mk_lib_crypto_hash_stream_md5_init         (&hasher->m_md5         ); break;
		case mk_clib_app_hash_alg_id_e_sha0_alg:         mk_lib_crypto_hash_stream_sha0_init        (&hasher->m_sha0        ); break;
		case mk_clib_app_hash_alg_id_e_sha1_alg:         mk_lib_crypto_hash_stream_sha1_init        (&hasher->m_sha1        ); break;
		case mk_clib_app_hash_alg_id_e_sha2_224_alg:     mk_lib_crypto_hash_stream_sha2_224_init    (&hasher->m_sha2_224    ); break;
		case mk_clib_app_hash_alg_id_e_sha2_256_alg:     mk_lib_crypto_hash_stream_sha2_256_init    (&hasher->m_sha2_256    ); break;
		case mk_clib_app_hash_alg_id_e_sha2_384_alg:     mk_lib_crypto_hash_stream_sha2_384_init    (&hasher->m_sha2_384    ); break;
		case mk_clib_app_hash_alg_id_e_sha2_512_224_alg: mk_lib_crypto_hash_stream_sha2_512_224_init(&hasher->m_sha2_512_224); break;
		case mk_clib_app_hash_alg_id_e_sha2_512_256_alg: mk_lib_crypto_hash_stream_sha2_512_256_init(&hasher->m_sha2_512_256); break;
		case mk_clib_app_hash_alg_id_e_sha2_512_alg:     mk_lib_crypto_hash_stream_sha2_512_init    (&hasher->m_sha2_512    ); break;
		case mk_clib_app_hash_alg_id_e_sha3_224_alg:     mk_lib_crypto_hash_stream_sha3_224_init    (&hasher->m_sha3_224    ); break;
		case mk_clib_app_hash_alg_id_e_sha3_256_alg:     mk_lib_crypto_hash_stream_sha3_256_init    (&hasher->m_sha3_256    ); break;
		case mk_clib_app_hash_alg_id_e_sha3_384_alg:     mk_lib_crypto_hash_stream_sha3_384_init    (&hasher->m_sha3_384    ); break;
		case mk_clib_app_hash_alg_id_e_sha3_512_alg:     mk_lib_crypto_hash_stream_sha3_512_init    (&hasher->m_sha3_512    ); break;
		case mk_clib_app_hash_alg_id_e_streebog_256_alg: mk_lib_crypto_hash_stream_streebog_256_init(&hasher->m_streebog_256); break;
		case mk_clib_app_hash_alg_id_e_streebog_512_alg: mk_lib_crypto_hash_stream_streebog_512_init(&hasher->m_streebog_512); break;
		case mk_clib_app_hash_alg_id_e_tiger2_128_alg:   mk_lib_crypto_hash_stream_tiger2_128_init  (&hasher->m_tiger2_128  ); break;
		case mk_clib_app_hash_alg_id_e_tiger2_160_alg:   mk_lib_crypto_hash_stream_tiger2_160_init  (&hasher->m_tiger2_160  ); break;
		case mk_clib_app_hash_alg_id_e_tiger2_192_alg:   mk_lib_crypto_hash_stream_tiger2_192_init  (&hasher->m_tiger2_192  ); break;
		case mk_clib_app_hash_alg_id_e_tiger_128_alg:    mk_lib_crypto_hash_stream_tiger_128_init   (&hasher->m_tiger_128   ); break;
		case mk_clib_app_hash_alg_id_e_tiger_160_alg:    mk_lib_crypto_hash_stream_tiger_160_init   (&hasher->m_tiger_160   ); break;
		case mk_clib_app_hash_alg_id_e_tiger_192_alg:    mk_lib_crypto_hash_stream_tiger_192_init   (&hasher->m_tiger_192   ); break;
		case mk_clib_app_hash_alg_id_e_whirlpool_alg:    mk_lib_crypto_hash_stream_whirlpool_init   (&hasher->m_whirlpool   ); break;
		case mk_clib_app_hash_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_hash_append(mk_clib_app_hash_hasher_pt const hasher, mk_clib_app_hash_alg_id_t const alg_id, mk_sl_cui_uint8_pct const msg, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_assert(hasher);
	mk_lang_assert(msg);
	mk_lang_assert(len >= 0);

	switch(alg_id)
	{
		case mk_clib_app_hash_alg_id_e_blake2b_256_alg:  mk_lib_crypto_hash_stream_blake2b_256_append_u8 (&hasher->m_blake2b_256,  msg, len); break;
		case mk_clib_app_hash_alg_id_e_blake2b_384_alg:  mk_lib_crypto_hash_stream_blake2b_384_append_u8 (&hasher->m_blake2b_384,  msg, len); break;
		case mk_clib_app_hash_alg_id_e_blake2b_512_alg:  mk_lib_crypto_hash_stream_blake2b_512_append_u8 (&hasher->m_blake2b_512,  msg, len); break;
		case mk_clib_app_hash_alg_id_e_blake2s_128_alg:  mk_lib_crypto_hash_stream_blake2s_128_append_u8 (&hasher->m_blake2s_128,  msg, len); break;
		case mk_clib_app_hash_alg_id_e_blake2s_160_alg:  mk_lib_crypto_hash_stream_blake2s_160_append_u8 (&hasher->m_blake2s_160,  msg, len); break;
		case mk_clib_app_hash_alg_id_e_blake2s_224_alg:  mk_lib_crypto_hash_stream_blake2s_224_append_u8 (&hasher->m_blake2s_224,  msg, len); break;
		case mk_clib_app_hash_alg_id_e_blake2s_256_alg:  mk_lib_crypto_hash_stream_blake2s_256_append_u8 (&hasher->m_blake2s_256,  msg, len); break;
		case mk_clib_app_hash_alg_id_e_blake3_alg:       mk_lib_crypto_hash_stream_blake3_append_u8      (&hasher->m_blake3,       msg, len); break;
		case mk_clib_app_hash_alg_id_e_md2_alg:          mk_lib_crypto_hash_stream_md2_append_u8         (&hasher->m_md2,          msg, len); break;
		case mk_clib_app_hash_alg_id_e_md4_alg:          mk_lib_crypto_hash_stream_md4_append_u8         (&hasher->m_md4,          msg, len); break;
		case mk_clib_app_hash_alg_id_e_md5_alg:          mk_lib_crypto_hash_stream_md5_append_u8         (&hasher->m_md5,          msg, len); break;
		case mk_clib_app_hash_alg_id_e_sha0_alg:         mk_lib_crypto_hash_stream_sha0_append_u8        (&hasher->m_sha0,         msg, len); break;
		case mk_clib_app_hash_alg_id_e_sha1_alg:         mk_lib_crypto_hash_stream_sha1_append_u8        (&hasher->m_sha1,         msg, len); break;
		case mk_clib_app_hash_alg_id_e_sha2_224_alg:     mk_lib_crypto_hash_stream_sha2_224_append_u8    (&hasher->m_sha2_224,     msg, len); break;
		case mk_clib_app_hash_alg_id_e_sha2_256_alg:     mk_lib_crypto_hash_stream_sha2_256_append_u8    (&hasher->m_sha2_256,     msg, len); break;
		case mk_clib_app_hash_alg_id_e_sha2_384_alg:     mk_lib_crypto_hash_stream_sha2_384_append_u8    (&hasher->m_sha2_384,     msg, len); break;
		case mk_clib_app_hash_alg_id_e_sha2_512_224_alg: mk_lib_crypto_hash_stream_sha2_512_224_append_u8(&hasher->m_sha2_512_224, msg, len); break;
		case mk_clib_app_hash_alg_id_e_sha2_512_256_alg: mk_lib_crypto_hash_stream_sha2_512_256_append_u8(&hasher->m_sha2_512_256, msg, len); break;
		case mk_clib_app_hash_alg_id_e_sha2_512_alg:     mk_lib_crypto_hash_stream_sha2_512_append_u8    (&hasher->m_sha2_512,     msg, len); break;
		case mk_clib_app_hash_alg_id_e_sha3_224_alg:     mk_lib_crypto_hash_stream_sha3_224_append_u8    (&hasher->m_sha3_224,     msg, len); break;
		case mk_clib_app_hash_alg_id_e_sha3_256_alg:     mk_lib_crypto_hash_stream_sha3_256_append_u8    (&hasher->m_sha3_256,     msg, len); break;
		case mk_clib_app_hash_alg_id_e_sha3_384_alg:     mk_lib_crypto_hash_stream_sha3_384_append_u8    (&hasher->m_sha3_384,     msg, len); break;
		case mk_clib_app_hash_alg_id_e_sha3_512_alg:     mk_lib_crypto_hash_stream_sha3_512_append_u8    (&hasher->m_sha3_512,     msg, len); break;
		case mk_clib_app_hash_alg_id_e_streebog_256_alg: mk_lib_crypto_hash_stream_streebog_256_append_u8(&hasher->m_streebog_256, msg, len); break;
		case mk_clib_app_hash_alg_id_e_streebog_512_alg: mk_lib_crypto_hash_stream_streebog_512_append_u8(&hasher->m_streebog_512, msg, len); break;
		case mk_clib_app_hash_alg_id_e_tiger2_128_alg:   mk_lib_crypto_hash_stream_tiger2_128_append_u8  (&hasher->m_tiger2_128,   msg, len); break;
		case mk_clib_app_hash_alg_id_e_tiger2_160_alg:   mk_lib_crypto_hash_stream_tiger2_160_append_u8  (&hasher->m_tiger2_160,   msg, len); break;
		case mk_clib_app_hash_alg_id_e_tiger2_192_alg:   mk_lib_crypto_hash_stream_tiger2_192_append_u8  (&hasher->m_tiger2_192,   msg, len); break;
		case mk_clib_app_hash_alg_id_e_tiger_128_alg:    mk_lib_crypto_hash_stream_tiger_128_append_u8   (&hasher->m_tiger_128,    msg, len); break;
		case mk_clib_app_hash_alg_id_e_tiger_160_alg:    mk_lib_crypto_hash_stream_tiger_160_append_u8   (&hasher->m_tiger_160,    msg, len); break;
		case mk_clib_app_hash_alg_id_e_tiger_192_alg:    mk_lib_crypto_hash_stream_tiger_192_append_u8   (&hasher->m_tiger_192,    msg, len); break;
		case mk_clib_app_hash_alg_id_e_whirlpool_alg:    mk_lib_crypto_hash_stream_whirlpool_append_u8   (&hasher->m_whirlpool,    msg, len); break;
		case mk_clib_app_hash_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_hash_finish(mk_clib_app_hash_hasher_pt const hasher, mk_clib_app_hash_alg_id_t const alg_id, mk_clib_app_hash_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(hasher);
	mk_lang_assert(digest);

	switch(alg_id)
	{
		case mk_clib_app_hash_alg_id_e_blake2b_256_alg:  mk_lib_crypto_hash_stream_blake2b_256_finish (&hasher->m_blake2b_256,	&digest->m_blake2b_256 ); break;
		case mk_clib_app_hash_alg_id_e_blake2b_384_alg:  mk_lib_crypto_hash_stream_blake2b_384_finish (&hasher->m_blake2b_384,  &digest->m_blake2b_384 ); break;
		case mk_clib_app_hash_alg_id_e_blake2b_512_alg:  mk_lib_crypto_hash_stream_blake2b_512_finish (&hasher->m_blake2b_512,  &digest->m_blake2b_512 ); break;
		case mk_clib_app_hash_alg_id_e_blake2s_128_alg:  mk_lib_crypto_hash_stream_blake2s_128_finish (&hasher->m_blake2s_128,  &digest->m_blake2s_128 ); break;
		case mk_clib_app_hash_alg_id_e_blake2s_160_alg:  mk_lib_crypto_hash_stream_blake2s_160_finish (&hasher->m_blake2s_160,  &digest->m_blake2s_160 ); break;
		case mk_clib_app_hash_alg_id_e_blake2s_224_alg:  mk_lib_crypto_hash_stream_blake2s_224_finish (&hasher->m_blake2s_224,  &digest->m_blake2s_224 ); break;
		case mk_clib_app_hash_alg_id_e_blake2s_256_alg:  mk_lib_crypto_hash_stream_blake2s_256_finish (&hasher->m_blake2s_256,  &digest->m_blake2s_256 ); break;
		case mk_clib_app_hash_alg_id_e_blake3_alg:       mk_lib_crypto_hash_stream_blake3_finish      (&hasher->m_blake3,       &digest->m_blake3      ); break;
		case mk_clib_app_hash_alg_id_e_md2_alg:          mk_lib_crypto_hash_stream_md2_finish         (&hasher->m_md2,          &digest->m_md2         ); break;
		case mk_clib_app_hash_alg_id_e_md4_alg:          mk_lib_crypto_hash_stream_md4_finish         (&hasher->m_md4,          &digest->m_md4         ); break;
		case mk_clib_app_hash_alg_id_e_md5_alg:          mk_lib_crypto_hash_stream_md5_finish         (&hasher->m_md5,          &digest->m_md5         ); break;
		case mk_clib_app_hash_alg_id_e_sha0_alg:         mk_lib_crypto_hash_stream_sha0_finish        (&hasher->m_sha0,         &digest->m_sha0        ); break;
		case mk_clib_app_hash_alg_id_e_sha1_alg:         mk_lib_crypto_hash_stream_sha1_finish        (&hasher->m_sha1,         &digest->m_sha1        ); break;
		case mk_clib_app_hash_alg_id_e_sha2_224_alg:     mk_lib_crypto_hash_stream_sha2_224_finish    (&hasher->m_sha2_224,     &digest->m_sha2_224    ); break;
		case mk_clib_app_hash_alg_id_e_sha2_256_alg:     mk_lib_crypto_hash_stream_sha2_256_finish    (&hasher->m_sha2_256,     &digest->m_sha2_256    ); break;
		case mk_clib_app_hash_alg_id_e_sha2_384_alg:     mk_lib_crypto_hash_stream_sha2_384_finish    (&hasher->m_sha2_384,     &digest->m_sha2_384    ); break;
		case mk_clib_app_hash_alg_id_e_sha2_512_224_alg: mk_lib_crypto_hash_stream_sha2_512_224_finish(&hasher->m_sha2_512_224, &digest->m_sha2_512_224); break;
		case mk_clib_app_hash_alg_id_e_sha2_512_256_alg: mk_lib_crypto_hash_stream_sha2_512_256_finish(&hasher->m_sha2_512_256, &digest->m_sha2_512_256); break;
		case mk_clib_app_hash_alg_id_e_sha2_512_alg:     mk_lib_crypto_hash_stream_sha2_512_finish    (&hasher->m_sha2_512,     &digest->m_sha2_512    ); break;
		case mk_clib_app_hash_alg_id_e_sha3_224_alg:     mk_lib_crypto_hash_stream_sha3_224_finish    (&hasher->m_sha3_224,     &digest->m_sha3_224    ); break;
		case mk_clib_app_hash_alg_id_e_sha3_256_alg:     mk_lib_crypto_hash_stream_sha3_256_finish    (&hasher->m_sha3_256,     &digest->m_sha3_256    ); break;
		case mk_clib_app_hash_alg_id_e_sha3_384_alg:     mk_lib_crypto_hash_stream_sha3_384_finish    (&hasher->m_sha3_384,     &digest->m_sha3_384    ); break;
		case mk_clib_app_hash_alg_id_e_sha3_512_alg:     mk_lib_crypto_hash_stream_sha3_512_finish    (&hasher->m_sha3_512,     &digest->m_sha3_512    ); break;
		case mk_clib_app_hash_alg_id_e_streebog_256_alg: mk_lib_crypto_hash_stream_streebog_256_finish(&hasher->m_streebog_256, &digest->m_streebog_256); break;
		case mk_clib_app_hash_alg_id_e_streebog_512_alg: mk_lib_crypto_hash_stream_streebog_512_finish(&hasher->m_streebog_512, &digest->m_streebog_512); break;
		case mk_clib_app_hash_alg_id_e_tiger2_128_alg:   mk_lib_crypto_hash_stream_tiger2_128_finish  (&hasher->m_tiger2_128,   &digest->m_tiger2_128  ); break;
		case mk_clib_app_hash_alg_id_e_tiger2_160_alg:   mk_lib_crypto_hash_stream_tiger2_160_finish  (&hasher->m_tiger2_160,   &digest->m_tiger2_160  ); break;
		case mk_clib_app_hash_alg_id_e_tiger2_192_alg:   mk_lib_crypto_hash_stream_tiger2_192_finish  (&hasher->m_tiger2_192,   &digest->m_tiger2_192  ); break;
		case mk_clib_app_hash_alg_id_e_tiger_128_alg:    mk_lib_crypto_hash_stream_tiger_128_finish   (&hasher->m_tiger_128,    &digest->m_tiger_128   ); break;
		case mk_clib_app_hash_alg_id_e_tiger_160_alg:    mk_lib_crypto_hash_stream_tiger_160_finish   (&hasher->m_tiger_160,    &digest->m_tiger_160   ); break;
		case mk_clib_app_hash_alg_id_e_tiger_192_alg:    mk_lib_crypto_hash_stream_tiger_192_finish   (&hasher->m_tiger_192,    &digest->m_tiger_192   ); break;
		case mk_clib_app_hash_alg_id_e_whirlpool_alg:    mk_lib_crypto_hash_stream_whirlpool_finish   (&hasher->m_whirlpool,    &digest->m_whirlpool   ); break;
		case mk_clib_app_hash_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_hash_print(mk_clib_app_hash_digest_pt const digest, mk_clib_app_hash_alg_id_t const alg_id) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_sl_cui_uint8_pct u8s;
	mk_lang_types_sint_t i;
	mk_lang_types_uchar_t tuc;
	mk_lang_types_pchar_t str[64 * 2 + 1];

	mk_lang_assert(digest);

	n = 0;
	u8s = mk_lang_null;
	switch(alg_id)
	{
		case mk_clib_app_hash_alg_id_e_blake2b_256_alg:  n = mk_lib_crypto_hash_block_blake2b_256_digest_len;  u8s = digest->m_blake2b_256.m_uint8s;  break;
		case mk_clib_app_hash_alg_id_e_blake2b_384_alg:  n = mk_lib_crypto_hash_block_blake2b_384_digest_len;  u8s = digest->m_blake2b_384.m_uint8s;  break;
		case mk_clib_app_hash_alg_id_e_blake2b_512_alg:  n = mk_lib_crypto_hash_block_blake2b_512_digest_len;  u8s = digest->m_blake2b_512.m_uint8s;  break;
		case mk_clib_app_hash_alg_id_e_blake2s_128_alg:  n = mk_lib_crypto_hash_block_blake2s_128_digest_len;  u8s = digest->m_blake2s_128.m_uint8s;  break;
		case mk_clib_app_hash_alg_id_e_blake2s_160_alg:  n = mk_lib_crypto_hash_block_blake2s_160_digest_len;  u8s = digest->m_blake2s_160.m_uint8s;  break;
		case mk_clib_app_hash_alg_id_e_blake2s_224_alg:  n = mk_lib_crypto_hash_block_blake2s_224_digest_len;  u8s = digest->m_blake2s_224.m_uint8s;  break;
		case mk_clib_app_hash_alg_id_e_blake2s_256_alg:  n = mk_lib_crypto_hash_block_blake2s_256_digest_len;  u8s = digest->m_blake2s_256.m_uint8s;  break;
		case mk_clib_app_hash_alg_id_e_blake3_alg:       n = mk_lib_crypto_hash_block_blake3_digest_len;       u8s = digest->m_blake3.m_uint8s;       break;
		case mk_clib_app_hash_alg_id_e_md2_alg:          n = mk_lib_crypto_hash_block_md2_digest_len;          u8s = digest->m_md2.m_uint8s;          break;
		case mk_clib_app_hash_alg_id_e_md4_alg:          n = mk_lib_crypto_hash_block_md4_digest_len;          u8s = digest->m_md4.m_uint8s;          break;
		case mk_clib_app_hash_alg_id_e_md5_alg:          n = mk_lib_crypto_hash_block_md5_digest_len;          u8s = digest->m_md5.m_uint8s;          break;
		case mk_clib_app_hash_alg_id_e_sha0_alg:         n = mk_lib_crypto_hash_block_sha0_digest_len;         u8s = digest->m_sha0.m_uint8s;         break;
		case mk_clib_app_hash_alg_id_e_sha1_alg:         n = mk_lib_crypto_hash_block_sha1_digest_len;         u8s = digest->m_sha1.m_uint8s;         break;
		case mk_clib_app_hash_alg_id_e_sha2_224_alg:     n = mk_lib_crypto_hash_block_sha2_224_digest_len;     u8s = digest->m_sha2_224.m_uint8s;     break;
		case mk_clib_app_hash_alg_id_e_sha2_256_alg:     n = mk_lib_crypto_hash_block_sha2_256_digest_len;     u8s = digest->m_sha2_256.m_uint8s;     break;
		case mk_clib_app_hash_alg_id_e_sha2_384_alg:     n = mk_lib_crypto_hash_block_sha2_384_digest_len;     u8s = digest->m_sha2_384.m_uint8s;     break;
		case mk_clib_app_hash_alg_id_e_sha2_512_224_alg: n = mk_lib_crypto_hash_block_sha2_512_224_digest_len; u8s = digest->m_sha2_512_224.m_uint8s; break;
		case mk_clib_app_hash_alg_id_e_sha2_512_256_alg: n = mk_lib_crypto_hash_block_sha2_512_256_digest_len; u8s = digest->m_sha2_512_256.m_uint8s; break;
		case mk_clib_app_hash_alg_id_e_sha2_512_alg:     n = mk_lib_crypto_hash_block_sha2_512_digest_len;     u8s = digest->m_sha2_512.m_uint8s;     break;
		case mk_clib_app_hash_alg_id_e_sha3_224_alg:     n = mk_lib_crypto_hash_block_sha3_224_digest_len;     u8s = digest->m_sha3_224.m_uint8s;     break;
		case mk_clib_app_hash_alg_id_e_sha3_256_alg:     n = mk_lib_crypto_hash_block_sha3_256_digest_len;     u8s = digest->m_sha3_256.m_uint8s;     break;
		case mk_clib_app_hash_alg_id_e_sha3_384_alg:     n = mk_lib_crypto_hash_block_sha3_384_digest_len;     u8s = digest->m_sha3_384.m_uint8s;     break;
		case mk_clib_app_hash_alg_id_e_sha3_512_alg:     n = mk_lib_crypto_hash_block_sha3_512_digest_len;     u8s = digest->m_sha3_512.m_uint8s;     break;
		case mk_clib_app_hash_alg_id_e_streebog_256_alg: n = mk_lib_crypto_hash_block_streebog_256_digest_len; u8s = digest->m_streebog_256.m_uint8s; break;
		case mk_clib_app_hash_alg_id_e_streebog_512_alg: n = mk_lib_crypto_hash_block_streebog_512_digest_len; u8s = digest->m_streebog_512.m_uint8s; break;
		case mk_clib_app_hash_alg_id_e_tiger2_128_alg:   n = mk_lib_crypto_hash_block_tiger2_128_digest_len;   u8s = digest->m_tiger2_128.m_uint8s;   break;
		case mk_clib_app_hash_alg_id_e_tiger2_160_alg:   n = mk_lib_crypto_hash_block_tiger2_160_digest_len;   u8s = digest->m_tiger2_160.m_uint8s;   break;
		case mk_clib_app_hash_alg_id_e_tiger2_192_alg:   n = mk_lib_crypto_hash_block_tiger2_192_digest_len;   u8s = digest->m_tiger2_192.m_uint8s;   break;
		case mk_clib_app_hash_alg_id_e_tiger_128_alg:    n = mk_lib_crypto_hash_block_tiger_128_digest_len;    u8s = digest->m_tiger_128.m_uint8s;    break;
		case mk_clib_app_hash_alg_id_e_tiger_160_alg:    n = mk_lib_crypto_hash_block_tiger_160_digest_len;    u8s = digest->m_tiger_160.m_uint8s;    break;
		case mk_clib_app_hash_alg_id_e_tiger_192_alg:    n = mk_lib_crypto_hash_block_tiger_192_digest_len;    u8s = digest->m_tiger_192.m_uint8s;    break;
		case mk_clib_app_hash_alg_id_e_whirlpool_alg:    n = mk_lib_crypto_hash_block_whirlpool_digest_len;    u8s = digest->m_whirlpool.m_uint8s;    break;
		case mk_clib_app_hash_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_uchar(&u8s[i], &tuc);
		sprintf(&str[i * 2], "%02x", ((mk_lang_types_uint_t)(tuc)));
	}
	str[i * 2] = '\0';
	printf("%s\n", &str[0]);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_pchar_t mk_clib_app_hash_to_lower(mk_lang_types_pchar_t const pc) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_static_assert(mk_clib_app_hash_count_of(s_mk_clib_app_hash_uc) == mk_clib_app_hash_count_of(s_mk_clib_app_hash_lc));

	n = mk_clib_app_hash_count_of(s_mk_clib_app_hash_uc);
	for(i = 0; i != n; ++i)
	{
		if(pc == s_mk_clib_app_hash_uc[i])
		{
			return s_mk_clib_app_hash_lc[i];
		}
	}
	return pc;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_clib_app_hash_match(mk_lang_types_pchar_pct const a, mk_lang_types_pchar_pct const b, mk_lang_types_sint_t const c) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c >= 1);

	n = c;
	for(i = 0; i != n; ++i)
	{
		if(mk_clib_app_hash_to_lower(a[i]) != mk_clib_app_hash_to_lower(b[i]))
		{
			return mk_lang_false;
		}
	}
	return a[i] == '\0' || b[i] == '\0';
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hash_work(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pct const* const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t c;
	mk_lang_types_pchar_pct const* v;
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t len;
	mk_clib_app_hash_alg_id_t alg_id;
	mk_clib_app_hash_hasher_t hasher;
	FILE* inputf;
	mk_lang_types_usize_t read;
	mk_clib_app_hash_buff_t buff;
	mk_lang_types_sint_t closed;
	mk_clib_app_hash_digest_t digest;

	mk_lang_static_assert(mk_clib_app_hash_count_of(s_mk_clib_app_hash_alg_pretty_name_lens) == mk_clib_app_hash_alg_id_e_dummy_end);

	mk_lang_assert(argc == 3);
	mk_lang_assert(argv);
	mk_lang_assert(argv[0]);

	c = argc;
	v = argv;
	n = c;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(v[i]);
	}
	mk_lang_cpuid_init();
	str = s_mk_clib_app_hash_alg_pretty_name_strs;
	n = mk_clib_app_hash_alg_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		len = s_mk_clib_app_hash_alg_pretty_name_lens[i];
		if(mk_clib_app_hash_match(v[1], str, len))
		{
			break;
		}
		str += len;
	}
	mk_clib_app_hash_check(i != mk_clib_app_hash_alg_id_e_dummy_end);
	alg_id = ((mk_clib_app_hash_alg_id_t)(i));
	mk_clib_app_hash_init(&hasher, alg_id);
	inputf = fopen(v[2], "rb"); mk_clib_app_hash_check(inputf);
	for(;;)
	{
		read = fread(&buff.m_data.m_uchars[0], 1, mk_clib_app_hash_count_of(buff.m_data.m_uchars), inputf);
		if(read == 0)
		{
			break;
		}
		mk_clib_app_hash_append(&hasher, alg_id, ((mk_sl_cui_uint8_pct)(&buff.m_data.m_uchars[0])), ((mk_lang_types_sint_t)(read)));
	}
	closed = fclose(inputf); mk_clib_app_hash_check(closed == 0);
	mk_clib_app_hash_finish(&hasher, alg_id, &digest);
	mk_clib_app_hash_print(&digest, alg_id);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_hash_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pct const* const argv) mk_lang_noexcept
{
	if(argc == 1)
	{
		return mk_clib_app_hash_usage(argc, argv);
	}
	else
	{
		mk_clib_app_hash_check(argc == 3);
		return mk_clib_app_hash_work(argc, argv);
	}
}
