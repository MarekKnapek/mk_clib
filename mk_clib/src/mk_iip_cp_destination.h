#ifndef mk_include_guard_mk_iip_cp_destination_h
#define mk_include_guard_mk_iip_cp_destination_h


#include "mk_iip_cp_type.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint8.h"


struct mk_iip_cp_destination_s
{
	mk_iip_cp_type_destination_elgamal_dsa_t m_destination;
	mk_sl_cui_uint16_t m_port;
};
typedef struct mk_iip_cp_destination_s mk_iip_cp_destination_t;
mk_lang_struct_typedef(mk_iip_cp_destination);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_destination_serialize_elgamal_dsa(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_destination_elgamal_dsa_pct const obj) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_iip_cp_destination.c"
#endif
#endif
