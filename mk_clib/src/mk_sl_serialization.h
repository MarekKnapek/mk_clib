#ifndef mk_include_guard_mk_sl_serialization
#define mk_include_guard_mk_sl_serialization


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_bool   (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_bool_pct    const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_pchar  (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_pchar_pct   const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_uchar  (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_uchar_pct   const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_schar  (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_schar_pct   const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_ushort (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_ushort_pct  const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_sshort (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_sshort_pct  const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_uint   (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_uint_pct    const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_sint   (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_sint_pct    const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_ulong  (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_ulong_pct   const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_slong  (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_slong_pct   const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_ullong (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_ullong_pct  const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_sllong (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_sllong_pct  const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_ulllong(mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_ulllong_pct const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_slllong(mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_slllong_pct const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_uintptr(mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_uintptr_pct const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_sintptr(mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_sintptr_pct const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_uintmax(mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_uintmax_pct const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_sintmax(mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_sintmax_pct const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_usize  (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_usize_pct   const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_write_ssize  (mk_sl_cui_uint8_pt const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_ssize_pct   const x) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_bool   (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_bool_pt    const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_pchar  (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_pchar_pt   const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_uchar  (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_uchar_pt   const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_schar  (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_schar_pt   const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_ushort (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_ushort_pt  const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_sshort (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_sshort_pt  const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_uint   (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_uint_pt    const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_sint   (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_sint_pt    const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_ulong  (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_ulong_pt   const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_slong  (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_slong_pt   const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_ullong (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_ullong_pt  const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_sllong (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_sllong_pt  const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_ulllong(mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_ulllong_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_slllong(mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_slllong_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_uintptr(mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_uintptr_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_sintptr(mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_sintptr_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_uintmax(mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_uintmax_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_sintmax(mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_sintmax_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_usize  (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_usize_pt   const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_serialization_read_ssize  (mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lang_types_usize_pt const ptr, mk_lang_types_ssize_pt   const x) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_serialization.c"
#endif
#endif
