#ifndef mk_include_guard_mk_clib_app_cryptor_c
#define mk_include_guard_mk_clib_app_cryptor_c
#include "mk_clib_app_cryptor.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bitness.h"
#include "mk_lang_check.h"
#include "mk_lang_command_line.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_entry_point.h"
#include "mk_lang_exe_name.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_stdout.h"
#include "mk_lang_str_len.h"
#include "mk_lang_str_lit.h"
#include "mk_lang_str_match.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_names.h"
#include "mk_lib_crypto_mode_names.h"
#include "mk_lib_crypto_mode_stream.h"
#include "mk_lib_crypto_mode_stream_any1.h"
#include "mk_lib_crypto_mode_stream_any2.h"
#include "mk_lib_crypto_mode_stream_names.h"
#include "mk_lib_crypto_padding_names.h"
#include "mk_lib_fmt.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_io_reader_file.h"
#include "mk_sl_io_writer_file.h"
#include "mk_sl_speedometer.h"
#include "mk_sl_stopwatch.h"


#if mk_lang_bitness_is_16
#define mk_clib_app_cryptor_buff_size 4 * 1024
#define mk_clib_app_cryptor_buff_algn 4 * 1024
#elif mk_lang_bitness_is_32
#define mk_clib_app_cryptor_buff_size 64 * 1024
#define mk_clib_app_cryptor_buff_algn 64 * 1024
#elif mk_lang_bitness_is_64
#define mk_clib_app_cryptor_buff_size 256 * 1024
#define mk_clib_app_cryptor_buff_algn 256 * 1024
#endif
union mk_clib_app_cryptor_buff_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_lang_roundup_add(mk_clib_app_cryptor_buff_size + mk_lib_crypto_mode_stream_any2_msg_len_v, mk_clib_app_cryptor_buff_algn)];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_clib_app_cryptor_buff_data_u mk_clib_app_cryptor_buff_data_t;
struct mk_clib_app_cryptor_buff_s
{
	mk_clib_app_cryptor_buff_data_t m_data;
};
typedef struct mk_clib_app_cryptor_buff_s mk_clib_app_cryptor_buff_t;
mk_lang_typedef(mk_clib_app_cryptor_buff);

enum mk_clib_app_cryptor_direction_e
{
	mk_clib_app_cryptor_direction_e_encrypt,
	mk_clib_app_cryptor_direction_e_decrypt,
	mk_clib_app_cryptor_direction_e_dummy_end
};
typedef enum mk_clib_app_cryptor_direction_e mk_clib_app_cryptor_direction_t;

struct mk_clib_app_cryptor_command_line_s
{
	mk_clib_app_cryptor_direction_t m_direction;
	mk_lib_crypto_mode_names_id_t m_mode;
	mk_lib_crypto_alg_names_id_t m_alg;
	mk_lib_crypto_padding_names_id_t m_padding;
};
typedef struct mk_clib_app_cryptor_command_line_s mk_clib_app_cryptor_command_line_t;


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_cryptor_s
{
	mk_clib_app_cryptor_command_line_t m_command_line;
	mk_lib_crypto_mode_stream_any2_t m_mode_stream;
	mk_clib_app_cryptor_buff_t m_buffer;
};
typedef struct mk_clib_app_cryptor_s mk_clib_app_cryptor_t;
mk_lang_typedef(mk_clib_app_cryptor);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_prrw_parse_cmdline_direction(mk_clib_app_cryptor_pt const cryptor, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(cryptor);
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
			mk_lang_assert((*argv)[i][0] != '\0');
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/direction")))
		{
			if(mk_lang_str_match_t((*argv)[1], (*lens)[1], mk_lang_str_lit("encrypt")))
			{
				cryptor->m_command_line.m_direction = mk_clib_app_cryptor_direction_e_encrypt;
				(*argc) -= 2;
				(*argv) += 2;
				(*lens) += 2;
				*gud = mk_lang_true;
			}
			else if(mk_lang_str_match_t((*argv)[1], (*lens)[1], mk_lang_str_lit("decrypt")))
			{
				cryptor->m_command_line.m_direction = mk_clib_app_cryptor_direction_e_decrypt;
				(*argc) -= 2;
				(*argv) += 2;
				(*lens) += 2;
				*gud = mk_lang_true;
			}
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_prrw_parse_cmdline_mode(mk_clib_app_cryptor_pt const cryptor, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(cryptor);
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
			mk_lang_assert((*argv)[i][0] != '\0');
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/mode")))
		{
			cryptor->m_command_line.m_mode = mk_lib_crypto_mode_names_get_id_from_str_t((*argv)[1], (*lens)[1]);
			mk_lang_check_return(cryptor->m_command_line.m_mode != mk_lib_crypto_mode_names_id_e_dummy_end);
			(*argc) -= 2;
			(*argv) += 2;
			(*lens) += 2;
			*gud = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_prrw_parse_cmdline_alg(mk_clib_app_cryptor_pt const cryptor, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(cryptor);
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
			mk_lang_assert((*argv)[i][0] != '\0');
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/alg")))
		{
			cryptor->m_command_line.m_alg = mk_lib_crypto_alg_names_get_id_from_str_t((*argv)[1], (*lens)[1]);
			mk_lang_check_return(cryptor->m_command_line.m_alg != mk_lib_crypto_alg_names_id_e_dummy_end);
			(*argc) -= 2;
			(*argv) += 2;
			(*lens) += 2;
			*gud = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_prrw_parse_cmdline_padding(mk_clib_app_cryptor_pt const cryptor, mk_lang_types_sint_pt const argc, mk_lang_tchar_ppcpct const argv, mk_lang_types_sint_ppct const lens, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(cryptor);
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
			mk_lang_assert((*argv)[i][0] != '\0');
			mk_lang_assert((*lens)[i] >= 0);
		}
		if(mk_lang_str_match_t((*argv)[0], (*lens)[0], mk_lang_str_lit("/padding")))
		{
			cryptor->m_command_line.m_padding = mk_lib_crypto_padding_names_get_id_from_str_t((*argv)[1], (*lens)[1]);
			mk_lang_check_return(cryptor->m_command_line.m_padding != mk_lib_crypto_padding_names_id_e_dummy_end);
			(*argc) -= 2;
			(*argv) += 2;
			(*lens) += 2;
			*gud = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_prrw_parse_cmdline_all(mk_clib_app_cryptor_pt const cryptor, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
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
	mk_lang_assert(argc >= 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(argv[i]);
		mk_lang_assert(argv[i][0] != '\0');
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
		err = mk_clib_app_cryptor_prrw_parse_cmdline_direction(cryptor, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_clib_app_cryptor_prrw_parse_cmdline_mode(cryptor, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_clib_app_cryptor_prrw_parse_cmdline_alg(cryptor, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
		err = mk_clib_app_cryptor_prrw_parse_cmdline_padding(cryptor, myp_argc, myp_argv, myp_lens, pgud); mk_lang_check_rereturn(err);
	}while(gud);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_prrw_construct_sub_objects(mk_clib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_types_sint_t mode_id;
	mk_lang_types_sint_t alg_max;
	mk_lang_types_sint_t alg_id;
	mk_lang_types_sint_t mode_alg_id;
	mk_lib_crypto_mode_stream_any1_id_t mode_stream_id;

	mk_lang_assert(cryptor);
	mk_lang_check_return(cryptor->m_command_line.m_direction != mk_clib_app_cryptor_direction_e_dummy_end);
	mk_lang_check_return(cryptor->m_command_line.m_mode != mk_lib_crypto_mode_names_id_e_dummy_end);
	mk_lang_check_return(cryptor->m_command_line.m_alg != mk_lib_crypto_alg_names_id_e_dummy_end);
	mk_lang_check_return(cryptor->m_command_line.m_padding != mk_lib_crypto_padding_names_id_e_dummy_end);

	mode_id = ((mk_lang_types_sint_t)(cryptor->m_command_line.m_mode));
	alg_max = ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end));
	alg_id = ((mk_lang_types_sint_t)(cryptor->m_command_line.m_alg));
	mode_alg_id = mode_id * alg_max + alg_id;
	switch(mode_alg_id)
	{
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_cbc )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_cbc_aes_128 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_cbc )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_cbc_aes_192 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_cbc )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_cbc_aes_256 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_cbc )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_serpent)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_cbc_serpent ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_cfb )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_cfb_aes_128 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_cfb )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_cfb_aes_192 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_cfb )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_cfb_aes_256 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_cfb )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_serpent)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_cfb_serpent ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_cfb8)) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_cfb8_aes_128; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_cfb8)) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_cfb8_aes_192; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_cfb8)) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_cfb8_aes_256; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_cfb8)) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_serpent)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_cfb8_serpent; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_ctr )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_ctr_aes_128 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_ctr )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_ctr_aes_192 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_ctr )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_ctr_aes_256 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_ctr )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_serpent)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_ctr_serpent ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_ecb )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_ecb_aes_128 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_ecb )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_ecb_aes_192 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_ecb )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_ecb_aes_256 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_ecb )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_serpent)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_ecb_serpent ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_ofb )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_ofb_aes_128 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_ofb )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_ofb_aes_192 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_ofb )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_ofb_aes_256 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_ofb )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_serpent)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_ofb_serpent ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_pcbc)) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_pcbc_aes_128; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_pcbc)) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_pcbc_aes_192; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_pcbc)) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_pcbc_aes_256; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_pcbc)) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_serpent)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_pcbc_serpent; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_xts )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_128)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_xts_aes_128 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_xts )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_192)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_xts_aes_192 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_xts )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_aes_256)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_xts_aes_256 ; break;
		case ((mk_lang_types_sint_t)(mk_lib_crypto_mode_names_id_e_xts )) * ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_alg_names_id_e_serpent)): mode_stream_id = mk_lib_crypto_mode_stream_any1_id_e_xts_serpent ; break;
		default: mk_lang_assert_false(); break;
	}
	mk_lib_crypto_mode_stream_any2_rw_construct(&cryptor->m_mode_stream, mode_id);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_rw_construct_void(mk_clib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_assert(cryptor);

	cryptor->m_command_line.m_direction = mk_clib_app_cryptor_direction_e_dummy_end;
	cryptor->m_command_line.m_mode = mk_lib_crypto_mode_names_id_e_dummy_end;
	cryptor->m_command_line.m_alg = mk_lib_crypto_alg_names_id_e_dummy_end;
	cryptor->m_command_line.m_padding = mk_lib_crypto_padding_names_id_e_dummy_end;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_rw_construct_cmdline(mk_clib_app_cryptor_pt const cryptor, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(cryptor);

	err = mk_clib_app_cryptor_rw_construct_void(cryptor); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_prrw_parse_cmdline_all(cryptor, argc, argv, lens); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_prrw_construct_sub_objects(cryptor); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_work(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_clib_app_cryptor_t cryptor;

	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t key_len;
	mk_lang_tchar_pct arg_alg_buf;
	mk_lang_tchar_pct arg_input_name_buf;
	mk_lang_tchar_pct arg_output_name_buf;
	mk_lang_types_sint_t arg_alg_len;
	mk_lang_types_sint_t arg_input_name_len;
	mk_lang_types_sint_t arg_output_name_len;
	mk_sl_speedometer_t speedometer;
	mk_lang_types_bool_t want;
	mk_lib_crypto_mode_stream_any1_id_t id;
	mk_sl_cui_uint8_pt ptr;
	mk_clib_app_cryptor_buff_t buff;
	mk_lang_types_sint_t err;
	mk_sl_io_reader_file_t input_file;
	mk_sl_io_writer_file_t output_file;
	mk_lang_types_sint_t read;
	mk_lang_types_sint_t written;
	mk_lang_types_usize_t encrypted;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t progress_str_a[64]; /* todo max */
	mk_lang_tchar_t progress_str_b[2 * mk_lang_countof(progress_str_a)]; /* todo max */
	mk_sl_cui_uint8_t ff;
	mk_lib_crypto_mode_stream_any2_key_t key;
	mk_lib_crypto_mode_stream_any2_t stream;

	mk_lang_assert(argc >= 2);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	err = mk_clib_app_cryptor_rw_construct_cmdline(&cryptor, argc, argv, lens); mk_lang_check_rereturn(err);

	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(argv[i]);
		mk_lang_assert(argv[i][0] != mk_lang_tchar_c('\0'));
		mk_lang_assert(lens[i] >= 0);
	}
	arg_alg_buf = argv[1];
	arg_input_name_buf = argv[2];
	arg_output_name_buf = argv[3];
	arg_alg_len = lens[1];
	arg_input_name_len = lens[2]; ((mk_lang_types_void_t)(arg_input_name_len)); /* todo file reader not zero terminated */
	arg_output_name_len = lens[3]; ((mk_lang_types_void_t)(arg_output_name_len)); /* todo file reader not zero terminated */
	err = mk_sl_speedometer_rw_construct(&speedometer); mk_lang_check_rereturn(err);
	id = 0; //id = mk_clib_app_cryptor_find_alg(arg_alg_buf, arg_alg_len);
	mk_lang_check_return(id != mk_lib_crypto_mode_stream_any1_id_e_dummy_end);
	mk_lib_crypto_mode_stream_any2_rw_construct(&stream, id);
	key_len = mk_lib_crypto_mode_stream_any2_ro_get_key_len(&stream); mk_lang_assert(key_len == 16 || key_len == 24 || key_len == 32);
	mk_sl_cui_uint8_set_max(&ff);
	mk_sl_cui_uint8_memset_fn(&key.m_data.m_uint8s[0], &ff, ((mk_lang_types_usize_t)(key_len)));
	mk_lib_crypto_mode_stream_any2_rw_set_key_enc(&stream, &key);
	ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(&buff.m_data.m_uchars[0], mk_clib_app_cryptor_buff_algn)));
	err = mk_sl_io_reader_file_open_t(&input_file, arg_input_name_buf); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_open_t(&output_file, arg_output_name_buf); mk_lang_check_rereturn(err);
	for(;;)
	{
		err = mk_sl_io_reader_file_read(&input_file, ptr, mk_clib_app_cryptor_buff_size, &read); mk_lang_check_rereturn(err);
		if(read == 0)
		{
			break;
		}
		mk_lib_crypto_mode_stream_any2_rw_encrypt(&stream, ptr, ((mk_lang_types_usize_t)(read)), ptr, mk_clib_app_cryptor_buff_size + mk_lib_crypto_mode_stream_any2_msg_len_v, &encrypted);
		err = mk_sl_io_writer_file_write(&output_file, ptr, read, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written = read);
		err = mk_sl_speedometer_rw_append(&speedometer, read); mk_lang_check_rereturn(err);
		err = mk_sl_speedometer_rw_report(&speedometer, &progress_str_a[0], mk_lang_countof(progress_str_a), &want, &len); mk_lang_check_rereturn(err); mk_lang_assert(!want || len >= 1); mk_lang_assert(!want || len <= mk_lang_countof(progress_str_a));
		if(want)
		{
			len = mk_lib_fmt_t_snnprintf(&progress_str_b[0], mk_lang_countof(progress_str_b), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("\x0d                                                            \x0d%t ")), &progress_str_a[0], len); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(progress_str_b));
			err = mk_lang_stdout_no_redirect_print_t(&progress_str_b[0], len); mk_lang_check_rereturn(err);
		}
	}
	len = mk_lib_fmt_t_snnprintf(&progress_str_b[0], mk_lang_countof(progress_str_b), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("\x0d                                                            \x0d"))); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(progress_str_b));
	err = mk_lang_stdout_no_redirect_print_t(&progress_str_b[0], len); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_close(&output_file); mk_lang_check_rereturn(err);
	err = mk_sl_io_reader_file_close(&input_file); mk_lang_check_rereturn(err);
	err = mk_sl_speedometer_rw_destroy(&speedometer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_print_algs(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_crypto_mode_stream_names_id_t id;
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t slen;
	mk_lang_tchar_t buf[0xff];
	mk_lang_types_sint_t err;

	n = mk_lib_crypto_mode_stream_any1_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		id = ((mk_lib_crypto_mode_stream_names_id_t)(i));
		str = mk_lib_crypto_mode_stream_names_get_str_buf(id); mk_lang_assert(str); mk_lang_assert(str[0] != '\0');
		len = mk_lib_crypto_mode_stream_names_get_str_len(id); mk_lang_assert(len >= 1); mk_lang_assert(len <= 0xff);
		slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), str, len); mk_lang_check_return(slen >= 1);
		err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_usage(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_tchar_pct exe_name;
	mk_lang_types_sint_t exe_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t buf[512];

	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != mk_lang_tchar_c('\0'));
	mk_lang_assert(lens[0] >= 1);

	exe_name = mk_lang_exe_name_get_t(argv[0]); mk_lang_check_return(exe_name); mk_lang_check_return(exe_name[0] != mk_lang_tchar_c('\0'));
	exe_len = lens[0] - ((mk_lang_types_sint_t)(exe_name - argv[0])); mk_lang_check_return(exe_len >= 1);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("Example usage:")); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("%t CBC-AES-256 message.txt message.dat")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("%t CTR-Serpent video.avi video.dat")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("Available algorithms:")); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_print_algs(); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_cpuid_init();
	err = mk_sl_stopwatch_init(); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_stopwatch_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#if mk_lang_entry_point_have


#include "mk_win_dll_kernel_process.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_wargs(mk_lang_types_sint_t const argc, mk_lang_types_wchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	if(argc == 1)
	{
		err = mk_clib_app_cryptor_usage(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc >= 2);
		err = mk_clib_app_cryptor_work(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_cryptor_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	mk_lang_assert(peb);

	err = mk_clib_app_cryptor_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_win(mk_win_dll_kernel_process_get_command_line(), &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_wargs(argc, &argv[0], &lens[0]);
	err = mk_clib_app_cryptor_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#else


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_cryptor_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t lens[16];

	err = mk_clib_app_cryptor_init(); mk_lang_check_rereturn(err);
	if(argc == 1)
	{
		lens[0] = mk_lang_str_len_n(argv[0]);
		err = mk_clib_app_cryptor_usage(argc, argv, &lens[0]); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc >= 2);
		mk_lang_check_return(argc <= mk_lang_countof(lens));
		n = argc;
		for(i = 0; i != n; ++i)
		{
			lens[i] = mk_lang_str_len_t(argv[i]);
		}
		err = mk_clib_app_cryptor_work(argc, argv, &lens[0]); mk_lang_check_rereturn(err);
	}
	err = mk_clib_app_cryptor_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#endif


#endif
