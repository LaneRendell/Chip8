@echo off

set CommonCompilerFlags=-MTd -nologo -fp:fast -Gm- -GR- -EHa- -Od -Oi -WX -W4 -wd4456 -wd4201 -wd4715 -wd4100 -wd4189 -wd4505 -wd4996 -FC -Z7
set CommonLinkerFlags= -incremental:no -opt:ref /SUBSYSTEM:CONSOLE SDL2main.lib SDL2.lib

IF NOT EXIST ..\..\build mkdir ..\..\build
pushd ..\..\build

cl %CommonCompilerFlags% ..\code\ch8.c -Fmch8.map /link %CommonLinkerFlags%
popd