#include "mk_lib_crypto_hash_block_sha3.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_uint64.h"


mk_lang_constexpr_static_inline mk_sl_cui_uint64_t const s_mk_lib_crypto_hash_block_sha3_rc_nums[24] =
{
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
};


#define round5(x) (((x) + 5) % 5)
#define get5(state, x) ((state)[round5(x)])
#define get25(state, x, y) ((state)[(round5(y) * 5) + round5(x)])


mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha3_chi(mk_lib_crypto_hash_block_sha3_state_prct const input, mk_lib_crypto_hash_block_sha3_state_prt const output) mk_lang_noexcept
{
	int y mk_lang_constexpr_init;
	int x mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;

	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(input != output);

	for(y = 0; y != 5; ++y)
	{
		for(x = 0; x != 5; ++x)
		{
			mk_sl_cui_uint64_not2(&get25(input->m_uint64s, x + 1, y), &ta);
			mk_sl_cui_uint64_and2(&ta, &get25(input->m_uint64s, x + 2, y));
			mk_sl_cui_uint64_xor3(&ta, &get25(input->m_uint64s, x, y), &get25(output->m_uint64s, x, y));
		}
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha3_theta(mk_lib_crypto_hash_block_sha3_state_prct const input, mk_lib_crypto_hash_block_sha3_state_prt const output) mk_lang_noexcept
{
	int x mk_lang_constexpr_init;
	mk_sl_cui_uint64_t c[5] mk_lang_constexpr_init;
	int y mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t d[5] mk_lang_constexpr_init;

	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(input != output);

	for(x = 0; x != 5; ++x)
	{
		get5(c, x) = get25(input->m_uint64s, x, 0);
		for(y = 1; y != 5; ++y)
		{
			mk_sl_cui_uint64_xor2(&get5(c, x), &get25(input->m_uint64s, x, y));
		}
	}
	for(x = 0; x != 5; ++x)
	{
		mk_sl_cui_uint64_rotl3(&get5(c, x + 1), 1, &ta);
		mk_sl_cui_uint64_xor3(&ta, &get5(c, x - 1), &get5(d, x));
		for(y = 0; y != 5; ++y)
		{
			mk_sl_cui_uint64_xor3(&get25(input->m_uint64s, x, y), &get5(d, x), &get25(output->m_uint64s, x, y));
		}
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha3_pi(mk_lib_crypto_hash_block_sha3_state_prct const input, mk_lib_crypto_hash_block_sha3_state_prt const output) mk_lang_noexcept
{
	int x mk_lang_constexpr_init;
	int y mk_lang_constexpr_init;
	int xx mk_lang_constexpr_init;
	int yy mk_lang_constexpr_init;

	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(input != output);

	for(x = 0; x != 5; ++x)
	{
		for(y = 0; y != 5; ++y)
		{
			xx = (0 * x + 1 * y) % 5;
			yy = (2 * x + 3 * y) % 5;
			get25(output->m_uint64s, xx, yy) = get25(input->m_uint64s, x, y);
		}
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha3_rho(mk_lib_crypto_hash_block_sha3_state_prct const input, mk_lib_crypto_hash_block_sha3_state_prt const output) mk_lang_noexcept
{
	int x mk_lang_constexpr_init;
	int y mk_lang_constexpr_init;
	int t mk_lang_constexpr_init;
	int r mk_lang_constexpr_init;
	int xx mk_lang_constexpr_init;
	int yy mk_lang_constexpr_init;

	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(input != output);

	get25(output->m_uint64s, 0, 0) = get25(input->m_uint64s, 0, 0);
	x = 1;
	y = 0;
	for(t = 0; t != 24; ++t)
	{
		r = (((t + 1) * (t + 2)) / 2) % 64;
		mk_sl_cui_uint64_rotl3(&get25(input->m_uint64s, x, y), r, &get25(output->m_uint64s, x, y));
		xx = (0 * x + 1 * y) % 5;
		yy = (2 * x + 3 * y) % 5;
		x = xx;
		y = yy;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha3_iota(mk_lib_crypto_hash_block_sha3_state_prt const state, int const rcidx) mk_lang_noexcept
{
	mk_lang_assert(state);
	mk_lang_assert(rcidx >= 0 && rcidx <= 23);

	mk_sl_cui_uint64_xor2(&get25(state->m_uint64s, 0, 0), &s_mk_lib_crypto_hash_block_sha3_rc_nums[rcidx]);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha3_rnd(mk_lib_crypto_hash_block_sha3_state_prt const state, int const rcidx) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_sha3_state_t tmp mk_lang_constexpr_init;

	mk_lang_assert(state);
	mk_lang_assert(rcidx >= 0 && rcidx <= 23);

	mk_lib_crypto_hash_block_sha3_theta(state, &tmp);
	mk_lib_crypto_hash_block_sha3_rho(&tmp, state);
	mk_lib_crypto_hash_block_sha3_pi(state, &tmp);
	mk_lib_crypto_hash_block_sha3_chi(&tmp, state);
	mk_lib_crypto_hash_block_sha3_iota(state, rcidx);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha3_p(mk_lib_crypto_hash_block_sha3_state_prt const state) mk_lang_noexcept
{
	int ir mk_lang_constexpr_init;

	mk_lang_assert(state);

	for(ir = 0; ir != 24; ++ir)
	{
		mk_lib_crypto_hash_block_sha3_rnd(state, ir);
	}
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha3_init(mk_lib_crypto_hash_block_sha3_state_prt const state) mk_lang_noexcept
{
	int y mk_lang_constexpr_init;
	int x mk_lang_constexpr_init;

	mk_lang_assert(state);

	for(y = 0; y != 5; ++y)
	{
		for(x = 0; x != 5; ++x)
		{
			mk_sl_cui_uint64_set_zero(&get25(state->m_uint64s, x, y));
		}
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha3_f(mk_lib_crypto_hash_block_sha3_state_prt const state) mk_lang_noexcept
{
	mk_lang_assert(state);

	mk_lib_crypto_hash_block_sha3_p(state);
}


#undef round5
#undef get5
#undef get25
