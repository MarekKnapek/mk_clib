#include "mk_sl_uint.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_16_to_8_le(mk_sl_cui_uint16_pct const u16, mk_sl_cui_uint8_pt const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[16 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u16);
	mk_lang_assert(u8);

	mk_sl_cui_uint16_to_buis_uchar_le(u16, bytes);
	for(i = 0; i != 16 / 8; ++i)
	{
		mk_sl_cui_uint8_from_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_16_to_8_be(mk_sl_cui_uint16_pct const u16, mk_sl_cui_uint8_pt const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[16 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u16);
	mk_lang_assert(u8);

	mk_sl_cui_uint16_to_buis_uchar_be(u16, bytes);
	for(i = 0; i != 16 / 8; ++i)
	{
		mk_sl_cui_uint8_from_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_32_to_8_le(mk_sl_cui_uint32_pct const u32, mk_sl_cui_uint8_pt const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[32 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u32);
	mk_lang_assert(u8);

	mk_sl_cui_uint32_to_buis_uchar_le(u32, bytes);
	for(i = 0; i != 32 / 8; ++i)
	{
		mk_sl_cui_uint8_from_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_32_to_8_be(mk_sl_cui_uint32_pct const u32, mk_sl_cui_uint8_pt const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[32 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u32);
	mk_lang_assert(u8);

	mk_sl_cui_uint32_to_buis_uchar_be(u32, bytes);
	for(i = 0; i != 32 / 8; ++i)
	{
		mk_sl_cui_uint8_from_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_64_to_8_le(mk_sl_cui_uint64_pct const u64, mk_sl_cui_uint8_pt const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[64 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u64);
	mk_lang_assert(u8);

	mk_sl_cui_uint64_to_buis_uchar_le(u64, bytes);
	for(i = 0; i != 64 / 8; ++i)
	{
		mk_sl_cui_uint8_from_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_64_to_8_be(mk_sl_cui_uint64_pct const u64, mk_sl_cui_uint8_pt const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[64 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u64);
	mk_lang_assert(u8);

	mk_sl_cui_uint64_to_buis_uchar_be(u64, bytes);
	for(i = 0; i != 64 / 8; ++i)
	{
		mk_sl_cui_uint8_from_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_128_to_8_le(mk_sl_cui_uint128_pct const u128, mk_sl_cui_uint8_pt const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[128 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u128);
	mk_lang_assert(u8);

	mk_sl_cui_uint128_to_buis_uchar_le(u128, bytes);
	for(i = 0; i != 128 / 8; ++i)
	{
		mk_sl_cui_uint8_from_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_128_to_8_be(mk_sl_cui_uint128_pct const u128, mk_sl_cui_uint8_pt const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[128 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u128);
	mk_lang_assert(u8);

	mk_sl_cui_uint128_to_buis_uchar_be(u128, bytes);
	for(i = 0; i != 128 / 8; ++i)
	{
		mk_sl_cui_uint8_from_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
}


mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_16_from_8_le(mk_sl_cui_uint16_pt const u16, mk_sl_cui_uint8_pct const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[16 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u16);
	mk_lang_assert(u8);

	for(i = 0; i != 16 / 8; ++i)
	{
		mk_sl_cui_uint8_to_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
	mk_sl_cui_uint16_from_buis_uchar_le(u16, bytes);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_16_from_8_be(mk_sl_cui_uint16_pt const u16, mk_sl_cui_uint8_pct const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[16 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u16);
	mk_lang_assert(u8);

	for(i = 0; i != 16 / 8; ++i)
	{
		mk_sl_cui_uint8_to_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
	mk_sl_cui_uint16_from_buis_uchar_be(u16, bytes);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_32_from_8_le(mk_sl_cui_uint32_pt const u32, mk_sl_cui_uint8_pct const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[32 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u32);
	mk_lang_assert(u8);

	for(i = 0; i != 32 / 8; ++i)
	{
		mk_sl_cui_uint8_to_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
	mk_sl_cui_uint32_from_buis_uchar_le(u32, bytes);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_32_from_8_be(mk_sl_cui_uint32_pt const u32, mk_sl_cui_uint8_pct const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[32 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u32);
	mk_lang_assert(u8);

	for(i = 0; i != 32 / 8; ++i)
	{
		mk_sl_cui_uint8_to_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
	mk_sl_cui_uint32_from_buis_uchar_be(u32, bytes);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_64_from_8_le(mk_sl_cui_uint64_pt const u64, mk_sl_cui_uint8_pct const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[64 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u64);
	mk_lang_assert(u8);

	for(i = 0; i != 64 / 8; ++i)
	{
		mk_sl_cui_uint8_to_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
	mk_sl_cui_uint64_from_buis_uchar_le(u64, bytes);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_64_from_8_be(mk_sl_cui_uint64_pt const u64, mk_sl_cui_uint8_pct const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[64 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u64);
	mk_lang_assert(u8);

	for(i = 0; i != 64 / 8; ++i)
	{
		mk_sl_cui_uint8_to_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
	mk_sl_cui_uint64_from_buis_uchar_be(u64, bytes);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_128_from_8_le(mk_sl_cui_uint128_pt const u128, mk_sl_cui_uint8_pct const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[128 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u128);
	mk_lang_assert(u8);

	for(i = 0; i != 128 / 8; ++i)
	{
		mk_sl_cui_uint8_to_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
	mk_sl_cui_uint128_from_buis_uchar_le(u128, bytes);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_128_from_8_be(mk_sl_cui_uint128_pt const u128, mk_sl_cui_uint8_pct const u8) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[128 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u128);
	mk_lang_assert(u8);

	for(i = 0; i != 128 / 8; ++i)
	{
		mk_sl_cui_uint8_to_buis_uchar_le(&u8[i], &bytes[i * 8 / 8]);
	}
	mk_sl_cui_uint128_from_buis_uchar_be(u128, bytes);
}


mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_64_to_32_le(mk_sl_cui_uint64_pct const u64, mk_sl_cui_uint32_pt const u32) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[64 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u64);
	mk_lang_assert(u32);

	mk_sl_cui_uint64_to_buis_uchar_le(u64, bytes);
	for(i = 0; i != 64 / 32; ++i)
	{
		mk_sl_cui_uint32_from_buis_uchar_le(&u32[i], &bytes[i * 32 / 8]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_64_from_32_le(mk_sl_cui_uint64_pt const u64, mk_sl_cui_uint32_pct const u32) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[64 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u64);
	mk_lang_assert(u32);

	for(i = 0; i != 64 / 32; ++i)
	{
		mk_sl_cui_uint32_to_buis_uchar_le(&u32[i], &bytes[i * 32 / 8]);
	}
	mk_sl_cui_uint64_from_buis_uchar_le(u64, bytes);
}


mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_128_to_64_le(mk_sl_cui_uint128_pct const u128, mk_sl_cui_uint64_pt const u64) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[128 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u128);
	mk_lang_assert(u64);

	mk_sl_cui_uint128_to_buis_uchar_le(u128, bytes);
	for(i = 0; i != 128 / 64; ++i)
	{
		mk_sl_cui_uint64_from_buis_uchar_le(&u64[i], &bytes[i * 64 / 8]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_128_from_64_le(mk_sl_cui_uint128_pt const u128, mk_sl_cui_uint64_pct const u64) mk_lang_noexcept
{
	mk_lang_types_uchar_t bytes[128 / 8] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(u128);
	mk_lang_assert(u64);

	for(i = 0; i != 128 / 64; ++i)
	{
		mk_sl_cui_uint64_to_buis_uchar_le(&u64[i], &bytes[i * 64 / 8]);
	}
	mk_sl_cui_uint128_from_buis_uchar_le(u128, bytes);
}
