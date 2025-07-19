#ifndef mk_include_guard_mk_sl_random_lang_cpp11_cpp
#define mk_include_guard_mk_sl_random_lang_cpp11_cpp
#include "mk_sl_random_lang_cpp11.hpp"

#include "mk_lang_version.h"
#if mk_lang_version_has_macro_cplusplus && (mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_14)

#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"

#include <array>
#include <random>


union mk_sl_random_lang_cpp11_eng_data_u
{
	mk_lang_alignas(mk_lang_alignof(std::default_random_engine)) mk_lang_types_uchar_t m_uchars[sizeof(std::default_random_engine)];
};
typedef union mk_sl_random_lang_cpp11_eng_data_u mk_sl_random_lang_cpp11_eng_data_t;
struct mk_sl_random_lang_cpp11_eng_s
{
	mk_sl_random_lang_cpp11_eng_data_t m_data;
};
typedef struct mk_sl_random_lang_cpp11_eng_s mk_sl_random_lang_cpp11_eng_t;
mk_lang_typedef(mk_sl_random_lang_cpp11_eng);

union mk_sl_random_lang_cpp11_dst_data_u
{
	mk_lang_alignas(mk_lang_alignof(std::uniform_int_distribution<mk_lang_types_ushort_t>)) mk_lang_types_uchar_t m_uchars[sizeof(std::uniform_int_distribution<mk_lang_types_ushort_t>)];
};
typedef union mk_sl_random_lang_cpp11_dst_data_u mk_sl_random_lang_cpp11_dst_data_t;
struct mk_sl_random_lang_cpp11_dst_s
{
	mk_sl_random_lang_cpp11_dst_data_t m_data;
};
typedef struct mk_sl_random_lang_cpp11_dst_s mk_sl_random_lang_cpp11_dst_t;
mk_lang_typedef(mk_sl_random_lang_cpp11_dst);


struct mk_sl_random_lang_cpp11_s
{
	mk_sl_random_lang_cpp11_eng_t m_eng;
	mk_sl_random_lang_cpp11_dst_t m_dst;
};
typedef struct mk_sl_random_lang_cpp11_s mk_sl_random_lang_cpp11_t;
mk_lang_typedef(mk_sl_random_lang_cpp11);


static mk_sl_random_lang_cpp11_t mk_sl_random_lang_cpp11_g;


template<typename t>
static mk_lang_inline mk_lang_types_void_t mk_sl_random_lang_cpp11_pr_destructor(t& obj) mk_lang_noexcept
{
	obj.~t();
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_cpp11_init(mk_lang_types_void_t) mk_lang_noexcept
{
	#define mk_sl_random_lang_cpp11_k_initial_random_uints (624)

	std::default_random_engine* eng;
	std::uniform_int_distribution<mk_lang_types_ushort_t>* dst;

	mk_lang_static_assert(std::random_device::min() == 0);
	mk_lang_static_assert(std::random_device::max() >= 0xff);
	mk_lang_static_assert(std::random_device::max() % 0xff == 0);
	mk_lang_static_assert(mk_sl_random_lang_cpp11_k_initial_random_uints * mk_lang_sizeof_bi_uint_t >= std::mt19937::state_size * sizeof(std::mt19937::result_type)); /* todo result type == initialization type == internal state type ??? */
	mk_lang_static_assert(mk_sl_random_lang_cpp11_k_initial_random_uints * mk_lang_sizeof_bi_uint_t >= std::mt19937_64::state_size * sizeof(std::mt19937_64::result_type)); /* todo result type == initialization type == internal state type ??? */

	eng = ((std::default_random_engine*)(&mk_sl_random_lang_cpp11_g.m_eng.m_data.m_uchars[0]));
	dst = ((std::uniform_int_distribution<mk_lang_types_ushort_t>*)(&mk_sl_random_lang_cpp11_g.m_dst.m_data.m_uchars[0]));
	{
		std::array<mk_lang_types_uint_t, mk_sl_random_lang_cpp11_k_initial_random_uints> uints;
		{
			std::random_device rd;
			for(auto& uint : uints)
			{
				uint = rd.operator()();
			}
		}
		std::seed_seq ss{uints.cbegin(), uints.cend()};
		new(((mk_lang_types_void_pt)(eng)))std::default_random_engine(ss);
	}
	new(((mk_lang_types_void_pt)(dst)))std::uniform_int_distribution<mk_lang_types_ushort_t>(0x00, 0xff);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_cpp11_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	std::default_random_engine* eng;
	std::uniform_int_distribution<mk_lang_types_ushort_t>* dst;

	eng = ((std::default_random_engine*)(&mk_sl_random_lang_cpp11_g.m_eng.m_data.m_uchars[0]));
	dst = ((std::uniform_int_distribution<mk_lang_types_ushort_t>*)(&mk_sl_random_lang_cpp11_g.m_dst.m_data.m_uchars[0]));
	mk_sl_random_lang_cpp11_pr_destructor(*dst);
	mk_sl_random_lang_cpp11_pr_destructor(*eng);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_cpp11_generate(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	std::default_random_engine* eng;
	std::uniform_int_distribution<mk_lang_types_ushort_t>* dst;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_uint_t tui;
	mk_lang_types_uchar_t tuc;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	eng = ((std::default_random_engine*)(&mk_sl_random_lang_cpp11_g.m_eng.m_data.m_uchars[0]));
	dst = ((std::uniform_int_distribution<mk_lang_types_ushort_t>*)(&mk_sl_random_lang_cpp11_g.m_dst.m_data.m_uchars[0]));
	n = data_len;
	for(i = 0; i != n; ++i)
	{
		tui = ((mk_lang_types_uint_t)(dst->operator()(*eng)));
		tuc = ((mk_lang_types_uchar_t)(tui));
		mk_sl_cui_uint8_from_bi_uchar(&data_buf[i], &tuc);
	}
	return 0;
}


#else
static void mk_sl_random_lang_cpp11_dummy(void){}
#endif
#endif
