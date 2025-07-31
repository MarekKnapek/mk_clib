#ifndef mk_include_guard_mk_lib_iip_random_c
#define mk_include_guard_mk_lib_iip_random_c
#include "mk_lib_iip_random.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_random.h"
#include "mk_sl_uint_convert.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_random_generate_u16_any(mk_sl_cui_uint16_pt const u16) mk_lang_noexcept
{
	union mk_lib_iip_random_generate_u16_any_data_u
	{
		mk_sl_cui_uint8_t m_u8s[((mk_lang_types_sint_t)(mk_sl_cui_uint16_size_bytes_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint8_size_bytes_v))];
		mk_sl_cui_uint16_t m_u16;
	};
	typedef union mk_lib_iip_random_generate_u16_any_data_u mk_lib_iip_random_generate_u16_any_data_t;
	struct mk_lib_iip_random_generate_u16_any_s
	{
		mk_lib_iip_random_generate_u16_any_data_t m_data;
	};
	typedef struct mk_lib_iip_random_generate_u16_any_s mk_lib_iip_random_generate_u16_any_t;

	mk_lang_types_sint_t err;
	mk_lib_iip_random_generate_u16_any_t storage;
	mk_lang_types_bool_t gud;

	mk_lang_assert(u16);

	do
	{
		err = mk_sl_random_generate(&storage.m_data.m_u8s[0], mk_lang_countof(storage.m_data.m_u8s)); mk_lang_check_rereturn(err);
		mk_sl_uint_convert_16_8_le_to_big(u16, &storage.m_data.m_u8s[0]); /* todo ne */
		#include "mk_lang_warning_clang_push_bitwise_instead_of_logical.h"
		gud =
			(!mk_sl_cui_uint8_is_zero(&storage.m_data.m_u8s[0])) &
			(!mk_sl_cui_uint8_is_zero(&storage.m_data.m_u8s[1])) &
			(!mk_sl_cui_uint8_is_max(&storage.m_data.m_u8s[0])) &
			(!mk_sl_cui_uint8_is_max(&storage.m_data.m_u8s[1])) &
			(mk_lang_true);
		#include "mk_lang_warning_clang_pop.h"
	}while(!gud);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_random_generate_u16_non_zero(mk_sl_cui_uint16_pt const u16) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(u16);

	do
	{
		err = mk_lib_iip_random_generate_u16_any(u16); mk_lang_check_rereturn(err);
	}while(mk_sl_cui_uint16_is_zero(u16));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_random_generate_u32_any(mk_sl_cui_uint32_pt const u32) mk_lang_noexcept
{
	union mk_lib_iip_random_generate_u32_any_data_u
	{
		mk_sl_cui_uint8_t m_u8s[((mk_lang_types_sint_t)(mk_sl_cui_uint32_size_bytes_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint8_size_bytes_v))];
		mk_sl_cui_uint32_t m_u32;
	};
	typedef union mk_lib_iip_random_generate_u32_any_data_u mk_lib_iip_random_generate_u32_any_data_t;
	struct mk_lib_iip_random_generate_u32_any_s
	{
		mk_lib_iip_random_generate_u32_any_data_t m_data;
	};
	typedef struct mk_lib_iip_random_generate_u32_any_s mk_lib_iip_random_generate_u32_any_t;

	mk_lang_types_sint_t err;
	mk_lib_iip_random_generate_u32_any_t storage;
	mk_lang_types_bool_t gud;

	mk_lang_assert(u32);

	do
	{
		err = mk_sl_random_generate(&storage.m_data.m_u8s[0], mk_lang_countof(storage.m_data.m_u8s)); mk_lang_check_rereturn(err);
		mk_sl_uint_convert_32_8_le_to_big(u32, &storage.m_data.m_u8s[0]); /* todo ne */
		#include "mk_lang_warning_clang_push_bitwise_instead_of_logical.h"
		gud =
			(!mk_sl_cui_uint8_is_zero(&storage.m_data.m_u8s[0])) &
			(!mk_sl_cui_uint8_is_zero(&storage.m_data.m_u8s[1])) &
			(!mk_sl_cui_uint8_is_zero(&storage.m_data.m_u8s[2])) &
			(!mk_sl_cui_uint8_is_zero(&storage.m_data.m_u8s[3])) &
			(!mk_sl_cui_uint8_is_max(&storage.m_data.m_u8s[0])) &
			(!mk_sl_cui_uint8_is_max(&storage.m_data.m_u8s[1])) &
			(!mk_sl_cui_uint8_is_max(&storage.m_data.m_u8s[2])) &
			(!mk_sl_cui_uint8_is_max(&storage.m_data.m_u8s[3])) &
			(mk_lang_true);
		#include "mk_lang_warning_clang_pop.h"
	}while(!gud);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_random_generate_u32_non_zero(mk_sl_cui_uint32_pt const u32) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(u32);

	do
	{
		err = mk_lib_iip_random_generate_u32_any(u32); mk_lang_check_rereturn(err);
	}while(mk_sl_cui_uint32_is_zero(u32));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_random_generate_u8s(mk_sl_cui_uint8_pt const u8s, mk_lang_types_sint_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);

	err = mk_sl_random_generate(u8s, count); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_random_generate_uchars(mk_lang_types_uchar_pt const ucs, mk_lang_types_sint_t const count) mk_lang_noexcept
{
	mk_lang_types_uchar_pt dst;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t batch;
	mk_sl_cui_uint8_t tu8s[64];
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;

	mk_lang_assert(ucs || count == 0);
	mk_lang_assert(count >= 0);

	dst = ucs;
	rem = count;
	batch = mk_lang_countof(tu8s);
	n = rem / batch;
	for(i = 0; i != n; ++i)
	{
		err = mk_lib_iip_random_generate_u8s(&tu8s[0], batch); mk_lang_check_rereturn(err);
		mk_sl_cui_uint8_to_bi_uchar_many(&tu8s[0], &dst[0], ((mk_lang_types_usize_t)(batch)));
		dst += batch;
	}
	rem = rem - n * batch;
	if(rem != 0)
	{
		err = mk_lib_iip_random_generate_u8s(&tu8s[0], rem); mk_lang_check_rereturn(err);
		mk_sl_cui_uint8_to_bi_uchar_many(&tu8s[0], &dst[0], ((mk_lang_types_usize_t)(rem)));
	}
	return 0;
}


#endif
