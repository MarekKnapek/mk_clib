#ifndef mk_include_guard_mk_lib_iip_any_data_h
#define mk_include_guard_mk_lib_iip_any_data_h


#include "mk_lang_jumbo.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


struct mk_lib_iip_any_data_s
{
	mk_lang_types_sint_t m_id;
};
typedef struct mk_lib_iip_any_data_s mk_lib_iip_any_data_t;
mk_lang_typedef(mk_lib_iip_any_data);


#if mk_lang_jumbo_have
#include "mk_lib_iip_any_data.c"
#endif
#endif
