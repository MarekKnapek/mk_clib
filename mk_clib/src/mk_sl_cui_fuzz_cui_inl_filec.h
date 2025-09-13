#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_endian.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_roundup.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"


#include "mk_sl_cui_fuzz_cui_inl_defd.h"


#define mk_sl_cui_t_name mk_sl_cui_fuzz_cui_inl_defd_cui_a_name
#define mk_sl_cui_t_base_type_name mk_sl_cui_fuzz_cui_inl_defd_cui_a_base
#define mk_sl_cui_t_count mk_sl_cui_fuzz_cui_inl_defd_cui_a_count
#define mk_sl_cui_t_endian mk_sl_cui_fuzz_cui_inl_defd_cui_a_endian
#define mk_sl_cui_t_disable_big_div mk_sl_cui_fuzz_cui_inl_defd_cui_a_disable_big_div
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_fuzz_cui_inl_defd_cui_a_base_size_bits_d
#define mk_sl_cui_t_inline mk_sl_cui_fuzz_cui_inl_defd_cui_a_inline
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_cui_fuzz_cui_inl_defd_cui_b_name
#define mk_sl_cui_t_base_type_name mk_sl_cui_fuzz_cui_inl_defd_cui_b_base
#define mk_sl_cui_t_count mk_sl_cui_fuzz_cui_inl_defd_cui_b_count
#define mk_sl_cui_t_endian mk_sl_cui_fuzz_cui_inl_defd_cui_b_endian
#define mk_sl_cui_t_disable_big_div mk_sl_cui_fuzz_cui_inl_defd_cui_b_disable_big_div
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_fuzz_cui_inl_defd_cui_b_base_size_bits_d
#define mk_sl_cui_t_inline mk_sl_cui_fuzz_cui_inl_defd_cui_b_inline
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


struct mk_sl_cui_fuzz_cui_inl_defd_pr_storage_s
{
	mk_lang_types_uint_t m_uints[mk_lang_roundup_div(mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v, mk_lang_sizeof_bi_uint_t)];
};
typedef struct mk_sl_cui_fuzz_cui_inl_defd_pr_storage_s mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t;


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_statics(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_fuzz_cui_inl_defd_cui_a_t) == sizeof(mk_sl_cui_fuzz_cui_inl_defd_cui_b_t));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_cui_inl_defd_cui_b_size_bytes_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v )) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_cui_inl_defd_cui_b_size_bits_v )));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_bin_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_oct_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_oct_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_dec_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_dec_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v)));

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(data));
	((mk_lang_types_void_t)(size));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_bool(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uchar_t ui mk_lang_constexpr_init;
	mk_lang_types_bool_t b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_bool_t)
	{
		mk_lang_bui_uchar_from_buis_uchar_le(&ui, &data[0]);
		b = !!((mk_lang_types_bool_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_bool(&cui_a, &b);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_bool(&cui_b, &b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_pchar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uchar_t ui mk_lang_constexpr_init;
	mk_lang_types_pchar_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_pchar_t)
	{
		mk_lang_bui_uchar_from_buis_uchar_le(&ui, &data[0]);
		si = ((mk_lang_types_pchar_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_pchar(&cui_a, &si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_pchar(&cui_b, &si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_wchar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_wchar_t ui mk_lang_constexpr_init;
	mk_lang_types_wchar_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_bui_wchar_size_bytes_v == mk_lang_sizeof_bi_wchar_t);

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_wchar_t)
	{
		mk_lang_bui_wchar_from_buis_uchar_le(&ui, &data[0]);
		si = ((mk_lang_types_wchar_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_wchar(&cui_a, &si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_wchar(&cui_b, &si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_uchar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uchar_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_uchar_t)
	{
		mk_lang_bui_uchar_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_uchar(&cui_a, &ui);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_uchar(&cui_b, &ui);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_schar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uchar_t ui mk_lang_constexpr_init;
	mk_lang_types_schar_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_schar_t)
	{
		mk_lang_bui_uchar_from_buis_uchar_le(&ui, &data[0]);
		si = ((mk_lang_types_schar_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_schar(&cui_a, &si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_schar(&cui_b, &si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_ushort(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ushort_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_ushort_t)
	{
		mk_lang_bui_ushort_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_ushort(&cui_a, &ui);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_ushort(&cui_b, &ui);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_sshort(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ushort_t ui mk_lang_constexpr_init;
	mk_lang_types_sshort_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_sshort_t)
	{
		mk_lang_bui_ushort_from_buis_uchar_le(&ui, &data[0]);
		si = ((mk_lang_types_sshort_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_sshort(&cui_a, &si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_sshort(&cui_b, &si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_uint(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uint_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_uint_t)
	{
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_uint(&cui_a, &ui);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_uint(&cui_b, &ui);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_sint(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_sint_t)
	{
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[0]);
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_sint(&cui_a, &si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_sint(&cui_b, &si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_ulong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ulong_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_ulong_t)
	{
		mk_lang_bui_ulong_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_ulong(&cui_a, &ui);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_ulong(&cui_b, &ui);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_slong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ulong_t ui mk_lang_constexpr_init;
	mk_lang_types_slong_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_slong_t)
	{
		mk_lang_bui_ulong_from_buis_uchar_le(&ui, &data[0]);
		si = ((mk_lang_types_slong_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_slong(&cui_a, &si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_slong(&cui_b, &si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_ullong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ullong_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_ullong_t)
	{
		mk_lang_bui_ullong_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_ullong(&cui_a, &ui);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_ullong(&cui_b, &ui);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_sllong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ullong_t ui mk_lang_constexpr_init;
	mk_lang_types_sllong_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_sllong_t)
	{
		mk_lang_bui_ullong_from_buis_uchar_le(&ui, &data[0]);
		si = ((mk_lang_types_sllong_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_sllong(&cui_a, &si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_sllong(&cui_b, &si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_ulllong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ulllong_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_ulllong_t)
	{
		mk_lang_bui_ulllong_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_ulllong(&cui_a, &ui);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_ulllong(&cui_b, &ui);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_slllong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ulllong_t ui mk_lang_constexpr_init;
	mk_lang_types_slllong_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_slllong_t)
	{
		mk_lang_bui_ulllong_from_buis_uchar_le(&ui, &data[0]);
		si = ((mk_lang_types_slllong_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_slllong(&cui_a, &si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_slllong(&cui_b, &si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_uintptr(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uintptr_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_uintptr_t)
	{
		mk_lang_bui_uintptr_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_uintptr(&cui_a, &ui);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_uintptr(&cui_b, &ui);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_sintptr(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uintptr_t ui mk_lang_constexpr_init;
	mk_lang_types_sintptr_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_sintptr_t)
	{
		mk_lang_bui_uintptr_from_buis_uchar_le(&ui, &data[0]);
		si = ((mk_lang_types_sintptr_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_sintptr(&cui_a, &si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_sintptr(&cui_b, &si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_uintmax(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uintmax_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_uintmax_t)
	{
		mk_lang_bui_uintmax_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_uintmax(&cui_a, &ui);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_uintmax(&cui_b, &ui);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_sintmax(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uintmax_t ui mk_lang_constexpr_init;
	mk_lang_types_sintmax_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_sintmax_t)
	{
		mk_lang_bui_uintmax_from_buis_uchar_le(&ui, &data[0]);
		si = ((mk_lang_types_sintmax_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_sintmax(&cui_a, &si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_sintmax(&cui_b, &si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_usize(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_usize_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_usize_t)
	{
		mk_lang_bui_usize_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_usize(&cui_a, &ui);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_usize(&cui_b, &ui);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_ssize(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_usize_t ui mk_lang_constexpr_init;
	mk_lang_types_ssize_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_ssize_t)
	{
		mk_lang_bui_usize_from_buis_uchar_le(&ui, &data[0]);
		si = ((mk_lang_types_ssize_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_bi_ssize(&cui_a, &si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_bi_ssize(&cui_b, &si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_bool(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_bool(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_bool(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_pchar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_pchar_t ra mk_lang_constexpr_init;
	mk_lang_types_pchar_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_pchar(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_pchar(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_wchar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_wchar_t ra mk_lang_constexpr_init;
	mk_lang_types_wchar_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_wchar(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_wchar(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_uchar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uchar_t ra mk_lang_constexpr_init;
	mk_lang_types_uchar_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_uchar(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_uchar(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_schar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_schar_t ra mk_lang_constexpr_init;
	mk_lang_types_schar_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_schar(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_schar(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_ushort(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_ushort_t ra mk_lang_constexpr_init;
	mk_lang_types_ushort_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_ushort(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_ushort(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_sshort(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_sshort_t ra mk_lang_constexpr_init;
	mk_lang_types_sshort_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_sshort(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_sshort(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_uint(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uint_t ra mk_lang_constexpr_init;
	mk_lang_types_uint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_uint(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_uint(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_sint(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_sint(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_sint(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_ulong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_ulong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_ulong(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_ulong(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_slong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_slong_t ra mk_lang_constexpr_init;
	mk_lang_types_slong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_slong(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_slong(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_ullong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_ullong_t ra mk_lang_constexpr_init;
	mk_lang_types_ullong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_ullong(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_ullong(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_sllong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_sllong_t ra mk_lang_constexpr_init;
	mk_lang_types_sllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_sllong(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_sllong(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_ulllong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_ulllong(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_ulllong(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_slllong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_slllong_t ra mk_lang_constexpr_init;
	mk_lang_types_slllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_slllong(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_slllong(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_uintptr(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uintptr_t ra mk_lang_constexpr_init;
	mk_lang_types_uintptr_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_uintptr(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_uintptr(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_sintptr(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_sintptr_t ra mk_lang_constexpr_init;
	mk_lang_types_sintptr_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_sintptr(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_sintptr(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_uintmax(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uintmax_t ra mk_lang_constexpr_init;
	mk_lang_types_uintmax_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_uintmax(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_uintmax(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_sintmax(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_sintmax_t ra mk_lang_constexpr_init;
	mk_lang_types_sintmax_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_sintmax(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_sintmax(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_usize(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_usize_t ra mk_lang_constexpr_init;
	mk_lang_types_usize_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_usize(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_usize(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_ssize(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_ssize_t ra mk_lang_constexpr_init;
	mk_lang_types_ssize_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_ssize(&cui_a, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_ssize(&cui_b, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_assign_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_b_assign(&buia, &buib);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_assign(&cuia, &cuib);

		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&buia, &buib));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cuia, &cuib));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_assign_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_assign(&cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_assign(&cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_set_zero(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_set_zero(&cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_set_zero(&cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_a));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_is_zero(&cui_b));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_set_max(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_set_max(&cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_set_max(&cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_max(&cui_a));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_is_max(&cui_b));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_set_one(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_set_one(&cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_set_one(&cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_one(&cui_a));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_is_one(&cui_b));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_set_two(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_set_two(&cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_set_two(&cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_two(&cui_a));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_is_two(&cui_b));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_set_bit(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uint_t count_ui mk_lang_constexpr_init;
	mk_lang_types_sint_t count_si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&count_ui, &data[ptr]);
		count_si = ((mk_lang_types_sint_t)(count_ui % mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_set_bit(&cui_a, count_si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_set_bit(&cui_b, count_si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_set_mask(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uint_t count_ui mk_lang_constexpr_init;
	mk_lang_types_sint_t count_si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&count_ui, &data[ptr]);
		count_si = ((mk_lang_types_sint_t)((count_ui % mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v) + 1));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_set_mask(&cui_a, count_si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_set_mask(&cui_b, count_si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_count_leading_zeros(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_count_leading_zeros(&cui_a);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_count_leading_zeros(&cui_b);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_count_leading_ones(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_count_leading_ones(&cui_a);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_count_leading_ones(&cui_b);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_count_trailing_zeros(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_count_trailing_zeros(&cui_a);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_count_trailing_zeros(&cui_b);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_count_trailing_ones(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_count_trailing_ones(&cui_a);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_count_trailing_ones(&cui_b);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_count_zeros(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_count_zeros(&cui_a);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_count_zeros(&cui_b);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_count_ones(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_count_ones(&cui_a);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_count_ones(&cui_b);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_has_msb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_has_msb(&cui_a);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_has_msb(&cui_b);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_has_lsb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_has_lsb(&cui_a);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_has_lsb(&cui_b);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_is_zero(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_a);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_is_zero(&cui_b);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_is_one(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_one(&cui_a);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_is_one(&cui_b);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_is_two(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_two(&cui_a);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_is_two(&cui_b);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_is_max(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_max(&cui_a);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_is_max(&cui_b);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_is_bit(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uint_t idx_ui mk_lang_constexpr_init;
	mk_lang_types_sint_t idx_si mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&idx_ui, &data[ptr]);
		idx_si = ((mk_lang_types_sint_t)(idx_ui % mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v));

		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_bit(&cui_a, idx_si);
		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_is_bit(&cui_b, idx_si);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_eq(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&buia, &buib);
		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_ne(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_ne(&buia, &buib);
		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_ne(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_lt(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_lt(&buia, &buib);
		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_lt(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_le(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_le(&buia, &buib);
		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_le(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_gt(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_gt(&buia, &buib);
		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_gt(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_ge(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_ge(&buia, &buib);
		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_ge(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_cmp(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		ra = mk_sl_cui_fuzz_cui_inl_defd_cui_b_cmp(&buia, &buib);
		rb = mk_sl_cui_fuzz_cui_inl_defd_cui_a_cmp(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_inc1(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_inc1(&cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_inc1(&cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_dec1(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_dec1(&cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_dec1(&cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_inc2_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_inc2(&cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_inc2(&cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_inc2_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_inc2(&cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_inc2(&cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_dec2_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_dec2(&cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_dec2(&cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_dec2_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_dec2(&cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_dec2(&cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_not1(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_not1(&cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_not1(&cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_not2_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_not2(&cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_not2(&cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_not2_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_not2(&cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_not2(&cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_or2_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_or2(&cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_or2(&cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_or2_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_or2(&cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_or2(&cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_and2_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_and2(&cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_and2(&cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_and2_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_and2(&cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_and2(&cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_xor2_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_xor2(&cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_xor2(&cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_xor2_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_xor2(&cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_xor2(&cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_or3_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_or3(&cui_aa, &cui_ab, &cui_ac);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_or3(&cui_ba, &cui_bb, &cui_bc);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_or3_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_or3(&cui_aa, &cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_or3(&cui_ba, &cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_or3_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_or3(&cui_aa, &cui_ab, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_or3(&cui_ba, &cui_bb, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_or3_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_or3(&cui_aa, &cui_ab, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_or3(&cui_ba, &cui_bb, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_or3_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_or3(&cui_a, &cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_or3(&cui_b, &cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_and3_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_and3(&cui_aa, &cui_ab, &cui_ac);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_and3(&cui_ba, &cui_bb, &cui_bc);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_and3_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_and3(&cui_aa, &cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_and3(&cui_ba, &cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_and3_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_and3(&cui_aa, &cui_ab, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_and3(&cui_ba, &cui_bb, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_and3_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_and3(&cui_aa, &cui_ab, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_and3(&cui_ba, &cui_bb, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_and3_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_and3(&cui_a, &cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_and3(&cui_b, &cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_xor3_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_xor3(&cui_aa, &cui_ab, &cui_ac);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_xor3(&cui_ba, &cui_bb, &cui_bc);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_xor3_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_xor3(&cui_aa, &cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_xor3(&cui_ba, &cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_xor3_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_xor3(&cui_aa, &cui_ab, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_xor3(&cui_ba, &cui_bb, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_xor3_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[0 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_xor3(&cui_aa, &cui_ab, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_xor3(&cui_ba, &cui_bb, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_xor3_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[0]);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_xor3(&cui_a, &cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_xor3(&cui_b, &cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_shl2(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v;
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_shl2(&cui_a, si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_shl2(&cui_b, si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_shl3_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v;
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_shl3(&cui_aa, si, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_shl3(&cui_ba, si, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_shl3_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v;
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_shl3(&cui_a, si, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_shl3(&cui_b, si, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_shr2(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v;
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_shr2(&cui_a, si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_shr2(&cui_b, si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_shr3_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v;
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_shr3(&cui_aa, si, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_shr3(&cui_ba, si, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_shr3_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v;
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_shr3(&cui_a, si, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_shr3(&cui_b, si, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_rotl2(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % (mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v - 1);
		si = ((mk_lang_types_sint_t)(ui)) + 1;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_rotl2(&cui_a, si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_rotl2(&cui_b, si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_rotl3_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % (mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v - 1);
		si = ((mk_lang_types_sint_t)(ui)) + 1;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_rotl3(&cui_aa, si, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_rotl3(&cui_ba, si, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_rotl3_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % (mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v - 1);
		si = ((mk_lang_types_sint_t)(ui)) + 1;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_rotl3(&cui_a, si, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_rotl3(&cui_b, si, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_rotr2(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % (mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v - 1);
		si = ((mk_lang_types_sint_t)(ui)) + 1;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_rotr2(&cui_a, si);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_rotr2(&cui_b, si);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_rotr3_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % (mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v - 1);
		si = ((mk_lang_types_sint_t)(ui)) + 1;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_rotr3(&cui_aa, si, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_rotr3(&cui_ba, si, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_rotr3_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % (mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bits_v - 1);
		si = ((mk_lang_types_sint_t)(ui)) + 1;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_rotr3(&cui_a, si, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_rotr3(&cui_b, si, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_cod_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cid_cod(&cui_aa, &cui_ab, &cui_ac);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cid_cod(&cui_ba, &cui_bb, &cui_bc);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_cod_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cid_cod(&cui_aa, &cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cid_cod(&cui_ba, &cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_cod_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cid_cod(&cui_aa, &cui_ab, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cid_cod(&cui_ba, &cui_bb, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_cod_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cid_cod(&cui_aa, &cui_ab, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cid_cod(&cui_ba, &cui_bb, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_cod_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cid_cod(&cui_a, &cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cid_cod(&cui_b, &cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_coe_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cid_coe(&cui_aa, &cui_ab, &cui_ac, &cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cid_coe(&cui_ba, &cui_bb, &cui_bc, &cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_coe_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cid_coe(&cui_aa, &cui_aa, &cui_ab, &cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cid_coe(&cui_ba, &cui_ba, &cui_bb, &cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_coe_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cid_coe(&cui_aa, &cui_ab, &cui_aa, &cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cid_coe(&cui_ba, &cui_bb, &cui_ba, &cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_coe_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cid_coe(&cui_aa, &cui_ab, &cui_ab, &cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cid_coe(&cui_ba, &cui_bb, &cui_bb, &cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_coe_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cid_coe(&cui_a, &cui_a, &cui_a, &cfb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cid_coe(&cui_b, &cui_b, &cui_b, &cfa);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_cod_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cie_cod(&cui_aa, &cui_ab, cfa, &cui_ac);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cie_cod(&cui_ba, &cui_bb, cfb, &cui_bc);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_cod_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cie_cod(&cui_aa, &cui_aa, cfa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cie_cod(&cui_ba, &cui_ba, cfb, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_cod_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cie_cod(&cui_aa, &cui_ab, cfa, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cie_cod(&cui_ba, &cui_bb, cfb, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_cod_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cie_cod(&cui_aa, &cui_ab, cfa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cie_cod(&cui_ba, &cui_bb, cfb, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_cod_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cie_cod(&cui_a, &cui_a, cfb, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cie_cod(&cui_b, &cui_b, cfa, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_coe_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cie_coe(&cui_aa, &cui_ab, cia, &cui_ac, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cie_coe(&cui_ba, &cui_bb, cib, &cui_bc, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_coe_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cie_coe(&cui_aa, &cui_aa, cia, &cui_ab, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cie_coe(&cui_ba, &cui_ba, cib, &cui_bb, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_coe_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cie_coe(&cui_aa, &cui_ab, cia, &cui_aa, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cie_coe(&cui_ba, &cui_bb, cib, &cui_ba, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_coe_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cie_coe(&cui_aa, &cui_ab, cia, &cui_ab, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cie_coe(&cui_ba, &cui_bb, cib, &cui_bb, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_coe_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add3_wrap_cie_coe(&cui_a, &cui_a, cia, &cui_a, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add3_wrap_cie_coe(&cui_b, &cui_b, cib, &cui_b, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cid_cod_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add2_wrap_cid_cod(&cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add2_wrap_cid_cod(&cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cid_cod_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add2_wrap_cid_cod(&cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add2_wrap_cid_cod(&cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cid_coe_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add2_wrap_cid_coe(&cui_aa, &cui_ab, &cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add2_wrap_cid_coe(&cui_ba, &cui_bb, &cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cid_coe_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add2_wrap_cid_coe(&cui_a, &cui_a, &cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add2_wrap_cid_coe(&cui_b, &cui_b, &cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cie_cod_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add2_wrap_cie_cod(&cui_aa, &cui_ab, cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add2_wrap_cie_cod(&cui_ba, &cui_bb, cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cie_cod_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add2_wrap_cie_cod(&cui_a, &cui_a, cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add2_wrap_cie_cod(&cui_b, &cui_b, cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cie_coe_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add2_wrap_cie_coe(&cui_aa, &cui_ab, cia, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add2_wrap_cie_coe(&cui_ba, &cui_bb, cib, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cie_coe_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_add2_wrap_cie_coe(&cui_a, &cui_a, cia, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_add2_wrap_cie_coe(&cui_b, &cui_b, cib, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_cod_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cid_cod(&cui_aa, &cui_ab, &cui_ac);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cid_cod(&cui_ba, &cui_bb, &cui_bc);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_cod_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cid_cod(&cui_aa, &cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cid_cod(&cui_ba, &cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_cod_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cid_cod(&cui_aa, &cui_ab, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cid_cod(&cui_ba, &cui_bb, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_cod_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cid_cod(&cui_aa, &cui_ab, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cid_cod(&cui_ba, &cui_bb, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_cod_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cid_cod(&cui_a, &cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cid_cod(&cui_b, &cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_coe_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cid_coe(&cui_aa, &cui_ab, &cui_ac, &cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cid_coe(&cui_ba, &cui_bb, &cui_bc, &cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_coe_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cid_coe(&cui_aa, &cui_aa, &cui_ab, &cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cid_coe(&cui_ba, &cui_ba, &cui_bb, &cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_coe_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cid_coe(&cui_aa, &cui_ab, &cui_aa, &cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cid_coe(&cui_ba, &cui_bb, &cui_ba, &cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_coe_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cid_coe(&cui_aa, &cui_ab, &cui_ab, &cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cid_coe(&cui_ba, &cui_bb, &cui_bb, &cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_coe_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cid_coe(&cui_a, &cui_a, &cui_a, &cfb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cid_coe(&cui_b, &cui_b, &cui_b, &cfa);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_cod_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cie_cod(&cui_aa, &cui_ab, cfa, &cui_ac);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cie_cod(&cui_ba, &cui_bb, cfb, &cui_bc);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_cod_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cie_cod(&cui_aa, &cui_aa, cfa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cie_cod(&cui_ba, &cui_ba, cfb, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_cod_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cie_cod(&cui_aa, &cui_ab, cfa, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cie_cod(&cui_ba, &cui_bb, cfb, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_cod_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cie_cod(&cui_aa, &cui_ab, cfa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cie_cod(&cui_ba, &cui_bb, cfb, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_cod_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cie_cod(&cui_a, &cui_a, cfb, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cie_cod(&cui_b, &cui_b, cfa, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_coe_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cie_coe(&cui_aa, &cui_ab, cia, &cui_ac, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cie_coe(&cui_ba, &cui_bb, cib, &cui_bc, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_coe_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cie_coe(&cui_aa, &cui_aa, cia, &cui_ab, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cie_coe(&cui_ba, &cui_ba, cib, &cui_bb, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_coe_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cie_coe(&cui_aa, &cui_ab, cia, &cui_aa, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cie_coe(&cui_ba, &cui_bb, cib, &cui_ba, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_coe_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cie_coe(&cui_aa, &cui_ab, cia, &cui_ab, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cie_coe(&cui_ba, &cui_bb, cib, &cui_bb, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_coe_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub3_wrap_cie_coe(&cui_a, &cui_a, cia, &cui_a, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub3_wrap_cie_coe(&cui_b, &cui_b, cib, &cui_b, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cid_cod_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub2_wrap_cid_cod(&cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub2_wrap_cid_cod(&cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cid_cod_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub2_wrap_cid_cod(&cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub2_wrap_cid_cod(&cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cid_coe_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub2_wrap_cid_coe(&cui_aa, &cui_ab, &cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub2_wrap_cid_coe(&cui_ba, &cui_bb, &cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cid_coe_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub2_wrap_cid_coe(&cui_a, &cui_a, &cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub2_wrap_cid_coe(&cui_b, &cui_b, &cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cie_cod_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub2_wrap_cie_cod(&cui_aa, &cui_ab, cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub2_wrap_cie_cod(&cui_ba, &cui_bb, cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cie_cod_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub2_wrap_cie_cod(&cui_a, &cui_a, cfa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub2_wrap_cie_cod(&cui_b, &cui_b, cfb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cie_coe_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub2_wrap_cie_coe(&cui_aa, &cui_ab, cia, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub2_wrap_cie_coe(&cui_ba, &cui_bb, cib, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cie_coe_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_sub2_wrap_cie_coe(&cui_a, &cui_a, cia, &coa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_sub2_wrap_cie_coe(&cui_b, &cui_b, cib, &cob);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_lo_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul3_wrap_lo(&cui_aa, &cui_ab, &cui_ac);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul3_wrap_lo(&cui_ba, &cui_bb, &cui_bc);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_lo_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul3_wrap_lo(&cui_aa, &cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul3_wrap_lo(&cui_ba, &cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_lo_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul3_wrap_lo(&cui_aa, &cui_ab, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul3_wrap_lo(&cui_ba, &cui_bb, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_lo_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul3_wrap_lo(&cui_aa, &cui_ab, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul3_wrap_lo(&cui_ba, &cui_bb, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_lo_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul3_wrap_lo(&cui_a, &cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul3_wrap_lo(&cui_b, &cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_hi_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul3_wrap_hi(&cui_aa, &cui_ab, &cui_ac);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul3_wrap_hi(&cui_ba, &cui_bb, &cui_bc);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_hi_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul3_wrap_hi(&cui_aa, &cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul3_wrap_hi(&cui_ba, &cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_hi_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul3_wrap_hi(&cui_aa, &cui_ab, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul3_wrap_hi(&cui_ba, &cui_bb, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_hi_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul3_wrap_hi(&cui_aa, &cui_ab, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul3_wrap_hi(&cui_ba, &cui_bb, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_hi_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul3_wrap_hi(&cui_a, &cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul3_wrap_hi(&cui_b, &cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abcd(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bd mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ad mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 4 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ad, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bd, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi(&cui_aa, &cui_ab, &cui_ac, &cui_ad);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi(&cui_ba, &cui_bb, &cui_bc, &cui_bd);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ad, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bd, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_aabc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi(&cui_aa, &cui_aa, &cui_ab, &cui_ac);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi(&cui_ba, &cui_ba, &cui_bb, &cui_bc);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abac(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi(&cui_aa, &cui_ab, &cui_aa, &cui_ac);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi(&cui_ba, &cui_bb, &cui_ba, &cui_bc);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abca(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi(&cui_aa, &cui_ab, &cui_ac, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi(&cui_ba, &cui_bb, &cui_bc, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abbc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi(&cui_aa, &cui_ab, &cui_ab, &cui_ac);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi(&cui_ba, &cui_bb, &cui_bb, &cui_bc);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abcb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi(&cui_aa, &cui_ab, &cui_ac, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi(&cui_ba, &cui_bb, &cui_bc, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi(&cui_aa, &cui_ab, &cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi(&cui_ba, &cui_bb, &cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi(&cui_aa, &cui_ab, &cui_ab, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi(&cui_ba, &cui_bb, &cui_bb, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_aaab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi(&cui_aa, &cui_aa, &cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi(&cui_ba, &cui_ba, &cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_aaba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi(&cui_aa, &cui_aa, &cui_ab, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi(&cui_ba, &cui_ba, &cui_bb, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_smol_a_abcd(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_base_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_base_t cui_ad mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_add mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_bd mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_sl_cui_fuzz_cui_inl_defd_cui_a_base_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_base_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_base(&cui_bb, &cui_ab);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_base_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi_smol(&cui_aa, &cui_ab, &cui_ac, &cui_ad);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi(&cui_ba, &cui_bb, &cui_bc, &cui_bd);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_roundup_div(mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v, mk_lang_sizeof_bi_uint_t)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_base(&cui_add, &cui_ad);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_add, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_bd, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_roundup_div(mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v, mk_lang_sizeof_bi_uint_t)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_smol_b_abcd(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_base_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_base_t cui_ad mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_add mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bd mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_b_size_bytes_v + mk_sl_cui_fuzz_cui_inl_defd_cui_b_base_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_b_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_base_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_base(&cui_bb, &cui_ab);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_b_base_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi_smol(&cui_aa, &cui_ab, &cui_ac, &cui_ad);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi(&cui_ba, &cui_bb, &cui_bc, &cui_bd);

		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_roundup_div(mk_sl_cui_fuzz_cui_inl_defd_cui_b_size_bytes_v, mk_lang_sizeof_bi_uint_t)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_base(&cui_add, &cui_ad);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_add, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bd, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_roundup_div(mk_sl_cui_fuzz_cui_inl_defd_cui_b_size_bytes_v, mk_lang_sizeof_bi_uint_t)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_smol_a_abab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_base_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_abb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_sl_cui_fuzz_cui_inl_defd_cui_a_base_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_base_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_base(&cui_bb, &cui_ab);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_base_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi_smol(&cui_aa, &cui_ab, &cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul4_wrap_wi(&cui_ba, &cui_bb, &cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_roundup_div(mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v, mk_lang_sizeof_bi_uint_t)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_base(&cui_abb, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_abb, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_roundup_div(mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v, mk_lang_sizeof_bi_uint_t)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_smol_b_abab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_base_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_abb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_b_size_bytes_v + mk_sl_cui_fuzz_cui_inl_defd_cui_b_base_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_b_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_base_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_base(&cui_bb, &cui_ab);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_b_base_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi_smol(&cui_aa, &cui_ab, &cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul4_wrap_wi(&cui_ba, &cui_bb, &cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_roundup_div(mk_sl_cui_fuzz_cui_inl_defd_cui_b_size_bytes_v, mk_lang_sizeof_bi_uint_t)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_base(&cui_abb, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_abb, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_roundup_div(mk_sl_cui_fuzz_cui_inl_defd_cui_b_size_bytes_v, mk_lang_sizeof_bi_uint_t)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul2_wrap_lo_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul2_wrap_lo(&cui_aa, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul2_wrap_lo(&cui_ba, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul2_wrap_lo_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul2_wrap_lo(&cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul2_wrap_lo(&cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul2_wrap_hi_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul2_wrap_hi(&cui_aa, &cui_aa);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul2_wrap_hi(&cui_ba, &cui_ba);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul2_wrap_hi_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul2_wrap_hi(&cui_a, &cui_a);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul2_wrap_hi(&cui_b, &cui_b);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mul2_wrap_wi_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_mul2_wrap_hi(&cui_aa, &cui_ab);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_mul2_wrap_hi(&cui_ba, &cui_bb);

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abcd(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ad mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bd mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 4 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ad, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bd, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_divmod4_wrap(&cui_aa, &cui_ab, &cui_ac, &cui_ad);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_divmod4_wrap(&cui_ba, &cui_bb, &cui_bc, &cui_bd);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ad, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bd, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_aabc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_aa))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_divmod4_wrap(&cui_aa, &cui_aa, &cui_ab, &cui_ac);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_divmod4_wrap(&cui_ba, &cui_ba, &cui_bb, &cui_bc);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abac(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_divmod4_wrap(&cui_aa, &cui_ab, &cui_aa, &cui_ac);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_divmod4_wrap(&cui_ba, &cui_bb, &cui_ba, &cui_bc);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abca(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_divmod4_wrap(&cui_aa, &cui_ab, &cui_ac, &cui_aa);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_divmod4_wrap(&cui_ba, &cui_bb, &cui_bc, &cui_ba);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abbc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_divmod4_wrap(&cui_aa, &cui_ab, &cui_ab, &cui_ac);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_divmod4_wrap(&cui_ba, &cui_bb, &cui_bb, &cui_bc);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abcb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_divmod4_wrap(&cui_aa, &cui_ab, &cui_ac, &cui_ab);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_divmod4_wrap(&cui_ba, &cui_bb, &cui_bc, &cui_bb);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_divmod4_wrap(&cui_aa, &cui_ab, &cui_aa, &cui_ab);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_divmod4_wrap(&cui_ba, &cui_bb, &cui_ba, &cui_bb);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_divmod4_wrap(&cui_aa, &cui_ab, &cui_ab, &cui_aa);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_divmod4_wrap(&cui_ba, &cui_bb, &cui_bb, &cui_ba);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_aaab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_aa))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_divmod4_wrap(&cui_aa, &cui_aa, &cui_aa, &cui_ab);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_divmod4_wrap(&cui_ba, &cui_ba, &cui_ba, &cui_bb);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_aaba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_aa))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_divmod4_wrap(&cui_aa, &cui_aa, &cui_ab, &cui_aa);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_divmod4_wrap(&cui_ba, &cui_ba, &cui_bb, &cui_ba);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_div3_wrap_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_div3_wrap(&cui_aa, &cui_ab, &cui_ac);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_div3_wrap(&cui_ba, &cui_bb, &cui_bc);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_div3_wrap_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_aa))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_div3_wrap(&cui_aa, &cui_aa, &cui_ab);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_div3_wrap(&cui_ba, &cui_ba, &cui_bb);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_div3_wrap_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_div3_wrap(&cui_aa, &cui_ab, &cui_aa);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_div3_wrap(&cui_ba, &cui_bb, &cui_ba);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_div3_wrap_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_div3_wrap(&cui_aa, &cui_ab, &cui_ab);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_div3_wrap(&cui_ba, &cui_bb, &cui_bb);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_div3_wrap_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_a))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_div3_wrap(&cui_a, &cui_a, &cui_a);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_div3_wrap(&cui_b, &cui_b, &cui_b);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mod3_wrap_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ac, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bc, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_mod3_wrap(&cui_aa, &cui_ab, &cui_ac);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_mod3_wrap(&cui_ba, &cui_bb, &cui_bc);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ac, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bc, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mod3_wrap_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_aa))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_mod3_wrap(&cui_aa, &cui_aa, &cui_ab);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_mod3_wrap(&cui_ba, &cui_ba, &cui_bb);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mod3_wrap_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_mod3_wrap(&cui_aa, &cui_ab, &cui_aa);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_mod3_wrap(&cui_ba, &cui_bb, &cui_ba);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mod3_wrap_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_mod3_wrap(&cui_aa, &cui_ab, &cui_ab);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_mod3_wrap(&cui_ba, &cui_bb, &cui_bb);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mod3_wrap_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_a))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_mod3_wrap(&cui_a, &cui_a, &cui_a);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_mod3_wrap(&cui_b, &cui_b, &cui_b);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_div2_wrap_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_div2_wrap(&cui_aa, &cui_ab);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_div2_wrap(&cui_ba, &cui_bb);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_div2_wrap_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_a))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_div2_wrap(&cui_a, &cui_a);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_div2_wrap(&cui_b, &cui_b);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mod2_wrap_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_mod2_wrap(&cui_aa, &cui_ab);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_mod2_wrap(&cui_ba, &cui_bb);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_mod2_wrap_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_a))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_mod2_wrap(&cui_a, &cui_a);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_mod2_wrap(&cui_b, &cui_b);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_divmod2_wrap_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		if(!mk_sl_cui_fuzz_cui_inl_defd_cui_a_is_zero(&cui_ab))
		{
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_divmod2_wrap(&cui_aa, &cui_ab);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_divmod2_wrap(&cui_ba, &cui_bb);
		}

		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_add_cc_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_add_cc(&cui_aa, &cui_ab);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_add_cc(&cui_ba, &cui_bb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_add_cc_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_add_cc(&cui_a, &cui_a);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_add_cc(&cui_b, &cui_b);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_add_cs_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_add_cs(&cui_aa, &cui_ab);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_add_cs(&cui_ba, &cui_bb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_add_cs_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_add_cs(&cui_a, &cui_a);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_add_cs(&cui_b, &cui_b);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_add_cp_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 != 0;
		cfb = data[ptr] % 2 != 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_add_cp(&cui_aa, &cui_ab, cfa);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_add_cp(&cui_ba, &cui_bb, cfb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_add_cp_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 != 0;
		cfb = data[ptr] % 2 != 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_add_cp(&cui_a, &cui_a, cfa);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_add_cp(&cui_b, &cui_b, cfb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_sub_cc_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_sub_cc(&cui_aa, &cui_ab);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_sub_cc(&cui_ba, &cui_bb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_sub_cc_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_sub_cc(&cui_a, &cui_a);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_sub_cc(&cui_b, &cui_b);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_sub_cs_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_sub_cs(&cui_aa, &cui_ab);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_sub_cs(&cui_ba, &cui_bb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_sub_cs_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_sub_cs(&cui_a, &cui_a);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_sub_cs(&cui_b, &cui_b);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_sub_cp_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 != 0;
		cfb = data[ptr] % 2 != 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_sub_cp(&cui_aa, &cui_ab, cfa);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_sub_cp(&cui_ba, &cui_bb, cfb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_sub_cp_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		cfa = data[ptr] % 2 != 0;
		cfb = data[ptr] % 2 != 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_sub_cp(&cui_a, &cui_a, cfa);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_sub_cp(&cui_b, &cui_b, cfb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_mul_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_mul(&cui_aa, &cui_ab);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_mul(&cui_ba, &cui_bb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_mul_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_mul(&cui_a, &cui_a);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_mul(&cui_b, &cui_b);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_div_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_div(&cui_aa, &cui_ab);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_div(&cui_ba, &cui_bb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_div_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_div(&cui_a, &cui_a);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_div(&cui_b, &cui_b);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_mod_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_ab, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_bb, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_mod(&cui_aa, &cui_ab);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_mod(&cui_ba, &cui_bb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_mod_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_b mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_a, &data[ptr]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_b, &data[ptr]);
		ptr += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;

		ba = mk_sl_cui_fuzz_cui_inl_defd_cui_a_would_overflow_mod(&cui_a, &cui_a);
		bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_would_overflow_mod(&cui_b, &cui_b);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_a, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_b, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_bin_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &d[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &d[0]);
	d += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_bin_n(&cui_aa, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_bin_n(&cui_ba, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
	mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_bin_n(&cui_ab, &str_buf_a[0], len_aa);
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_bin_n(&cui_bb, &str_buf_b[0], len_ba);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab == len_aa);
		mk_lang_test(len_bb == len_ba);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_bin_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_a[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &d[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &d[0]);
	d += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_bin_w(&cui_aa, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_bin_w(&cui_ba, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
	mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_bin_w(&cui_ab, &str_buf_a[0], len_aa);
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_bin_w(&cui_bb, &str_buf_b[0], len_ba);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab == len_aa);
		mk_lang_test(len_bb == len_ba);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_oct_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &d[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &d[0]);
	d += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_oct_n(&cui_aa, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_oct_n(&cui_ba, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
	mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_oct_n(&cui_ab, &str_buf_a[0], len_aa);
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_oct_n(&cui_bb, &str_buf_b[0], len_ba);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab == len_aa);
		mk_lang_test(len_bb == len_ba);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_oct_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_a[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &d[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &d[0]);
	d += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_oct_w(&cui_aa, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_oct_w(&cui_ba, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
	mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_oct_w(&cui_ab, &str_buf_a[0], len_aa);
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_oct_w(&cui_bb, &str_buf_b[0], len_ba);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab == len_aa);
		mk_lang_test(len_bb == len_ba);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_dec_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &d[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &d[0]);
	d += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_dec_n(&cui_aa, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_dec_n(&cui_ba, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
	mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_dec_n(&cui_ab, &str_buf_a[0], len_aa);
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_dec_n(&cui_bb, &str_buf_b[0], len_ba);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab == len_aa);
		mk_lang_test(len_bb == len_ba);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_dec_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_a[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &d[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &d[0]);
	d += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_dec_w(&cui_aa, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_dec_w(&cui_ba, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
	mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_dec_w(&cui_ab, &str_buf_a[0], len_aa);
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_dec_w(&cui_bb, &str_buf_b[0], len_ba);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab == len_aa);
		mk_lang_test(len_bb == len_ba);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_hex_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &d[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &d[0]);
	d += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_hex_n(&cui_aa, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_hex_n(&cui_ba, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
	mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_n(&cui_ab, &str_buf_a[0], len_aa);
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_n(&cui_bb, &str_buf_b[0], len_ba);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab == len_aa);
		mk_lang_test(len_bb == len_ba);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_hex_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_a[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &d[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &d[0]);
	d += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_hex_w(&cui_aa, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_hex_w(&cui_ba, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
	mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_w(&cui_ab, &str_buf_a[0], len_aa);
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_w(&cui_bb, &str_buf_b[0], len_ba);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab == len_aa);
		mk_lang_test(len_bb == len_ba);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_binf_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &d[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &d[0]);
	d += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_binf_n(&cui_aa, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_binf_n(&cui_ba, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
	mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_bin_n(&cui_ab, &str_buf_a[0], len_aa);
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_bin_n(&cui_bb, &str_buf_b[0], len_ba);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab == len_aa);
		mk_lang_test(len_bb == len_ba);
		mk_lang_test(len_ab == mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v);
		mk_lang_test(len_bb == mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_binf_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_a[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &d[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &d[0]);
	d += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_binf_w(&cui_aa, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_binf_w(&cui_ba, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
	mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_bin_w(&cui_ab, &str_buf_a[0], len_aa);
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_bin_w(&cui_bb, &str_buf_b[0], len_ba);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab == len_aa);
		mk_lang_test(len_bb == len_ba);
		mk_lang_test(len_ab == mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v);
		mk_lang_test(len_bb == mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_hexf_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &d[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &d[0]);
	d += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_hexf_n(&cui_aa, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_hexf_n(&cui_ba, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
	mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_n(&cui_ab, &str_buf_a[0], len_aa);
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_n(&cui_bb, &str_buf_b[0], len_ba);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab == len_aa);
		mk_lang_test(len_bb == len_ba);
		mk_lang_test(len_ab == mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v);
		mk_lang_test(len_bb == mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_hexf_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_a[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa, &d[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba, &d[0]);
	d += mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_hexf_w(&cui_aa, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_hexf_w(&cui_ba, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
	mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_w(&cui_ab, &str_buf_a[0], len_aa);
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_w(&cui_bb, &str_buf_b[0], len_ba);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab == len_aa);
		mk_lang_test(len_bb == len_ba);
		mk_lang_test(len_ab == mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v);
		mk_lang_test(len_bb == mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_hexf_many_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t count mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa[64] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba[mk_lang_countof(cui_aa)] mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[2 * mk_lang_countof(cui_aa) * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab[mk_lang_countof(cui_aa)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb[mk_lang_countof(cui_aa)] mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&count, &d[0]);
	count = count % mk_lang_countof(cui_aa);
	if(!(s >= count * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	n = ((mk_lang_types_sint_t)(count));
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa[i], &d[i * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba[i], &d[i * mk_sl_cui_fuzz_cui_inl_defd_cui_b_size_bytes_v]);
	}
	d += ((mk_lang_types_usize_t)(n)) * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= ((mk_lang_types_usize_t)(n)) * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_hexf_many_n(&cui_aa[0], n, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_hexf_many_n(&cui_ba[0], n, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa[i], &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba[i], &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		for(i = 0; i != n; ++i)
		{
			len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_n(&cui_ab[i], &str_buf_a[i * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v], mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v);
			len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_n(&cui_bb[i], &str_buf_b[i * mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v], mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v);
			mk_lang_test(len_ab == len_bb);
			mk_lang_test(len_ab == mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v);
			mk_lang_test(len_bb == mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v);
			mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa[i], &cui_ab[i]));
			mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba[i], &cui_bb[i]));
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_hexf_many_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t count mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa[64] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba[mk_lang_countof(cui_aa)] mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_a[2 * mk_lang_countof(cui_aa) * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_lang_countof(str_buf_a)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab[mk_lang_countof(cui_aa)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb[mk_lang_countof(cui_aa)] mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&count, &d[0]);
	count = count % mk_lang_countof(cui_aa);
	if(!(s >= count * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v))
	{
		return;
	}
	n = ((mk_lang_types_sint_t)(count));
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_buis_uchar_le(&cui_aa[i], &d[i * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_buis_uchar_le(&cui_ba[i], &d[i * mk_sl_cui_fuzz_cui_inl_defd_cui_b_size_bytes_v]);
	}
	d += ((mk_lang_types_usize_t)(n)) * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	s -= ((mk_lang_types_usize_t)(n)) * mk_sl_cui_fuzz_cui_inl_defd_cui_a_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % (mk_lang_countof(str_buf_b) + 1);

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_hexf_many_w(&cui_aa[0], n, &str_buf_a[0], ((mk_lang_types_sint_t)(str_len)));
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_hexf_many_w(&cui_ba[0], n, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));

	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa[i], &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba[i], &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}
	mk_lang_test(len_aa == len_ba);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_aa))) == 0);

	if(len_aa != 0)
	{
		for(i = 0; i != n; ++i)
		{
			len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_w(&cui_ab[i], &str_buf_a[i * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v], mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v);
			len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_w(&cui_bb[i], &str_buf_b[i * mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v], mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v);
			mk_lang_test(len_ab == len_bb);
			mk_lang_test(len_ab == mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v);
			mk_lang_test(len_bb == mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v);
			mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa[i], &cui_ab[i]));
			mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba[i], &cui_bb[i]));
		}
	}
}

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_bin_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&tul, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = ((mk_lang_types_sint_t)(tul % (mk_lang_countof(str_buf) + 1)));
	if(!(s >= ((mk_lang_types_usize_t)(str_len))))
	{
		return;
	}
	n = str_len;
	for(i = 0; i != n; ++i)
	{
		str_buf[i] = ((mk_lang_types_pchar_t)(d[i]));
	}
	d += str_len;
	s -= ((mk_lang_types_usize_t)(str_len));

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_bin_n(&cui_aa, &str_buf[0], str_len);
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_bin_n(&cui_ba, &str_buf[0], str_len);

	mk_lang_test(len_aa == len_ba);
	if(len_aa >= 1)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}

	if(len_aa >= 1)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_bin_n(&cui_aa, &str_buf_a[0], mk_lang_min(mk_lang_countof(str_buf_a), len_aa));
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_bin_n(&cui_ba, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_ba));
		mk_lang_test(len_ab >= 1);
		mk_lang_test(len_bb >= 1);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab <= len_aa);
		mk_lang_test(len_bb <= len_ba);
		mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_ab))) == 0);

		len_ac = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_bin_n(&cui_ab, &str_buf_a[0], len_ab);
		len_bc = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_bin_n(&cui_bb, &str_buf_b[0], len_bb);
		mk_lang_test(len_ac == len_ab);
		mk_lang_test(len_bc == len_bb);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_bin_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_type_traits_to_unsigned_wchar_t tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_a[mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&tul, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = ((mk_lang_types_sint_t)(tul % (mk_lang_countof(str_buf) + 1)));
	if(!(s >= ((mk_lang_types_usize_t)(str_len)) * mk_lang_sizeof_bi_wchar_t))
	{
		return;
	}
	n = str_len;
	for(i = 0; i != n; ++i)
	{
		mk_lang_bui_wchar_from_buis_uchar_le(&tmp, &d[0]);
		d += mk_lang_bui_wchar_size_bytes_v;
		s -= mk_lang_bui_wchar_size_bytes_v;
		str_buf[i] = ((mk_lang_types_wchar_t)(tmp));
	}

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_bin_w(&cui_aa, &str_buf[0], str_len);
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_bin_w(&cui_ba, &str_buf[0], str_len);

	mk_lang_test(len_aa == len_ba);
	if(len_aa >= 1)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}

	if(len_aa >= 1)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_bin_w(&cui_aa, &str_buf_a[0], mk_lang_min(mk_lang_countof(str_buf_a), len_aa));
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_bin_w(&cui_ba, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_ba));
		mk_lang_test(len_ab >= 1);
		mk_lang_test(len_bb >= 1);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab <= len_aa);
		mk_lang_test(len_bb <= len_ba);
		mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_ab))) == 0);

		len_ac = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_bin_w(&cui_ab, &str_buf_a[0], len_ab);
		len_bc = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_bin_w(&cui_bb, &str_buf_b[0], len_bb);
		mk_lang_test(len_ac == len_ab);
		mk_lang_test(len_bc == len_bb);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_oct_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&tul, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = ((mk_lang_types_sint_t)(tul % (mk_lang_countof(str_buf) + 1)));
	if(!(s >= ((mk_lang_types_usize_t)(str_len))))
	{
		return;
	}
	n = str_len;
	for(i = 0; i != n; ++i)
	{
		str_buf[i] = ((mk_lang_types_pchar_t)(d[i]));
	}
	d += str_len;
	s -= ((mk_lang_types_usize_t)(str_len));

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_oct_n(&cui_aa, &str_buf[0], str_len);
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_oct_n(&cui_ba, &str_buf[0], str_len);

	mk_lang_test(len_aa == len_ba);
	if(len_aa >= 1)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}

	if(len_aa >= 1)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_oct_n(&cui_aa, &str_buf_a[0], mk_lang_min(mk_lang_countof(str_buf_a), len_aa));
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_oct_n(&cui_ba, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_ba));
		mk_lang_test(len_ab >= 1);
		mk_lang_test(len_bb >= 1);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab <= len_aa);
		mk_lang_test(len_bb <= len_ba);
		mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_ab))) == 0);

		len_ac = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_oct_n(&cui_ab, &str_buf_a[0], len_ab);
		len_bc = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_oct_n(&cui_bb, &str_buf_b[0], len_bb);
		mk_lang_test(len_ac == len_ab);
		mk_lang_test(len_bc == len_bb);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_oct_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_type_traits_to_unsigned_wchar_t tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_a[mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&tul, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = ((mk_lang_types_sint_t)(tul % (mk_lang_countof(str_buf) + 1)));
	if(!(s >= ((mk_lang_types_usize_t)(str_len)) * mk_lang_sizeof_bi_wchar_t))
	{
		return;
	}
	n = str_len;
	for(i = 0; i != n; ++i)
	{
		mk_lang_bui_wchar_from_buis_uchar_le(&tmp, &d[0]);
		d += mk_lang_bui_wchar_size_bytes_v;
		s -= mk_lang_bui_wchar_size_bytes_v;
		str_buf[i] = ((mk_lang_types_wchar_t)(tmp));
	}

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_oct_w(&cui_aa, &str_buf[0], str_len);
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_oct_w(&cui_ba, &str_buf[0], str_len);

	mk_lang_test(len_aa == len_ba);
	if(len_aa >= 1)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}

	if(len_aa >= 1)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_oct_w(&cui_aa, &str_buf_a[0], mk_lang_min(mk_lang_countof(str_buf_a), len_aa));
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_oct_w(&cui_ba, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_ba));
		mk_lang_test(len_ab >= 1);
		mk_lang_test(len_bb >= 1);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab <= len_aa);
		mk_lang_test(len_bb <= len_ba);
		mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_ab))) == 0);

		len_ac = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_oct_w(&cui_ab, &str_buf_a[0], len_ab);
		len_bc = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_oct_w(&cui_bb, &str_buf_b[0], len_bb);
		mk_lang_test(len_ac == len_ab);
		mk_lang_test(len_bc == len_bb);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_dec_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&tul, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = ((mk_lang_types_sint_t)(tul % (mk_lang_countof(str_buf) + 1)));
	if(!(s >= ((mk_lang_types_usize_t)(str_len))))
	{
		return;
	}
	n = str_len;
	for(i = 0; i != n; ++i)
	{
		str_buf[i] = ((mk_lang_types_pchar_t)(d[i]));
	}
	d += str_len;
	s -= ((mk_lang_types_usize_t)(str_len));

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_dec_n(&cui_aa, &str_buf[0], str_len);
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_dec_n(&cui_ba, &str_buf[0], str_len);

	mk_lang_test(len_aa == len_ba);
	if(len_aa >= 1)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}

	if(len_aa >= 1)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_dec_n(&cui_aa, &str_buf_a[0], mk_lang_min(mk_lang_countof(str_buf_a), len_aa));
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_dec_n(&cui_ba, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_ba));
		mk_lang_test(len_ab >= 1);
		mk_lang_test(len_bb >= 1);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab <= len_aa);
		mk_lang_test(len_bb <= len_ba);
		mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_ab))) == 0);

		len_ac = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_dec_n(&cui_ab, &str_buf_a[0], len_ab);
		len_bc = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_dec_n(&cui_bb, &str_buf_b[0], len_bb);
		mk_lang_test(len_ac == len_ab);
		mk_lang_test(len_bc == len_bb);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_dec_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_type_traits_to_unsigned_wchar_t tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_a[mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&tul, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = ((mk_lang_types_sint_t)(tul % (mk_lang_countof(str_buf) + 1)));
	if(!(s >= ((mk_lang_types_usize_t)(str_len)) * mk_lang_sizeof_bi_wchar_t))
	{
		return;
	}
	n = str_len;
	for(i = 0; i != n; ++i)
	{
		mk_lang_bui_wchar_from_buis_uchar_le(&tmp, &d[0]);
		d += mk_lang_bui_wchar_size_bytes_v;
		s -= mk_lang_bui_wchar_size_bytes_v;
		str_buf[i] = ((mk_lang_types_wchar_t)(tmp));
	}

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_dec_w(&cui_aa, &str_buf[0], str_len);
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_dec_w(&cui_ba, &str_buf[0], str_len);

	mk_lang_test(len_aa == len_ba);
	if(len_aa >= 1)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}

	if(len_aa >= 1)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_dec_w(&cui_aa, &str_buf_a[0], mk_lang_min(mk_lang_countof(str_buf_a), len_aa));
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_dec_w(&cui_ba, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_ba));
		mk_lang_test(len_ab >= 1);
		mk_lang_test(len_bb >= 1);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab <= len_aa);
		mk_lang_test(len_bb <= len_ba);
		mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_ab))) == 0);

		len_ac = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_dec_w(&cui_ab, &str_buf_a[0], len_ab);
		len_bc = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_dec_w(&cui_bb, &str_buf_b[0], len_bb);
		mk_lang_test(len_ac == len_ab);
		mk_lang_test(len_bc == len_bb);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_hex_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&tul, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = ((mk_lang_types_sint_t)(tul % (mk_lang_countof(str_buf) + 1)));
	if(!(s >= ((mk_lang_types_usize_t)(str_len))))
	{
		return;
	}
	n = str_len;
	for(i = 0; i != n; ++i)
	{
		str_buf[i] = ((mk_lang_types_pchar_t)(d[i]));
	}
	d += str_len;
	s -= ((mk_lang_types_usize_t)(str_len));

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_n(&cui_aa, &str_buf[0], str_len);
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_n(&cui_ba, &str_buf[0], str_len);

	mk_lang_test(len_aa == len_ba);
	if(len_aa >= 1)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}

	if(len_aa >= 1)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_hex_n(&cui_aa, &str_buf_a[0], mk_lang_min(mk_lang_countof(str_buf_a), len_aa));
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_hex_n(&cui_ba, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_ba));
		mk_lang_test(len_ab >= 1);
		mk_lang_test(len_bb >= 1);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab <= len_aa);
		mk_lang_test(len_bb <= len_ba);
		mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_ab))) == 0);

		len_ac = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_n(&cui_ab, &str_buf_a[0], len_ab);
		len_bc = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_n(&cui_bb, &str_buf_b[0], len_bb);
		mk_lang_test(len_ac == len_ab);
		mk_lang_test(len_bc == len_bb);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_hex_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf[2 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_type_traits_to_unsigned_wchar_t tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t len_aa mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ab mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_a[mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bb mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_ac mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab mk_lang_constexpr_init;
	mk_lang_types_sint_t len_bc mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&tul, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = ((mk_lang_types_sint_t)(tul % (mk_lang_countof(str_buf) + 1)));
	if(!(s >= ((mk_lang_types_usize_t)(str_len)) * mk_lang_sizeof_bi_wchar_t))
	{
		return;
	}
	n = str_len;
	for(i = 0; i != n; ++i)
	{
		mk_lang_bui_wchar_from_buis_uchar_le(&tmp, &d[0]);
		d += mk_lang_bui_wchar_size_bytes_v;
		s -= mk_lang_bui_wchar_size_bytes_v;
		str_buf[i] = ((mk_lang_types_wchar_t)(tmp));
	}

	len_aa = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_w(&cui_aa, &str_buf[0], str_len);
	len_ba = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_w(&cui_ba, &str_buf[0], str_len);

	mk_lang_test(len_aa == len_ba);
	if(len_aa >= 1)
	{
		mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_aa, &ra.m_uints[0]);
		mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_ba, &rb.m_uints[0]);
		mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
	}

	if(len_aa >= 1)
	{
		len_ab = mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_str_hex_w(&cui_aa, &str_buf_a[0], mk_lang_min(mk_lang_countof(str_buf_a), len_aa));
		len_bb = mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_str_hex_w(&cui_ba, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_ba));
		mk_lang_test(len_ab >= 1);
		mk_lang_test(len_bb >= 1);
		mk_lang_test(len_ab == len_bb);
		mk_lang_test(len_ab <= len_aa);
		mk_lang_test(len_bb <= len_ba);
		mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_a[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_ab))) == 0);

		len_ac = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_w(&cui_ab, &str_buf_a[0], len_ab);
		len_bc = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_w(&cui_bb, &str_buf_b[0], len_bb);
		mk_lang_test(len_ac == len_ab);
		mk_lang_test(len_bc == len_bb);
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_aa, &cui_ab));
		mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_ba, &cui_bb));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_hex_many_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t tui mk_lang_constexpr_init;
	mk_lang_types_sint_t count mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[64 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_a mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&tui, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	tui = tui % 64;
	count = ((mk_lang_types_sint_t)(tui));
	str_len = count * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v;
	if(!(s >= ((mk_lang_types_uint_t)(str_len))))
	{
		return;
	}
	n = str_len;
	for(i = 0; i != n; ++i)
	{
		str_buf[i] = ((mk_lang_types_pchar_t)(d[i]));
	}
	d += ((mk_lang_types_usize_t)(str_len));
	s -= ((mk_lang_types_usize_t)(str_len));
	len_a = 0;
	len_b = 0;
	n = count;
	for(i = 0; i != n; ++i)
	{
		len_a = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_n(&cui_aa[i], &str_buf[i * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v], mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v);
		len_b = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_n(&cui_ba[i], &str_buf[i * mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v], mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v);
		mk_lang_assert(len_b == len_a);
		if(len_b != mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v)
		{
			break;
		}
	}

	if(len_a == mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v)
	{
		len_a = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_many_n(&cui_ab[0], count, &str_buf[0], str_len);
		len_b = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_many_n(&cui_bb[0], count, &str_buf[0], str_len);
		mk_lang_test(len_b == len_a);
		mk_lang_test(len_b == count * mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v);

		n = count;
		for(i = 0; i != n; ++i)
		{
			mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_ab[i], &cui_aa[i]));
			mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_bb[i], &cui_ba[i]));
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab[i], &ra.m_uints[0]);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb[i], &rb.m_uints[0]);
			mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		}
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_hex_many_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t tui mk_lang_constexpr_init;
	mk_lang_types_sint_t count mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_type_traits_to_unsigned_wchar_t tmp mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf[64 * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_a mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_aa[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_ba[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_a_t cui_ab[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_cui_b_t cui_bb[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t ra mk_lang_constexpr_init;
	mk_sl_cui_fuzz_cui_inl_defd_pr_storage_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&tui, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	tui = tui % 64;
	count = ((mk_lang_types_sint_t)(tui));
	str_len = count * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v;
	if(!(s >= ((mk_lang_types_uint_t)(str_len)) * mk_lang_bui_wchar_size_bytes_v))
	{
		return;
	}
	n = str_len;
	for(i = 0; i != n; ++i)
	{
		mk_lang_bui_wchar_from_buis_uchar_le(&tmp, &d[i * mk_lang_bui_wchar_size_bytes_v]);
		str_buf[i] = ((mk_lang_types_wchar_t)(tmp));
	}
	d += ((mk_lang_types_usize_t)(str_len)) * mk_lang_bui_wchar_size_bytes_v;
	s -= ((mk_lang_types_usize_t)(str_len)) * mk_lang_bui_wchar_size_bytes_v;
	len_a = 0;
	len_b = 0;
	n = count;
	for(i = 0; i != n; ++i)
	{
		len_a = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_w(&cui_aa[i], &str_buf[i * mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v], mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_bin_v);
		len_b = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_w(&cui_ba[i], &str_buf[i * mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v], mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v);
		mk_lang_assert(len_b == len_a);
		if(len_b != mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v)
		{
			break;
		}
	}

	if(len_a == mk_sl_cui_fuzz_cui_inl_defd_cui_a_strlen_hex_v)
	{
		len_a = mk_sl_cui_fuzz_cui_inl_defd_cui_a_from_str_hex_many_w(&cui_ab[0], count, &str_buf[0], str_len);
		len_b = mk_sl_cui_fuzz_cui_inl_defd_cui_b_from_str_hex_many_w(&cui_bb[0], count, &str_buf[0], str_len);
		mk_lang_test(len_b == len_a);
		mk_lang_test(len_b == count * mk_sl_cui_fuzz_cui_inl_defd_cui_b_strlen_hex_v);

		n = count;
		for(i = 0; i != n; ++i)
		{
			mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_a_eq(&cui_ab[i], &cui_aa[i]));
			mk_lang_test(mk_sl_cui_fuzz_cui_inl_defd_cui_b_eq(&cui_bb[i], &cui_ba[i]));
			mk_sl_cui_fuzz_cui_inl_defd_cui_a_to_buis_uint_le(&cui_ab[i], &ra.m_uints[0]);
			mk_sl_cui_fuzz_cui_inl_defd_cui_b_to_buis_uint_le(&cui_bb[i], &rb.m_uints[0]);
			mk_lang_test(mk_lang_string_memcmp_ui_fn(&ra.m_uints[0], &rb.m_uints[0], mk_lang_countof(ra.m_uints)) == 0);
		}
	}
}
#include "mk_lang_warning_msvc_pop.h"


mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_fuzz_cui_inl_defd_fn(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size, mk_lang_types_bool_t const allow_all) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t line mk_lang_constexpr_init;
	mk_lang_types_bool_t all mk_lang_constexpr_init;
	mk_lang_types_uint_t base mk_lang_constexpr_init;
	mk_lang_types_uint_t curr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	mk_lang_assert(allow_all == mk_lang_true || allow_all == mk_lang_false);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
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
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_statics(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_bool(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_pchar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_wchar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_uchar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_schar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_ushort(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_sshort(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_uint(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_sint(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_ulong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_slong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_ullong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_sllong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_ulllong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_slllong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_uintptr(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_sintptr(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_uintmax(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_sintmax(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_usize(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_bi_ssize(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_bool(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_pchar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_wchar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_uchar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_schar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_ushort(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_sshort(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_uint(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_sint(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_ulong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_slong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_ullong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_sllong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_ulllong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_slllong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_uintptr(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_sintptr(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_uintmax(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_sintmax(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_usize(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_bi_ssize(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_assign_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_assign_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_set_zero(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_set_max(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_set_one(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_set_one(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_set_bit(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_set_mask(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_count_leading_zeros(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_count_leading_ones(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_count_trailing_zeros(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_count_trailing_ones(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_count_zeros(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_count_ones(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_has_msb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_has_lsb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_is_zero(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_is_one(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_is_two(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_is_max(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_is_bit(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_eq(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_ne(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_lt(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_le(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_gt(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_ge(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_cmp(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_inc1(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_dec1(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_inc2_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_inc2_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_dec2_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_dec2_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_not1(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_not2_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_not2_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_or2_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_or2_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_and2_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_and2_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_xor2_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_xor2_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_or3_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_or3_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_or3_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_or3_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_or3_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_and3_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_and3_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_and3_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_and3_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_and3_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_xor3_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_xor3_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_xor3_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_xor3_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_xor3_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_shl2(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_shl3_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_shl3_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_shr2(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_shr3_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_shr3_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_rotl2(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_rotl3_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_rotl3_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_rotr2(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_rotr3_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_rotr3_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_cod_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_cod_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_cod_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_cod_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_cod_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_coe_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_coe_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_coe_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_coe_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cid_coe_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_cod_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_cod_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_cod_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_cod_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_cod_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_coe_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_coe_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_coe_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_coe_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add3_wrap_cie_coe_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cid_cod_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cid_cod_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cid_coe_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cid_coe_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cie_cod_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cie_cod_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cie_coe_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_add2_wrap_cie_coe_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_cod_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_cod_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_cod_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_cod_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_cod_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_coe_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_coe_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_coe_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_coe_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cid_coe_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_cod_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_cod_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_cod_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_cod_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_cod_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_coe_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_coe_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_coe_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_coe_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub3_wrap_cie_coe_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cid_cod_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cid_cod_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cid_coe_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cid_coe_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cie_cod_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cie_cod_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cie_coe_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_sub2_wrap_cie_coe_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_lo_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_lo_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_lo_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_lo_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_lo_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_hi_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_hi_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_hi_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_hi_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul3_wrap_hi_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abcd(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_aabc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abac(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abca(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abbc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abcb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_abba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_aaab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_aaba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_smol_a_abcd(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_smol_b_abcd(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_smol_a_abab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul4_wrap_wi_smol_b_abab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul2_wrap_lo_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul2_wrap_lo_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul2_wrap_hi_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul2_wrap_hi_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mul2_wrap_wi_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abcd(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_aabc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abac(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abca(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abbc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abcb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_abba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_aaab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_divmod4_wrap_aaba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_div3_wrap_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_div3_wrap_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_div3_wrap_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_div3_wrap_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_div3_wrap_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mod3_wrap_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mod3_wrap_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mod3_wrap_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mod3_wrap_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mod3_wrap_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_div2_wrap_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_div2_wrap_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mod2_wrap_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_mod2_wrap_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_divmod2_wrap_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_add_cc_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_add_cc_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_add_cs_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_add_cs_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_add_cp_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_add_cp_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_sub_cc_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_sub_cc_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_sub_cs_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_sub_cs_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_sub_cp_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_sub_cp_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_mul_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_mul_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_div_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_div_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_mod_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_would_overflow_mod_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_bin_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_bin_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_oct_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_oct_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_dec_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_dec_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_hex_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_hex_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_binf_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_binf_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_hexf_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_hexf_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_hexf_many_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_to_str_hexf_many_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_bin_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_bin_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_oct_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_oct_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_dec_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_dec_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_hex_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_hex_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_hex_many_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui_inl_defd_pr_from_str_hex_many_w(d, s); }
}


#include "mk_sl_cui_fuzz_cui_inl_defu.h"
