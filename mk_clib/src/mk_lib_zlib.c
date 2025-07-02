#ifndef mk_include_guard_mk_lib_zlib_c
#define mk_include_guard_mk_lib_zlib_c
#include "mk_lib_zlib.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_sl_cui_uint8.h"





#include "mk_lang_concat.h"

#define mk_lang_function_define_2_cpp17(name, ret_type, arg_1, arg_2) typedef ret_type(*mk_lang_concat(name, _t))(arg_1, arg_2) mk_lang_noexcept
#define mk_lang_function_define_3_cpp17(name, ret_type, arg_1, arg_2, arg_3) typedef ret_type(*mk_lang_concat(name, _t))(arg_1, arg_2, arg_3) mk_lang_noexcept
#define mk_lang_function_define_2_cpp11(name, ret_type, arg_1, arg_2) ret_type mk_lang_concat(name, _dummy)(arg_1, arg_2) mk_lang_noexcept; typedef decltype(&mk_lang_concat(name, _dummy)) mk_lang_concat(name, _t)
#define mk_lang_function_define_3_cpp11(name, ret_type, arg_1, arg_2, arg_3) ret_type mk_lang_concat(name, _dummy)(arg_1, arg_2, arg_3) mk_lang_noexcept; typedef decltype(&mk_lang_concat(name, _dummy)) mk_lang_concat(name, _t)
#define mk_lang_function_define_2_c(name, ret_type, arg_1, arg_2) typedef ret_type(*mk_lang_concat(name, _t))(arg_1, arg_2)
#define mk_lang_function_define_3_c(name, ret_type, arg_1, arg_2, arg_3) typedef ret_type(*mk_lang_concat(name, _t))(arg_1, arg_2, arg_3)

#if mk_lang_version_at_least_cpp_17
#define mk_lang_function_define_2 mk_lang_function_define_2_cpp17
#define mk_lang_function_define_3 mk_lang_function_define_3_cpp17
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#define mk_lang_function_define_2 mk_lang_function_define_2_cpp11
#define mk_lang_function_define_3 mk_lang_function_define_3_cpp11
#else
#define mk_lang_function_define_2 mk_lang_function_define_2_c
#define mk_lang_function_define_3 mk_lang_function_define_3_c
#endif





#define mk_lib_zlib_version "1.3.1"

enum mk_lib_zlib_flush_e
{
	mk_lib_zlib_flush_e_no_flush      = 0,
	mk_lib_zlib_flush_e_partial_flush = 1,
	mk_lib_zlib_flush_e_sync_flush    = 2,
	mk_lib_zlib_flush_e_full_flush    = 3,
	mk_lib_zlib_flush_e_finish        = 4,
	mk_lib_zlib_flush_e_block         = 5,
	mk_lib_zlib_flush_e_trees         = 6,
	mk_lib_zlib_flush_e_dummy_end
};
typedef enum mk_lib_zlib_flush_e mk_lib_zlib_flush_t;

enum mk_lib_zlib_err_e
{
	mk_lib_zlib_err_e_ok         = 0,
	mk_lib_zlib_err_e_stream_end = 1,
	mk_lib_zlib_err_e_dummy_end
};
typedef enum mk_lib_zlib_err_e mk_lib_zlib_err_t;

enum mk_lib_zlib_method_e
{
	mk_lib_zlib_method_e_deflated = 8,
	mk_lib_zlib_method_e_dummy_end
};
typedef enum mk_lib_zlib_method_e mk_lib_zlib_method_t;

enum mk_lib_zlib_strategy_e
{
	mk_lib_zlib_strategy_e_default = 0,
	mk_lib_zlib_strategy_e_dummy_end
};
typedef enum mk_lib_zlib_strategy_e mk_lib_zlib_strategy_t;

mk_lang_function_define_3(mk_lib_zlib_fn_alloc, mk_lang_types_void_pt, mk_lang_types_void_pt const context, mk_lang_types_uint_t const elements_count, mk_lang_types_uint_t const element_size);
mk_lang_function_define_2(mk_lib_zlib_fn_dealloc, mk_lang_types_void_t, mk_lang_types_void_pt const context, mk_lang_types_void_pt const memory);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_zlib_stream_s
{
	mk_sl_cui_uint8_pct m_next_input_buf;
	mk_lang_types_uint_t m_next_input_len;
	mk_lang_types_ulong_t m_input_total_len;
	mk_sl_cui_uint8_pt m_next_output_buf;
	mk_lang_types_uint_t m_next_output_len;
	mk_lang_types_ulong_t m_output_total_len;
	mk_lang_types_pchar_pct m_err_msg;
	mk_lang_types_void_pt m_internal_state;
	mk_lib_zlib_fn_alloc_t m_allocator;
	mk_lib_zlib_fn_dealloc_t m_deallocator;
	mk_lang_types_void_pt m_context;
	mk_lang_types_sint_t m_data_type;
	mk_lang_types_ulong_t m_adler;
	mk_lang_types_ulong_t m_reserved;
};
typedef struct mk_lib_zlib_stream_s mk_lib_zlib_stream_t;
mk_lang_typedef(mk_lib_zlib_stream);
#include "mk_lang_warning_msvc_pop.h"

mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t inflateInit2_(mk_lib_zlib_stream_pt const stream, mk_lang_types_sint_t const window_bits, mk_lang_types_pchar_pct const version, mk_lang_types_sint_t const stream_size) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t inflate(mk_lib_zlib_stream_pt const stream, mk_lang_types_sint_t const flush) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t inflateEnd(mk_lib_zlib_stream_pt const stream) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t deflateInit2_(mk_lib_zlib_stream_pt const stream, mk_lang_types_sint_t const level, mk_lang_types_sint_t const method, mk_lang_types_sint_t const window_bits, mk_lang_types_sint_t const mem_level, mk_lang_types_sint_t const strategy, mk_lang_types_pchar_pct const version, mk_lang_types_sint_t const stream_size) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t deflate(mk_lib_zlib_stream_pt const stream, mk_lang_types_sint_t const flush) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t deflateEnd(mk_lib_zlib_stream_pt const stream) mk_lang_noexcept;





mk_lang_nodiscard static mk_lang_inline mk_lang_types_void_pt mk_lib_zlib_allocate(mk_lang_types_void_pt const context, mk_lang_types_uint_t const elements_count, mk_lang_types_uint_t const element_size) mk_lang_noexcept
{
	mk_lang_types_usize_t size_real;
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt mem;
	mk_lang_types_usize_pt header;
	mk_lang_types_void_pt user_block;

	((mk_lang_types_void_t)(context));
	size_real = sizeof(mk_lang_types_usize_t) + elements_count * element_size;
	err = mk_lib_iip_cp_mallocator_global_allocate(size_real, &mem); mk_lang_check_recrash(err); mk_lang_assert(mem);
	header = ((mk_lang_types_usize_pt)(mem));
	*header = size_real;
	user_block = ((mk_lang_types_void_pt)(((mk_lang_types_uchar_pt)(mem)) + sizeof(mk_lang_types_usize_t)));
	return user_block;
}

static mk_lang_inline mk_lang_types_void_t mk_lib_zlib_deallocate(mk_lang_types_void_pt const context, mk_lang_types_void_pt const memory) mk_lang_noexcept
{
	mk_lang_types_void_pt mem;
	mk_lang_types_usize_pt header;
	mk_lang_types_usize_t size_real;
	mk_lang_types_sint_t err;

	((mk_lang_types_void_t)(context));
	if(memory)
	{
		mem = ((mk_lang_types_void_pt)(((mk_lang_types_uchar_pt)(memory)) - sizeof(mk_lang_types_usize_t)));
		header = ((mk_lang_types_usize_pt)(mem));
		size_real = *header;
		err = mk_lib_iip_cp_mallocator_global_deallocate(mem, size_real); mk_lang_check_recrash(err);
	}
	return;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_zlib_compress(mk_sl_cui_uint8_pct const src_buf, mk_lang_types_sint_t const src_len, mk_lang_types_sint_t const level, mk_sl_cui_uint8_pt const dst_buf, mk_lang_types_sint_t const dst_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lib_zlib_stream_t stream;
	mk_lang_types_sint_t st;

	mk_lang_assert(src_buf);
	mk_lang_assert(src_len >= 1);
	mk_lang_assert(level >= 0);
	mk_lang_assert(level <= 9);
	mk_lang_assert(dst_buf);
	mk_lang_assert(dst_len >= 1);
	mk_lang_assert(out_len);

	stream.m_allocator = &mk_lib_zlib_allocate;
	stream.m_deallocator = &mk_lib_zlib_deallocate;
	stream.m_context = mk_lang_null;
	st = deflateInit2_(&stream, level, mk_lib_zlib_method_e_deflated, 15 + 16, 9, mk_lib_zlib_strategy_e_default, mk_lib_zlib_version, ((mk_lang_types_sint_t)(sizeof(stream)))); mk_lang_check_return(st == mk_lib_zlib_err_e_ok);
	stream.m_next_input_buf = src_buf;
	stream.m_next_input_len = ((mk_lang_types_uint_t)(src_len));
	stream.m_next_output_buf = dst_buf;
	stream.m_next_output_len = ((mk_lang_types_uint_t)(dst_len));
	st = deflate(&stream, mk_lib_zlib_flush_e_finish); mk_lang_check_return(st == mk_lib_zlib_err_e_stream_end);
	mk_lang_check_return(stream.m_next_input_len == 0);
	mk_lang_check_return(stream.m_input_total_len == ((mk_lang_types_ulong_t)(src_len)));
	mk_lang_check_return(stream.m_output_total_len <= ((mk_lang_types_ulong_t)(dst_len)));
	mk_lang_check_return(((mk_lang_types_uint_t)(dst_len)) - stream.m_output_total_len == stream.m_next_output_len);
	mk_lang_check_return(stream.m_err_msg == mk_lang_null);
	st = deflateEnd(&stream); mk_lang_check_return(st == mk_lib_zlib_err_e_ok);
	*out_len = ((mk_lang_types_sint_t)(stream.m_output_total_len));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_zlib_decompress(mk_sl_cui_uint8_pct const src_buf, mk_lang_types_sint_t const src_len, mk_sl_cui_uint8_pt const dst_buf, mk_lang_types_sint_t const dst_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lib_zlib_stream_t stream;
	mk_lang_types_sint_t st;

	mk_lang_assert(src_buf);
	mk_lang_assert(src_len >= 1);
	mk_lang_assert(dst_buf);
	mk_lang_assert(dst_len >= 1);
	mk_lang_assert(out_len);

	stream.m_allocator = &mk_lib_zlib_allocate;
	stream.m_deallocator = &mk_lib_zlib_deallocate;
	stream.m_context = mk_lang_null;
	st = inflateInit2_(&stream, 15 + 32, mk_lib_zlib_version, ((mk_lang_types_sint_t)(sizeof(stream)))); mk_lang_check_return(st == mk_lib_zlib_err_e_ok);
	stream.m_next_input_buf = src_buf;
	stream.m_next_input_len = ((mk_lang_types_uint_t)(src_len));
	stream.m_next_output_buf = dst_buf;
	stream.m_next_output_len = ((mk_lang_types_uint_t)(dst_len));
	st = inflate(&stream, mk_lib_zlib_flush_e_finish); mk_lang_check_return(st == mk_lib_zlib_err_e_stream_end);
	mk_lang_check_return(stream.m_next_input_len == 0);
	mk_lang_check_return(stream.m_input_total_len == ((mk_lang_types_ulong_t)(src_len)));
	mk_lang_check_return(stream.m_output_total_len <= ((mk_lang_types_ulong_t)(dst_len)));
	mk_lang_check_return(((mk_lang_types_uint_t)(dst_len)) - stream.m_output_total_len == stream.m_next_output_len);
	mk_lang_check_return(stream.m_err_msg == mk_lang_null);
	st = inflateEnd(&stream); mk_lang_check_return(st == mk_lib_zlib_err_e_ok);
	*out_len = ((mk_lang_types_sint_t)(stream.m_output_total_len));
	return 0;
}


#endif
