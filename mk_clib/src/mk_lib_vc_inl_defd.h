#include "mk_lang_concat.h"


#define mk_lib_vc_inl_defd_name mk_lib_vc_t_name
#define mk_lib_vc_inl_defd_reader mk_lib_vc_t_reader
#define mk_lib_vc_inl_defd_writer mk_lib_vc_t_writer

#define mk_lib_vc_inl_defd_prefix mk_lang_concat(mk_lib_vc_, mk_lib_vc_inl_defd_name)

#define mk_lib_vc_inl_defd_decrypt mk_lang_concat(mk_lib_vc_inl_defd_prefix, _decrypt)

#define mk_lib_vc_inl_defd_reader_helper_s mk_lang_concat(mk_lib_vc_inl_defd_prefix, _reader_helper_s)
#define mk_lib_vc_inl_defd_reader_helper_t mk_lang_concat(mk_lib_vc_inl_defd_prefix, _reader_helper_t)
#define mk_lib_vc_inl_defd_reader_helper_ct mk_lang_concat(mk_lib_vc_inl_defd_prefix, _reader_helper_ct)
#define mk_lib_vc_inl_defd_reader_helper_pt mk_lang_concat(mk_lib_vc_inl_defd_prefix, _reader_helper_pt)
#define mk_lib_vc_inl_defd_reader_helper_pct mk_lang_concat(mk_lib_vc_inl_defd_prefix, _reader_helper_pct)
#define mk_lib_vc_inl_defd_reader_helper_read mk_lang_concat(mk_lib_vc_inl_defd_prefix, _reader_helper_read)

#define mk_lib_vc_inl_defd_reader_t mk_lang_concat(mk_lib_vc_inl_defd_reader, _t)
#define mk_lib_vc_inl_defd_reader_ct mk_lang_concat(mk_lib_vc_inl_defd_reader, _ct)
#define mk_lib_vc_inl_defd_reader_pt mk_lang_concat(mk_lib_vc_inl_defd_reader, _pt)
#define mk_lib_vc_inl_defd_reader_pct mk_lang_concat(mk_lib_vc_inl_defd_reader, _pct)
#define mk_lib_vc_inl_defd_reader_seek_pt mk_lang_concat(mk_lib_vc_inl_defd_reader, _seek_pt)
#define mk_lib_vc_inl_defd_reader_seek mk_lang_concat(mk_lib_vc_inl_defd_reader, _seek)
#define mk_lib_vc_inl_defd_reader_read_pt mk_lang_concat(mk_lib_vc_inl_defd_reader, _read_pt)
#define mk_lib_vc_inl_defd_reader_read mk_lang_concat(mk_lib_vc_inl_defd_reader, _read)

#define mk_lib_vc_inl_defd_writer_t mk_lang_concat(mk_lib_vc_inl_defd_writer, _t)
#define mk_lib_vc_inl_defd_writer_ct mk_lang_concat(mk_lib_vc_inl_defd_writer, _ct)
#define mk_lib_vc_inl_defd_writer_pt mk_lang_concat(mk_lib_vc_inl_defd_writer, _pt)
#define mk_lib_vc_inl_defd_writer_pct mk_lang_concat(mk_lib_vc_inl_defd_writer, _pct)
#define mk_lib_vc_inl_defd_writer_write_pt mk_lang_concat(mk_lib_vc_inl_defd_writer, _write_pt)
#define mk_lib_vc_inl_defd_writer_write mk_lang_concat(mk_lib_vc_inl_defd_writer, _write)
