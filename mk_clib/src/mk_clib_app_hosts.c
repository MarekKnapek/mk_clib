#ifndef mk_include_guard_mk_clib_app_hosts_c
#define mk_include_guard_mk_clib_app_hosts_c
#include "mk_clib_app_hosts.h"

#include "mk_lang_alg_iota.h"
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
#include "mk_lang_typedef.h"
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





#define mk_clib_app_hosts_buf_len (4 * 1024)
#define mk_clib_app_hosts_buf_alg (4 * 1024)
#define mk_clib_app_hosts_domain_prefix "http://"
#define mk_clib_app_hosts_domain_suffix ".i2p"
#define mk_clib_app_hosts_b32_prefix "http://"
#define mk_clib_app_hosts_b32_suffix ".b32.i2p"
#define mk_clib_app_hosts_duplicate_1_prefix " - "
#define mk_clib_app_hosts_duplicate_2_prefix "   - "
#define mk_clib_app_hosts_b32_cert_null "null"
#define mk_clib_app_hosts_b32_cert_key_0_0 "key(ElGamal, DSA/SHA-1)"
#define mk_clib_app_hosts_b32_cert_key_0_1 "key(ElGamal, ECDSA/SHA-256/P256)"
#define mk_clib_app_hosts_b32_cert_key_0_3 "key(ElGamal, ECDSA/SHA-512/P521)"
#define mk_clib_app_hosts_b32_cert_key_0_7 "key(ElGamal, EdDSA/SHA-512/Ed25519)"
#define mk_clib_app_hosts_b32_cert_key_0_11 "key(ElGamal, RedDSA/SHA-512/Ed25519)"
#define mk_clib_app_hosts_b32_cert_signed "signed"
#define mk_clib_app_hosts_b32_cert_hidden "hidden"





#include "mk_sl_fixed_vector_copy.h"
#define mk_sl_fixed_vector_t_name mk_clib_app_hosts_domain
#define mk_sl_fixed_vector_t_element_type mk_sl_cui_uint8_t
#define mk_sl_fixed_vector_t_capacity 64 + 4/*mk_clib_app_hosts_domain_suffix*/ + 1
#define mk_sl_fixed_vector_t_copy_style mk_sl_fixed_vector_copy_use_bitblt
#include "mk_sl_fixed_vector_inl_fileh.h"
#include "mk_sl_fixed_vector_inl_filec.h"
#include "mk_sl_fixed_vector_inl_fileu.h"

#include "mk_sl_vector.h"
#define mk_sl_vector_t_name mk_clib_app_hosts_domains
#define mk_sl_vector_t_element_type mk_clib_app_hosts_domain_t
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_copy_style mk_sl_vector_copy_use_bitblt
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_hosts_b32_with_domains_s
{
	mk_lib_crypto_hash_stream_sha2_256_digest_t m_b32;
	mk_clib_app_hosts_domains_t m_domains;
};
typedef struct mk_clib_app_hosts_b32_with_domains_s mk_clib_app_hosts_b32_with_domains_t;
mk_lang_typedef(mk_clib_app_hosts_b32_with_domains);
#include "mk_lang_warning_msvc_pop.h"

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_b32_with_domains_rw_construct_void(mk_clib_app_hosts_b32_with_domains_pt const x) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	((mk_lang_types_void_t)(x->m_b32));
	err = mk_clib_app_hosts_domains_rw_construct(&x->m_domains); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_b32_with_domains_rw_destroy(mk_clib_app_hosts_b32_with_domains_pt const x) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	err = mk_clib_app_hosts_domains_rw_destroy(&x->m_domains); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_b32_with_domains_rw_construct_b32(mk_clib_app_hosts_b32_with_domains_pt const x, mk_lib_crypto_hash_stream_sha2_256_digest_pct const b32) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(x);
	mk_lang_assert(b32);

	x->m_b32 = *b32;
	err = mk_clib_app_hosts_domains_rw_construct(&x->m_domains); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_b32_with_domains_rw_cmp(mk_clib_app_hosts_b32_with_domains_pct const a, mk_clib_app_hosts_b32_with_domains_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_types_sint_t c;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(cmp);

	c = mk_sl_cui_uint8_memcmp_fn(&a->m_b32.m_data.m_uint8s[0], &b->m_b32.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_256_digest_len_v);
	*cmp = c;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_b32_with_domains_rw_construct_copy(mk_clib_app_hosts_b32_with_domains_pt const dst, mk_clib_app_hosts_b32_with_domains_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dst);
	mk_lang_assert(src);

	dst->m_b32 = src->m_b32;
	err = mk_clib_app_hosts_domains_rw_copy_construct(&dst->m_domains, &src->m_domains); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_b32_with_domains_rw_construct_move(mk_clib_app_hosts_b32_with_domains_pt const dst, mk_clib_app_hosts_b32_with_domains_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dst);
	mk_lang_assert(src);

	dst->m_b32 = src->m_b32;
	err = mk_clib_app_hosts_domains_rw_move_construct(&dst->m_domains, &src->m_domains); mk_lang_check_rereturn(err);
	return 0;
}

#define mk_sl_tree_wavl_t_name mk_clib_app_hosts_tree
#define mk_sl_tree_wavl_t_element_type mk_clib_app_hosts_b32_with_domains_t
#define mk_sl_tree_wavl_t_elements_compare mk_clib_app_hosts_b32_with_domains_rw_cmp
#define mk_sl_tree_wavl_t_mallocatorg_name mk_lib_iip_cp_mallocator_global
#define mk_sl_tree_wavl_t_validate_want 0
#define mk_sl_tree_wavl_t_element_copy_construct mk_clib_app_hosts_b32_with_domains_rw_construct_copy
#define mk_sl_tree_wavl_t_element_move_construct mk_clib_app_hosts_b32_with_domains_rw_construct_move
#define mk_sl_tree_wavl_t_element_destruct mk_clib_app_hosts_b32_with_domains_rw_destroy
#include "mk_sl_tree_wavl_inl_fileh.h"
#include "mk_sl_tree_wavl_inl_filec.h"
#include "mk_sl_tree_wavl_inl_fileu.h"

#define mk_sl_vector_t_name mk_clib_app_phosts_domains
#define mk_sl_vector_t_element_type mk_clib_app_hosts_b32_with_domains_pct
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_copy_style mk_sl_vector_copy_use_bitblt
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_clib_app_hosts_cmp(mk_lang_types_uintptr_t const context, mk_clib_app_hosts_b32_with_domains_pcpct const a, mk_clib_app_hosts_b32_with_domains_pcpct const b) mk_lang_noexcept
{
	mk_lang_types_pchar_t b32str_a[mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_pchar_t b32str_b[mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5)] mk_lang_constexpr_init;
	mk_lang_types_sint_t ca mk_lang_constexpr_init;
	mk_lang_types_bool_t cb mk_lang_constexpr_init;

	mk_lang_assert(&context);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(*a);
	mk_lang_assert(*b);

	((mk_lang_types_void_t)(context));
	mk_lib_iip_base32_encoder_fn(&(*a)->m_b32.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_256_digest_len_v, &b32str_a[0], mk_lang_countof(b32str_a), &len); mk_lang_check_return(len == mk_lang_countof(b32str_a));
	mk_lib_iip_base32_encoder_fn(&(*b)->m_b32.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_256_digest_len_v, &b32str_b[0], mk_lang_countof(b32str_b), &len); mk_lang_check_return(len == mk_lang_countof(b32str_b));
	ca = mk_lang_string_memcmp_pc_fn(&b32str_a[0], &b32str_b[0], mk_lang_countof(b32str_a));
	cb = ca < 0;
	return cb;
}
#define mk_sl_sort_merge_t_name mk_clib_app_hosts_sort
#define mk_sl_sort_merge_t_element_type mk_clib_app_hosts_b32_with_domains_pct
#define mk_sl_sort_merge_t_element_is_sorted mk_clib_app_hosts_cmp
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"
#include "mk_sl_sort_merge_inl_fileu.h"

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_tree_rw_add(mk_clib_app_hosts_tree_pt const tree, mk_lib_crypto_hash_stream_sha2_256_digest_pct const b32, mk_clib_app_hosts_domain_pct const domain) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_clib_app_hosts_b32_with_domains_t element_val;
	mk_clib_app_hosts_tree_node_pt node;
	mk_clib_app_hosts_b32_with_domains_pt element_ptr;

	mk_lang_assert(tree);
	mk_lang_assert(b32);
	mk_lang_assert(domain);

	err = mk_clib_app_hosts_b32_with_domains_rw_construct_b32(&element_val, b32); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_tree_rw_insert_element_move(tree, &element_val, &node); mk_lang_check_rereturn(err); mk_lang_assert(node);
	err = mk_clib_app_hosts_b32_with_domains_rw_destroy(&element_val); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_tree_rw_node_get_element(node, &element_ptr); mk_lang_check_rereturn(err); mk_lang_assert(element_ptr);
	err = mk_clib_app_hosts_domains_rw_push_back_copy_single(&element_ptr->m_domains, domain); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_tree_rw_callback_collect(mk_lang_types_uintptr_t const ctx, mk_clib_app_hosts_tree_pct const tree, mk_clib_app_hosts_tree_node_pct const node) mk_lang_noexcept
{
	mk_clib_app_phosts_domains_pt hosts;
	mk_lang_types_sint_t err;
	mk_clib_app_hosts_b32_with_domains_pct element;
	mk_lang_types_usize_t count;

	mk_lang_assert(ctx != 0);
	mk_lang_assert(tree);
	mk_lang_assert(node);

	hosts = ((mk_clib_app_phosts_domains_pt)(ctx)); mk_lang_assert(hosts);
	err = mk_clib_app_hosts_tree_ro_node_get_element(node, &element); mk_lang_check_rereturn(err); mk_lang_assert(element);
	count = mk_clib_app_hosts_domains_ro_size(&element->m_domains);
	if(count >= 2)
	{
		err =  mk_clib_app_phosts_domains_rw_push_back_copy_single(hosts, &element); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_tree_rw_sort(mk_clib_app_phosts_domains_pt const hosts) mk_lang_noexcept
{
	mk_lang_types_usize_t cnt;
	mk_lang_types_sint_t err;
	mk_clib_app_hosts_b32_with_domains_ppct buf;

	mk_lang_assert(hosts);

	cnt = mk_clib_app_phosts_domains_rw_size(hosts);
	err = mk_clib_app_phosts_domains_rw_reserve_additional(hosts, cnt); mk_lang_check_rereturn(err);
	buf = mk_clib_app_phosts_domains_rw_data(hosts);
	mk_clib_app_hosts_sort_fn(0, buf, cnt, buf + cnt);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_tree_rw_writf(mk_clib_app_phosts_domains_pct const hosts) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_writer_file_t writer;
	mk_lang_types_pchar_t nl_pchar;
	mk_sl_cui_uint8_t nl_u8;
	mk_lang_types_pchar_t b32_buf[mk_lang_countstr(mk_clib_app_hosts_b32_prefix) + mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5) + mk_lang_countstr(mk_clib_app_hosts_b32_suffix)];
	mk_lang_types_usize_t m;
	mk_lang_types_usize_t j;
	mk_clib_app_hosts_b32_with_domains_pcpct element_ptr;
	mk_clib_app_hosts_b32_with_domains_pct element;
	mk_lang_types_sint_t b32_len;
	mk_lang_types_sint_t written;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_clib_app_hosts_domain_pct domain;
	mk_sl_cui_uint8_pct domain_buf;
	mk_lang_types_sint_t domain_len;

	mk_lang_assert(hosts);

	err = mk_sl_io_writer_file_open_n(&writer, "duplicates.md"); mk_lang_check_rereturn(err);
	nl_pchar = '\x0a'; mk_sl_cui_uint8_from_bi_pchar(&nl_u8, &nl_pchar);
	mk_lang_string_memcpy_pc_fn(&b32_buf[0], &mk_clib_app_hosts_b32_prefix[0], mk_lang_countstr(mk_clib_app_hosts_b32_prefix));
	mk_lang_string_memcpy_pc_fn(&b32_buf[mk_lang_countof(b32_buf) - mk_lang_countstr(mk_clib_app_hosts_b32_suffix)], &mk_clib_app_hosts_b32_suffix[0], mk_lang_countstr(mk_clib_app_hosts_b32_suffix));
	m = mk_clib_app_phosts_domains_ro_size(hosts);
	for(j = 0; j != m; ++j)
	{
		element_ptr = mk_clib_app_phosts_domains_ro_at(hosts, j); mk_lang_assert(element_ptr); element = *element_ptr; mk_lang_assert(element);
		mk_lib_iip_base32_encoder_fn(&element->m_b32.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_256_digest_len_v, &b32_buf[mk_lang_countstr(mk_clib_app_hosts_b32_prefix)], mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5), &b32_len); mk_lang_check_return(b32_len == mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5));
		err = mk_sl_io_writer_file_write(&writer, ((mk_sl_cui_uint8_pct)(&mk_clib_app_hosts_duplicate_1_prefix[0])), mk_lang_countstr(mk_clib_app_hosts_duplicate_1_prefix), &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == mk_lang_countstr(mk_clib_app_hosts_duplicate_1_prefix));
		err = mk_sl_io_writer_file_write(&writer, ((mk_sl_cui_uint8_pct)(&b32_buf[0])), mk_lang_countof(b32_buf), &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == mk_lang_countof(b32_buf));
		err = mk_sl_io_writer_file_write(&writer, &nl_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
		n = mk_clib_app_hosts_domains_ro_size(&element->m_domains); mk_lang_assert(n >= 2);
		for(i = 0; i != n; ++i)
		{
			domain = mk_clib_app_hosts_domains_ro_at(&element->m_domains, i); mk_lang_assert(domain);
			domain_buf = mk_clib_app_hosts_domain_ro_data(domain); mk_lang_assert(domain_buf);
			domain_len = mk_clib_app_hosts_domain_ro_sise(domain); mk_lang_assert(domain_len >= 1);
			err = mk_sl_io_writer_file_write(&writer, ((mk_sl_cui_uint8_pct)(&mk_clib_app_hosts_duplicate_2_prefix[0])), mk_lang_countstr(mk_clib_app_hosts_duplicate_2_prefix), &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == mk_lang_countstr(mk_clib_app_hosts_duplicate_2_prefix));
			err = mk_sl_io_writer_file_write(&writer, ((mk_sl_cui_uint8_pct)(&mk_clib_app_hosts_domain_prefix[0])), mk_lang_countstr(mk_clib_app_hosts_domain_prefix), &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == mk_lang_countstr(mk_clib_app_hosts_domain_prefix));
			err = mk_sl_io_writer_file_write(&writer, domain_buf, domain_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == domain_len);
			err = mk_sl_io_writer_file_write(&writer, &nl_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
		}
	}
	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_tree_rw_write(mk_clib_app_hosts_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_clib_app_phosts_domains_t hosts;

	mk_lang_assert(tree);

	err = mk_clib_app_phosts_domains_rw_construct(&hosts); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_tree_ro_walk(tree, &mk_clib_app_hosts_tree_rw_callback_collect, ((mk_lang_types_uintptr_t)(&hosts))); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_tree_rw_sort(&hosts); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_tree_rw_writf(&hosts); mk_lang_check_rereturn(err);
	err = mk_clib_app_phosts_domains_rw_destroy(&hosts); mk_lang_check_rereturn(err);
	return 0;
}





#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_hosts_entry_s
{
	mk_clib_app_hosts_domain_t m_domain;
	mk_lib_crypto_hash_stream_sha2_256_digest_t m_b32;
	mk_lib_iip_cp_destination_cert_type_t m_cert_type;
	mk_lib_iip_cp_destination_certificate_key_sgn_type_t m_sgn_type;
	mk_lib_iip_cp_destination_certificate_key_enc_type_t m_enc_type;
};
typedef struct mk_clib_app_hosts_entry_s mk_clib_app_hosts_entry_t;
mk_lang_typedef(mk_clib_app_hosts_entry);
#include "mk_lang_warning_msvc_pop.h"
#include "mk_sl_vector.h"

#define mk_sl_vector_t_name mk_clib_app_hosts_entries
#define mk_sl_vector_t_element_type mk_clib_app_hosts_entry_t
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_copy_style mk_sl_vector_copy_use_bitblt
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

#include "mk_sl_vector.h"
#define mk_sl_vector_t_name mk_clib_app_hosts_ints
#define mk_sl_vector_t_element_type mk_lang_types_sint_t
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_copy_style mk_sl_vector_copy_use_bitblt
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_clib_app_hosts_entry_ro_is_sorted_indirect(mk_clib_app_hosts_entry_pct const context, mk_lang_types_sint_pct const a, mk_lang_types_sint_pct const b) mk_lang_noexcept
{
	mk_lang_types_pchar_t b32str_a[mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_pchar_t b32str_b[mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5)] mk_lang_constexpr_init;
	mk_lang_types_sint_t ca mk_lang_constexpr_init;
	mk_lang_types_bool_t cb mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct domain_a_buf mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct domain_b_buf mk_lang_constexpr_init;
	mk_lang_types_usize_t domain_a_len mk_lang_constexpr_init;
	mk_lang_types_usize_t domain_b_len mk_lang_constexpr_init;
	mk_lang_types_usize_t domain_len mk_lang_constexpr_init;

	mk_lang_assert(context);
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_base32_encoder_fn(&context[*a].m_b32.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_256_digest_len_v, &b32str_a[0], mk_lang_countof(b32str_a), &len); mk_lang_check_return(len == mk_lang_countof(b32str_a));
	mk_lib_iip_base32_encoder_fn(&context[*b].m_b32.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_256_digest_len_v, &b32str_b[0], mk_lang_countof(b32str_b), &len); mk_lang_check_return(len == mk_lang_countof(b32str_b));
	ca = mk_lang_string_memcmp_pc_fn(&b32str_a[0], &b32str_b[0], mk_lang_countof(b32str_a));
	if(ca == 0)
	{
		domain_a_buf = mk_clib_app_hosts_domain_ro_data(&context[*a].m_domain); mk_lang_assert(domain_a_buf);
		domain_b_buf = mk_clib_app_hosts_domain_ro_data(&context[*b].m_domain); mk_lang_assert(domain_b_buf);
		domain_a_len = mk_clib_app_hosts_domain_ro_size(&context[*a].m_domain);
		domain_b_len = mk_clib_app_hosts_domain_ro_size(&context[*b].m_domain);
		domain_len = mk_lang_min(domain_a_len, domain_b_len);
		ca = mk_sl_cui_uint8_memcmp_fn(domain_a_buf, domain_b_buf, domain_len);
	}
	cb = ca < 0;
	return cb;
}
#define mk_sl_sort_merge_t_name mk_clib_app_hosts_entries_sort_b32
#define mk_sl_sort_merge_t_element_type mk_lang_types_sint_t
#define mk_sl_sort_merge_t_element_is_sorted mk_clib_app_hosts_entry_ro_is_sorted_indirect
#define mk_sl_sort_merge_t_context_type mk_clib_app_hosts_entry_pct
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"
#include "mk_sl_sort_merge_inl_fileu.h"

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_clib_app_hosts_entry_ro_is_sorted_domain_indirect(mk_clib_app_hosts_entry_pct const context, mk_lang_types_sint_pct const a, mk_lang_types_sint_pct const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct domain_a_buf mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct domain_b_buf mk_lang_constexpr_init;
	mk_lang_types_usize_t domain_a_len mk_lang_constexpr_init;
	mk_lang_types_usize_t domain_b_len mk_lang_constexpr_init;
	mk_lang_types_usize_t domain_len mk_lang_constexpr_init;
	mk_lang_types_sint_t ca mk_lang_constexpr_init;
	mk_lang_types_pchar_t b32str_a[mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5)] mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_pchar_t b32str_b[mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5)] mk_lang_constexpr_init;
	mk_lang_types_bool_t cb mk_lang_constexpr_init;

	mk_lang_assert(context);
	mk_lang_assert(a);
	mk_lang_assert(b);

	domain_a_buf = mk_clib_app_hosts_domain_ro_data(&context[*a].m_domain); mk_lang_assert(domain_a_buf);
	domain_b_buf = mk_clib_app_hosts_domain_ro_data(&context[*b].m_domain); mk_lang_assert(domain_b_buf);
	domain_a_len = mk_clib_app_hosts_domain_ro_size(&context[*a].m_domain);
	domain_b_len = mk_clib_app_hosts_domain_ro_size(&context[*b].m_domain);
	mk_sl_cui_uint8_set_zero(&((mk_sl_cui_uint8_pt)(domain_a_buf))[domain_a_len]);
	mk_sl_cui_uint8_set_zero(&((mk_sl_cui_uint8_pt)(domain_b_buf))[domain_b_len]);
	domain_len = mk_lang_min(domain_a_len, domain_b_len);
	ca = mk_sl_cui_uint8_memcmp_fn(domain_a_buf, domain_b_buf, domain_len + 1);
	if(ca == 0)
	{
		mk_lib_iip_base32_encoder_fn(&context[*a].m_b32.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_256_digest_len_v, &b32str_a[0], mk_lang_countof(b32str_a), &len); mk_lang_check_return(len == mk_lang_countof(b32str_a));
		mk_lib_iip_base32_encoder_fn(&context[*b].m_b32.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_256_digest_len_v, &b32str_b[0], mk_lang_countof(b32str_b), &len); mk_lang_check_return(len == mk_lang_countof(b32str_b));
		ca = mk_lang_string_memcmp_pc_fn(&b32str_a[0], &b32str_b[0], mk_lang_countof(b32str_a));
	}
	cb = ca < 0;
	return cb;
}
#define mk_sl_sort_merge_t_name mk_clib_app_hosts_entries_sort_domain
#define mk_sl_sort_merge_t_element_type mk_lang_types_sint_t
#define mk_sl_sort_merge_t_element_is_sorted mk_clib_app_hosts_entry_ro_is_sorted_domain_indirect
#define mk_sl_sort_merge_t_context_type mk_clib_app_hosts_entry_pct
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"
#include "mk_sl_sort_merge_inl_fileu.h"

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_entries_rw_add(mk_clib_app_hosts_entries_pt const entries, mk_clib_app_hosts_domain_pct const domain, mk_lib_crypto_hash_stream_sha2_256_digest_pct const b32, mk_lib_iip_cp_destination_cert_type_t const cert_type, mk_lib_iip_cp_destination_certificate_key_sgn_type_t const sgn_type, mk_lib_iip_cp_destination_certificate_key_enc_type_t const enc_type) mk_lang_noexcept
{
	mk_clib_app_hosts_entry_t entry;
	mk_lang_types_sint_t err;

	mk_lang_assert(entries);
	mk_lang_assert(domain);
	mk_lang_assert(b32);
	mk_lang_assert(&cert_type);
	mk_lang_assert(&sgn_type);
	mk_lang_assert(&enc_type);

	entry.m_domain = *domain;
	entry.m_b32 = *b32;
	entry.m_cert_type = cert_type;
	entry.m_sgn_type = sgn_type;
	entry.m_enc_type = enc_type;
	err = mk_clib_app_hosts_entries_rw_push_back_move_single(entries, &entry); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_entries_rw_write_header_b32(mk_sl_io_writer_file_pt const writer) mk_lang_noexcept
{
	#define mk_clib_app_hosts_entries_rw_write_header_b32_k_msg \
	"| b32 | domain | cert |" "\x0a" \
	"| ---------- | ---------- | ---------- |" "\x0a" \
	""

	mk_sl_cui_uint8_pct hdr_buf;
	mk_lang_types_sint_t hdr_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t written;

	mk_lang_assert(writer);

	hdr_buf = ((mk_sl_cui_uint8_pct)(&mk_clib_app_hosts_entries_rw_write_header_b32_k_msg[0]));
	hdr_len = mk_lang_countstr(mk_clib_app_hosts_entries_rw_write_header_b32_k_msg);
	err = mk_sl_io_writer_file_write(writer, hdr_buf, hdr_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == hdr_len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_entries_rw_write_header_domain(mk_sl_io_writer_file_pt const writer) mk_lang_noexcept
{
	#define mk_clib_app_hosts_entries_rw_write_header_domain_k_msg \
	"| domain | b32 | cert |" "\x0a" \
	"| ---------- | ---------- | ---------- |" "\x0a" \
	""

	mk_sl_cui_uint8_pct hdr_buf;
	mk_lang_types_sint_t hdr_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t written;

	mk_lang_assert(writer);

	hdr_buf = ((mk_sl_cui_uint8_pct)(&mk_clib_app_hosts_entries_rw_write_header_domain_k_msg[0]));
	hdr_len = mk_lang_countstr(mk_clib_app_hosts_entries_rw_write_header_domain_k_msg);
	err = mk_sl_io_writer_file_write(writer, hdr_buf, hdr_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == hdr_len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_entries_rw_write_entry_b32(mk_sl_io_writer_file_pt const writer, mk_clib_app_hosts_entry_pct const entry) mk_lang_noexcept
{
	mk_lang_types_pchar_t nl_pchar;
	mk_sl_cui_uint8_t nl_u8;
	mk_lang_types_pchar_t sp_pchar;
	mk_sl_cui_uint8_t sp_u8;
	mk_lang_types_pchar_t ba_pchar;
	mk_sl_cui_uint8_t ba_u8;
	mk_lang_types_pchar_t b32_buf[mk_lang_countstr(mk_clib_app_hosts_b32_prefix) + mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5) + mk_lang_countstr(mk_clib_app_hosts_b32_suffix)];
	mk_lang_types_sint_t b32_len;
	mk_lang_types_pchar_pct cert_buf;
	mk_lang_types_sint_t cert_len;
	mk_sl_cui_uint8_pct domain_buf;
	mk_lang_types_sint_t domain_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t written;

	mk_lang_assert(writer);
	mk_lang_assert(entry);

	nl_pchar = '\x0a'; mk_sl_cui_uint8_from_bi_pchar(&nl_u8, &nl_pchar);
	sp_pchar = ' '; mk_sl_cui_uint8_from_bi_pchar(&sp_u8, &sp_pchar);
	ba_pchar = '|'; mk_sl_cui_uint8_from_bi_pchar(&ba_u8, &ba_pchar);
	mk_lang_string_memcpy_pc_fn(&b32_buf[0], &mk_clib_app_hosts_b32_prefix[0], mk_lang_countstr(mk_clib_app_hosts_b32_prefix));
	mk_lang_string_memcpy_pc_fn(&b32_buf[mk_lang_countof(b32_buf) - mk_lang_countstr(mk_clib_app_hosts_b32_suffix)], &mk_clib_app_hosts_b32_suffix[0], mk_lang_countstr(mk_clib_app_hosts_b32_suffix));
	mk_lib_iip_base32_encoder_fn(&entry->m_b32.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_256_digest_len_v, &b32_buf[mk_lang_countstr(mk_clib_app_hosts_b32_prefix)], mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5), &b32_len); mk_lang_check_return(b32_len == mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5));
	cert_buf = mk_lang_null;
	cert_len = 0;
	switch(entry->m_cert_type)
	{
		case mk_lib_iip_cp_destination_cert_type_e_null: cert_buf = &mk_clib_app_hosts_b32_cert_null[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_null); break;
		case mk_lib_iip_cp_destination_cert_type_e_hidden: cert_buf = &mk_clib_app_hosts_b32_cert_hidden[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_hidden); break;
		case mk_lib_iip_cp_destination_cert_type_e_signeda: cert_buf = &mk_clib_app_hosts_b32_cert_signed[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_signed); break;
		case mk_lib_iip_cp_destination_cert_type_e_signedb: cert_buf = &mk_clib_app_hosts_b32_cert_signed[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_signed); break;
		case mk_lib_iip_cp_destination_cert_type_e_key:
			#include "mk_lang_warning_msvc_push_c4127.h"
			if(mk_lang_false){}
			#include "mk_lang_warning_msvc_pop.h"
			else if(entry->m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && entry->m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dsa_sha1             ){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_0 [0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_0 ); }
			else if(entry->m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && entry->m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha256_p256    ){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_1 [0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_1 ); }
			else if(entry->m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && entry->m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519 ){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_7 [0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_7 ); }
			else if(entry->m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && entry->m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha512_p521    ){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_3 [0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_3 ); }
			else if(entry->m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && entry->m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_reddsa_sha512_ed25519){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_11[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_11); }
			else{ mk_lang_check_todo(); }
		break;
		case mk_lib_iip_cp_destination_cert_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&cert_buf);
	mk_lang_clobber(&cert_len);

	domain_buf = mk_clib_app_hosts_domain_ro_data(&entry->m_domain);
	domain_len = mk_clib_app_hosts_domain_ro_sise(&entry->m_domain);

	err = mk_sl_io_writer_file_write(writer, &ba_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	err = mk_sl_io_writer_file_write(writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);

	err = mk_sl_io_writer_file_write(writer, ((mk_sl_cui_uint8_pct)(&b32_buf[0])), mk_lang_countof(b32_buf), &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == mk_lang_countof(b32_buf));

	err = mk_sl_io_writer_file_write(writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	err = mk_sl_io_writer_file_write(writer, &ba_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	err = mk_sl_io_writer_file_write(writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);

	err = mk_sl_io_writer_file_write(writer, ((mk_sl_cui_uint8_pct)(&mk_clib_app_hosts_b32_prefix[0])), mk_lang_countstr(mk_clib_app_hosts_b32_prefix), &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == mk_lang_countstr(mk_clib_app_hosts_b32_prefix));
	err = mk_sl_io_writer_file_write(writer, domain_buf, domain_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == domain_len);

	err = mk_sl_io_writer_file_write(writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	err = mk_sl_io_writer_file_write(writer, &ba_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	err = mk_sl_io_writer_file_write(writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);

	err = mk_sl_io_writer_file_write(writer, ((mk_sl_cui_uint8_pct)(cert_buf)), cert_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == cert_len);
	err = mk_sl_io_writer_file_write(writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	err = mk_sl_io_writer_file_write(writer, &ba_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);

	err = mk_sl_io_writer_file_write(writer, &nl_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_entries_rw_write_entry_domain(mk_sl_io_writer_file_pt const writer, mk_clib_app_hosts_entry_pct const entry) mk_lang_noexcept
{
	mk_lang_types_pchar_t nl_pchar;
	mk_sl_cui_uint8_t nl_u8;
	mk_lang_types_pchar_t sp_pchar;
	mk_sl_cui_uint8_t sp_u8;
	mk_lang_types_pchar_t ba_pchar;
	mk_sl_cui_uint8_t ba_u8;
	mk_lang_types_pchar_t b32_buf[mk_lang_countstr(mk_clib_app_hosts_b32_prefix) + mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5) + mk_lang_countstr(mk_clib_app_hosts_b32_suffix)];
	mk_lang_types_sint_t b32_len;
	mk_lang_types_pchar_pct cert_buf;
	mk_lang_types_sint_t cert_len;
	mk_sl_cui_uint8_pct domain_buf;
	mk_lang_types_sint_t domain_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t written;

	mk_lang_assert(writer);
	mk_lang_assert(entry);

	nl_pchar = '\x0a'; mk_sl_cui_uint8_from_bi_pchar(&nl_u8, &nl_pchar);
	sp_pchar = ' '; mk_sl_cui_uint8_from_bi_pchar(&sp_u8, &sp_pchar);
	ba_pchar = '|'; mk_sl_cui_uint8_from_bi_pchar(&ba_u8, &ba_pchar);
	mk_lang_string_memcpy_pc_fn(&b32_buf[0], &mk_clib_app_hosts_b32_prefix[0], mk_lang_countstr(mk_clib_app_hosts_b32_prefix));
	mk_lang_string_memcpy_pc_fn(&b32_buf[mk_lang_countof(b32_buf) - mk_lang_countstr(mk_clib_app_hosts_b32_suffix)], &mk_clib_app_hosts_b32_suffix[0], mk_lang_countstr(mk_clib_app_hosts_b32_suffix));
	mk_lib_iip_base32_encoder_fn(&entry->m_b32.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_256_digest_len_v, &b32_buf[mk_lang_countstr(mk_clib_app_hosts_b32_prefix)], mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5), &b32_len); mk_lang_check_return(b32_len == mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5));
	cert_buf = mk_lang_null;
	cert_len = 0;
	switch(entry->m_cert_type)
	{
		case mk_lib_iip_cp_destination_cert_type_e_null: cert_buf = &mk_clib_app_hosts_b32_cert_null[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_null); break;
		case mk_lib_iip_cp_destination_cert_type_e_hidden: cert_buf = &mk_clib_app_hosts_b32_cert_hidden[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_hidden); break;
		case mk_lib_iip_cp_destination_cert_type_e_signeda: cert_buf = &mk_clib_app_hosts_b32_cert_signed[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_signed); break;
		case mk_lib_iip_cp_destination_cert_type_e_signedb: cert_buf = &mk_clib_app_hosts_b32_cert_signed[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_signed); break;
		case mk_lib_iip_cp_destination_cert_type_e_key:
			#include "mk_lang_warning_msvc_push_c4127.h"
			if(mk_lang_false){}
			#include "mk_lang_warning_msvc_pop.h"
			else if(entry->m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && entry->m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dsa_sha1             ){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_0 [0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_0 ); }
			else if(entry->m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && entry->m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha256_p256    ){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_1 [0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_1 ); }
			else if(entry->m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && entry->m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519 ){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_7 [0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_7 ); }
			else if(entry->m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && entry->m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha512_p521    ){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_3 [0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_3 ); }
			else if(entry->m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && entry->m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_reddsa_sha512_ed25519){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_11[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_11); }
			else{ mk_lang_check_todo(); }
		break;
		case mk_lib_iip_cp_destination_cert_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&cert_buf);
	mk_lang_clobber(&cert_len);

	domain_buf = mk_clib_app_hosts_domain_ro_data(&entry->m_domain);
	domain_len = mk_clib_app_hosts_domain_ro_sise(&entry->m_domain);

	err = mk_sl_io_writer_file_write(writer, &ba_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	err = mk_sl_io_writer_file_write(writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);

	err = mk_sl_io_writer_file_write(writer, ((mk_sl_cui_uint8_pct)(&mk_clib_app_hosts_b32_prefix[0])), mk_lang_countstr(mk_clib_app_hosts_b32_prefix), &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == mk_lang_countstr(mk_clib_app_hosts_b32_prefix));
	err = mk_sl_io_writer_file_write(writer, domain_buf, domain_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == domain_len);

	err = mk_sl_io_writer_file_write(writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	err = mk_sl_io_writer_file_write(writer, &ba_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	err = mk_sl_io_writer_file_write(writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);

	err = mk_sl_io_writer_file_write(writer, ((mk_sl_cui_uint8_pct)(&b32_buf[0])), mk_lang_countof(b32_buf), &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == mk_lang_countof(b32_buf));

	err = mk_sl_io_writer_file_write(writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	err = mk_sl_io_writer_file_write(writer, &ba_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	err = mk_sl_io_writer_file_write(writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);

	err = mk_sl_io_writer_file_write(writer, ((mk_sl_cui_uint8_pct)(cert_buf)), cert_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == cert_len);
	err = mk_sl_io_writer_file_write(writer, &sp_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	err = mk_sl_io_writer_file_write(writer, &ba_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);

	err = mk_sl_io_writer_file_write(writer, &nl_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_entries_rw_write_sorted_b32(mk_clib_app_hosts_entries_pct const entries, mk_lang_types_sint_pct const sort_order) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_writer_file_t writer;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t idx;
	mk_clib_app_hosts_entry_pct entry;

	mk_lang_assert(entries);
	mk_lang_assert(sort_order);

	err = mk_sl_io_writer_file_open_n(&writer, "b32s.md"); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_entries_rw_write_header_b32(&writer); mk_lang_check_rereturn(err);
	n = mk_clib_app_hosts_entries_ro_sise(entries);
	for(i = 0; i != n; ++i)
	{
		idx = sort_order[i]; mk_lang_assert(idx >= 0); mk_lang_assert(idx < n);
		entry = mk_clib_app_hosts_entries_ro_at(entries, ((mk_lang_types_usize_t)(idx))); mk_lang_assert(entry);
		err = mk_clib_app_hosts_entries_rw_write_entry_b32(&writer, entry); mk_lang_check_rereturn(err);
	}
	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_entries_rw_write_sorted_domain(mk_clib_app_hosts_entries_pct const entries, mk_lang_types_sint_pct const sort_order) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_writer_file_t writer;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t idx;
	mk_clib_app_hosts_entry_pct entry;

	mk_lang_assert(entries);
	mk_lang_assert(sort_order);

	err = mk_sl_io_writer_file_open_n(&writer, "hosts.md"); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_entries_rw_write_header_domain(&writer); mk_lang_check_rereturn(err);
	n = mk_clib_app_hosts_entries_ro_sise(entries);
	for(i = 0; i != n; ++i)
	{
		idx = sort_order[i]; mk_lang_assert(idx >= 0); mk_lang_assert(idx < n);
		entry = mk_clib_app_hosts_entries_ro_at(entries, ((mk_lang_types_usize_t)(idx))); mk_lang_assert(entry);
		err = mk_clib_app_hosts_entries_rw_write_entry_domain(&writer, entry); mk_lang_check_rereturn(err);
	}
	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_entries_rw_sort_by_domain_and_write(mk_clib_app_hosts_entries_pct const entries) mk_lang_noexcept
{
	mk_lang_types_usize_t count;
	mk_lang_types_sint_t err;
	mk_clib_app_hosts_ints_t ints;
	mk_clib_app_hosts_entry_pct data_entries;
	mk_lang_types_sint_pt data_ints;

	mk_lang_assert(entries);

	if(!mk_clib_app_hosts_entries_ro_is_empty(entries))
	{
		count = mk_clib_app_hosts_entries_ro_size(entries);
		err = mk_clib_app_hosts_ints_rw_construct(&ints); mk_lang_check_rereturn(err);
		err = mk_clib_app_hosts_ints_rw_resize_to(&ints, count * 2); mk_lang_check_rereturn(err);
		data_entries = mk_clib_app_hosts_entries_ro_data(entries); mk_lang_assert(data_entries);
		data_ints = mk_clib_app_hosts_ints_rw_data(&ints); mk_lang_assert(data_ints);
		mk_lang_alg_iota_sint_usize_fn(data_ints, count);
		mk_clib_app_hosts_entries_sort_domain_fn(data_entries, &data_ints[0], count, &data_ints[count]);
		err = mk_clib_app_hosts_entries_rw_write_sorted_domain(entries, data_ints); mk_lang_check_rereturn(err);
		err = mk_clib_app_hosts_ints_rw_destroy(&ints); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hosts_entries_rw_sort_by_b32_and_write(mk_clib_app_hosts_entries_pct const entries) mk_lang_noexcept
{
	mk_lang_types_usize_t count;
	mk_lang_types_sint_t err;
	mk_clib_app_hosts_ints_t ints;
	mk_clib_app_hosts_entry_pct data_entries;
	mk_lang_types_sint_pt data_ints;

	mk_lang_assert(entries);

	if(!mk_clib_app_hosts_entries_ro_is_empty(entries))
	{
		count = mk_clib_app_hosts_entries_ro_size(entries);
		err = mk_clib_app_hosts_ints_rw_construct(&ints); mk_lang_check_rereturn(err);
		err = mk_clib_app_hosts_ints_rw_resize_to(&ints, count * 2); mk_lang_check_rereturn(err);
		data_entries = mk_clib_app_hosts_entries_ro_data(entries); mk_lang_assert(data_entries);
		data_ints = mk_clib_app_hosts_ints_rw_data(&ints); mk_lang_assert(data_ints);
		mk_lang_alg_iota_sint_usize_fn(data_ints, count);
		mk_clib_app_hosts_entries_sort_b32_fn(data_entries, &data_ints[0], count, &data_ints[count]);
		err = mk_clib_app_hosts_entries_rw_write_sorted_b32(entries, data_ints); mk_lang_check_rereturn(err);
		err = mk_clib_app_hosts_ints_rw_destroy(&ints); mk_lang_check_rereturn(err);
	}
	return 0;
}





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
	mk_lang_types_sint_t err;
	mk_clib_app_hosts_entries_t entries;
	mk_clib_app_hosts_tree_t db;
	mk_lang_types_pchar_t nl_pchar;
	mk_sl_cui_uint8_t nl_u8;
	mk_lang_types_pchar_t eq_pchar;
	mk_sl_cui_uint8_t eq_u8;
	mk_lang_types_pchar_t sp_pchar;
	mk_sl_cui_uint8_t sp_u8;
	mk_lang_types_pchar_t ba_pchar;
	mk_sl_cui_uint8_t ba_u8;
	mk_lang_types_pchar_t cm_pchar;
	mk_sl_cui_uint8_t cm_u8;
	mk_lang_types_pchar_t b32_buf[mk_lang_countstr(mk_clib_app_hosts_b32_prefix) + mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5) + mk_lang_countstr(mk_clib_app_hosts_b32_suffix)];
	mk_sl_cui_uint8_pt read_data_ptr;
	mk_sl_cui_uint8_t read_data_buf[mk_lang_roundup_add(mk_clib_app_hosts_buf_len, mk_clib_app_hosts_buf_alg)];
	mk_lang_types_sint_t read_data_cap;
	mk_sl_dynamic_ring_u8_t ring;
	mk_sl_io_reader_file_t reader;
	mk_sl_io_writer_file_t addresses_csv;
	mk_lang_types_sint_t read_data_len;
	mk_sl_cui_uint8_pt data_ptr;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t idx_nl;
	mk_lang_types_sint_t idx_eq;
	mk_lang_types_sint_t domain_beg;
	mk_lang_types_sint_t domain_len;
	mk_lang_types_sint_t b64_beg;
	mk_lang_types_sint_t b64_len;
	mk_lang_types_pchar_t b64_buf[2 * 1024];
	mk_sl_cui_uint8_t address_buf[mk_lib_iip_cp_destination_max_len_bytes_v];
	mk_lang_types_sint_t address_len;
	mk_lang_types_bool_t gud;
	mk_lib_iip_cp_destination_remote_t remote_destination;
	mk_lang_types_sint_t consumed;
	mk_lib_crypto_hash_stream_sha2_256_t hasher;
	mk_lib_crypto_hash_stream_sha2_256_digest_t digest;
	mk_clib_app_hosts_domain_t domain;
	mk_lang_types_sint_t b32_len;
	mk_lang_types_pchar_pct cert_buf;
	mk_lang_types_sint_t cert_len;
	mk_lang_types_sint_t written;

	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != mk_lang_tchar_c('\0'));
	mk_lang_assert(lens[0] >= 1);

	err = mk_clib_app_hosts_entries_rw_construct(&entries); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_tree_rw_construct(&db); mk_lang_check_rereturn(err);
	nl_pchar = '\x0a'; mk_sl_cui_uint8_from_bi_pchar(&nl_u8, &nl_pchar);
	eq_pchar = '='; mk_sl_cui_uint8_from_bi_pchar(&eq_u8, &eq_pchar);
	sp_pchar = ' '; mk_sl_cui_uint8_from_bi_pchar(&sp_u8, &sp_pchar);
	ba_pchar = '|'; mk_sl_cui_uint8_from_bi_pchar(&ba_u8, &ba_pchar);
	cm_pchar = ','; mk_sl_cui_uint8_from_bi_pchar(&cm_u8, &cm_pchar);
	mk_lang_string_memcpy_pc_fn(&b32_buf[0], &mk_clib_app_hosts_b32_prefix[0], mk_lang_countstr(mk_clib_app_hosts_b32_prefix));
	mk_lang_string_memcpy_pc_fn(&b32_buf[mk_lang_countof(b32_buf) - mk_lang_countstr(mk_clib_app_hosts_b32_suffix)], &mk_clib_app_hosts_b32_suffix[0], mk_lang_countstr(mk_clib_app_hosts_b32_suffix));
	read_data_ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(&read_data_buf[0], mk_clib_app_hosts_buf_alg)));
	read_data_cap = mk_clib_app_hosts_buf_len;
	err = mk_sl_dynamic_ring_u8_rw_construct(&ring); mk_lang_check_rereturn(err);
	err = mk_sl_io_reader_file_open_n(&reader, "hosts.txt"); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_open_n(&addresses_csv, "addresses.csv"); mk_lang_check_rereturn(err);
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
			b64_len = idx_nl - b64_beg;
			mk_lang_string_memcpy_pc_fn(&b64_buf[0], ((mk_lang_types_pchar_pt)(&data_ptr[b64_beg])), ((mk_lang_types_usize_t)(b64_len))); b64_buf[b64_len + 0] = '='; b64_buf[b64_len + 1] = '=';
			mk_lib_iip_base64_decoder_do_check(&b64_buf[0], mk_lang_roundup_mul(b64_len, 4), &address_buf[0], mk_lang_countof(address_buf), &address_len, &gud); mk_lang_check_return(gud);
			err = mk_lib_iip_cp_destination_remote_rw_from_bytes(&remote_destination, &address_buf[0], address_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_check_return(consumed == address_len);
			mk_lib_crypto_hash_stream_sha2_256_init(&hasher);
			mk_lib_crypto_hash_stream_sha2_256_append_u8s(&hasher, &address_buf[0], ((mk_lang_types_usize_t)(address_len)));
			mk_lib_crypto_hash_stream_sha2_256_finish(&hasher, &digest);
			err = mk_clib_app_hosts_domain_rw_construct_void(&domain); mk_lang_check_rereturn(err);
			err = mk_clib_app_hosts_domain_rw_push_back_copy_many(&domain, &data_ptr[domain_beg], ((mk_lang_types_usize_t)(domain_len))); mk_lang_check_rereturn(err);
			err = mk_clib_app_hosts_tree_rw_add(&db, &digest, &domain); mk_lang_check_rereturn(err);
			err = mk_clib_app_hosts_entries_rw_add(&entries, &domain, &digest, remote_destination.m_certificate.m_cert_type, remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type, remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type); mk_lang_check_rereturn(err);
			err = mk_clib_app_hosts_domain_rw_destroy(&domain); mk_lang_check_rereturn(err);
			mk_lib_iip_base32_encoder_fn(&digest.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_256_digest_len_v, &b32_buf[mk_lang_countstr(mk_clib_app_hosts_b32_prefix)], mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5), &b32_len); mk_lang_check_return(b32_len == mk_lang_roundup_div(mk_lib_crypto_hash_stream_sha2_256_digest_len_v * 8, 5));
			cert_buf = mk_lang_null;
			cert_len = 0;
			switch(remote_destination.m_certificate.m_cert_type)
			{
				case mk_lib_iip_cp_destination_cert_type_e_null: cert_buf = &mk_clib_app_hosts_b32_cert_null[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_null); break;
				case mk_lib_iip_cp_destination_cert_type_e_hidden: cert_buf = &mk_clib_app_hosts_b32_cert_hidden[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_hidden); break;
				case mk_lib_iip_cp_destination_cert_type_e_signeda: cert_buf = &mk_clib_app_hosts_b32_cert_signed[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_signed); break;
				case mk_lib_iip_cp_destination_cert_type_e_signedb: cert_buf = &mk_clib_app_hosts_b32_cert_signed[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_signed); break;
				case mk_lib_iip_cp_destination_cert_type_e_key:
					#include "mk_lang_warning_msvc_push_c4127.h"
					if(mk_lang_false){}
					#include "mk_lang_warning_msvc_pop.h"
					else if(remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_dsa_sha1             ){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_0 [0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_0 ); }
					else if(remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha256_p256    ){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_1 [0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_1 ); }
					else if(remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_eddsa_sha512_ed25519 ){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_7 [0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_7 ); }
					else if(remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_ecdsa_sha512_p521    ){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_3 [0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_3 ); }
					else if(remote_destination.m_certificate.m_cert_data.m_data.m_key.m_enc_type == mk_lib_iip_cp_destination_certificate_key_enc_type_e_elgamal && remote_destination.m_certificate.m_cert_data.m_data.m_key.m_sgn_type == mk_lib_iip_cp_destination_certificate_key_sgn_type_e_reddsa_sha512_ed25519){ cert_buf = &mk_clib_app_hosts_b32_cert_key_0_11[0]; cert_len = mk_lang_countstr(mk_clib_app_hosts_b32_cert_key_0_11); }
					else{ mk_lang_check_todo(); }
				break;
				case mk_lib_iip_cp_destination_cert_type_e_dummy_end: mk_lang_assert_false(); break;
				default: mk_lang_assert_false(); break;
			}
			mk_lang_clobber(&cert_buf);
			mk_lang_clobber(&cert_len);
			err = mk_sl_io_writer_file_write(&addresses_csv, &data_ptr[domain_beg], domain_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == domain_len);
			err = mk_sl_io_writer_file_write(&addresses_csv, &cm_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_io_writer_file_write(&addresses_csv, ((mk_sl_cui_uint8_pct)(&b32_buf[0] + mk_lang_countstr(mk_clib_app_hosts_b32_prefix))), mk_lang_countof(b32_buf) - mk_lang_countstr(mk_clib_app_hosts_b32_prefix) - mk_lang_countstr(mk_clib_app_hosts_b32_suffix), &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == mk_lang_countof(b32_buf) - mk_lang_countstr(mk_clib_app_hosts_b32_prefix) - mk_lang_countstr(mk_clib_app_hosts_b32_suffix));
			err = mk_sl_io_writer_file_write(&addresses_csv, &nl_u8, 1, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == 1);
			err = mk_sl_dynamic_ring_u8_rw_pop_front_many(&ring, ((mk_lang_types_usize_t)(idx_nl + 1))); mk_lang_check_rereturn(err);
		}
	}
	err = mk_sl_io_reader_file_close(&reader); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_close(&addresses_csv); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_destroy(&ring); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_tree_rw_write(&db); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_entries_rw_sort_by_domain_and_write(&entries); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_entries_rw_sort_by_b32_and_write(&entries); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_tree_rw_destruct(&db); mk_lang_check_rereturn(err);
	err = mk_clib_app_hosts_entries_rw_destroy(&entries); mk_lang_check_rereturn(err);
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
