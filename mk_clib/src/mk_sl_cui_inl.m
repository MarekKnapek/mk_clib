define(`mm_per_bi_nobool',
`define(`mm_x', ``$1'')mm_x(`pchar')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`uchar')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`schar')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`ushort')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`sshort')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`uint')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`sint')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`ulong')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`slong')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`ullong')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`sllong')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`ulllong')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`slllong')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`uintptr')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`sintptr')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`uintmax')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`sintmax')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`usize')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`ssize')undefine(`mm_x')')dnl
define(`mm_per_bi',
`define(`mm_x', ``$1'')mm_x(`bool')undefine(`mm_x')'
`mm_per_bi_nobool(`$1')')dnl
define(`mm_per_bui',
`define(`mm_x', ``$1'')mm_x(`uchar')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`ushort')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`uint')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`ulong')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`ullong')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`ulllong')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`uintptr')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`uintmax')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`usize')undefine(`mm_x')')dnl
define(`mm_per_bsi',
`define(`mm_x', ``$1'')mm_x(`schar')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`sshort')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`sint')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`slong')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`sllong')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`slllong')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`sintptr')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`sintmax')undefine(`mm_x')'
`define(`mm_x', ``$1'')mm_x(`ssize')undefine(`mm_x')')dnl
