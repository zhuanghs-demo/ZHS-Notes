@ echo off

set LOCALPATH=%CD%\
set BUILDFOLDER=build\
set LIBFOLDER=lib\

if exist %LOCALPATH%%BUILDFOLDER% (
    rem  Current path has exist build folder
    echo Folder %LOCALPATH%%BUILDFOLDER% has exist
) else (
    rem  Create build folder on current path 
    echo Create %LOCALPATH%%BUILDFOLDER%
    md   %LOCALPATH%%BUILDFOLDER%
)

if exist %LOCALPATH%%LIBFOLDER% (
    rem  Current path has exist build folder
    echo Folder %LOCALPATH%%LIBFOLDER% has exist
) else (
    rem  Create build folder on current path 
    echo Create %LOCALPATH%%LIBFOLDER%
    md   %LOCALPATH%%LIBFOLDER%
)

cd build\
cmake -G"MinGW Makefiles" ../
mingw32-make