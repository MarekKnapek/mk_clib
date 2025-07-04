define(`mk_mm_strings_include_guard'









include(`mk_mm_concat.m')dnl
define(`mk_mm_strings_pr_nl', `
')dnl
define(`mk_mm_symbol_quote_beg', changequote(`[', `]')[changequote(`[', `]')[`]changequote([`], ['])]changequote([`], [']))dnl
define(`mk_mm_symbol_quote_end', changequote(`[', `]')[changequote(`[', `]')[']changequote([`], ['])]changequote([`], [']))dnl
define(`mk_mm_shift4', `shift(shift(shift(shift($@))))')dnl
define(`mk_mm_strings_pr_per_pair_a', `define(`mm_x', ``$1'')`'mm_x(`$2', `$3', `$4')`'mk_mm_strings_pr_nl`'undefine(`mm_x')')dnl
define(`mk_mm_strings_pr_per_pair', `mk_mm_strings_pr_per_pair_a($@)`'ifelse(eval(`$# >= 6'), `1', `$0(`$1', `$2', mk_mm_shift4($@))', `')')dnl
define(`mk_mm_strings_make_header',
`#ifndef 'mk_mm_concat(`mk_include_guard_', `$1')`_h'
`#define 'mk_mm_concat(`mk_include_guard_', `$1')`_h'
`'
`'
mk_mm_strings_pr_per_pair(`#define $1_def_$2 "$3"', `$1', `get', `GET', `post', `POST', `head', `HEAD')dnl
dnl mk_mm_strings_pr_per_pair(`#define $1_def_$2 "$3"', `$1', `$2', `$3', `$4', `$5', `$6', `$7')dnl
mk_mm_strings_pr_per_pair(`#define $1_def_$2 "$3"', `$1', mk_mm_args(`$#'))dnl
`'
`'
`#endif'
)dnl
