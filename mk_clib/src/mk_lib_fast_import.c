#ifndef mk_include_guard_mk_lib_fast_import_c
#define mk_include_guard_mk_lib_fast_import_c
#include "mk_lib_fast_import.h"

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
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_runtime_bool.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_stdout.h"
#include "mk_lang_str_len.h"
#include "mk_lang_string.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_compress_zlib.h"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_lib_decompress_zlib.h"
#include "mk_lib_hash_adler32.h"
#include "mk_sl_cui_uint128.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_io_reader_file.h"
#include "mk_sl_io_writer_file.h"
#include "mk_sl_mallocator_lokal_windows.h" /* todo */
#include "mk_sl_uint_more.h"
#include "mk_win_base.h" /* todo */
#include "mk_win_dll_kernel_errors.h" /* todo */
#include "mk_win_dll_kernel_files.h" /* todo */

#define mk_sl_mallocator_lokal_t_name mk_lib_fast_import_mallocator_lokal
#define mk_sl_mallocator_lokal_t_base mk_sl_mallocator_lokal_windows
#define mk_sl_mallocator_lokal_t_constexpr_want 0
#include "mk_sl_mallocator_lokal_inl_fileh.h"
#include "mk_sl_mallocator_lokal_inl_filec.h"
#include "mk_sl_mallocator_lokal_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_fast_import_file_mode
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_size_bits_d mk_sl_cui_uint32_size_bits_d
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_fast_import_mark
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint128
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_size_bits_d mk_sl_cui_uint128_size_bits_d
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#define mk_lib_fast_import_k_buf_len 512
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_author_sp[] = "author ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_blob[] = "blob\x0a";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_blobsp[] = "blob ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_colon[] = ":";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_commitsp[] = "commit ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_committer_sp[] = "committer ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_data[] = "data ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_dot_git[] = ".git";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_from_sp_colon[] = "from :";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_gtsp[] = "> ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_heads[] = "refs/heads/";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_lf[] = "\x0a";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_mark_sp_colon[] = "mark :";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_msp[] = "M ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_objects[] = "objects";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_parent_sp[] = "parent ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_resetsp[] = "reset ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_sp[] = " ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_splt[] = " <";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_tree_sp[] = "tree ";


mk_lang_forward(mk_lib_fast_import);


#define mk_sl_vector_t_name mk_lib_fast_import_string
#define mk_sl_vector_t_element_type mk_lang_types_pchar_t
#define mk_sl_vector_t_mallocatorl mk_lib_fast_import_mallocator_lokal
#define mk_sl_vector_t_element_eq mk_lang_types_pchar_eq
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

#define mk_sl_vector_t_name mk_lib_fast_import_strings
#define mk_sl_vector_t_element_type mk_lib_fast_import_string_t
#define mk_sl_vector_t_mallocatorl mk_lib_fast_import_mallocator_lokal
#define mk_sl_vector_t_element_eq mk_lib_fast_import_string_ro_eq
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

#define mk_sl_vector_t_name mk_lib_fast_import_binary_data
#define mk_sl_vector_t_element_type mk_sl_cui_uint8_t
#define mk_sl_vector_t_mallocatorl mk_lib_fast_import_mallocator_lokal
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_buffered_reader_s
{
	mk_sl_io_reader_file_t m_reader;
	mk_sl_cui_uint8_t m_data_buf[2 * mk_lib_fast_import_k_buf_len];
	mk_lang_types_sint_t m_data_len;
};
typedef struct mk_lib_fast_import_buffered_reader_s mk_lib_fast_import_buffered_reader_t;
mk_lang_typedef(mk_lib_fast_import_buffered_reader);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_blob_s
{
	mk_lib_fast_import_pt m_fi;
	mk_lib_fast_import_mark_t m_mark;
	mk_lang_types_pchar_t m_mode_buf[mk_sl_cui_uint32_strlen_dec_v + 1];
	mk_lang_types_sint_t m_mode_len;
	mk_lang_types_sint_t m_binary_len;
	mk_sl_cui_uint8_pt m_binary_buf;
	mk_lib_crypto_hash_stream_sha1_digest_t m_digest;
};
typedef struct mk_lib_fast_import_blob_s mk_lib_fast_import_blob_t;
mk_lang_typedef(mk_lib_fast_import_blob);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_file_modify_s
{
	mk_lib_fast_import_pt m_fi;
	mk_sl_cui_uint32_t m_mode;
	mk_lib_fast_import_mark_t m_data_ref;
	mk_lib_fast_import_string_t m_path;
};
typedef struct mk_lib_fast_import_file_modify_s mk_lib_fast_import_file_modify_t;
mk_lang_typedef(mk_lib_fast_import_file_modify);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_file_op_s
{
	mk_lib_fast_import_pt m_fi;
	mk_lib_fast_import_file_modify_t m_file_modify;
};
typedef struct mk_lib_fast_import_file_op_s mk_lib_fast_import_file_op_t;
mk_lang_typedef(mk_lib_fast_import_file_op);
#include "mk_lang_warning_msvc_pop.h"

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_file_op_rw_construct_void(mk_lib_fast_import_file_op_pt const x, mk_lib_fast_import_mallocator_lokal_pt const m) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(x);
	mk_lang_assert(m);

	err = mk_lib_fast_import_string_rw_construct(&x->m_file_modify.m_path, m); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_file_op_rw_destroy(mk_lib_fast_import_file_op_pt const x) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	err = mk_lib_fast_import_string_rw_destroy(&x->m_file_modify.m_path); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_file_op_rw_copy_construct(mk_lib_fast_import_file_op_pt const dst, mk_lib_fast_import_file_op_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dst);
	mk_lang_assert(src);

	dst->m_fi = src->m_fi;
	dst->m_file_modify.m_fi = src->m_file_modify.m_fi;
	dst->m_file_modify.m_mode = src->m_file_modify.m_mode;
	dst->m_file_modify.m_data_ref = src->m_file_modify.m_data_ref;
	err = mk_lib_fast_import_string_rw_copy_construct(&dst->m_file_modify.m_path, &src->m_file_modify.m_path); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_file_op_rw_move_construct(mk_lib_fast_import_file_op_pt const dst, mk_lib_fast_import_file_op_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dst);
	mk_lang_assert(src);

	dst->m_fi = src->m_fi;
	dst->m_file_modify.m_fi = src->m_file_modify.m_fi;
	dst->m_file_modify.m_mode = src->m_file_modify.m_mode;
	dst->m_file_modify.m_data_ref = src->m_file_modify.m_data_ref;
	err = mk_lib_fast_import_string_rw_move_construct(&dst->m_file_modify.m_path, &src->m_file_modify.m_path); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_file_op_rw_copy_assign(mk_lib_fast_import_file_op_pt const dst, mk_lib_fast_import_file_op_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dst);
	mk_lang_assert(src);

	dst->m_fi = src->m_fi;
	dst->m_file_modify.m_fi = src->m_file_modify.m_fi;
	dst->m_file_modify.m_mode = src->m_file_modify.m_mode;
	dst->m_file_modify.m_data_ref = src->m_file_modify.m_data_ref;
	err = mk_lib_fast_import_string_rw_copy_assign(&dst->m_file_modify.m_path, &src->m_file_modify.m_path); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_file_op_rw_move_assign(mk_lib_fast_import_file_op_pt const dst, mk_lib_fast_import_file_op_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dst);
	mk_lang_assert(src);

	dst->m_fi = src->m_fi;
	dst->m_file_modify.m_fi = src->m_file_modify.m_fi;
	dst->m_file_modify.m_mode = src->m_file_modify.m_mode;
	dst->m_file_modify.m_data_ref = src->m_file_modify.m_data_ref;
	err = mk_lib_fast_import_string_rw_move_assign(&dst->m_file_modify.m_path, &src->m_file_modify.m_path); mk_lang_check_rereturn(err);
	return 0;
}

#define mk_sl_vector_t_name mk_lib_fast_import_file_ops
#define mk_sl_vector_t_element_type mk_lib_fast_import_file_op_t
#define mk_sl_vector_t_mallocatorl mk_lib_fast_import_mallocator_lokal
#define mk_sl_vector_t_copy_style mk_sl_vector_copy_use_custom
#define mk_sl_vector_t_element_construct_void mk_lib_fast_import_file_op_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_fast_import_file_op_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_fast_import_file_op_rw_copy_construct
#define mk_sl_vector_t_element_move_construct mk_lib_fast_import_file_op_rw_move_construct
#define mk_sl_vector_t_element_copy_assign mk_lib_fast_import_file_op_rw_copy_assign
#define mk_sl_vector_t_element_move_assign mk_lib_fast_import_file_op_rw_move_assign
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_commit_s
{
	mk_lib_fast_import_pt m_fi;
	mk_lib_fast_import_string_t m_ref;
	mk_lang_types_bool_t m_has_mark;
	mk_lib_fast_import_mark_t m_mark;
	mk_lib_fast_import_string_t m_author_name;
	mk_lib_fast_import_string_t m_author_email;
	mk_lib_fast_import_string_t m_author_timestamp;
	mk_lib_fast_import_string_t m_committer_name;
	mk_lib_fast_import_string_t m_committer_email;
	mk_lib_fast_import_string_t m_committer_timestamp;
	mk_lib_fast_import_binary_data_t m_message;
	mk_lang_types_bool_t m_has_from_mark_ref;
	mk_lib_fast_import_mark_t m_from_mark_ref;
	mk_lib_fast_import_file_ops_t m_file_ops;
	mk_lib_fast_import_binary_data_t m_data;
	mk_lib_crypto_hash_stream_sha1_digest_t m_digest;
	mk_lib_crypto_hash_stream_sha1_digest_t m_tree_digest;
};
typedef struct mk_lib_fast_import_commit_s mk_lib_fast_import_commit_t;
mk_lang_typedef(mk_lib_fast_import_commit);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_reset_s
{
	mk_lib_fast_import_pt m_fi;
	mk_lib_fast_import_string_t m_ref;
	mk_lib_fast_import_mark_t m_from;
};
typedef struct mk_lib_fast_import_reset_s mk_lib_fast_import_reset_t;
mk_lang_typedef(mk_lib_fast_import_reset);
#include "mk_lang_warning_msvc_pop.h"


#define mk_sl_tree_wavl_t_name mk_lib_fast_import_tree_by_mark
#define mk_sl_tree_wavl_t_element_type mk_lib_fast_import_blob_t
#define mk_sl_tree_wavl_t_elements_compare mk_lib_fast_import_blob_ro_cmp
#define mk_sl_tree_wavl_t_mallocatorl_name mk_lib_fast_import_mallocator_lokal
#define mk_sl_tree_wavl_t_validate_want 0
#define mk_sl_tree_wavl_t_element_copy_construct mk_lib_fast_import_blob_rw_copy_construct
#define mk_sl_tree_wavl_t_element_move_construct mk_lib_fast_import_blob_rw_move_construct
#define mk_sl_tree_wavl_t_element_destruct mk_lib_fast_import_blob_rw_destroy
#include "mk_sl_tree_wavl_inl_fileh.h"
#include "mk_sl_tree_wavl_inl_fileu.h"


mk_lang_forward(mk_lib_fast_import_tree);

enum mk_lib_fast_import_tree_node_id_e
{
	mk_lib_fast_import_tree_node_id_e_tree,
	mk_lib_fast_import_tree_node_id_e_blob,
	mk_lib_fast_import_tree_node_id_e_dummy_end
};
typedef enum mk_lib_fast_import_tree_node_id_e mk_lib_fast_import_tree_node_id_t;

union mk_lib_fast_import_tree_node_val_data_u
{
	mk_lib_fast_import_tree_pt m_tree;
	mk_lib_fast_import_blob_pt m_blob;
};
typedef union mk_lib_fast_import_tree_node_val_data_u mk_lib_fast_import_tree_node_val_data_t;
struct mk_lib_fast_import_tree_node_val_s
{
	mk_lib_fast_import_tree_node_val_data_t m_data;
};
typedef struct mk_lib_fast_import_tree_node_val_s mk_lib_fast_import_tree_node_val_t;
mk_lang_typedef(mk_lib_fast_import_tree_node_val);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_tree_node_s
{
	mk_lib_fast_import_tree_node_id_t m_type;
	mk_lib_fast_import_tree_node_val_t m_val;
	mk_lib_fast_import_string_t m_name;
	mk_lib_fast_import_tree_pt m_parent;
};
typedef struct mk_lib_fast_import_tree_node_s mk_lib_fast_import_tree_node_t;
mk_lang_typedef(mk_lib_fast_import_tree_node);
#include "mk_lang_warning_msvc_pop.h"

#define mk_sl_vector_t_name mk_lib_fast_import_tree_nodes
#define mk_sl_vector_t_element_type mk_lib_fast_import_tree_node_t
#define mk_sl_vector_t_mallocatorl mk_lib_fast_import_mallocator_lokal
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_tree_s
{
	mk_lib_fast_import_pt m_fi;
	mk_lang_types_pchar_t m_mode_buf[mk_lib_fast_import_file_mode_strlen_dec_v + 1];
	mk_lang_types_sint_t m_mode_len;
	mk_lib_fast_import_tree_nodes_t m_children;
	mk_lib_fast_import_binary_data_t m_data;
	mk_lang_types_bool_t m_digest_computed;
	mk_lib_crypto_hash_stream_sha1_digest_t m_digest_value;
};
typedef struct mk_lib_fast_import_tree_s mk_lib_fast_import_tree_t;
mk_lang_typedef(mk_lib_fast_import_tree);
#include "mk_lang_warning_msvc_pop.h"

#define mk_sl_vector_t_name mk_lib_fast_import_trees
#define mk_sl_vector_t_element_type mk_lib_fast_import_tree_pt
#define mk_sl_vector_t_mallocatorl mk_lib_fast_import_mallocator_lokal
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_mark_to_commit_s
{
	mk_lib_fast_import_mark_t m_mark;
	mk_lib_crypto_hash_stream_sha1_digest_t m_digest;
};
typedef struct mk_lib_fast_import_mark_to_commit_s mk_lib_fast_import_mark_to_commit_t;
mk_lang_typedef(mk_lib_fast_import_mark_to_commit);
#include "mk_lang_warning_msvc_pop.h"

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_mark_to_commit_cmp(mk_lib_fast_import_mark_to_commit_pct const a, mk_lib_fast_import_mark_to_commit_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(cmp);

	*cmp = mk_lib_fast_import_mark_cmp(&a->m_mark, &b->m_mark);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_mark_to_commit_copy_construct(mk_lib_fast_import_mark_to_commit_pt const dst, mk_lib_fast_import_mark_to_commit_pct const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_mark_to_commit_move_construct(mk_lib_fast_import_mark_to_commit_pt const dst, mk_lib_fast_import_mark_to_commit_pt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_mark_to_commit_destruct(mk_lib_fast_import_mark_to_commit_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	return 0;
}

#define mk_sl_tree_wavl_t_name mk_lib_fast_import_map_mark_to_commit
#define mk_sl_tree_wavl_t_element_type mk_lib_fast_import_mark_to_commit_t
#define mk_sl_tree_wavl_t_elements_compare mk_lib_fast_import_mark_to_commit_cmp
#define mk_sl_tree_wavl_t_mallocatorl_name mk_lib_fast_import_mallocator_lokal
#define mk_sl_tree_wavl_t_validate_want 0
#define mk_sl_tree_wavl_t_element_copy_construct mk_lib_fast_import_mark_to_commit_copy_construct
#define mk_sl_tree_wavl_t_element_move_construct mk_lib_fast_import_mark_to_commit_move_construct
#define mk_sl_tree_wavl_t_element_destruct mk_lib_fast_import_mark_to_commit_destruct
#include "mk_sl_tree_wavl_inl_fileh.h"
#include "mk_sl_tree_wavl_inl_filec.h"
#include "mk_sl_tree_wavl_inl_fileu.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_s
{
	mk_lib_fast_import_mallocator_lokal_pt m_mallocator;
	mk_lib_fast_import_buffered_reader_t m_buffered_reader;
	mk_sl_cui_uint8_pt m_buf;
	mk_lang_types_sint_t m_len;
	mk_lib_fast_import_tree_by_mark_t m_marks;
	mk_lib_fast_import_map_mark_to_commit_t m_commits;
	mk_lib_fast_import_string_t m_output_dir;
};
typedef struct mk_lib_fast_import_s mk_lib_fast_import_t;
mk_lang_typedef(mk_lib_fast_import);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_blob_ro_cmp(mk_lib_fast_import_blob_pct const a, mk_lib_fast_import_blob_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_types_sint_t c;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(cmp);

	c = mk_lib_fast_import_mark_cmp(&a->m_mark, &b->m_mark);
	*cmp = c;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_blob_rw_copy_construct(mk_lib_fast_import_blob_pt const dst, mk_lib_fast_import_blob_pct const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	dst->m_fi = src->m_fi;
	dst->m_mark = src->m_mark;
	dst->m_binary_len = src->m_binary_len;
	dst->m_binary_buf = src->m_binary_buf;
	dst->m_digest = src->m_digest;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_blob_rw_move_construct(mk_lib_fast_import_blob_pt const dst, mk_lib_fast_import_blob_pt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	dst->m_fi = src->m_fi;
	dst->m_mark = src->m_mark;
	dst->m_binary_len = src->m_binary_len; src->m_binary_len = 0;
	dst->m_binary_buf = src->m_binary_buf; src->m_binary_buf = mk_lang_null;
	dst->m_digest = src->m_digest;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_blob_rw_construct(mk_lib_fast_import_blob_pt const blob, mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_assert(blob);
	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);

	blob->m_fi = fi;
	mk_lib_fast_import_mark_set_zero(&blob->m_mark);
	mk_lang_string_memclr_pc_fn(&blob->m_mode_buf[0], mk_lang_countof(blob->m_mode_buf));
	blob->m_mode_len = 0;
	blob->m_binary_len = 0;
	blob->m_binary_buf = mk_lang_null;
	mk_sl_cui_uint8_memclr_fn(&blob->m_digest.m_data.m_uint8s[0], mk_lang_countof(blob->m_digest.m_data.m_uint8s));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_blob_rw_destroy(mk_lib_fast_import_blob_pt const blob) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(blob);

	err = mk_lib_fast_import_mallocator_lokal_deallocate(blob->m_fi->m_mallocator, blob->m_binary_buf, ((mk_lang_types_usize_t)(blob->m_binary_len))); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_blob_rw_copy_assign(mk_lib_fast_import_blob_pt const blob, mk_lib_fast_import_blob_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt mem;

	mk_lang_assert(blob);
	mk_lang_assert(src);
	mk_lang_assert(src->m_fi);
	mk_lang_assert(src->m_fi->m_mallocator);

	err = mk_lib_fast_import_blob_rw_destroy(blob); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_blob_rw_construct(blob, src->m_fi); mk_lang_check_rereturn(err);
	mk_lib_fast_import_mark_assign(&blob->m_mark, &src->m_mark);
	mk_lang_string_memcpy_pc_fn(&blob->m_mode_buf[0], &src->m_mode_buf[0], mk_lang_countof(blob->m_mode_buf));
	blob->m_mode_len = src->m_mode_len;
	if(src->m_binary_len != 0)
	{
		mk_lang_assert(src->m_binary_buf != mk_lang_null);
		err = mk_lib_fast_import_mallocator_lokal_allocate(blob->m_fi->m_mallocator, ((mk_lang_types_usize_t)(src->m_binary_len)), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); blob->m_binary_buf = ((mk_sl_cui_uint8_pt)(mem)); mk_lang_assert(blob->m_binary_buf);
		blob->m_binary_len = src->m_binary_len;
		mk_sl_cui_uint8_memcpy_fn(&blob->m_binary_buf[0], &src->m_binary_buf[0], ((mk_lang_types_usize_t)(src->m_binary_len)));
	}
	else
	{
		mk_lang_assert(src->m_binary_buf == mk_lang_null);
		blob->m_binary_len = 0;
		blob->m_binary_buf = mk_lang_null;
	}
	blob->m_digest = src->m_digest;
	return 0;
}


#define mk_sl_tree_wavl_t_name mk_lib_fast_import_tree_by_mark
#define mk_sl_tree_wavl_t_element_type mk_lib_fast_import_blob_t
#define mk_sl_tree_wavl_t_elements_compare mk_lib_fast_import_blob_ro_cmp
#define mk_sl_tree_wavl_t_mallocatorl_name mk_lib_fast_import_mallocator_lokal
#define mk_sl_tree_wavl_t_validate_want 0
#define mk_sl_tree_wavl_t_element_copy_construct mk_lib_fast_import_blob_rw_copy_construct
#define mk_sl_tree_wavl_t_element_move_construct mk_lib_fast_import_blob_rw_move_construct
#define mk_sl_tree_wavl_t_element_destruct mk_lib_fast_import_blob_rw_destroy
#include "mk_sl_tree_wavl_inl_filec.h"
#include "mk_sl_tree_wavl_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_fancy_str(mk_lib_fast_import_string_pt const str) mk_lang_noexcept
{
	mk_lang_types_pchar_t nul;
	mk_lang_types_sint_t err;

	mk_lang_assert(str);

	nul = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(str, &nul); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_pop_back_single(str); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_fancy_bin(mk_lib_fast_import_binary_data_pt const bin) mk_lang_noexcept
{
	mk_sl_cui_uint8_t nul;
	mk_lang_types_sint_t err;

	mk_lang_assert(bin);

	mk_sl_cui_uint8_set_zero(&nul);
	err = mk_lib_fast_import_binary_data_rw_push_back_copy_single(bin, &nul); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_pop_back_single(bin); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_generic_find(mk_lang_types_pchar_pct const haystack_buf, mk_lang_types_sint_t const haystack_len, mk_lang_types_pchar_pct const needle) mk_lang_noexcept
{
	mk_lang_types_pchar_t nnn mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(haystack_buf || haystack_len == 0);
	mk_lang_assert(haystack_len >= 0);
	mk_lang_assert(needle);

	nnn = *needle;
	n = haystack_len;
	for(i = 0; i != n; ++i)
	{
		if(haystack_buf[i] == nnn)
		{
			break;
		}
	}
	return i;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_generic_find_u8(mk_sl_cui_uint8_pct const haystack_buf, mk_lang_types_sint_t const haystack_len, mk_sl_cui_uint8_pct const needle_buf, mk_lang_types_sint_t const needle_len) mk_lang_noexcept
{
	mk_lang_types_sint_t found mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;

	mk_lang_assert(haystack_buf || haystack_len == 0);
	mk_lang_assert(haystack_len >= 0);
	mk_lang_assert(needle_buf);
	mk_lang_assert(needle_len >= 1);

	found = haystack_len;
	if(haystack_len >= needle_len)
	{
		n = haystack_len - needle_len;
		for(i = 0; i != n; ++i)
		{
			m = needle_len;
			for(j = 0; j != m; ++j)
			{
				if(mk_sl_cui_uint8_ne(&haystack_buf[i + j], &needle_buf[j]))
				{
					break;
				}
			}
			if(j == m)
			{
				found = i;
				break;
			}
		}
	}
	mk_lang_assert((found == haystack_len) || (found >= 0 && found <= haystack_len - needle_len));
	return found;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_string_compare(mk_lib_fast_import_string_pct const a_str, mk_lang_types_pchar_pct const b_buf, mk_lang_types_sint_t const b_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pct a_buf;
	mk_lang_types_sint_t a_len;
	mk_lang_types_bool_t cmp;

	mk_lang_assert(a_str);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(a_str));
	mk_lang_assert(b_buf);
	mk_lang_assert(b_len >= 1);

	a_buf = mk_lib_fast_import_string_ro_data(a_str); mk_lang_assert(a_buf);
	a_len = mk_lib_fast_import_string_ro_sise(a_str); mk_lang_assert(a_len >= 1);
	cmp = a_len == b_len;
	cmp = cmp && mk_lang_string_memcmp_pc_fn(a_buf, b_buf, ((mk_lang_types_usize_t)(a_len))) == 0;
	return cmp;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_string_rw_push_back_copy_many_u8(mk_lib_fast_import_string_pt const string, mk_sl_cui_uint8_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pct u8s;
	mk_lang_types_usize_t rem;
	mk_lang_types_usize_t cnt;
	mk_lang_types_pchar_t str[64];

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(string);
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_lib_fast_import_string_rw_reserve_additional(string, count); mk_lang_check_rereturn(err);
	u8s = elements;
	rem = count;
	while(rem != 0)
	{
		cnt = mk_lang_min(rem, mk_lang_countof(str));
		mk_sl_cui_uint8_to_bi_pchar_many(u8s, &str[0], cnt);
		err = mk_lib_fast_import_string_rw_push_back_copy_many(string, &str[0], cnt); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_st_fancy_str(string); mk_lang_check_rereturn(err);
		u8s += cnt;
		rem -= cnt;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_file_find_digest(mk_lib_fast_import_pt const fi, mk_lib_fast_import_mark_pct const file_ref, mk_lib_crypto_hash_stream_sha1_digest_pct* const digest) mk_lang_noexcept
{
	mk_lib_fast_import_blob_t blob;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_tree_by_mark_node_pt node;

	mk_lang_assert(fi);
	mk_lang_assert(file_ref);
	mk_lang_assert(digest);

	blob.m_mark = *file_ref;
	err = mk_lib_fast_import_tree_by_mark_ro_find_node(&fi->m_marks, &blob, &node); mk_lang_check_rereturn(err);
	if(node)
	{
		*digest = &node->m_element.m_digest;
	}
	else
	{
		*digest = mk_lang_null;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_file_op_rw_construct(mk_lib_fast_import_file_op_pt const file_op, mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(file_op);
	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);

	file_op->m_fi = fi;
	file_op->m_file_modify.m_fi = fi;
	mk_sl_cui_uint32_set_zero(&file_op->m_file_modify.m_mode);
	mk_lib_fast_import_mark_set_zero(&file_op->m_file_modify.m_data_ref);
	err = mk_lib_fast_import_string_rw_construct(&file_op->m_file_modify.m_path, fi->m_mallocator); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_any_rw_deserialize_pr_object_len(mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[mk_sl_cui_uint32_strlen_dec_v + 1];
	mk_lang_types_sint_t len;
	mk_sl_cui_uint32_t obj_len_u32;
	mk_lang_types_ulong_t tul;
	mk_lang_types_sint_t obj_len_si;

	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	gud = mk_lang_true;
	if(gud)
	{
		str_len = mk_lang_min(binary_data_len, mk_lang_countof(str_buf));
		mk_sl_cui_uint8_to_bi_pchar_many(binary_data_buf, &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
		len = mk_sl_cui_uint32_from_str_dec_n(&obj_len_u32, &str_buf[0], str_len); mk_lang_assert(len <= str_len);
		gud = len >= 1;
	}
	if(gud)
	{
		mk_lang_clobber(&len);
		gud = str_buf[len] == '\0';
	}
	if(gud)
	{
		mk_sl_cui_uint32_to_bi_ulong(&obj_len_u32, &tul);
		gud = tul <= ((mk_lang_types_ulong_t)(mk_lang_limits_sint_max));
	}
	if(gud)
	{
		mk_lang_clobber(&tul);
		mk_lang_clobber(&len);
		obj_len_si = ((mk_lang_types_sint_t)(tul));
		gud = obj_len_si == binary_data_len - len - 1;
	}
	mk_lang_clobber(&len);
	*success = gud;
	*consumed = len + 1;
	return 0;
#include "mk_lang_warning_clang_pop.h"
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_construct(mk_lib_fast_import_commit_pt const commit, mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(commit);
	mk_lang_assert(fi);

	commit->m_fi = fi;
	err = mk_lib_fast_import_string_rw_construct(&commit->m_ref, fi->m_mallocator); mk_lang_check_rereturn(err);
	commit->m_has_mark = mk_lang_false;
	mk_lib_fast_import_mark_set_zero(&commit->m_mark);
	err = mk_lib_fast_import_string_rw_construct(&commit->m_author_name, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_construct(&commit->m_author_email, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_construct(&commit->m_author_timestamp, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_construct(&commit->m_committer_name, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_construct(&commit->m_committer_email, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_construct(&commit->m_committer_timestamp, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_construct(&commit->m_message, fi->m_mallocator); mk_lang_check_rereturn(err);
	commit->m_has_from_mark_ref = mk_lang_false;
	mk_lib_fast_import_mark_set_zero(&commit->m_from_mark_ref);
	err = mk_lib_fast_import_file_ops_rw_construct(&commit->m_file_ops, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_construct(&commit->m_data, fi->m_mallocator); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_destroy(mk_lib_fast_import_commit_pt const commit) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(commit);

	err = mk_lib_fast_import_string_rw_destroy(&commit->m_ref); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&commit->m_author_name); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&commit->m_author_email); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&commit->m_author_timestamp); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&commit->m_committer_name); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&commit->m_committer_email); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&commit->m_committer_timestamp); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_destroy(&commit->m_message); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_file_ops_rw_destroy(&commit->m_file_ops); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_destroy(&commit->m_data); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_clear(mk_lib_fast_import_commit_pt const commit) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);

	err = mk_lib_fast_import_string_rw_clear(&commit->m_ref); mk_lang_check_rereturn(err);
	commit->m_has_mark = mk_lang_false;
	mk_lib_fast_import_mark_set_zero(&commit->m_mark);
	err = mk_lib_fast_import_string_rw_clear(&commit->m_author_name); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_clear(&commit->m_author_email); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_clear(&commit->m_author_timestamp); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_clear(&commit->m_committer_name); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_clear(&commit->m_committer_email); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_clear(&commit->m_committer_timestamp); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_clear(&commit->m_message); mk_lang_check_rereturn(err);
	commit->m_has_from_mark_ref = mk_lang_false;
	mk_lib_fast_import_mark_set_zero(&commit->m_from_mark_ref);
	err = mk_lib_fast_import_file_ops_rw_clear(&commit->m_file_ops); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_clear(&commit->m_data); mk_lang_check_rereturn(err);
	mk_sl_cui_uint8_memclr_fn(&commit->m_digest.m_data.m_uint8s[0], mk_lang_countof(commit->m_digest.m_data.m_uint8s));
	mk_sl_cui_uint8_memclr_fn(&commit->m_tree_digest.m_data.m_uint8s[0], mk_lang_countof(commit->m_tree_digest.m_data.m_uint8s));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_pr_object_type(mk_lib_fast_import_commit_pt const commit, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;
	mk_sl_cui_uint8_t commit_sp[mk_lang_countstr(mk_lib_fast_import_k_commitsp)];

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	gud = mk_lang_true;
	if(gud)
	{
		gud = binary_data_len >= mk_lang_countof(commit_sp);
	}
	if(gud)
	{
		mk_sl_cui_uint8_from_bi_pchar_many(&commit_sp[0], &mk_lib_fast_import_k_commitsp[0], mk_lang_countstr(mk_lib_fast_import_k_commitsp));
		gud = mk_sl_cui_uint8_memcmp_fn(binary_data_buf, &commit_sp[0], mk_lang_countof(commit_sp)) == 0;
	}
	*success = gud;
	*consumed = mk_lang_countof(commit_sp);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_pr_object_len(mk_lib_fast_import_commit_pt const commit, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(commit->m_fi->m_mallocator);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	err = mk_lib_fast_import_any_rw_deserialize_pr_object_len(binary_data_buf, binary_data_len, success, consumed); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_pr_tree(mk_lib_fast_import_commit_pt const commit, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_bool_t gud;
	mk_sl_cui_uint8_t tree_sp[mk_lang_countstr(mk_lib_fast_import_k_tree_sp)];
	mk_lang_types_pchar_t digest_str[((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_sha1_digest_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))];
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;
	if(gud)
	{
		gud = data_len >= mk_lang_countof(tree_sp);
	}
	if(gud)
	{
		mk_sl_cui_uint8_from_bi_pchar_many(&tree_sp[0], &mk_lib_fast_import_k_tree_sp[0], mk_lang_countstr(mk_lib_fast_import_k_tree_sp));
		gud = mk_sl_cui_uint8_memcmp_fn(data_buf, &tree_sp[0], mk_lang_countof(tree_sp)) == 0;
	}
	if(gud)
	{
		data_buf += mk_lang_countof(tree_sp);
		data_len -= mk_lang_countof(tree_sp);
		gud = data_len >= mk_lang_countof(digest_str);
	}
	if(gud)
	{
		mk_sl_cui_uint8_to_bi_pchar_many(data_buf, &digest_str[0], mk_lang_countof(digest_str));
		len = mk_sl_cui_uint8_from_str_hex_many_n(&commit->m_tree_digest.m_data.m_uint8s[0], mk_lang_countof(commit->m_tree_digest.m_data.m_uint8s), &digest_str[0], mk_lang_countof(digest_str)); mk_lang_assert(len >= 0); mk_lang_assert(len <= mk_lang_countof(digest_str));
		gud = len == mk_lang_countof(digest_str);
	}
	if(gud)
	{
		data_buf += mk_lang_countof(digest_str);
		data_len -= mk_lang_countof(digest_str);
		gud = data_len >= 1;
	}
	if(gud)
	{
		mk_sl_cui_uint8_to_bi_sint(&data_buf[0], &tsi);
		gud = tsi == 0x0a;
	}
	if(gud)
	{
		data_buf += 1;
		data_len -= 1;
	}
	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_pr_author_prefix(mk_lib_fast_import_commit_pt const commit, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_bool_t gud;
	mk_sl_cui_uint8_t str_u8_author_sp[mk_lang_countstr(mk_lib_fast_import_k_author_sp)];

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;
	if(gud)
	{
		gud = data_len >= mk_lang_countof(str_u8_author_sp);
	}
	if(gud)
	{
		mk_sl_cui_uint8_from_bi_pchar_many(&str_u8_author_sp[0], &mk_lib_fast_import_k_author_sp[0], mk_lang_countstr(mk_lib_fast_import_k_author_sp));
		gud = mk_sl_cui_uint8_memcmp_fn(data_buf, &str_u8_author_sp[0], mk_lang_countof(str_u8_author_sp)) == 0;
	}
	if(gud)
	{
		data_buf += mk_lang_countof(str_u8_author_sp);
		data_len -= mk_lang_countof(str_u8_author_sp);
	}
	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_pr_committer_prefix(mk_lib_fast_import_commit_pt const commit, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_bool_t gud;
	mk_sl_cui_uint8_t str_u8_committer_sp[mk_lang_countstr(mk_lib_fast_import_k_committer_sp)];

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;
	if(gud)
	{
		gud = data_len >= mk_lang_countof(str_u8_committer_sp);
	}
	if(gud)
	{
		mk_sl_cui_uint8_from_bi_pchar_many(&str_u8_committer_sp[0], &mk_lib_fast_import_k_committer_sp[0], mk_lang_countstr(mk_lib_fast_import_k_committer_sp));
		gud = mk_sl_cui_uint8_memcmp_fn(data_buf, &str_u8_committer_sp[0], mk_lang_countof(str_u8_committer_sp)) == 0;
	}
	if(gud)
	{
		data_buf += mk_lang_countof(str_u8_committer_sp);
		data_len -= mk_lang_countof(str_u8_committer_sp);
	}
	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_pr_name(mk_lib_fast_import_commit_pt const commit, mk_lib_fast_import_string_pt const name, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_bool_t gud;
	mk_sl_cui_uint8_t str_u8_splt[mk_lang_countstr(mk_lib_fast_import_k_splt)];
	mk_lang_types_sint_t found;
	mk_lang_types_sint_t err;

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(name);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;
	if(gud)
	{
		gud = data_len >= 1 + mk_lang_countof(str_u8_splt);
	}
	if(gud)
	{
		mk_sl_cui_uint8_from_bi_pchar_many(&str_u8_splt[0], &mk_lib_fast_import_k_splt[0], mk_lang_countstr(mk_lib_fast_import_k_splt));
		found = mk_generic_find_u8(data_buf, data_len, &str_u8_splt[0], mk_lang_countof(str_u8_splt)); mk_lang_assert((found == data_len) || (found >= 1 && found <= data_len - mk_lang_countof(str_u8_splt)));
		gud = found != data_len;
	}
	if(gud)
	{
		mk_lang_clobber(&found);
		err = mk_lib_fast_import_string_rw_clear(name); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_string_rw_push_back_copy_many_u8(name, data_buf, ((mk_lang_types_usize_t)(found))); mk_lang_check_rereturn(err);
		data_buf += found;
		data_len -= found;
		data_buf += mk_lang_countof(str_u8_splt);
		data_len -= mk_lang_countof(str_u8_splt);
	}
	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_pr_email(mk_lib_fast_import_commit_pt const commit, mk_lib_fast_import_string_pt const email, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_bool_t gud;
	mk_sl_cui_uint8_t str_u8_gtsp[mk_lang_countstr(mk_lib_fast_import_k_gtsp)];
	mk_lang_types_sint_t found;
	mk_lang_types_sint_t err;

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(email);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;
	if(gud)
	{
		gud = data_len >= 1 + mk_lang_countof(str_u8_gtsp);
	}
	if(gud)
	{
		mk_sl_cui_uint8_from_bi_pchar_many(&str_u8_gtsp[0], &mk_lib_fast_import_k_gtsp[0], mk_lang_countstr(mk_lib_fast_import_k_gtsp));
		found = mk_generic_find_u8(data_buf, data_len, &str_u8_gtsp[0], mk_lang_countof(str_u8_gtsp)); mk_lang_assert((found == data_len) || (found >= 1 && found <= data_len - mk_lang_countof(str_u8_gtsp)));
		gud = found != data_len;
	}
	if(gud)
	{
		mk_lang_clobber(&found);
		err = mk_lib_fast_import_string_rw_clear(email); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_string_rw_push_back_copy_many_u8(email, data_buf, ((mk_lang_types_usize_t)(found))); mk_lang_check_rereturn(err);
		data_buf += found;
		data_len -= found;
		data_buf += mk_lang_countof(str_u8_gtsp);
		data_len -= mk_lang_countof(str_u8_gtsp);
	}
	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_pr_timestamp(mk_lib_fast_import_commit_pt const commit, mk_lib_fast_import_string_pt const timestamp, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_bool_t gud;
	mk_sl_cui_uint8_t str_u8_lf[mk_lang_countstr(mk_lib_fast_import_k_lf)];
	mk_lang_types_sint_t found;
	mk_lang_types_sint_t err;

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(timestamp);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;
	if(gud)
	{
		gud = data_len >= 1 + mk_lang_countof(str_u8_lf);
	}
	if(gud)
	{
		mk_sl_cui_uint8_from_bi_pchar_many(&str_u8_lf[0], &mk_lib_fast_import_k_lf[0], mk_lang_countstr(mk_lib_fast_import_k_lf));
		found = mk_generic_find_u8(data_buf, data_len, &str_u8_lf[0], mk_lang_countof(str_u8_lf)); mk_lang_assert((found == data_len) || (found >= 1 && found <= data_len - mk_lang_countof(str_u8_lf)));
		gud = found != data_len;
	}
	if(gud)
	{
		mk_lang_clobber(&found);
		err = mk_lib_fast_import_string_rw_clear(timestamp); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_string_rw_push_back_copy_many_u8(timestamp, data_buf, ((mk_lang_types_usize_t)(found))); mk_lang_check_rereturn(err);
		data_buf += found;
		data_len -= found;
		data_buf += mk_lang_countof(str_u8_lf);
		data_len -= mk_lang_countof(str_u8_lf);
	}
	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_pr_author(mk_lib_fast_import_commit_pt const commit, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t used;

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_author_prefix(commit,                              data_buf, data_len, &gud, &used); mk_lang_check_rereturn(err); mk_lang_assert(used >= 0); mk_lang_assert(used <= data_len); data_buf += used; data_len -= used; }
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_name         (commit, &commit->m_author_name,      data_buf, data_len, &gud, &used); mk_lang_check_rereturn(err); mk_lang_assert(used >= 0); mk_lang_assert(used <= data_len); data_buf += used; data_len -= used; }
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_email        (commit, &commit->m_author_email,     data_buf, data_len, &gud, &used); mk_lang_check_rereturn(err); mk_lang_assert(used >= 0); mk_lang_assert(used <= data_len); data_buf += used; data_len -= used; }
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_timestamp    (commit, &commit->m_author_timestamp, data_buf, data_len, &gud, &used); mk_lang_check_rereturn(err); mk_lang_assert(used >= 0); mk_lang_assert(used <= data_len); data_buf += used; data_len -= used; }
	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_pr_committer(mk_lib_fast_import_commit_pt const commit, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t used;

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_committer_prefix(commit,                                 data_buf, data_len, &gud, &used); mk_lang_check_rereturn(err); mk_lang_assert(used >= 0); mk_lang_assert(used <= data_len); data_buf += used; data_len -= used; }
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_name            (commit, &commit->m_committer_name,      data_buf, data_len, &gud, &used); mk_lang_check_rereturn(err); mk_lang_assert(used >= 0); mk_lang_assert(used <= data_len); data_buf += used; data_len -= used; }
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_email           (commit, &commit->m_committer_email,     data_buf, data_len, &gud, &used); mk_lang_check_rereturn(err); mk_lang_assert(used >= 0); mk_lang_assert(used <= data_len); data_buf += used; data_len -= used; }
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_timestamp       (commit, &commit->m_committer_timestamp, data_buf, data_len, &gud, &used); mk_lang_check_rereturn(err); mk_lang_assert(used >= 0); mk_lang_assert(used <= data_len); data_buf += used; data_len -= used; }
	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_pr_message(mk_lib_fast_import_commit_pt const commit, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_bool_t gud;
	mk_lang_types_pchar_t tpc;
	mk_sl_cui_uint8_t lf;
	mk_lang_types_sint_t err;

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;
	if(gud)
	{
		gud = data_len >= 1;
	}
	if(gud)
	{
		tpc = '\x0a'; mk_sl_cui_uint8_from_bi_pchar(&lf, &tpc);
		gud = mk_sl_cui_uint8_eq(&data_buf[0], &lf);
	}
	if(gud)
	{
		data_buf += 1;
		data_len -= 1;
	}
	if(gud)
	{
		err = mk_lib_fast_import_binary_data_rw_clear(&commit->m_message); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_binary_data_rw_push_back_copy_many(&commit->m_message, data_buf, ((mk_lang_types_usize_t)(data_len))); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_st_fancy_bin(&commit->m_message); mk_lang_check_rereturn(err);
		data_buf += data_len;
		data_len -= data_len;
	}
	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_from_buf_and_len(mk_lib_fast_import_commit_pt const commit, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(did);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	err = mk_lib_fast_import_commit_rw_clear(commit); mk_lang_check_rereturn(err);
	gud = mk_lang_true;
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_object_type(commit, data_buf, data_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(consumed >= 0); mk_lang_assert(consumed <= data_len); data_buf += consumed; data_len -= consumed; }
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_object_len (commit, data_buf, data_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(consumed >= 0); mk_lang_assert(consumed <= data_len); data_buf += consumed; data_len -= consumed; }
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_tree       (commit, data_buf, data_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(consumed >= 0); mk_lang_assert(consumed <= data_len); data_buf += consumed; data_len -= consumed; }
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_author     (commit, data_buf, data_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(consumed >= 0); mk_lang_assert(consumed <= data_len); data_buf += consumed; data_len -= consumed; }
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_committer  (commit, data_buf, data_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(consumed >= 0); mk_lang_assert(consumed <= data_len); data_buf += consumed; data_len -= consumed; }
	if(gud){ err = mk_lib_fast_import_commit_rw_deserialize_pr_message    (commit, data_buf, data_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(consumed >= 0); mk_lang_assert(consumed <= data_len); data_buf += consumed; data_len -= consumed; }
	*did = gud;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_deserialize_from_binary_data(mk_lib_fast_import_commit_pt const commit, mk_lib_fast_import_binary_data_pct const binary_data, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct binary_data_buf;
	mk_lang_types_sint_t binary_data_len;
	mk_lang_types_sint_t err;

	mk_lang_assert(commit);
	mk_lang_assert(commit->m_fi);
	mk_lang_assert(binary_data);
	mk_lang_assert(did);

	binary_data_buf = mk_lib_fast_import_binary_data_ro_data(binary_data);
	binary_data_len = mk_lib_fast_import_binary_data_ro_sise(binary_data);
	err = mk_lib_fast_import_commit_rw_deserialize_from_buf_and_len(commit, binary_data_buf, binary_data_len, did); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_rw_construct(mk_lib_fast_import_tree_pt const tree, mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);

	tree->m_fi = fi;
	mk_lang_string_memclr_pc_fn(&tree->m_mode_buf[0], mk_lang_countof(tree->m_mode_buf));
	tree->m_mode_len = 0;
	err = mk_lib_fast_import_tree_nodes_rw_construct(&tree->m_children, tree->m_fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_construct(&tree->m_data, tree->m_fi->m_mallocator); mk_lang_check_rereturn(err);
	tree->m_digest_computed = mk_lang_false;
	mk_sl_cui_uint8_memclr_fn(&tree->m_digest_value.m_data.m_uint8s[0], mk_lang_countof(tree->m_digest_value.m_data.m_uint8s));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_destroy(mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);

	err = mk_lib_fast_import_tree_nodes_rw_destroy(&tree->m_children); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_destroy(&tree->m_data); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_rw_clear(mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(tree->m_fi);
	mk_lang_assert(tree->m_fi->m_mallocator);

	#if defined DEBUG || defined _DEBUG
	mk_lang_string_memclr_pc_fn(&tree->m_mode_buf[0], mk_lang_countof(tree->m_mode_buf));
	#endif
	tree->m_mode_len = 0;
	err = mk_lib_fast_import_tree_nodes_rw_clear(&tree->m_children); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_clear(&tree->m_data); mk_lang_check_rereturn(err);
	tree->m_digest_computed = mk_lang_false;
	#if defined DEBUG || defined _DEBUG
	mk_sl_cui_uint8_memclr_fn(&tree->m_digest_value.m_data.m_uint8s[0], mk_lang_countof(tree->m_digest_value.m_data.m_uint8s));
	#endif
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_node_rw_construct(mk_lib_fast_import_tree_node_pt const tree_node, mk_lib_fast_import_pt const fi, mk_lib_fast_import_tree_node_id_t const type, mk_lib_fast_import_tree_pt const parent, mk_lang_types_pchar_pct const name_buf, mk_lang_types_sint_t const name_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt mem;
	mk_lib_fast_import_tree_pt tree;
	mk_lib_fast_import_blob_pt blob;

	mk_lang_assert(tree_node);
	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(type >= 0);
	mk_lang_assert(type < mk_lib_fast_import_tree_node_id_e_dummy_end);
	mk_lang_assert(parent || !parent);
	mk_lang_assert(name_buf);
	mk_lang_assert(name_len >= 1);

	tree_node->m_type = type;
	switch(type)
	{
		case mk_lib_fast_import_tree_node_id_e_tree:
		{
			err = mk_lib_fast_import_mallocator_lokal_allocate(fi->m_mallocator, sizeof(*tree), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem);
			tree = ((mk_lib_fast_import_tree_pt)(mem));
			tree_node->m_val.m_data.m_tree = tree;
			err = mk_lib_fast_import_tree_rw_construct(tree, fi); mk_lang_check_rereturn(err);
		}
		break;
		case mk_lib_fast_import_tree_node_id_e_blob:
		{
			err = mk_lib_fast_import_mallocator_lokal_allocate(fi->m_mallocator, sizeof(*blob), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem);
			blob = ((mk_lib_fast_import_blob_pt)(mem));
			tree_node->m_val.m_data.m_blob = blob;
			err = mk_lib_fast_import_blob_rw_construct(blob, fi); mk_lang_check_rereturn(err);
		}
		break;
		case mk_lib_fast_import_tree_node_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	err = mk_lib_fast_import_string_rw_construct(&tree_node->m_name, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&tree_node->m_name, name_buf, ((mk_lang_types_usize_t)(name_len))); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_st_fancy_str(&tree_node->m_name); mk_lang_check_rereturn(err);
	tree_node->m_parent = parent;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_load_from_commit_3(mk_lib_fast_import_tree_pt const tree, mk_lib_fast_import_file_op_pct const file_op, mk_lang_types_pchar_pct const part_buf, mk_lang_types_sint_t const part_len, mk_lang_types_bool_t const is_last, mk_lib_fast_import_tree_ppt const curr) mk_lang_noexcept
{
	mk_lib_fast_import_tree_pt cr;
	mk_lang_types_sint_t count;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_fast_import_tree_node_pt child;
	mk_lib_fast_import_tree_node_id_t type;
	mk_lang_types_sint_t err;
	mk_lib_crypto_hash_stream_sha1_digest_pct digest;
	mk_lang_types_sint_t tsi;
	mk_sl_cui_uint32_t tu32;

	mk_lang_assert(tree);
	mk_lang_assert(file_op);
	mk_lang_assert(part_buf);
	mk_lang_assert(part_len >= 1);
	mk_lang_assert(is_last == mk_lang_false || is_last == mk_lang_true);
	mk_lang_assert(curr);
	mk_lang_assert(*curr);

	cr = *curr;
	count = mk_lib_fast_import_tree_nodes_rw_sise(&cr->m_children); mk_lang_assert(count >= 0);
	n = count;
	for(i = 0; i != n; ++i)
	{
		child = mk_lib_fast_import_tree_nodes_rw_at(&cr->m_children, ((mk_lang_types_usize_t)(i))); mk_lang_assert(child);
		if(!is_last && child->m_type == mk_lib_fast_import_tree_node_id_e_tree && mk_string_compare(&child->m_name, part_buf, part_len))
		{
			cr = child->m_val.m_data.m_tree;
			break;
		}
	}
	if(cr == *curr)
	{
		type = is_last ? mk_lib_fast_import_tree_node_id_e_blob : mk_lib_fast_import_tree_node_id_e_tree;
		err = mk_lib_fast_import_tree_nodes_rw_grow_by(&cr->m_children, 1); mk_lang_check_rereturn(err);
		child = mk_lib_fast_import_tree_nodes_rw_back(&cr->m_children); mk_lang_assert(child);
		err = mk_lib_fast_import_tree_node_rw_construct(child, tree->m_fi, type, cr, part_buf, part_len); mk_lang_check_rereturn(err);
		if(is_last)
		{
			err = mk_lib_fast_import_pr_file_find_digest(cr->m_fi, &file_op->m_file_modify.m_data_ref, &digest); mk_lang_check_rereturn(err); mk_lang_check_return(digest);
			child->m_val.m_data.m_blob->m_mark = file_op->m_file_modify.m_data_ref;
			child->m_val.m_data.m_blob->m_digest = *digest;
			child->m_val.m_data.m_blob->m_mode_len = mk_sl_cui_uint32_to_str_dec_n(&file_op->m_file_modify.m_mode, &child->m_val.m_data.m_blob->m_mode_buf[0], mk_lang_countof(child->m_val.m_data.m_blob->m_mode_buf));
		}
		else
		{
			tsi = 40000; mk_sl_cui_uint32_from_bi_sint(&tu32, &tsi); child->m_val.m_data.m_tree->m_mode_len = mk_sl_cui_uint32_to_str_dec_n(&tu32, &child->m_val.m_data.m_tree->m_mode_buf[0], mk_lang_countof(child->m_val.m_data.m_tree->m_mode_buf)); mk_lang_assert(child->m_val.m_data.m_tree->m_mode_len == 5);
			cr = child->m_val.m_data.m_tree;
		}
	}
	*curr = cr;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_load_from_commit_2(mk_lib_fast_import_tree_pt const tree, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_pchar_t sep;
	mk_lib_fast_import_tree_pt curr;
	mk_lang_types_pchar_pct path_buf;
	mk_lang_types_sint_t path_len;
	mk_lang_types_sint_t pos;
	mk_lang_types_pchar_pct part_buf;
	mk_lang_types_sint_t part_len;
	mk_lang_types_bool_t is_last;
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(file_op);

	sep = '/';
	curr = tree;
	path_buf = mk_lib_fast_import_string_ro_data(&file_op->m_file_modify.m_path);
	path_len = mk_lib_fast_import_string_ro_sise(&file_op->m_file_modify.m_path);
	do
	{
		pos = mk_generic_find(path_buf, path_len, &sep);
		part_buf = path_buf;
		part_len = pos;
		is_last = pos == path_len;
		err = mk_lib_fast_import_tree_load_from_commit_3(tree, file_op, part_buf, part_len, is_last, &curr); mk_lang_check_rereturn(err);
		path_buf += part_len + 1;
		path_len -= part_len + 1;
	}while(!is_last);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_load_from_commit(mk_lib_fast_import_tree_pt const tree, mk_lib_fast_import_commit_pct const commit) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fast_import_file_op_pct file_op;

	mk_lang_assert(tree);
	mk_lang_assert(commit);

	err = mk_lib_fast_import_tree_rw_clear(tree); mk_lang_check_rereturn(err);
	n = mk_lib_fast_import_file_ops_ro_size(&commit->m_file_ops);
	for(i = 0; i != n; ++i)
	{
		file_op = mk_lib_fast_import_file_ops_ro_at(&commit->m_file_ops, i); mk_lang_assert(file_op);
		err = mk_lib_fast_import_tree_load_from_commit_2(tree, file_op); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_debug_print_p(mk_lib_fast_import_file_ops_pct const file_ops) mk_lang_noexcept
{
	mk_lang_types_pchar_t sp;
	mk_lang_types_pchar_t colon;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_fast_import_file_op_pct file_op;
	mk_lib_fast_import_file_modify_pct op_modify;
	mk_lang_types_pchar_t name;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t mode[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_pchar_t ref[mk_lib_fast_import_mark_strlen_dec_v];

	mk_lang_assert(file_ops);

	sp = ' ';
	colon = ':';
	n = mk_lib_fast_import_file_ops_ro_sise(file_ops);
	for(i = 0; i != n; ++i)
	{
		file_op = mk_lib_fast_import_file_ops_ro_at(file_ops, ((mk_lang_types_usize_t)(i))); mk_lang_assert(file_op);
		op_modify = &file_op->m_file_modify;
		name = 'M';
		err = mk_lang_stdout_print_n(&name, 1); mk_lang_check_rereturn(err);
		err = mk_lang_stdout_print_n(&sp, 1); mk_lang_check_rereturn(err);
		len = mk_sl_cui_uint32_to_str_dec_n(&op_modify->m_mode, &mode[0], mk_lang_countof(mode)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(mode));
		err = mk_lang_stdout_print_n(&mode[0], len); mk_lang_check_rereturn(err);
		err = mk_lang_stdout_print_n(&sp, 1); mk_lang_check_rereturn(err);
		err = mk_lang_stdout_print_n(&colon, 1); mk_lang_check_rereturn(err);
		len = mk_lib_fast_import_mark_to_str_dec_n(&op_modify->m_data_ref, &ref[0], mk_lang_countof(ref)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(ref));
		err = mk_lang_stdout_print_n(&ref[0], len); mk_lang_check_rereturn(err);
		err = mk_lang_stdout_print_n(&sp, 1); mk_lang_check_rereturn(err);
		err = mk_lang_stdout_print_n(mk_lib_fast_import_string_ro_data(&op_modify->m_path), mk_lib_fast_import_string_ro_sise(&op_modify->m_path)); mk_lang_check_rereturn(err);
		err = mk_lang_stdout_println_lit_n(""); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_debug_print_r(mk_lib_fast_import_pt const fi, mk_lib_fast_import_tree_node_pct const node, mk_lib_fast_import_string_pt const path, mk_lib_fast_import_file_ops_pt const file_ops) mk_lang_noexcept
{
	mk_lib_fast_import_tree_pct sub_tree;
	mk_lang_types_usize_t old_len;
	mk_lang_types_pchar_t sep;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_fast_import_tree_node_pct sub_node;
	mk_lib_fast_import_blob_pct sub_blob;
	mk_lib_fast_import_file_op_pt file_op;
	mk_lib_fast_import_file_modify_pt op_modify;
	mk_lang_types_sint_t len;
	mk_lib_fast_import_file_op_t op;

	mk_lang_assert(fi);
	mk_lang_assert(node);
	mk_lang_assert(path);
	mk_lang_assert(file_ops);

	switch(node->m_type)
	{
		case mk_lib_fast_import_tree_node_id_e_tree:
		{
			sub_tree = node->m_val.m_data.m_tree;
			old_len = mk_lib_fast_import_string_rw_size(path);
			sep = '/'; if(!mk_lib_fast_import_string_rw_is_empty(path)){ err = mk_lib_fast_import_string_rw_push_back_copy_single(path, &sep); mk_lang_check_rereturn(err); err = mk_lib_fast_import_st_fancy_str(path); mk_lang_check_rereturn(err); }
			err = mk_lib_fast_import_string_rw_push_back_copy_many(path, mk_lib_fast_import_string_ro_data(&node->m_name), mk_lib_fast_import_string_ro_size(&node->m_name)); mk_lang_check_rereturn(err); err = mk_lib_fast_import_st_fancy_str(path); mk_lang_check_rereturn(err);
			n = mk_lib_fast_import_tree_nodes_ro_sise(&sub_tree->m_children);
			for(i = 0; i != n; ++i)
			{
				sub_node = mk_lib_fast_import_tree_nodes_ro_at(&sub_tree->m_children, ((mk_lang_types_usize_t)(i))); mk_lang_assert(sub_node);
				err = mk_lib_fast_import_tree_debug_print_r(fi, sub_node, path, file_ops); mk_lang_check_rereturn(err);
			}
			err = mk_lib_fast_import_string_rw_resize_to(path, old_len); mk_lang_check_rereturn(err); err = mk_lib_fast_import_st_fancy_str(path); mk_lang_check_rereturn(err);
		}
		break;
		case mk_lib_fast_import_tree_node_id_e_blob:
		{
			sub_blob = node->m_val.m_data.m_blob;
			err = mk_lib_fast_import_file_op_rw_construct(&op, fi); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_file_ops_rw_push_back_move_single(file_ops, &op); mk_lang_check_rereturn(err);
			file_op = mk_lib_fast_import_file_ops_rw_back(file_ops); mk_lang_assert(file_op);
			op_modify = &file_op->m_file_modify;
			len = mk_sl_cui_uint32_from_str_dec_n(&op_modify->m_mode, &sub_blob->m_mode_buf[0], sub_blob->m_mode_len); mk_lang_assert(len >= 1); mk_lang_assert(len <= sub_blob->m_mode_len);
			op_modify->m_data_ref = sub_blob->m_mark;
			old_len = mk_lib_fast_import_string_rw_size(path);
			sep = '/'; if(!mk_lib_fast_import_string_rw_is_empty(path)){ err = mk_lib_fast_import_string_rw_push_back_copy_single(path, &sep); mk_lang_check_rereturn(err); err = mk_lib_fast_import_st_fancy_str(path); mk_lang_check_rereturn(err); }
			err = mk_lib_fast_import_string_rw_push_back_copy_many(path, mk_lib_fast_import_string_ro_data(&node->m_name), mk_lib_fast_import_string_ro_size(&node->m_name)); mk_lang_check_rereturn(err); err = mk_lib_fast_import_st_fancy_str(path); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_string_rw_push_back_copy_many(&op_modify->m_path, mk_lib_fast_import_string_ro_data(path), mk_lib_fast_import_string_ro_size(path)); mk_lang_check_rereturn(err); err = mk_lib_fast_import_st_fancy_str(&op_modify->m_path); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_string_rw_resize_to(path, old_len); mk_lang_check_rereturn(err); err = mk_lib_fast_import_st_fancy_str(path); mk_lang_check_rereturn(err);
		}
		break;
		case mk_lib_fast_import_tree_node_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_debug_print(mk_lib_fast_import_tree_pct const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_fast_import_string_t path;
	mk_lib_fast_import_file_ops_t file_ops;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_fast_import_tree_node_pct node;

	mk_lang_assert(tree);
	mk_lang_assert(tree->m_fi);
	mk_lang_assert(tree->m_fi->m_mallocator);

	err = mk_lang_stdout_println_lit_n("=========="); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_construct(&path, tree->m_fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_file_ops_rw_construct(&file_ops, tree->m_fi->m_mallocator); mk_lang_check_rereturn(err);
	n = mk_lib_fast_import_tree_nodes_ro_sise(&tree->m_children);
	for(i = 0; i != n; ++i)
	{
		node = mk_lib_fast_import_tree_nodes_ro_at(&tree->m_children, ((mk_lang_types_usize_t)(i))); mk_lang_assert(node);
		err = mk_lib_fast_import_tree_debug_print_r(tree->m_fi, node, &path, &file_ops); mk_lang_check_rereturn(err);
	}
	err = mk_lib_fast_import_tree_debug_print_p(&file_ops); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_file_ops_rw_destroy(&file_ops); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&path); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_n("=========="); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_rw_deserialize_pr_object_type(mk_lib_fast_import_tree_pt const tree, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;
	mk_sl_cui_uint8_t tree_sp[mk_lang_countstr(mk_lib_fast_import_k_tree_sp)];

	mk_lang_assert(tree);
	mk_lang_assert(tree->m_fi);
	mk_lang_assert(tree->m_fi->m_mallocator);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	gud = mk_lang_true;
	if(gud)
	{
		gud = binary_data_len >= mk_lang_countof(tree_sp);
	}
	if(gud)
	{
		mk_sl_cui_uint8_from_bi_pchar_many(&tree_sp[0], &mk_lib_fast_import_k_tree_sp[0], mk_lang_countstr(mk_lib_fast_import_k_tree_sp));
		gud = mk_sl_cui_uint8_memcmp_fn(binary_data_buf, &tree_sp[0], mk_lang_countof(tree_sp)) == 0;
	}
	*success = gud;
	*consumed = mk_lang_countof(tree_sp);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_rw_deserialize_pr_object_len(mk_lib_fast_import_tree_pt const tree, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(tree->m_fi);
	mk_lang_assert(tree->m_fi->m_mallocator);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	err = mk_lib_fast_import_any_rw_deserialize_pr_object_len(binary_data_buf, binary_data_len, success, consumed); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_rw_deserialize_pr_file_mode(mk_lib_fast_import_tree_pt const tree, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed, mk_lang_types_pchar_pt file_mode_buf, mk_lang_types_sint_pt const file_mode_len, mk_lib_fast_import_file_mode_pt const file_mode_num) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[mk_lib_fast_import_file_mode_strlen_dec_v + 1];
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t sp;
	mk_sl_cui_uint8_t tu8;

	mk_lang_assert(tree);
	mk_lang_assert(tree->m_fi);
	mk_lang_assert(tree->m_fi->m_mallocator);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(file_mode_buf);
	mk_lang_assert(file_mode_len);
	mk_lang_assert(*file_mode_len >= 1);
	mk_lang_assert(*file_mode_len <= mk_lib_fast_import_file_mode_strlen_dec_v + 1);
	mk_lang_assert(file_mode_num);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;
	if(gud)
	{
		gud = data_len >= 1;
	}
	if(gud)
	{
		str_len = mk_lang_limits_sint_max;
		str_len = mk_lang_min(str_len, data_len);
		str_len = mk_lang_min(str_len, mk_lang_countof(str_buf));
		str_len = mk_lang_min(str_len, *file_mode_len);
		mk_sl_cui_uint8_to_bi_pchar_many(data_buf, &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
		len = mk_lib_fast_import_file_mode_from_str_dec_n(file_mode_num, &str_buf[0], str_len); mk_lang_assert(len <= str_len);
		gud = str_len >= 1;
	}
	if(gud)
	{
		mk_lang_clobber(&len);
		mk_lang_string_memcpy_pc_fn(&file_mode_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(len)));
		*file_mode_len = len;
		data_buf += len;
		data_len -= len;
	}
	if(gud)
	{
		gud = data_len >= 1;
	}
	if(gud)
	{
		sp = ' '; mk_sl_cui_uint8_from_bi_pchar(&tu8, &sp);
		gud = mk_sl_cui_uint8_eq(&data_buf[0], &tu8);
	}
	if(gud)
	{
		data_buf += 1;
		data_len -= 1;
	}
	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_rw_deserialize_pr_file_name(mk_lib_fast_import_tree_pt const tree, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed, mk_lib_fast_import_string_pt const file_name) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_bool_t gud;
	mk_lang_types_pchar_t nul_pc;
	mk_sl_cui_uint8_t nul_u8;
	mk_lang_types_sint_t found;
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(tree->m_fi);
	mk_lang_assert(tree->m_fi->m_mallocator);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(file_name);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;
	if(gud)
	{
		gud = data_len >= 1;
	}
	if(gud)
	{
		nul_pc = '\0'; mk_sl_cui_uint8_from_bi_pchar(&nul_u8, &nul_pc);
		found = mk_generic_find_u8(data_buf, data_len, &nul_u8, 1); mk_lang_assert(found >= 0); mk_lang_assert(found == data_len || found <= data_len - 1);
		gud = found >= 1 && found != data_len;
	}
	if(gud)
	{
		mk_lang_clobber(&found);
		err = mk_lib_fast_import_string_rw_clear(file_name); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_string_rw_push_back_copy_many_u8(file_name, data_buf, ((mk_lang_types_usize_t)(found))); mk_lang_check_rereturn(err);
		data_buf += found;
		data_len -= found;
		mk_lang_assert(data_len >= 1 && mk_sl_cui_uint8_eq(&data_buf[0], &nul_u8));
		data_buf += 1;
		data_len -= 1;
	}
	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_rw_deserialize_pr_file_dgst(mk_lib_fast_import_tree_pt const tree, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed, mk_lib_crypto_hash_stream_sha1_digest_pt const file_digest) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_bool_t gud;

	mk_lang_assert(tree);
	mk_lang_assert(tree->m_fi);
	mk_lang_assert(tree->m_fi->m_mallocator);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(file_digest);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;
	if(gud)
	{
		gud = data_len >= mk_lang_countof(file_digest->m_data.m_uint8s);
	}
	if(gud)
	{
		mk_sl_cui_uint8_memcpy_fn(&file_digest->m_data.m_uint8s[0], data_buf, mk_lang_countof(file_digest->m_data.m_uint8s));
		data_buf += mk_lang_countof(file_digest->m_data.m_uint8s);
		data_len -= mk_lang_countof(file_digest->m_data.m_uint8s);
	}
	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_rw_deserialize_pr_append_child(mk_lib_fast_import_tree_pt const tree, mk_lib_fast_import_file_mode_pct const file_mode_num, mk_lib_fast_import_string_pct const file_name, mk_lib_crypto_hash_stream_sha1_digest_pct const file_digest) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_ulong_t tul;
	mk_lib_fast_import_tree_node_id_t type;
	mk_lang_types_pchar_pct name_buf;
	mk_lang_types_sint_t name_len;
	mk_lib_fast_import_tree_node_pt child;

	mk_lang_assert(tree);
	mk_lang_assert(tree->m_fi);
	mk_lang_assert(tree->m_fi->m_mallocator);
	mk_lang_assert(file_mode_num);
	mk_lang_assert(file_name);
	mk_lang_assert(file_digest);

	mk_lib_fast_import_file_mode_to_bi_ulong(file_mode_num, &tul);
	type = tul == 40000 ? mk_lib_fast_import_tree_node_id_e_tree : mk_lib_fast_import_tree_node_id_e_blob;
	name_buf = mk_lib_fast_import_string_ro_data(file_name); mk_lang_assert(name_buf); mk_lang_assert(name_buf[0] != '\0');
	name_len = mk_lib_fast_import_string_ro_sise(file_name); mk_lang_assert(name_len >= 1);

	err = mk_lib_fast_import_tree_nodes_rw_grow_by(&tree->m_children, 1); mk_lang_check_rereturn(err);
	child = mk_lib_fast_import_tree_nodes_rw_back(&tree->m_children); mk_lang_assert(child);
	err = mk_lib_fast_import_tree_node_rw_construct(child, tree->m_fi, type, tree, name_buf, name_len); mk_lang_check_rereturn(err);
	if(type == mk_lib_fast_import_tree_node_id_e_blob)
	{
		child->m_val.m_data.m_blob->m_digest = *file_digest;
		child->m_val.m_data.m_blob->m_mode_len = mk_lib_fast_import_file_mode_to_str_dec_n(file_mode_num, &child->m_val.m_data.m_blob->m_mode_buf[0], mk_lang_countof(child->m_val.m_data.m_blob->m_mode_buf) - 1); mk_lang_assert(child->m_val.m_data.m_blob->m_mode_len >= 1); mk_lang_assert(child->m_val.m_data.m_blob->m_mode_len <= mk_lang_countof(child->m_val.m_data.m_blob->m_mode_buf) - 1); child->m_val.m_data.m_blob->m_mode_buf[child->m_val.m_data.m_blob->m_mode_len] = '\0';
	}
	else
	{
		child->m_val.m_data.m_tree->m_digest_computed = mk_lang_true;
		child->m_val.m_data.m_tree->m_digest_value = *file_digest;
		child->m_val.m_data.m_tree->m_mode_len = mk_lib_fast_import_file_mode_to_str_dec_n(file_mode_num, &child->m_val.m_data.m_tree->m_mode_buf[0], mk_lang_countof(child->m_val.m_data.m_tree->m_mode_buf) - 1); mk_lang_assert(child->m_val.m_data.m_tree->m_mode_len >= 1); mk_lang_assert(child->m_val.m_data.m_tree->m_mode_len <= mk_lang_countof(child->m_val.m_data.m_tree->m_mode_buf) - 1); child->m_val.m_data.m_tree->m_mode_buf[child->m_val.m_data.m_tree->m_mode_len] = '\0';
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_rw_deserialize_pr_child(mk_lib_fast_import_tree_pt const tree, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t file_mode_len;
	mk_lang_types_pchar_t file_mode_buf[mk_lib_fast_import_file_mode_strlen_dec_v + 1];
	mk_lang_types_sint_t err;
	mk_lib_fast_import_string_t file_name;
	mk_lang_types_sint_t used;
	mk_lib_fast_import_file_mode_t file_mode_num;
	mk_lib_crypto_hash_stream_sha1_digest_t file_digest;

	mk_lang_assert(tree);
	mk_lang_assert(tree->m_fi);
	mk_lang_assert(tree->m_fi->m_mallocator);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	gud = mk_lang_true;

	file_mode_len = mk_lang_countof(file_mode_buf);
	err = mk_lib_fast_import_string_rw_construct(&file_name, tree->m_fi->m_mallocator); mk_lang_check_rereturn(err);

	if(gud){ err = mk_lib_fast_import_tree_rw_deserialize_pr_file_mode(tree, data_buf, data_len, &gud, &used, &file_mode_buf[0], &file_mode_len, &file_mode_num); mk_lang_check_rereturn(err); mk_lang_assert(used >= 0); mk_lang_assert(used <= data_len); data_buf += used; data_len -= used; }
	if(gud){ err = mk_lib_fast_import_tree_rw_deserialize_pr_file_name(tree, data_buf, data_len, &gud, &used, &file_name                                       ); mk_lang_check_rereturn(err); mk_lang_assert(used >= 0); mk_lang_assert(used <= data_len); data_buf += used; data_len -= used; }
	if(gud){ err = mk_lib_fast_import_tree_rw_deserialize_pr_file_dgst(tree, data_buf, data_len, &gud, &used, &file_digest                                     ); mk_lang_check_rereturn(err); mk_lang_assert(used >= 0); mk_lang_assert(used <= data_len); data_buf += used; data_len -= used; }

	if(gud){ err = mk_lib_fast_import_tree_rw_deserialize_pr_append_child(tree, &file_mode_num, &file_name, &file_digest); mk_lang_check_rereturn(err); }
	err = mk_lib_fast_import_string_rw_destroy(&file_name); mk_lang_check_rereturn(err);

	*success = gud;
	*consumed = binary_data_len - data_len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_rw_deserialize_from_buf_and_len(mk_lib_fast_import_tree_pt const tree, mk_sl_cui_uint8_pct const binary_data_buf, mk_lang_types_sint_t const binary_data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(tree);
	mk_lang_assert(tree->m_fi);
	mk_lang_assert(binary_data_buf);
	mk_lang_assert(binary_data_len >= 1);
	mk_lang_assert(did);

	data_buf = binary_data_buf;
	data_len = binary_data_len;
	err = mk_lib_fast_import_tree_rw_clear(tree); mk_lang_check_rereturn(err);
	gud = mk_lang_true;
	if(gud){ err = mk_lib_fast_import_tree_rw_deserialize_pr_object_type(tree, data_buf, data_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(consumed >= 0); mk_lang_assert(consumed <= data_len); data_buf += consumed; data_len -= consumed; }
	if(gud){ err = mk_lib_fast_import_tree_rw_deserialize_pr_object_len (tree, data_buf, data_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(consumed >= 0); mk_lang_assert(consumed <= data_len); data_buf += consumed; data_len -= consumed; }
	if(gud)
	{
		while(data_len != 0)
		{
			if(gud){ err = mk_lib_fast_import_tree_rw_deserialize_pr_child(tree, data_buf, data_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(consumed >= 0); mk_lang_assert(consumed <= data_len); data_buf += consumed; data_len -= consumed; }
		}
	}
	*did = gud;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_rw_deserialize_from_binary_data(mk_lib_fast_import_tree_pt const tree, mk_lib_fast_import_binary_data_pct const binary_data, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct binary_data_buf;
	mk_lang_types_sint_t binary_data_len;
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(tree->m_fi);
	mk_lang_assert(binary_data);
	mk_lang_assert(did);

	binary_data_buf = mk_lib_fast_import_binary_data_ro_data(binary_data);
	binary_data_len = mk_lib_fast_import_binary_data_ro_sise(binary_data);
	err = mk_lib_fast_import_tree_rw_deserialize_from_buf_and_len(tree, binary_data_buf, binary_data_len, did); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_reset_rw_construct(mk_lib_fast_import_reset_pt const reset, mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(reset);
	mk_lang_assert(fi);

	reset->m_fi = fi;
	err = mk_lib_fast_import_string_rw_construct(&reset->m_ref, fi->m_mallocator); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_reset_rw_destroy(mk_lib_fast_import_reset_pt const reset) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(reset);

	err = mk_lib_fast_import_string_rw_destroy(&reset->m_ref); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_fi_pr_construct(mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_assert(fi);

	fi->m_mallocator = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_fi_pr_destroy(mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);

	err = mk_sl_io_reader_file_close(&fi->m_buffered_reader.m_reader); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_tree_by_mark_rw_destruct(&fi->m_marks); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_map_mark_to_commit_rw_destruct(&fi->m_commits); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_fi_pr_set_mallocator(mk_lib_fast_import_pt const fi, mk_lib_fast_import_mallocator_lokal_pt const mallocator) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(mallocator);
	mk_lang_assert(!fi->m_mallocator);

	fi->m_mallocator = mallocator;
	err = mk_lib_fast_import_string_rw_construct(&fi->m_output_dir, fi->m_mallocator); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_fi_pr_set_input_file(mk_lib_fast_import_pt const fi, mk_lang_types_pchar_pct const file_path) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(file_path);
	mk_lang_assert(file_path[0] != '\0');

	err = mk_lib_fast_import_tree_by_mark_rw_construct(&fi->m_marks, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_map_mark_to_commit_rw_construct(&fi->m_commits, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_sl_io_reader_file_open_n(&fi->m_buffered_reader.m_reader, file_path); mk_lang_check_rereturn(err);
	err = mk_sl_io_reader_file_read(&fi->m_buffered_reader.m_reader, &fi->m_buffered_reader.m_data_buf[0], mk_lang_countof(fi->m_buffered_reader.m_data_buf), &fi->m_buffered_reader.m_data_len); mk_lang_check_rereturn(err);
	fi->m_buf = &fi->m_buffered_reader.m_data_buf[0];
	fi->m_len = fi->m_buffered_reader.m_data_len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_fi_pr_set_output_dir(mk_lib_fast_import_pt const fi, mk_lang_types_pchar_pct const dir_path) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));
	mk_lang_assert(dir_path);
	mk_lang_assert(dir_path[0] != '\0');

	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, dir_path, ((mk_lang_types_usize_t)(mk_lang_str_len_n(dir_path)))); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_save_blob_to_database_4(mk_sl_io_writer_file_pt const writer, mk_lib_compress_zlib_pt const zlib) mk_lang_noexcept
{
	mk_lang_types_sint_t out_len;
	mk_sl_cui_uint8_t out_buf[4 * 1024];
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t out_c;
	mk_lang_types_sint_t w;

	mk_lang_assert(writer);
	mk_lang_assert(zlib);

	do
	{
		out_len = mk_lang_countof(out_buf);
		mk_lib_compress_zlib_finish(zlib, &out_buf[0], out_len, &out_c);
		err = mk_sl_io_writer_file_write(writer, &out_buf[0], out_c, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == out_c);
	}while(out_c != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_save_blob_to_database_3(mk_sl_io_writer_file_pt const writer, mk_lib_compress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf;
	mk_lang_types_sint_t in_len;
	mk_lang_types_sint_t out_len;
	mk_sl_cui_uint8_t out_buf[4 * 1024];
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t in_c;
	mk_lang_types_sint_t out_c;
	mk_lang_types_sint_t w;

	mk_lang_assert(writer);
	mk_lang_assert(zlib);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	in_buf = data_buf;
	in_len = data_len;
	while(in_len != 0)
	{
		out_len = mk_lang_countof(out_buf);
		mk_lib_compress_zlib_append(zlib, in_buf, in_len, &out_buf[0], out_len, &in_c, &out_c);
		err = mk_sl_io_writer_file_write(writer, &out_buf[0], out_c, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == out_c);
		in_buf += in_c;
		in_len -= in_c;
	}

	/*err = mk_sl_io_writer_file_write(writer, &prefix[0], mk_lang_countof(prefix), &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == mk_lang_countof(prefix));
	err = mk_sl_io_writer_file_write(writer, &str_u8[0], in_len, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == in_len);
	err = mk_sl_io_writer_file_write(writer, &zero, 1, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == 1);
	err = mk_sl_io_writer_file_write(writer, blob->m_binary_buf, blob->m_binary_len, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == blob->m_binary_len);*/
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_save_blob_to_database_2(mk_lib_fast_import_pt const fi, mk_sl_io_writer_file_pt const writer, mk_lib_fast_import_blob_pct const blob) mk_lang_noexcept
{
	mk_sl_cui_uint8_t prefix[mk_lang_countstr(mk_lib_fast_import_k_blobsp)];
	mk_lang_bui_uint_t bui;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t str_pc[mk_lang_bui_uint_strlen_dec_v];
	mk_sl_cui_uint8_t str_u8[mk_lang_bui_uint_strlen_dec_v];
	mk_sl_cui_uint8_t zero;
	mk_lang_types_sint_t err;
	mk_lib_compress_zlib_t zlib;

	mk_lang_assert(fi);
	mk_lang_assert(writer);
	mk_lang_assert(blob);
	mk_lang_assert(blob->m_binary_buf || blob->m_binary_len == 0);
	mk_lang_assert(blob->m_binary_len >= 0);

	((mk_lang_types_void_t)(fi));
	mk_sl_cui_uint8_from_bi_pchar_many(&prefix[0], &mk_lib_fast_import_k_blobsp[0], mk_lang_countof(prefix));
	bui = ((mk_lang_bui_uint_t)(blob->m_binary_len));
	len = mk_lang_bui_uint_to_str_dec_n(&bui, &str_pc[0], mk_lang_bui_uint_strlen_dec_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&str_u8[0], &str_pc[0], mk_lang_bui_uint_strlen_dec_v);
	mk_sl_cui_uint8_set_zero(&zero);
	mk_lib_compress_zlib_init(&zlib);
	err = mk_lib_fast_import_pr_save_blob_to_database_3(writer, &zlib, &prefix[0], mk_lang_countof(prefix)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_save_blob_to_database_3(writer, &zlib, &str_u8[0], len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_save_blob_to_database_3(writer, &zlib, &zero, 1); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_save_blob_to_database_3(writer, &zlib, blob->m_binary_buf, blob->m_binary_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_save_blob_to_database_4(writer, &zlib); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_save_blob_to_database(mk_lib_fast_import_pt const fi, mk_lib_fast_import_blob_pct const blob) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_lang_types_pchar_t str[((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_sha1_digest_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))];
	mk_lang_types_usize_t old_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_sl_io_writer_file_t writer;
	mk_win_base_bool_t b; /* todo */
	mk_win_base_dword_t gle; /* todo */

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));
	mk_lang_assert(blob);

	old_len = mk_lib_fast_import_string_ro_size(&fi->m_output_dir);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_dot_git[0], mk_lang_countstr(mk_lib_fast_import_k_dot_git)); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_objects[0], mk_lang_countstr(mk_lib_fast_import_k_objects)); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_n(&blob->m_digest.m_data.m_uint8s[0], &str[0], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str[0], mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	tpc = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	b = mk_win_dll_kernel_files_a_create_directory(mk_lib_fast_import_string_ro_data(&fi->m_output_dir), mk_win_base_null); mk_lang_check_return(b != 0 || (gle = mk_win_dll_kernel_errors_get_last()) == mk_win_dll_kernel_errors_id_e_already_exists); /* todo */
	err = mk_lib_fast_import_string_rw_pop_back_single(&fi->m_output_dir); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_many_n(&blob->m_digest.m_data.m_uint8s[1], mk_lib_crypto_hash_stream_sha1_digest_len_v - 1, &str[0], mk_lang_countof(str)); mk_lang_assert(len == (mk_lib_crypto_hash_stream_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str[0], (mk_lib_crypto_hash_stream_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	tpc = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_open_n(&writer, mk_lib_fast_import_string_ro_data(&fi->m_output_dir)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_save_blob_to_database_2(fi, &writer, blob); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_resize_to(&fi->m_output_dir, old_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_compute_tree_len(mk_lib_fast_import_pt const fi, mk_lib_fast_import_file_ops_pct const tree, mk_lang_types_sint_pt const len) mk_lang_noexcept
{
	mk_lang_types_sint_t acc;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fast_import_file_op_pct file;
	mk_lang_types_sint_t slen;
	mk_lang_types_pchar_t str[mk_sl_cui_uint32_strlen_dec_v];

	mk_lang_assert(fi);
	mk_lang_assert(tree);
	mk_lang_assert(len);

	((mk_lang_types_void_t)(fi));
	acc = 0;
	n = mk_lib_fast_import_file_ops_ro_size(tree);
	for(i = 0; i != n; ++i)
	{
		file = mk_lib_fast_import_file_ops_ro_at(tree, i); mk_lang_assert(file);
		slen = mk_sl_cui_uint32_to_str_dec_n(&file->m_file_modify.m_mode, &str[0], mk_lang_countof(str)); acc += slen;
		acc += 1; /* sp */
		acc += ((mk_lang_types_sint_t)(mk_lib_fast_import_string_ro_size(&file->m_file_modify.m_path)));
		acc += 1; /* nul */
		acc += mk_lib_crypto_hash_stream_sha1_digest_len_v; /* digest */
	}
	*len = acc;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_u8s(mk_lib_fast_import_pt const fi, mk_lib_compress_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf;
	mk_lang_types_sint_t in_len;
	mk_sl_cui_uint8_pt out_buf;
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t out_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t in_c;
	mk_lang_types_sint_t out_c;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);

	in_buf = buf;
	in_len = len;
	out_buf = &u8s[0];
	out_len = mk_lang_countof(u8s);
	do
	{
		mk_lib_compress_zlib_append(zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c);
		err = mk_lib_fast_import_binary_data_rw_push_back_copy_many(bytes, out_buf, ((mk_lang_types_usize_t)(out_c))); mk_lang_check_rereturn(err);
		in_buf += in_c;
		in_len -= in_c;
	}while(in_len != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_pchars(mk_lib_fast_import_pt const fi, mk_lib_compress_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lang_types_pchar_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);

	if(len > mk_lang_countof(u8s))
	{
		mk_lang_check_todo();
	}
	mk_sl_cui_uint8_from_bi_pchar_many(&u8s[0], buf, ((mk_lang_types_usize_t)(len)));
	err = mk_lib_fast_import_pr_tree_append_u8s(fi, zlib, bytes, &u8s[0], len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_finish(mk_lib_fast_import_pt const fi, mk_lib_compress_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt out_buf;
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t out_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t out_c;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);

	out_buf = &u8s[0];
	out_len = mk_lang_countof(u8s);
	do
	{
		mk_lib_compress_zlib_finish(zlib, out_buf, out_len, &out_c);
		err = mk_lib_fast_import_binary_data_rw_push_back_copy_many(bytes, out_buf, ((mk_lang_types_usize_t)(out_c))); mk_lang_check_rereturn(err);
	}while(out_c != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_file_op_mode(mk_lib_fast_import_pt const fi, mk_lib_compress_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_sint_t slen;
	mk_lang_types_pchar_t str[mk_sl_cui_uint32_strlen_dec_v];
	mk_sl_cui_uint8_t u8s[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(file_op);

	slen = mk_sl_cui_uint32_to_str_dec_n(&file_op->m_file_modify.m_mode, &str[0], mk_lang_countof(str)); mk_lang_assert(slen >= 1); mk_lang_assert(slen <= mk_lang_countof(str));
	mk_sl_cui_uint8_from_bi_pchar_many(&u8s[0], &str[0], ((mk_lang_types_usize_t)(slen)));
	err = mk_lib_fast_import_pr_tree_append_u8s(fi, zlib, bytes, &u8s[0], slen); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_file_op_sp(mk_lib_fast_import_pt const fi, mk_lib_compress_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_sl_cui_uint8_t u8s;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(file_op);

	tpc = ' ';
	mk_sl_cui_uint8_from_bi_pchar_many(&u8s, &tpc, 1);
	err = mk_lib_fast_import_pr_tree_append_u8s(fi, zlib, bytes, &u8s, 1); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_file_op_nul(mk_lib_fast_import_pt const fi, mk_lib_compress_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_sl_cui_uint8_t u8s;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(file_op);

	tpc = '\0';
	mk_sl_cui_uint8_from_bi_pchar_many(&u8s, &tpc, 1);
	err = mk_lib_fast_import_pr_tree_append_u8s(fi, zlib, bytes, &u8s, 1); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_file_op_name(mk_lib_fast_import_pt const fi, mk_lib_compress_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_usize_t u_file_name;
	mk_lang_types_sint_t i_file_name;
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(file_op);

	u_file_name = mk_lib_fast_import_string_ro_size(&file_op->m_file_modify.m_path);
	i_file_name = ((mk_lang_types_sint_t)(u_file_name));
	if(i_file_name > mk_lang_countof(u8s))
	{
		mk_lang_check_todo();
	}
	mk_sl_cui_uint8_from_bi_pchar_many(&u8s[0], mk_lib_fast_import_string_ro_data(&file_op->m_file_modify.m_path), u_file_name);
	err = mk_lib_fast_import_pr_tree_append_u8s(fi, zlib, bytes, &u8s[0], i_file_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_add_to_refs_commit(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_commit_pct const commit) mk_lang_noexcept
{
	mk_lib_fast_import_mark_to_commit_t element;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_map_mark_to_commit_node_pt node;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(commit);
	mk_lang_assert(commit->m_has_mark);

	element.m_mark = commit->m_mark;
	element.m_digest = commit->m_digest;
	err = mk_lib_fast_import_map_mark_to_commit_rw_insert_element_move(&fi->m_commits, &element, &node); mk_lang_check_rereturn(err); mk_lang_check_return(node);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_file_op_digest(mk_lib_fast_import_pt const fi, mk_lib_compress_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_crypto_hash_stream_sha1_digest_pct digest;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(file_op);

	err = mk_lib_fast_import_pr_file_find_digest(fi, &file_op->m_file_modify.m_data_ref, &digest); mk_lang_check_rereturn(err); mk_lang_check_return(digest);
	err = mk_lib_fast_import_pr_tree_append_u8s(fi, zlib, bytes, &digest->m_data.m_uint8s[0], mk_lang_countof(digest->m_data.m_uint8s)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_file_op(mk_lib_fast_import_pt const fi, mk_lib_compress_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(file_op);

	err = mk_lib_fast_import_pr_tree_append_file_op_mode(fi, zlib, bytes, file_op); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_file_op_sp(fi, zlib, bytes, file_op); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_file_op_name(fi, zlib, bytes, file_op); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_file_op_nul(fi, zlib, bytes, file_op); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_file_op_digest(fi, zlib, bytes, file_op); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_compute_tree_bytes(mk_lib_fast_import_pt const fi, mk_lib_fast_import_file_ops_pct const tree, mk_lib_fast_import_binary_data_pt const bytes) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_types_uint_t ulen;
	mk_lang_types_sint_t slen;
	mk_lang_types_pchar_t str[mk_lang_bui_uint_strlen_dec_v];
	mk_lang_types_sint_t size;
	mk_lang_types_pchar_t nul;
	mk_lib_compress_zlib_t zlib;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fast_import_file_op_pct file_op;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));
	mk_lang_assert(tree);

	err = mk_lib_fast_import_binary_data_rw_clear(bytes); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_compute_tree_len(fi, tree, &len); mk_lang_check_rereturn(err); mk_lang_assert(len >= 1);
	ulen = ((mk_lang_types_uint_t)(len));
	slen = mk_lang_bui_uint_to_str_dec_n(&ulen, &str[0], mk_lang_countof(str)); mk_lang_assert(slen >= 1); mk_lang_assert(slen <= mk_lang_countof(str));
	nul = '\0';
	size = 0;
	size += 2; /* zlib header */
	size += 5; /* deflate block header */
	size += mk_lang_countstr(mk_lib_fast_import_k_tree_sp);
	size += slen;
	size += 1; /* nul */
	size += ulen;
	size += 4; /* zlib footer */
	err = mk_lib_fast_import_binary_data_rw_reserve_at_least(bytes, ((mk_lang_types_usize_t)(size))); mk_lang_check_rereturn(err);
	mk_lib_compress_zlib_init(&zlib);
	err = mk_lib_fast_import_pr_tree_append_pchars(fi, &zlib, bytes, &mk_lib_fast_import_k_tree_sp[0], mk_lang_countstr(mk_lib_fast_import_k_tree_sp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_pchars(fi, &zlib, bytes, &str[0], slen); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_pchars(fi, &zlib, bytes, &nul, 1); mk_lang_check_rereturn(err);
	n = mk_lib_fast_import_file_ops_ro_size(tree);
	for(i = 0; i != n; ++i)
	{
		file_op = mk_lib_fast_import_file_ops_ro_at(tree, i); mk_lang_assert(file_op);
		err = mk_lib_fast_import_pr_tree_append_file_op(fi, &zlib, bytes, file_op); mk_lang_check_rereturn(err);
	}
	err = mk_lib_fast_import_pr_tree_finish(fi, &zlib, bytes); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_free_binary_data(mk_lib_fast_import_blob_pt const blob) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(blob);

	err = mk_lib_fast_import_mallocator_lokal_deallocate(blob->m_fi->m_mallocator, blob->m_binary_buf, ((mk_lang_types_usize_t)(blob->m_binary_len))); mk_lang_check_rereturn(err);
	blob->m_binary_buf = mk_lang_null;
	blob->m_binary_len = 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_string(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(str_buf);
	mk_lang_assert(str_len >= 1);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_false;
	if(l >= str_len)
	{
		b = mk_sl_cui_uint8_eq_pchar_many(&d[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	}
	if(b)
	{
		d += str_len;
		l -= str_len;
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_number(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_mark_pt const number) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t n;
	mk_lang_types_pchar_t str[mk_lib_fast_import_mark_strlen_dec_v];
	mk_lang_types_sint_t len;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);
	mk_lang_assert(number);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_false;
	n = mk_lang_min(l, mk_lang_countof(str));
	if(n >= 1)
	{
		mk_sl_cui_uint8_to_bi_pchar_many(&d[0], &str[0], ((mk_lang_types_usize_t)(n)));
		len = mk_lib_fast_import_mark_from_str_dec_n(number, &str[0], n); mk_lang_assert(len <= n);
		if(len >= 1)
		{
			d += len;
			l -= len;
			b = mk_lang_true;
		}
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_u32(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_sl_cui_uint32_pt const u32) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t n;
	mk_lang_types_pchar_t str[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_sint_t len;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);
	mk_lang_assert(u32);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_false;
	n = mk_lang_min(l, mk_lang_countof(str));
	if(n != 0)
	{
		mk_sl_cui_uint8_to_bi_pchar_many(&d[0], &str[0], ((mk_lang_types_usize_t)(n)));
		len = mk_sl_cui_uint32_from_str_dec_n(u32, &str[0], n); mk_lang_assert(len <= n);
		if(len >= 1)
		{
			d += len;
			l -= len;
			b = mk_lang_true;
		}
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_data_ref(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_mark_pt const u128) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t n;
	mk_lang_types_pchar_t str[mk_lib_fast_import_mark_strlen_dec_v];
	mk_lang_types_sint_t len;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);
	mk_lang_assert(u128);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_false;
	n = mk_lang_min(l, mk_lang_countof(str));
	if(n != 0)
	{
		mk_sl_cui_uint8_to_bi_pchar_many(&d[0], &str[0], ((mk_lang_types_usize_t)(n)));
		len = mk_lib_fast_import_mark_from_str_dec_n(u128, &str[0], n); mk_lang_assert(len <= n);
		if(len >= 1)
		{
			d += len;
			l -= len;
			b = mk_lang_true;
		}
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_string_splt(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_string_pt const string) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct str_buf;
	mk_lang_types_sint_t str_len;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(string);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	n = l - mk_lang_countstr(mk_lib_fast_import_k_splt);
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_uint8_eq_pchar_many(&d[i], &mk_lib_fast_import_k_splt[0], mk_lang_countstr(mk_lib_fast_import_k_splt)))
		{
			break;
		}
	}
	b = i != n;
	if(b)
	{
		str_buf = ((mk_lang_types_pchar_pct)(&d[0]));
		str_len = i;
		err = mk_lib_fast_import_string_rw_clear(string); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_string_rw_push_back_copy_many(string, str_buf, ((mk_lang_types_usize_t)(str_len))); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_st_fancy_str(string); mk_lang_check_rereturn(err);
		d += str_len + mk_lang_countstr(mk_lib_fast_import_k_splt);
		l -= str_len + mk_lang_countstr(mk_lib_fast_import_k_splt);
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_string_gtsp(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_string_pt const string) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct str_buf;
	mk_lang_types_sint_t str_len;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(string);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	n = l - mk_lang_countstr(mk_lib_fast_import_k_gtsp);
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_uint8_eq_pchar_many(&d[i], &mk_lib_fast_import_k_gtsp[0], mk_lang_countstr(mk_lib_fast_import_k_gtsp)))
		{
			break;
		}
	}
	b = i != n;
	if(b)
	{
		str_buf = ((mk_lang_types_pchar_pct)(&d[0]));
		str_len = i;
		err = mk_lib_fast_import_string_rw_clear(string); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_string_rw_push_back_copy_many(string, str_buf, ((mk_lang_types_usize_t)(str_len))); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_st_fancy_str(string); mk_lang_check_rereturn(err);
		d += str_len + mk_lang_countstr(mk_lib_fast_import_k_gtsp);
		l -= str_len + mk_lang_countstr(mk_lib_fast_import_k_gtsp);
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_string_lf(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_string_pt const string) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct str_buf;
	mk_lang_types_sint_t str_len;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(string);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	n = l - mk_lang_countstr(mk_lib_fast_import_k_lf);
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_uint8_eq_pchar_many(&d[i], &mk_lib_fast_import_k_lf[0], mk_lang_countstr(mk_lib_fast_import_k_lf)))
		{
			break;
		}
	}
	b = i != n;
	if(b)
	{
		str_buf = ((mk_lang_types_pchar_pct)(&d[0]));
		str_len = i;
		err = mk_lib_fast_import_string_rw_clear(string); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_string_rw_push_back_copy_many(string, str_buf, ((mk_lang_types_usize_t)(str_len))); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_st_fancy_str(string); mk_lang_check_rereturn(err);
		d += str_len + mk_lang_countstr(mk_lib_fast_import_k_lf);
		l -= str_len + mk_lang_countstr(mk_lib_fast_import_k_lf);
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_binary_suffix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_lf[0], mk_lang_countstr(mk_lib_fast_import_k_lf), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_data_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_data[0], mk_lang_countstr(mk_lib_fast_import_k_data), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_data_suffix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_lf[0], mk_lang_countstr(mk_lib_fast_import_k_lf), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_data_whole(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lang_types_sint_pt const binary_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_mark_t number;
	mk_lang_types_sint_t tsi;
	mk_lib_fast_import_mark_t cui;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);
	mk_lang_assert(binary_len);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_data_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_number(&d, &l, &b, &number); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_data_suffix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b)
	{
		tsi = mk_lang_limits_sint_max; mk_lib_fast_import_mark_from_bi_sint(&cui, &tsi);
		mk_lang_check_return(mk_lib_fast_import_mark_le(&number, &cui));
		mk_lib_fast_import_mark_to_bi_sint(&number, binary_len);
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_mark_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_mark_sp_colon[0], mk_lang_countstr(mk_lib_fast_import_k_mark_sp_colon), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_from_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_from_sp_colon[0], mk_lang_countstr(mk_lib_fast_import_k_from_sp_colon), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_author_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_author_sp[0], mk_lang_countstr(mk_lib_fast_import_k_author_sp), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_committer_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_committer_sp[0], mk_lang_countstr(mk_lib_fast_import_k_committer_sp), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_mark_suffix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_lf[0], mk_lang_countstr(mk_lib_fast_import_k_lf), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_from_suffix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_lf[0], mk_lang_countstr(mk_lib_fast_import_k_lf), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_mark_whole(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_mark_pt const mark) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);
	mk_lang_assert(mark);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_mark_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_number(&d, &l, &b, mark); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_mark_suffix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_blob_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_blob[0], mk_lang_countstr(mk_lib_fast_import_k_blob), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_commit_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_commitsp[0], mk_lang_countstr(mk_lib_fast_import_k_commitsp), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_reset_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_resetsp[0], mk_lang_countstr(mk_lib_fast_import_k_resetsp), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_from_opt(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lang_types_bool_pt const has, mk_lib_fast_import_mark_pt const mark_ref) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(has);
	mk_lang_assert(mark_ref);

	d = fi->m_buf;
	l = fi->m_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_from_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_data_ref(&d, &l, &b, mark_ref); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_from_suffix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b)
	{
		fi->m_buf = d;
		fi->m_len = l;
	}
	*has = b;
	*did = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_blob_whole(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_blob_pt const blob) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);
	mk_lang_assert(blob);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_blob_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_mark_whole(&d, &l, &b, &blob->m_mark); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_data_whole(&d, &l, &b, &blob->m_binary_len); mk_lang_check_rereturn(err); }
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_ref_lf(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_string_pt const ref) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_sl_cui_uint8_t cui;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct str_buf;
	mk_lang_types_sint_t str_len;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(ref);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	mk_sl_cui_uint8_from_bi_pchar(&cui, &mk_lib_fast_import_k_lf[0]);
	n = l;
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_uint8_eq(&d[i], &cui))
		{
			break;
		}
	}
	b = i != n;
	if(b)
	{
		str_buf = ((mk_lang_types_pchar_pct)(&d[0]));
		str_len = i;
		err = mk_lib_fast_import_string_rw_clear(ref); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_string_rw_push_back_copy_many(ref, str_buf, ((mk_lang_types_usize_t)(str_len))); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_st_fancy_str(ref); mk_lang_check_rereturn(err);
		d += str_len + 1;
		l -= str_len + 1;
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_mark_opt(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lang_types_bool_pt const mark_has, mk_lib_fast_import_mark_pt const mark_val) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_bool_t b_old;
	mk_lang_types_sint_t err;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(mark_has);
	mk_lang_assert(mark_val);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_mark_prefix(&d, &l, &b); mk_lang_check_rereturn(err);
	b_old = b;
	b = mk_lang_true;
	if(b_old)
	{
		err = mk_lib_fast_import_st_do_number(&d, &l, &b, mark_val); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_st_do_mark_suffix(&d, &l, &b); mk_lang_check_rereturn(err);
		*mark_has = b;
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_from_mark(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_mark_pt const mark) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(mark);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_from_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_number(&d, &l, &b, mark); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_from_suffix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_author(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_string_pt const name, mk_lib_fast_import_string_pt const email, mk_lib_fast_import_string_pt const timestamp) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(name);
	mk_lang_assert(email);
	mk_lang_assert(timestamp);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_author_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_splt(&d, &l, &b, name); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_gtsp(&d, &l, &b, email); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_lf(&d, &l, &b, timestamp); mk_lang_check_rereturn(err); }
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_committer(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_string_pt const name, mk_lib_fast_import_string_pt const email, mk_lib_fast_import_string_pt const timestamp) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(name);
	mk_lang_assert(email);
	mk_lang_assert(timestamp);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_committer_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_splt(&d, &l, &b, name); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_gtsp(&d, &l, &b, email); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_lf(&d, &l, &b, timestamp); mk_lang_check_rereturn(err); }
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_reread(mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);

	if(fi->m_len <= mk_lib_fast_import_k_buf_len)
	{
		if(fi->m_len != 0)
		{
			mk_sl_cui_uint8_memmov_fn(&fi->m_buffered_reader.m_data_buf[0], fi->m_buf, ((mk_lang_types_usize_t)(fi->m_len)));
		}
		rem = mk_lang_countof(fi->m_buffered_reader.m_data_buf) - fi->m_len;
		err = mk_sl_io_reader_file_read(&fi->m_buffered_reader.m_reader, &fi->m_buffered_reader.m_data_buf[fi->m_len], rem, &fi->m_buffered_reader.m_data_len); mk_lang_check_rereturn(err);
		fi->m_buf = &fi->m_buffered_reader.m_data_buf[0];
		fi->m_len = fi->m_len + fi->m_buffered_reader.m_data_len;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_binary_data_2(mk_lib_fast_import_pt const fi, mk_lang_types_sint_t const binary_len, mk_lib_fast_import_binary_data_pt const binary_data) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pt bin_buf;
	mk_lang_types_sint_t bin_len;
	mk_lang_types_sint_t to_copy;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(binary_len >= 0);
	mk_lang_assert(binary_data);

	err = mk_lib_fast_import_binary_data_rw_clear(binary_data); mk_lang_check_rereturn(err);
	if(binary_len != 0)
	{
		err = mk_lib_fast_import_binary_data_rw_reserve_at_least(binary_data, ((mk_lang_types_usize_t)(binary_len))); mk_lang_check_rereturn(err);
		bin_buf = mk_lib_fast_import_binary_data_rw_data(binary_data); mk_lang_assert(bin_buf);
		bin_len = binary_len;
		do
		{
			to_copy = mk_lang_min(bin_len, fi->m_len);
			mk_sl_cui_uint8_memcpy_fn(bin_buf, fi->m_buf, ((mk_lang_types_usize_t)(to_copy)));
			fi->m_buf += to_copy;
			fi->m_len -= to_copy;
			bin_buf += to_copy;
			bin_len -= to_copy;
			err = mk_lib_fast_import_pr_reread(fi); mk_lang_check_rereturn(err);
		}while(bin_len != 0);
		err = mk_lib_fast_import_binary_data_rw_resize_to(binary_data, ((mk_lang_types_usize_t)(binary_len))); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_st_fancy_bin(binary_data); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_data_with_binary_data(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_binary_data_pt const binary_data) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t binary_len;
	mk_lang_types_sint_t err;

	b = mk_lang_true;
	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(did);
	mk_lang_assert(binary_data);

	d = fi->m_buf;
	l = fi->m_len;
	b = mk_lang_true;
	mk_lang_clobber(&binary_len);
	if(b){ err = mk_lib_fast_import_st_do_data_whole(&d, &l, &b, &binary_len); mk_lang_check_rereturn(err); mk_lang_assert(binary_len >= 0); }
	if(b){ fi->m_buf = d; fi->m_len = l; }
	if(b){ err = mk_lib_fast_import_pr_do_binary_data_2(fi, binary_len, binary_data); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_binary_suffix(&fi->m_buf, &fi->m_len, &b); mk_lang_check_rereturn(err); }
	*did = b;
	return 0;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_file_op_modify(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_file_modify_pt const file_op_modify) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(file_op_modify);

	err = mk_lib_fast_import_pr_reread(fi); mk_lang_check_rereturn(err);
	d = fi->m_buf;
	l = fi->m_len;
	b = mk_lang_true;
	file_op_modify->m_fi = fi;
	err = mk_lib_fast_import_string_rw_construct(&file_op_modify->m_path, fi->m_mallocator); mk_lang_check_rereturn(err);
	if(b){ err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_msp[0], mk_lang_countstr(mk_lib_fast_import_k_msp), &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_u32(&d, &l, &b, &file_op_modify->m_mode); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_sp[0], mk_lang_countstr(mk_lib_fast_import_k_sp), &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_colon[0], mk_lang_countstr(mk_lib_fast_import_k_colon), &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_data_ref(&d, &l, &b, &file_op_modify->m_data_ref); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_sp[0], mk_lang_countstr(mk_lib_fast_import_k_sp), &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_lf(&d, &l, &b, &file_op_modify->m_path); mk_lang_check_rereturn(err); }
	if(!b)
	{
		err = mk_lib_fast_import_string_rw_destroy(&file_op_modify->m_path); mk_lang_check_rereturn(err);
	}
	if(b)
	{
		fi->m_buf = d;
		fi->m_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_file_op(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_file_op_pt const file_op) mk_lang_noexcept
{
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(file_op);

	b = mk_lang_false;
	file_op->m_fi = fi;
	if(!b){ err = mk_lib_fast_import_pr_do_file_op_modify(fi, &b, &file_op->m_file_modify); mk_lang_check_rereturn(err); }
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_file_ops(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_file_ops_pt const file_ops) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;
	mk_lib_fast_import_file_op_t op;
	mk_lib_fast_import_file_op_pt file_op;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(file_ops);

	err = mk_lib_fast_import_file_ops_rw_clear(file_ops); mk_lang_check_rereturn(err);
	b = mk_lang_true;
	while(b)
	{
		err = mk_lib_fast_import_file_op_rw_construct(&op, fi); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_file_ops_rw_push_back_move_single(file_ops, &op); mk_lang_check_rereturn(err);
		file_op = mk_lib_fast_import_file_ops_rw_back(file_ops); mk_lang_assert(file_op);
		err = mk_lib_fast_import_pr_do_file_op(fi, &b, file_op); mk_lang_check_rereturn(err);
		if(!b)
		{
			err = mk_lib_fast_import_file_ops_rw_shrink_by(file_ops, 1); mk_lang_check_rereturn(err);
		}
	}
	*did = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_commit_whole(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_commit_pt const commit) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(commit);

	d = fi->m_buf;
	l = fi->m_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_commit_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_ref_lf(&d, &l, &b, &commit->m_ref); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_mark_opt(&d, &l, &b, &commit->m_has_mark, &commit->m_mark); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_author(&d, &l, &b, &commit->m_author_name, &commit->m_author_email, &commit->m_author_timestamp); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_committer(&d, &l, &b, &commit->m_committer_name, &commit->m_committer_email, &commit->m_committer_timestamp); mk_lang_check_rereturn(err); }
	if(b){ fi->m_buf = d; fi->m_len = l; }
	if(b){ err = mk_lib_fast_import_pr_reread(fi); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_do_data_with_binary_data(fi, &b, &commit->m_message); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_reread(fi); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_do_from_opt(fi, &b, &commit->m_has_from_mark_ref, &commit->m_from_mark_ref); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_do_file_ops(fi, &b, &commit->m_file_ops); mk_lang_check_rereturn(err); }
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_binary_data(mk_lib_fast_import_pt const fi, mk_lib_fast_import_blob_pt const blob) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt tvp;
	mk_sl_cui_uint8_pt binary_buf;
	mk_lang_types_sint_t binary_len;
	mk_lang_types_sint_t to_copy;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(blob);

	err = mk_lib_fast_import_mallocator_lokal_allocate(fi->m_mallocator, ((mk_lang_types_usize_t)(blob->m_binary_len)), &tvp); mk_lang_check_rereturn(err);
	mk_lang_check_return(tvp);
	blob->m_binary_buf = ((mk_sl_cui_uint8_pt)(tvp));
	binary_buf = blob->m_binary_buf;
	binary_len = blob->m_binary_len;
	do
	{
		to_copy = mk_lang_min(binary_len, fi->m_len);
		mk_sl_cui_uint8_memcpy_fn(binary_buf, fi->m_buf, ((mk_lang_types_usize_t)(to_copy)));
		fi->m_buf += to_copy;
		fi->m_len -= to_copy;
		binary_buf += to_copy;
		binary_len -= to_copy;
		err = mk_lib_fast_import_pr_reread(fi); mk_lang_check_rereturn(err);
	}while(binary_len != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_hash_anything(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_crypto_hash_stream_sha1_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_stream_sha1_t hasher;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_stream_sha1_init(&hasher);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, data_buf, ((mk_lang_types_usize_t)(data_len)));
	mk_lib_crypto_hash_stream_sha1_finish(&hasher, digest);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_hash_blob(mk_lib_fast_import_blob_pt const blob) mk_lang_noexcept
{
	mk_sl_cui_uint8_t prefix[mk_lang_countstr(mk_lib_fast_import_k_blobsp)];
	mk_lang_bui_uint_t bui;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t str_pc[mk_lang_bui_uint_strlen_dec_v];
	mk_sl_cui_uint8_t str_u8[mk_lang_bui_uint_strlen_dec_v];
	mk_sl_cui_uint8_t zero;
	mk_lib_crypto_hash_stream_sha1_t hasher;

	mk_lang_assert(blob);
	mk_lang_assert(blob->m_binary_buf || blob->m_binary_len == 0);
	mk_lang_assert(blob->m_binary_len >= 0);

	mk_sl_cui_uint8_from_bi_pchar_many(&prefix[0], &mk_lib_fast_import_k_blobsp[0], mk_lang_countof(prefix));
	bui = ((mk_lang_bui_uint_t)(blob->m_binary_len));
	len = mk_lang_bui_uint_to_str_dec_n(&bui, &str_pc[0], mk_lang_bui_uint_strlen_dec_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&str_u8[0], &str_pc[0], mk_lang_bui_uint_strlen_dec_v);
	mk_lib_crypto_hash_stream_sha1_init(&hasher);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, &prefix[0], mk_lang_countof(prefix));
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, &str_u8[0], ((mk_lang_types_usize_t)(len)));
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, blob->m_binary_buf, ((mk_lang_types_usize_t)(blob->m_binary_len)));
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, &zero, 1);
	mk_lib_crypto_hash_stream_sha1_finish(&hasher, &blob->m_digest);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_blob(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_blob_t blob;
	mk_lib_fast_import_tree_by_mark_node_pt node;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(did);

	d = fi->m_buf;
	l = fi->m_len;
	b = mk_lang_true;
	blob.m_fi = fi;
	if(b){ err = mk_lib_fast_import_st_do_blob_whole(&d, &l, &b, &blob); mk_lang_check_rereturn(err); }
	if(b){ fi->m_buf = d; fi->m_len = l; }
	if(b){ err = mk_lib_fast_import_pr_do_binary_data(fi, &blob); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_binary_suffix(&fi->m_buf, &fi->m_len, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_hash_blob(&blob); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_save_blob_to_database(fi, &blob); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_free_binary_data(&blob); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_tree_by_mark_rw_insert_element_move(&fi->m_marks, &blob, &node); mk_lang_check_rereturn(err); mk_lang_assert(node); }
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_append_object_path(mk_lib_fast_import_pt const fi, mk_lib_crypto_hash_stream_sha1_digest_pct const digest, mk_lang_types_usize_pt const old_len) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr;
	mk_lang_types_pchar_t slash;
	mk_lang_types_pchar_t nul;
	mk_lang_types_pchar_t str_digest[1 + mk_lang_countstr(mk_lib_fast_import_k_dot_git) + 1 + mk_lang_countstr(mk_lib_fast_import_k_objects) + 1 + 1 * mk_sl_cui_uint8_strlen_hex_v + 1 + (mk_lib_crypto_hash_stream_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v + 1];
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;

	mk_lang_static_assert(mk_lang_countof(digest->m_data.m_uint8s) == mk_lib_crypto_hash_stream_sha1_digest_len_v);

	mk_lang_assert(fi);
	mk_lang_assert(digest);
	mk_lang_assert(old_len);
	mk_lang_assert(fi->m_mallocator);

	ptr = 0;
	slash = '/';
	nul = '\0';
	str_digest[ptr] = slash; ++ptr;
	mk_lang_string_memcpy_pc_fn(&str_digest[ptr], &mk_lib_fast_import_k_dot_git[0], mk_lang_countstr(mk_lib_fast_import_k_dot_git)); ptr += mk_lang_countstr(mk_lib_fast_import_k_dot_git);
	str_digest[ptr] = slash; ++ptr;
	mk_lang_string_memcpy_pc_fn(&str_digest[ptr], &mk_lib_fast_import_k_objects[0], mk_lang_countstr(mk_lib_fast_import_k_objects)); ptr += mk_lang_countstr(mk_lib_fast_import_k_objects);
	str_digest[ptr] = slash; ++ptr;
	len = mk_sl_cui_uint8_to_str_hexf_many_n(&digest->m_data.m_uint8s[0], 1, &str_digest[ptr], mk_lang_countof(str_digest) - ptr); mk_lang_assert(len == 1 * mk_sl_cui_uint8_strlen_hex_v); ptr += len;
	str_digest[ptr] = slash; ++ptr;
	len = mk_sl_cui_uint8_to_str_hexf_many_n(&digest->m_data.m_uint8s[1], mk_lang_countof(digest->m_data.m_uint8s) - 1, &str_digest[ptr], mk_lang_countof(str_digest) - ptr); mk_lang_assert(len == (mk_lib_crypto_hash_stream_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v); ptr += len;
	str_digest[ptr] = nul; ++ptr;
	*old_len = mk_lib_fast_import_string_ro_size(&fi->m_output_dir);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str_digest[0], ((mk_lang_types_usize_t)(ptr))); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_restore_object_path(mk_lib_fast_import_pt const fi, mk_lang_types_usize_t const old_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(old_len != 0);
	mk_lang_assert(fi->m_mallocator);

	err = mk_lib_fast_import_string_rw_resize_to(&fi->m_output_dir, old_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_read_entire_file(mk_lib_fast_import_string_pct const path, mk_lib_fast_import_binary_data_pt const bin_data) mk_lang_noexcept
{
	mk_lang_types_pchar_pct path_buf;
	mk_lang_types_usize_t path_len;
	mk_lang_types_sint_t err;
	mk_sl_io_reader_file_t reader;
	mk_sl_cui_uint8_t file_buf[4 * 1024];
	mk_lang_types_sint_t read;

	mk_lang_assert(path);
	mk_lang_assert(bin_data);

	path_buf = mk_lib_fast_import_string_ro_data(path); mk_lang_assert(path_buf);
	path_len = mk_lib_fast_import_string_ro_size(path); mk_lang_assert(path_len >= 1);
	mk_lang_assert(path_buf[path_len - 1] == '\0');
	err = mk_sl_io_reader_file_open_n(&reader, path_buf);
	do
	{
		err = mk_sl_io_reader_file_read(&reader, &file_buf[0], mk_lang_countof(file_buf), &read); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_binary_data_rw_push_back_copy_many(bin_data, &file_buf[0], ((mk_lang_types_usize_t)(read))); mk_lang_check_rereturn(err);
	}while(read != 0);
	err = mk_sl_io_reader_file_close(&reader);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_decompress(mk_lib_fast_import_binary_data_pct const compressed, mk_lib_fast_import_binary_data_pt const decompressed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_decompress_zlib_t zlib;
	mk_sl_cui_uint8_pct deflated_buf;
	mk_lang_types_sint_t deflated_len;
	mk_sl_cui_uint8_t inflated[512];
	mk_lang_types_sint_t inc;
	mk_lang_types_sint_t outc;

	mk_lang_assert(compressed);
	mk_lang_assert(decompressed);

	err = mk_lib_fast_import_binary_data_rw_clear(decompressed); mk_lang_check_rereturn(err);
	err = mk_lib_decompress_zlib_init(&zlib);
	deflated_buf = mk_lib_fast_import_binary_data_ro_data(compressed); mk_lang_assert(deflated_buf);
	deflated_len = mk_lib_fast_import_binary_data_ro_sise(compressed); mk_lang_assert(deflated_len >= 1);
	do
	{
		err = mk_lib_decompress_zlib_append(&zlib, deflated_buf, deflated_len, &inflated[0], mk_lang_countof(inflated), &inc, &outc); mk_lang_check_rereturn(err);
		mk_lang_assert(inc >= 0);
		mk_lang_assert(outc >= 0);
		mk_lang_assert(inc <= deflated_len);
		mk_lang_assert(outc <= mk_lang_countof(inflated));
		deflated_buf += inc;
		deflated_len -= inc;
		err = mk_lib_fast_import_binary_data_rw_push_back_copy_many(decompressed, &inflated[0], ((mk_lang_types_usize_t)(outc))); mk_lang_check_rereturn(err);
	}while(deflated_len != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_load_commit(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_crypto_hash_stream_sha1_digest_pct const digest, mk_lib_fast_import_commit_pt const commit) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t old_len;
	mk_lib_fast_import_binary_data_t bin_commit_compressed;
	mk_lib_fast_import_binary_data_t bin_commit_decompressed;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(digest);
	mk_lang_assert(commit);
	mk_lang_assert(fi->m_mallocator);

	err = mk_lib_fast_import_pr_append_object_path(fi, digest, &old_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_construct(&bin_commit_compressed, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_read_entire_file(&fi->m_output_dir, &bin_commit_compressed); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_restore_object_path(fi, old_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_construct(&bin_commit_decompressed, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_decompress(&bin_commit_compressed, &bin_commit_decompressed); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_destroy(&bin_commit_compressed); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_commit_rw_deserialize_from_binary_data(commit, &bin_commit_decompressed, did); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_destroy(&bin_commit_decompressed); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_gather_sub_trees_2(mk_lib_fast_import_pt const fi, mk_lib_fast_import_tree_pct const tree, mk_lib_fast_import_trees_pt const sub_trees) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fast_import_tree_node_pct child;
	mk_lib_fast_import_tree_pt sub_tree;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(tree);
	mk_lang_assert(sub_trees);
	mk_lang_assert(fi->m_mallocator);

	n = mk_lib_fast_import_tree_nodes_ro_size(&tree->m_children);
	for(i = 0; i != n; ++i)
	{
		child = mk_lib_fast_import_tree_nodes_ro_at(&tree->m_children, i); mk_lang_assert(child);
		if(child->m_type == mk_lib_fast_import_tree_node_id_e_tree)
		{
			sub_tree = child->m_val.m_data.m_tree; mk_lang_assert(sub_tree);
			if(mk_lib_fast_import_tree_nodes_ro_is_empty(&sub_tree->m_children))
			{
				err = mk_lib_fast_import_trees_rw_push_back_copy_single(sub_trees, &sub_tree); mk_lang_check_rereturn(err);
			}
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_gather_sub_trees_1(mk_lib_fast_import_pt const fi, mk_lib_fast_import_tree_pct const tree, mk_lib_fast_import_trees_pt const sub_trees) mk_lang_noexcept
{
	mk_lang_types_usize_t old_len;
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t i;
	mk_lib_fast_import_tree_ppt ta;
	mk_lib_fast_import_tree_pt tb;

	mk_lang_assert(fi);
	mk_lang_assert(tree);
	mk_lang_assert(sub_trees);
	mk_lang_assert(fi->m_mallocator);

	old_len = mk_lib_fast_import_trees_rw_size(sub_trees);
	err = mk_lib_fast_import_pr_gather_sub_trees_2(fi, tree, sub_trees); mk_lang_check_rereturn(err);
	for(i = old_len; i != mk_lib_fast_import_trees_rw_size(sub_trees); ++i)
	{
		ta = mk_lib_fast_import_trees_rw_at(sub_trees, i); mk_lang_assert(ta); tb = *ta; mk_lang_assert(tb);
		err = mk_lib_fast_import_pr_gather_sub_trees_2(fi, tb, sub_trees); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_load_tree_2(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_crypto_hash_stream_sha1_digest_pct const digest, mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t old_len;
	mk_lib_fast_import_binary_data_t bin_tree_compressed;
	mk_lib_fast_import_binary_data_t bin_tree_decompressed;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(digest);
	mk_lang_assert(digest);
	mk_lang_assert(fi->m_mallocator);

	err = mk_lib_fast_import_pr_append_object_path(fi, digest, &old_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_construct(&bin_tree_compressed, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_read_entire_file(&fi->m_output_dir, &bin_tree_compressed); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_restore_object_path(fi, old_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_construct(&bin_tree_decompressed, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_decompress(&bin_tree_compressed, &bin_tree_decompressed); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_destroy(&bin_tree_compressed); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_tree_rw_deserialize_from_binary_data(tree, &bin_tree_decompressed, did); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_destroy(&bin_tree_decompressed); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_load_tree_1(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_crypto_hash_stream_sha1_digest_pct const digest, mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_trees_t sub_trees;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(digest);
	mk_lang_assert(digest);
	mk_lang_assert(fi->m_mallocator);

	gud = mk_lang_true;
	if(gud)
	{
		err = mk_lib_fast_import_pr_load_tree_2(fi, &gud, digest, tree); mk_lang_check_rereturn(err);
	}
	if(gud)
	{
		err = mk_lib_fast_import_trees_rw_construct(&sub_trees, fi->m_mallocator); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_pr_gather_sub_trees_1(fi, tree, &sub_trees); mk_lang_check_rereturn(err);
		while(!mk_lib_fast_import_trees_rw_is_empty(&sub_trees))
		{
		}
		//err = mk_lib_fast_import_pr_load_tree_2(fi, &gud, &sub_digest, sub_tree); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_trees_rw_destroy(&sub_trees); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_gather_sub_trees_3(mk_lib_fast_import_pt const fi, mk_lib_fast_import_tree_pct const tree, mk_lib_fast_import_trees_pt const sub_trees) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fast_import_tree_node_pct child;
	mk_lib_fast_import_tree_pt sub_tree;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(tree);
	mk_lang_assert(sub_trees);
	mk_lang_assert(fi->m_mallocator);

	n = mk_lib_fast_import_tree_nodes_ro_size(&tree->m_children);
	for(i = 0; i != n; ++i)
	{
		child = mk_lib_fast_import_tree_nodes_ro_at(&tree->m_children, i); mk_lang_assert(child);
		if(child->m_type == mk_lib_fast_import_tree_node_id_e_tree)
		{
			sub_tree = child->m_val.m_data.m_tree; mk_lang_assert(sub_tree);
			mk_lang_assert(mk_lib_fast_import_tree_nodes_ro_is_empty(&sub_tree->m_children)); /* todo */
			{
				err = mk_lib_fast_import_trees_rw_push_back_copy_single(sub_trees, &sub_tree); mk_lang_check_rereturn(err);
			}
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_load_tree_4(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t old_len;
	mk_lib_fast_import_binary_data_t bin_tree_compressed;
	mk_lib_fast_import_binary_data_t bin_tree_decompressed;
	mk_lang_types_bool_t gud;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(tree);
	mk_lang_assert(fi->m_mallocator);

	err = mk_lib_fast_import_pr_append_object_path(fi, &tree->m_digest_value, &old_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_construct(&bin_tree_compressed, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_read_entire_file(&fi->m_output_dir, &bin_tree_compressed); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_restore_object_path(fi, old_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_construct(&bin_tree_decompressed, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_decompress(&bin_tree_compressed, &bin_tree_decompressed); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_destroy(&bin_tree_compressed); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_tree_rw_deserialize_from_binary_data(tree, &bin_tree_decompressed, &gud); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_destroy(&bin_tree_decompressed); mk_lang_check_rereturn(err);
	*did = gud;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_load_tree_3(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_crypto_hash_stream_sha1_digest_pct const digest, mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_trees_t sub_trees;
	mk_lib_fast_import_tree_ppt ta;
	mk_lib_fast_import_tree_pt tb;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(digest);
	mk_lang_assert(tree);
	mk_lang_assert(fi->m_mallocator);

	tree->m_digest_computed = mk_lang_true;
	tree->m_digest_value = *digest;
	err = mk_lib_fast_import_trees_rw_construct(&sub_trees, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_trees_rw_push_back_copy_single(&sub_trees, &tree); mk_lang_check_rereturn(err);
	while(!mk_lib_fast_import_trees_rw_is_empty(&sub_trees))
	{
		ta = mk_lib_fast_import_trees_rw_back(&sub_trees); mk_lang_assert(ta); tb = *ta; mk_lang_assert(tb);
		err = mk_lib_fast_import_trees_rw_pop_back_single(&sub_trees); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_pr_load_tree_4(fi, &gud, tb); mk_lang_check_rereturn(err);
		mk_lang_check_return(gud); /* todo */
		err = mk_lib_fast_import_pr_gather_sub_trees_3(fi, tb, &sub_trees); mk_lang_check_rereturn(err);
	}
	err = mk_lib_fast_import_trees_rw_destroy(&sub_trees); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_load_parent_tree(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_commit_pct const commit, mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;
	mk_lib_fast_import_mark_to_commit_t mark_to_commit_a;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_map_mark_to_commit_node_pt node;
	mk_lib_fast_import_mark_to_commit_pct mark_to_commit_b;
	mk_lib_fast_import_commit_t parent_commit;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(commit);
	mk_lang_assert(tree);
	mk_lang_assert(fi->m_mallocator);

	gud = mk_lang_true;
	if(commit->m_has_from_mark_ref)
	{
		mark_to_commit_a.m_mark = commit->m_from_mark_ref;
		err = mk_lib_fast_import_map_mark_to_commit_ro_find_node(&fi->m_commits, &mark_to_commit_a, &node); mk_lang_check_rereturn(err); mk_lang_check_return(node);
		err = mk_lib_fast_import_map_mark_to_commit_ro_node_get_element(node, &mark_to_commit_b); mk_lang_check_rereturn(err); mk_lang_check_return(mark_to_commit_b);
		err = mk_lib_fast_import_commit_rw_construct(&parent_commit, fi); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_pr_load_commit(fi, &gud, &mark_to_commit_b->m_digest, &parent_commit); mk_lang_check_rereturn(err);
		if(gud){ err = mk_lib_fast_import_pr_load_tree_3(fi, &gud, &parent_commit.m_tree_digest, tree); mk_lang_check_rereturn(err); }
		err = mk_lib_fast_import_commit_rw_destroy(&parent_commit); mk_lang_check_rereturn(err);
	}
	*did = gud;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_extract_parent_tree(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_commit_pct const commit, mk_lib_fast_import_tree_pt const parent_tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(commit);
	mk_lang_assert(parent_tree);
	mk_lang_assert(fi->m_mallocator);

	err = mk_lib_fast_import_pr_load_parent_tree(fi, &gud, commit, parent_tree); mk_lang_check_rereturn(err);
	if(gud){ err = mk_lib_fast_import_tree_debug_print(parent_tree); mk_lang_check_rereturn(err); }
	*did = gud;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_extract_my_tree(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_commit_pct const commit, mk_lib_fast_import_tree_pt const my_tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(commit);
	mk_lang_assert(my_tree);
	mk_lang_assert(fi->m_mallocator);

	err = mk_lib_fast_import_tree_load_from_commit(my_tree, commit); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_tree_debug_print(my_tree); mk_lang_check_rereturn(err);
	*did = mk_lang_true;
	return 0;
}

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_zlib_and_digest_s
{
	mk_lib_fast_import_pt m_fi;
	mk_lib_compress_zlib_t m_zlib;
	mk_lib_crypto_hash_stream_sha1_t m_hasher;
	mk_lib_fast_import_binary_data_pt m_bytes;
	mk_lib_crypto_hash_stream_sha1_digest_pt m_digest;
};
typedef struct mk_lib_fast_import_zlib_and_digest_s mk_lib_fast_import_zlib_and_digest_t;
mk_lang_typedef(mk_lib_fast_import_zlib_and_digest);
#include "mk_lang_warning_msvc_pop.h"

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_zlib_and_digest_init(mk_lib_fast_import_zlib_and_digest_pt const zlib_and_digest, mk_lib_fast_import_pt const fi, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_crypto_hash_stream_sha1_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(zlib_and_digest);
	mk_lang_assert(fi);
	mk_lang_assert(bytes);
	mk_lang_assert(digest);

	zlib_and_digest->m_fi = fi;
	mk_lib_compress_zlib_init(&zlib_and_digest->m_zlib);
	mk_lib_crypto_hash_stream_sha1_init(&zlib_and_digest->m_hasher);
	zlib_and_digest->m_bytes = bytes;
	zlib_and_digest->m_digest = digest;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_zlib_and_digest_append_u8s(mk_lib_fast_import_zlib_and_digest_pt const zlib_and_digest, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf;
	mk_lang_types_sint_t in_len;
	mk_sl_cui_uint8_pt out_buf;
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t out_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t in_c;
	mk_lang_types_sint_t out_c;

	mk_lang_assert(zlib_and_digest);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);

	in_buf = buf;
	in_len = len;
	out_buf = &u8s[0];
	out_len = mk_lang_countof(u8s);
	do
	{
		mk_lib_compress_zlib_append(&zlib_and_digest->m_zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c);
		err = mk_lib_fast_import_binary_data_rw_push_back_copy_many(zlib_and_digest->m_bytes, out_buf, ((mk_lang_types_usize_t)(out_c))); mk_lang_check_rereturn(err);
		mk_lib_crypto_hash_stream_sha1_append_u8s(&zlib_and_digest->m_hasher, in_buf, ((mk_lang_types_usize_t)(in_c)));
		in_buf += in_c;
		in_len -= in_c;
	}while(in_len != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_zlib_and_digest_append_pchars(mk_lib_fast_import_zlib_and_digest_pt const zlib_and_digest, mk_lang_types_pchar_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t err;

	mk_lang_assert(zlib_and_digest);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);

	if(len > mk_lang_countof(u8s))
	{
		mk_lang_check_todo();
	}
	mk_sl_cui_uint8_from_bi_pchar_many(&u8s[0], buf, ((mk_lang_types_usize_t)(len)));
	err = mk_lib_fast_import_zlib_and_digest_append_u8s(zlib_and_digest, &u8s[0], len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_zlib_and_digest_finish(mk_lib_fast_import_zlib_and_digest_pt const zlib_and_digest) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt out_buf;
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t out_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t out_c;

	mk_lang_assert(zlib_and_digest);

	out_buf = &u8s[0];
	out_len = mk_lang_countof(u8s);
	do
	{
		mk_lib_compress_zlib_finish(&zlib_and_digest->m_zlib, out_buf, out_len, &out_c);
		err = mk_lib_fast_import_binary_data_rw_push_back_copy_many(zlib_and_digest->m_bytes, out_buf, ((mk_lang_types_usize_t)(out_c))); mk_lang_check_rereturn(err);
	}while(out_c != 0);
	mk_lib_crypto_hash_stream_sha1_finish(&zlib_and_digest->m_hasher, zlib_and_digest->m_digest);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_zlib_append_u32_str(mk_lib_fast_import_pt const fi, mk_lib_compress_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_sl_cui_uint32_pct const u32) mk_lang_noexcept
{
	mk_lang_types_sint_t slen;
	mk_lang_types_pchar_t str[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(u32);

	slen = mk_sl_cui_uint32_to_str_dec_n(u32, &str[0], mk_lang_countof(str)); mk_lang_assert(slen >= 1); mk_lang_assert(slen <= mk_lang_countof(str));
	err = mk_lib_fast_import_pr_tree_append_pchars(fi, zlib, bytes, &str[0], slen); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_write_to_database_2(mk_lib_fast_import_pt const fi, mk_sl_io_writer_file_pt const writer, mk_lib_fast_import_tree_pct const tree) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t w;

	mk_lang_assert(fi);
	mk_lang_assert(writer);
	mk_lang_assert(tree);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));

	data_buf = mk_lib_fast_import_binary_data_ro_data(&tree->m_data);
	data_len = mk_lib_fast_import_binary_data_ro_sise(&tree->m_data);
	err = mk_sl_io_writer_file_write(writer, data_buf, data_len, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == data_len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_write_to_database_1(mk_lib_fast_import_pt const fi, mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_lang_types_pchar_t str[((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_sha1_digest_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))];
	mk_lang_types_usize_t old_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_sl_io_writer_file_t writer;
	mk_win_base_bool_t b; /* todo */
	mk_win_base_dword_t gle; /* todo */

	mk_lang_assert(fi);
	mk_lang_assert(tree);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));

	old_len = mk_lib_fast_import_string_ro_size(&fi->m_output_dir);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_dot_git[0], mk_lang_countstr(mk_lib_fast_import_k_dot_git)); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_objects[0], mk_lang_countstr(mk_lib_fast_import_k_objects)); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_n(&tree->m_digest_value.m_data.m_uint8s[0], &str[0], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str[0], mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	tpc = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	b = mk_win_dll_kernel_files_a_create_directory(mk_lib_fast_import_string_ro_data(&fi->m_output_dir), mk_win_base_null); mk_lang_check_return(b != 0 || (gle = mk_win_dll_kernel_errors_get_last()) == mk_win_dll_kernel_errors_id_e_already_exists); /* todo */
	err = mk_lib_fast_import_string_rw_pop_back_single(&fi->m_output_dir); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_many_n(&tree->m_digest_value.m_data.m_uint8s[1], mk_lib_crypto_hash_stream_sha1_digest_len_v - 1, &str[0], mk_lang_countof(str)); mk_lang_assert(len == (mk_lib_crypto_hash_stream_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str[0], (mk_lib_crypto_hash_stream_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	tpc = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_open_n(&writer, mk_lib_fast_import_string_ro_data(&fi->m_output_dir)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_write_to_database_2(fi, &writer, tree); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_resize_to(&fi->m_output_dir, old_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_depth_first(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t sise;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_fast_import_tree_node_pt child;
	mk_lib_fast_import_tree_pt sub_tree;
	mk_lib_fast_import_blob_pt sub_blob;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t acc;
	mk_lang_types_pchar_t str_buf[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_sint_t str_len;
	mk_sl_cui_uint32_t u32;
	mk_lang_types_pchar_t nul;
	mk_lang_types_pchar_t sp;
	mk_lib_fast_import_zlib_and_digest_t zlib_and_digest;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(tree);

	acc = 0;
	sise = mk_lib_fast_import_tree_nodes_rw_sise(&tree->m_children);
	n = sise;
	for(i = 0; i != n; ++i)
	{
		child = mk_lib_fast_import_tree_nodes_rw_at(&tree->m_children, ((mk_lang_types_usize_t)(i))); mk_lang_assert(child);
		if(child->m_type == mk_lib_fast_import_tree_node_id_e_tree)
		{
			sub_tree = child->m_val.m_data.m_tree; mk_lang_assert(sub_tree);
			err = mk_lib_fast_import_pr_depth_first(fi, did, sub_tree); mk_lang_check_rereturn(err);
		}
		if(child->m_type == mk_lib_fast_import_tree_node_id_e_tree)
		{
			sub_tree = child->m_val.m_data.m_tree;
			acc += sub_tree->m_mode_len;
			acc += 1; /* sp */
			acc += mk_lib_fast_import_string_ro_sise(&child->m_name);
			acc += 1; /* nul */
			acc += mk_lib_crypto_hash_stream_sha1_digest_len_v;
		}
		else if(child->m_type == mk_lib_fast_import_tree_node_id_e_blob)
		{
			sub_blob = child->m_val.m_data.m_blob;
			acc += sub_blob->m_mode_len;
			acc += 1; /* sp */
			acc += mk_lib_fast_import_string_ro_sise(&child->m_name);
			acc += 1; /* nul */
			acc += mk_lib_crypto_hash_stream_sha1_digest_len_v;
		}
		else
		{
			mk_lang_assert(mk_lang_runtime_bool_fn_false);
		}
	}
	mk_sl_cui_uint32_from_bi_sint(&u32, &acc);
	str_len = mk_sl_cui_uint32_to_str_dec_n(&u32, &str_buf[0], mk_lang_countof(str_buf));
	nul = '\0';
	sp = ' ';
	err = mk_lib_fast_import_zlib_and_digest_init(&zlib_and_digest, fi, &tree->m_data, &tree->m_digest_value); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_tree_sp[0], mk_lang_countstr(mk_lib_fast_import_k_tree_sp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &str_buf[0], str_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &nul, 1); mk_lang_check_rereturn(err);
	for(i = 0; i != n; ++i)
	{
		child = mk_lib_fast_import_tree_nodes_rw_at(&tree->m_children, ((mk_lang_types_usize_t)(i))); mk_lang_assert(child);
		if(child->m_type == mk_lib_fast_import_tree_node_id_e_tree)
		{
			sub_tree = child->m_val.m_data.m_tree;
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &sub_tree->m_mode_buf[0], sub_tree->m_mode_len); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &sp, 1); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&child->m_name), mk_lib_fast_import_string_ro_sise(&child->m_name)); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &nul, 1); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_u8s(&zlib_and_digest, &sub_tree->m_digest_value.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha1_digest_len_v); mk_lang_check_rereturn(err);
		}
		else if(child->m_type == mk_lib_fast_import_tree_node_id_e_blob)
		{
			sub_blob = child->m_val.m_data.m_blob;
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &sub_blob->m_mode_buf[0], sub_blob->m_mode_len); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &sp, 1); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&child->m_name), mk_lib_fast_import_string_ro_sise(&child->m_name)); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &nul, 1); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_u8s(&zlib_and_digest, &sub_blob->m_digest.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha1_digest_len_v); mk_lang_check_rereturn(err);
		}
		else
		{
			mk_lang_assert(mk_lang_runtime_bool_fn_false);
		}
	}
	err = mk_lib_fast_import_zlib_and_digest_finish(&zlib_and_digest); mk_lang_check_rereturn(err);
	tree->m_digest_computed = mk_lang_true;
	err = mk_lib_fast_import_pr_tree_write_to_database_1(fi, tree); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_hash_tree(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(tree);

	err = mk_lib_fast_import_pr_depth_first(fi, did, tree); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_commit_compute_len(mk_lib_fast_import_pt const fi, mk_lib_fast_import_commit_pct const commit, mk_lib_fast_import_tree_pct const tree, mk_lang_types_sint_pt const len) mk_lang_noexcept
{
	mk_lang_types_sint_t acc;

	mk_lang_assert(fi);
	mk_lang_assert(commit);
	mk_lang_assert(tree);
	mk_lang_assert(len);

	acc = 0;
	acc += mk_lang_countstr(mk_lib_fast_import_k_tree_sp);
	acc += ((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_sha1_digest_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v));
	acc += 1; /* lf */
	if(commit->m_has_from_mark_ref)
	{
		acc += mk_lang_countstr(mk_lib_fast_import_k_parent_sp);
		acc += ((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_sha1_digest_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v));
		acc += 1; /* lf */
	}
	acc += mk_lang_countstr(mk_lib_fast_import_k_author_sp);
	acc += mk_lib_fast_import_string_ro_sise(&commit->m_author_name);
	acc += mk_lang_countstr(mk_lib_fast_import_k_splt);
	acc += mk_lib_fast_import_string_ro_sise(&commit->m_author_email);
	acc += mk_lang_countstr(mk_lib_fast_import_k_gtsp);
	acc += mk_lib_fast_import_string_ro_sise(&commit->m_author_timestamp);
	acc += 1; /* lf */
	acc += mk_lang_countstr(mk_lib_fast_import_k_committer_sp);
	acc += mk_lib_fast_import_string_ro_sise(&commit->m_committer_name);
	acc += mk_lang_countstr(mk_lib_fast_import_k_splt);
	acc += mk_lib_fast_import_string_ro_sise(&commit->m_committer_email);
	acc += mk_lang_countstr(mk_lib_fast_import_k_gtsp);
	acc += mk_lib_fast_import_string_ro_sise(&commit->m_committer_timestamp);
	acc += 1; /* lf */
	acc += 1; /* lf */
	acc += mk_lib_fast_import_binary_data_ro_sise(&commit->m_message);
	*len = acc;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_write_object_to_database_2(mk_lib_fast_import_pt const fi, mk_sl_io_writer_file_pt const writer, mk_lib_fast_import_binary_data_pct const data) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t w;

	mk_lang_assert(fi);
	mk_lang_assert(writer);
	mk_lang_assert(data);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));

	data_buf = mk_lib_fast_import_binary_data_ro_data(data);
	data_len = mk_lib_fast_import_binary_data_ro_sise(data);
	err = mk_sl_io_writer_file_write(writer, data_buf, data_len, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == data_len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_write_object_to_database(mk_lib_fast_import_pt const fi, mk_lib_crypto_hash_stream_sha1_digest_pct const digest, mk_lib_fast_import_binary_data_pct const data) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_lang_types_pchar_t str[((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_sha1_digest_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))];
	mk_lang_types_usize_t old_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_sl_io_writer_file_t writer;
	mk_win_base_bool_t b; /* todo */
	mk_win_base_dword_t gle; /* todo */

	mk_lang_assert(fi);
	mk_lang_assert(digest);
	mk_lang_assert(data);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));

	old_len = mk_lib_fast_import_string_ro_size(&fi->m_output_dir);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_dot_git[0], mk_lang_countstr(mk_lib_fast_import_k_dot_git)); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_objects[0], mk_lang_countstr(mk_lib_fast_import_k_objects)); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_n(&digest->m_data.m_uint8s[0], &str[0], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str[0], mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	tpc = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	b = mk_win_dll_kernel_files_a_create_directory(mk_lib_fast_import_string_ro_data(&fi->m_output_dir), mk_win_base_null); mk_lang_check_return(b != 0 || (gle = mk_win_dll_kernel_errors_get_last()) == mk_win_dll_kernel_errors_id_e_already_exists); /* todo */
	err = mk_lib_fast_import_string_rw_pop_back_single(&fi->m_output_dir); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_many_n(&digest->m_data.m_uint8s[1], mk_lib_crypto_hash_stream_sha1_digest_len_v - 1, &str[0], mk_lang_countof(str)); mk_lang_assert(len == (mk_lib_crypto_hash_stream_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str[0], (mk_lib_crypto_hash_stream_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	tpc = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_open_n(&writer, mk_lib_fast_import_string_ro_data(&fi->m_output_dir)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_write_object_to_database_2(fi, &writer, data); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_resize_to(&fi->m_output_dir, old_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_commit_compute_data(mk_lib_fast_import_pt const fi, mk_lib_fast_import_commit_pt const commit, mk_lib_fast_import_tree_pct const tree, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_pchar_t str_buf[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t nul;
	mk_lang_types_pchar_t lf;
	mk_lib_fast_import_zlib_and_digest_t zlib_and_digest;
	mk_lang_types_pchar_t digest_str_buf[((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_sha1_digest_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))];
	mk_lang_types_sint_t digest_str_len;
	mk_lib_fast_import_mark_to_commit_t mark_to_commit_a;
	mk_lib_fast_import_map_mark_to_commit_node_pt node;
	mk_lib_fast_import_mark_to_commit_pct mark_to_commit_b;
	mk_lang_types_pchar_t parent_str_buf[((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_sha1_digest_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))];
	mk_lang_types_sint_t parent_str_len;

	mk_lang_assert(fi);
	mk_lang_assert(commit);
	mk_lang_assert(tree);
	mk_lang_assert(len >= 1);

	mk_sl_cui_uint32_from_bi_sint(&tu32, &len);
	str_len = mk_sl_cui_uint32_to_str_dec_n(&tu32, &str_buf[0], mk_lang_countof(str_buf));
	nul = '\0';
	lf = '\x0a';
	digest_str_len = mk_sl_cui_uint8_to_str_hexf_many_n(&tree->m_digest_value.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha1_digest_len_v, &digest_str_buf[0], mk_lang_countof(digest_str_buf)); mk_lang_assert(digest_str_len == ((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_sha1_digest_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)));
	err = mk_lib_fast_import_zlib_and_digest_init(&zlib_and_digest, fi, &commit->m_data, &commit->m_digest); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_commitsp[0], mk_lang_countstr(mk_lib_fast_import_k_commitsp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &str_buf[0], str_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &nul, 1); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_tree_sp[0], mk_lang_countstr(mk_lib_fast_import_k_tree_sp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &digest_str_buf[0], digest_str_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &lf, 1); mk_lang_check_rereturn(err);
	if(commit->m_has_from_mark_ref)
	{
		mark_to_commit_a.m_mark = commit->m_from_mark_ref;
		err = mk_lib_fast_import_map_mark_to_commit_ro_find_node(&fi->m_commits, &mark_to_commit_a, &node); mk_lang_check_rereturn(err); mk_lang_check_return(node);
		err = mk_lib_fast_import_map_mark_to_commit_ro_node_get_element(node, &mark_to_commit_b); mk_lang_check_rereturn(err); mk_lang_check_return(mark_to_commit_b);
		parent_str_len = mk_sl_cui_uint8_to_str_hexf_many_n(&mark_to_commit_b->m_digest.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha1_digest_len_v, &parent_str_buf[0], mk_lang_countof(parent_str_buf)); mk_lang_assert(parent_str_len == ((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_sha1_digest_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)));
		err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_parent_sp[0], mk_lang_countstr(mk_lib_fast_import_k_parent_sp)); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &parent_str_buf[0], parent_str_len); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &lf, 1); mk_lang_check_rereturn(err);
	}
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_author_sp[0], mk_lang_countstr(mk_lib_fast_import_k_author_sp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&commit->m_author_name), mk_lib_fast_import_string_ro_sise(&commit->m_author_name)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_splt[0], mk_lang_countstr(mk_lib_fast_import_k_splt)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&commit->m_author_email), mk_lib_fast_import_string_ro_sise(&commit->m_author_email)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_gtsp[0], mk_lang_countstr(mk_lib_fast_import_k_gtsp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&commit->m_author_timestamp), mk_lib_fast_import_string_ro_sise(&commit->m_author_timestamp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &lf, 1); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_committer_sp[0], mk_lang_countstr(mk_lib_fast_import_k_committer_sp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&commit->m_committer_name), mk_lib_fast_import_string_ro_sise(&commit->m_committer_name)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_splt[0], mk_lang_countstr(mk_lib_fast_import_k_splt)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&commit->m_committer_email), mk_lib_fast_import_string_ro_sise(&commit->m_committer_email)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_gtsp[0], mk_lang_countstr(mk_lib_fast_import_k_gtsp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&commit->m_committer_timestamp), mk_lib_fast_import_string_ro_sise(&commit->m_committer_timestamp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &lf, 1); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &lf, 1); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_u8s(&zlib_and_digest, mk_lib_fast_import_binary_data_ro_data(&commit->m_message), mk_lib_fast_import_binary_data_ro_sise(&commit->m_message)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_finish(&zlib_and_digest); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_commit_write_to_database_1(mk_lib_fast_import_pt const fi, mk_lib_fast_import_commit_pt const commit, mk_lib_fast_import_tree_pct const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;

	mk_lang_assert(fi);
	mk_lang_assert(commit);
	mk_lang_assert(tree);

	err = mk_lib_fast_import_pr_commit_compute_len(fi, commit, tree, &len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_commit_compute_data(fi, commit, tree, len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_write_object_to_database(fi, &commit->m_digest, &commit->m_data); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_string_starts_with(mk_lib_fast_import_string_pct const a_str, mk_lang_types_pchar_pct const b_buf, mk_lang_types_sint_t const b_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pct a_buf;
	mk_lang_types_sint_t a_len;
	mk_lang_types_bool_t cmp;

	mk_lang_assert(a_str);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(a_str));
	mk_lang_assert(b_buf);
	mk_lang_assert(b_len >= 1);

	a_buf = mk_lib_fast_import_string_ro_data(a_str); mk_lang_assert(a_buf);
	a_len = mk_lib_fast_import_string_ro_sise(a_str); mk_lang_assert(a_len >= 1);
	cmp = a_len >= b_len;
	cmp = cmp && mk_lang_string_memcmp_pc_fn(a_buf, b_buf, ((mk_lang_types_usize_t)(b_len))) == 0;
	return cmp;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_update_branch(mk_lib_fast_import_pt const fi, mk_lib_fast_import_commit_pct const commit) mk_lang_noexcept
{
	mk_lang_types_pchar_t str_buf[((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_sha1_digest_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))];
	mk_sl_cui_uint8_t data_buf[((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_sha1_digest_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))];
	mk_lang_types_pchar_t tpc;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t str_len;
	mk_lang_types_usize_t old_len;
	mk_lang_types_sint_t w;
	mk_sl_io_writer_file_t writer;

	mk_lang_assert(fi);
	mk_lang_assert(commit);

	mk_lang_check_return(mk_string_starts_with(&commit->m_ref, &mk_lib_fast_import_k_heads[0], mk_lang_countstr(mk_lib_fast_import_k_heads)));

	old_len = mk_lib_fast_import_string_ro_size(&fi->m_output_dir);
	tpc = '\\'; err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_dot_git[0], mk_lang_countstr(mk_lib_fast_import_k_dot_git)); mk_lang_check_rereturn(err);
	tpc = '\\'; err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, mk_lib_fast_import_string_ro_data(&commit->m_ref), mk_lib_fast_import_string_ro_size(&commit->m_ref)); mk_lang_check_rereturn(err);
	tpc = '\0'; err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);

	err = mk_sl_io_writer_file_open_n(&writer, mk_lib_fast_import_string_ro_data(&fi->m_output_dir)); mk_lang_check_rereturn(err);

	str_len = mk_sl_cui_uint8_to_str_hexf_many_n(&commit->m_digest.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha1_digest_len_v, &str_buf[0], mk_lang_countof(str_buf));
	mk_sl_cui_uint8_from_bi_pchar_many(&data_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, data_buf, str_len, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == str_len);

	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_resize_to(&fi->m_output_dir, old_len); mk_lang_check_rereturn(err);
	return 0;
}

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_merge_child_3(mk_lib_fast_import_pt const fi, mk_lib_fast_import_tree_pt const merged_tree, mk_lib_fast_import_tree_node_pct const child) mk_lang_noexcept
{
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_merge_child_2(mk_lib_fast_import_pt const fi, mk_lib_fast_import_tree_pt const merged_tree, mk_lib_fast_import_tree_node_pct const child) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_fast_import_tree_node_t chld;
	mk_lib_fast_import_tree_nodes_t children;

	mk_lang_assert(fi);
	mk_lang_assert(merged_tree);
	mk_lang_assert(child);
	mk_lang_assert(fi->m_mallocator);

	err = mk_lib_fast_import_tree_nodes_rw_construct(&children, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_tree_nodes_rw_destroy(&children); mk_lang_check_rereturn(err);
	return 0;
}*/

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_merge_blob(mk_lib_fast_import_pt const fi, mk_lib_fast_import_tree_pt const merged_tree, mk_lib_fast_import_tree_node_pct const child) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fast_import_tree_node_pt node;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(merged_tree);
	mk_lang_assert(child);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(child->m_type == mk_lib_fast_import_tree_node_id_e_blob);

	n = mk_lib_fast_import_tree_nodes_rw_size(&merged_tree->m_children);
	for(i = 0; i != n; ++i)
	{
		node = mk_lib_fast_import_tree_nodes_rw_at(&merged_tree->m_children, i); mk_lang_assert(node);
		if(mk_lib_fast_import_string_ro_eq(&child->m_name, &node->m_name))
		{
			break;
		}
	}
	if(i != n)
	{
		mk_lang_clobber(&node);
		mk_lang_assert(node);
		mk_lang_assert((mk_lib_fast_import_string_ro_eq(&child->m_name, &node->m_name)));
		if(node->m_type == mk_lib_fast_import_tree_node_id_e_tree)
		{
			mk_lang_check_todo();
		}
		else if(node->m_type == mk_lib_fast_import_tree_node_id_e_blob)
		{
			err = mk_lib_fast_import_blob_rw_copy_assign(node->m_val.m_data.m_blob, child->m_val.m_data.m_blob); mk_lang_check_rereturn(err);
		}
		else
		{
			mk_lang_assert_false();
		}
	}
	else
	{
	}
	return 0;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_merge_child(mk_lib_fast_import_pt const fi, mk_lib_fast_import_tree_pt const merged_tree, mk_lib_fast_import_tree_node_pct const child) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	//mk_lib_fast_import_strings_t path;
	mk_lib_fast_import_tree_node_pct curr;

	//mk_lib_fast_import_tree_node_t child;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fast_import_tree_node_pct node;

	mk_lang_assert(fi);
	mk_lang_assert(merged_tree);
	mk_lang_assert(child);
	mk_lang_assert(fi->m_mallocator);

	if(child->m_type == mk_lib_fast_import_tree_node_id_e_blob)
	{
		err = mk_lib_fast_import_pr_merge_blob(fi, merged_tree, child); mk_lang_check_rereturn(err);
	}
	else if(child->m_type == mk_lib_fast_import_tree_node_id_e_blob)
	{
		mk_lang_check_todo();
	}
	else
	{
		mk_lang_assert_false();
	}

	//err = mk_lib_fast_import_strings_rw_construct(&path, fi->m_mallocator); mk_lang_check_rereturn(err);
	curr = child;
	n = mk_lib_fast_import_tree_nodes_ro_size(&merged_tree->m_children);
	for(i = 0; i != n; ++i)
	{
		node = mk_lib_fast_import_tree_nodes_ro_at(&merged_tree->m_children, i); mk_lang_assert(node);
		if
		(
			node->m_type == mk_lib_fast_import_tree_node_id_e_tree &&
			curr->m_type == mk_lib_fast_import_tree_node_id_e_tree &&
			mk_lib_fast_import_string_ro_eq(&node->m_name, &curr->m_name)
		)
		{
			curr = node;
			break;
		}
	}
	if(i == n)
	{
		mk_lang_check_todo();
	}
	//err = mk_lib_fast_import_strings_rw_destroy(&path); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_merge_trees(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_tree_pct const parent_tree, mk_lib_fast_import_tree_pct const my_tree, mk_lib_fast_import_tree_pt const merged_tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t children_len;
	mk_lib_fast_import_tree_node_pct children_buf;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fast_import_tree_node_pct child;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(parent_tree);
	mk_lang_assert(my_tree);
	mk_lang_assert(merged_tree);
	mk_lang_assert(fi->m_mallocator);

	err = mk_lib_fast_import_tree_nodes_rw_clear(&merged_tree->m_children); mk_lang_check_rereturn(err);
	if(mk_lib_fast_import_tree_nodes_ro_is_empty(&parent_tree->m_children))
	{
		children_len = mk_lib_fast_import_tree_nodes_ro_size(&my_tree->m_children);
		children_buf = mk_lib_fast_import_tree_nodes_ro_data(&my_tree->m_children);
		err = mk_lib_fast_import_tree_nodes_rw_push_back_copy_many(&merged_tree->m_children, children_buf, children_len); mk_lang_check_rereturn(err);
	}
	else
	{
		children_len = mk_lib_fast_import_tree_nodes_ro_size(&parent_tree->m_children);
		children_buf = mk_lib_fast_import_tree_nodes_ro_data(&parent_tree->m_children);
		err = mk_lib_fast_import_tree_nodes_rw_push_back_copy_many(&merged_tree->m_children, children_buf, children_len); mk_lang_check_rereturn(err);
		n = mk_lib_fast_import_tree_nodes_ro_size(&my_tree->m_children);
		for(i = 0; i != n; ++i)
		{
			child = mk_lib_fast_import_tree_nodes_ro_at(&my_tree->m_children, i); mk_lang_assert(child);
			err = mk_lib_fast_import_pr_merge_child(fi, merged_tree, child); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_commit(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_commit_t commit;
	mk_lib_fast_import_tree_t parent_tree;
	mk_lib_fast_import_tree_t my_tree;
	mk_lib_fast_import_tree_t merged_tree;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(fi->m_mallocator);

	b = mk_lang_true;
	err = mk_lib_fast_import_commit_rw_construct(&commit, fi); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_tree_rw_construct(&parent_tree, fi); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_tree_rw_construct(&my_tree, fi); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_tree_rw_construct(&merged_tree, fi); mk_lang_check_rereturn(err);
	if(b){ err = mk_lib_fast_import_pr_do_commit_whole(fi, &b, &commit); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_extract_parent_tree(fi, &b, &commit, &parent_tree); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_extract_my_tree(fi, &b, &commit, &my_tree); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_merge_trees(fi, &b, &parent_tree, &my_tree, &merged_tree); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_hash_tree(fi, &b, &merged_tree); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_commit_write_to_database_1(fi, &commit, &merged_tree); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_add_to_refs_commit(fi, &b, &commit); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_update_branch(fi, &commit); mk_lang_check_rereturn(err); }
	err = mk_lib_fast_import_tree_destroy(&merged_tree); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_tree_destroy(&my_tree); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_tree_destroy(&parent_tree); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_commit_rw_destroy(&commit); mk_lang_check_rereturn(err);
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_reset_whole(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_reset_pt const reset) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(reset);

	d = fi->m_buf;
	l = fi->m_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_reset_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_ref_lf(&d, &l, &b, &reset->m_ref); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_from_mark(&d, &l, &b, &reset->m_from); mk_lang_check_rereturn(err); }
	if(b){ fi->m_buf = d; fi->m_len = l; }
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_reset(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_reset_t reset;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(did);

	b = mk_lang_true;
	err = mk_lib_fast_import_reset_rw_construct(&reset, fi); mk_lang_check_rereturn(err);
	if(b){ err = mk_lib_fast_import_pr_do_reset_whole(fi, &b, &reset); mk_lang_check_rereturn(err); }
	err = mk_lib_fast_import_reset_rw_destroy(&reset); mk_lang_check_rereturn(err);
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_step(mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);

	b = mk_lang_false;
	if(!b){ err = mk_lib_fast_import_pr_do_blob(fi, &b); mk_lang_check_rereturn(err); }
	if(!b){ err = mk_lib_fast_import_pr_do_commit(fi, &b); mk_lang_check_rereturn(err); }
	if(!b){ err = mk_lib_fast_import_pr_do_reset(fi, &b); mk_lang_check_rereturn(err); }
	if(!b){ mk_lang_check_todo(); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_fast_import_pr_is_done(mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_bool_t b;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);

	b = mk_lang_false;
	return b;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fast_import_run(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_fast_import_mallocator_lokal_t mallocator_lokal;
	mk_lib_fast_import_t fi;

	err = mk_lib_fast_import_mallocator_lokal_init(&mallocator_lokal); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_fi_pr_construct(&fi); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_fi_pr_set_mallocator(&fi, &mallocator_lokal); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_fi_pr_set_input_file(&fi, "c:\\dev\\mnt\\mkdisk\\dev\\repos\\da\\galaxy.fe"); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_fi_pr_set_output_dir(&fi, "c:\\dev\\mnt\\mkdisk\\dev\\repos\\da\\galaxy"); mk_lang_check_rereturn(err);
	do
	{
		err = mk_lib_fast_import_pr_do_step(&fi); mk_lang_check_rereturn(err);
	}while(!mk_lib_fast_import_pr_is_done(&fi));
	err = mk_lib_fast_import_fi_pr_destroy(&fi); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_mallocator_lokal_deinit(&mallocator_lokal); mk_lang_check_rereturn(err);
	return 0;
}


#endif
