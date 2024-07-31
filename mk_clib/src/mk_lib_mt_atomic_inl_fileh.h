#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_mt_memory_order.h"


#include "mk_lib_mt_atomic_inl_defd.h"


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#define mk_lib_mt_atomic_portable_cpp_t_name mk_lib_mt_atomic_inl_defd_base
#define mk_lib_mt_atomic_portable_cpp_t_type mk_lib_mt_atomic_inl_defd_type
#include "mk_lib_mt_atomic_portable_cpp_inl_fileh.hpp"
#elif mk_lang_version_at_least_c_11 && !defined __STDC_NO_ATOMICS__
#define mk_lib_mt_atomic_portable_ca_t_name mk_lib_mt_atomic_inl_defd_base
#define mk_lib_mt_atomic_portable_ca_t_type mk_lib_mt_atomic_inl_defd_type
#include "mk_lib_mt_atomic_portable_ca_inl_fileh.h"
#elif mk_lang_version_at_least_c_11 && !defined __STDC_NO_THREADS__
#define mk_lib_mt_atomic_portable_cb_t_name mk_lib_mt_atomic_inl_defd_base
#define mk_lib_mt_atomic_portable_cb_t_type mk_lib_mt_atomic_inl_defd_type
#include "mk_lib_mt_atomic_portable_cb_inl_fileh.h"
#else
#error xxxxxxxxxx
#endif


typedef mk_lib_mt_atomic_inl_defd_type mk_lib_mt_atomic_inl_defd_type_t;
typedef mk_lib_mt_atomic_inl_defd_type_t const mk_lib_mt_atomic_inl_defd_type_ct;
typedef mk_lib_mt_atomic_inl_defd_type_t* mk_lib_mt_atomic_inl_defd_type_pt;
typedef mk_lib_mt_atomic_inl_defd_type_t const* mk_lib_mt_atomic_inl_defd_type_pct;


struct mk_lib_mt_atomic_inl_defd_s
{
	mk_lib_mt_atomic_inl_defd_base_t m_atomyc;
};
typedef struct mk_lib_mt_atomic_inl_defd_s mk_lib_mt_atomic_inl_defd_t;
typedef mk_lib_mt_atomic_inl_defd_t const mk_lib_mt_atomic_inl_defd_ct;
typedef mk_lib_mt_atomic_inl_defd_t* mk_lib_mt_atomic_inl_defd_pt;
typedef mk_lib_mt_atomic_inl_defd_t const* mk_lib_mt_atomic_inl_defd_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_construct(mk_lib_mt_atomic_inl_defd_pt const atomyc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_destroy(mk_lib_mt_atomic_inl_defd_pt const atomyc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_store(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_atomic_inl_defd_type_pct const desired, mk_lib_mt_memory_order_t const mo) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_load(mk_lib_mt_atomic_inl_defd_pct const atomyc, mk_lib_mt_atomic_inl_defd_type_pt const dst, mk_lib_mt_memory_order_t const mo) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_fetch_add(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_atomic_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_fetch_sub(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_atomic_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_fetch_and(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_atomic_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_fetch_xor(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_atomic_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_fetch_or(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_atomic_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_inc(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_dec(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept;


#include "mk_lib_mt_atomic_inl_defu.h"
