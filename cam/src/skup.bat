rem $Header: r:/t2repos/thief2/src/skup.bat,v 1.35 1999/11/09 19:21:35 BODISAFA Exp $
rem Skup a Dark exe!
rem @echo off

rem Misc saveoff of possible config environment conflicts
set _OLDRC=%NORC%
set _OLDCLEANOLD=%NOCLEANOLD%
set _OLDNOMAP=%NOMAP%
set NOMAP=NOMAP
set NORC=
set NOCLEANOLD=

rem setup the exe paths
if "%EDEXE%"=="" set EDEXE=dromed.exe
if "%EDMAP%"=="" set EDEXE=dromed.map
if "%DBGEDEXE%"=="" set DBGEDEXE=dbgdrom.exe
if "%DBGEDPDB%"=="" set DBGEDPDB=dbgdrom.pdb
if "%COPYBAT%"=="" set COPYBAT=skupdark.bat
if "%BASE%"=="" set BASE=r
if "%PRJDIR%"=="" set PRJDIR=cam

rem Our real environment for the batch process
set _TARG=%TARG%
set _BASE=%BASE%:\prj\%PRJDIR%
set _OLDNAME=lastrel
set _OLDREL=%_BASE%\%_OLDNAME%
set _NEWREL=%_BASE%\release

if "%1a"=="reskupa" goto reskup_only
@echo Full release... Removing directory %_OLDREL%
del %_OLDREL%\*.*
rmdir %_OLDREL%
copy cam.cfg %_OLDREL%\cam.cfg
if exist %_OLDREL%\cam.cfg goto dir_fail
rendir %_NEWREL% %_OLDNAME%

:reskup_only
mkdir %_NEWREL%

@echo Lets Go....
@echo %BASE%:
%BASE%:
@echo %_BASE%\skup\%PRJDIR%\src
cd %_BASE%\skup\%PRJDIR%\src
if "%TARG%"=="deepc" pause
co skupbld.bat
call skupbld

@echo Copy It Over....
cd %_BASE%\src
copy *.cfg %_NEWREL%
rem blast the prog.cfg so that no one but programmers sees it.
rm %_NEWREL%\prog.cfg
copy *.bnd %_NEWREL%
copy *.cmd %_NEWREL%
copy *.cm& %_NEWREL%
copy csgmerge.exe %_NEWREL%
copy ..\bin\darkdlgs.dll %_NEWREL%
copy ..\bin\mottable.dll %_NEWREL%
copy ..\bin\qmixer.dll %_NEWREL%

rem echo xcopy x:\prj\tech\h\*.h %_BASE%\scripts\rel_h /q
rem xcopy x:\prj\tech\h\*.h %_BASE%\scripts\rel_h /q

rem echo xcopy %_BASE%\h\*.h %_BASE%\scripts\rel_h /q
rem xcopy %_BASE%\h\*.h %_BASE%\scripts\rel_h /q

rem echo xcopy %_BASE%\src\*.h %_BASE%\scripts\rel_h /q
rem xcopy %_BASE%\src\*.h %_BASE%\scripts\rel_h /q

rem echo xcopy %_BASE%\src\ai\*.h %_BASE%\scripts\rel_h /q
rem xcopy %_BASE%\src\ai\*.h %_BASE%\scripts\rel_h /q

rem echo xcopy %_BASE%\src\dark\*.h %_BASE%\scripts\rel_h /q
rem xcopy %_BASE%\src\dark\*.h %_BASE%\scripts\rel_h /q

rem echo xcopy %_BASE%\src\shock\*.h %_BASE%\scripts\rel_h /q
rem xcopy %_BASE%\src\shock\*.h %_BASE%\scripts\rel_h /q

rem echo xcopy %_BASE%\src\physics\*.h %_BASE%\scripts\rel_h /q
rem xcopy %_BASE%\src\physics\*.h %_BASE%\scripts\rel_h /q

rem echo xcopy %_BASE%\src\motion\*.h %_BASE%\scripts\rel_h /q
rem xcopy %_BASE%\src\motion\*.h %_BASE%\scripts\rel_h /q

rem echo xcopy %_BASE%\src\editor\*.h %_BASE%\scripts\rel_h /q
rem xcopy %_BASE%\src\editor\*.h %_BASE%\scripts\rel_h /q

rem echo xcopy %_BASE%\src\csg\*.h %_BASE%\scripts\rel_h /q
rem xcopy %_BASE%\src\csg\*.h %_BASE%\scripts\rel_h /q

echo Running Rel_H Update
%BASE%:
cd %_BASE%\scripts\rel_h
call update.bat
cd %_BASE%\src

copy data\*.res %_NEWREL%

rem copy stuff over into thief2\release
call %COPYBAT%

if exist %_NEWREL%\%EDEXE% goto got_drom
goto missing_exe
:got_drom
if exist %_NEWREL%\%DBGEDEXE% goto got_dbgd
goto missing_exe
:got_dbgd
rem if exist %_NEWREL%\watdrom.exe goto got_wat
rem goto missing_exe
:got_wat
goto it_worked

:missing_exe
@echo A .EXE is missing!!! warning! Danger Will Robinson
goto we_failed
:dir_fail
@echo Directory zaniness failure
goto we_failed
:we_failed
@echo Booooo
goto ending

:it_worked
@echo Yea

:ending
rem Misc restore of env variables
set NOMAP=%_OLDNOMAP%
set NORC=%_OLDRC%
set NOCLEANOLD=%_OLDCLEANOLD%
set _OLDRC=
set _OLDCLEANOLD=
set _OLDNOMAP=

rem cleanup of our real env vars
set BASE=
set PRJDIR=
set _BASE=
set _OLDREL=
set _NEWREL=
set _OLDNAME=
set _TARG=
