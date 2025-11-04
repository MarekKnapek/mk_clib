#ifndef mk_include_guard_mk_lib_app_cryptor_c
#define mk_include_guard_mk_lib_app_cryptor_c
#include "mk_lib_app_cryptor.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_pow2.h"
#include "mk_lang_roundup.h"
#include "mk_lang_str_lit.h"
#include "mk_lang_str_match.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"
#include "mk_lib_app_cryptor_alg_names.h"
#include "mk_lib_app_cryptor_mode_names.h"
#include "mk_lib_app_cryptor_mode_stream_any1.h"
#include "mk_lib_app_cryptor_mode_stream_any2.h"
#include "mk_lib_crypto_hash_names.h"
#include "mk_lib_crypto_kdf_pbkdf2_any.h"
#include "mk_lib_crypto_mac_hmac_stream_any2.h"
#include "mk_lib_crypto_mode_stream_any2.h"
#include "mk_lib_crypto_padding_any.h"
#include "mk_lib_crypto_padding_names.h"
#include "mk_sl_bui.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_random.h"
#include "mk_sl_speedometer.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_args_no_check(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_direction_t const direction, mk_lib_app_cryptor_mode_names_id_t const mode, mk_lib_app_cryptor_alg_names_id_t const alg, mk_lib_crypto_padding_names_id_t const padding, mk_lang_types_bool_t const kdf, mk_lib_crypto_hash_names_id_t const hash, mk_lang_types_ulong_t const cost, mk_sl_cui_uint8_pct const password_ptr, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt_ptr, mk_lang_types_sint_t const salt_len) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(cryptor);
	mk_lang_assert(direction >= 0);
	mk_lang_assert(direction < mk_lib_app_cryptor_direction_e_dummy_end);
	mk_lang_assert(mode >= 0);
	mk_lang_assert(mode < mk_lib_app_cryptor_mode_names_id_e_dummy_end);
	mk_lang_assert(alg >= 0);
	mk_lang_assert(alg < mk_lib_app_cryptor_alg_names_id_e_dummy_end);
	mk_lang_assert(padding >= 0);
	mk_lang_assert(padding < mk_lib_crypto_padding_names_id_e_dummy_end);
	mk_lang_assert(kdf == mk_lang_false || kdf == mk_lang_true);
	mk_lang_assert(hash >= 0);
	mk_lang_assert(hash < mk_lib_crypto_hash_names_id_e_dummy_end);
	mk_lang_assert(cost >= 0);
	mk_lang_assert(cost <= 0xfffffffful);
	mk_lang_assert(password_ptr);
	mk_lang_assert(password_len >= 1);
	mk_lang_assert(password_len <= mk_lang_countof(cryptor->m_password_buf));
	mk_lang_assert(salt_ptr);
	mk_lang_assert(salt_len >= 1);
	mk_lang_assert(salt_len <= mk_lang_countof(cryptor->m_salt_buf));
	#include "mk_lang_warning_msvc_pop.h"

	cryptor->m_config.m_direction = direction;
	cryptor->m_config.m_mode = mode;
	cryptor->m_config.m_alg = alg;
	cryptor->m_config.m_padding = padding;
	cryptor->m_config.m_kdf = kdf;
	cryptor->m_config.m_hash = hash;
	cryptor->m_config.m_cost = cost;
	cryptor->m_config.m_password_ptr = &cryptor->m_password_buf[0];
	cryptor->m_config.m_password_len = password_len;
	cryptor->m_config.m_salt_ptr = &cryptor->m_salt_buf[0];
	cryptor->m_config.m_salt_len = salt_len;
	mk_sl_cui_uint8_memcpy_fn(&cryptor->m_password_buf[0], &password_ptr[0], ((mk_lang_types_usize_t)(password_len)));
	mk_sl_cui_uint8_memcpy_fn(&cryptor->m_salt_buf[0], &salt_ptr[0], ((mk_lang_types_usize_t)(salt_len)));
	cryptor->m_iv_handled = mk_lang_false;
	cryptor->m_padding_handled = mk_lang_false;
	cryptor->m_last_chunk_idx = 0;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_args_check(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_direction_t const direction, mk_lib_app_cryptor_mode_names_id_t const mode, mk_lib_app_cryptor_alg_names_id_t const alg, mk_lib_crypto_padding_names_id_t const padding, mk_lang_types_bool_t const kdf, mk_lib_crypto_hash_names_id_t const hash, mk_lang_types_ulong_t const cost, mk_sl_cui_uint8_pct const password_ptr, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt_ptr, mk_lang_types_sint_t const salt_len, mk_lib_app_cryptor_param_id_pt const failed) mk_lang_noexcept
{
	mk_lang_assert(cryptor);
	mk_lang_assert(failed);

	*failed = mk_lib_app_cryptor_param_id_e_dummy_end;
	#include "mk_lang_warning_msvc_push_c4296.h"
	if(!(direction >= 0)                                          ){ *failed = mk_lib_app_cryptor_param_id_e_direction; return 0; }
	if(!(direction < mk_lib_app_cryptor_direction_e_dummy_end)    ){ *failed = mk_lib_app_cryptor_param_id_e_direction; return 0; }
	if(!(mode >= 0)                                               ){ *failed = mk_lib_app_cryptor_param_id_e_mode     ; return 0; }
	if(!(mode < mk_lib_app_cryptor_mode_names_id_e_dummy_end)     ){ *failed = mk_lib_app_cryptor_param_id_e_mode     ; return 0; }
	if(!(alg >= 0)                                                ){ *failed = mk_lib_app_cryptor_param_id_e_alg      ; return 0; }
	if(!(alg < mk_lib_app_cryptor_alg_names_id_e_dummy_end)       ){ *failed = mk_lib_app_cryptor_param_id_e_alg      ; return 0; }
	if(!(padding >= 0)                                            ){ *failed = mk_lib_app_cryptor_param_id_e_padding  ; return 0; }
	if(!(padding < mk_lib_crypto_padding_names_id_e_dummy_end)    ){ *failed = mk_lib_app_cryptor_param_id_e_padding  ; return 0; }
	if(!(kdf == mk_lang_false || kdf == mk_lang_true)             ){ *failed = mk_lib_app_cryptor_param_id_e_kdf      ; return 0; }
	if(!(hash >= 0)                                               ){ *failed = mk_lib_app_cryptor_param_id_e_hash     ; return 0; }
	if(!(hash < mk_lib_crypto_hash_names_id_e_dummy_end)          ){ *failed = mk_lib_app_cryptor_param_id_e_hash     ; return 0; }
	if(!(cost >= 0)                                               ){ *failed = mk_lib_app_cryptor_param_id_e_cost     ; return 0; }
	if(!(cost <= 0xfffffffful)                                    ){ *failed = mk_lib_app_cryptor_param_id_e_cost     ; return 0; }
	if(!(password_ptr)                                            ){ *failed = mk_lib_app_cryptor_param_id_e_password ; return 0; }
	if(!(password_len >= 1)                                       ){ *failed = mk_lib_app_cryptor_param_id_e_password ; return 0; }
	if(!(password_len <= mk_lang_countof(cryptor->m_password_buf))){ *failed = mk_lib_app_cryptor_param_id_e_password ; return 0; }
	if(!(salt_ptr)                                                ){ *failed = mk_lib_app_cryptor_param_id_e_salt     ; return 0; }
	if(!(salt_len >= 1)                                           ){ *failed = mk_lib_app_cryptor_param_id_e_salt     ; return 0; }
	if(!(salt_len <= mk_lang_countof(cryptor->m_salt_buf))        ){ *failed = mk_lib_app_cryptor_param_id_e_salt     ; return 0; }
	#include "mk_lang_warning_msvc_pop.h"
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_args_do_check(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_direction_t const direction, mk_lib_app_cryptor_mode_names_id_t const mode, mk_lib_app_cryptor_alg_names_id_t const alg, mk_lib_crypto_padding_names_id_t const padding, mk_lang_types_bool_t const kdf, mk_lib_crypto_hash_names_id_t const hash, mk_lang_types_ulong_t const cost, mk_sl_cui_uint8_pct const password_ptr, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt_ptr, mk_lang_types_sint_t const salt_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_app_cryptor_param_id_t failed mk_lang_constexpr_init;

	mk_lang_assert(cryptor);

	err = mk_lib_app_cryptor_prrw_args_check(cryptor, direction, mode, alg, padding, kdf, hash, cost, password_ptr, password_len, salt_ptr, salt_len, &failed); mk_lang_check_rereturn(err);
	mk_lang_check_return(failed == mk_lib_app_cryptor_param_id_e_dummy_end);
	err = mk_lib_app_cryptor_prrw_construct_args_no_check(cryptor, direction, mode, alg, padding, kdf, hash, cost, password_ptr, password_len, salt_ptr, salt_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_args(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_direction_t const direction, mk_lib_app_cryptor_mode_names_id_t const mode, mk_lib_app_cryptor_alg_names_id_t const alg, mk_lib_crypto_padding_names_id_t const padding, mk_lang_types_bool_t const kdf, mk_lib_crypto_hash_names_id_t const hash, mk_lang_types_ulong_t const cost, mk_sl_cui_uint8_pct const password_ptr, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt_ptr, mk_lang_types_sint_t const salt_len) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_construct_args_no_check(cryptor, direction, mode, alg, padding, kdf, hash, cost, password_ptr, password_len, salt_ptr, salt_len);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_config(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_config_pct const config) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_construct_args_no_check(cryptor, config->m_direction, config->m_mode, config->m_alg, config->m_padding, config->m_kdf, config->m_hash, config->m_cost, config->m_password_ptr, config->m_password_len, config->m_salt_ptr, config->m_salt_len);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_cmd_line_direction(mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(command_line);
	mk_lang_assert(argc);
	mk_lang_assert(*argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(*argv);
	mk_lang_assert(lens);
	mk_lang_assert(*lens);
	mk_lang_assert(gud);
	mk_lang_assert(*gud == mk_lang_false || *gud == mk_lang_true);

	if(*argc >= 2)
	{
		n = *argc;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert((*argv)[i]);
			mk_lang_assert((*argv)[i][0] != mk_lang_tchar_c('\0'));
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/direction")))
		{
			if(mk_lang_str_match_t((*argv)[1], (*lens)[1], mk_lang_str_lit("encrypt")))
			{
				command_line->m_config.m_direction = mk_lib_app_cryptor_direction_e_encrypt;
				(*argc) -= 2;
				(*argv) += 2;
				(*lens) += 2;
				*gud = mk_lang_true;
			}
			else if(mk_lang_str_match_t((*argv)[1], (*lens)[1], mk_lang_str_lit("decrypt")))
			{
				command_line->m_config.m_direction = mk_lib_app_cryptor_direction_e_decrypt;
				(*argc) -= 2;
				(*argv) += 2;
				(*lens) += 2;
				*gud = mk_lang_true;
			}
			else
			{
				command_line->m_config.m_direction = mk_lib_app_cryptor_direction_e_dummy_end;
			}
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_cmd_line_mode(mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(command_line);
	mk_lang_assert(argc);
	mk_lang_assert(*argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(*argv);
	mk_lang_assert(lens);
	mk_lang_assert(*lens);
	mk_lang_assert(gud);
	mk_lang_assert(*gud == mk_lang_false || *gud == mk_lang_true);

	if(*argc >= 2)
	{
		n = *argc;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert((*argv)[i]);
			mk_lang_assert((*argv)[i][0] != mk_lang_tchar_c('\0'));
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/mode")))
		{
			command_line->m_config.m_mode = mk_lib_app_cryptor_mode_names_get_id_from_str_t((*argv)[1], (*lens)[1]);
			(*argc) -= 2;
			(*argv) += 2;
			(*lens) += 2;
			*gud = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_cmd_line_alg(mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(command_line);
	mk_lang_assert(argc);
	mk_lang_assert(*argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(*argv);
	mk_lang_assert(lens);
	mk_lang_assert(*lens);
	mk_lang_assert(gud);
	mk_lang_assert(*gud == mk_lang_false || *gud == mk_lang_true);

	if(*argc >= 2)
	{
		n = *argc;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert((*argv)[i]);
			mk_lang_assert((*argv)[i][0] != mk_lang_tchar_c('\0'));
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/alg")))
		{
			command_line->m_config.m_alg = mk_lib_app_cryptor_alg_names_get_id_from_str_t((*argv)[1], (*lens)[1]);
			(*argc) -= 2;
			(*argv) += 2;
			(*lens) += 2;
			*gud = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_cmd_line_padding(mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(command_line);
	mk_lang_assert(argc);
	mk_lang_assert(*argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(*argv);
	mk_lang_assert(lens);
	mk_lang_assert(*lens);
	mk_lang_assert(gud);
	mk_lang_assert(*gud == mk_lang_false || *gud == mk_lang_true);

	if(*argc >= 2)
	{
		n = *argc;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert((*argv)[i]);
			mk_lang_assert((*argv)[i][0] != mk_lang_tchar_c('\0'));
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/padding")))
		{
			command_line->m_config.m_padding = mk_lib_crypto_padding_names_get_id_from_str_t((*argv)[1], (*lens)[1]);
			(*argc) -= 2;
			(*argv) += 2;
			(*lens) += 2;
			*gud = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_cmd_line_kdf(mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(command_line);
	mk_lang_assert(argc);
	mk_lang_assert(*argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(*argv);
	mk_lang_assert(lens);
	mk_lang_assert(*lens);
	mk_lang_assert(gud);
	mk_lang_assert(*gud == mk_lang_false || *gud == mk_lang_true);

	if(*argc >= 2)
	{
		n = *argc;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert((*argv)[i]);
			mk_lang_assert((*argv)[i][0] != mk_lang_tchar_c('\0'));
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/kdf")))
		{
			if(mk_lang_str_match_t((*argv)[1], (*lens)[1], mk_lang_str_lit("PBKDF2")))
			{
				command_line->m_config.m_kdf = mk_lang_true;
				(*argc) -= 2;
				(*argv) += 2;
				(*lens) += 2;
				*gud = mk_lang_true;
			}
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_cmd_line_hash(mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(command_line);
	mk_lang_assert(argc);
	mk_lang_assert(*argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(*argv);
	mk_lang_assert(lens);
	mk_lang_assert(*lens);
	mk_lang_assert(gud);
	mk_lang_assert(*gud == mk_lang_false || *gud == mk_lang_true);

	if(*argc >= 2)
	{
		n = *argc;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert((*argv)[i]);
			mk_lang_assert((*argv)[i][0] != mk_lang_tchar_c('\0'));
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/hash")))
		{
			command_line->m_config.m_hash = mk_lib_crypto_hash_names_get_id_from_str_t((*argv)[1], (*lens)[1]);
			(*argc) -= 2;
			(*argv) += 2;
			(*lens) += 2;
			*gud = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_cmd_line_cost(mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_tchar_pct cost_str_ptr;
	mk_lang_types_sint_t cost_str_len;
	mk_lang_types_sint_t len;
	mk_lang_types_ulong_pt cost_integer;

	mk_lang_assert(command_line);
	mk_lang_assert(argc);
	mk_lang_assert(*argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(*argv);
	mk_lang_assert(lens);
	mk_lang_assert(*lens);
	mk_lang_assert(gud);
	mk_lang_assert(*gud == mk_lang_false || *gud == mk_lang_true);

	if(*argc >= 2)
	{
		n = *argc;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert((*argv)[i]);
			mk_lang_assert((*argv)[i][0] != mk_lang_tchar_c('\0'));
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/cost")))
		{
			cost_str_ptr = (*argv)[1];
			cost_str_len = (*lens)[1];
			cost_integer = &command_line->m_config.m_cost;
			len = mk_lang_tchar_dispatch(mk_lang_bui_ulong_from_str_dec_)(cost_integer, cost_str_ptr, cost_str_len);
			if(!(len == cost_str_len)){ *cost_integer = ((mk_lang_types_ulong_t)(((mk_lang_types_slong_t)(-1)))); }
			(*argc) -= 2;
			(*argv) += 2;
			(*lens) += 2;
			*gud = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_cmd_line_password(mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(command_line);
	mk_lang_assert(argc);
	mk_lang_assert(*argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(*argv);
	mk_lang_assert(lens);
	mk_lang_assert(*lens);
	mk_lang_assert(gud);
	mk_lang_assert(*gud == mk_lang_false || *gud == mk_lang_true);

	if(*argc >= 2)
	{
		n = *argc;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert((*argv)[i]);
			mk_lang_assert((*argv)[i][0] != mk_lang_tchar_c('\0'));
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/password")))
		{
			command_line->m_config.m_password_ptr = ((mk_sl_cui_uint8_pct)((*argv)[1]));
			command_line->m_config.m_password_len = (*lens)[1];
			(*argc) -= 2;
			(*argv) += 2;
			(*lens) += 2;
			*gud = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_cmd_line_salt(mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(command_line);
	mk_lang_assert(argc);
	mk_lang_assert(*argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(*argv);
	mk_lang_assert(lens);
	mk_lang_assert(*lens);
	mk_lang_assert(gud);
	mk_lang_assert(*gud == mk_lang_false || *gud == mk_lang_true);

	if(*argc >= 2)
	{
		n = *argc;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert((*argv)[i]);
			mk_lang_assert((*argv)[i][0] != mk_lang_tchar_c('\0'));
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/salt")))
		{
			command_line->m_config.m_salt_ptr = ((mk_sl_cui_uint8_pct)((*argv)[1]));
			command_line->m_config.m_salt_len = (*lens)[1];
			(*argc) -= 2;
			(*argv) += 2;
			(*lens) += 2;
			*gud = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_cmd_line_input(mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(command_line);
	mk_lang_assert(argc);
	mk_lang_assert(*argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(*argv);
	mk_lang_assert(lens);
	mk_lang_assert(*lens);
	mk_lang_assert(gud);
	mk_lang_assert(*gud == mk_lang_false || *gud == mk_lang_true);

	if(*argc >= 2)
	{
		n = *argc;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert((*argv)[i]);
			mk_lang_assert((*argv)[i][0] != mk_lang_tchar_c('\0'));
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/input")))
		{
			command_line->m_input_ptr = (*argv)[1];
			command_line->m_input_len = (*lens)[1];
			(*argc) -= 2;
			(*argv) += 2;
			(*lens) += 2;
			*gud = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_cmd_line_output(mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(command_line);
	mk_lang_assert(argc);
	mk_lang_assert(*argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(*argv);
	mk_lang_assert(lens);
	mk_lang_assert(*lens);
	mk_lang_assert(gud);
	mk_lang_assert(*gud == mk_lang_false || *gud == mk_lang_true);

	if(*argc >= 2)
	{
		n = *argc;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert((*argv)[i]);
			mk_lang_assert((*argv)[i][0] != mk_lang_tchar_c('\0'));
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/output")))
		{
			command_line->m_output_ptr = (*argv)[1];
			command_line->m_output_len = (*lens)[1];
			(*argc) -= 2;
			(*argv) += 2;
			(*lens) += 2;
			*gud = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_cmd_line(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens, mk_lib_app_cryptor_param_id_pt const failed) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t my_argc;
	mk_lang_types_sint_pt myp_argc;
	mk_lang_tchar_pcpct my_argv;
	mk_lang_tchar_ppcpct myp_argv;
	mk_lang_types_sint_pct my_lens;
	mk_lang_types_sint_ppct myp_lens;
	mk_lang_types_bool_t gud;
	mk_lang_types_bool_pt pgud;

	mk_lang_assert(cryptor);
	mk_lang_assert(command_line);
	mk_lang_assert(argc >= 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(failed);

	command_line->m_config.m_direction = mk_lib_app_cryptor_direction_e_dummy_end;
	command_line->m_config.m_mode = mk_lib_app_cryptor_mode_names_id_e_dummy_end;
	command_line->m_config.m_alg = mk_lib_app_cryptor_alg_names_id_e_dummy_end;
	command_line->m_config.m_padding = mk_lib_crypto_padding_names_id_e_dummy_end;
	command_line->m_config.m_kdf = mk_lang_false;
	command_line->m_config.m_hash = mk_lib_crypto_hash_names_id_e_dummy_end;
	command_line->m_config.m_cost = ((mk_lang_types_ulong_t)(((mk_lang_types_slong_t)(-1))));
	command_line->m_config.m_password_ptr = mk_lang_null;
	command_line->m_config.m_password_len = 0;
	command_line->m_config.m_salt_ptr = mk_lang_null;
	command_line->m_config.m_salt_len = 0;
	command_line->m_input_ptr = mk_lang_null;
	command_line->m_input_len = 0;
	command_line->m_output_ptr = mk_lang_null;
	command_line->m_output_len = 0;
	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(argv[i]);
		mk_lang_assert(argv[i][0] != mk_lang_tchar_c('\0'));
		mk_lang_assert(lens[i] >= 0);
	}
	my_argc = argc; myp_argc = &my_argc;
	my_argv = argv; myp_argv = &my_argv;
	my_lens = lens; myp_lens = &my_lens;
	--my_argc; ++my_argv; ++my_lens;
	pgud = &gud;
	do
	{
		gud = mk_lang_false;
		err = mk_lib_app_cryptor_prrw_construct_cmd_line_direction(command_line, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_lib_app_cryptor_prrw_construct_cmd_line_mode     (command_line, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_lib_app_cryptor_prrw_construct_cmd_line_alg      (command_line, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_lib_app_cryptor_prrw_construct_cmd_line_padding  (command_line, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_lib_app_cryptor_prrw_construct_cmd_line_kdf      (command_line, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_lib_app_cryptor_prrw_construct_cmd_line_hash     (command_line, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_lib_app_cryptor_prrw_construct_cmd_line_cost     (command_line, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_lib_app_cryptor_prrw_construct_cmd_line_password (command_line, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_lib_app_cryptor_prrw_construct_cmd_line_salt     (command_line, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_lib_app_cryptor_prrw_construct_cmd_line_input    (command_line, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_lib_app_cryptor_prrw_construct_cmd_line_output   (command_line, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
	}while(gud);
	err = mk_lib_app_cryptor_prrw_args_check(cryptor, command_line->m_config.m_direction, command_line->m_config.m_mode, command_line->m_config.m_alg, command_line->m_config.m_padding, command_line->m_config.m_kdf, command_line->m_config.m_hash, command_line->m_config.m_cost, command_line->m_config.m_password_ptr, command_line->m_config.m_password_len, command_line->m_config.m_salt_ptr, command_line->m_config.m_salt_len, failed); mk_lang_check_rereturn(err);
	if(*failed == mk_lib_app_cryptor_param_id_e_dummy_end)
	{
		if(!(command_line->m_input_len  >= 1 && command_line->m_input_ptr )){ *failed = mk_lib_app_cryptor_param_id_e_input ; return 0; }
		if(!(command_line->m_output_len >= 1 && command_line->m_output_ptr)){ *failed = mk_lib_app_cryptor_param_id_e_output; return 0; }
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_parse(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct d;
	mk_lang_types_sint_t s;
	mk_lang_bui_uintptr_t bui;
	mk_lib_app_cryptor_direction_t direction;
	mk_lib_app_cryptor_mode_names_id_t mode;
	mk_lib_app_cryptor_alg_names_id_t alg;
	mk_lib_crypto_padding_names_id_t padding;
	mk_lang_types_bool_t kdf;
	mk_lib_crypto_hash_names_id_t hash;
	mk_lang_types_ulong_t cost;
	mk_sl_cui_uint8_pct password_ptr;
	mk_lang_types_sint_t password_len;
	mk_sl_cui_uint8_pct salt_ptr;
	mk_lang_types_sint_t salt_len;
	mk_lang_types_sint_t err;

	mk_lang_assert(cryptor);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	d = data_buf;
	s = data_len;
	mk_lang_check_return(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; direction    = ((mk_lib_app_cryptor_direction_t    )(bui));
	mk_lang_check_return(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; mode         = ((mk_lib_app_cryptor_mode_names_id_t)(bui));
	mk_lang_check_return(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; alg          = ((mk_lib_app_cryptor_alg_names_id_t )(bui));
	mk_lang_check_return(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; padding      = ((mk_lib_crypto_padding_names_id_t  )(bui));
	mk_lang_check_return(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; kdf          = ((mk_lang_types_bool_t              )(bui));
	mk_lang_check_return(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; hash         = ((mk_lib_crypto_hash_names_id_t     )(bui));
	mk_lang_check_return(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; cost         = ((mk_lang_types_ulong_t             )(bui));
	mk_lang_check_return(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; password_ptr = ((mk_sl_cui_uint8_pct               )(bui));
	mk_lang_check_return(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; password_len = ((mk_lang_types_sint_t              )(bui));
	mk_lang_check_return(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; salt_ptr     = ((mk_sl_cui_uint8_pct               )(bui));
	mk_lang_check_return(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; salt_len     = ((mk_lang_types_sint_t              )(bui));
	err = mk_lib_app_cryptor_prrw_construct_args_do_check(cryptor, direction, mode, alg, padding, kdf, hash, cost, password_ptr, password_len, salt_ptr, salt_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_destroy(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(cryptor);

	err = mk_sl_speedometer_rw_destroy(&cryptor->m_speedometer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_mode(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_types_sint_t mode_id;
	mk_lang_types_sint_t alg_max;
	mk_lang_types_sint_t alg_id;
	mk_lang_types_sint_t mode_alg_id;
	mk_lib_app_cryptor_mode_stream_any1_id_t mode_stream_id;

	mk_lang_assert(cryptor);
	mk_lang_assert(cryptor->m_config.m_mode != mk_lib_app_cryptor_mode_names_id_e_dummy_end);
	mk_lang_assert(cryptor->m_config.m_alg != mk_lib_app_cryptor_alg_names_id_e_dummy_end);

	mode_id = ((mk_lang_types_sint_t)(cryptor->m_config.m_mode));
	alg_max = ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end));
	alg_id = ((mk_lang_types_sint_t)(cryptor->m_config.m_alg));
	mode_alg_id = mode_id * alg_max + alg_id;
	mk_lang_clobber(&mode_stream_id);
	switch(mode_alg_id)
	{
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_cbc )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_cbc_aes_128 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_cbc )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_cbc_aes_192 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_cbc )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_cbc_aes_256 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_cbc )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_serpent)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_cbc_serpent ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_cfb )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_cfb_aes_128 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_cfb )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_cfb_aes_192 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_cfb )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_cfb_aes_256 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_cfb )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_serpent)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_cfb_serpent ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_cfb8)) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_cfb8_aes_128; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_cfb8)) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_cfb8_aes_192; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_cfb8)) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_cfb8_aes_256; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_cfb8)) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_serpent)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_cfb8_serpent; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_ctr )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_ctr_aes_128 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_ctr )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_ctr_aes_192 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_ctr )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_ctr_aes_256 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_ctr )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_serpent)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_ctr_serpent ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_ecb )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_ecb_aes_128 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_ecb )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_ecb_aes_192 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_ecb )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_ecb_aes_256 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_ecb )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_serpent)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_ecb_serpent ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_ofb )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_ofb_aes_128 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_ofb )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_ofb_aes_192 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_ofb )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_ofb_aes_256 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_ofb )) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_serpent)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_ofb_serpent ; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_pcbc)) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_pcbc_aes_128; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_pcbc)) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_pcbc_aes_192; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_pcbc)) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_pcbc_aes_256; break;
		case ((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_names_id_e_pcbc)) * ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_app_cryptor_alg_names_id_e_serpent)): mode_stream_id = mk_lib_app_cryptor_mode_stream_any1_id_e_pcbc_serpent; break;
		default: mk_lang_assert_false(); break;
	}
	mk_lib_app_cryptor_mode_stream_any2_rw_construct(&cryptor->m_mode_stream, mode_stream_id);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_derive_keys(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lib_crypto_kdf_pbkdf2_any_id_t id;
	mk_lang_types_sint_t key_len;
	mk_lang_types_sint_t iv_len;
	mk_sl_cui_uint8_pct password_ptr;
	mk_lang_types_sint_t password_len;
	mk_sl_cui_uint8_pct salt_ptr;
	mk_lang_types_sint_t salt_len;
	mk_lang_types_ulong_t cost;
	mk_sl_cui_uint8_t key_material[mk_lib_app_cryptor_mode_stream_any2_key_len_v + 64];
	mk_lib_app_cryptor_mode_stream_any2_key_t mode_key;
	mk_sl_cui_uint8_pct hmac_key_ptr;
	mk_lang_types_sint_t hmac_key_len;

	mk_lang_assert(cryptor);

	id = ((mk_lib_crypto_kdf_pbkdf2_any_id_t)(cryptor->m_config.m_hash));
	key_len = mk_lib_app_cryptor_mode_stream_any2_ro_get_key_len(&cryptor->m_mode_stream); mk_lang_assert(key_len == 16 || key_len == 24 || key_len == 32);
	iv_len = mk_lib_app_cryptor_mode_stream_any2_ro_get_iv_len(&cryptor->m_mode_stream); mk_lang_assert(iv_len == 0 || iv_len == 16);
	password_ptr = cryptor->m_config.m_password_ptr;
	password_len = cryptor->m_config.m_password_len;
	salt_ptr = cryptor->m_config.m_salt_ptr;
	salt_len = cryptor->m_config.m_salt_len;
	cost = cryptor->m_config.m_cost;
	mk_lib_crypto_kdf_pbkdf2_any_fn(id, password_ptr, password_len, salt_ptr, salt_len, cost, mk_lang_countof(key_material), &key_material[0]);
	mk_sl_cui_uint8_memcpy_fn(&mode_key.m_data.m_uint8s[0], &key_material[0], mk_lib_app_cryptor_mode_stream_any2_key_len_v);
	switch(cryptor->m_config.m_direction)
	{
		case mk_lib_app_cryptor_direction_e_encrypt: mk_lib_app_cryptor_mode_stream_any2_rw_set_key_enc(&cryptor->m_mode_stream, &mode_key); break;
		case mk_lib_app_cryptor_direction_e_decrypt: mk_lib_app_cryptor_mode_stream_any2_rw_set_key_dec(&cryptor->m_mode_stream, &mode_key); break;
		case mk_lib_app_cryptor_direction_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	hmac_key_ptr = &key_material[mk_lib_app_cryptor_mode_stream_any2_key_len_v];
	hmac_key_len = mk_lang_countof(key_material) - mk_lib_app_cryptor_mode_stream_any2_key_len_v;
	mk_lib_crypto_mac_hmac_stream_any2_rw_init(&cryptor->m_hmac_stream, hmac_key_ptr, ((mk_lang_types_usize_t)(hmac_key_len)));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_init_objects(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(cryptor);

	err = mk_lib_app_cryptor_prrw_construct_mode(cryptor); mk_lang_check_rereturn(err);
	mk_lib_crypto_mac_hmac_stream_any2_rw_construct(&cryptor->m_hmac_stream, mk_lib_crypto_mac_hmac_stream_any1_id_e_sha2_256); /* todo from command line */
	err = mk_lib_app_cryptor_prrw_derive_keys(cryptor); mk_lang_check_rereturn(err);
	err = mk_sl_speedometer_rw_construct(&cryptor->m_speedometer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pt mk_lib_app_cryptor_prrw_get_buffer_1_ptr(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	mk_lang_assert(cryptor);

	ptr = &cryptor->m_buffer.m_data.m_uint8s[0];
	ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(ptr, mk_lib_app_cryptor_buff_algn)));
	ptr += 0 * mk_lib_app_cryptor_buff_size;
	return ptr;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_get_buffer_1_len(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(cryptor);

	((mk_lang_types_void_t)(cryptor));
	len = mk_lib_app_cryptor_buff_size;
	return len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pt mk_lib_app_cryptor_prrw_get_buffer_2_ptr(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	mk_lang_assert(cryptor);

	ptr = &cryptor->m_buffer.m_data.m_uint8s[0];
	ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(ptr, mk_lib_app_cryptor_buff_algn)));
	ptr += 1 * mk_lib_app_cryptor_buff_size;
	return ptr;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_get_buffer_2_len(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(cryptor);

	((mk_lang_types_void_t)(cryptor));
	len = mk_lib_app_cryptor_buff_size + mk_lib_app_cryptor_buff_extra;
	return len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_handle_iv_enc(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const in_ptr, mk_lang_types_sint_t const in_len, mk_sl_cui_uint8_pt const out_ptr, mk_lang_types_sint_t const out_len, mk_lang_types_sint_pt const in_used, mk_lang_types_sint_pt const out_used) mk_lang_noexcept
{
	mk_lang_types_sint_t iv_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt iv_ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(cryptor);
	mk_lang_assert(in_ptr || in_len == 0);
	mk_lang_assert(in_len >= 0);
	mk_lang_assert(out_ptr || out_len == 0);
	mk_lang_assert(out_len >= 0);
	mk_lang_assert(in_used);
	mk_lang_assert(out_used);
	mk_lang_assert(!cryptor->m_iv_handled);

	iv_len = mk_lib_app_cryptor_mode_stream_any2_ro_get_iv_len(&cryptor->m_mode_stream);
	iv_ptr = &cryptor->m_mode_iv.m_data.m_uint8s[0];
	mk_lang_check_return(out_len >= iv_len);
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		err = mk_sl_random_generate(iv_ptr, iv_len); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_sl_cui_uint8_memclr_fn(iv_ptr, ((mk_lang_types_usize_t)(iv_len))); /* todo constexpr random */
	}
	mk_lib_app_cryptor_mode_stream_any2_rw_set_iv(&cryptor->m_mode_stream, &cryptor->m_mode_iv);
	mk_sl_cui_uint8_memcpy_fn(out_ptr, iv_ptr, ((mk_lang_types_usize_t)(iv_len)));
	cryptor->m_iv_handled = mk_lang_true;
	*in_used = 0;
	*out_used = iv_len;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_handle_iv_dec(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const in_ptr, mk_lang_types_sint_t const in_len, mk_sl_cui_uint8_pt const out_ptr, mk_lang_types_sint_t const out_len, mk_lang_types_sint_pt const in_used, mk_lang_types_sint_pt const out_used) mk_lang_noexcept
{
	mk_lang_types_sint_t iv_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt iv_ptr mk_lang_constexpr_init;

	mk_lang_assert(cryptor);
	mk_lang_assert(in_ptr || in_len == 0);
	mk_lang_assert(in_len >= 0);
	mk_lang_assert(out_ptr || out_len == 0);
	mk_lang_assert(out_len >= 0);
	mk_lang_assert(in_used);
	mk_lang_assert(out_used);
	mk_lang_assert(!cryptor->m_iv_handled);

	iv_len = mk_lib_app_cryptor_mode_stream_any2_ro_get_iv_len(&cryptor->m_mode_stream);
	iv_ptr = &cryptor->m_mode_iv.m_data.m_uint8s[0];
	mk_lang_check_return(in_len >= iv_len);
	mk_sl_cui_uint8_memcpy_fn(iv_ptr, in_ptr, ((mk_lang_types_usize_t)(iv_len)));
	mk_lib_app_cryptor_mode_stream_any2_rw_set_iv(&cryptor->m_mode_stream, &cryptor->m_mode_iv);
	cryptor->m_iv_handled = mk_lang_true;
	*in_used = iv_len;
	*out_used = 0;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_handle_iv(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const in_ptr, mk_lang_types_sint_t const in_len, mk_sl_cui_uint8_pt const out_ptr, mk_lang_types_sint_t const out_len, mk_lang_types_sint_pt const in_used, mk_lang_types_sint_pt const out_used) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(cryptor);
	mk_lang_assert(in_ptr || in_len == 0);
	mk_lang_assert(in_len >= 0);
	mk_lang_assert(out_ptr || out_len == 0);
	mk_lang_assert(out_len >= 0);
	mk_lang_assert(in_used);
	mk_lang_assert(out_used);

	if(cryptor->m_iv_handled)
	{
		*in_used = 0;
		*out_used = 0;
	}
	else
	{
		switch(cryptor->m_config.m_direction)
		{
			case mk_lib_app_cryptor_direction_e_encrypt: err = mk_lib_app_cryptor_prrw_handle_iv_enc(cryptor, in_ptr, in_len, out_ptr, out_len, in_used, out_used); mk_lang_check_rereturn(err); break;
			case mk_lib_app_cryptor_direction_e_decrypt: err = mk_lib_app_cryptor_prrw_handle_iv_dec(cryptor, in_ptr, in_len, out_ptr, out_len, in_used, out_used); mk_lang_check_rereturn(err); break;
			case mk_lib_app_cryptor_direction_e_dummy_end: mk_lang_assert_false(); break;
			default: mk_lang_assert_false(); break;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_crypt_enc(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const in_ptr, mk_lang_types_sint_t const in_len, mk_sl_cui_uint8_pt const out_ptr, mk_lang_types_sint_t const out_len, mk_lang_types_sint_pt const in_used, mk_lang_types_sint_pt const out_used) mk_lang_noexcept
{
	mk_lang_types_usize_t out_consumed mk_lang_constexpr_init;

	mk_lang_assert(cryptor);
	mk_lang_assert(in_ptr || in_len == 0);
	mk_lang_assert(in_len >= 0);
	mk_lang_assert(out_ptr || out_len == 0);
	mk_lang_assert(out_len >= 0);
	mk_lang_assert(in_used);
	mk_lang_assert(out_used);
	mk_lang_assert(cryptor->m_config.m_direction == mk_lib_app_cryptor_direction_e_encrypt);

	mk_lib_crypto_mac_hmac_stream_any2_rw_append(&cryptor->m_hmac_stream, in_ptr, ((mk_lang_types_usize_t)(in_len)));
	mk_lib_app_cryptor_mode_stream_any2_rw_encrypt(&cryptor->m_mode_stream, in_ptr, ((mk_lang_types_usize_t)(in_len)), out_ptr, ((mk_lang_types_usize_t)(out_len)), &out_consumed);
	*in_used = in_len;
	mk_lang_assert(out_consumed <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max))); *out_used = ((mk_lang_types_sint_t)(out_consumed));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_crypt_dec(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const in_ptr, mk_lang_types_sint_t const in_len, mk_sl_cui_uint8_pt const out_ptr, mk_lang_types_sint_t const out_len, mk_lang_types_sint_pt const in_used, mk_lang_types_sint_pt const out_used) mk_lang_noexcept
{
	mk_lang_types_usize_t out_consumed mk_lang_constexpr_init;

	mk_lang_assert(cryptor);
	mk_lang_assert(in_ptr || in_len == 0);
	mk_lang_assert(in_len >= 0);
	mk_lang_assert(out_ptr || out_len == 0);
	mk_lang_assert(out_len >= 0);
	mk_lang_assert(in_used);
	mk_lang_assert(out_used);
	mk_lang_assert(cryptor->m_config.m_direction == mk_lib_app_cryptor_direction_e_decrypt);

	mk_lib_app_cryptor_mode_stream_any2_rw_decrypt(&cryptor->m_mode_stream, in_ptr, ((mk_lang_types_usize_t)(in_len)), out_ptr, ((mk_lang_types_usize_t)(out_len)), &out_consumed);
	mk_lib_crypto_mac_hmac_stream_any2_rw_append(&cryptor->m_hmac_stream, out_ptr, out_consumed);
	*in_used = in_len;
	mk_lang_assert(out_consumed <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max))); *out_used = ((mk_lang_types_sint_t)(out_consumed));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_crypt2(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const in_ptr, mk_lang_types_sint_t const in_len, mk_sl_cui_uint8_pt const out_ptr, mk_lang_types_sint_t const out_len, mk_lang_types_sint_pt const in_used, mk_lang_types_sint_pt const out_used) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(cryptor);
	mk_lang_assert(in_ptr || in_len == 0);
	mk_lang_assert(in_len >= 0);
	mk_lang_assert(out_ptr || out_len == 0);
	mk_lang_assert(out_len >= 0);
	mk_lang_assert(in_used);
	mk_lang_assert(out_used);

	switch(cryptor->m_config.m_direction)
	{
		case mk_lib_app_cryptor_direction_e_encrypt: err = mk_lib_app_cryptor_prrw_crypt_enc(cryptor, in_ptr, in_len, out_ptr, out_len, in_used, out_used); mk_lang_check_rereturn(err); break;
		case mk_lib_app_cryptor_direction_e_decrypt: err = mk_lib_app_cryptor_prrw_crypt_dec(cryptor, in_ptr, in_len, out_ptr, out_len, in_used, out_used); mk_lang_check_rereturn(err); break;
		case mk_lib_app_cryptor_direction_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_crypt(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const input_ptr, mk_lang_types_sint_t const input_len, mk_sl_cui_uint8_pt const output_ptr, mk_lang_types_sint_t const output_len, mk_lang_types_sint_pt const input_consumed, mk_lang_types_sint_pt const output_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt last_chunk mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct in_ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out_ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t idx mk_lang_constexpr_init;
	mk_lang_types_sint_t free_space mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t in_consumed mk_lang_constexpr_init;
	mk_lang_types_sint_t out_consumed mk_lang_constexpr_init;
	mk_lang_types_sint_t to_crypt mk_lang_constexpr_init;
	mk_lang_types_sint_t cap mk_lang_constexpr_init;

	mk_lang_assert(cryptor);
	mk_lang_assert(input_ptr || input_len == 0);
	mk_lang_assert(input_len >= 0);
	mk_lang_assert(output_ptr || output_len == 0);
	mk_lang_assert(output_len >= 0);
	mk_lang_assert(input_consumed);
	mk_lang_assert(output_consumed);

	in_ptr = input_ptr;
	in_len = input_len;
	out_ptr = output_ptr;
	out_len = output_len;
	last_chunk = &cryptor->m_last_chunk_buf[0];
	cap = mk_lang_countof(cryptor->m_last_chunk_buf);
	idx = cryptor->m_last_chunk_idx;
	free_space = cap - idx;
	if(idx != 0)
	{
		to_copy = mk_lang_max(0, in_len - cap);
		to_copy = mk_lang_min(to_copy, free_space);
		mk_sl_cui_uint8_memcpy_fn(&last_chunk[idx], in_ptr, ((mk_lang_types_usize_t)(to_copy)));
		in_ptr += to_copy;
		in_len -= to_copy;
		idx += to_copy;
		if(idx == cap)
		{
			idx = 0;
			err = mk_lib_app_cryptor_prrw_crypt2(cryptor, &last_chunk[0], cap, out_ptr, out_len, &in_consumed, &out_consumed); mk_lang_check_rereturn(err);
			mk_lang_assert(in_consumed >= 0);
			mk_lang_assert(in_consumed <= cap);
			mk_lang_assert(in_consumed == cap);
			mk_lang_assert(out_consumed >= 0);
			mk_lang_assert(out_consumed <= out_len);
			out_ptr += out_consumed;
			out_len -= out_consumed;
		}
	}
	if(idx == 0)
	{
		to_crypt = mk_lang_max(0, in_len - cap);
		err = mk_lib_app_cryptor_prrw_crypt2(cryptor, in_ptr, to_crypt, out_ptr, out_len, &in_consumed, &out_consumed); mk_lang_check_rereturn(err);
		mk_lang_assert(in_consumed >= 0);
		mk_lang_assert(in_consumed <= to_crypt);
		mk_lang_assert(in_consumed == to_crypt);
		mk_lang_assert(out_consumed >= 0);
		mk_lang_assert(out_consumed <= out_len);
		in_ptr += in_consumed;
		in_len -= in_consumed;
		out_ptr += out_consumed;
		out_len -= out_consumed;
	}
	free_space = cap - idx;
	to_copy = mk_lang_min(free_space, in_len);
	mk_sl_cui_uint8_memcpy_fn(&last_chunk[idx], in_ptr, ((mk_lang_types_usize_t)(to_copy)));
	in_ptr += to_copy;
	in_len -= to_copy;
	idx += to_copy;
	if(in_len != 0)
	{
		mk_lang_assert(idx == cap);
		mk_lang_assert(in_len < cap);
		err = mk_lib_app_cryptor_prrw_crypt2(cryptor, &last_chunk[0], in_len, out_ptr, out_len, &in_consumed, &out_consumed); mk_lang_check_rereturn(err);
		mk_lang_assert(in_consumed >= 0);
		mk_lang_assert(in_consumed <= in_len);
		mk_lang_assert(in_consumed == in_len);
		mk_lang_assert(out_consumed >= 0);
		mk_lang_assert(out_consumed <= out_len);
		out_ptr += out_consumed;
		out_len -= out_consumed;
		mk_sl_cui_uint8_memmov_fn(&last_chunk[0], &last_chunk[in_len], in_len);
		mk_sl_cui_uint8_memcpy_fn(&last_chunk[cap - in_len], in_ptr, in_len);
		in_ptr += in_len;
		in_len -= in_len;
	}
	cryptor->m_last_chunk_idx = idx;
	in_consumed = input_len - in_len;
	out_consumed = output_len - out_len;
	*input_consumed = in_consumed;
	*output_consumed = out_consumed;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_append_chunk(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const input_ptr, mk_lang_types_sint_t const input_len, mk_sl_cui_uint8_pt const output_ptr, mk_lang_types_sint_t const output_len, mk_lang_types_sint_pt const input_consumed, mk_lang_types_sint_pt const output_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out_ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t in_used mk_lang_constexpr_init;
	mk_lang_types_sint_t out_used mk_lang_constexpr_init;

	mk_lang_assert(cryptor);
	mk_lang_assert(input_ptr || input_len == 0);
	mk_lang_assert(input_len >= 0);
	mk_lang_assert(output_ptr || output_len == 0);
	mk_lang_assert(output_len >= 0);
	mk_lang_assert(input_consumed);
	mk_lang_assert(output_consumed);

	in_ptr = input_ptr;
	in_len = input_len;
	out_ptr = output_ptr;
	out_len = output_len;
	err = mk_lib_app_cryptor_prrw_handle_iv(cryptor, in_ptr, in_len, out_ptr, out_len, &in_used, &out_used); mk_lang_check_rereturn(err);
	mk_lang_assert(in_used >= 0);
	mk_lang_assert(in_used <= in_len);
	mk_lang_assert(out_used >= 0);
	mk_lang_assert(out_used <= out_len);
	in_ptr += in_used; in_len -= in_used;
	out_ptr += out_used; out_len -= out_used;
	err = mk_lib_app_cryptor_prrw_crypt(cryptor, in_ptr, in_len, out_ptr, out_len, &in_used, &out_used); mk_lang_check_rereturn(err);
	mk_lang_assert(in_used >= 0);
	mk_lang_assert(in_used <= in_len);
	mk_lang_assert(out_used >= 0);
	mk_lang_assert(out_used <= out_len);
	in_ptr += in_used; in_len -= in_used;
	out_ptr += out_used; out_len -= out_used;
	in_used = input_len - in_len;
	out_used = output_len - out_len;
	*input_consumed = in_used;
	*output_consumed = out_used;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_finish_enc(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pt const output_ptr, mk_lang_types_sint_t const output_len, mk_lang_types_sint_pt const consumed, mk_lang_types_bool_pt const succeeded) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt out_ptr;
	mk_lang_types_sint_t out_len;
	mk_lang_types_sint_t block_len;
	mk_sl_cui_uint8_pct remaining_stream_ptr;
	mk_lang_types_sint_t remaining_stream_len;
	mk_sl_cui_uint8_pct remaining_last_block_ptr;
	mk_lang_types_sint_t remaining_last_block_len;
	mk_lang_types_sint_t remaining_all_len_;
	mk_lang_types_sint_t remaining_all_mod;
	mk_lang_types_sint_t to_copy_len_first;
	mk_lang_types_sint_t to_copy_len_second;
	mk_sl_cui_uint8_pct to_copy_ptr_first;
	mk_sl_cui_uint8_pct to_copy_ptr_second;
	mk_sl_cui_uint8_t last_block[2 * mk_lib_app_cryptor_mode_stream_any2_msg_len_v];
	mk_lib_crypto_padding_any_id_t id;
	mk_lang_types_sint_t padding_added;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t in_consumed;
	mk_lang_types_sint_t out_consumed;
	mk_lang_types_usize_t used;
	mk_lang_types_sint_t tag_len;
	mk_lang_types_sint_t cap mk_lang_constexpr_init;

	mk_lang_assert(cryptor);
	mk_lang_assert(output_ptr || output_len == 0);
	mk_lang_assert(output_len >= 0);
	mk_lang_assert(consumed);
	mk_lang_assert(cryptor->m_config.m_direction == mk_lib_app_cryptor_direction_e_encrypt);
	mk_lang_assert(succeeded);

	out_ptr = output_ptr;
	out_len = output_len;
	cap = mk_lang_countof(cryptor->m_last_chunk_buf);
	block_len = mk_lib_app_cryptor_mode_stream_any2_ro_get_msg_len(&cryptor->m_mode_stream); mk_lang_assert(mk_lang_pow2_is(block_len)); mk_lang_assert(block_len >= 1); mk_lang_assert(block_len <= 16);
	remaining_stream_ptr = mk_lib_app_cryptor_mode_stream_any2_rw_get_ptr(&cryptor->m_mode_stream); mk_lang_assert(remaining_stream_ptr);
	remaining_stream_len = mk_lib_app_cryptor_mode_stream_any2_ro_get_idx(&cryptor->m_mode_stream); mk_lang_assert(remaining_stream_len >= 0); mk_lang_assert(remaining_stream_len < block_len);
	remaining_last_block_ptr = &cryptor->m_last_chunk_buf[0]; mk_lang_assert(remaining_last_block_ptr);
	remaining_last_block_len = cryptor->m_last_chunk_idx; mk_lang_assert(remaining_last_block_len >= 0); mk_lang_assert(remaining_last_block_len <= cap);
	remaining_all_len_ = remaining_stream_len + remaining_last_block_len;
	remaining_all_mod = remaining_all_len_ & (block_len - 1);
	to_copy_len_first = remaining_all_mod - mk_lang_min(remaining_all_mod, remaining_last_block_len); mk_lang_assert(to_copy_len_first >= 0); mk_lang_assert(to_copy_len_first <= block_len); mk_lang_assert(to_copy_len_first <= remaining_stream_len);
	to_copy_len_second = remaining_all_mod - to_copy_len_first; mk_lang_assert(to_copy_len_second >= 0); mk_lang_assert(to_copy_len_second <= block_len); mk_lang_assert(to_copy_len_second <= remaining_last_block_len);
	to_copy_ptr_first = remaining_stream_ptr + remaining_stream_len - to_copy_len_first;
	to_copy_ptr_second = remaining_last_block_ptr + remaining_last_block_len - to_copy_len_second;
	mk_sl_cui_uint8_memcpy_fn(&last_block[0 * to_copy_len_first], to_copy_ptr_first, ((mk_lang_types_usize_t)(to_copy_len_first)));
	mk_sl_cui_uint8_memcpy_fn(&last_block[1 * to_copy_len_first], to_copy_ptr_second, ((mk_lang_types_usize_t)(to_copy_len_second)));
	id = ((mk_lib_crypto_padding_any_id_t)(cryptor->m_config.m_padding));
	padding_added = mk_lib_crypto_padding_any_pad(id, &last_block[0], remaining_all_mod, block_len, mk_lang_countof(last_block) - remaining_all_mod); mk_lang_assert(padding_added >= 1);
	err = mk_lib_app_cryptor_prrw_crypt(cryptor, &last_block[remaining_all_mod], padding_added, out_ptr, out_len, &in_consumed, &out_consumed); mk_lang_check_rereturn(err);
	mk_lang_assert(in_consumed >= 0);
	mk_lang_assert(in_consumed <= padding_added);
	mk_lang_assert(out_consumed >= 0);
	mk_lang_assert(out_consumed <= out_len);
	mk_lang_check_return(in_consumed == padding_added);
	out_ptr += out_consumed;
	out_len -= out_consumed;
	err = mk_lib_app_cryptor_prrw_crypt2(cryptor, &cryptor->m_last_chunk_buf[0], cryptor->m_last_chunk_idx, out_ptr, out_len, &in_consumed, &out_consumed); mk_lang_check_rereturn(err);
	mk_lang_assert(in_consumed >= 0);
	mk_lang_assert(in_consumed <= cryptor->m_last_chunk_idx);
	mk_lang_assert(out_consumed >= 0);
	mk_lang_assert(out_consumed <= out_len);
	mk_lang_check_return(in_consumed == cryptor->m_last_chunk_idx);
	cryptor->m_last_chunk_idx -= in_consumed;
	out_ptr += out_consumed;
	out_len -= out_consumed;
	mk_lang_assert(mk_lib_app_cryptor_mode_stream_any2_ro_get_idx(&cryptor->m_mode_stream) == 0);
	mk_lib_crypto_mac_hmac_stream_any2_rw_finish(&cryptor->m_hmac_stream, out_ptr, ((mk_lang_types_usize_t)(out_len)), &used);
	tag_len = mk_lib_crypto_mac_hmac_stream_any2_ro_get_tag_len(&cryptor->m_hmac_stream);
	mk_lang_check_return(((mk_lang_types_sint_t)(used)) == tag_len);
	out_ptr += ((mk_lang_types_sint_t)(used));
	out_len -= ((mk_lang_types_sint_t)(used));
	out_consumed = output_len - out_len;
	*consumed = out_consumed;
	*succeeded = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_finish_dec(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pt const output_ptr, mk_lang_types_sint_t const output_len, mk_lang_types_sint_pt const consumed, mk_lang_types_bool_pt const succeeded) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt out_ptr;
	mk_lang_types_sint_t out_len;
	mk_lang_types_sint_t msg_len;
	mk_lang_types_sint_t tag_len;
	mk_lang_types_sint_t idx;
	mk_sl_cui_uint8_pct last_chunk;
	mk_lang_types_sint_t cap;
	mk_sl_cui_uint8_pct data_msg;
	mk_sl_cui_uint8_pct data_tag;
	mk_lang_types_sint_t rest;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t in_used;
	mk_lang_types_sint_t out_used;
	mk_sl_cui_uint8_t msg[2 * mk_lib_crypto_mode_stream_any2_msg_len_v];
	mk_sl_cui_uint8_t tag_computed_buf[mk_lib_crypto_mac_hmac_stream_any2_digest_len_v];
	mk_lang_types_usize_t tag_computed_len;
	mk_lib_crypto_padding_any_id_t padding_id;
	mk_lang_types_sint_t padding_len;

	mk_lang_assert(cryptor);
	mk_lang_assert(output_ptr || output_len == 0);
	mk_lang_assert(output_len >= 0);
	mk_lang_assert(consumed);
	mk_lang_assert(cryptor->m_config.m_direction == mk_lib_app_cryptor_direction_e_decrypt);
	mk_lang_assert(succeeded);

	out_ptr = output_ptr;
	out_len = output_len;
	msg_len = mk_lib_app_cryptor_mode_stream_any2_ro_get_msg_len(&cryptor->m_mode_stream);
	tag_len = mk_lib_crypto_mac_hmac_stream_any2_ro_get_tag_len(&cryptor->m_hmac_stream);
	idx = cryptor->m_last_chunk_idx;
	last_chunk = &cryptor->m_last_chunk_buf[0];
	cap = mk_lang_countof(cryptor->m_last_chunk_buf);
	mk_lang_check_return(idx >= msg_len + tag_len);
	data_msg = last_chunk + idx - tag_len - msg_len;
	data_tag = last_chunk + idx - tag_len;
	rest = idx - tag_len - msg_len;
	err = mk_lib_app_cryptor_prrw_crypt2(cryptor, last_chunk, rest, out_ptr, out_len, &in_used, &out_used); mk_lang_check_rereturn(err);
	mk_lang_assert(in_used >= 0);
	mk_lang_assert(in_used <= rest);
	mk_lang_check_return(in_used == rest);
	mk_lang_assert(out_used >= 0);
	mk_lang_assert(out_used <= out_len);
	out_ptr += out_used;
	out_len -= out_used;
	err = mk_lib_app_cryptor_prrw_crypt2(cryptor, data_msg, msg_len, &msg[0], mk_lang_countof(msg), &in_used, &out_used); mk_lang_check_rereturn(err);
	mk_lang_assert(in_used >= 0);
	mk_lang_assert(in_used <= msg_len);
	mk_lang_assert(in_used == msg_len);
	mk_lang_assert(out_used >= 0);
	mk_lang_assert(out_used <= mk_lang_countof(msg));
	mk_lang_assert(out_used == msg_len);
	mk_lib_crypto_mac_hmac_stream_any2_rw_finish(&cryptor->m_hmac_stream, &tag_computed_buf[0], mk_lang_countof(tag_computed_buf), &tag_computed_len);
	mk_lang_assert(((mk_lang_types_sint_t)(tag_computed_len)) == tag_len);
	*succeeded = mk_sl_cui_uint8_memcmp_fn(data_tag, &tag_computed_buf[0], tag_computed_len) == 0;
	if(!*succeeded)
	{
		return 0;
	}
	padding_id = ((mk_lib_crypto_padding_any_id_t)(cryptor->m_config.m_padding));
	padding_len = mk_lib_crypto_padding_any_unpad(padding_id, &msg[0], msg_len);
	mk_lang_check_return(padding_len >= 1);
	mk_lang_assert(padding_len <= msg_len);
	rest = msg_len - padding_len;
	mk_lang_check_return(out_len >= rest);
	mk_sl_cui_uint8_memcpy_fn(out_ptr, &msg[0], ((mk_lang_types_usize_t)(rest)));
	out_ptr += rest;
	out_len -= rest;
	rest = output_len - out_len;
	*consumed = rest;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_finish(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pt const output_ptr, mk_lang_types_sint_t const output_len, mk_lang_types_sint_pt const consumed, mk_lang_types_bool_pt const succeeded) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(cryptor);
	mk_lang_assert(output_ptr || output_len == 0);
	mk_lang_assert(output_len >= 0);
	mk_lang_assert(consumed);
	mk_lang_assert(succeeded);

	switch(cryptor->m_config.m_direction)
	{
		case mk_lib_app_cryptor_direction_e_encrypt: err = mk_lib_app_cryptor_prrw_finish_enc(cryptor, output_ptr, output_len, consumed, succeeded); mk_lang_check_rereturn(err); break;
		case mk_lib_app_cryptor_direction_e_decrypt: err = mk_lib_app_cryptor_prrw_finish_dec(cryptor, output_ptr, output_len, consumed, succeeded); mk_lang_check_rereturn(err); break;
		case mk_lib_app_cryptor_direction_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_construct_args(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_direction_t const direction, mk_lib_app_cryptor_mode_names_id_t const mode, mk_lib_app_cryptor_alg_names_id_t const alg, mk_lib_crypto_padding_names_id_t const padding, mk_lang_types_bool_t const kdf, mk_lib_crypto_hash_names_id_t const hash, mk_lang_types_ulong_t const cost, mk_sl_cui_uint8_pct const password_ptr, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt_ptr, mk_lang_types_sint_t const salt_len) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_construct_args(cryptor, direction, mode, alg, padding, kdf, hash, cost, password_ptr, password_len, salt_ptr, salt_len);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_construct_config(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_config_pct const config) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_construct_config(cryptor, config);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_construct_cmd_line(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens, mk_lib_app_cryptor_param_id_pt const failed) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_construct_cmd_line(cryptor, command_line, argc, argv, lens, failed);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_construct_parse(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_construct_parse(cryptor, data_buf, data_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_destroy(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_destroy(cryptor);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_init_objects(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_init_objects(cryptor);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_cui_uint8_pt mk_lib_app_cryptor_rw_get_buffer_1_ptr(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_get_buffer_1_ptr(cryptor);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_get_buffer_1_len(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_get_buffer_1_len(cryptor);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_cui_uint8_pt mk_lib_app_cryptor_rw_get_buffer_2_ptr(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_get_buffer_2_ptr(cryptor);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_get_buffer_2_len(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_get_buffer_2_len(cryptor);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_append_chunk(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const input_ptr, mk_lang_types_sint_t const input_len, mk_sl_cui_uint8_pt const output_ptr, mk_lang_types_sint_t const output_len, mk_lang_types_sint_pt const input_consumed, mk_lang_types_sint_pt const output_consumed) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_append_chunk(cryptor, input_ptr, input_len, output_ptr, output_len, input_consumed, output_consumed);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_finish(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pt const output_ptr, mk_lang_types_sint_t const output_len, mk_lang_types_sint_pt const consumed, mk_lang_types_bool_pt const succeeded) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_finish(cryptor, output_ptr, output_len, consumed, succeeded);
}


#endif
