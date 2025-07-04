define(`mk_lib_iip_http_strings_pr_nl', `
')dnl
define(`mk_lib_iip_http_strings_per_string_beg', `define(`mm_x', ``$1'')`'mm_x(`$2', `$3', `$4', `$5')`'mk_lib_iip_http_strings_pr_nl`'undefine(`mm_x')')dnl
define(`mk_lib_iip_http_strings_per_string_main', `define(`mm_x', ``$1'')`'mm_x(`$2', `$3', `$4', `$5', `$6', `$7')`'mk_lib_iip_http_strings_pr_nl`'undefine(`mm_x')')dnl
define(`mk_lib_iip_http_strings_per_string_end', `define(`mm_x', ``$1'')`'mm_x(`$2', `$3', `$4', `$5')`'mk_lib_iip_http_strings_pr_nl`'undefine(`mm_x')')dnl
define(`mk_lib_iip_http_strings_per_string_mid', `ifelse(eval(`$# > 3+3*2'), `1', `mk_lib_iip_http_strings_per_string_main(`$2', `$6', `$7', `$4', `$5', `$8', `$9')`'$0(`$1', `$2', `$3', shift(shift(shift(shift(shift($@))))))', `mk_lib_iip_http_strings_per_string_end(`$3', `$6', `$7', `$4', `$5')')')dnl
define(`mk_lib_iip_http_strings_per_string_impl_main', `mk_lib_iip_http_strings_per_string_beg(`$1', `$4', `$5', `$6', `$7')`'mk_lib_iip_http_strings_per_string_mid($@)')dnl
define(`mk_lib_iip_http_strings_per_string_impl_check_end', `ifelse(`$3', `', `mk_lib_iip_http_strings_per_string_impl_main(`$1', `$2', `$2', shift(shift(shift($@))))', `mk_lib_iip_http_strings_per_string_impl_main($@)')')dnl
define(`mk_lib_iip_http_strings_per_string_impl_check_beg', `ifelse(`$1', `', `mk_lib_iip_http_strings_per_string_impl_check_end(`$2', `$2', shift(shift($@)))', `mk_lib_iip_http_strings_per_string_impl_check_end($@)')')dnl
define(`mk_lib_iip_http_strings_per_string', `mk_lib_iip_http_strings_per_string_impl_check_beg(`$1', `$2', `$3',
`connect', `CONNECT',
`delete', `DELETE',
`get', `GET',
`head', `HEAD',
`options', `OPTIONS',
`post', `POST',
`put', `PUT',
`trace', `TRACE',
`version_1_1', `HTTP/1.1\x0d\x0a',
`', `')')dnl
