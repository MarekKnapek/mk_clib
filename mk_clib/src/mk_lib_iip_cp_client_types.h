#ifndef mk_include_guard_mk_lib_iip_cp_client_types_h
#define mk_include_guard_mk_lib_iip_cp_client_types_h


#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_lib_net.h"


#define mk_sl_cui_t_name mk_lib_iip_cp_client_types_handle_wrapper
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_iip_cp_client_types_handle_wrapper_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_lib_iip_cp_client_types_handle_wrapper_size_bytes_d (mk_lang_bui_uintptr_size_bits_d / mk_lang_charbit)

#define mk_sl_cui_t_name mk_lib_iip_cp_client_types_handle_local
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_iip_cp_client_types_handle_local_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_lib_iip_cp_client_types_handle_local_size_bytes_d (mk_lang_bui_uintptr_size_bits_d / mk_lang_charbit)

#define mk_sl_cui_t_name mk_lib_iip_cp_client_types_handle_connection
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_iip_cp_client_types_handle_connection_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_lib_iip_cp_client_types_handle_connection_size_bytes_d (mk_lang_bui_uintptr_size_bits_d / mk_lang_charbit)

#define mk_sl_cui_t_name mk_lib_iip_cp_client_types_handle_session
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_iip_cp_client_types_handle_session_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_lib_iip_cp_client_types_handle_session_size_bytes_d (mk_lang_bui_uintptr_size_bits_d / mk_lang_charbit)


struct mk_lib_iip_cp_client_types_iocp_settings_s
{
	int m_dummy;
};
typedef struct mk_lib_iip_cp_client_types_iocp_settings_s mk_lib_iip_cp_client_types_iocp_settings_t;
mk_lang_typedef(mk_lib_iip_cp_client_types_iocp_settings);


struct mk_lib_iip_cp_client_types_application_settings_s
{
	mk_lib_iip_cp_client_types_iocp_settings_t m_iocp_settings;
	int m_dummy;
};
typedef struct mk_lib_iip_cp_client_types_application_settings_s mk_lib_iip_cp_client_types_application_settings_t;
mk_lang_typedef(mk_lib_iip_cp_client_types_application_settings);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_client_types_local_settings_s
{
	mk_lib_net_destination_t m_destination;
};
typedef struct mk_lib_iip_cp_client_types_local_settings_s mk_lib_iip_cp_client_types_local_settings_t;
mk_lang_typedef(mk_lib_iip_cp_client_types_local_settings);
#include "mk_lang_warning_msvc_pop.h"


struct mk_lib_iip_cp_client_types_connection_authentication_s
{
	mk_lib_iip_cp_types_string_t m_user_name;
	mk_lib_iip_cp_types_string_t m_password;
};
typedef struct mk_lib_iip_cp_client_types_connection_authentication_s mk_lib_iip_cp_client_types_connection_authentication_t;
mk_lang_typedef(mk_lib_iip_cp_client_types_connection_authentication);

struct mk_lib_iip_cp_client_types_connection_settings_s
{
	mk_lib_net_destination_t m_destination;
	mk_lib_iip_cp_client_types_connection_authentication_t m_authentication;
};
typedef struct mk_lib_iip_cp_client_types_connection_settings_s mk_lib_iip_cp_client_types_connection_settings_t;
mk_lang_typedef(mk_lib_iip_cp_client_types_connection_settings);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_client_types_session_settings_s
{
	mk_lib_iip_cp_client_types_handle_connection_t m_connection;
	mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_t m_destination;
	mk_lib_iip_cp_client_types_handle_session_t m_master_session;
};
typedef struct mk_lib_iip_cp_client_types_session_settings_s mk_lib_iip_cp_client_types_session_settings_t;
mk_lang_typedef(mk_lib_iip_cp_client_types_session_settings);
#include "mk_lang_warning_msvc_pop.h"


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_client_types.c"
#endif
#endif
