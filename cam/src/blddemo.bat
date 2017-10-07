@rem $Header: r:/t2repos/thief2/src/blddemo.bat,v 1.3 1998/06/24 00:32:41 mahk Exp $
set _PRJDRV_=r:
set _PRJ_=%_PRJDRV_%\prj\cam
set _DEMO_=%_PRJ_%\demo\thief


xcopy %_PRJ_%\release\*.* %_DEMO_%\*.*
xcopy %_PRJ_%\levels\shipping\*.mis %_DEMO_%\*.*
xcopy %_PRJ_%\levels\shipping\*.gam %_DEMO_%\*.*
xcopy %_PRJ_%\scripts\osm %_DEMO_%\*.*

set _FINALS_=%_PRJ_%\art\finals
%_PRJDRV_%
cd %_FINALS_%
call getneed %_DEMO_%

rem xcopy %_FINALS_%\Briefings\*.avi %_DEMO_%\*.*  /d
rem xcopy %_FINALS_%\Cutscenes\*.avi %_DEMO_%\*.*  /d

cd %_DEMO_%\obj
del *.3ds
cd %_DEMO_%\mesh
del *.exe 
cd %_DEMO_%

set _FINALS_=
set _DEMO_=
set _PRJ_=
set _PRJDRV_= 






