rem @echo off
set EDMAP=deepced.map
set DBGEDPDB=dbgdeepc.pdb
set TARG=deepc
set EDEXE=deepced.exe
set DBGEDEXE=dbgdeepc.exe
set COPYBAT=skupdpc2.bat
set BASE=u
set PRJDIR=deepc
set COMPVER=v60
skup %1 %2 %3 %4 %5 %6 %7 %8 %9
rem clean up our env mess.
set EDMAP=
set DBGEDPDB=
set TARG=
set EDEXE=
set DBGEDEXE=
set COPYBAT=
set BASE=
set PRJDIR=
set COMPVER=


