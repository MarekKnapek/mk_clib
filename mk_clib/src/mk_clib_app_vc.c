#undef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS


#include "mk_clib_app_vc.h"

#include "mk_lang_bool.h"
#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_vc.h"
#include "mk_sl_mallocator_lang.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"

#include <stdio.h> /* printf fflush fopen fclose fread fwrite EOF */
#include <stdlib.h> /* EXIT_SUCCESS EXIT_FAILURE */


union mk_clib_app_vc_data_u
{
	mk_sl_cui_uint8_t m_u8s[512];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_clib_app_vc_data_u mk_clib_app_vc_data_t;

struct mk_clib_app_vc_request_givemem_s
{
	mk_lang_types_usize_t m_code;
	mk_sl_cui_uint8_pt m_mem;
	mk_lang_types_usize_t m_len;
};
typedef struct mk_clib_app_vc_request_givemem_s mk_clib_app_vc_request_givemem_t;

union mk_clib_app_vc_request_u
{
	mk_lang_types_usize_t m_code;
	mk_clib_app_vc_request_givemem_t m_givemem;
};
typedef union mk_clib_app_vc_request_u mk_clib_app_vc_request_t;

struct mk_clib_app_vc_response_ok_s
{
	mk_lang_types_usize_t m_code;
};
typedef struct mk_clib_app_vc_response_ok_s mk_clib_app_vc_response_ok_t;

struct mk_clib_app_vc_response_wantmem_s
{
	mk_lang_types_usize_t m_code;
	mk_lang_types_usize_t m_mem_len;
	mk_lang_types_usize_t m_mem_align;
};
typedef struct mk_clib_app_vc_response_wantmem_s mk_clib_app_vc_response_wantmem_t;

union mk_clib_app_vc_response_u
{
	mk_lang_types_usize_t m_code;
	mk_clib_app_vc_response_ok_t m_ok;
	mk_clib_app_vc_response_wantmem_t m_wantmem;
};
typedef union mk_clib_app_vc_response_u mk_clib_app_vc_response_t;
typedef mk_clib_app_vc_response_t const mk_clib_app_vc_response_ct;
typedef mk_clib_app_vc_response_t* mk_clib_app_vc_response_pt;
typedef mk_clib_app_vc_response_t const* mk_clib_app_vc_response_pct;


#define mk_clib_app_vc_check_return(x) do{ if(!(x)){ mk_lang_unlikely return 1; } }while(0)
#define mk_clib_app_vc_check2_return(x) do{ mk_lang_types_sint_t err; err = ((int)(x)); if(err != 0){ mk_lang_unlikely return err; } }while(0)
#define mk_clib_app_vc_check_goto_exret(x) do{ if(!(x)){ mk_lang_unlikely goto exret; } }while(0)
#define mk_clib_app_vc_check2_goto_exret(x) do{ mk_lang_types_sint_t err; err = ((int)(x)); if(err != 0){ mk_lang_unlikely ret = err; goto exret; } }while(0)


mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_clib_app_vc_strlen(mk_lang_types_pchar_pct const str) mk_lang_noexcept
{
	mk_lang_types_pchar_pct p;
	mk_lang_types_usize_t r;

	mk_lang_assert(str);

	p = str;
	while(*p){ ++p; }
	r = ((mk_lang_types_usize_t)(p - str));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_parse_strlen(mk_lang_types_pchar_pct const str, mk_lang_types_sint_pt const strlen) mk_lang_noexcept
{
	mk_lang_types_usize_t strlen_;

	mk_lang_assert(str);
	mk_lang_assert(strlen);

	strlen_ = mk_clib_app_vc_strlen(str);
	mk_clib_app_vc_check_return(strlen_ <= mk_lang_limits_sint_max);
	*strlen = ((mk_lang_types_sint_t)(strlen_));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_parse_u32(mk_lang_types_pchar_pct const str, mk_lang_types_ulong_pt const ul) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t len;
	mk_sl_cui_uint32_t u32;

	mk_lang_assert(str);
	mk_lang_assert(ul);

	tsi = mk_clib_app_vc_parse_strlen(str, &len); mk_clib_app_vc_check2_return(tsi);
	tsi = mk_sl_cui_uint32_from_str_dec_n(&u32, str, len); mk_clib_app_vc_check_return(tsi == len);
	mk_sl_cui_uint32_to_bi_ulong(&u32, ul);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_work_1(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pct const* const argv) mk_lang_noexcept
{
#if 0
	mk_lang_types_sint_t ret;
	mk_lang_types_void_pt mem;
	mk_lang_types_usize_t mem_len;
	mk_lang_types_sint_t chunk_len;
	FILE* ifile;
	FILE* ofile;
	mk_lang_types_pchar_pct input_file_path;
	mk_sl_cui_uint8_pct password;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t password_len;
	mk_lang_types_ulong_t pim;
	mk_lang_types_pchar_pct output_file_path;
	mk_lang_exception_t ex;
	mk_sl_cui_uint8_pt memory;
	mk_lib_vc_t vc;
	mk_clib_app_vc_response_t response;
	mk_sl_cui_uint8_pt response_ptr;
	mk_lang_types_usize_t response_len;
	mk_clib_app_vc_data_t vc_data;
	mk_lang_types_bool_t data_used;
	mk_lang_types_usize_t request;
	mk_sl_cui_uint8_pt input_buff;
	mk_lang_types_usize_t input_len;

	mk_lang_types_usize_t output;
	mk_sl_cui_uint8_pt buff;
	mk_lang_types_usize_t buff_len;
	mk_lang_types_usize_t read;
	mk_lang_types_usize_t written;

	mk_lang_assert(argv);

	ret = 1;
	mem = mk_lang_null;
	mem_len = 128 * 1024;
	chunk_len = 512;
	ifile = mk_lang_null;
	ofile = mk_lang_null;
	mk_lang_cpuid_init();
	mk_sl_mallocator_lang_init();
	mk_clib_app_vc_check_goto_exret(argc == 5);
	mk_clib_app_vc_check_goto_exret(argv[1]);
	mk_clib_app_vc_check_goto_exret(argv[2]);
	mk_clib_app_vc_check_goto_exret(argv[3]);
	mk_clib_app_vc_check_goto_exret(argv[4]);
	input_file_path = argv[1];
	password = ((mk_sl_cui_uint8_pct)(argv[2]));
	tsi = mk_clib_app_vc_parse_strlen(argv[2], &password_len); mk_clib_app_vc_check2_goto_exret(tsi);
	tsi = mk_clib_app_vc_parse_u32(argv[3], &pim); mk_clib_app_vc_check2_goto_exret(tsi);
	output_file_path = argv[4];
	mk_lang_exception_make_none(&ex);
	ifile = fopen(input_file_path, "rb"); mk_clib_app_vc_check_goto_exret(ifile);
	ofile = fopen(output_file_path, "wb"); mk_clib_app_vc_check_goto_exret(ofile);
	data_used = mk_lang_false;
	request = mk_lib_vc_request_e_dowork;
	input_buff = mk_lang_null;
	input_len = 0;
	response_ptr = ((mk_sl_cui_uint8_pt)(&response));
	response_len = sizeof(response);
	mk_lib_vc_req(&vc, mk_lib_vc_request_e_init, mk_lang_null, 0, response_ptr, &response_len);
	mk_lang_assert(response_len == sizeof(mk_clib_app_vc_response_ok_t) && response.m_code == mk_lib_vc_response_e_ok);
	for(;;)
	{
		response_len = sizeof(response);
		mk_lib_vc_req(&vc, request, input_buff, input_len, response_ptr, &response_len);
		mk_lang_assert(response_len >= sizeof(response.m_code));
		request = mk_lib_vc_request_e_dowork;
		input_buff = mk_lang_null;
		input_len = 0;
		switch(response.m_code)
		{
			case mk_lib_vc_response_e_ok:
				mk_lang_assert(response_len == sizeof(response.m_ok));
			break;
			case mk_lib_vc_response_e_wantmem:
				mk_lang_assert(response_len == sizeof(response.m_wantmem));
				request = mk_lib_vc_request_e_givemem;
				if(!data_used && response.m_wantmem.m_mem_len <= sizeof(mk_clib_app_vc_data_t) && response.m_wantmem.m_mem_align <= mk_lang_alignof(mk_clib_app_vc_data_t))
				{
					data_used = mk_lang_true;
					input_buff = ((mk_sl_cui_uint8_pt)(&vc_data));
					input_len = sizeof(input_buff);
				}
				else
				{
					mk_sl_mallocator_lang_allocate(&ex, response.m_wantmem.m_mem_len, &mem);
					mk_lang_assert(!mk_lang_exception_is(&ex));
					mk_lang_assert(mem);
					input_buff = ((mk_sl_cui_uint8_pt)(mem));
					input_len = sizeof(input_buff);
				}
			break;
			case mk_lib_vc_response_e_dummy_end:
				mk_lang_assert(0);
			break;
			default:
				mk_lang_assert(0);
			break;
		}
	}
	ret = 0;
	exret:;
	if(ofile){ tsi = fclose(ofile); mk_lang_test(tsi == 0 && tsi != EOF); }
	if(ifile){ tsi = fclose(ifile); mk_lang_test(tsi == 0 && tsi != EOF); }
	if(mem){ mk_sl_mallocator_lang_deallocate(mem, mem_len); }
	mk_sl_mallocator_lang_deinit();
	return ret;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_work(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pct const* const argv) mk_lang_noexcept
{
	mk_lib_vc_pt vc;
	mk_lib_vc_t vcobj;
	mk_lang_types_uint_t resid;
	mk_lib_vc_response_t response;
	mk_lib_vc_request_t request;
	mk_sl_cui_uint8_pct input_buff;
	mk_lang_types_usize_t input_len;
	mk_sl_cui_uint8_pt output_buff;
	mk_lang_types_usize_t output_len;
	mk_lib_vc_response_type_t response_data;
	mk_lib_vc_response_type_pt resp;
	mk_lib_vc_request_type_t request_data;
	mk_lib_vc_request_type_pt reqp;
	mk_lang_types_void_pt mem;
	mk_lang_exception_t ex;
	mk_lang_types_sint_t exit_code;

	mk_lang_assert(argv);

	mk_sl_mallocator_lang_init();
	vc = &vcobj;
	resp = &response_data;
	reqp = &request_data;
	mk_lang_exception_make_none(&ex);
	request = mk_lib_vc_request_e_init;
	input_buff = mk_lang_null;
	input_len = 0;
	output_buff = ((mk_sl_cui_uint8_pt)(&response_data));
	output_len = ((mk_lang_types_usize_pt)(sizeof(response_data)));
	mk_lib_vc_req(vc, request, input_buff, input_len, &resid, output_buff, &output_len); mk_lang_assert(resid >= 0 && resid < mk_lib_vc_response_e_dummy_end); response = ((mk_lib_vc_response_t)(resid));
	mk_lang_assert(resid == mk_lib_vc_response_e_ok);
	mk_lang_assert(output_len == 0);
	request = mk_lib_vc_request_e_dowork;
	output_len = ((mk_lang_types_usize_pt)(sizeof(response_data)));
	for(;;)
	{
		mk_lib_vc_req(vc, request, input_buff, input_len, &resid, output_buff, &output_len); mk_lang_assert(resid >= 0 && resid < mk_lib_vc_response_e_dummy_end); response = ((mk_lib_vc_response_t)(resid));
		switch(response)
		{
			case mk_lib_vc_response_e_ok:
				mk_lang_assert(output_len == 0);
				request = mk_lib_vc_request_e_dowork;
				input_buff = mk_lang_null;
				input_len = 0;
				output_buff = ((mk_sl_cui_uint8_pt)(&response_data));
				output_len = ((mk_lang_types_usize_t)(sizeof(response_data)));
			break;
			case mk_lib_vc_response_e_allocmem:
				mk_lang_assert(output_len == sizeof(resp->m_allocmem));
				mk_sl_mallocator_lang_allocate(&ex, resp->m_allocmem.m_memlen, &mem);
				mk_lang_assert(!mk_lang_exception_is(&ex));
				mk_lang_assert(mem);
				reqp->m_fullfill_allocmem.m_mem = ((mk_sl_cui_uint8_pt)(mem));
				request = mk_lib_vc_request_e_fullfill_allocmem;
				input_buff = ((mk_sl_cui_uint8_pct)(&reqp->m_fullfill_allocmem));
				input_len = ((mk_lang_types_usize_t)(sizeof(reqp->m_fullfill_allocmem)));
				output_buff = ((mk_sl_cui_uint8_pt)(&response_data));
				output_len = ((mk_lang_types_usize_t)(sizeof(response_data)));
			break;
			case mk_lib_vc_response_e_readargc:
				mk_lang_assert(output_len == 0);
				reqp->m_fullfill_readargc.m_argc = argc - 1;
				input_buff = ((mk_sl_cui_uint8_pct)(&reqp->m_fullfill_readargc));
				input_len = ((mk_lang_types_usize_t)(sizeof(reqp->m_fullfill_readargc)));
				request = mk_lib_vc_request_e_fullfill_readargc;
				output_buff = ((mk_sl_cui_uint8_pt)(&response_data));
				output_len = ((mk_lang_types_usize_t)(sizeof(response_data)));
			break;
			case mk_lib_vc_response_e_freemem:
				mk_lang_assert(output_len == sizeof(resp->m_freemem));
				mk_sl_mallocator_lang_deallocate(resp->m_freemem.m_mem, resp->m_freemem.m_memlen);
				input_buff = mk_lang_null;
				input_len = 0;
				request = mk_lib_vc_request_e_fullfill_freemem;
				output_buff = ((mk_sl_cui_uint8_pt)(&response_data));
				output_len = ((mk_lang_types_usize_t)(sizeof(response_data)));
			break;
			case mk_lib_vc_response_e_done:
				mk_lang_assert(output_len == sizeof(resp->m_done));
				exit_code = resp->m_done.m_exit_code;
				goto endloop;
			break;
			case mk_lib_vc_response_e_dummy_end:
				mk_lang_assert(0);
			break;
			default:
				mk_lang_assert(0);
			break;
		}
	}
	endloop:;
	mk_sl_mallocator_lang_deinit();
	return exit_code;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_pchar_pct mk_clib_app_vc_get_exe_name(mk_lang_types_pchar_pct const arg) mk_lang_noexcept
{
	mk_lang_types_pchar_pct r;
	mk_lang_types_pchar_pct p;

	mk_lang_assert(arg);

	r = arg;
	for(p = r; *p != '\0'; ++p)
	{
		if(*p == '/' || *p == '\\')
		{
			r = p + 1;
		}
	}
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_usage(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pct const* const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi;

	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);

	mk_clib_app_vc_check_return(argv[0]);
	tsi = printf("Example usage:\n"); mk_clib_app_vc_check_return(tsi > 0);
	tsi = printf("%s volume.vc Hunter2 1234 volume.raw\n", mk_clib_app_vc_get_exe_name(argv[0])); mk_clib_app_vc_check_return(tsi > 0);
	tsi = fflush(mk_lang_null); mk_clib_app_vc_check_return(tsi == 0 && tsi != EOF);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_vc_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pct const* const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi;

	mk_clib_app_vc_check_return(argv);
	if(argc == 1)
	{
		tsi = mk_clib_app_vc_usage(argc, argv);
	}
	else
	{
		tsi = mk_clib_app_vc_work(argc, argv);
	}
	return tsi == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
