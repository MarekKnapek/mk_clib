#ifndef mk_include_guard_mk_sl_buffers_h
#define mk_include_guard_mk_sl_buffers_h


#include "mk_lang_alignas.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_vector.h"


#define mk_sl_buffers_buffer_size_d (64 * 1024)
union mk_sl_buffers_buffer_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_sl_buffers_buffer_size_d];
	mk_lang_types_uchar_t m_uchars[mk_sl_buffers_buffer_size_d];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_sl_buffers_buffer_data_u mk_sl_buffers_buffer_data_t;
struct mk_sl_buffers_buffer_s
{
	mk_lang_alignas(sizeof(mk_sl_buffers_buffer_data_t)) mk_sl_buffers_buffer_data_t m_data;
};
typedef struct mk_sl_buffers_buffer_s mk_sl_buffers_buffer_t;
mk_lang_typedef(mk_sl_buffers_buffer);


struct mk_sl_buffers_s
{
	mk_sl_vector_vp_t m_blocks;
	mk_sl_buffers_buffer_pt m_free_list;
};
typedef struct mk_sl_buffers_s mk_sl_buffers_t;
mk_lang_typedef(mk_sl_buffers);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_buffers_rw_construct(mk_sl_buffers_pt const buffers) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_buffers_rw_destroy(mk_sl_buffers_pt const buffers) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_buffers_rw_allocate_one(mk_sl_buffers_pt const buffers, mk_sl_buffers_buffer_ppt const buffer) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_buffers_rw_deallocate_one(mk_sl_buffers_pt const buffers, mk_sl_buffers_buffer_pt const buffer) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_buffers.c"
#endif
#endif
