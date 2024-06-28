tcc -impdef kernel32.dll && ^
tcc -impdef advapi32.dll && ^
tcc -O2 -DNDEBUG -D_WIN32_WINNT=0x0601 ^
..\..\app\mkdefrag.c ^
kernel32.def ^
advapi32.def
