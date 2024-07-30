#include "mk_lib_fe_posix.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_strlen.h"
#include "mk_lang_types.h"
#include "mk_lib_posix_headers.h"
#include "mk_sl_mallocatorg.h"

#define mk_sl_vector_t_name mk_lib_fe_posix_string
#define mk_sl_vector_t_element mk_lang_types_pchar_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_filec.h"

#define mk_sl_vector_t_name mk_lib_fe_posix_files
#define mk_sl_vector_t_element mk_lib_fe_posix_file_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_filec.h"

#define mk_sl_vector_t_name mk_lib_fe_posix_ints
#define mk_sl_vector_t_element mk_lang_types_sint_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_filec.h"

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lib_fe_posix_file_lt(mk_lib_fe_posix_file_pct const a, mk_lib_fe_posix_file_pct const b)
{
	mk_lang_types_bool_t ret;
	mk_lang_types_pchar_pct texta;
	mk_lang_types_pchar_pct textb;
	mk_lang_types_usize_t lena;
	mk_lang_types_usize_t lenb;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t cmpa;
	mk_lang_types_sint_t cmpb;

	mk_lang_assert(a);
	mk_lang_assert(b);

	if(a->m_is_dir && !b->m_is_dir)
	{
		ret = mk_lang_true;
	}
	else if(b->m_is_dir && !a->m_is_dir)
	{
		ret = mk_lang_false;
	}
	else
	{
		cmpb = 0;
		texta = mk_lib_fe_posix_string_ro_data(&a->m_name); mk_lang_assert(texta && texta[0] != '\0');
		textb = mk_lib_fe_posix_string_ro_data(&b->m_name); mk_lang_assert(textb && textb[0] != '\0');
		lena = mk_lib_fe_posix_string_ro_size(&a->m_name); mk_lang_assert(lena >= 1);
		lenb = mk_lib_fe_posix_string_ro_size(&b->m_name); mk_lang_assert(lenb >= 1);
		n = mk_lang_min(lena, lenb);
		for(i = 0; i != n; ++i)
		{
			if
			(
				((texta[i] >= 'a' && texta[i] <= 'z') || (texta[i] >= 'A' && texta[i] <= 'Z')) &&
				((textb[i] >= 'a' && textb[i] <= 'z') || (textb[i] >= 'A' && textb[i] <= 'Z'))
			)
			{
				cmpa =
					((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(texta[i])) | ((mk_lang_types_ushort_t)(1u << 5)))))) -
					((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(textb[i])) | ((mk_lang_types_ushort_t)(1u << 5))))));
				if(cmpb == 0)
				{
					cmpb =
						((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(texta[i])))) -
						((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(textb[i]))));
				}
			}
			else
			{
				cmpa =
					((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(texta[i])))) -
					((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(textb[i]))));
			}
			if(cmpa != 0)
			{
				ret = cmpa < 0;
				break;
			}
		}
		if(i == n)
		{
			if(cmpb != 0)
			{
				ret = cmpb < 0;
			}
			else
			{
				ret = lena <= lenb;
			}
		}
	}
	return ret;
}
#define mk_lang_bui_t_name mk_lib_fe_posix_cntr
#define mk_lang_bui_t_base uint
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_sort_merge_t_name mk_lib_fe_posix_sort_files
#define mk_sl_sort_merge_t_data mk_lib_fe_posix_file
#define mk_sl_sort_merge_t_counter mk_lib_fe_posix_cntr
#define mk_sl_sort_merge_t_is_sorted mk_lib_fe_posix_file_lt
#define mk_sl_sort_merge_t_first_round 1
#define mk_sl_sort_merge_t_proxy mk_lang_types_sint
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t alg_find_reverse(mk_lang_types_pchar_pct const str, mk_lang_types_sint_t const len, mk_lang_types_pchar_t const chr) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t idx;
	mk_lang_types_sint_t ret;

	mk_lang_assert(str || len == 0);
	mk_lang_assert(len >= 0);

	ret = -1;
	n = len;
	for(i = 0; i != n; ++i)
	{
		idx = (n - 1) - i;
		if(str[idx] == chr)
		{
			ret = idx;
			break;
		}
	}
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_posix_prrw_clear_files(mk_lib_fe_posix_pt const fe) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fe_posix_file_pt file;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);

	n = mk_lib_fe_posix_files_ro_size(&fe->m_files);
	for(i = 0; i != n; ++i)
	{
		file = mk_lib_fe_posix_files_rw_at(&fe->m_files, (n - 1) - i); mk_lang_assert(file);
		err = mk_lib_fe_posix_string_rw_destroy(&file->m_name); mk_lang_check_rereturn(err);
	}
	err = mk_lib_fe_posix_files_rw_clear(&fe->m_files); mk_lang_check_rereturn(err);
	return  0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_posix_prrw_sort(mk_lib_fe_posix_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t count;
	mk_lib_fe_posix_file_pt files_buf;
	mk_lang_types_sint_pt proxy;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(fe);

	err = mk_lib_fe_posix_ints_rw_clear(&fe->m_sort); mk_lang_check_rereturn(err);
	count = mk_lib_fe_posix_files_ro_size(&fe->m_files); mk_lang_assert(count >= 0 && count <= mk_lang_limits_usize_max / 2 && count <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)) / 2);
	if(count != 0)
	{
		files_buf = mk_lib_fe_posix_files_rw_data(&fe->m_files); mk_lang_assert(files_buf);
		err = mk_lib_fe_posix_ints_rw_push_back_void(&fe->m_sort, count * 2); mk_lang_check_rereturn(err);
		proxy = mk_lib_fe_posix_ints_rw_data(&fe->m_sort); mk_lang_assert(proxy);
		n = ((mk_lang_types_sint_t)(count));
		for(i = 0; i != n; ++i)
		{
			proxy[i] = i;
		}
		mk_lib_fe_posix_sort_files_proxy(&files_buf[0], &proxy[0], ((mk_lib_fe_posix_cntr_t)(count)), &proxy[count]);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_posix_prrw_go_impl_1(mk_lib_fe_posix_pt const fe, DIR* const dir) mk_lang_noexcept
{
	mk_lang_types_bool_t is_root;
	mk_lang_types_pchar_t slash;
	struct dirent* elem;
	mk_lang_types_sint_t tsi;
	mk_lang_types_usize_t len;
	mk_lang_types_sint_t err;
	mk_lib_fe_posix_file_pt file;
	struct stat st;

	mk_lang_assert(fe);

	err = mk_lib_fe_posix_prrw_clear_files(fe); mk_lang_check_rereturn(err);
	is_root = mk_lib_fe_posix_string_ro_size(&fe->m_path) == 1;
	if(!is_root)
	{
		slash = '/'; err = mk_lib_fe_posix_string_rw_push_back_one(&fe->m_path, &slash); mk_lang_check_rereturn(err);
	}
	errno = 0;
	for(;;)
	{
		elem = readdir(dir);
		if(!elem)
		{
			tsi = errno;
			mk_lang_check_return(tsi == 0);
			break;
		}
		if
		(
			(elem->d_name[0] == '.' && elem->d_name[1] == '\0') ||
			(elem->d_name[0] == '.' && elem->d_name[1] == '.' && elem->d_name[2] == '\0')
		)
		{
			continue;
		}
		mk_lang_assert(elem->d_name[0] != '\0');
		len = mk_lang_strlen_n_fn(&elem->d_name[0]); mk_lang_assert(len >= 1 && len <= mk_lang_countof(elem->d_name) - 1);
		err = mk_lib_fe_posix_string_rw_push_back_many(&fe->m_path, &elem->d_name[0], len + 1); mk_lang_check_rereturn(err);
		tsi = stat(mk_lib_fe_posix_string_ro_data(&fe->m_path), &st); mk_lang_check_return(tsi == 0);
		err = mk_lib_fe_posix_string_rw_shrink(&fe->m_path, len + 1); mk_lang_check_rereturn(err);
		err = mk_lib_fe_posix_files_rw_push_back_void(&fe->m_files, 1); mk_lang_check_rereturn(err);
		file = mk_lib_fe_posix_files_rw_back(&fe->m_files); mk_lang_assert(file);
		err = mk_lib_fe_posix_string_rw_construct(&file->m_name); mk_lang_check_rereturn(err);
		err = mk_lib_fe_posix_string_rw_push_back_many(&file->m_name, &elem->d_name[0], len); mk_lang_check_rereturn(err);
		file->m_is_dir = !!S_ISDIR(st.st_mode);
	}
	if(!is_root)
	{
		err = mk_lib_fe_posix_string_rw_shrink(&fe->m_path, 1); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_posix_prrw_go(mk_lib_fe_posix_pt const fe) mk_lang_noexcept
{
	mk_lang_types_pchar_t slash;
	mk_lang_types_pchar_t zero;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct buf;
	DIR* dir;
	mk_lang_types_sint_t err_b;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(fe);

	if(mk_lib_fe_posix_string_ro_is_empty(&fe->m_path))
	{
		slash = '/'; err = mk_lib_fe_posix_string_rw_push_back_one(&fe->m_path, &slash); mk_lang_check_rereturn(err);
	}
	buf = mk_lib_fe_posix_string_ro_data(&fe->m_path); mk_lang_assert(buf && buf[0] != '\0');
	zero = '\0'; err = mk_lib_fe_posix_string_rw_push_back_one(&fe->m_path, &zero); mk_lang_check_rereturn(err);
	dir = opendir(buf); mk_lang_check_return(dir);
	err = mk_lib_fe_posix_string_rw_shrink(&fe->m_path, 1); mk_lang_check_rereturn(err);
	err_b = mk_lib_fe_posix_prrw_go_impl_1(fe, dir);
	tsi = closedir(dir); mk_lang_check_return(tsi == 0);
	mk_lang_check_rereturn(err_b);
	err = mk_lib_fe_posix_prrw_sort(fe); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_rw_construct(mk_lib_fe_posix_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);

	err = mk_lib_fe_posix_string_rw_construct(&fe->m_path); mk_lang_check_rereturn(err);
	err = mk_lib_fe_posix_files_rw_construct(&fe->m_files); mk_lang_check_rereturn(err);
	err = mk_lib_fe_posix_ints_rw_construct(&fe->m_sort); mk_lang_check_rereturn(err);
	fe->m_depth = 0;
	err = mk_lib_fe_posix_prrw_go(fe); mk_lang_check_rereturn(err);
	return  0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_rw_destruct(mk_lib_fe_posix_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fe_posix_file_pt file;

	mk_lang_assert(fe);

	err = mk_lib_fe_posix_ints_rw_destroy(&fe->m_sort); mk_lang_check_rereturn(err);
	n = mk_lib_fe_posix_files_ro_size(&fe->m_files);
	for(i = 0; i != n; ++i)
	{
		file = mk_lib_fe_posix_files_rw_at(&fe->m_files, (n - 1) - i); mk_lang_assert(file);
		err = mk_lib_fe_posix_string_rw_destroy(&file->m_name); mk_lang_check_rereturn(err);
	}
	err = mk_lib_fe_posix_files_rw_destroy(&fe->m_files); mk_lang_check_rereturn(err);
	err = mk_lib_fe_posix_string_rw_destroy(&fe->m_path); mk_lang_check_rereturn(err);
	return  0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_ro_get_path(mk_lib_fe_posix_pct const fe, mk_lib_fe_posix_string_ppct const path_out) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(path_out);

	*path_out = &fe->m_path;
	return  0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_ro_get_files(mk_lib_fe_posix_pct const fe, mk_lib_fe_posix_files_ppct const files_out) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(files_out);

	*files_out = &fe->m_files;
	return  0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_ro_get_sort(mk_lib_fe_posix_pct const fe, mk_lib_fe_posix_ints_ppct const sort_out) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(sort_out);

	*sort_out = &fe->m_sort;
	return  0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_ro_get_count(mk_lib_fe_posix_pct const fe, mk_lang_types_sint_pt const count_out) mk_lang_noexcept
{
	mk_lang_types_usize_t cnt;
	mk_lang_types_sint_t count;

	mk_lang_assert(fe);
	mk_lang_assert(count_out);

	cnt = mk_lib_fe_posix_files_ro_size(&fe->m_files); mk_lang_assert(cnt <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	count = ((mk_lang_types_sint_t)(cnt));
	*count_out = count;
	return  0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_ro_get_depth(mk_lib_fe_posix_pct const fe, mk_lang_types_sint_pt const depth_out) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(depth_out);

	*depth_out = fe->m_depth;
	return  0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_ro_can_go_up(mk_lib_fe_posix_pct const fe, mk_lang_types_bool_pt const can_go_up_out) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(can_go_up_out);

	*can_go_up_out = fe->m_depth != 0;
	return  0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_rw_go_dn(mk_lib_fe_posix_pt const fe, mk_lang_types_sint_t const idx, mk_lang_types_bool_pt const went) mk_lang_noexcept
{
	mk_lang_types_bool_t is_root;
	mk_lang_types_pchar_t slash;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t id;
	mk_lib_fe_posix_file_pct file;
	mk_lib_fe_posix_string_pct name;
	mk_lang_types_pchar_pct buf;
	mk_lang_types_usize_t len;

	mk_lang_assert(fe);
	mk_lang_assert(idx >= 0 && idx < ((mk_lang_types_sint_t)(mk_lib_fe_posix_files_ro_size(&fe->m_files))));
	mk_lang_assert(went);

	id = *mk_lib_fe_posix_ints_ro_at(&fe->m_sort, idx);
	file = mk_lib_fe_posix_files_ro_at(&fe->m_files, id); mk_lang_assert(file);
	if(file->m_is_dir)
	{
		is_root = mk_lib_fe_posix_string_ro_size(&fe->m_path) == 1;
		if(!is_root){ slash = '/'; err = mk_lib_fe_posix_string_rw_push_back_one(&fe->m_path, &slash); mk_lang_check_rereturn(err); }
		name = &file->m_name;
		buf = mk_lib_fe_posix_string_ro_data(name); mk_lang_assert(buf && buf[0] != '\0');
		len = mk_lib_fe_posix_string_ro_size(name); mk_lang_assert(len >= 1);
		err = mk_lib_fe_posix_string_rw_push_back_many(&fe->m_path, &buf[0], len); mk_lang_check_rereturn(err);
		++fe->m_depth;
		err = mk_lib_fe_posix_prrw_go(fe); mk_lang_check_rereturn(err);
		*went = mk_lang_true;
	}
	else
	{
		*went = mk_lang_false;
	}
	return  0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_rw_go_up(mk_lib_fe_posix_pt const fe, mk_lang_types_bool_pt const went) mk_lang_noexcept
{
	mk_lang_types_pchar_pct buf;
	mk_lang_types_usize_t len;
	mk_lang_types_sint_t idx;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);
	mk_lang_assert(went);

	if(fe->m_depth >= 1)
	{
		buf = mk_lib_fe_posix_string_ro_data(&fe->m_path); mk_lang_assert(buf && buf[0] != '\0');
		len = mk_lib_fe_posix_string_ro_size(&fe->m_path); mk_lang_assert(len >= 1); mk_lang_assert(len <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
		idx = alg_find_reverse(&buf[0], ((mk_lang_types_sint_t)(len)), '/'); mk_lang_assert(idx != -1);
		err = mk_lib_fe_posix_string_rw_shrink(&fe->m_path, len - idx); mk_lang_check_rereturn(err);
		--fe->m_depth;
		err = mk_lib_fe_posix_prrw_go(fe); mk_lang_check_rereturn(err);
		*went = mk_lang_true;
	}
	else
	{
		*went = mk_lang_false;
	}
	return  0;
}
