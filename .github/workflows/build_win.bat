curl -L -o m4-dep.zip http://downloads.sourceforge.net/gnuwin32/m4-1.4.14-1-dep.zip
curl -L -o m4-1.4.14-1-bin.zip http://downloads.sourceforge.net/gnuwin32/m4-1.4.14-1-bin.zip
7z e m4-dep.zip
7z e m4-1.4.14-1-bin.zip
set path=%path%;%cd%
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Release|x64" /Project mkch /ProjectConfig "Release|x64" /Out "mkch.txt"
