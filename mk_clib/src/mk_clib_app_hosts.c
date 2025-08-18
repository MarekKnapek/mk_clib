#ifndef mk_include_guard_mk_clib_app_hosts_c
#define mk_include_guard_mk_clib_app_hosts_c
#include "mk_clib_app_hosts.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_command_line.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_entry_point.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_stdout.h"
#include "mk_lang_string.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha2_256.h"
#include "mk_lib_iip_base32_encoder.h"
#include "mk_lib_iip_base64_decoder.h"
#include "mk_lib_iip_cp_destination.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_dynamic_ring.h"
#include "mk_sl_io_reader_file.h"
#include "mk_sl_io_writer_file.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_global_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_cpuid_init();
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_mallocator_global_init(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_global_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lib_iip_cp_mallocator_global_deinit(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_global_main(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	#define mk_clib_app_hosts_buf_len (4 * 1024)
	#define mk_clib_app_hosts_buf_alg (4 * 1024)
	#define mk_clib_app_hosts_b32_prefix "http://"
	#define mk_clib_app_hosts_b32_suffix ".b32.i2p"
	#define mk_clib_app_hosts_b32_cert_null "null"
	#define mk_clib_app_hosts_b32_cert_key_0_0 "key(ElGamal, DSA/SHA-1)"
	#define mk_clib_app_hosts_b32_cert_key_0_1 "key(ElGamal, ECDSA/SHA-256/P256)"
	#define mk_clib_app_hosts_b32_cert_key_0_3 "key(ElGamal, ECDSA/SHA-512/P521)"
	#define mk_clib_app_hosts_b32_cert_key_0_7 "key(ElGamal, EdDSA/SHA-512/Ed25519)"
	#define mk_clib_app_hosts_b32_cert_key_0_11 "key(ElGamal, RedDSA/SHA-512/Ed25519)"
	#define mk_clib_app_hosts_b32_cert_signed "signed"
	#define mk_clib_app_hosts_b32_cert_hidden "hidden"

	mk_sl_cui_uint8_pt read_data_ptr;
	mk_sl_cui_uint8_pt data_ptr;
	mk_sl_cui_uint8_t read_data_buf[mk_lang_roundup_add(mk_clib_app_hosts_buf_len, mk_clib_app_hosts_buf_alg)];
	mk_lang_types_sint_t read_data_cap;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t idx_nl;
	mk_lang_types_sint_t idx_eq;
	mk_lang_types_sint_t i;
	mk_sl_io_reader_file_t reader;
	mk_lang_types_sint_t read_data_len;
	mk_lang_types_sint_t data_len;
	mk_sl_dynamic_ring_u8_t ring;
	mk_lang_types_pchar_t nl_pchar;
	mk_sl_cui_uint8_t nl_u8;
	mk_lang_types_pchar_t eq_pchar;
	mk_sl_cui_uint8_t eq_u8;
	mk_lang_types_pchar_t sp_pchar;
	mk_sl_cui_uint8_t sp_u8;
	mk_lang_types_pchar_t ba_pchar;
	mk_sl_cui_uint8_t ba_u8;
	mk_sl_io_writer_file_t writer;
	mk_sl_cui_uint8_t address_buf[1 * 1024];
	mk_lang_types_sint_t address_len;
	mk_lang_types_sint_t b64_len;
	mk_lang_types_sint_t b64_beg;
	mk_lang_types_sint_t domain_len;
	mk_lang_types_sint_t domain_beg;
	mk_lang_types_sint_t written;
	mk_lang_types_sint_t cert_len;
	mk_lang_types_sint_t b32_len;
	mk_lang_types_sint_t consumed;
	mk_lang_types_bool_t gud;
	mk_lib_crypto_hash_stream_sha2_256_t hasher;
	mk_lib_crypto_hash_stream_sha2_256_digest_t digest;
	mk_lang_types_pchar_t b32_buf[mk_lang_countstr(mk_clib_app_hosts_b32_prefix) + mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5) + mk_lang_countstr(mk_clib_app_hosts_b32_suffix)];
	mk_lang_types_pchar_t b64_buf[1 * 1024];
	mk_lang_types_pchar_pct cert_buf;
	mk_lib_iip_cp_destination_remote_t remote_destination;

	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != mk_lang_tchar_c('\0'));
	mk_lang_assert(lens[0] >= 1);

	nl_pchar = '\x0a'; mk_sl_cui_uint8_from_bi_pchar(&nl_u8, &nl_pchar);
	eq_pchar = '='; mk_sl_cui_uint8_from_bi_pchar(&eq_u8, &eq_pchar);
	sp_pchar = ' '; mk_sl_cui_uint8_from_bi_pchar(&sp_u8, &sp_pchar);
	ba_pchar = '|'; mk_sl_cui_uint8_from_bi_pchar(&ba_u8, &ba_pchar);
	mk_lang_string_memcpy_pc_fn(&b32_buf[0], &mk_clib_app_hosts_b32_prefix[0], mk_lang_countstr(mk_clib_app_hosts_b32_prefix));
	mk_lang_string_memcpy_pc_fn(&b32_buf[mk_lang_countof(b32_buf) - mk_lang_countstr(mk_clib_app_hosts_b32_suffix)], &mk_clib_app_hosts_b32_suffix[0], mk_lang_countstr(mk_clib_app_hosts_b32_suffix));
	read_data_ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(&read_data_buf[0], mk_clib_app_hosts_buf_alg)));
	read_data_cap = mk_clib_app_hosts_buf_len;
	err = mk_sl_dynamic_ring_u8_rw_construct(&ring); mk_lang_check_rereturn(err);
	err = mk_sl_io_reader_file_open_n(&reader, "hosts.txt"); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_open_n(&writer, "hosts.md"); mk_lang_check_rereturn(err);
	for(;;)
	{
		err = mk_sl_io_reader_file_read(&reader, read_data_ptr, read_data_cap, &read_data_len); mk_lang_check_rereturn(err);
		if(read_data_len == 0)
		{
			break;
		}
		err = mk_sl_dynamic_ring_u8_rw_push_back_copy_many(&ring, read_data_ptr, ((mk_lang_types_usize_t)(read_data_len))); mk_lang_check_rereturn(err);
		err = mk_sl_dynamic_ring_u8_rw_consolidate(&ring); mk_lang_check_rereturn(err);
		for(;;)
		{
			data_ptr = mk_sl_dynamic_ring_u8_rw_get_data_a(&ring);
			data_len = mk_sl_dynamic_ring_u8_rw_get_sise_a(&ring);
			n = data_len;
			for(i = 0; i != n; ++i)
			{
				if(mk_sl_cui_uint8_eq(&data_ptr[i], &nl_u8))
				{
					break;
				}
			}
			if(i == n)
			{
				break;
			}
			if(i == 0)
			{
				break;
			}
			idx_nl = i;
			n = idx_nl - 1;
			for(i = 0; i != n; ++i)
			{
				if(mk_sl_cui_uint8_eq(&data_ptr[i], &eq_u8))
				{
					break;
				}
			}
			if(i == n)
			{
				break;
			}
			idx_eq = i;
			domain_beg = 0;
			domain_len = idx_eq;
			b64_beg = idx_eq + 1;
			b64_len = idx_nl - b64_beg - 1;
			mk_lang_string_memcpy_pc_fn(&b64_buf[0], ((mk_lang_types_pchar_pt)(&data_ptr[b64_beg])), ((mk_lang_types_usize_t)(b64_len))); b64_buf[b64_len + 0] = '='; b64_buf[b64_len + 1] = '=';
			mk_lib_iip_base64_decoder_do_check(&b64_buf[0], mk_lang_roundup_mul(b64_len, 4), &address_buf[0], mk_lang_countof(address_buf), &address_len, &gud); mk_lang_check_return(gud);
			err = mk_lib_iip_cp_destination_remote_rw_from_bytes(&remote_destination, &address_buf[0], address_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_check_return(consumed == address_len);
			mk_lib_crypto_hash_stream_sha2_256_init(&hasher);
			mk_lib_crypto_hash_stream_sha2_256_append_u8s(&hasher, &address_buf[0], ((mk_lang_types_usize_t)(address_len)));
			mk_lib_crypto_hash_stream_sha2_256_finish(&hasher, &digest);
			mk_lib_iip_base32_encoder_fn(&digest.m_data.m_uint8s[0], mk_lang_countof(digest.m_data.m_uint8s), &b32_buf[mk_lang_countstr(mk_clib_app_hosts_b32_prefix)], mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5), &b32_len); mk_lang_check_return(b32_len == mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5));
			cert_buf = mk_lang_null;
			cert_len = 0;
			switch(remote_destination.m_certificate.m_cert_type)
			{
				case mk_lib_iip_cp_destination_cert_type_e_null: cert_buf = &mk_clib_app_hosts_b32_cert_null[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_null); break;
				case mk_lib_iip_cp_destination_cert_type_e_hidden: cert_buf = &mk_clib_app_hosts_b32_cert_hidden[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_hidden); break;
				case mk_lib_iip_cp_destination_cert_type_e_signeda: cert_buf = &mk_clib_app_hosts_b32_cert_signed[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_signed); break;
				case mk_lib_iip_cp_destination_cert_type_e_signedb: cert_buf = &mk_clib_app_hosts_b32_cert_signed[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_signed); break;
				case mk_lib_iip_cp_destination_cert_type_e_key:
					if(remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dsa_sha1){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_0[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_0); }
					else if(remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha256_p256){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_1[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_1); }
					else if(remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_7[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_7); }
					else if(remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha512_p521){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_3[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_3); }
					else if(remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_reddsa_sha512_ed25519){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_11[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_11); }
					else{ mk_lang_check_todo(); }
				break;
				case mk_lib_iip_cp_destination_cert_type_e_dummy_end: mk_lang_assert_false(); break;
				default: mk_lang_assert_false(); break;
			}
			mk_lang_clobber(&cert_buf);
			mk_lang_clobber(&cert_len);
			err = mk_sl_io_writer_file_write(&writer, &ba_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_io_writer_file_write(&writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_io_writer_file_write(&writer, ((mk_sl_cui_uint8_pct)(&mk_clib_app_hosts_b32_prefix[0])), mk_lang_countstr(mk_clib_app_hosts_b32_prefix), &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == mk_lang_countstr(mk_clib_app_hosts_b32_prefix));
			err = mk_sl_io_writer_file_write(&writer, &data_ptr[domain_beg], domain_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == domain_len);
			err = mk_sl_io_writer_file_write(&writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_io_writer_file_write(&writer, &ba_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_io_writer_file_write(&writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_io_writer_file_write(&writer, ((mk_sl_cui_uint8_pct)(&b32_buf[0])), mk_lang_countof(b32_buf), &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == mk_lang_countof(b32_buf));
			err = mk_sl_io_writer_file_write(&writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_io_writer_file_write(&writer, &ba_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_io_writer_file_write(&writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_io_writer_file_write(&writer, ((mk_sl_cui_uint8_pct)(cert_buf)), cert_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == cert_len);
			err = mk_sl_io_writer_file_write(&writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_io_writer_file_write(&writer, &ba_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_io_writer_file_write(&writer, &nl_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_dynamic_ring_u8_rw_pop_front_many(&ring, ((mk_lang_types_usize_t)(idx_nl + 1))); mk_lang_check_rereturn(err);
		}
	}
	err = mk_sl_io_reader_file_close(&reader); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_destroy(&ring); mk_lang_check_rereturn(err);
	return 0;
}

#if mk_lang_entry_point_have


#include "mk_win_dll_kernel_process.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_peb_2(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	mk_lang_assert(peb);

	err = mk_clib_app_hosts_global_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_win(mk_win_dll_kernel_process_get_command_line(), &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_global_main(argc, &argv[0], &lens[0]);
	err = mk_clib_app_hosts_global_deinit(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_hosts_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err_b;
	mk_lang_types_sint_t err;

	err_b = mk_clib_app_hosts_peb_2(peb);
	if(err_b == 0)
	{
		err = mk_lang_stdout_println_lit_n("Gud."); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_lang_stdout_println_lit_n("Bad."); mk_lang_check_rereturn(err);
	}
	mk_lang_check_rereturn(err_b);
	return 0;
}


#else


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_args_2(mk_lang_types_sint_t const std_argc, mk_lang_types_pchar_pcpct const std_argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	err = mk_clib_app_hosts_global_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_std(std_argc, std_argv, &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_global_main(argc, &argv[0], &lens[0]); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_global_deinit(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_hosts_args(mk_lang_types_sint_t const std_argc, mk_lang_types_pchar_pcpct const std_argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err_b;
	mk_lang_types_sint_t err;

	err_b = mk_clib_app_hosts_args_2(std_argc, std_argv);
	if(err_b == 0)
	{
		err = mk_lang_stdout_println_lit_n("Gud."); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_lang_stdout_println_lit_n("Bad."); mk_lang_check_rereturn(err);
	}
	mk_lang_check_rereturn(err_b);
	return 0;
}


#endif


#endif
