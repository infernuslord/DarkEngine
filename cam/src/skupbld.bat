rem $Header: r:/t2repos/thief2/src/skupbld.bat,v 1.25 1999/11/29 19:34:26 adurant Exp $
rem actually do the builds

if "%1x"=="rebuildx" goto build

rem Copy over all of the source files
rem Make sure you update skupcopy if adding new source subdirectories
co skupcopy.bat
@echo Skupcopy running
call skupcopy

:build

if "%BASE%"=="" set BASE=r
if "%PRJDIR%"=="" set PRJDIR=cam
if "%COMPVER%"=="" set COMPVER=v50
set _TARG=%TARG%
set _BASE=%BASE%:\prj\%PRJDIR%
set _NEWREL=%_BASE%\release

rem use the frozen tech libs
rem no, dont!
rem call st

rm %EDEXE% %EDMAP% %DBGEDPDB%
rm %DBGEDEXE%
touch dialogs.rc

if "%1h"=="wath" goto wat
if "%1h"=="opth" goto opt

rem SKUPBLD - about to do a build, switch to the project's sandbox.
rem set didpush=1
rem pushdir
%BASE%:
@echo %BASE%:
cd %_BASE%\skup\%PRJDIR%\src
@echo cd %_BASE%\skup\%PRJDIR%\src

@echo make build %_TARG% FLAV=dbg MASTER=editdbg SB=%BASE%:\prj\%PRJDIR%\skup comp=%COMPVER% sys=win32 PORTAL_DBG=1
make build %_TARG% FLAV=dbg MASTER=editdbg SB=%BASE%:\prj\%PRJDIR%\skup comp=%COMPVER% sys=win32 PORTAL_DBG=1
rem wdw=wdw
if "%1h"=="buildh" goto opt
move %DBGEDEXE% %_NEWREL%\%DBGEDEXE%
rem this map file doesnt get build by msvc debug with default settings
rem copy dromed.map %_NEWREL%\dbgdrom.map
copy %DBGEDPDB% %_NEWREL%\%DBGEDPDB%
if "%1h"=="dbgh" goto out
:opt

make build %_TARG% FLAV=opt MASTER=editprof SB=%BASE%:\prj\%PRJDIR%\skup comp=%COMPVER% sys=win32
if "%1h"=="buildh" goto wat
rm %EDMAP%
move %EDEXE% %_NEWREL%\%EDEXE%
copy %EDMAP% %_NEWREL%\%EDMAP%
if "%1h"=="opth" goto out

if "%1h"=="nowath" goto out
rem And for now, in the land of hacks, since watcom wont build anyway
goto out

:wat
rem msvc doesn't like watcom res files
make build %_TARG% FLAV=opt MASTER=editprof SB=%BASE%:\prj\%PRJDIR%\skup comp=w106 sys=win32
if "%1h"=="buildh" goto out
rm %EDMAP%
move %EDEXE% %_NEWREL%\watdrom.exe
copy %EDMAP% %_NEWREL%\watdrom.map
:out
rem if "%didpush%"==1 popdir
rem didpush=
