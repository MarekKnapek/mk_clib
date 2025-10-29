include(`mk_mm_strings.m')dnl
include(`mk_lib_app_cryptor_mode_stream.m')dnl
mk_mm_strings_generate_header(`mk_lib_app_cryptor_mode_stream_names', mk_lib_app_cryptor_mode_stream_mm_for_all(`$1_$3, $2-$4, '))dnl
