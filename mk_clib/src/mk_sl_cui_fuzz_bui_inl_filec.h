#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_endian.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"


#include "mk_sl_cui_fuzz_bui_inl_defd.h"


#if(!(mk_sl_cui_fuzz_bui_inl_defd_big_size_bytes_d >= mk_sl_cui_fuzz_bui_inl_defd_sml_size_bytes_d && mk_sl_cui_fuzz_bui_inl_defd_big_size_bytes_d % mk_sl_cui_fuzz_bui_inl_defd_sml_size_bytes_d == 0))
#error xxxxxxxxxx
#endif


#define mk_sl_cui_t_name mk_sl_cui_fuzz_bui_inl_defd_cui_name
#define mk_sl_cui_t_base_type_name mk_sl_cui_fuzz_bui_inl_defd_sml_bui_tn
#define mk_sl_cui_t_count mk_sl_cui_fuzz_bui_inl_defd_big_size_bytes_d / mk_sl_cui_fuzz_bui_inl_defd_sml_size_bytes_d
#define mk_sl_cui_t_endian mk_sl_cui_fuzz_bui_inl_defd_endian
#define mk_sl_cui_t_disable_big_div 0
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_fuzz_bui_inl_defd_sml_size_bits_d
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_statics(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_fuzz_bui_inl_defd_cui_t) == sizeof(mk_sl_cui_fuzz_bui_inl_defd_bui_t));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_bui_inl_defd_bui_size_bytes_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v )) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_bui_inl_defd_bui_size_bits_v )));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_bin_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_bin_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_oct_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_oct_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_dec_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_dec_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_hex_v)));

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(data));
	((mk_lang_types_void_t)(size));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_bool(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uchar_t ui mk_lang_constexpr_init;
	mk_lang_types_bool_t b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

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

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_bool(&bui, &b);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_bool(&cui, &b);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_pchar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uchar_t ui mk_lang_constexpr_init;
	mk_lang_types_pchar_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

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

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_pchar(&bui, &si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_pchar(&cui, &si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_wchar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_wchar_t ui mk_lang_constexpr_init;
	mk_lang_types_wchar_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

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

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_wchar(&bui, &si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_wchar(&cui, &si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_uchar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uchar_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_uchar_t)
	{
		mk_lang_bui_uchar_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_uchar(&bui, &ui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_uchar(&cui, &ui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_schar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uchar_t ui mk_lang_constexpr_init;
	mk_lang_types_schar_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

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

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_schar(&bui, &si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_schar(&cui, &si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_ushort(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ushort_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_ushort_t)
	{
		mk_lang_bui_ushort_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_ushort(&bui, &ui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_ushort(&cui, &ui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_sshort(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ushort_t ui mk_lang_constexpr_init;
	mk_lang_types_sshort_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

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

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_sshort(&bui, &si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_sshort(&cui, &si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_uint(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uint_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_uint_t)
	{
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_uint(&bui, &ui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_uint(&cui, &ui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_sint(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

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

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_sint(&bui, &si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_sint(&cui, &si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_ulong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ulong_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_ulong_t)
	{
		mk_lang_bui_ulong_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_ulong(&bui, &ui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_ulong(&cui, &ui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_slong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ulong_t ui mk_lang_constexpr_init;
	mk_lang_types_slong_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

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

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_slong(&bui, &si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_slong(&cui, &si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_ullong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ullong_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_ullong_t)
	{
		mk_lang_bui_ullong_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_ullong(&bui, &ui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_ullong(&cui, &ui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_sllong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ullong_t ui mk_lang_constexpr_init;
	mk_lang_types_sllong_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

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

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_sllong(&bui, &si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_sllong(&cui, &si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_ulllong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ulllong_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_ulllong_t)
	{
		mk_lang_bui_ulllong_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_ulllong(&bui, &ui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_ulllong(&cui, &ui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_slllong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_ulllong_t ui mk_lang_constexpr_init;
	mk_lang_types_slllong_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

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

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_slllong(&bui, &si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_slllong(&cui, &si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_uintptr(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uintptr_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_uintptr_t)
	{
		mk_lang_bui_uintptr_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_uintptr(&bui, &ui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_uintptr(&cui, &ui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_sintptr(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uintptr_t ui mk_lang_constexpr_init;
	mk_lang_types_sintptr_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

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

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_sintptr(&bui, &si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_sintptr(&cui, &si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_uintmax(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uintmax_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_uintmax_t)
	{
		mk_lang_bui_uintmax_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_uintmax(&bui, &ui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_uintmax(&cui, &ui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_sintmax(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_uintmax_t ui mk_lang_constexpr_init;
	mk_lang_types_sintmax_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

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

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_sintmax(&bui, &si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_sintmax(&cui, &si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_usize(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_usize_t ui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_lang_sizeof_bi_usize_t)
	{
		mk_lang_bui_usize_from_buis_uchar_le(&ui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_usize(&bui, &ui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_usize(&cui, &ui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_ssize(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_usize_t ui mk_lang_constexpr_init;
	mk_lang_types_ssize_t si mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

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

		mk_sl_cui_fuzz_bui_inl_defd_bui_from_bi_ssize(&bui, &si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_bi_ssize(&cui, &si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_bool(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_bool(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_bool(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_pchar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_pchar_t ra mk_lang_constexpr_init;
	mk_lang_types_pchar_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_pchar(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_pchar(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_wchar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_wchar_t ra mk_lang_constexpr_init;
	mk_lang_types_wchar_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_wchar(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_wchar(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_uchar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uchar_t ra mk_lang_constexpr_init;
	mk_lang_types_uchar_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_uchar(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_uchar(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_schar(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_schar_t ra mk_lang_constexpr_init;
	mk_lang_types_schar_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_schar(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_schar(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_ushort(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ushort_t ra mk_lang_constexpr_init;
	mk_lang_types_ushort_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ushort(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ushort(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_sshort(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_sshort_t ra mk_lang_constexpr_init;
	mk_lang_types_sshort_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_sshort(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_sshort(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_uint(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uint_t ra mk_lang_constexpr_init;
	mk_lang_types_uint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_uint(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_uint(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_sint(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_sint(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_sint(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_ulong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulong(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_slong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_slong_t ra mk_lang_constexpr_init;
	mk_lang_types_slong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_slong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_slong(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_ullong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ullong_t ra mk_lang_constexpr_init;
	mk_lang_types_ullong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ullong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ullong(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_sllong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_sllong_t ra mk_lang_constexpr_init;
	mk_lang_types_sllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_sllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_sllong(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_ulllong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_slllong(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_slllong_t ra mk_lang_constexpr_init;
	mk_lang_types_slllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_slllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_slllong(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_uintptr(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uintptr_t ra mk_lang_constexpr_init;
	mk_lang_types_uintptr_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_uintptr(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_uintptr(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_sintptr(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_sintptr_t ra mk_lang_constexpr_init;
	mk_lang_types_sintptr_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_sintptr(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_sintptr(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_uintmax(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uintmax_t ra mk_lang_constexpr_init;
	mk_lang_types_uintmax_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_uintmax(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_uintmax(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_sintmax(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_sintmax_t ra mk_lang_constexpr_init;
	mk_lang_types_sintmax_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_sintmax(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_sintmax(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_usize(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_usize_t ra mk_lang_constexpr_init;
	mk_lang_types_usize_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_usize(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_usize(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_ssize(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ssize_t ra mk_lang_constexpr_init;
	mk_lang_types_ssize_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ssize(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ssize(&cui, &rb);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_assign_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_assign(&buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_assign(&cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&buia, &buib));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cuia, &cuib));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_assign_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_assign(&bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_assign(&cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_set_zero(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_set_zero(&bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_set_zero(&cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(ra == 0);
		mk_lang_test(rb == 0);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_is_zero(&bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_is_zero(&cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_set_max(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_set_max(&bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_set_max(&cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(ra == ((mk_lang_types_ulllong_t)(((mk_lang_types_ulllong_t)(((mk_lang_types_ulllong_t)(((mk_lang_types_ulllong_t)(((mk_lang_types_ulllong_t)(1)) << (mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v - 1))) - ((mk_lang_types_ulllong_t)(1)))) << 1)) | ((mk_lang_types_ulllong_t)(1)))));
		mk_lang_test(rb == ((mk_lang_types_ulllong_t)(((mk_lang_types_ulllong_t)(((mk_lang_types_ulllong_t)(((mk_lang_types_ulllong_t)(((mk_lang_types_ulllong_t)(1)) << (mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v - 1))) - ((mk_lang_types_ulllong_t)(1)))) << 1)) | ((mk_lang_types_ulllong_t)(1)))));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_is_max(&bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_is_max(&cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_set_one(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_set_one(&bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_set_one(&cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(ra == 1);
		mk_lang_test(rb == 1);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_is_one(&bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_is_one(&cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_set_two(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_set_two(&bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_set_two(&cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(ra == 2);
		mk_lang_test(rb == 2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_is_two(&bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_is_two(&cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_set_bit(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uint_t count_ui mk_lang_constexpr_init;
	mk_lang_types_sint_t count_si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&count_ui, &data[ptr]);
		count_si = ((mk_lang_types_sint_t)(count_ui % mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v));

		mk_sl_cui_fuzz_bui_inl_defd_bui_set_bit(&bui, count_si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_set_bit(&cui, count_si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_set_mask(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uint_t count_ui mk_lang_constexpr_init;
	mk_lang_types_sint_t count_si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&count_ui, &data[ptr]);
		count_si = ((mk_lang_types_sint_t)((count_ui % mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v) + 1));

		mk_sl_cui_fuzz_bui_inl_defd_bui_set_mask(&bui, count_si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_set_mask(&cui, count_si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_count_leading_zeros(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_count_leading_zeros(&bui);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_count_leading_zeros(&cui);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_count_leading_ones(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_count_leading_ones(&bui);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_count_leading_ones(&cui);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_count_trailing_zeros(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_count_trailing_zeros(&bui);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_count_trailing_zeros(&cui);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_count_trailing_ones(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_count_trailing_ones(&bui);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_count_trailing_ones(&cui);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_count_zeros(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_count_zeros(&bui);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_count_zeros(&cui);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_count_ones(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_count_ones(&bui);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_count_ones(&cui);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_has_msb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_has_msb(&bui);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_has_msb(&cui);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_has_lsb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_has_lsb(&bui);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_has_lsb(&cui);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_is_zero(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_is_zero(&bui);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_is_zero(&cui);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_is_one(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_is_one(&bui);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_is_one(&cui);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_is_two(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_is_two(&bui);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_is_two(&cui);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_is_max(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_is_max(&bui);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_is_max(&cui);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_is_bit(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uint_t idx_ui mk_lang_constexpr_init;
	mk_lang_types_sint_t idx_si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&idx_ui, &data[ptr]);
		idx_si = ((mk_lang_types_sint_t)(idx_ui % mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v));

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_is_bit(&bui, idx_si);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_is_bit(&cui, idx_si);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_eq(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&buia, &buib);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_ne(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_ne(&buia, &buib);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_ne(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_lt(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_lt(&buia, &buib);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_lt(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_le(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_le(&buia, &buib);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_le(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_gt(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_gt(&buia, &buib);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_gt(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_ge(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ra mk_lang_constexpr_init;
	mk_lang_types_bool_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_ge(&buia, &buib);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_ge(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_cmp(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t ra mk_lang_constexpr_init;
	mk_lang_types_sint_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		ra = mk_sl_cui_fuzz_bui_inl_defd_bui_cmp(&buia, &buib);
		rb = mk_sl_cui_fuzz_bui_inl_defd_cui_cmp(&cuia, &cuib);

		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_inc1(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_inc1(&bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_inc1(&cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_dec1(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_dec1(&bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_dec1(&cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_inc2_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_inc2(&buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_inc2(&cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_inc2_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_inc2(&bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_inc2(&cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_dec2_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_dec2(&buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_dec2(&cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_dec2_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_dec2(&bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_dec2(&cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_not1(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_not1(&bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_not1(&cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_not2_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_not2(&buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_not2(&cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_not2_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_not2(&bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_not2(&cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_or2_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_or2(&buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_or2(&cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_or2_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_or2(&bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_or2(&cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_and2_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_and2(&buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_and2(&cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_and2_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_and2(&bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_and2(&cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_xor2_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_xor2(&buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_xor2(&cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_xor2_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_xor2(&bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_xor2(&cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_or3_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_or3(&buia, &buib, &buic);
		mk_sl_cui_fuzz_bui_inl_defd_cui_or3(&cuia, &cuib, &cuic);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_or3_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_or3(&buia, &buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_or3(&cuia, &cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_or3_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_or3(&buia, &buib, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_or3(&cuia, &cuib, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_or3_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_or3(&buia, &buib, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_or3(&cuia, &cuib, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_or3_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_or3(&bui, &bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_or3(&cui, &cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_and3_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_and3(&buia, &buib, &buic);
		mk_sl_cui_fuzz_bui_inl_defd_cui_and3(&cuia, &cuib, &cuic);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_and3_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_and3(&buia, &buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_and3(&cuia, &cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_and3_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_and3(&buia, &buib, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_and3(&cuia, &cuib, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_and3_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_and3(&buia, &buib, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_and3(&cuia, &cuib, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_and3_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_and3(&bui, &bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_and3(&cui, &cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_xor3_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_xor3(&buia, &buib, &buic);
		mk_sl_cui_fuzz_bui_inl_defd_cui_xor3(&cuia, &cuib, &cuic);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_xor3_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_xor3(&buia, &buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_xor3(&cuia, &cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_xor3_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_xor3(&buia, &buib, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_xor3(&cuia, &cuib, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_xor3_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[0 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_xor3(&buia, &buib, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_xor3(&cuia, &cuib, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_xor3_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[0]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[0]);

		mk_sl_cui_fuzz_bui_inl_defd_bui_xor3(&bui, &bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_xor3(&cui, &cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_shl2(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v;
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_bui_inl_defd_bui_shl2(&bui, si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_shl2(&cui, si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_shl3_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v;
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_bui_inl_defd_bui_shl3(&buia, si, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_shl3(&cuia, si, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_shl3_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v;
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_bui_inl_defd_bui_shl3(&bui, si, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_shl3(&cui, si, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_shr2(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v;
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_bui_inl_defd_bui_shr2(&bui, si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_shr2(&cui, si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_shr3_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v;
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_bui_inl_defd_bui_shr3(&buia, si, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_shr3(&cuia, si, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_shr3_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v;
		si = ((mk_lang_types_sint_t)(ui));

		mk_sl_cui_fuzz_bui_inl_defd_bui_shr3(&bui, si, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_shr3(&cui, si, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_rotl2(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % (mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v - 1);
		si = ((mk_lang_types_sint_t)(ui)) + 1;

		mk_sl_cui_fuzz_bui_inl_defd_bui_rotl2(&bui, si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_rotl2(&cui, si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_rotl3_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % (mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v - 1);
		si = ((mk_lang_types_sint_t)(ui)) + 1;

		mk_sl_cui_fuzz_bui_inl_defd_bui_rotl3(&buia, si, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_rotl3(&cuia, si, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_rotl3_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % (mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v - 1);
		si = ((mk_lang_types_sint_t)(ui)) + 1;

		mk_sl_cui_fuzz_bui_inl_defd_bui_rotl3(&bui, si, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_rotl3(&cui, si, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_rotr2(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % (mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v - 1);
		si = ((mk_lang_types_sint_t)(ui)) + 1;

		mk_sl_cui_fuzz_bui_inl_defd_bui_rotr2(&bui, si);
		mk_sl_cui_fuzz_bui_inl_defd_cui_rotr2(&cui, si);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_rotr3_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % (mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v - 1);
		si = ((mk_lang_types_sint_t)(ui)) + 1;

		mk_sl_cui_fuzz_bui_inl_defd_bui_rotr3(&buia, si, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_rotr3(&cuia, si, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_rotr3_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t si mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_uint_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_lang_bui_uint_from_buis_uchar_le(&ui, &data[ptr]);
		ui = ui % (mk_sl_cui_fuzz_bui_inl_defd_cui_size_bits_v - 1);
		si = ((mk_lang_types_sint_t)(ui)) + 1;

		mk_sl_cui_fuzz_bui_inl_defd_bui_rotr3(&bui, si, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_rotr3(&cui, si, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_cod_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cid_cod(&buia, &buib, &buic);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cid_cod(&cuia, &cuib, &cuic);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_cod_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cid_cod(&buia, &buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cid_cod(&cuia, &cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_cod_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cid_cod(&buia, &buib, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cid_cod(&cuia, &cuib, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_cod_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cid_cod(&buia, &buib, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cid_cod(&cuia, &cuib, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_cod_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cid_cod(&bui, &bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cid_cod(&cui, &cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_coe_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cid_coe(&buia, &buib, &buic, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cid_coe(&cuia, &cuib, &cuic, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_coe_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cid_coe(&buia, &buia, &buib, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cid_coe(&cuia, &cuia, &cuib, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_coe_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cid_coe(&buia, &buib, &buia, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cid_coe(&cuia, &cuib, &cuia, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_coe_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cid_coe(&buia, &buib, &buib, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cid_coe(&cuia, &cuib, &cuib, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_coe_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cid_coe(&bui, &bui, &bui, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cid_coe(&cui, &cui, &cui, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_cod_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cie_cod(&buia, &buib, cfa, &buic);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cie_cod(&cuia, &cuib, cfb, &cuic);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_cod_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cie_cod(&buia, &buia, cfa, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cie_cod(&cuia, &cuia, cfb, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_cod_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cie_cod(&buia, &buib, cfa, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cie_cod(&cuia, &cuib, cfb, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_cod_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cie_cod(&buia, &buib, cfa, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cie_cod(&cuia, &cuib, cfb, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_cod_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cie_cod(&bui, &bui, cfa, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cie_cod(&cui, &cui, cfb, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_coe_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cie_coe(&buia, &buib, cia, &buic, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cie_coe(&cuia, &cuib, cib, &cuic, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_coe_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cie_coe(&buia, &buia, cia, &buib, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cie_coe(&cuia, &cuia, cib, &cuib, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_coe_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cie_coe(&buia, &buib, cia, &buia, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cie_coe(&cuia, &cuib, cib, &cuia, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_coe_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cie_coe(&buia, &buib, cia, &buib, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cie_coe(&cuia, &cuib, cib, &cuib, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_coe_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add3_wrap_cie_coe(&bui, &bui, cia, &bui, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add3_wrap_cie_coe(&cui, &cui, cib, &cui, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cid_cod_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add2_wrap_cid_cod(&buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add2_wrap_cid_cod(&cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cid_cod_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add2_wrap_cid_cod(&bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add2_wrap_cid_cod(&cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cid_coe_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add2_wrap_cid_coe(&buia, &buib, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add2_wrap_cid_coe(&cuia, &cuib, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cid_coe_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add2_wrap_cid_coe(&bui, &bui, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add2_wrap_cid_coe(&cui, &cui, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cie_cod_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add2_wrap_cie_cod(&buia, &buib, cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add2_wrap_cie_cod(&cuia, &cuib, cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cie_cod_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add2_wrap_cie_cod(&bui, &bui, cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add2_wrap_cie_cod(&cui, &cui, cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cie_coe_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add2_wrap_cie_coe(&buia, &buib, cia, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add2_wrap_cie_coe(&cuia, &cuib, cib, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cie_coe_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_add2_wrap_cie_coe(&bui, &bui, cia, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_add2_wrap_cie_coe(&cui, &cui, cib, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_cod_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cid_cod(&buia, &buib, &buic);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cid_cod(&cuia, &cuib, &cuic);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_cod_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cid_cod(&buia, &buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cid_cod(&cuia, &cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_cod_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cid_cod(&buia, &buib, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cid_cod(&cuia, &cuib, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_cod_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cid_cod(&buia, &buib, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cid_cod(&cuia, &cuib, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_cod_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cid_cod(&bui, &bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cid_cod(&cui, &cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_coe_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cid_coe(&buia, &buib, &buic, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cid_coe(&cuia, &cuib, &cuic, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_coe_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cid_coe(&buia, &buia, &buib, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cid_coe(&cuia, &cuia, &cuib, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_coe_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cid_coe(&buia, &buib, &buia, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cid_coe(&cuia, &cuib, &cuia, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_coe_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cid_coe(&buia, &buib, &buib, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cid_coe(&cuia, &cuib, &cuib, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_coe_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cid_coe(&bui, &bui, &bui, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cid_coe(&cui, &cui, &cui, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_cod_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cie_cod(&buia, &buib, cfa, &buic);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cie_cod(&cuia, &cuib, cfb, &cuic);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_cod_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cie_cod(&buia, &buia, cfa, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cie_cod(&cuia, &cuia, cfb, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_cod_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cie_cod(&buia, &buib, cfa, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cie_cod(&cuia, &cuib, cfb, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_cod_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cie_cod(&buia, &buib, cfa, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cie_cod(&cuia, &cuib, cfb, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_cod_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cie_cod(&bui, &bui, cfa, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cie_cod(&cui, &cui, cfb, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_coe_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cie_coe(&buia, &buib, cia, &buic, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cie_coe(&cuia, &cuib, cib, &cuic, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_coe_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cie_coe(&buia, &buia, cia, &buib, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cie_coe(&cuia, &cuia, cib, &cuib, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_coe_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cie_coe(&buia, &buib, cia, &buia, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cie_coe(&cuia, &cuib, cib, &cuia, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_coe_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cie_coe(&buia, &buib, cia, &buib, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cie_coe(&cuia, &cuib, cib, &cuib, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_coe_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub3_wrap_cie_coe(&bui, &bui, cia, &bui, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub3_wrap_cie_coe(&cui, &cui, cib, &cui, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cid_cod_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub2_wrap_cid_cod(&buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub2_wrap_cid_cod(&cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cid_cod_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub2_wrap_cid_cod(&bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub2_wrap_cid_cod(&cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cid_coe_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub2_wrap_cid_coe(&buia, &buib, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub2_wrap_cid_coe(&cuia, &cuib, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cid_coe_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub2_wrap_cid_coe(&bui, &bui, &cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub2_wrap_cid_coe(&cui, &cui, &cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cie_cod_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub2_wrap_cie_cod(&buia, &buib, cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub2_wrap_cie_cod(&cuia, &cuib, cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cie_cod_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 == 0;
		cfb = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub2_wrap_cie_cod(&bui, &bui, cfa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub2_wrap_cie_cod(&cui, &cui, cfb);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cfa == cfb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cie_coe_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub2_wrap_cie_coe(&buia, &buib, cia, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub2_wrap_cie_coe(&cuia, &cuib, cib, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cie_coe_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cia mk_lang_constexpr_init;
	mk_lang_types_bool_t cib mk_lang_constexpr_init;
	mk_lang_types_bool_t coa mk_lang_constexpr_init;
	mk_lang_types_bool_t cob mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + 2 * mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cia = data[ptr] % 2 == 0;
		cib = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;
		coa = data[ptr] % 2 == 0;
		cob = data[ptr] % 2 == 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		mk_sl_cui_fuzz_bui_inl_defd_bui_sub2_wrap_cie_coe(&bui, &bui, cia, &coa);
		mk_sl_cui_fuzz_bui_inl_defd_cui_sub2_wrap_cie_coe(&cui, &cui, cib, &cob);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
		mk_lang_test(cia == cib);
		mk_lang_test(coa == cob);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_lo_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul3_wrap_lo(&buia, &buib, &buic);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul3_wrap_lo(&cuia, &cuib, &cuic);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_lo_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul3_wrap_lo(&buia, &buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul3_wrap_lo(&cuia, &cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_lo_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul3_wrap_lo(&buia, &buib, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul3_wrap_lo(&cuia, &cuib, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_lo_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul3_wrap_lo(&buia, &buib, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul3_wrap_lo(&cuia, &cuib, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_lo_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul3_wrap_lo(&bui, &bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul3_wrap_lo(&cui, &cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_hi_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul3_wrap_hi(&buia, &buib, &buic);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul3_wrap_hi(&cuia, &cuib, &cuic);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_hi_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul3_wrap_hi(&buia, &buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul3_wrap_hi(&cuia, &cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_hi_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul3_wrap_hi(&buia, &buib, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul3_wrap_hi(&cuia, &cuib, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_hi_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul3_wrap_hi(&buia, &buib, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul3_wrap_hi(&cuia, &cuib, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_hi_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul3_wrap_hi(&bui, &bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul3_wrap_hi(&cui, &cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abcd(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuid mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 4 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buid, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuid, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul4_wrap_wi(&buia, &buib, &buic, &buid);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul4_wrap_wi(&cuia, &cuib, &cuic, &cuid);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buid, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuid, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_aabc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul4_wrap_wi(&buia, &buia, &buib, &buic);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul4_wrap_wi(&cuia, &cuia, &cuib, &cuic);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abac(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul4_wrap_wi(&buia, &buib, &buia, &buic);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul4_wrap_wi(&cuia, &cuib, &cuia, &cuic);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abca(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul4_wrap_wi(&buia, &buib, &buic, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul4_wrap_wi(&cuia, &cuib, &cuic, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abbc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul4_wrap_wi(&buia, &buib, &buib, &buic);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul4_wrap_wi(&cuia, &cuib, &cuib, &cuic);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abcb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul4_wrap_wi(&buia, &buib, &buic, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul4_wrap_wi(&cuia, &cuib, &cuic, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul4_wrap_wi(&buia, &buib, &buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul4_wrap_wi(&cuia, &cuib, &cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul4_wrap_wi(&buia, &buib, &buib, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul4_wrap_wi(&cuia, &cuib, &cuib, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_aaab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul4_wrap_wi(&buia, &buia, &buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul4_wrap_wi(&cuia, &cuia, &cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_aaba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul4_wrap_wi(&buia, &buia, &buib, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul4_wrap_wi(&cuia, &cuia, &cuib, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul2_wrap_lo_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul2_wrap_lo(&buia, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul2_wrap_lo(&cuia, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul2_wrap_lo_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul2_wrap_lo(&bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul2_wrap_lo(&cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul2_wrap_hi_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul2_wrap_hi(&buia, &buia);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul2_wrap_hi(&cuia, &cuia);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul2_wrap_hi_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul2_wrap_hi(&bui, &bui);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul2_wrap_hi(&cui, &cui);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mul2_wrap_wi_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		mk_sl_cui_fuzz_bui_inl_defd_bui_mul2_wrap_hi(&buia, &buib);
		mk_sl_cui_fuzz_bui_inl_defd_cui_mul2_wrap_hi(&cuia, &cuib);

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abcd(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuid mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 4 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buid, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuid, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_divmod4_wrap(&buia, &buib, &buic, &buid);
			mk_sl_cui_fuzz_bui_inl_defd_cui_divmod4_wrap(&cuia, &cuib, &cuic, &cuid);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buid, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuid, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_aabc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buia != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_divmod4_wrap(&buia, &buia, &buib, &buic);
			mk_sl_cui_fuzz_bui_inl_defd_cui_divmod4_wrap(&cuia, &cuia, &cuib, &cuic);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abac(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_divmod4_wrap(&buia, &buib, &buia, &buic);
			mk_sl_cui_fuzz_bui_inl_defd_cui_divmod4_wrap(&cuia, &cuib, &cuia, &cuic);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abca(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_divmod4_wrap(&buia, &buib, &buic, &buia);
			mk_sl_cui_fuzz_bui_inl_defd_cui_divmod4_wrap(&cuia, &cuib, &cuic, &cuia);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abbc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_divmod4_wrap(&buia, &buib, &buib, &buic);
			mk_sl_cui_fuzz_bui_inl_defd_cui_divmod4_wrap(&cuia, &cuib, &cuib, &cuic);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abcb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_divmod4_wrap(&buia, &buib, &buic, &buib);
			mk_sl_cui_fuzz_bui_inl_defd_cui_divmod4_wrap(&cuia, &cuib, &cuic, &cuib);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_divmod4_wrap(&buia, &buib, &buia, &buib);
			mk_sl_cui_fuzz_bui_inl_defd_cui_divmod4_wrap(&cuia, &cuib, &cuia, &cuib);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_divmod4_wrap(&buia, &buib, &buib, &buia);
			mk_sl_cui_fuzz_bui_inl_defd_cui_divmod4_wrap(&cuia, &cuib, &cuib, &cuia);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_aaab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buia != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_divmod4_wrap(&buia, &buia, &buia, &buib);
			mk_sl_cui_fuzz_bui_inl_defd_cui_divmod4_wrap(&cuia, &cuia, &cuia, &cuib);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_aaba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buia != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_divmod4_wrap(&buia, &buia, &buib, &buia);
			mk_sl_cui_fuzz_bui_inl_defd_cui_divmod4_wrap(&cuia, &cuia, &cuib, &cuia);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_div3_wrap_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_div3_wrap(&buia, &buib, &buic);
			mk_sl_cui_fuzz_bui_inl_defd_cui_div3_wrap(&cuia, &cuib, &cuic);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_div3_wrap_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buia != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_div3_wrap(&buia, &buia, &buib);
			mk_sl_cui_fuzz_bui_inl_defd_cui_div3_wrap(&cuia, &cuia, &cuib);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_div3_wrap_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_div3_wrap(&buia, &buib, &buia);
			mk_sl_cui_fuzz_bui_inl_defd_cui_div3_wrap(&cuia, &cuib, &cuia);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_div3_wrap_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_div3_wrap(&buia, &buib, &buib);
			mk_sl_cui_fuzz_bui_inl_defd_cui_div3_wrap(&cuia, &cuib, &cuib);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_div3_wrap_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(bui != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_div3_wrap(&bui, &bui, &bui);
			mk_sl_cui_fuzz_bui_inl_defd_cui_div3_wrap(&cui, &cui, &cui);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mod3_wrap_abc(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuic mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 3 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buic, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuic, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_mod3_wrap(&buia, &buib, &buic);
			mk_sl_cui_fuzz_bui_inl_defd_cui_mod3_wrap(&cuia, &cuib, &cuic);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buic, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuic, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mod3_wrap_aab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buia != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_mod3_wrap(&buia, &buia, &buib);
			mk_sl_cui_fuzz_bui_inl_defd_cui_mod3_wrap(&cuia, &cuia, &cuib);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mod3_wrap_aba(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_mod3_wrap(&buia, &buib, &buia);
			mk_sl_cui_fuzz_bui_inl_defd_cui_mod3_wrap(&cuia, &cuib, &cuia);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mod3_wrap_abb(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_mod3_wrap(&buia, &buib, &buib);
			mk_sl_cui_fuzz_bui_inl_defd_cui_mod3_wrap(&cuia, &cuib, &cuib);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mod3_wrap_aaa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(bui != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_mod3_wrap(&bui, &bui, &bui);
			mk_sl_cui_fuzz_bui_inl_defd_cui_mod3_wrap(&cui, &cui, &cui);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_div2_wrap_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_div2_wrap(&buia, &buib);
			mk_sl_cui_fuzz_bui_inl_defd_cui_div2_wrap(&cuia, &cuib);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_div2_wrap_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(bui != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_div2_wrap(&bui, &bui);
			mk_sl_cui_fuzz_bui_inl_defd_cui_div2_wrap(&cui, &cui);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mod2_wrap_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_mod2_wrap(&buia, &buib);
			mk_sl_cui_fuzz_bui_inl_defd_cui_mod2_wrap(&cuia, &cuib);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_mod2_wrap_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(bui != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_mod2_wrap(&bui, &bui);
			mk_sl_cui_fuzz_bui_inl_defd_cui_mod2_wrap(&cui, &cui);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_divmod2_wrap_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		if(buib != 0)
		{
			mk_sl_cui_fuzz_bui_inl_defd_bui_divmod2_wrap(&buia, &buib);
			mk_sl_cui_fuzz_bui_inl_defd_cui_divmod2_wrap(&cuia, &cuib);
		}

		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_add_cc_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_add_cc(&buia, &buib);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_add_cc(&cuia, &cuib);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_add_cc_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_add_cc(&bui, &bui);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_add_cc(&cui, &cui);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_add_cs_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_add_cs(&buia, &buib);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_add_cs(&cuia, &cuib);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_add_cs_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_add_cs(&bui, &bui);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_add_cs(&cui, &cui);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_add_cp_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 != 0;
		cfb = data[ptr] % 2 != 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_add_cp(&buia, &buib, cfa);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_add_cp(&cuia, &cuib, cfb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_add_cp_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 != 0;
		cfb = data[ptr] % 2 != 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_add_cp(&bui, &bui, cfa);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_add_cp(&cui, &cui, cfb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_sub_cc_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_sub_cc(&buia, &buib);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_sub_cc(&cuia, &cuib);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_sub_cc_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_sub_cc(&bui, &bui);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_sub_cc(&cui, &cui);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_sub_cs_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_sub_cs(&buia, &buib);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_sub_cs(&cuia, &cuib);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_sub_cs_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_sub_cs(&bui, &bui);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_sub_cs(&cui, &cui);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_sub_cp_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 != 0;
		cfb = data[ptr] % 2 != 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_sub_cp(&buia, &buib, cfa);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_sub_cp(&cuia, &cuib, cfb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_sub_cp_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t cfa mk_lang_constexpr_init;
	mk_lang_types_bool_t cfb mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v + mk_lang_sizeof_bi_bool_t)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		cfa = data[ptr] % 2 != 0;
		cfb = data[ptr] % 2 != 0;
		ptr += mk_lang_sizeof_bi_bool_t;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_sub_cp(&bui, &bui, cfa);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_sub_cp(&cui, &cui, cfb);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_mul_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_mul(&buia, &buib);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_mul(&cuia, &cuib);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_mul_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_mul(&bui, &bui);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_mul(&cui, &cui);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_div_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_div(&buia, &buib);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_div(&cuia, &cuib);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_div_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_div(&bui, &bui);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_div(&cui, &cui);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_mod_ab(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t buib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cuib mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 2 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buia, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuia, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&buib, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cuib, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_mod(&buia, &buib);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_mod(&cuia, &cuib);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buia, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuia, &rb);
		mk_lang_test(ra == rb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&buib, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cuib, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_mod_aa(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size >= 1 * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v)
	{
		ptr = 0;
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &data[ptr]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &data[ptr]);
		ptr += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;

		ba = mk_sl_cui_fuzz_bui_inl_defd_bui_would_overflow_mod(&bui, &bui);
		bb = mk_sl_cui_fuzz_bui_inl_defd_cui_would_overflow_mod(&cui, &cui);

		mk_lang_test(ba == bb);
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &ra);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &rb);
		mk_lang_test(ra == rb);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_bin_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &d[0]);
	d += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_bin_n(&bui, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_bin_n(&cui, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
	mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
	mk_lang_test(r_c == r_b);
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_bin_n(&bui2, &str_buf_b[0], len_b);
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_bin_n(&cui2, &str_buf_c[0], len_c);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_bin_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &d[0]);
	d += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_bin_w(&bui, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_bin_w(&cui, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
	mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
	mk_lang_test(r_c == r_b);
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_bin_w(&bui2, &str_buf_b[0], len_b);
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_bin_w(&cui2, &str_buf_c[0], len_c);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_oct_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &d[0]);
	d += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_oct_n(&bui, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_oct_n(&cui, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
	mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
	mk_lang_test(r_c == r_b);
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_oct_n(&bui2, &str_buf_b[0], len_b);
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_oct_n(&cui2, &str_buf_c[0], len_c);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_oct_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &d[0]);
	d += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_oct_w(&bui, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_oct_w(&cui, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
	mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
	mk_lang_test(r_c == r_b);
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_oct_w(&bui2, &str_buf_b[0], len_b);
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_oct_w(&cui2, &str_buf_c[0], len_c);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_dec_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &d[0]);
	d += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_dec_n(&bui, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_dec_n(&cui, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
	mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
	mk_lang_test(r_c == r_b);
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_dec_n(&bui2, &str_buf_b[0], len_b);
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_dec_n(&cui2, &str_buf_c[0], len_c);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_dec_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &d[0]);
	d += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_dec_w(&bui, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_dec_w(&cui, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
	mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
	mk_lang_test(r_c == r_b);
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_dec_w(&bui2, &str_buf_b[0], len_b);
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_dec_w(&cui2, &str_buf_c[0], len_c);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_hex_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &d[0]);
	d += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_hex_n(&bui, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_hex_n(&cui, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
	mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
	mk_lang_test(r_c == r_b);
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_n(&bui2, &str_buf_b[0], len_b);
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_n(&cui2, &str_buf_c[0], len_c);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_hex_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &d[0]);
	d += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_hex_w(&bui, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_hex_w(&cui, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
	mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
	mk_lang_test(r_c == r_b);
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_w(&bui2, &str_buf_b[0], len_b);
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_w(&cui2, &str_buf_c[0], len_c);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_binf_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &d[0]);
	d += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_binf_n(&bui, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_binf_n(&cui, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
	mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
	mk_lang_test(r_c == r_b);
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_bin_n(&bui2, &str_buf_b[0], len_b);
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_bin_n(&cui2, &str_buf_c[0], len_c);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_binf_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &d[0]);
	d += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_binf_w(&bui, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_binf_w(&cui, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
	mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
	mk_lang_test(r_c == r_b);
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_bin_w(&bui2, &str_buf_b[0], len_b);
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_bin_w(&cui2, &str_buf_c[0], len_c);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_hexf_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &d[0]);
	d += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_hexf_n(&bui, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_hexf_n(&cui, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
	mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
	mk_lang_test(r_c == r_b);
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_n(&bui2, &str_buf_b[0], len_b);
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_n(&cui2, &str_buf_c[0], len_c);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_hexf_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui, &d[0]);
	d += mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_hexf_w(&bui, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_hexf_w(&cui, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
	mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
	mk_lang_test(r_c == r_b);
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_w(&bui2, &str_buf_b[0], len_b);
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_w(&cui2, &str_buf_c[0], len_c);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_hexf_many_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t count mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui[64] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui[mk_lang_countof(bui)] mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[2 * mk_lang_countof(bui) * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2[mk_lang_countof(bui)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2[mk_lang_countof(bui)] mk_lang_constexpr_init;

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
	count = count % mk_lang_countof(bui);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	if(!(s >= count * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	n = ((mk_lang_types_sint_t)(count));
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui[i], &d[i * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui[i], &d[i * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
	}
	d += ((mk_lang_types_usize_t)(n)) * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= ((mk_lang_types_usize_t)(n)) * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_hexf_many_n(&bui[0], n, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_hexf_many_n(&cui[0], n, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui[i], &r_b);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui[i], &r_c);
		mk_lang_test(r_c == r_b);
	}
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		for(i = 0; i != n; ++i)
		{
			len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_n(&bui2[i], &str_buf_b[i * mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_hex_v], mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_hex_v);
			len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_n(&cui2[i], &str_buf_c[i * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v], mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v);
			mk_lang_test(len_c2 == len_b2);
			mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2[i], &bui[i]));
			mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2[i], &cui[i]));
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_hexf_many_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t count mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui[64] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui[mk_lang_countof(bui)] mk_lang_constexpr_init;
	mk_lang_types_ulong_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[2 * mk_lang_countof(bui) * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_c[mk_lang_countof(str_buf_b)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2[mk_lang_countof(bui)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2[mk_lang_countof(bui)] mk_lang_constexpr_init;

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
	count = count % mk_lang_countof(bui);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	if(!(s >= count * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v))
	{
		return;
	}
	n = ((mk_lang_types_sint_t)(count));
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_from_buis_uchar_le(&bui[i], &d[i * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
		mk_sl_cui_fuzz_bui_inl_defd_cui_from_buis_uchar_le(&cui[i], &d[i * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v]);
	}
	d += ((mk_lang_types_usize_t)(n)) * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	s -= ((mk_lang_types_usize_t)(n)) * mk_sl_cui_fuzz_bui_inl_defd_cui_size_bytes_v;
	if(!(s >= mk_lang_sizeof_bi_ulong_t))
	{
		return;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&str_len, &d[0]);
	d += mk_lang_sizeof_bi_ulong_t;
	s -= mk_lang_sizeof_bi_ulong_t;
	str_len = str_len % mk_lang_countof(str_buf_b);

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_hexf_many_w(&bui[0], n, &str_buf_b[0], ((mk_lang_types_sint_t)(str_len)));
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_hexf_many_w(&cui[0], n, &str_buf_c[0], ((mk_lang_types_sint_t)(str_len)));

	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui[i], &r_b);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui[i], &r_c);
		mk_lang_test(r_c == r_b);
	}
	mk_lang_test(len_c == len_b);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b))) == 0);

	if(len_b != 0)
	{
		for(i = 0; i != n; ++i)
		{
			len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_w(&bui2[i], &str_buf_b[i * mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_hex_v], mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_hex_v);
			len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_w(&cui2[i], &str_buf_c[i * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v], mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v);
			mk_lang_test(len_c2 == len_b2);
			mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2[i], &bui[i]));
			mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2[i], &cui[i]));
		}
	}
}

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_bin_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

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
	str_len = ((mk_lang_types_sint_t)(tul % mk_lang_countof(str_buf)));
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

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_bin_n(&bui, &str_buf[0], str_len);
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_bin_n(&cui, &str_buf[0], str_len);

	mk_lang_test(len_c == len_b);
	if(len_b >= 1)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
		mk_lang_test(r_c == r_b);
	}

	if(len_b >= 1)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_bin_n(&bui, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_b));
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_bin_n(&cui, &str_buf_c[0], mk_lang_min(mk_lang_countof(str_buf_c), len_c));
		mk_lang_test(len_b2 >= 1);
		mk_lang_test(len_c2 >= 1);
		mk_lang_test(len_b2 <= len_b);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(len_c2 <= len_c);
		mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b2))) == 0);

		len_b3 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_bin_n(&bui2, &str_buf_b[0], len_b2);
		len_c3 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_bin_n(&cui2, &str_buf_c[0], len_c2);
		mk_lang_test(len_c3 == len_b3);
		mk_lang_test(len_b3 == len_b2);
		mk_lang_test(len_c3 == len_c2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_bin_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_type_traits_to_unsigned_wchar_t tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_c[mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_bin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

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
	str_len = ((mk_lang_types_sint_t)(tul % mk_lang_countof(str_buf)));
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

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_bin_w(&bui, &str_buf[0], str_len);
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_bin_w(&cui, &str_buf[0], str_len);

	mk_lang_test(len_c == len_b);
	if(len_b >= 1)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
		mk_lang_test(r_c == r_b);
	}

	if(len_b >= 1)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_bin_w(&bui, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_b));
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_bin_w(&cui, &str_buf_c[0], mk_lang_min(mk_lang_countof(str_buf_c), len_c));
		mk_lang_test(len_b2 >= 1);
		mk_lang_test(len_c2 >= 1);
		mk_lang_test(len_b2 <= len_b);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(len_c2 <= len_c);
		mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b2))) == 0);

		len_b3 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_bin_w(&bui2, &str_buf_b[0], len_b2);
		len_c3 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_bin_w(&cui2, &str_buf_c[0], len_c2);
		mk_lang_test(len_c3 == len_b3);
		mk_lang_test(len_b3 == len_b2);
		mk_lang_test(len_c3 == len_c2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_oct_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

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
	str_len = ((mk_lang_types_sint_t)(tul % mk_lang_countof(str_buf)));
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

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_oct_n(&bui, &str_buf[0], str_len);
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_oct_n(&cui, &str_buf[0], str_len);

	mk_lang_test(len_c == len_b);
	if(len_b >= 1)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
		mk_lang_test(r_c == r_b);
	}

	if(len_b >= 1)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_oct_n(&bui, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_b));
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_oct_n(&cui, &str_buf_c[0], mk_lang_min(mk_lang_countof(str_buf_c), len_c));
		mk_lang_test(len_b2 >= 1);
		mk_lang_test(len_c2 >= 1);
		mk_lang_test(len_b2 <= len_b);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(len_c2 <= len_c);
		mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b2))) == 0);

		len_b3 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_oct_n(&bui2, &str_buf_b[0], len_b2);
		len_c3 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_oct_n(&cui2, &str_buf_c[0], len_c2);
		mk_lang_test(len_c3 == len_b3);
		mk_lang_test(len_b3 == len_b2);
		mk_lang_test(len_c3 == len_c2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_oct_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_type_traits_to_unsigned_wchar_t tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_c[mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_oct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

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
	str_len = ((mk_lang_types_sint_t)(tul % mk_lang_countof(str_buf)));
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

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_oct_w(&bui, &str_buf[0], str_len);
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_oct_w(&cui, &str_buf[0], str_len);

	mk_lang_test(len_c == len_b);
	if(len_b >= 1)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
		mk_lang_test(r_c == r_b);
	}

	if(len_b >= 1)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_oct_w(&bui, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_b));
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_oct_w(&cui, &str_buf_c[0], mk_lang_min(mk_lang_countof(str_buf_c), len_c));
		mk_lang_test(len_b2 >= 1);
		mk_lang_test(len_c2 >= 1);
		mk_lang_test(len_b2 <= len_b);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(len_c2 <= len_c);
		mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b2))) == 0);

		len_b3 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_oct_w(&bui2, &str_buf_b[0], len_b2);
		len_c3 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_oct_w(&cui2, &str_buf_c[0], len_c2);
		mk_lang_test(len_c3 == len_b3);
		mk_lang_test(len_b3 == len_b2);
		mk_lang_test(len_c3 == len_c2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_dec_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

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
	str_len = ((mk_lang_types_sint_t)(tul % mk_lang_countof(str_buf)));
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

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_dec_n(&bui, &str_buf[0], str_len);
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_dec_n(&cui, &str_buf[0], str_len);

	mk_lang_test(len_c == len_b);
	if(len_b >= 1)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
		mk_lang_test(r_c == r_b);
	}

	if(len_b >= 1)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_dec_n(&bui, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_b));
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_dec_n(&cui, &str_buf_c[0], mk_lang_min(mk_lang_countof(str_buf_c), len_c));
		mk_lang_test(len_b2 >= 1);
		mk_lang_test(len_c2 >= 1);
		mk_lang_test(len_b2 <= len_b);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(len_c2 <= len_c);
		mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b2))) == 0);

		len_b3 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_dec_n(&bui2, &str_buf_b[0], len_b2);
		len_c3 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_dec_n(&cui2, &str_buf_c[0], len_c2);
		mk_lang_test(len_c3 == len_b3);
		mk_lang_test(len_b3 == len_b2);
		mk_lang_test(len_c3 == len_c2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_dec_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_type_traits_to_unsigned_wchar_t tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_c[mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

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
	str_len = ((mk_lang_types_sint_t)(tul % mk_lang_countof(str_buf)));
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

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_dec_w(&bui, &str_buf[0], str_len);
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_dec_w(&cui, &str_buf[0], str_len);

	mk_lang_test(len_c == len_b);
	if(len_b >= 1)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
		mk_lang_test(r_c == r_b);
	}

	if(len_b >= 1)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_dec_w(&bui, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_b));
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_dec_w(&cui, &str_buf_c[0], mk_lang_min(mk_lang_countof(str_buf_c), len_c));
		mk_lang_test(len_b2 >= 1);
		mk_lang_test(len_c2 >= 1);
		mk_lang_test(len_b2 <= len_b);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(len_c2 <= len_c);
		mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b2))) == 0);

		len_b3 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_dec_w(&bui2, &str_buf_b[0], len_b2);
		len_c3 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_dec_w(&cui2, &str_buf_c[0], len_c2);
		mk_lang_test(len_c3 == len_b3);
		mk_lang_test(len_b3 == len_b2);
		mk_lang_test(len_c3 == len_c2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_hex_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_b[mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

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
	str_len = ((mk_lang_types_sint_t)(tul % mk_lang_countof(str_buf)));
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

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_n(&bui, &str_buf[0], str_len);
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_n(&cui, &str_buf[0], str_len);

	mk_lang_test(len_c == len_b);
	if(len_b >= 1)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
		mk_lang_test(r_c == r_b);
	}

	if(len_b >= 1)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_hex_n(&bui, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_b));
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_hex_n(&cui, &str_buf_c[0], mk_lang_min(mk_lang_countof(str_buf_c), len_c));
		mk_lang_test(len_b2 >= 1);
		mk_lang_test(len_c2 >= 1);
		mk_lang_test(len_b2 <= len_b);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(len_c2 <= len_c);
		mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b2))) == 0);

		len_b3 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_n(&bui2, &str_buf_b[0], len_b2);
		len_c3 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_n(&cui2, &str_buf_c[0], len_c2);
		mk_lang_test(len_c3 == len_b3);
		mk_lang_test(len_b3 == len_b2);
		mk_lang_test(len_c3 == len_c2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_hex_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf[2 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_type_traits_to_unsigned_wchar_t tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b2 mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_b[mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c2 mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf_c[mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2 mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c3 mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2 mk_lang_constexpr_init;

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
	str_len = ((mk_lang_types_sint_t)(tul % mk_lang_countof(str_buf)));
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

	len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_w(&bui, &str_buf[0], str_len);
	len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_w(&cui, &str_buf[0], str_len);

	mk_lang_test(len_c == len_b);
	if(len_b >= 1)
	{
		mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui, &r_b);
		mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui, &r_c);
		mk_lang_test(r_c == r_b);
	}

	if(len_b >= 1)
	{
		len_b2 = mk_sl_cui_fuzz_bui_inl_defd_bui_to_str_hex_w(&bui, &str_buf_b[0], mk_lang_min(mk_lang_countof(str_buf_b), len_b));
		len_c2 = mk_sl_cui_fuzz_bui_inl_defd_cui_to_str_hex_w(&cui, &str_buf_c[0], mk_lang_min(mk_lang_countof(str_buf_c), len_c));
		mk_lang_test(len_b2 >= 1);
		mk_lang_test(len_c2 >= 1);
		mk_lang_test(len_b2 <= len_b);
		mk_lang_test(len_c2 == len_b2);
		mk_lang_test(len_c2 <= len_c);
		mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_buf_c[0], &str_buf_b[0], ((mk_lang_types_usize_t)(len_b2))) == 0);

		len_b3 = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_w(&bui2, &str_buf_b[0], len_b2);
		len_c3 = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_w(&cui2, &str_buf_c[0], len_c2);
		mk_lang_test(len_c3 == len_b3);
		mk_lang_test(len_b3 == len_b2);
		mk_lang_test(len_c3 == len_c2);
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2, &bui));
		mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2, &cui));
	}
}
#include "mk_lang_warning_msvc_pop.h"

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_hex_many_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t tui mk_lang_constexpr_init;
	mk_lang_types_sint_t count mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[64 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2[64] mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;

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
	str_len = count * mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_hex_v;
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
	len_b = 0;
	len_c = 0;
	n = count;
	for(i = 0; i != n; ++i)
	{
		len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_n(&bui[i], &str_buf[i * mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_bin_v], mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_bin_v);
		len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_n(&cui[i], &str_buf[i * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v], mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v);
		mk_lang_assert(len_c == len_b);
		if(len_b != mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v)
		{
			break;
		}
	}

	if(len_b == mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v)
	{
		len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_many_n(&bui2[0], count, &str_buf[0], str_len);
		len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_many_n(&cui2[0], count, &str_buf[0], str_len);
		mk_lang_test(len_c == len_b);
		mk_lang_test(len_c == count * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v);
		n = count;
		for(i = 0; i != n; ++i)
		{
			mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2[i], &bui[i]));
			mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2[i], &cui[i]));
			mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui2[i], &r_b);
			mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui2[i], &r_c);
			mk_lang_test(r_c == r_b);
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_hex_many_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t tui mk_lang_constexpr_init;
	mk_lang_types_sint_t count mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_type_traits_to_unsigned_wchar_t tmp mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buf[64 * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui[64] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_bui_t bui2[64] mk_lang_constexpr_init;
	mk_sl_cui_fuzz_bui_inl_defd_cui_t cui2[64] mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_b mk_lang_constexpr_init;
	mk_lang_types_ulllong_t r_c mk_lang_constexpr_init;

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
	str_len = count * mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_hex_v;
	if(!(s >= ((mk_lang_types_usize_t)(str_len)) * mk_lang_bui_wchar_size_bytes_v))
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
	len_b = 0;
	len_c = 0;
	n = count;
	for(i = 0; i != n; ++i)
	{
		len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_w(&bui[i], &str_buf[i * mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_bin_v], mk_sl_cui_fuzz_bui_inl_defd_bui_strlen_bin_v);
		len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_w(&cui[i], &str_buf[i * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v], mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v);
		mk_lang_assert(len_c == len_b);
		if(len_b != mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v)
		{
			break;
		}
	}

	if(len_b == mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v)
	{
		len_b = mk_sl_cui_fuzz_bui_inl_defd_bui_from_str_hex_many_w(&bui2[0], count, &str_buf[0], str_len);
		len_c = mk_sl_cui_fuzz_bui_inl_defd_cui_from_str_hex_many_w(&cui2[0], count, &str_buf[0], str_len);
		mk_lang_test(len_c == len_b);
		mk_lang_test(len_c == count * mk_sl_cui_fuzz_bui_inl_defd_cui_strlen_hex_v);
		n = count;
		for(i = 0; i != n; ++i)
		{
			mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_bui_eq(&bui2[i], &bui[i]));
			mk_lang_test(mk_sl_cui_fuzz_bui_inl_defd_cui_eq(&cui2[i], &cui[i]));
			mk_sl_cui_fuzz_bui_inl_defd_bui_to_bi_ulllong(&bui2[i], &r_b);
			mk_sl_cui_fuzz_bui_inl_defd_cui_to_bi_ulllong(&cui2[i], &r_c);
			mk_lang_test(r_c == r_b);
		}
	}
}


mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_fuzz_bui_inl_defd_fn(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size, mk_lang_types_bool_t const allow_all) mk_lang_noexcept
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
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_statics(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_bool(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_pchar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_wchar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_uchar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_schar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_ushort(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_sshort(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_uint(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_sint(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_ulong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_slong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_ullong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_sllong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_ulllong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_slllong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_uintptr(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_sintptr(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_uintmax(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_sintmax(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_usize(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_bi_ssize(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_bool(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_pchar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_wchar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_uchar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_schar(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_ushort(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_sshort(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_uint(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_sint(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_ulong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_slong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_ullong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_sllong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_ulllong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_slllong(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_uintptr(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_sintptr(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_uintmax(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_sintmax(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_usize(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_bi_ssize(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_assign_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_assign_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_set_zero(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_set_max(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_set_one(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_set_one(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_set_bit(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_set_mask(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_count_leading_zeros(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_count_leading_ones(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_count_trailing_zeros(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_count_trailing_ones(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_count_zeros(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_count_ones(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_has_msb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_has_lsb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_is_zero(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_is_one(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_is_two(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_is_max(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_is_bit(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_eq(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_ne(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_lt(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_le(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_gt(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_ge(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_cmp(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_inc1(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_dec1(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_inc2_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_inc2_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_dec2_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_dec2_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_not1(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_not2_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_not2_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_or2_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_or2_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_and2_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_and2_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_xor2_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_xor2_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_or3_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_or3_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_or3_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_or3_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_or3_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_and3_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_and3_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_and3_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_and3_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_and3_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_xor3_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_xor3_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_xor3_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_xor3_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_xor3_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_shl2(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_shl3_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_shl3_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_shr2(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_shr3_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_shr3_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_rotl2(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_rotl3_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_rotl3_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_rotr2(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_rotr3_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_rotr3_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_cod_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_cod_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_cod_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_cod_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_cod_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_coe_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_coe_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_coe_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_coe_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cid_coe_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_cod_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_cod_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_cod_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_cod_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_cod_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_coe_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_coe_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_coe_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_coe_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add3_wrap_cie_coe_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cid_cod_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cid_cod_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cid_coe_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cid_coe_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cie_cod_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cie_cod_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cie_coe_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_add2_wrap_cie_coe_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_cod_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_cod_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_cod_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_cod_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_cod_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_coe_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_coe_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_coe_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_coe_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cid_coe_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_cod_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_cod_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_cod_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_cod_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_cod_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_coe_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_coe_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_coe_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_coe_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub3_wrap_cie_coe_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cid_cod_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cid_cod_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cid_coe_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cid_coe_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cie_cod_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cie_cod_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cie_coe_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_sub2_wrap_cie_coe_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_lo_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_lo_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_lo_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_lo_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_lo_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_hi_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_hi_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_hi_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_hi_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul3_wrap_hi_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abcd(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_aabc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abac(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abca(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abbc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abcb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_abba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_aaab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul4_wrap_wi_aaba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul2_wrap_lo_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul2_wrap_lo_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul2_wrap_hi_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul2_wrap_hi_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mul2_wrap_wi_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abcd(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_aabc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abac(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abca(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abbc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abcb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_abba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_aaab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_divmod4_wrap_aaba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_div3_wrap_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_div3_wrap_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_div3_wrap_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_div3_wrap_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_div3_wrap_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mod3_wrap_abc(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mod3_wrap_aab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mod3_wrap_aba(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mod3_wrap_abb(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mod3_wrap_aaa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_div2_wrap_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_div2_wrap_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mod2_wrap_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_mod2_wrap_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_divmod2_wrap_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_add_cc_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_add_cc_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_add_cs_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_add_cs_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_add_cp_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_add_cp_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_sub_cc_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_sub_cc_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_sub_cs_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_sub_cs_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_sub_cp_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_sub_cp_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_mul_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_mul_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_div_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_div_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_mod_ab(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_would_overflow_mod_aa(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_bin_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_bin_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_oct_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_oct_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_dec_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_dec_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_hex_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_hex_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_binf_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_binf_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_hexf_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_hexf_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_hexf_many_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_to_str_hexf_many_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_bin_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_bin_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_oct_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_oct_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_dec_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_dec_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_hex_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_hex_w(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_hex_many_n(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui_inl_defd_pr_from_str_hex_many_w(d, s); }
}


#include "mk_sl_cui_fuzz_bui_inl_defu.h"
