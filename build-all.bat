@ECHO OFF
REM Build script for cleaning and/or building everything

SET PLATFORM=%1
SET ACTION=%2
SET TARGET=%3

if "%ACTION%" == "build" (
    SET ACTION=all
    SET ACTION_STR=Building
    SET ACTION_STR_PAST=built
    SET DO_VERSION=no
) else (
    if "%ACTION%" == "clean" (
        SET ACTION=clean
        SET ACTION_STR=Cleaning
        SET ACTION_STR_PAST=cleaned
        SET DO_VERSION=no
    ) else (
        echo "Unknown action %ACTION%. Aborting" && exit
    )
)

DEL bin\*.pdb

ECHO "%ACTION_STR% everything on %PLATFORM% (%TARGET%)..."

REM Engine
make -f "Makefile.library.mak" %ACTION% TARGET=%TARGET% ASSEMBLY=dih COMPILED_NAME=dihlib VER_MAJOR=0 VER_MINOR=3 DO_VERSION=%DO_VERSION%
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

REM Testbed
make -f "Makefile.executable.mak" %ACTION% TARGET=%TARGET% ASSEMBLY=dihi COMPILED_NAME=dihi ADDL_INC_FLAGS="-Idih/src" ADDL_LINK_FLAGS="-ldihlib"
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

ECHO "All assemblies %ACTION_STR_PAST% successfully."