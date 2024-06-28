tcc -impdef kernel32.dll && ^
tcc -impdef ktmw32.dll && ^
tcc -O2 -DNDEBUG -D_WIN32_WINNT=0x0601 ^
..\..\app\mkvc.c ^
kernel32.def ^
ktmw32.def
