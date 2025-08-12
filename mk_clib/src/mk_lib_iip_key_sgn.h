#ifndef mk_include_guard_mk_lib_iip_key_sgn_h
#define mk_include_guard_mk_lib_iip_key_sgn_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_lib_iip_cp_local_destination);
mk_lang_forward(mk_sl_cui_uint8);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_rw_sign_data(mk_lib_iip_cp_local_destination_pct const local_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_sl_cui_uint8_pt const signature_buf, mk_lang_types_sint_t const signature_len, mk_lang_types_sint_pt const actual_len) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_key_sgn.c"
#endif
#endif
