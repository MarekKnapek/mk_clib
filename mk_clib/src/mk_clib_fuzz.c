#ifndef mk_include_guard_mk_clib_fuzz_c
#define mk_include_guard_mk_clib_fuzz_c
#include "mk_clib_fuzz.h"

#include "mk_clib_test.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include "mk_lib_crypto_any_piecewise_fuzz.h"
#include "mk_lib_crypto_hash_stream_blake2b_256_fuzz.h"
#include "mk_lib_crypto_hash_stream_blake2s_128_fuzz.h"
#include "mk_lib_crypto_hash_stream_blake2s_160_fuzz.h"
#include "mk_lib_crypto_hash_stream_blake2s_224_fuzz.h"
#include "mk_lib_crypto_hash_stream_blake2s_256_fuzz.h"
#include "mk_lib_crypto_hash_stream_md2_fuzz.h"
#include "mk_lib_crypto_hash_stream_md4_fuzz.h"
#include "mk_lib_crypto_hash_stream_md5_fuzz.h"
#include "mk_lib_crypto_hash_stream_sha1_fuzz.h"
#include "mk_lib_crypto_hash_stream_sha2_224_fuzz.h"
#include "mk_lib_crypto_hash_stream_sha2_256_fuzz.h"
#include "mk_lib_crypto_hash_stream_sha2_384_fuzz.h"
#include "mk_lib_crypto_hash_stream_sha2_512_224_fuzz.h"
#include "mk_lib_crypto_hash_stream_sha2_512_256_fuzz.h"
#include "mk_lib_crypto_hash_stream_sha2_512_fuzz.h"
#include "mk_lib_crypto_hash_stream_sha3_224_fuzz.h"
#include "mk_lib_crypto_hash_stream_sha3_256_fuzz.h"
#include "mk_lib_crypto_hash_stream_sha3_384_fuzz.h"
#include "mk_lib_crypto_hash_stream_sha3_512_fuzz.h"
#include "mk_lib_crypto_xof_stream_shake_128_fuzz.h"
#include "mk_lib_crypto_xof_stream_shake_256_fuzz.h"
#include "mk_sl_cui_fuzz.h"


static mk_lang_types_bool_t mk_clib_fuzz_g_once = mk_lang_false;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_fuzz_fn(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size, mk_lang_types_bool_t const allow_all) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t line mk_lang_constexpr_init;
	mk_lang_types_bool_t all mk_lang_constexpr_init;
	mk_lang_types_uint_t base mk_lang_constexpr_init;
	mk_lang_types_uint_t curr mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	mk_lang_assert(allow_all == mk_lang_true || allow_all == mk_lang_false);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(s >= 1)
	{
		if(d[0] % 2 == 0)
		{
			mk_lang_cpuid_init();
		}
		else
		{
			mk_lang_cpuid_reset();
		}
		d += 1;
		s -= 1;
	}
	line = 0;
	if(s >= mk_lang_bui_uint_size_bytes_v)
	{
		mk_lang_bui_uint_from_buis_uchar_le(&line, &d[0]);
		d += mk_lang_bui_uint_size_bytes_v;
		s -= mk_lang_bui_uint_size_bytes_v;
	}
	all = mk_lang_bui_uint_is_max(&line) && allow_all;
	base = __LINE__;
	curr = base + 2 + line;
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_any_piecewise_fuzz(d, s, allow_all); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_blake2b_256_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_blake2s_128_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_blake2s_160_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_blake2s_224_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_blake2s_256_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_md2_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_md4_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_md5_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_sha1_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_sha2_224_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_sha2_256_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_sha2_384_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_sha2_512_224_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_sha2_512_256_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_sha2_512_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_sha3_224_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_sha3_256_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_sha3_384_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_hash_stream_sha3_512_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_xof_stream_shake_128_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_xof_stream_shake_256_fuzz(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz(d, s, allow_all); }
	return 0;
}


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_inline mk_lang_types_sint_t mk_clib_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size, mk_lang_types_bool_t const allow_all) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	mk_lang_assert(allow_all == mk_lang_true || allow_all == mk_lang_false);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(!mk_clib_fuzz_g_once)
	{
		mk_clib_fuzz_g_once = mk_lang_true;
		mk_clib_test();
	}
	err = mk_clib_fuzz_fn(data, size, allow_all); mk_lang_check_rereturn(err);
	return 0;
}


#endif
