#ifndef mk_include_guard_mk_lib_iip_random_c
#define mk_include_guard_mk_lib_iip_random_c
#include "mk_lib_iip_random.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"

#include <stdlib.h> /* rand */


mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_random_generate_u32_any(mk_sl_cui_uint32_pt const u32) mk_lang_noexcept
{
	union mk_lib_iip_random_generate_u32_any_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_sl_cui_uint32_size_bytes_v];
		mk_sl_cui_uint32_t m_u32;
	};
	typedef union mk_lib_iip_random_generate_u32_any_data_u mk_lib_iip_random_generate_u32_any_data_t;
	struct mk_lib_iip_random_generate_u32_any_s
	{
		mk_lib_iip_random_generate_u32_any_data_t m_data;
	};
	typedef struct mk_lib_iip_random_generate_u32_any_s mk_lib_iip_random_generate_u32_any_t;

	mk_lib_iip_random_generate_u32_any_t storage;
	mk_lang_types_bool_t gud;

	mk_lang_assert(u32);

	do
	{
		storage.m_data.m_uchars[0] = ((mk_lang_types_uchar_t)(((mk_lang_types_uint_t)(rand())) & ((mk_lang_types_uint_t)(0xff))));
		storage.m_data.m_uchars[1] = ((mk_lang_types_uchar_t)(((mk_lang_types_uint_t)(rand())) & ((mk_lang_types_uint_t)(0xff))));
		storage.m_data.m_uchars[2] = ((mk_lang_types_uchar_t)(((mk_lang_types_uint_t)(rand())) & ((mk_lang_types_uint_t)(0xff))));
		storage.m_data.m_uchars[3] = ((mk_lang_types_uchar_t)(((mk_lang_types_uint_t)(rand())) & ((mk_lang_types_uint_t)(0xff))));
		mk_sl_cui_uint32_from_buis_uchar_le(u32, &storage.m_data.m_uchars[0]); /* todo ne */
		gud =
			(storage.m_data.m_uchars[0] != 0x00) &
			(storage.m_data.m_uchars[1] != 0x00) &
			(storage.m_data.m_uchars[2] != 0x00) &
			(storage.m_data.m_uchars[3] != 0x00) &
			(storage.m_data.m_uchars[0] != 0xff) &
			(storage.m_data.m_uchars[1] != 0xff) &
			(storage.m_data.m_uchars[2] != 0xff) &
			(storage.m_data.m_uchars[3] != 0xff) &
			mk_lang_true;
	}while(!gud);
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_random_generate_u32_non_zero(mk_sl_cui_uint32_pt const u32) mk_lang_noexcept
{
	mk_lang_assert(u32);

	do
	{
		mk_lib_iip_random_generate_u32_any(u32);
	}while(mk_sl_cui_uint32_is_zero(u32));
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_random_generate_u8s(mk_sl_cui_uint8_pt const u8s, mk_lang_types_sint_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_uchar_t tuc;

	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);

	n = count;
	for(i = 0; i != n; ++i)
	{
		do
		{
			tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_uint_t)(rand())) & ((mk_lang_types_uint_t)(0xff))));
		}while((tuc == 0x00) | (tuc == 0xff));
		mk_sl_cui_uint8_from_bi_uchar(&u8s[i], &tuc);
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_random_generate_uchars(mk_lang_types_uchar_pt const ucs, mk_lang_types_sint_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_uchar_t tuc;

	mk_lang_assert(ucs || count == 0);
	mk_lang_assert(count >= 0);

	n = count;
	for(i = 0; i != n; ++i)
	{
		do
		{
			tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_uint_t)(rand())) & ((mk_lang_types_uint_t)(0xff))));
		}while((tuc == 0x00) | (tuc == 0xff));
		ucs[i] = tuc;
	}
}


#endif
