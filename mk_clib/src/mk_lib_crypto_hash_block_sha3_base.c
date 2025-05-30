#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha3_base_c
#define mk_include_guard_mk_lib_crypto_hash_block_sha3_base_c
#include "mk_lib_crypto_hash_block_sha3_base.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_sl_cui_uint64.h"


#include "mk_lang_warning_msvc_push_c4820.h"
union mk_lib_crypto_hash_block_sha3_base_table_data_u
{
	mk_sl_cui_uint64_t m_uint64s[24];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha3_base_table_data_u mk_lib_crypto_hash_block_sha3_base_table_data_t;
struct mk_lib_crypto_hash_block_sha3_base_table_s
{
	mk_lang_alignas(mk_lang_pow2_roundup(sizeof(mk_lib_crypto_hash_block_sha3_base_table_data_t))) mk_lib_crypto_hash_block_sha3_base_table_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha3_base_table_s mk_lib_crypto_hash_block_sha3_base_table_t;
#include "mk_lang_warning_msvc_pop.h"


mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_sha3_base_table_t const mk_lib_crypto_hash_block_sha3_base_k_rc_nums =
{{{
	mk_sl_cui_uint64_c(0x00000000ul, 0x00000001ul),
	mk_sl_cui_uint64_c(0x00000000ul, 0x00008082ul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x0000808aul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x80008000ul),
	mk_sl_cui_uint64_c(0x00000000ul, 0x0000808bul),
	mk_sl_cui_uint64_c(0x00000000ul, 0x80000001ul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x80008081ul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x00008009ul),
	mk_sl_cui_uint64_c(0x00000000ul, 0x0000008aul),
	mk_sl_cui_uint64_c(0x00000000ul, 0x00000088ul),
	mk_sl_cui_uint64_c(0x00000000ul, 0x80008009ul),
	mk_sl_cui_uint64_c(0x00000000ul, 0x8000000aul),
	mk_sl_cui_uint64_c(0x00000000ul, 0x8000808bul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x0000008bul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x00008089ul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x00008003ul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x00008002ul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x00000080ul),
	mk_sl_cui_uint64_c(0x00000000ul, 0x0000800aul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x8000000aul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x80008081ul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x00008080ul),
	mk_sl_cui_uint64_c(0x00000000ul, 0x80000001ul),
	mk_sl_cui_uint64_c(0x80000000ul, 0x80008008ul)
}}};


#define mk_lib_crypto_hash_block_sha3_base_round_5(x) (((x) + 5) % 5)
#define mk_lib_crypto_hash_block_sha3_base_get_5(sha3_base, x) ((sha3_base)[mk_lib_crypto_hash_block_sha3_base_round_5((x))])
#define mk_lib_crypto_hash_block_sha3_base_get_25(sha3_base, x, y) ((sha3_base)[(mk_lib_crypto_hash_block_sha3_base_round_5((y)) * 5) + mk_lib_crypto_hash_block_sha3_base_round_5((x))])


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_chi(mk_lib_crypto_hash_block_sha3_base_prct const input, mk_lib_crypto_hash_block_sha3_base_prt const output) mk_lang_noexcept
{
	mk_lang_types_sint_t y mk_lang_constexpr_init;
	mk_lang_types_sint_t x mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;

	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(input != output);

	for(y = 0; y != 5; ++y)
	{
		for(x = 0; x != 5; ++x)
		{
			mk_sl_cui_uint64_not2(&mk_lib_crypto_hash_block_sha3_base_get_25(input->m_data.m_uint64s, x + 1, y), &ta);
			mk_sl_cui_uint64_and2(&ta, &mk_lib_crypto_hash_block_sha3_base_get_25(input->m_data.m_uint64s, x + 2, y));
			mk_sl_cui_uint64_xor3(&ta, &mk_lib_crypto_hash_block_sha3_base_get_25(input->m_data.m_uint64s, x, y), &mk_lib_crypto_hash_block_sha3_base_get_25(output->m_data.m_uint64s, x, y));
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_theta(mk_lib_crypto_hash_block_sha3_base_prct const input, mk_lib_crypto_hash_block_sha3_base_prt const output) mk_lang_noexcept
{
	mk_lang_types_sint_t x mk_lang_constexpr_init;
	mk_sl_cui_uint64_t c[5] mk_lang_constexpr_init;
	mk_lang_types_sint_t y mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t d[5] mk_lang_constexpr_init;

	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(input != output);

	for(x = 0; x != 5; ++x)
	{
		mk_lib_crypto_hash_block_sha3_base_get_5(c, x) = mk_lib_crypto_hash_block_sha3_base_get_25(input->m_data.m_uint64s, x, 0);
		for(y = 1; y != 5; ++y)
		{
			mk_sl_cui_uint64_xor2(&mk_lib_crypto_hash_block_sha3_base_get_5(c, x), &mk_lib_crypto_hash_block_sha3_base_get_25(input->m_data.m_uint64s, x, y));
		}
	}
	for(x = 0; x != 5; ++x)
	{
		mk_sl_cui_uint64_rotl3(&mk_lib_crypto_hash_block_sha3_base_get_5(c, x + 1), 1, &ta);
		mk_sl_cui_uint64_xor3(&ta, &mk_lib_crypto_hash_block_sha3_base_get_5(c, x - 1), &mk_lib_crypto_hash_block_sha3_base_get_5(d, x));
		for(y = 0; y != 5; ++y)
		{
			mk_sl_cui_uint64_xor3(&mk_lib_crypto_hash_block_sha3_base_get_25(input->m_data.m_uint64s, x, y), &mk_lib_crypto_hash_block_sha3_base_get_5(d, x), &mk_lib_crypto_hash_block_sha3_base_get_25(output->m_data.m_uint64s, x, y));
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_pi(mk_lib_crypto_hash_block_sha3_base_prct const input, mk_lib_crypto_hash_block_sha3_base_prt const output) mk_lang_noexcept
{
	mk_lang_types_sint_t x mk_lang_constexpr_init;
	mk_lang_types_sint_t y mk_lang_constexpr_init;
	mk_lang_types_sint_t xx mk_lang_constexpr_init;
	mk_lang_types_sint_t yy mk_lang_constexpr_init;

	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(input != output);

	for(x = 0; x != 5; ++x)
	{
		for(y = 0; y != 5; ++y)
		{
			xx = (0 * x + 1 * y) % 5;
			yy = (2 * x + 3 * y) % 5;
			mk_lib_crypto_hash_block_sha3_base_get_25(output->m_data.m_uint64s, xx, yy) = mk_lib_crypto_hash_block_sha3_base_get_25(input->m_data.m_uint64s, x, y);
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_rho(mk_lib_crypto_hash_block_sha3_base_prct const input, mk_lib_crypto_hash_block_sha3_base_prt const output) mk_lang_noexcept
{
	mk_lang_types_sint_t x mk_lang_constexpr_init;
	mk_lang_types_sint_t y mk_lang_constexpr_init;
	mk_lang_types_sint_t t mk_lang_constexpr_init;
	mk_lang_types_sint_t r mk_lang_constexpr_init;
	mk_lang_types_sint_t xx mk_lang_constexpr_init;
	mk_lang_types_sint_t yy mk_lang_constexpr_init;

	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(input != output);

	mk_lib_crypto_hash_block_sha3_base_get_25(output->m_data.m_uint64s, 0, 0) = mk_lib_crypto_hash_block_sha3_base_get_25(input->m_data.m_uint64s, 0, 0);
	x = 1;
	y = 0;
	for(t = 0; t != 24; ++t)
	{
		r = (((t + 1) * (t + 2)) / 2) % 64;
		mk_sl_cui_uint64_rotl3(&mk_lib_crypto_hash_block_sha3_base_get_25(input->m_data.m_uint64s, x, y), r, &mk_lib_crypto_hash_block_sha3_base_get_25(output->m_data.m_uint64s, x, y));
		xx = (0 * x + 1 * y) % 5;
		yy = (2 * x + 3 * y) % 5;
		x = xx;
		y = yy;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_iota(mk_lib_crypto_hash_block_sha3_base_pt const sha3_base, mk_lang_types_sint_t const rcidx) mk_lang_noexcept
{
	mk_lang_assert(sha3_base);
	mk_lang_assert(rcidx >= 0 && rcidx <= 23);

	mk_sl_cui_uint64_xor2(&mk_lib_crypto_hash_block_sha3_base_get_25(sha3_base->m_data.m_uint64s, 0, 0), &mk_lib_crypto_hash_block_sha3_base_k_rc_nums.m_data.m_uint64s[rcidx]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_rnd_24(mk_lib_crypto_hash_block_sha3_base_pt const sha3_base, mk_lang_types_sint_t const rcidx) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_sha3_base_t tmp mk_lang_constexpr_init;

	mk_lang_assert(sha3_base);
	mk_lang_assert(rcidx >= 0 && rcidx < 24);

	mk_lib_crypto_hash_block_sha3_base_theta(sha3_base, &tmp);
	mk_lib_crypto_hash_block_sha3_base_rho(&tmp, sha3_base);
	mk_lib_crypto_hash_block_sha3_base_pi(sha3_base, &tmp);
	mk_lib_crypto_hash_block_sha3_base_chi(&tmp, sha3_base);
	mk_lib_crypto_hash_block_sha3_base_iota(sha3_base, rcidx);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_rnd_12(mk_lib_crypto_hash_block_sha3_base_pt const sha3_base, mk_lang_types_sint_t const rcidx) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_sha3_base_t tmp mk_lang_constexpr_init;

	mk_lang_assert(sha3_base);
	mk_lang_assert(rcidx >= 0 && rcidx < 12);

	mk_lib_crypto_hash_block_sha3_base_theta(sha3_base, &tmp);
	mk_lib_crypto_hash_block_sha3_base_rho(&tmp, sha3_base);
	mk_lib_crypto_hash_block_sha3_base_pi(sha3_base, &tmp);
	mk_lib_crypto_hash_block_sha3_base_chi(&tmp, sha3_base);
	mk_lib_crypto_hash_block_sha3_base_iota(sha3_base, 12 + rcidx);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_p(mk_lib_crypto_hash_block_sha3_base_pt const sha3_base) mk_lang_noexcept
{
	mk_lang_types_sint_t ir mk_lang_constexpr_init;

	mk_lang_assert(sha3_base);

	for(ir = 0; ir != 24; ++ir)
	{
		mk_lib_crypto_hash_block_sha3_base_rnd_24(sha3_base, ir);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_p_b_1600_nr_12(mk_lib_crypto_hash_block_sha3_base_pt const sha3_base) mk_lang_noexcept
{
	mk_lang_types_sint_t ir mk_lang_constexpr_init;

	mk_lang_assert(sha3_base);

	for(ir = 0; ir != 12; ++ir)
	{
		mk_lib_crypto_hash_block_sha3_base_rnd_12(sha3_base, ir);
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_init(mk_lib_crypto_hash_block_sha3_base_pt const sha3_base) mk_lang_noexcept
{
	mk_lang_assert(sha3_base);

	mk_lib_crypto_bitops_bulk_uint64_25_memclr(&sha3_base->m_data.m_uint64s[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_f(mk_lib_crypto_hash_block_sha3_base_pt const sha3_base) mk_lang_noexcept
{
	mk_lang_assert(sha3_base);

	mk_lib_crypto_hash_block_sha3_base_p(sha3_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_f_turbo(mk_lib_crypto_hash_block_sha3_base_pt const sha3_base) mk_lang_noexcept
{
	mk_lang_assert(sha3_base);

	mk_lib_crypto_hash_block_sha3_base_p_b_1600_nr_12(sha3_base);
}


#endif
