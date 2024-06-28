#include "mk_clib_app_defrag.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_offsetof.h"
#include "mk_lang_roundup.h"
#include "mk_lang_strlen.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_fmt.h"
#include "mk_lib_text_encoding.h"
#include "mk_sl_io_writer_file_windows.h"
#include "mk_sl_uint8.h"
#include "mk_win_advapi_security.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_communication.h"
#include "mk_win_kernel_console.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_kernel_files.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_kernel_process.h"

#define mk_lang_memcpy_t_name mk_clib_app_defrag_memcpywc
#define mk_lang_memcpy_t_type mk_win_base_wchar_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_lang_memset_t_name mk_clib_app_defrag_memsetuc
#define mk_lang_memset_t_type mk_lang_types_uchar_t
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"

#define mk_lang_memcmp_t_name mk_clib_app_defrag_memcmpwc
#define mk_lang_memcmp_t_type mk_lang_types_wchar_t
#include "mk_lang_memcmp_inl_fileh.h"
#include "mk_lang_memcmp_inl_filec.h"


#define mk_clib_app_defrag_name_len_max (32 * 1024)
#define mk_clib_app_defrag_type_normal 0
#define mk_clib_app_defrag_type_dir 1
#define mk_clib_app_defrag_bitmap_store_len (4 * 1024)
#define mk_clib_app_defrag_bitmap_store_ali (4 * 1024)


#define s_hlp_mk_clib_app_defrag_str_buf_crlf                         "\x0d\x0a"
#define s_hlp_mk_clib_app_defrag_str_buf_err                          "Error: %u 0x%x\x0d\x0a\0"
#define s_hlp_mk_clib_app_defrag_str_buf_fff_directory                "Directory\x0d\x0a"
#define s_hlp_mk_clib_app_defrag_str_buf_fff_reparse                  "Reparse point\x0d\x0a"
#define s_hlp_mk_clib_app_defrag_str_buf_could_not_open               "Could not open."
#define s_hlp_mk_clib_app_defrag_str_buf_could_not_enumerate          "Could not enumerate."
#define s_hlp_mk_clib_app_defrag_str_buf_could_not_enumerate_more     "Could not enumerate more."
#define s_hlp_mk_clib_app_defrag_str_buf_could_not_get_extents_more   "Could not get more extents."
#define s_hlp_mk_clib_app_defrag_str_buf_could_not_get_extents_info   "Could not get extents info."
#define s_hlp_mk_clib_app_defrag_str_buf_could_not_find_stream_first  "Could not find first stream."
#define s_hlp_mk_clib_app_defrag_str_buf_could_not_find_stream_next   "Could not find next stream."
#define s_hlp_mk_clib_app_defrag_str_buf_could_not_open_volume        "Could not open volume."
#define s_hlp_mk_clib_app_defrag_str_buf_could_not_read_volume_bitmap "Could not read volume bitmap."
#define s_hlp_mk_clib_app_defrag_str_buf_could_not_find_hole          "Could not find hole big enough for entire file.\x0d\x0a"
#define s_hlp_mk_clib_app_defrag_str_buf_could_not_move_file          "Could not move file."
#define s_hlp_mk_clib_app_defrag_str_buf_resident                     "Fragments: 1 (resident)\x0d\x0a"
#define s_hlp_mk_clib_app_defrag_str_buf_extents                      "Extents:           %llu\x0d\x0a\0"
#define s_hlp_mk_clib_app_defrag_str_buf_vclusters                    "Virtual clusters:  %llu\x0d\x0a\0"
#define s_hlp_mk_clib_app_defrag_str_buf_pclusters                    "Physical clusters: %llu\x0d\x0a\0"
#define s_hlp_mk_clib_app_defrag_str_buf_fragments                    "Fragments:         %llu\x0d\x0a\0"

#define s_mk_clib_app_defrag_str_len_crlf                         ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_crlf                        ) - 1))
#define s_mk_clib_app_defrag_str_len_err                          ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_err                         ) - 1))
#define s_mk_clib_app_defrag_str_len_fff_directory                ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_fff_directory               ) - 1))
#define s_mk_clib_app_defrag_str_len_fff_reparse                  ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_fff_reparse                 ) - 1))
#define s_mk_clib_app_defrag_str_len_could_not_open               ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_could_not_open              ) - 1))
#define s_mk_clib_app_defrag_str_len_could_not_enumerate          ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_could_not_enumerate         ) - 1))
#define s_mk_clib_app_defrag_str_len_could_not_enumerate_more     ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_could_not_enumerate_more    ) - 1))
#define s_mk_clib_app_defrag_str_len_could_not_get_extents_more   ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_could_not_get_extents_more  ) - 1))
#define s_mk_clib_app_defrag_str_len_could_not_get_extents_info   ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_could_not_get_extents_info  ) - 1))
#define s_mk_clib_app_defrag_str_len_could_not_find_stream_first  ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_could_not_find_stream_first ) - 1))
#define s_mk_clib_app_defrag_str_len_could_not_find_stream_next   ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_could_not_find_stream_next  ) - 1))
#define s_mk_clib_app_defrag_str_len_could_not_open_volume        ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_could_not_open_volume       ) - 1))
#define s_mk_clib_app_defrag_str_len_could_not_read_volume_bitmap ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_could_not_read_volume_bitmap) - 1))
#define s_mk_clib_app_defrag_str_len_could_not_find_hole          ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_could_not_find_hole         ) - 1))
#define s_mk_clib_app_defrag_str_len_could_not_move_file          ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_could_not_move_file         ) - 1))
#define s_mk_clib_app_defrag_str_len_resident                     ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_resident                    ) - 1))
#define s_mk_clib_app_defrag_str_len_extents                      ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_extents                     ) - 1))
#define s_mk_clib_app_defrag_str_len_vclusters                    ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_vclusters                   ) - 1))
#define s_mk_clib_app_defrag_str_len_pclusters                    ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_pclusters                   ) - 1))
#define s_mk_clib_app_defrag_str_len_fragments                    ((mk_lang_types_sint_t)(sizeof(s_hlp_mk_clib_app_defrag_str_buf_fragments                   ) - 1))

enum mk_clib_app_defrag_str_idx_e
{
	mk_clib_app_defrag_str_idx_e_crlf                        ,
	mk_clib_app_defrag_str_idx_e_err                         ,
	mk_clib_app_defrag_str_idx_e_fff_directory               ,
	mk_clib_app_defrag_str_idx_e_fff_reparse                 ,
	mk_clib_app_defrag_str_idx_e_could_not_open              ,
	mk_clib_app_defrag_str_idx_e_could_not_enumerate         ,
	mk_clib_app_defrag_str_idx_e_could_not_enumerate_more    ,
	mk_clib_app_defrag_str_idx_e_could_not_get_extents_more  ,
	mk_clib_app_defrag_str_idx_e_could_not_get_extents_info  ,
	mk_clib_app_defrag_str_idx_e_could_not_find_stream_first ,
	mk_clib_app_defrag_str_idx_e_could_not_find_stream_next  ,
	mk_clib_app_defrag_str_idx_e_could_not_open_volume       ,
	mk_clib_app_defrag_str_idx_e_could_not_read_volume_bitmap,
	mk_clib_app_defrag_str_idx_e_could_not_find_hole         ,
	mk_clib_app_defrag_str_idx_e_could_not_move_file         ,
	mk_clib_app_defrag_str_idx_e_resident                    ,
	mk_clib_app_defrag_str_idx_e_extents                     ,
	mk_clib_app_defrag_str_idx_e_vclusters                   ,
	mk_clib_app_defrag_str_idx_e_pclusters                   ,
	mk_clib_app_defrag_str_idx_e_fragments                   ,
	mk_clib_app_defrag_str_idx_e_dummy_end
};
typedef enum mk_clib_app_defrag_str_idx_e mk_clib_app_defrag_str_idx_t;


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_clib_app_defrag_str_all[] =
	s_hlp_mk_clib_app_defrag_str_buf_crlf
	s_hlp_mk_clib_app_defrag_str_buf_err
	s_hlp_mk_clib_app_defrag_str_buf_fff_directory
	s_hlp_mk_clib_app_defrag_str_buf_fff_reparse
	s_hlp_mk_clib_app_defrag_str_buf_could_not_open
	s_hlp_mk_clib_app_defrag_str_buf_could_not_enumerate
	s_hlp_mk_clib_app_defrag_str_buf_could_not_enumerate_more
	s_hlp_mk_clib_app_defrag_str_buf_could_not_get_extents_more
	s_hlp_mk_clib_app_defrag_str_buf_could_not_get_extents_info
	s_hlp_mk_clib_app_defrag_str_buf_could_not_find_stream_first
	s_hlp_mk_clib_app_defrag_str_buf_could_not_find_stream_next
	s_hlp_mk_clib_app_defrag_str_buf_could_not_open_volume
	s_hlp_mk_clib_app_defrag_str_buf_could_not_read_volume_bitmap
	s_hlp_mk_clib_app_defrag_str_buf_could_not_find_hole
	s_hlp_mk_clib_app_defrag_str_buf_could_not_move_file
	s_hlp_mk_clib_app_defrag_str_buf_resident
	s_hlp_mk_clib_app_defrag_str_buf_extents
	s_hlp_mk_clib_app_defrag_str_buf_vclusters
	s_hlp_mk_clib_app_defrag_str_buf_pclusters
	s_hlp_mk_clib_app_defrag_str_buf_fragments;

mk_lang_constexpr_static_inline mk_lang_types_ushort_t const s_mk_clib_app_defrag_str_lens[] =
{
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_crlf                        )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_err                         )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_fff_directory               )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_fff_reparse                 )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_could_not_open              )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_could_not_enumerate         )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_could_not_enumerate_more    )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_could_not_get_extents_more  )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_could_not_get_extents_info  )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_could_not_find_stream_first )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_could_not_find_stream_next  )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_could_not_open_volume       )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_could_not_read_volume_bitmap)),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_could_not_find_hole         )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_could_not_move_file         )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_resident                    )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_extents                     )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_vclusters                   )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_pclusters                   )),
	((mk_lang_types_ushort_t)(s_mk_clib_app_defrag_str_len_fragments                   )),
};

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ushort_t mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_t const idx) mk_lang_noexcept
{
	mk_lang_types_ushort_t r mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	r = 0;
	n = ((mk_lang_types_sint_t)(idx));
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(r + s_mk_clib_app_defrag_str_lens[i] > r);
		r += s_mk_clib_app_defrag_str_lens[i];
	}
	return r;
}

#define s_hlp_mk_clib_app_defrag_str_off_crlf                         mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_crlf                        )
#define s_hlp_mk_clib_app_defrag_str_off_err                          mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_err                         )
#define s_hlp_mk_clib_app_defrag_str_off_fff_directory                mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_fff_directory               )
#define s_hlp_mk_clib_app_defrag_str_off_fff_reparse                  mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_fff_reparse                 )
#define s_hlp_mk_clib_app_defrag_str_off_could_not_open               mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_could_not_open              )
#define s_hlp_mk_clib_app_defrag_str_off_could_not_enumerate          mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_could_not_enumerate         )
#define s_hlp_mk_clib_app_defrag_str_off_could_not_enumerate_more     mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_could_not_enumerate_more    )
#define s_hlp_mk_clib_app_defrag_str_off_could_not_get_extents_more   mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_could_not_get_extents_more  )
#define s_hlp_mk_clib_app_defrag_str_off_could_not_get_extents_info   mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_could_not_get_extents_info  )
#define s_hlp_mk_clib_app_defrag_str_off_could_not_find_stream_first  mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_could_not_find_stream_first )
#define s_hlp_mk_clib_app_defrag_str_off_could_not_find_stream_next   mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_could_not_find_stream_next  )
#define s_hlp_mk_clib_app_defrag_str_off_could_not_open_volume        mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_could_not_open_volume       )
#define s_hlp_mk_clib_app_defrag_str_off_could_not_read_volume_bitmap mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_could_not_read_volume_bitmap)
#define s_hlp_mk_clib_app_defrag_str_off_could_not_find_hole          mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_could_not_find_hole         )
#define s_hlp_mk_clib_app_defrag_str_off_could_not_move_file          mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_could_not_move_file         )
#define s_hlp_mk_clib_app_defrag_str_off_resident                     mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_resident                    )
#define s_hlp_mk_clib_app_defrag_str_off_extents                      mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_extents                     )
#define s_hlp_mk_clib_app_defrag_str_off_vclusters                    mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_vclusters                   )
#define s_hlp_mk_clib_app_defrag_str_off_pclusters                    mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_pclusters                   )
#define s_hlp_mk_clib_app_defrag_str_off_fragments                    mk_clib_app_defrag_str_off(mk_clib_app_defrag_str_idx_e_fragments                   )

#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

mk_lang_constexpr_static_inline mk_lang_types_ushort_t const s_mk_clib_app_defrag_str_offs[] =
{
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_crlf                        )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_err                         )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_fff_directory               )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_fff_reparse                 )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_could_not_open              )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_could_not_enumerate         )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_could_not_enumerate_more    )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_could_not_get_extents_more  )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_could_not_get_extents_info  )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_could_not_find_stream_first )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_could_not_find_stream_next  )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_could_not_open_volume       )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_could_not_read_volume_bitmap)),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_could_not_find_hole         )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_could_not_move_file         )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_resident                    )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_extents                     )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_vclusters                   )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_pclusters                   )),
	((mk_lang_types_ushort_t)(s_hlp_mk_clib_app_defrag_str_off_fragments                   )),
};

#define s_mk_clib_app_defrag_str_off_crlf                         s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_crlf                        ]
#define s_mk_clib_app_defrag_str_off_err                          s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_err                         ]
#define s_mk_clib_app_defrag_str_off_fff_directory                s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_fff_directory               ]
#define s_mk_clib_app_defrag_str_off_fff_reparse                  s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_fff_reparse                 ]
#define s_mk_clib_app_defrag_str_off_could_not_open               s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_could_not_open              ]
#define s_mk_clib_app_defrag_str_off_could_not_enumerate          s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_could_not_enumerate         ]
#define s_mk_clib_app_defrag_str_off_could_not_enumerate_more     s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_could_not_enumerate_more    ]
#define s_mk_clib_app_defrag_str_off_could_not_get_extents_more   s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_could_not_get_extents_more  ]
#define s_mk_clib_app_defrag_str_off_could_not_get_extents_info   s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_could_not_get_extents_info  ]
#define s_mk_clib_app_defrag_str_off_could_not_find_stream_first  s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_could_not_find_stream_first ]
#define s_mk_clib_app_defrag_str_off_could_not_find_stream_next   s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_could_not_find_stream_next  ]
#define s_mk_clib_app_defrag_str_off_could_not_open_volume        s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_could_not_open_volume       ]
#define s_mk_clib_app_defrag_str_off_could_not_read_volume_bitmap s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_could_not_read_volume_bitmap]
#define s_mk_clib_app_defrag_str_off_could_not_find_hole          s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_could_not_find_hole         ]
#define s_mk_clib_app_defrag_str_off_could_not_move_file          s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_could_not_move_file         ]
#define s_mk_clib_app_defrag_str_off_resident                     s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_resident                    ]
#define s_mk_clib_app_defrag_str_off_extents                      s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_extents                     ]
#define s_mk_clib_app_defrag_str_off_vclusters                    s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_vclusters                   ]
#define s_mk_clib_app_defrag_str_off_pclusters                    s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_pclusters                   ]
#define s_mk_clib_app_defrag_str_off_fragments                    s_mk_clib_app_defrag_str_offs[mk_clib_app_defrag_str_idx_e_fragments                   ]

#else

#define s_mk_clib_app_defrag_str_off_crlf                         s_hlp_mk_clib_app_defrag_str_off_crlf
#define s_mk_clib_app_defrag_str_off_err                          s_hlp_mk_clib_app_defrag_str_off_err
#define s_mk_clib_app_defrag_str_off_fff_directory                s_hlp_mk_clib_app_defrag_str_off_fff_directory
#define s_mk_clib_app_defrag_str_off_fff_reparse                  s_hlp_mk_clib_app_defrag_str_off_fff_reparse
#define s_mk_clib_app_defrag_str_off_could_not_open               s_hlp_mk_clib_app_defrag_str_off_could_not_open
#define s_mk_clib_app_defrag_str_off_could_not_enumerate          s_hlp_mk_clib_app_defrag_str_off_could_not_enumerate
#define s_mk_clib_app_defrag_str_off_could_not_enumerate_more     s_hlp_mk_clib_app_defrag_str_off_could_not_enumerate_more
#define s_mk_clib_app_defrag_str_off_could_not_get_extents_more   s_hlp_mk_clib_app_defrag_str_off_could_not_get_extents_more
#define s_mk_clib_app_defrag_str_off_could_not_get_extents_info   s_hlp_mk_clib_app_defrag_str_off_could_not_get_extents_info
#define s_mk_clib_app_defrag_str_off_could_not_find_stream_first  s_hlp_mk_clib_app_defrag_str_off_could_not_find_stream_first
#define s_mk_clib_app_defrag_str_off_could_not_find_stream_next   s_hlp_mk_clib_app_defrag_str_off_could_not_find_stream_next
#define s_mk_clib_app_defrag_str_off_could_not_open_volume        s_hlp_mk_clib_app_defrag_str_off_could_not_open_volume
#define s_mk_clib_app_defrag_str_off_could_not_read_volume_bitmap s_hlp_mk_clib_app_defrag_str_off_could_not_read_volume_bitmap
#define s_mk_clib_app_defrag_str_off_could_not_find_hole          s_hlp_mk_clib_app_defrag_str_off_could_not_find_hole
#define s_mk_clib_app_defrag_str_off_could_not_move_file          s_hlp_mk_clib_app_defrag_str_off_could_not_move_file
#define s_mk_clib_app_defrag_str_off_resident                     s_hlp_mk_clib_app_defrag_str_off_resident
#define s_mk_clib_app_defrag_str_off_extents                      s_hlp_mk_clib_app_defrag_str_off_extents
#define s_mk_clib_app_defrag_str_off_vclusters                    s_hlp_mk_clib_app_defrag_str_off_vclusters
#define s_mk_clib_app_defrag_str_off_pclusters                    s_hlp_mk_clib_app_defrag_str_off_pclusters
#define s_mk_clib_app_defrag_str_off_fragments                    s_hlp_mk_clib_app_defrag_str_off_fragments

#endif


mk_lang_constexpr_static_inline mk_lang_types_wchar_t const s_mk_clib_app_defrag_ads_data[] = L"::$DATA";


struct mk_clib_app_defrag_fff_s
{
	mk_win_base_handle_t m_fff;
	mk_lang_types_ushort_t m_len;
};
typedef struct mk_clib_app_defrag_fff_s mk_clib_app_defrag_fff_t;
typedef mk_clib_app_defrag_fff_t const mk_clib_app_defrag_fff_ct;
typedef mk_clib_app_defrag_fff_t* mk_clib_app_defrag_fff_pt;
typedef mk_clib_app_defrag_fff_t const* mk_clib_app_defrag_fff_pct;

#define mk_sl_fixed_vector_t_name mk_clib_app_defrag_fffs
#define mk_sl_fixed_vector_t_element mk_clib_app_defrag_fff_t
#define mk_sl_fixed_vector_t_count (mk_clib_app_defrag_name_len_max / 2)
#include "mk_sl_fixed_vector_inl_fileh.h"
#include "mk_sl_fixed_vector_inl_filec.h"

#define mk_sl_io_writer_buffered_t_name mk_clib_app_defrag_buf_writer
#define mk_sl_io_writer_buffered_t_base mk_sl_io_writer_file_windows
#include "mk_sl_io_writer_buffered_inl_fileh.h"
#include "mk_sl_io_writer_buffered_inl_filec.h"

#define mk_clib_app_defrag_redirected_buf_len (64 * 1024)
#define mk_clib_app_defrag_redirected_buf_ali (64 * 1024)

struct mk_clib_app_defrag_s
{
	mk_win_base_handle_t m_output;
	mk_win_base_handle_t m_volume;
	mk_lang_types_bool_t m_redirected;
	mk_lang_types_ushort_t m_curname_len;
	mk_sl_io_writer_file_windows_t m_writer;
	mk_clib_app_defrag_buf_writer_t m_buf_writer;
	mk_win_kernel_files_w_find_data_t m_fd;
	mk_lang_types_bool_t m_opened;
	mk_lang_types_bool_t m_is_dir;
	mk_lang_types_bool_t m_just_opened_sub;
	mk_win_base_wchar_t m_curname_buf[mk_clib_app_defrag_name_len_max];
	mk_win_base_wchar_t m_tmpname_buf[mk_clib_app_defrag_name_len_max];
	mk_clib_app_defrag_fffs_t m_fffs;
	mk_sl_cui_uint8_t m_redirected_buf[mk_lang_roundup_size(mk_clib_app_defrag_redirected_buf_len, mk_clib_app_defrag_redirected_buf_ali)];
};
typedef struct mk_clib_app_defrag_s mk_clib_app_defrag_t;
typedef mk_clib_app_defrag_t const mk_clib_app_defrag_ct;
typedef mk_clib_app_defrag_t* mk_clib_app_defrag_pt;
typedef mk_clib_app_defrag_t const* mk_clib_app_defrag_pct;


mk_clib_app_defrag_t g_mk_clib_app_defrag;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_print_init(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_win_base_handle_t output;
	mk_win_base_bool_t b;
	mk_win_base_dword_t mode;
	mk_lang_types_bool_t redirected;
	mk_sl_cui_uint8_pt redirected_buf;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	output = defrag->m_output;
	if(mk_win_base_handle_is_invalid(output))
	{
		output = mk_win_kernel_console_get_std_handle(mk_win_kernel_console_std_handle_id_e_output); mk_lang_check_return(!mk_win_base_handle_is_invalid(output));
		b = mk_win_kernel_console_get_mode(output, &mode);
		redirected = b == 0;
		if(redirected)
		{
			redirected_buf = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align_ptr(&defrag->m_redirected_buf[0], mk_clib_app_defrag_redirected_buf_ali)));
			err = mk_sl_io_writer_file_windows_adopt(&defrag->m_writer, output); mk_lang_check_rereturn(err);
			err = mk_clib_app_defrag_buf_writer_init(&defrag->m_buf_writer, &defrag->m_writer, redirected_buf, mk_clib_app_defrag_redirected_buf_len); mk_lang_check_rereturn(err);
		}
		defrag->m_output = output;
		defrag->m_redirected = redirected;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_printn_redirected_0(mk_clib_app_defrag_pt const defrag, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t olen;
	mk_win_base_bool_t b;
	mk_win_base_dword_t writtendw;

	mk_lang_assert(defrag);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(!defrag->m_redirected);

	if(!mk_win_base_handle_is_null(defrag->m_output))
	{
		err = mk_lib_text_encoding_asci_to_wide(((mk_lang_types_pchar_pct)(&buf[0])), len, &defrag->m_tmpname_buf[0], mk_lang_countof(defrag->m_tmpname_buf), &olen); mk_lang_check_return(olen >= 0);
		b = mk_win_kernel_console_w_write(defrag->m_output, &defrag->m_tmpname_buf[0], ((mk_win_base_dword_t)(olen)), &writtendw, mk_win_base_null); mk_lang_check_return(b != 0 && writtendw == ((mk_win_base_dword_t)(olen)));
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_printw_redirected_0(mk_clib_app_defrag_pt const defrag, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t writtendw;

	mk_lang_assert(defrag);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(!defrag->m_redirected);

	if(!mk_win_base_handle_is_null(defrag->m_output))
	{
		b = mk_win_kernel_console_w_write(defrag->m_output, ((mk_win_base_wchar_lpct)(buf)), ((mk_win_base_dword_t)(len)), &writtendw, mk_win_base_null); mk_lang_check_return(b != 0 && writtendw == ((mk_win_base_dword_t)(len)));
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_printn_redirected_1(mk_clib_app_defrag_pt const defrag, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t writtenus;

	mk_lang_assert(defrag);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(defrag->m_redirected);

	err = mk_clib_app_defrag_buf_writer_write(&defrag->m_buf_writer, buf, ((mk_lang_types_usize_t)(len)), &writtenus); mk_lang_check_rereturn(err); mk_lang_check_return(writtenus == ((mk_lang_types_usize_t)(len)));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_printw_redirected_1(mk_clib_app_defrag_pt const defrag, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t olen;
	mk_lang_types_usize_t writtenus;

	mk_lang_assert(defrag);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(defrag->m_redirected);

	err = mk_lib_text_encoding_wide_to_utf8(((mk_lang_types_wchar_pct)(buf)), len, ((mk_lang_types_pchar_pt)(&defrag->m_tmpname_buf[0])), mk_lang_countof(defrag->m_tmpname_buf) * sizeof(defrag->m_tmpname_buf[0]), &olen); mk_lang_check_rereturn(err); mk_lang_check_return(olen >= 0);
	err = mk_clib_app_defrag_buf_writer_write(&defrag->m_buf_writer, ((mk_sl_cui_uint8_pct)(&defrag->m_tmpname_buf[0])), ((mk_lang_types_usize_t)(olen)), &writtenus); mk_lang_check_rereturn(err); mk_lang_check_return(writtenus == ((mk_lang_types_usize_t)(olen)));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_printn(mk_clib_app_defrag_pt const defrag, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);

	err = mk_clib_app_defrag_print_init(defrag); mk_lang_check_rereturn(err);
	if(!defrag->m_redirected)
	{
		err = mk_clib_app_defrag_printn_redirected_0(defrag, buf, len); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_clib_app_defrag_printn_redirected_1(defrag, buf, len); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_printw(mk_clib_app_defrag_pt const defrag, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);

	err = mk_clib_app_defrag_print_init(defrag); mk_lang_check_rereturn(err);
	if(!defrag->m_redirected)
	{
		err = mk_clib_app_defrag_printw_redirected_0(defrag, buf, len); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_clib_app_defrag_printw_redirected_1(defrag, buf, len); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_print_line_name(mk_clib_app_defrag_pt const defrag, mk_lang_types_wchar_pt const buf, mk_lang_types_ushort_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(buf);
	mk_lang_assert(buf[0] != L'\0');

	mk_lang_check_return(len >= 1 && len <= mk_clib_app_defrag_name_len_max - 2);
	if
	(
		len >= 6 &&
		buf[0] == L'\\' &&
		buf[1] == L'\\' &&
		buf[2] == L'?' &&
		buf[3] == L'\\' &&
		((buf[4] >= L'A' && buf[4] <= L'Z') || (buf[4] >= L'a' && buf[4] <= L'z')) &&
		buf[5] == L':'
	)
	{
		offset = 4;
	}
	else
	{
		offset = 0;
	}
	buf[len + 0] = L'\x0d';
	buf[len + 1] = L'\x0a';
	err = mk_clib_app_defrag_printw(defrag, ((mk_sl_cui_uint8_pct)(&buf[offset])), len - offset + 2); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_print_currname(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	err = mk_clib_app_defrag_print_line_name(defrag, &defrag->m_curname_buf[0], defrag->m_curname_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_print_crlf(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	err = mk_clib_app_defrag_printn(defrag, ((mk_sl_cui_uint8_pct)(&s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_crlf])), s_mk_clib_app_defrag_str_len_crlf); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_print_msg(mk_clib_app_defrag_pt const defrag, mk_lang_types_pchar_pct const msg_buf, mk_lang_types_sint_t const msg_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(msg_buf || msg_len == 0);
	mk_lang_assert(msg_len >= 0);

	err = mk_clib_app_defrag_printn(defrag, ((mk_sl_cui_uint8_pct)(msg_buf)), msg_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_print_gle(mk_clib_app_defrag_pt const defrag, mk_win_base_dword_t const gle) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi;
	mk_lang_types_pchar_t msg[14 + 1];
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	tsi = mk_lib_fmt_n_snprintf(&msg[0], mk_lang_countof(msg), &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_err], &gle, &gle); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countof(msg) - 1);
	err = mk_clib_app_defrag_printn(defrag, ((mk_sl_cui_uint8_pct)(&msg[0])), tsi); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_drive_letter_root_adjust(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_assert(defrag);

	if(defrag->m_curname_len == 6)
	{
		if
		(
			defrag->m_curname_buf[0] == L'\\' &&
			defrag->m_curname_buf[1] == L'\\' &&
			defrag->m_curname_buf[2] == L'?' &&
			defrag->m_curname_buf[3] == L'\\' &&
			((defrag->m_curname_buf[4] >= L'A' && defrag->m_curname_buf[4] <= L'Z') || (defrag->m_curname_buf[4] >= L'a' && defrag->m_curname_buf[4] <= L'z')) &&
			defrag->m_curname_buf[5] == L':' &&
			defrag->m_curname_buf[6] == L'\0'
		)
		{
			defrag->m_curname_buf[6] = L'\\';
			defrag->m_curname_buf[7] = L'\0';
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_file_move(mk_clib_app_defrag_pt const defrag, mk_win_base_handle_t const volume, mk_win_base_handle_t const file, mk_lang_types_ullong_t const vclusters, mk_lang_types_sint_t const align, mk_lang_types_ullong_t const hole) mk_lang_noexcept
{
	mk_win_kernel_communication_buf_fs_move_file_t mf;
	mk_win_base_bool_t b;
	mk_win_base_dword_t written;
	mk_win_base_dword_t gle;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_win_base_handle_is_invalid(volume));
	mk_lang_assert(!mk_win_base_handle_is_invalid(file));
	mk_lang_assert(vclusters >= 2);
	mk_lang_assert(align >= 0 && align <= 0xf);
	mk_lang_assert(hole != 0);

	mf.m_file = file;
	mf.m_vcn.m_data.m_data_b = 0;
	mf.m_lcn.m_data.m_data_b = hole + (((align + (0xf + 1)) - (hole & 0xf)) & 0xf);
	mf.m_clusters = ((mk_win_base_dword_t)(vclusters));
	b = mk_win_kernel_communication_device_io_control(volume, mk_win_kernel_communication_control_code_id_fs_move_file, &mf, ((mk_win_base_dword_t)(sizeof(mf))), mk_win_base_null, 0, &written, mk_win_base_null); ((mk_lang_types_void_t)(written));
	if(b == 0)
	{
		gle = mk_win_kernel_errors_get_last();
		err = mk_clib_app_defrag_print_msg(defrag, &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_could_not_move_file], s_mk_clib_app_defrag_str_len_could_not_move_file); mk_lang_check_rereturn(err);
		err = mk_clib_app_defrag_print_gle(defrag, gle); mk_lang_check_rereturn(err);
	}
	return 0;
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_defrag_hole_analyze_beg(mk_win_base_ullong_pt const biggest_hole_pos, mk_win_base_ullong_pt const biggest_hole_len, mk_win_base_ullong_pt const current_hole_pos, mk_win_base_ullong_pt const current_hole_len, mk_win_kernel_communication_buf_fs_volume_bitmap_pct const bitmap_ptr, mk_win_base_ullong_t const i) mk_lang_noexcept
{
	mk_lang_types_uint_pct ptr;
	mk_lang_types_sint_t m;
	mk_lang_types_sint_t j;
	mk_win_base_ullong_t hole_beg;
	mk_win_base_ullong_t hole_end;
	mk_lang_types_bool_t found_end;
	mk_lang_types_bool_t found_beg;
	mk_win_base_ullong_t hole_len;

	mk_lang_assert(biggest_hole_pos);
	mk_lang_assert(biggest_hole_len);
	mk_lang_assert(current_hole_pos);
	mk_lang_assert(current_hole_len);
	mk_lang_assert(bitmap_ptr);
	mk_lang_assert(*current_hole_pos == 0);
	mk_lang_assert(((mk_lang_types_uintptr_t)(&bitmap_ptr->m_buffer[0])) % sizeof(*ptr) == 0);

	ptr = ((mk_lang_types_uint_pct)(&bitmap_ptr->m_buffer[0]));
	mk_lang_assert(ptr[i] != ((mk_lang_types_uint_t)(~((mk_lang_types_uint_t)(0)))));
	m = sizeof(*ptr) * mk_lang_charbit;
	for(j = 0; j != m; ++j)
	{
		if(((ptr[i] >> j) & 0x1) == 0)
		{
			break;
		}
	}
	mk_lang_assert(j != m);
	hole_beg = bitmap_ptr->m_starting_lcn.m_data.m_data_b + i * sizeof(*ptr) * mk_lang_charbit + j;
	*current_hole_pos = hole_beg;
	*current_hole_len = 0;
	++j;
	do
	{
		found_end = mk_lang_false;
		found_beg = mk_lang_false;
		for(; j != m; ++j)
		{
			if(((ptr[i] >> j) & 0x1) != 0)
			{
				break;
			}
		}
		found_end = j != m;
		if(found_end)
		{
			hole_end = bitmap_ptr->m_starting_lcn.m_data.m_data_b + i * sizeof(*ptr) * mk_lang_charbit + j;
			hole_len = hole_end - *current_hole_pos;
			*current_hole_len = hole_len;
			if(*current_hole_len > *biggest_hole_len)
			{
				*biggest_hole_pos = *current_hole_pos;
				*biggest_hole_len = *current_hole_len;
			}
			*current_hole_pos = 0;
			for(; j != m; ++j)
			{
				if(((ptr[i] >> j) & 0x1) == 0)
				{
					break;
				}
			}
			found_beg = j != m;
			if(found_beg)
			{
				hole_beg = bitmap_ptr->m_starting_lcn.m_data.m_data_b + i * sizeof(*ptr) * mk_lang_charbit + j;
				*current_hole_pos = hole_beg;
				*current_hole_len = 0;
			}
		}
	}
	while(found_end || found_beg);
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_defrag_hole_analyze_end(mk_win_base_ullong_pt const biggest_hole_pos, mk_win_base_ullong_pt const biggest_hole_len, mk_win_base_ullong_pt const current_hole_pos, mk_win_base_ullong_pt const current_hole_len, mk_win_kernel_communication_buf_fs_volume_bitmap_pct const bitmap_ptr, mk_win_base_ullong_t const i) mk_lang_noexcept
{
	mk_lang_types_uint_pct ptr;
	mk_lang_types_sint_t m;
	mk_lang_types_sint_t j;
	mk_win_base_ullong_t hole_end;
	mk_win_base_ullong_t hole_len;
	mk_lang_types_bool_t found_beg;
	mk_lang_types_bool_t found_end;
	mk_win_base_ullong_t hole_beg;

	mk_lang_assert(biggest_hole_pos);
	mk_lang_assert(biggest_hole_len);
	mk_lang_assert(current_hole_pos);
	mk_lang_assert(current_hole_len);
	mk_lang_assert(bitmap_ptr);
	mk_lang_assert(*current_hole_pos != 0);
	mk_lang_assert(((mk_lang_types_uintptr_t)(&bitmap_ptr->m_buffer[0])) % sizeof(*ptr) == 0);

	ptr = ((mk_lang_types_uint_pct)(&bitmap_ptr->m_buffer[0]));
	mk_lang_assert(ptr[i] != ((mk_lang_types_uint_t)(0)));
	m = sizeof(*ptr) * mk_lang_charbit;
	for(j = 0; j != m; ++j)
	{
		if(((ptr[i] >> j) & 0x1) != 0)
		{
			break;
		}
	}
	mk_lang_assert(j != m);
	hole_end = bitmap_ptr->m_starting_lcn.m_data.m_data_b + i * sizeof(*ptr) * mk_lang_charbit + j;
	hole_len = hole_end - *current_hole_pos;
	*current_hole_len = hole_len;
	if(*current_hole_len > *biggest_hole_len)
	{
		*biggest_hole_pos = *current_hole_pos;
		*biggest_hole_len = *current_hole_len;
	}
	*current_hole_pos = 0;
	++j;
	do
	{
		found_beg = mk_lang_false;
		found_end = mk_lang_false;
		for(; j != m; ++j)
		{
			if(((ptr[i] >> j) & 0x1) == 0)
			{
				break;
			}
		}
		found_beg = j != m;
		if(found_beg)
		{
			hole_beg = bitmap_ptr->m_starting_lcn.m_data.m_data_b + i * sizeof(*ptr) * mk_lang_charbit + j;
			*current_hole_pos = hole_beg;
			*current_hole_len = 0;
			for(; j != m; ++j)
			{
				if(((ptr[i] >> j) & 0x1) != 0)
				{
					break;
				}
			}
			found_end = j != m;
			if(found_end)
			{
				hole_end = bitmap_ptr->m_starting_lcn.m_data.m_data_b + i * sizeof(*ptr) * mk_lang_charbit + j;
				hole_len = hole_end - *current_hole_pos;
				*current_hole_len = hole_len;
				if(*current_hole_len > *biggest_hole_len)
				{
					*biggest_hole_pos = *current_hole_pos;
					*biggest_hole_len = *current_hole_len;
				}
				*current_hole_pos = 0;
			}
		}
	}
	while(found_end || found_beg);
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_defrag_hole_analyze(mk_win_base_ullong_pt const biggest_hole_pos, mk_win_base_ullong_pt const biggest_hole_len, mk_win_base_ullong_pt const current_hole_pos, mk_win_base_ullong_pt const current_hole_len, mk_win_kernel_communication_buf_fs_volume_bitmap_pct const bitmap_ptr) mk_lang_noexcept
{
	mk_lang_types_uint_pct ptr;
	mk_win_base_ullong_t clusters;
	mk_win_base_ullong_t n;
	mk_win_base_ullong_t i;

	mk_lang_assert(biggest_hole_pos);
	mk_lang_assert(biggest_hole_len);
	mk_lang_assert(current_hole_pos);
	mk_lang_assert(current_hole_len);
	mk_lang_assert(bitmap_ptr);
	mk_lang_assert(((mk_lang_types_uintptr_t)(&bitmap_ptr->m_buffer[0])) % sizeof(*ptr) == 0);

	ptr = ((mk_lang_types_uint_pct)(&bitmap_ptr->m_buffer[0]));
	clusters = (mk_clib_app_defrag_bitmap_store_len - mk_lang_offsetof(mk_win_kernel_communication_buf_fs_volume_bitmap_t, m_buffer)) * mk_lang_charbit;
	clusters = mk_lang_min(clusters, bitmap_ptr->m_bitmap_len.m_data.m_data_b);
	n = clusters / (sizeof(*ptr) * mk_lang_charbit);
	for(i = 0; i != n; ++i)
	{
		if(*current_hole_pos == 0 && ptr[i] != ((mk_lang_types_uint_t)(~((mk_lang_types_uint_t)(0)))))
		{
			mk_clib_app_defrag_hole_analyze_beg(biggest_hole_pos, biggest_hole_len, current_hole_pos, current_hole_len, bitmap_ptr, i);
		}
		else if(*current_hole_pos != 0 && ptr[i] != ((mk_lang_types_uint_t)(0)))
		{
			mk_clib_app_defrag_hole_analyze_end(biggest_hole_pos, biggest_hole_len, current_hole_pos, current_hole_len, bitmap_ptr, i);
		}
	}
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_find_hole(mk_clib_app_defrag_pt const defrag, mk_win_base_handle_t const volume, mk_lang_types_ullong_t const vclusters, mk_lang_types_sint_t const align, mk_lang_types_ullong_pt const hole) mk_lang_noexcept
{
	mk_win_base_ullong_t biggest_hole_pos;
	mk_win_base_ullong_t biggest_hole_len;
	mk_win_base_ullong_t current_hole_pos;
	mk_win_base_ullong_t current_hole_len;
	mk_win_kernel_communication_buf_fs_volume_bitmap_pt bitmap_ptr;
	mk_lang_types_uchar_t bitmap_store[mk_lang_roundup_size(mk_clib_app_defrag_bitmap_store_len, mk_clib_app_defrag_bitmap_store_ali)];
	mk_win_kernel_communication_buf_fs_starting_lcn_t lcn;
	mk_win_base_bool_t b;
	mk_win_base_dword_t written;
	mk_win_base_dword_t gle;
	mk_win_base_ullong_t clusters;
	mk_win_base_ullong_t rem;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_win_base_handle_is_invalid(volume));
	mk_lang_assert(vclusters >= 2);
	mk_lang_assert(align >= 0 && align <= 0xf);
	mk_lang_assert(hole);

	*hole = 0;
	biggest_hole_pos = 0;
	biggest_hole_len = 0;
	current_hole_pos = 0;
	current_hole_len = 0;
	bitmap_ptr = ((mk_win_kernel_communication_buf_fs_volume_bitmap_pt)(mk_lang_roundup_align_ptr(&bitmap_store[0], mk_clib_app_defrag_bitmap_store_ali)));
	lcn.m_starting_lcn.m_data.m_data_b = 0;
	for(;;)
	{
		b = mk_win_kernel_communication_device_io_control(volume, mk_win_kernel_communication_control_code_id_fs_get_volume_bitmap, &lcn, ((mk_win_base_dword_t)(sizeof(lcn))), bitmap_ptr, mk_clib_app_defrag_bitmap_store_len, &written, mk_win_base_null); gle = mk_win_kernel_errors_get_last();
		if((b != 0) || (b == 0 && gle == ((mk_win_base_dword_t)(mk_win_kernel_errors_id_e_more_data))))
		{
			mk_lang_check_return(written >= ((mk_win_base_dword_t)(sizeof(*bitmap_ptr))) && written <= mk_clib_app_defrag_bitmap_store_len);
			mk_lang_check_return(bitmap_ptr->m_starting_lcn.m_data.m_data_b <= lcn.m_starting_lcn.m_data.m_data_b);
			clusters = (mk_clib_app_defrag_bitmap_store_len - mk_lang_offsetof(mk_win_kernel_communication_buf_fs_volume_bitmap_t, m_buffer)) * mk_lang_charbit;
			clusters = mk_lang_min(clusters, bitmap_ptr->m_bitmap_len.m_data.m_data_b);
			mk_clib_app_defrag_hole_analyze(&biggest_hole_pos, &biggest_hole_len, &current_hole_pos, &current_hole_len, bitmap_ptr);
			if(biggest_hole_len >= vclusters + (((align + (0xf + 1)) - (biggest_hole_pos & 0xf)) & 0xf))
			{
				*hole = biggest_hole_pos;
				break;
			}
			rem = bitmap_ptr->m_bitmap_len.m_data.m_data_b - clusters;
			if(rem == 0)
			{
				break;
			}
			mk_lang_check_return(bitmap_ptr->m_starting_lcn.m_data.m_data_b + clusters > lcn.m_starting_lcn.m_data.m_data_b);
			lcn.m_starting_lcn.m_data.m_data_b = bitmap_ptr->m_starting_lcn.m_data.m_data_b + clusters;
		}
		else
		{
			err = mk_clib_app_defrag_print_msg(defrag, &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_could_not_read_volume_bitmap], s_mk_clib_app_defrag_str_len_could_not_read_volume_bitmap); mk_lang_check_rereturn(err);
			err = mk_clib_app_defrag_print_gle(defrag, gle); mk_lang_check_rereturn(err);
			break;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_find_hole_and_move(mk_clib_app_defrag_pt const defrag, mk_win_base_handle_t const volume, mk_win_base_handle_t const file, mk_lang_types_ullong_t const vclusters, mk_lang_types_sint_t const align) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_ullong_t hole;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_win_base_handle_is_invalid(volume));
	mk_lang_assert(!mk_win_base_handle_is_invalid(file));
	mk_lang_assert(vclusters >= 2);
	mk_lang_assert(align >= 0 && align <= 0xf);

	err = mk_clib_app_defrag_find_hole(defrag, volume, vclusters, align, &hole); mk_lang_check_rereturn(err);
	if(hole != 0)
	{
		err = mk_clib_app_defrag_file_move(defrag, volume, file, vclusters, align, hole); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_clib_app_defrag_printn(defrag, ((mk_sl_cui_uint8_pct)(&s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_could_not_find_hole])), s_mk_clib_app_defrag_str_len_could_not_find_hole); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_volume_get_name(mk_clib_app_defrag_pt const defrag, mk_lang_types_wchar_pt const file_name, mk_lang_types_ushort_t const file_len, mk_lang_types_wchar_pt const vol_name, mk_lang_types_ushort_pt const vol_len) mk_lang_noexcept
{
	mk_lang_types_ushort_t vol_path_len;
	mk_lang_types_wchar_pt vol_path_buf;
	mk_win_base_bool_t b;
	mk_lang_types_usize_t lenus;

	mk_lang_assert(defrag);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != L'\0');
	mk_lang_assert(file_len >= 1);
	mk_lang_assert(vol_name);
	mk_lang_assert(vol_len);
	mk_lang_assert(*vol_len >= 50);

	mk_lang_check_return(file_len <= mk_clib_app_defrag_name_len_max - 1);
	file_name[file_len] = L'\0';
	vol_path_len = ((mk_lang_types_ushort_t)(mk_lang_countof(defrag->m_tmpname_buf))) / 2;
	vol_path_buf = &defrag->m_tmpname_buf[vol_path_len];
	b = mk_win_kernel_files_w_get_volume_path_name(&file_name[0], &vol_path_buf[0], vol_path_len); mk_lang_check_return(b != 0);
	b = mk_win_kernel_files_w_get_volume_name_for_volume_mount_point(&vol_path_buf[0], &vol_name[0], *vol_len); mk_lang_check_return(b != 0);
	lenus = mk_lang_strlen_w_fn(&vol_name[0]); mk_lang_check_return(lenus >= 2);
	*vol_len = ((mk_lang_types_ushort_t)(lenus));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_volume_open(mk_clib_app_defrag_pt const defrag, mk_win_base_handle_pt const volume) mk_lang_noexcept
{
	mk_lang_types_ushort_t vol_len;
	mk_lang_types_wchar_pt vol_name;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(volume);

	vol_len = ((mk_lang_types_ushort_t)(mk_lang_countof(defrag->m_tmpname_buf))) / 2;
	vol_name = &defrag->m_tmpname_buf[0];
	err = mk_clib_app_defrag_volume_get_name(defrag, &defrag->m_curname_buf[0], defrag->m_curname_len, &vol_name[0], &vol_len); mk_lang_check_rereturn(err); mk_lang_check_return(vol_len >= 1);
	if(vol_name[vol_len - 1] == L'\\' || vol_name[vol_len - 1] == L'/')
	{
		vol_name[vol_len - 1] = L'\0';
		--vol_len;
	}
	*volume = mk_win_kernel_files_w_create_file(vol_name, ((mk_win_base_dword_t)(mk_win_advapi_base_right_generic_e_read)), ((mk_win_base_dword_t)(mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_write | mk_win_kernel_files_share_e_delete)), mk_win_base_null, ((mk_win_base_dword_t)(mk_win_kernel_files_create_e_open_existing)), ((mk_win_base_dword_t)(mk_win_kernel_files_attribute_e_normal)), mk_win_base_handle_null_g);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_open_volume_find_hole_and_move(mk_clib_app_defrag_pt const defrag, mk_win_base_handle_t const file, mk_lang_types_ullong_t const vclusters, mk_lang_types_sint_t const align) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_handle_t volume;
	mk_win_base_bool_t b;
	mk_win_base_dword_t gle;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_win_base_handle_is_invalid(file));
	mk_lang_assert(vclusters >= 2);
	mk_lang_assert(align >= 0 && align <= 0xf);

	err = mk_clib_app_defrag_volume_open(defrag, &volume); mk_lang_check_rereturn(err);
	if(!mk_win_base_handle_is_invalid(volume))
	{
		err = mk_clib_app_defrag_find_hole_and_move(defrag, volume, file, vclusters, align);
		b = mk_win_kernel_handle_close_handle(volume); mk_lang_check_return(b != 0);
		mk_lang_check_rereturn(err);
	}
	else
	{
		gle = mk_win_kernel_errors_get_last();
		err = mk_clib_app_defrag_print_msg(defrag, &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_could_not_open_volume], s_mk_clib_app_defrag_str_len_could_not_open_volume); mk_lang_check_rereturn(err);
		err = mk_clib_app_defrag_print_gle(defrag, gle); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_file_get_details(mk_clib_app_defrag_pt const defrag, mk_win_base_handle_t const file, mk_lang_types_ullong_pt const vclusters_out, mk_lang_types_ullong_pt const fragments_out, mk_lang_types_sint_pt const align_out) mk_lang_noexcept
{
	#define s_invalid_lcn ((mk_win_base_ullong_t)(~((mk_win_base_ullong_t)(0))))
	#define s_vcns_store_len (4 * 1024)
	#define s_vcns_store_ali (4 * 1024)

	mk_win_base_ullong_t extents;
	mk_win_base_ullong_t vclusters;
	mk_win_base_ullong_t pclusters;
	mk_win_base_ullong_t fragments;
	mk_lang_types_sint_t align;
	mk_lang_types_bool_t bad;
	mk_win_base_large_integer_t prev_lcn;
	mk_win_kernel_communication_buf_fs_starting_vcn_t vcn_start;
	mk_win_kernel_communication_buf_fs_retrieval_pointers_pt vcns;
	mk_lang_types_uchar_t vcns_store[mk_lang_roundup_size(s_vcns_store_len, s_vcns_store_ali)];
	mk_win_base_bool_t b;
	mk_win_base_dword_t nwritten;
	mk_win_base_dword_t gle;
	mk_win_base_dword_t n;
	mk_win_base_large_integer_t curr_vcn;
	mk_win_base_dword_t i;
	mk_win_base_large_integer_t next_vcn;
	mk_win_base_large_integer_t curr_lcn;
	mk_win_base_ullong_t diff_vcn;
	mk_win_base_ullong_t last_pclusters_len;
	mk_lang_types_sint_t tsi;
	mk_lang_types_pchar_t msg[41 + 1];
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_win_base_handle_is_invalid(file));
	mk_lang_assert(vclusters_out);
	mk_lang_assert(fragments_out);
	mk_lang_assert(align_out);

	extents = 0;
	vclusters = 0;
	pclusters = 0;
	fragments = 1;
	align = -1;
	bad = mk_lang_false;
	prev_lcn.m_data.m_data_b = s_invalid_lcn;
	vcn_start.m_starting_vcn.m_data.m_data_b = 0;
	vcns = ((mk_win_kernel_communication_buf_fs_retrieval_pointers_pt)(mk_lang_roundup_align_ptr(&vcns_store[0], s_vcns_store_ali)));
	b = mk_win_kernel_communication_device_io_control(file, mk_win_kernel_communication_control_code_id_fs_get_retrieval_pointers, &vcn_start, ((mk_win_base_dword_t)(sizeof(vcn_start))), vcns, s_vcns_store_len, &nwritten, mk_win_base_null); gle = mk_win_kernel_errors_get_last();
	if(b != 0 || gle == ((mk_win_base_dword_t)(mk_win_kernel_errors_id_e_more_data)))
	{
		for(;;)
		{
			mk_lang_check_return(nwritten >= ((mk_win_base_dword_t)(sizeof(*vcns))) && nwritten <= ((mk_win_base_dword_t)(s_vcns_store_len)));
			mk_lang_check_return(vcns->m_starting_vcn.m_data.m_data_b == vcn_start.m_starting_vcn.m_data.m_data_b);
			mk_lang_check_return(vcns->m_extents_count >= 1);
			mk_lang_check_return(vcns->m_extents_count <= (nwritten - ((mk_win_base_dword_t)(mk_lang_offsetof(mk_win_kernel_communication_buf_fs_retrieval_pointers_t, m_extents)))) / ((mk_win_base_dword_t)(sizeof(vcns->m_extents[0]))));
			n = vcns->m_extents_count;
			extents += n;
			curr_vcn = vcn_start.m_starting_vcn;
			for(i = 0; i != n; ++i)
			{
				next_vcn = vcns->m_extents[i].m_next_vcn;
				curr_lcn = vcns->m_extents[i].m_lcn;
				mk_lang_check_return(next_vcn.m_data.m_data_b > curr_vcn.m_data.m_data_b);
				diff_vcn = next_vcn.m_data.m_data_b - curr_vcn.m_data.m_data_b;
				if(curr_lcn.m_data.m_data_b != s_invalid_lcn)
				{
					pclusters += diff_vcn;
					if(prev_lcn.m_data.m_data_b != s_invalid_lcn)
					{
						if(!(prev_lcn.m_data.m_data_b + last_pclusters_len == curr_lcn.m_data.m_data_b))
						{
							++fragments;
						}
					}
					if(align == -1)
					{
						align = ((mk_lang_types_sint_t)(((mk_lang_types_uint_t)(curr_lcn.m_data.m_data_b)) & 0xf));
					}
					prev_lcn = curr_lcn;
					last_pclusters_len = diff_vcn;
				}
				curr_vcn = next_vcn;
			}
			vclusters = vcns->m_extents[vcns->m_extents_count - 1].m_next_vcn.m_data.m_data_b;
			vcn_start.m_starting_vcn = vcns->m_extents[vcns->m_extents_count - 1].m_next_vcn;
			b = mk_win_kernel_communication_device_io_control(file, mk_win_kernel_communication_control_code_id_fs_get_retrieval_pointers, &vcn_start, ((mk_win_base_dword_t)(sizeof(vcn_start))), vcns,s_vcns_store_len, &nwritten, mk_win_base_null); gle = mk_win_kernel_errors_get_last();
			if(b != 0 || gle == ((mk_win_base_dword_t)(mk_win_kernel_errors_id_e_more_data)))
			{
			}
			else if(b == 0 && gle == ((mk_win_base_dword_t)(mk_win_kernel_errors_id_e_handle_eof)))
			{
				break;
			}
			else
			{
				err = mk_clib_app_defrag_print_msg(defrag, &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_could_not_get_extents_more], s_mk_clib_app_defrag_str_len_could_not_get_extents_more); mk_lang_check_rereturn(err);
				err = mk_clib_app_defrag_print_gle(defrag, gle); mk_lang_check_rereturn(err);
				bad = mk_lang_true;
				break;
			}
		}
	}
	else if(b == 0 && gle == ((mk_win_base_dword_t)(mk_win_kernel_errors_id_e_handle_eof)))
	{
		err = mk_clib_app_defrag_printn(defrag, ((mk_sl_cui_uint8_pct)(&s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_resident])), s_mk_clib_app_defrag_str_len_resident); mk_lang_check_rereturn(err);
		bad = mk_lang_true;
	}
	else
	{
		err = mk_clib_app_defrag_print_msg(defrag, &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_could_not_get_extents_info], s_mk_clib_app_defrag_str_len_could_not_get_extents_info); mk_lang_check_rereturn(err);
		err = mk_clib_app_defrag_print_gle(defrag, gle); mk_lang_check_rereturn(err);
		bad = mk_lang_true;
	}
	if(bad)
	{
		extents = 0;
		vclusters = 0;
		pclusters = 0;
		fragments = 0;
		align = -1;
	}
	else
	{
		tsi = mk_lib_fmt_n_snprintf(&msg[0], mk_lang_countof(msg), &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_extents]  , &extents  ); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countof(msg) - 1); err = mk_clib_app_defrag_printn(defrag, ((mk_sl_cui_uint8_pct)(&msg[0])), tsi); mk_lang_check_rereturn(err);
		tsi = mk_lib_fmt_n_snprintf(&msg[0], mk_lang_countof(msg), &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_vclusters], &vclusters); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countof(msg) - 1); err = mk_clib_app_defrag_printn(defrag, ((mk_sl_cui_uint8_pct)(&msg[0])), tsi); mk_lang_check_rereturn(err);
		tsi = mk_lib_fmt_n_snprintf(&msg[0], mk_lang_countof(msg), &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_pclusters], &pclusters); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countof(msg) - 1); err = mk_clib_app_defrag_printn(defrag, ((mk_sl_cui_uint8_pct)(&msg[0])), tsi); mk_lang_check_rereturn(err);
		tsi = mk_lib_fmt_n_snprintf(&msg[0], mk_lang_countof(msg), &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_fragments], &fragments); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countof(msg) - 1); err = mk_clib_app_defrag_printn(defrag, ((mk_sl_cui_uint8_pct)(&msg[0])), tsi); mk_lang_check_rereturn(err);
	}
	mk_lang_assert(fragments <= extents);
	mk_lang_assert(extents <= vclusters);
	mk_lang_assert(pclusters <= vclusters);
	*vclusters_out = ((mk_lang_types_ullong_t)(vclusters));
	*fragments_out = ((mk_lang_types_ullong_t)(fragments));
	*align_out = align;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_file_impl_2(mk_clib_app_defrag_pt const defrag, mk_win_base_handle_t const file) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_ullong_t vclusters;
	mk_lang_types_ullong_t fragments;
	mk_lang_types_sint_t align;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_win_base_handle_is_invalid(file));

	err = mk_clib_app_defrag_file_get_details(defrag, file, &vclusters, &fragments, &align); mk_lang_check_rereturn(err);
	if(fragments >= 2)
	{
		err = mk_clib_app_defrag_open_volume_find_hole_and_move(defrag, file, vclusters, align); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_drive_letter_adjust_impl(mk_win_base_wchar_pt const name, mk_lang_types_ushort_t const len) mk_lang_noexcept
{
	mk_lang_assert(name[0] != L'\0');
	mk_lang_assert(len >= 1);

	if(len == 6)
	{
		if
		(
			name[0] == L'\\' &&
			name[1] == L'\\' &&
			name[2] == L'?' &&
			name[3] == L'\\' &&
			((name[4] >= L'A' && name[4] <= L'Z') || (name[4] >= L'a' && name[4] <= L'z')) &&
			name[5] == L':' &&
			name[6] == L'\0'
		)
		{
			name[6] = L'\\';
			name[7] = L'\0';
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_drive_letter_adjust(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	err = mk_clib_app_defrag_drive_letter_adjust_impl(&defrag->m_curname_buf[0], defrag->m_curname_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_file_impl_1(mk_clib_app_defrag_pt const defrag, mk_win_base_handle_t const file) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_kernel_files_info_by_handle_t info;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_win_base_handle_is_invalid(file));

	b = mk_win_kernel_files_get_file_information_by_handle(file, &info); mk_lang_check_return(b != 0);
	defrag->m_is_dir = (info.m_attributes & mk_win_kernel_files_attribute_e_directory) != 0;
	if(defrag->m_is_dir)
	{
		err = mk_clib_app_defrag_printn(defrag, ((mk_sl_cui_uint8_pct)(&s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_fff_directory])), s_mk_clib_app_defrag_str_len_fff_directory); mk_lang_check_rereturn(err);
	}
	err = mk_clib_app_defrag_process_file_impl_2(defrag, file); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_file(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_handle_t file;
	mk_win_base_bool_t b;
	mk_win_base_dword_t gle;

	mk_lang_assert(defrag);
	mk_lang_assert(defrag->m_curname_buf[0] != L'\0');
	mk_lang_assert(defrag->m_curname_len >= 1);

	mk_lang_check_return(defrag->m_curname_len <= mk_clib_app_defrag_name_len_max - 1);
	defrag->m_curname_buf[defrag->m_curname_len] = L'\0';
	err = mk_clib_app_defrag_drive_letter_adjust(defrag); mk_lang_check_rereturn(err);
	file = mk_win_kernel_files_w_create_file(&defrag->m_curname_buf[0], ((mk_win_base_dword_t)(mk_win_advapi_base_right_specific_file_e_read_attributes)), ((mk_win_base_dword_t)(mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_write | mk_win_kernel_files_share_e_delete)), mk_win_base_null, ((mk_win_base_dword_t)(mk_win_kernel_files_create_e_open_existing)), ((mk_win_base_dword_t)(mk_win_kernel_files_attribute_e_normal)) | ((mk_win_base_dword_t)(mk_win_kernel_files_flag_e_backup_semantics)), mk_win_base_handle_null_g);
	defrag->m_opened = !mk_win_base_handle_is_invalid(file);
	if(!mk_win_base_handle_is_invalid(file))
	{
		err = mk_clib_app_defrag_process_file_impl_1(defrag, file);
		b = mk_win_kernel_handle_close_handle(file); mk_lang_check_return(b != 0);
		mk_lang_check_rereturn(err);
	}
	else
	{
		gle = mk_win_kernel_errors_get_last();
		err = mk_clib_app_defrag_print_msg(defrag, &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_could_not_open], s_mk_clib_app_defrag_str_len_could_not_open); mk_lang_check_rereturn(err);
		err = mk_clib_app_defrag_print_gle(defrag, gle); mk_lang_check_rereturn(err);
	}
	err = mk_clib_app_defrag_print_crlf(defrag); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_streams_impl_3(mk_clib_app_defrag_pt const defrag, mk_win_base_handle_t const file) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_win_base_handle_is_invalid(file));

	err = mk_clib_app_defrag_process_file_impl_1(defrag, file); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_streams_impl_2(mk_clib_app_defrag_pt const defrag, mk_win_kernel_files_w_stream_data_pt const fsd) mk_lang_noexcept
{
	mk_lang_types_usize_t lenus;
	mk_lang_types_ushort_t len;
	mk_lang_types_sint_t err;
	mk_win_base_handle_t file;
	mk_win_base_bool_t b;
	mk_win_base_dword_t gle;

	mk_lang_assert(defrag);
	mk_lang_assert(fsd);
	mk_lang_assert(mk_clib_app_defrag_memcmpwc_fn(&fsd->m_name[0], &s_mk_clib_app_defrag_ads_data[0], mk_lang_countof(s_mk_clib_app_defrag_ads_data)) != 0);

	lenus = mk_lang_strlen_w_fn(&fsd->m_name[0]); mk_lang_check_return(lenus <= mk_lang_limits_ushort_max); len = ((mk_lang_types_ushort_t)(lenus));
	mk_lang_check_return(defrag->m_curname_len + len <= mk_lang_countof(defrag->m_curname_buf) - 1);
	mk_clib_app_defrag_memcpywc_fn(&defrag->m_curname_buf[defrag->m_curname_len], &fsd->m_name[0], len);
	defrag->m_curname_len += len;
	err = mk_clib_app_defrag_print_currname(defrag); mk_lang_check_rereturn(err);
	defrag->m_curname_buf[defrag->m_curname_len] = L'\0';
	file = mk_win_kernel_files_w_create_file(&defrag->m_curname_buf[0], ((mk_win_base_dword_t)(mk_win_advapi_base_right_specific_file_e_read_attributes)), ((mk_win_base_dword_t)(mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_write | mk_win_kernel_files_share_e_delete)), mk_win_base_null, ((mk_win_base_dword_t)(mk_win_kernel_files_create_e_open_existing)), ((mk_win_base_dword_t)(mk_win_kernel_files_attribute_e_normal)) | ((mk_win_base_dword_t)(mk_win_kernel_files_flag_e_backup_semantics)), mk_win_base_handle_null_g);
	if(!mk_win_base_handle_is_invalid(file))
	{
		err = mk_clib_app_defrag_process_streams_impl_3(defrag, file);
		defrag->m_curname_len -= len;
		b = mk_win_kernel_handle_close_handle(file); mk_lang_check_return(b != 0);
		mk_lang_check_rereturn(err);
	}
	else
	{
		gle = mk_win_kernel_errors_get_last();
		err = mk_clib_app_defrag_print_msg(defrag, &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_could_not_open], s_mk_clib_app_defrag_str_len_could_not_open); mk_lang_check_rereturn(err);
		err = mk_clib_app_defrag_print_gle(defrag, gle); mk_lang_check_rereturn(err);
	}
	err = mk_clib_app_defrag_print_crlf(defrag); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_streams_impl_1(mk_clib_app_defrag_pt const defrag, mk_win_base_handle_t const ffs, mk_win_kernel_files_w_stream_data_pt const fsd) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_bool_t b;
	mk_win_base_dword_t gle;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_win_base_handle_is_invalid(ffs));
	mk_lang_assert(fsd);

	if(mk_clib_app_defrag_memcmpwc_fn(&fsd->m_name[0], &s_mk_clib_app_defrag_ads_data[0], mk_lang_countof(s_mk_clib_app_defrag_ads_data)) != 0)
	{
		err = mk_clib_app_defrag_process_streams_impl_2(defrag, fsd); mk_lang_check_rereturn(err);
	}
	for(;;)
	{
		b = mk_win_kernel_files_w_find_next_stream(ffs, fsd);
		if(b != 0)
		{
			err = mk_clib_app_defrag_process_streams_impl_2(defrag, fsd); mk_lang_check_rereturn(err);
		}
		else
		{
			gle = mk_win_kernel_errors_get_last();
			if(gle != ((mk_win_base_dword_t)(mk_win_kernel_errors_id_e_handle_eof)))
			{
				err = mk_clib_app_defrag_print_msg(defrag, &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_could_not_find_stream_next], s_mk_clib_app_defrag_str_len_could_not_find_stream_next); mk_lang_check_rereturn(err);
				err = mk_clib_app_defrag_print_gle(defrag, gle); mk_lang_check_rereturn(err);
			}
			break;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_streams(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_handle_t ffs;
	mk_win_kernel_files_w_stream_data_t fsd;
	mk_win_base_bool_t b;
	mk_win_base_dword_t gle;

	mk_lang_assert(defrag);
	mk_lang_assert(defrag->m_curname_buf[0] != L'\0');
	mk_lang_assert(defrag->m_curname_len >= 1);

	if(defrag->m_opened)
	{
		mk_lang_check_return(defrag->m_curname_len <= mk_clib_app_defrag_name_len_max - 1);
		defrag->m_curname_buf[defrag->m_curname_len] = L'\0';
		err = mk_clib_app_defrag_drive_letter_adjust(defrag); mk_lang_check_rereturn(err);
		ffs = mk_win_kernel_files_w_find_first_stream(&defrag->m_curname_buf[0], 0, &fsd, 0);
		if(!mk_win_base_handle_is_invalid(ffs))
		{
			err = mk_clib_app_defrag_process_streams_impl_1(defrag, ffs, &fsd);
			b = mk_win_kernel_files_find_close(ffs); mk_lang_check_return(b != 0);
			mk_lang_check_rereturn(err);
		}
		else
		{
			gle = mk_win_kernel_errors_get_last();
			if(gle == ((mk_win_base_dword_t)(mk_win_kernel_errors_id_e_handle_eof)))
			{
			}
			else if(gle == ((mk_win_base_dword_t)(mk_win_kernel_errors_id_e_invalid_parameter)))
			{
			}
			else
			{
				err = mk_clib_app_defrag_print_msg(defrag, &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_could_not_find_stream_first], s_mk_clib_app_defrag_str_len_could_not_find_stream_first); mk_lang_check_rereturn(err);
				err = mk_clib_app_defrag_print_gle(defrag, gle); mk_lang_check_rereturn(err);
				err = mk_clib_app_defrag_print_crlf(defrag); mk_lang_check_rereturn(err);
			}
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_file_and_streams(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	err = mk_clib_app_defrag_process_file(defrag); mk_lang_check_rereturn(err);
	err = mk_clib_app_defrag_process_streams(defrag); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_open_sub_file(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_clib_app_defrag_fff_t fff;
	mk_win_base_dword_t gle;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(defrag->m_curname_buf[0] != L'\0');
	mk_lang_assert(defrag->m_curname_len >= 1);

	if(defrag->m_opened && defrag->m_is_dir)
	{
		mk_lang_check_return(!mk_clib_app_defrag_fffs_ro_is_full(&defrag->m_fffs));
		mk_lang_check_return(defrag->m_curname_len <= mk_clib_app_defrag_name_len_max - 3);
		defrag->m_curname_buf[defrag->m_curname_len + 0] = L'\\';
		defrag->m_curname_buf[defrag->m_curname_len + 1] = L'*';
		defrag->m_curname_buf[defrag->m_curname_len + 2] = L'\0';
		fff.m_fff = mk_win_kernel_files_w_find_first_file(&defrag->m_curname_buf[0], &defrag->m_fd);
		if(!mk_win_base_handle_is_invalid(fff.m_fff))
		{
			fff.m_len = defrag->m_curname_len;
			mk_clib_app_defrag_fffs_rw_push_back_one(&defrag->m_fffs, &fff);
			defrag->m_just_opened_sub = mk_lang_true;
		}
		else
		{
			gle = mk_win_kernel_errors_get_last();
			err = mk_clib_app_defrag_print_msg(defrag, &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_could_not_enumerate], s_mk_clib_app_defrag_str_len_could_not_enumerate); mk_lang_check_rereturn(err);
			err = mk_clib_app_defrag_print_gle(defrag, gle); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_file_and_streams_and_open_sub_file(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	err = mk_clib_app_defrag_file_and_streams(defrag); mk_lang_check_rereturn(err);
	err = mk_clib_app_defrag_open_sub_file(defrag); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_nextsubfile_and_streams(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_clib_app_defrag_fff_pt fff;
	mk_lang_types_usize_t lenus;
	mk_lang_types_ushort_t len;
	mk_lang_types_ushort_t old_len;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_clib_app_defrag_fffs_ro_is_empty(&defrag->m_fffs));

	defrag->m_just_opened_sub = mk_lang_false;
	if
	(!(
		(defrag->m_fd.m_name[0] == L'.' && defrag->m_fd.m_name[1] == L'\0') ||
		(defrag->m_fd.m_name[0] == L'.' && defrag->m_fd.m_name[1] == L'.' && defrag->m_fd.m_name[2] == L'\0')
	))
	{
		fff = mk_clib_app_defrag_fffs_rw_back(&defrag->m_fffs); mk_lang_assert(fff);
		lenus = mk_lang_strlen_w_fn(defrag->m_fd.m_name); mk_lang_check_return(lenus >= 1 && lenus <= ((mk_lang_types_usize_t)(mk_lang_limits_ushort_max)));
		len = ((mk_lang_types_ushort_t)(lenus));
		mk_lang_check_return(fff->m_len + 1 + len <= mk_lang_countof(defrag->m_curname_buf));
		mk_clib_app_defrag_memcpywc_fn(&defrag->m_curname_buf[fff->m_len+ 1], &defrag->m_fd.m_name[0], len);
		old_len = defrag->m_curname_len;
		defrag->m_curname_len = ((mk_lang_types_ushort_t)(fff->m_len + 1 + len));
		err = mk_clib_app_defrag_print_currname(defrag); mk_lang_check_rereturn(err);
		if((defrag->m_fd.m_attributes & mk_win_kernel_files_attribute_e_reparse_point) == 0)
		{
			err = mk_clib_app_defrag_process_file_and_streams_and_open_sub_file(defrag);
			defrag->m_curname_len = old_len;
			mk_lang_check_rereturn(err);
		}
		else
		{
			err = mk_clib_app_defrag_printn(defrag, ((mk_sl_cui_uint8_pct)(&s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_fff_reparse])), s_mk_clib_app_defrag_str_len_fff_reparse); mk_lang_check_rereturn(err);
			err = mk_clib_app_defrag_print_crlf(defrag); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_next_sub_file(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;
	mk_clib_app_defrag_fff_pt fff;
	mk_win_base_bool_t b;
	mk_win_base_dword_t gle;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_clib_app_defrag_fffs_ro_is_empty(&defrag->m_fffs));

	if(!defrag->m_just_opened_sub)
	{
		gud = mk_lang_false;
		do
		{
			fff = mk_clib_app_defrag_fffs_rw_back(&defrag->m_fffs); mk_lang_assert(fff);
			if(!(mk_win_base_handle_is_invalid(fff->m_fff) && fff->m_len == 0))
			{
				b = mk_win_kernel_files_w_find_next_file(fff->m_fff, &defrag->m_fd);
				if(b != 0)
				{
					gud = mk_lang_true;
				}
				else
				{
					gle = mk_win_kernel_errors_get_last();
					if(gle != ((mk_win_base_dword_t)(mk_win_kernel_errors_id_e_no_more_files)))
					{
						err = mk_clib_app_defrag_print_msg(defrag, &s_mk_clib_app_defrag_str_all[s_mk_clib_app_defrag_str_off_could_not_enumerate_more], s_mk_clib_app_defrag_str_len_could_not_enumerate_more); mk_lang_check_rereturn(err);
						err = mk_clib_app_defrag_print_gle(defrag, gle); mk_lang_check_rereturn(err);
					}
					b = mk_win_kernel_files_find_close(fff->m_fff);
					mk_clib_app_defrag_fffs_rw_pop_back_one(&defrag->m_fffs);
					mk_lang_check_return(b != 0);
					mk_lang_assert(!mk_clib_app_defrag_fffs_ro_is_empty(&defrag->m_fffs));
				}
			}
			else
			{
				mk_clib_app_defrag_fffs_rw_pop_back_one(&defrag->m_fffs);
				mk_lang_assert(mk_clib_app_defrag_fffs_ro_is_empty(&defrag->m_fffs));
				gud = mk_lang_true;
			}
		}while(!gud);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_subfile_and_streams_and_next_sub_file(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	err = mk_clib_app_defrag_process_nextsubfile_and_streams(defrag); mk_lang_check_rereturn(err);
	err = mk_clib_app_defrag_next_sub_file(defrag); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_element(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_clib_app_defrag_fff_pt fff;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_clib_app_defrag_fffs_ro_is_empty(&defrag->m_fffs));

	fff = mk_clib_app_defrag_fffs_rw_back(&defrag->m_fffs); mk_lang_assert(fff);
	if(!(mk_win_base_handle_is_invalid(fff->m_fff) && fff->m_len == 0))
	{
		err = mk_clib_app_defrag_process_subfile_and_streams_and_next_sub_file(defrag); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_clib_app_defrag_fffs_rw_pop_back_one(&defrag->m_fffs);
		mk_lang_assert(mk_clib_app_defrag_fffs_ro_is_empty(&defrag->m_fffs));
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_append_dummy(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_clib_app_defrag_fff_t fff;

	mk_lang_assert(defrag);

	mk_lang_check_return(!mk_clib_app_defrag_fffs_ro_is_full(&defrag->m_fffs));
	fff.m_fff = mk_win_base_handle_get_invalid();
	fff.m_len = 0;
	mk_clib_app_defrag_fffs_rw_push_back_one(&defrag->m_fffs, &fff);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_all(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	err = mk_clib_app_defrag_append_dummy(defrag); mk_lang_check_rereturn(err);
	err = mk_clib_app_defrag_process_file_and_streams_and_open_sub_file(defrag); mk_lang_check_rereturn(err);
	while(!mk_clib_app_defrag_fffs_ro_is_empty(&defrag->m_fffs))
	{
		err = mk_clib_app_defrag_process_element(defrag); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_adjust_name_impl_2(mk_clib_app_defrag_pt const defrag, mk_win_base_handle_t const file_a, mk_win_base_handle_t const file_b, mk_win_base_wchar_pct const tmpname_buf, mk_lang_types_ushort_t const len) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_kernel_files_info_by_handle_t info_a;
	mk_win_kernel_files_info_by_handle_t info_b;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_win_base_handle_is_invalid(file_a));
	mk_lang_assert(!mk_win_base_handle_is_invalid(file_b));
	mk_lang_assert(file_a.m_data != file_b.m_data);
	mk_lang_assert(tmpname_buf);
	mk_lang_assert(len >= 1 && len <= mk_clib_app_defrag_name_len_max - 1);

	b = mk_win_kernel_files_get_file_information_by_handle(file_a, &info_a); mk_lang_check_return(b != 0);
	b = mk_win_kernel_files_get_file_information_by_handle(file_b, &info_b); mk_lang_check_return(b != 0);
	if
	(
		info_a.m_vol_ser_no == info_b.m_vol_ser_no &&
		info_a.m_index_lo == info_b.m_index_lo &&
		info_a.m_index_hi == info_b.m_index_hi
	)
	{
		mk_clib_app_defrag_memcpywc_fn(&defrag->m_curname_buf[0], &tmpname_buf[0], len);
		defrag->m_curname_len = len;
		if(defrag->m_curname_buf[defrag->m_curname_len - 1] == L'\\' || defrag->m_curname_buf[defrag->m_curname_len - 1] == L'/')
		{
			--defrag->m_curname_len;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_adjust_name_impl_1(mk_clib_app_defrag_pt const defrag, mk_win_base_handle_t const file_a) mk_lang_noexcept
{
	mk_win_base_dword_t lendw;
	mk_lang_types_ushort_t len;
	mk_win_base_handle_t file_b;
	mk_lang_types_sint_t err;
	mk_win_base_bool_t b;

	mk_lang_assert(defrag);
	mk_lang_assert(!mk_win_base_handle_is_invalid(file_a));

	lendw = mk_win_kernel_files_w_get_final_path_name_by_handle(file_a, &defrag->m_tmpname_buf[0], mk_lang_countof(defrag->m_tmpname_buf), ((mk_win_base_dword_t)(mk_win_kernel_files_file_name_e_normalized)) | ((mk_win_base_dword_t)(mk_win_kernel_files_volume_name_e_dos))); mk_lang_check_return(lendw != 0 && lendw >= 1 && lendw <= ((mk_win_base_dword_t)(mk_lang_limits_ushort_max)) && lendw <= mk_lang_countof(defrag->m_tmpname_buf));
	len = ((mk_lang_types_ushort_t)(lendw));
	mk_lang_check_return(len <= mk_lang_countof(defrag->m_tmpname_buf) - 1);
	defrag->m_tmpname_buf[len] = L'\0';
	file_b = mk_win_kernel_files_w_create_file(&defrag->m_tmpname_buf[0], ((mk_win_base_dword_t)(mk_win_advapi_base_right_specific_file_e_read_attributes)), ((mk_win_base_dword_t)(mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_write | mk_win_kernel_files_share_e_delete)), mk_win_base_null, ((mk_win_base_dword_t)(mk_win_kernel_files_create_e_open_existing)), ((mk_win_base_dword_t)(mk_win_kernel_files_attribute_e_normal)) | ((mk_win_base_dword_t)(mk_win_kernel_files_flag_e_backup_semantics)), mk_win_base_handle_null_g);
	if(!mk_win_base_handle_is_invalid(file_b))
	{
		err = mk_clib_app_defrag_adjust_name_impl_2(defrag, file_a, file_b, &defrag->m_tmpname_buf[0], len);
		b = mk_win_kernel_handle_close_handle(file_b); mk_lang_check_return(b != 0);
		mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_adjust_name(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_win_base_handle_t file_a;
	mk_lang_types_sint_t err;
	mk_win_base_bool_t b;

	mk_lang_assert(defrag);
	mk_lang_assert(defrag->m_curname_buf[0] != L'\0');
	mk_lang_assert(defrag->m_curname_len >= 1 && defrag->m_curname_len <= mk_lang_countof(defrag->m_curname_buf) - 1);

	defrag->m_curname_buf[defrag->m_curname_len] = L'\0';
	file_a = mk_win_kernel_files_w_create_file(&defrag->m_curname_buf[0], ((mk_win_base_dword_t)(mk_win_advapi_base_right_specific_file_e_read_attributes)), ((mk_win_base_dword_t)(mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_write | mk_win_kernel_files_share_e_delete)), mk_win_base_null, ((mk_win_base_dword_t)(mk_win_kernel_files_create_e_open_existing)), ((mk_win_base_dword_t)(mk_win_kernel_files_attribute_e_normal)) | ((mk_win_base_dword_t)(mk_win_kernel_files_flag_e_backup_semantics)), mk_win_base_handle_null_g);
	if(!mk_win_base_handle_is_invalid(file_a))
	{
		err = mk_clib_app_defrag_adjust_name_impl_1(defrag, file_a);
		b = mk_win_kernel_handle_close_handle(file_a); mk_lang_check_return(b != 0);
		mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_getcwd(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_win_base_dword_t len;

	mk_lang_assert(defrag);

	len = mk_win_kernel_files_w_get_current_directory(mk_lang_countof(defrag->m_curname_buf), &defrag->m_curname_buf[0]); mk_lang_check_return(len != 0 && len >= 1 && len <= ((mk_win_base_dword_t)(mk_lang_limits_ushort_max)) && len <= mk_lang_countof(defrag->m_curname_buf));
	if(defrag->m_curname_buf[len - 1] == L'\\' || defrag->m_curname_buf[len - 1] == L'/')
	{
		--len;
	}
	defrag->m_curname_len = ((mk_lang_types_ushort_t)(len));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_process_root(mk_clib_app_defrag_pt const defrag, mk_lang_types_wchar_pct const name_buf, mk_lang_types_usize_t const name_len) mk_lang_noexcept
{
	mk_lang_types_ushort_t len;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	if(!(!name_buf && name_len == 0))
	{
		mk_lang_check_return(name_len >= 1 && name_len <= ((mk_lang_types_usize_t)(mk_lang_countof(defrag->m_curname_buf))));
		len = ((mk_lang_types_ushort_t)(name_len));
		mk_clib_app_defrag_memcpywc_fn(&defrag->m_curname_buf[0], name_buf, len);
		defrag->m_curname_len = len;
	}
	else
	{
		err = mk_clib_app_defrag_getcwd(defrag); mk_lang_check_rereturn(err);
	}
	err = mk_clib_app_defrag_adjust_name(defrag); mk_lang_check_rereturn(err);
	err = mk_clib_app_defrag_print_currname(defrag); mk_lang_check_rereturn(err);
	err = mk_clib_app_defrag_process_all(defrag); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_enable_backup(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_luid_t backup;
	mk_win_advapi_security_token_privileges_t privs;
	mk_win_base_handle_t token;

	mk_lang_assert(defrag);

	((mk_lang_types_void_t)(defrag));
	b = mk_win_advapi_security_lookup_privilege_value_a(mk_win_base_null, mk_win_advapi_base_privilege_name_a_se_backup, &backup); mk_lang_check_return(b != 0);
	privs.m_count = 1;
	privs.m_privileges[0].m_luid = backup;
	privs.m_privileges[0].m_attributes = ((mk_win_base_dword_t)(mk_win_advapi_security_privilege_attribute_e_enabled));
	b = mk_win_advapi_security_open_process_token(mk_win_kernel_process_get_current(), ((mk_win_base_dword_t)(mk_win_advapi_base_right_specific_token_e_query | mk_win_advapi_base_right_specific_token_e_adjust_privileges)), &token); mk_lang_check_return(b != 0);
	b = mk_win_advapi_security_adjust_token_privileges(token, mk_win_base_false, &privs, 0, mk_win_base_null, mk_win_base_null); mk_lang_check_return(b != 0);
	b = mk_win_kernel_handle_close_handle(token); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_init(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_types_uchar_t tuc;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	mk_lang_cpuid_init();
	#if defined NDEBUG
	((mk_lang_types_void_t)(tuc));
	#else
	tuc = 0xff;
	mk_clib_app_defrag_memsetuc_fn(((mk_lang_types_uchar_pt)(defrag)), &tuc, sizeof(*defrag));;
	#endif
	mk_clib_app_defrag_fffs_rw_construct(&defrag->m_fffs);
	defrag->m_output = mk_win_base_handle_get_invalid();
	defrag->m_redirected = mk_lang_false;
	err = mk_clib_app_defrag_enable_backup(defrag); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_deinit(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	if(defrag->m_redirected)
	{
		err = mk_clib_app_defrag_buf_writer_flush(&defrag->m_buf_writer); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_run_argc_impl(mk_clib_app_defrag_pt const defrag, mk_lang_types_sint_t const argc, mk_lang_types_wchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	mk_lang_check_return(argc >= 1);
	mk_lang_check_return(argv);
	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_check_return(argv[i]);
		mk_lang_check_return(argv[i][0] != L'\0');
	}
	mk_lang_check_return(!argv[n]);
	if(argc == 1)
	{
		err = mk_clib_app_defrag_process_root(defrag, mk_lang_null, 0); mk_lang_check_rereturn(err);
	}
	else
	{
		for(i = 1; i != n; ++i)
		{
			err = mk_clib_app_defrag_process_root(defrag, argv[i], mk_lang_strlen_w_fn(argv[i])); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_run_argc(mk_clib_app_defrag_pt const defrag, mk_lang_types_sint_t const argc, mk_lang_types_wchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(defrag);

	err = mk_clib_app_defrag_init(defrag); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_defrag_run_argc_impl(defrag, argc, argv);
	err = mk_clib_app_defrag_deinit(defrag); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_defrag_run_cmdline(mk_clib_app_defrag_pt const defrag) mk_lang_noexcept
{
	mk_win_base_wchar_pct cmdline;
	mk_lang_types_bool_t first;
	mk_lang_types_bool_t at_least_one;
	mk_win_base_wchar_pct ptr;
	mk_win_base_wchar_pct arg;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;

	mk_lang_assert(defrag);

	cmdline = mk_win_kernel_process_get_command_line(); mk_lang_check_return(cmdline && cmdline[0] != L'\0');
	first = mk_lang_true;
	at_least_one = mk_lang_false;
	ptr = cmdline;
	for(;;)
	{
		while(ptr[0] == L' ')
		{
			++ptr;
		}
		if(ptr[0] == L'\0')
		{
			break;
		}
		if(ptr[0] == L'"')
		{
			arg = ptr + 1;
			do
			{
				++ptr;
			}while(ptr[0] != L'"' && ptr[0] != L'\0');
			len = ((mk_lang_types_sint_t)(((mk_lang_types_sintptr_t)(ptr - arg))));
			if(ptr[0] == L'"')
			{
				++ptr;
			}
		}
		else
		{
			arg = ptr;
			do
			{
				++ptr;
			}while(ptr[0] != L' ' && ptr[0] != L'\0');
			len = ((mk_lang_types_sint_t)(((mk_lang_types_sintptr_t)(ptr - arg))));
		}
		if(len == 0)
		{
			continue;
		}
		if(first)
		{
			first = mk_lang_false;
		}
		else
		{
			at_least_one = mk_lang_true;
			err = mk_clib_app_defrag_process_root(defrag, arg, len); mk_lang_check_rereturn(err);
		}
	}
	if(!at_least_one)
	{
		err = mk_clib_app_defrag_process_root(defrag, mk_lang_null, 0); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_defrag_arg(mk_lang_types_bool_t const wide, mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(wide == mk_lang_true);

	err = mk_clib_app_defrag_run_argc(&g_mk_clib_app_defrag, argc, ((mk_lang_types_wchar_pcpct)(argv))); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_defrag_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_clib_app_defrag_pt defrag;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(peb);

	defrag = &g_mk_clib_app_defrag;
	err = mk_clib_app_defrag_init(defrag); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_defrag_run_cmdline(defrag);
	err = mk_clib_app_defrag_deinit(defrag); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}
