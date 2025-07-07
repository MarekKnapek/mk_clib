#ifndef mk_include_guard_mk_lib_iip_any_data_connection_h
#define mk_include_guard_mk_lib_iip_any_data_connection_h


#include "mk_lang_jumbo.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_any_data.h"


enum mk_lib_iip_any_data_connection_result_e
{
	mk_lib_iip_any_data_connection_result_e_did_something,
	mk_lib_iip_any_data_connection_result_e_would_block,
	mk_lib_iip_any_data_connection_result_e_timed_out,
	mk_lib_iip_any_data_connection_result_e_idle,
	mk_lib_iip_any_data_connection_result_e_dummy_end
};
typedef enum mk_lib_iip_any_data_connection_result_e mk_lib_iip_any_data_connection_result_t;
mk_lang_typedef(mk_lib_iip_any_data_connection_result);


struct mk_lib_iip_any_data_connection_s
{
	mk_lib_iip_any_data_t m_data;
};
typedef struct mk_lib_iip_any_data_connection_s mk_lib_iip_any_data_connection_t;
mk_lang_typedef(mk_lib_iip_any_data_connection);


#if mk_lang_jumbo_have
#include "mk_lib_iip_any_data_connection.c"
#endif
#endif
