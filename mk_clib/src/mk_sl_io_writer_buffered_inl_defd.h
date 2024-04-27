#include "mk_lang_concat.h"


#if(!( \
	(defined mk_sl_io_writer_buffered_t_name) && \
	(defined mk_sl_io_writer_buffered_t_base) && \
	1))
#error xxxxxxxxxx
#endif


#define mk_sl_io_writer_buffered_inl_defd_name mk_sl_io_writer_buffered_t_name
#define mk_sl_io_writer_buffered_inl_defd_base mk_sl_io_writer_buffered_t_base

#define mk_sl_io_writer_buffered_inl_defd_base_t mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_base, _t)
#define mk_sl_io_writer_buffered_inl_defd_base_pt mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_base, _pt)
#define mk_sl_io_writer_buffered_inl_defd_base_write mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_base, _write)

#define mk_sl_io_writer_buffered_inl_defd_s mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_name, _s)
#define mk_sl_io_writer_buffered_inl_defd_t mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_name, _t)
#define mk_sl_io_writer_buffered_inl_defd_ct mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_name, _ct)
#define mk_sl_io_writer_buffered_inl_defd_pt mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_name, _pt)
#define mk_sl_io_writer_buffered_inl_defd_prt mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_name, _prt)
#define mk_sl_io_writer_buffered_inl_defd_pct mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_name, _pct)
#define mk_sl_io_writer_buffered_inl_defd_prct mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_name, _prct)

#define mk_sl_io_writer_buffered_inl_defd_init mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_name, _init)
#define mk_sl_io_writer_buffered_inl_defd_write mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_name, _write)
#define mk_sl_io_writer_buffered_inl_defd_flush mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_name, _flush)
