# Microsoft Developer Studio Project File - Name="sound" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=sound - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "sound.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "sound.mak" CFG="sound - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "sound - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "sound - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "sound - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\_Libs\Release"
# PROP Intermediate_Dir "..\_Bins\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /Zp1 /MT /W3 /GX /O2 /I "." /I "..\..\h" /I "..\lg" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\comtools" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I "..\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /I "..\..\..\3rdsrc\Qmix413" /I "..\..\..\3rdsrc\Aureal3d" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "SHIP" /FR /YX"..\..\types.h" /FI "..\..\h\types.h" /c
# SUBTRACT CPP /X /u
# ADD BASE RSC /l 0x816 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\_Libs\Debug"
# PROP Intermediate_Dir "..\_Bins\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_WIN32" /D "_WINDOWS" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /Zp1 /ML /W3 /Gm /GX /ZI /Od /I "." /I "..\..\h" /I "..\lg" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\comtools" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I "..\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /I "..\..\..\3rdsrc\Qmix413" /I "..\..\..\3rdsrc\Aureal3d" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_WINDOWS" /YX"..\..\types.h" /FD /FI /GZ "..\..\h\types.h" /c
# ADD BASE RSC /l 0x816 /d "_DEBUG"
# ADD RSC /l 0x816 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "sound - Win32 Release"
# Name "sound - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\dmixer.cpp
DEP_CPP_DMIXE=\
	"..\..\..\3rdsrc\Aureal3d\ia3d.h"\
	"..\..\..\3rdsrc\Qmix413\qmixer.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\comtools.h"\
	"..\cpptools\dynfunc.h"\
	"..\dispdev\wdispapi.h"\
	"..\dispdev\wdspguid.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\mprintf\mprintf.h"\
	"..\timer\timer.h"\
	".\dlgsndi.h"\
	".\dsnddynf.h"\
	".\lgsndi.h"\
	".\lgsndid.h"\
	".\lgsound.h"\
	".\mixerlck.h"\
	".\timelog.h"\
	
NODEP_CPP_DMIXE=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dsample.cpp
DEP_CPP_DSAMP=\
	"..\..\..\3rdsrc\Qmix413\qmixer.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\timer\timer.h"\
	".\dlgsndi.h"\
	".\lgsndi.h"\
	".\lgsndid.h"\
	".\lgsound.h"\
	".\mixerlck.h"\
	".\timelog.h"\
	
NODEP_CPP_DSAMP=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dsnddynf.cpp
DEP_CPP_DSNDD=\
	"..\cpptools\dynfunc.h"\
	".\dsnddynf.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fade.cpp
DEP_CPP_FADE_=\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\timer\timer.h"\
	".\lgsndi.h"\
	".\lgsndid.h"\
	".\lgsound.h"\
	".\timelog.h"\
	
NODEP_CPP_FADE_=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lgsndid.cpp
DEP_CPP_LGSND=\
	"..\comtools\comtools.h"\
	".\lgsndid.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\midiplay.cpp
DEP_CPP_MIDIP=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\cpptools\dynfunc.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\lgsndid.h"\
	".\midiplay.h"\
	".\midplayi.h"\
	".\wail.h"\
	".\waildynf.h"\
	
NODEP_CPP_MIDIP=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mixer.cpp
DEP_CPP_MIXER=\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\comtools.h"\
	"..\cpptools\dynfunc.h"\
	"..\dispdev\wdispapi.h"\
	"..\dispdev\wdspguid.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\timer\timer.h"\
	".\dsnddynf.h"\
	".\lgsndi.h"\
	".\lgsndid.h"\
	".\lgsound.h"\
	".\mixerlck.h"\
	".\timelog.h"\
	
NODEP_CPP_MIXER=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\qmixer.cpp
DEP_CPP_QMIXE=\
	"..\..\..\3rdsrc\Qmix413\qmixer.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\comtools.h"\
	"..\dispdev\wdispapi.h"\
	"..\dispdev\wdspguid.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\mprintf\mprintf.h"\
	"..\timer\timer.h"\
	".\lgsndi.h"\
	".\lgsndid.h"\
	".\lgsound.h"\
	".\mixerlck.h"\
	".\qlgsndi.h"\
	".\timelog.h"\
	
NODEP_CPP_QMIXE=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\qsample.cpp
DEP_CPP_QSAMP=\
	"..\..\..\3rdsrc\Qmix413\qmixer.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\timer\timer.h"\
	".\lgsndi.h"\
	".\lgsndid.h"\
	".\lgsound.h"\
	".\mixerlck.h"\
	".\qlgsndi.h"\
	".\timelog.h"\
	
NODEP_CPP_QSAMP=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sample.cpp
DEP_CPP_SAMPL=\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\timer\timer.h"\
	".\lgsndi.h"\
	".\lgsndid.h"\
	".\lgsound.h"\
	".\mixerlck.h"\
	".\timelog.h"\
	
NODEP_CPP_SAMPL=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sndfmt.cpp
DEP_CPP_SNDFM=\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\timer\timer.h"\
	".\lgsndi.h"\
	".\lgsndid.h"\
	".\lgsound.h"\
	".\sndfmt.h"\
	".\sndvoc.h"\
	".\timelog.h"\
	
NODEP_CPP_SNDFM=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sndtest.cpp

!IF  "$(CFG)" == "sound - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\testsnd1.c

!IF  "$(CFG)" == "sound - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\timelog.cpp
DEP_CPP_TIMEL=\
	"..\fix\fix.h"\
	"..\timer\timer.h"\
	".\timelog.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\waildynf.cpp
DEP_CPP_WAILD=\
	"..\cpptools\dynfunc.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\wail.h"\
	".\waildynf.h"\
	
NODEP_CPP_WAILD=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sound - Win32 Release"

!ELSEIF  "$(CFG)" == "sound - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\dlgsndi.h
# End Source File
# Begin Source File

SOURCE=.\dsnddynf.h
# End Source File
# Begin Source File

SOURCE=.\lgsndi.h
# End Source File
# Begin Source File

SOURCE=.\lgsndid.h
# End Source File
# Begin Source File

SOURCE=.\lgsound.h
# End Source File
# Begin Source File

SOURCE=.\midiplay.h
# End Source File
# Begin Source File

SOURCE=.\midplayi.h
# End Source File
# Begin Source File

SOURCE=.\mixerlck.h
# End Source File
# Begin Source File

SOURCE=.\qlgsndi.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\sndfmt.h
# End Source File
# Begin Source File

SOURCE=.\sndvoc.h
# End Source File
# Begin Source File

SOURCE=.\timelog.h
# End Source File
# Begin Source File

SOURCE=.\volconv.h
# End Source File
# Begin Source File

SOURCE=.\wail.h
# End Source File
# Begin Source File

SOURCE=.\waildynf.h
# End Source File
# End Group
# Begin Group "Asm Source Files"

# PROP Default_Filter "asm"
# End Group
# Begin Group "Asm Inc Files"

# PROP Default_Filter "inc"
# End Group
# Begin Group "Resources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\sndtest.rc
# End Source File
# End Group
# End Target
# End Project
