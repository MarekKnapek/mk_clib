#ifndef mk_include_guard_mk_lib_iip_cp_client_types_c
#define mk_include_guard_mk_lib_iip_cp_client_types_c
#include "mk_lib_iip_cp_client_types.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_string.h"
#include "mk_lib_iip_cp_message_create_session_strings.h"
#include "mk_lib_iip_cp_types.h"


#define mk_sl_cui_t_name mk_lib_iip_cp_client_types_handle_wrapper
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_client_types_handle_local
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_client_types_handle_connection
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_client_types_handle_session
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_client_types_handle_socket_listener
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_client_types_handle_socket_connect
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(mk_lib_iip_cp_types_strpairs_pt const options, mk_lib_iip_cp_message_create_session_strings_id_t const str_id, mk_lib_iip_cp_types_strpair_ppt const found) mk_lang_noexcept
{
	mk_lang_types_pchar_pct str_buf;
	mk_lang_types_sint_t str_len;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lib_iip_cp_types_strpair_pt fnd;
	mk_lang_types_sint_t err;

	mk_lang_assert(options);
	mk_lang_assert(str_id >= 0);
	mk_lang_assert(str_id < mk_lib_iip_cp_message_create_session_strings_id_e_dummy_end);
	mk_lang_assert(found);

	str_buf = mk_lib_iip_cp_message_create_session_strings_get_str_buf(str_id); mk_lang_assert(str_buf); mk_lang_assert(str_buf[0] != '\0');
	str_len = mk_lib_iip_cp_message_create_session_strings_get_str_len(str_id); mk_lang_assert(str_len >= 0x01); mk_lang_assert(str_len <= 0xff);
	n = mk_lib_iip_cp_types_strpairs_rw_size(options);
	for(i = 0; i != n; ++i)
	{
		option = mk_lib_iip_cp_types_strpairs_rw_at(options, i); mk_lang_assert(option);
		if(option->m_key.m_len == str_len && mk_lang_string_memcmp_pc_fn(&option->m_key.m_buf[0], str_buf, ((mk_lang_types_usize_t)(str_len))) == 0)
		{
			fnd = option;
			break;
		}
	}
	if(i == n)
	{
		err = mk_lib_iip_cp_types_strpairs_rw_grow_by(options, 1); mk_lang_check_rereturn(err);
		fnd = mk_lib_iip_cp_types_strpairs_rw_back(options); mk_lang_assert(fnd);
		mk_lang_string_memcpy_pc_fn(&fnd->m_key.m_buf[0], str_buf, ((mk_lang_types_usize_t)(str_len)));
		fnd->m_key.m_len = str_len;
	}
	mk_lang_clobber(&fnd);
	*found = fnd;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_construct(mk_lib_iip_cp_types_strpairs_pt const options) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(options);

	err = mk_lib_iip_cp_types_strpairs_rw_construct_void(options); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_client_message_timeout(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_slong_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_ulong_t tul;

	mk_lang_assert(options);
	mk_lang_assert(val >= 8l * 1000l);
	mk_lang_assert(val <= 120l * 1000l);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_client_message_timeout;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tul = ((mk_lang_bui_ulong_t)(val));
	option->m_val.m_len = mk_lang_bui_ulong_to_str_dec_n(&tul, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_crypto_low_tag_threshold(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 1);
	mk_lang_assert(val <= 128);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_crypto_low_tag_threshold;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_crypto_ratchet_inbound_tags(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 1);
	mk_lang_assert(val <= 32000);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_crypto_ratchet_inbound_tags;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_crypto_ratchet_outbound_tags(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 1);
	mk_lang_assert(val <= 32000);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_crypto_ratchet_outbound_tags;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_crypto_tags_to_send(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 1);
	mk_lang_assert(val <= 128);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_crypto_tags_to_send;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_explicit_peers(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_pchar_pct const val_buf, mk_lang_types_sint_t const val_len) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;

	mk_lang_assert(options);
	mk_lang_assert(val_buf || val_len == 0);
	mk_lang_assert(val_len >= 0x00);
	mk_lang_assert(val_len <= 0xff);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_explicit_peers;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_dont_publish_lease_set(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_bool_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lib_iip_cp_message_create_session_strings_id_t val_id;
	mk_lang_types_pchar_pct val_buf;
	mk_lang_types_sint_t val_len;

	mk_lang_assert(options);
	mk_lang_assert(val == mk_lang_true || val == mk_lang_false);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_dont_publish_lease_set;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	val_id = val ? mk_lib_iip_cp_message_create_session_strings_id_e_true: mk_lib_iip_cp_message_create_session_strings_id_e_false;
	val_buf = mk_lib_iip_cp_message_create_session_strings_get_str_buf(val_id); mk_lang_assert(val_buf); mk_lang_assert(val_buf[0] != '\0');
	val_len = mk_lib_iip_cp_message_create_session_strings_get_str_len(val_id); mk_lang_assert(val_len >= 0x01); mk_lang_assert(val_len <= 0xff);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_fast_receive(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_bool_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lib_iip_cp_message_create_session_strings_id_t val_id;
	mk_lang_types_pchar_pct val_buf;
	mk_lang_types_sint_t val_len;

	mk_lang_assert(options);
	mk_lang_assert(val == mk_lang_true || val == mk_lang_false);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_fast_receive;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	val_id = val ? mk_lib_iip_cp_message_create_session_strings_id_e_true: mk_lib_iip_cp_message_create_session_strings_id_e_false;
	val_buf = mk_lib_iip_cp_message_create_session_strings_get_str_buf(val_id); mk_lang_assert(val_buf); mk_lang_assert(val_buf[0] != '\0');
	val_len = mk_lib_iip_cp_message_create_session_strings_get_str_len(val_id); mk_lang_assert(val_len >= 0x01); mk_lang_assert(val_len <= 0xff);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_lease_set_auth_type(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 0);
	mk_lang_assert(val <= 2);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_lease_set_auth_type;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_lease_set_enc_type(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_slong_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_ulong_t tul;

	mk_lang_assert(options);
	mk_lang_assert(val >= 0x0000l);
	mk_lang_assert(val <= 0xffffl);

	/* tdo coma separated multiple values */
	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_lease_set_enc_type;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tul = ((mk_lang_bui_ulong_t)(val));
	option->m_val.m_len = mk_lang_bui_ulong_to_str_dec_n(&tul, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_lease_set_offline_expiration(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_ulong_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(options);
	mk_lang_assert(val >= 0x00000000ul);
	mk_lang_assert(val <= 0xfffffffful);
	#include "mk_lang_warning_msvc_pop.h"

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_lease_set_offline_expiration;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	option->m_val.m_len = mk_lang_bui_ulong_to_str_dec_n(&val, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len >= 1); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_lease_set_offline_signature(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_pchar_pct const val_buf, mk_lang_types_sint_t const val_len) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;

	mk_lang_assert(options);
	mk_lang_assert(val_buf || val_len == 0);
	mk_lang_assert(val_len >= 0x00);
	mk_lang_assert(val_len <= 0xff);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_lease_set_offline_signature;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_lease_set_priv_key(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_pchar_pct const val_buf, mk_lang_types_sint_t const val_len) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;

	mk_lang_assert(options);
	mk_lang_assert(val_buf || val_len == 0);
	mk_lang_assert(val_len >= 0x00);
	mk_lang_assert(val_len <= 0xff);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_lease_set_priv_key;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_lease_set_secret(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_pchar_pct const val_buf, mk_lang_types_sint_t const val_len) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;

	mk_lang_assert(options);
	mk_lang_assert(val_buf || val_len == 0);
	mk_lang_assert(val_len >= 0x00);
	mk_lang_assert(val_len <= 0xff);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_lease_set_secret;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_lease_set_transient_public_key(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_pchar_pct const val_buf, mk_lang_types_sint_t const val_len) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;

	mk_lang_assert(options);
	mk_lang_assert(val_buf || val_len == 0);
	mk_lang_assert(val_len >= 0x00);
	mk_lang_assert(val_len <= 0xff);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_lease_set_transient_public_key;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_lease_set_type(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 0x01);
	mk_lang_assert(val <= 0xff);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_lease_set_type;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_message_reliability(mk_lib_iip_cp_types_strpairs_pt const options, mk_lib_iip_cp_client_types_session_settings_options_message_reliability_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lib_iip_cp_message_create_session_strings_id_t val_id;
	mk_lang_types_pchar_pct val_buf;
	mk_lang_types_sint_t val_len;

	mk_lang_assert(options);
	mk_lang_assert(val >= 0);
	mk_lang_assert(val < mk_lib_iip_cp_client_types_session_settings_options_message_reliability_e_dummy_end);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_message_reliability;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	val_id =
		val == mk_lib_iip_cp_client_types_session_settings_options_message_reliability_e_best_effort ? mk_lib_iip_cp_message_create_session_strings_id_e_best_effort : (
		val == mk_lib_iip_cp_client_types_session_settings_options_message_reliability_e_none ? mk_lib_iip_cp_message_create_session_strings_id_e_none : (
		(mk_lang_assert_false(), mk_lib_iip_cp_message_create_session_strings_id_e_dummy_end)
		));
	val_buf = mk_lib_iip_cp_message_create_session_strings_get_str_buf(val_id); mk_lang_assert(val_buf); mk_lang_assert(val_buf[0] != '\0');
	val_len = mk_lib_iip_cp_message_create_session_strings_get_str_len(val_id); mk_lang_assert(val_len >= 0x01); mk_lang_assert(val_len <= 0xff);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_password(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_pchar_pct const val_buf, mk_lang_types_sint_t const val_len) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;

	mk_lang_assert(options);
	mk_lang_assert(val_buf || val_len == 0);
	mk_lang_assert(val_len >= 0x00);
	mk_lang_assert(val_len <= 0xff);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_password;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_username(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_pchar_pct const val_buf, mk_lang_types_sint_t const val_len) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;

	mk_lang_assert(options);
	mk_lang_assert(val_buf || val_len == 0);
	mk_lang_assert(val_len >= 0x00);
	mk_lang_assert(val_len <= 0xff);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_i2cp_username;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_inbound_allow_zero_hop(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_bool_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lib_iip_cp_message_create_session_strings_id_t val_id;
	mk_lang_types_pchar_pct val_buf;
	mk_lang_types_sint_t val_len;

	mk_lang_assert(options);
	mk_lang_assert(val == mk_lang_true || val == mk_lang_false);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_inbound_allow_zero_hop;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	val_id = val ? mk_lib_iip_cp_message_create_session_strings_id_e_true: mk_lib_iip_cp_message_create_session_strings_id_e_false;
	val_buf = mk_lib_iip_cp_message_create_session_strings_get_str_buf(val_id); mk_lang_assert(val_buf); mk_lang_assert(val_buf[0] != '\0');
	val_len = mk_lib_iip_cp_message_create_session_strings_get_str_len(val_id); mk_lang_assert(val_len >= 0x01); mk_lang_assert(val_len <= 0xff);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_inbound_backup_quantity(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 0);
	mk_lang_assert(val <= 30000);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_inbound_backup_quantity;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_inbound_ip_restriction(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 0);
	mk_lang_assert(val <= 4);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_inbound_ip_restriction;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_inbound_length(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 0);
	mk_lang_assert(val <= 7);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_inbound_length;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_inbound_length_variance(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= -7);
	mk_lang_assert(val <= +7);

	/* todo negative */
	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_inbound_length_variance;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_inbound_nickname(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_pchar_pct const val_buf, mk_lang_types_sint_t const val_len) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;

	mk_lang_assert(options);
	mk_lang_assert(val_buf || val_len == 0);
	mk_lang_assert(val_len >= 0x00);
	mk_lang_assert(val_len <= 0xff);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_inbound_nickname;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_inbound_quantity(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 1);
	mk_lang_assert(val <= 16);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_inbound_quantity;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_inbound_random_key(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_pchar_pct const val_buf, mk_lang_types_sint_t const val_len) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;

	mk_lang_assert(options);
	mk_lang_assert(val_buf || val_len == 0);
	mk_lang_assert(val_len >= 0x00);
	mk_lang_assert(val_len <= 0xff);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_inbound_random_key;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_outbound_allow_zero_hop(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_bool_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lib_iip_cp_message_create_session_strings_id_t val_id;
	mk_lang_types_pchar_pct val_buf;
	mk_lang_types_sint_t val_len;

	mk_lang_assert(options);
	mk_lang_assert(val == mk_lang_true || val == mk_lang_false);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_outbound_allow_zero_hop;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	val_id = val ? mk_lib_iip_cp_message_create_session_strings_id_e_true: mk_lib_iip_cp_message_create_session_strings_id_e_false;
	val_buf = mk_lib_iip_cp_message_create_session_strings_get_str_buf(val_id); mk_lang_assert(val_buf); mk_lang_assert(val_buf[0] != '\0');
	val_len = mk_lib_iip_cp_message_create_session_strings_get_str_len(val_id); mk_lang_assert(val_len >= 0x01); mk_lang_assert(val_len <= 0xff);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_outbound_backup_quantity(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 0);
	mk_lang_assert(val <= 30000);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_outbound_backup_quantity;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_outbound_ip_restriction(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 0);
	mk_lang_assert(val <= 4);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_outbound_ip_restriction;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_outbound_length(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 0);
	mk_lang_assert(val <= 7);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_outbound_length;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_outbound_length_variance(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= -7);
	mk_lang_assert(val <= +7);

	/* todo negative */
	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_outbound_length_variance;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_outbound_nickname(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_pchar_pct const val_buf, mk_lang_types_sint_t const val_len) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;

	mk_lang_assert(options);
	mk_lang_assert(val_buf || val_len == 0);
	mk_lang_assert(val_len >= 0x00);
	mk_lang_assert(val_len <= 0xff);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_inbound_nickname;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_outbound_priority(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= -25);
	mk_lang_assert(val <= +25);

	/* todo negative */
	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_outbound_priority;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_outbound_quantity(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_sint_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lang_bui_uint_t tui;

	mk_lang_assert(options);
	mk_lang_assert(val >= 1);
	mk_lang_assert(val <= 30000);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_outbound_quantity;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	tui = ((mk_lang_bui_uint_t)(val));
	option->m_val.m_len = mk_lang_bui_uint_to_str_dec_n(&tui, &option->m_val.m_buf[0], mk_lang_countof(option->m_val.m_buf)); mk_lang_assert(option->m_val.m_len <= mk_lang_countof(option->m_val.m_buf));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_outbound_random_key(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_pchar_pct const val_buf, mk_lang_types_sint_t const val_len) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;

	mk_lang_assert(options);
	mk_lang_assert(val_buf || val_len == 0);
	mk_lang_assert(val_len >= 0x00);
	mk_lang_assert(val_len <= 0xff);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_outbound_random_key;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_types_session_settings_options_rw_set_should_bundle_reply_info(mk_lib_iip_cp_types_strpairs_pt const options, mk_lang_types_bool_t const val) mk_lang_noexcept
{
	mk_lib_iip_cp_message_create_session_strings_id_t str_id;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_strpair_pt option;
	mk_lib_iip_cp_message_create_session_strings_id_t val_id;
	mk_lang_types_pchar_pct val_buf;
	mk_lang_types_sint_t val_len;

	mk_lang_assert(options);
	mk_lang_assert(val == mk_lang_true || val == mk_lang_false);

	str_id = mk_lib_iip_cp_message_create_session_strings_id_e_should_bundle_reply_info;
	err = mk_lib_iip_cp_client_types_session_settings_options_prrw_find_or_append(options, str_id, &option); mk_lang_check_rereturn(err); mk_lang_assert(option);
	val_id = val ? mk_lib_iip_cp_message_create_session_strings_id_e_true: mk_lib_iip_cp_message_create_session_strings_id_e_false;
	val_buf = mk_lib_iip_cp_message_create_session_strings_get_str_buf(val_id); mk_lang_assert(val_buf); mk_lang_assert(val_buf[0] != '\0');
	val_len = mk_lib_iip_cp_message_create_session_strings_get_str_len(val_id); mk_lang_assert(val_len >= 0x01); mk_lang_assert(val_len <= 0xff);
	mk_lang_string_memcpy_pc_fn(&option->m_val.m_buf[0], val_buf, ((mk_lang_types_usize_t)(val_len)));
	option->m_val.m_len = val_len;
	return 0;
}


#define mk_sl_cui_t_name mk_lib_iip_cp_client_types_handle_lookup_host_name
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#endif
