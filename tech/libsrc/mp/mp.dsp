# Microsoft Developer Studio Project File - Name="mp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=mp - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mp.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mp.mak" CFG="mp - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mp - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "mp - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mp - Win32 Release"

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
# ADD CPP /nologo /Zp1 /MT /W3 /GX /O2 /I "." /I "..\..\h" /I "..\lg" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\comtools" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I "..\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "SHIP" /FR /YX"..\..\types.h" /FI "..\..\h\types.h" /c
# SUBTRACT CPP /X /u
# ADD BASE RSC /l 0x816 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "mp - Win32 Debug"

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
# ADD CPP /nologo /Zp1 /ML /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\h" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\comtools" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lg" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I ".\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_WINDOWS" /YX"..\..\types.h" /FD /FI /GZ "..\..\h\types.h" /c
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

# Name "mp - Win32 Release"
# Name "mp - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\abmp.c

!IF  "$(CFG)" == "mp - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "mp - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\abvm.c

!IF  "$(CFG)" == "mp - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "mp - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mpinit.c
DEP_CPP_MPINI=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\motion.h"\
	".\motstruc.h"\
	".\mplist.h"\
	".\mpstack.h"\
	".\multiped.h"\
	".\qt.h"\
	
NODEP_CPP_MPINI=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "mp - Win32 Release"

!ELSEIF  "$(CFG)" == "mp - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mplist.c
DEP_CPP_MPLIS=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\motion.h"\
	".\mplist.h"\
	".\mpstack.h"\
	".\multiped.h"\
	".\qt.h"\
	
NODEP_CPP_MPLIS=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "mp - Win32 Release"

!ELSEIF  "$(CFG)" == "mp - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mploco.c
DEP_CPP_MPLOC=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\motion.h"\
	".\mplist.h"\
	".\mpstack.h"\
	".\multiped.h"\
	".\qt.h"\
	
NODEP_CPP_MPLOC=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "mp - Win32 Release"

!ELSEIF  "$(CFG)" == "mp - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mpmot.c
DEP_CPP_MPMOT=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\motion.h"\
	".\mplist.h"\
	".\mpstack.h"\
	".\multiped.h"\
	".\qt.h"\
	
NODEP_CPP_MPMOT=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "mp - Win32 Release"

!ELSEIF  "$(CFG)" == "mp - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mpstack.c
DEP_CPP_MPSTA=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\motion.h"\
	".\mplist.h"\
	".\mpstack.h"\
	".\multiped.h"\
	".\qt.h"\
	
NODEP_CPP_MPSTA=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "mp - Win32 Release"

!ELSEIF  "$(CFG)" == "mp - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mpupdate.c
DEP_CPP_MPUPD=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\motion.h"\
	".\mplist.h"\
	".\mpstack.h"\
	".\multiped.h"\
	".\qt.h"\
	
NODEP_CPP_MPUPD=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "mp - Win32 Release"

!ELSEIF  "$(CFG)" == "mp - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mpvm.c
DEP_CPP_MPVM_=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\motion.h"\
	".\mplist.h"\
	".\mpstack.h"\
	".\multiped.h"\
	".\qt.h"\
	
NODEP_CPP_MPVM_=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "mp - Win32 Release"

!ELSEIF  "$(CFG)" == "mp - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\multiped.c
DEP_CPP_MULTI=\
	"..\..\h\3d.h"\
	"..\..\h\prikind.h"\
	"..\..\h\schedstr.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\motion.h"\
	".\motstruc.h"\
	".\mplist.h"\
	".\mpstack.h"\
	".\multiped.h"\
	".\qt.h"\
	
NODEP_CPP_MULTI=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "mp - Win32 Release"

!ELSEIF  "$(CFG)" == "mp - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\qt.c
DEP_CPP_QT_C10=\
	"..\lg\dbg.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\qt.h"\
	
NODEP_CPP_QT_C10=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "mp - Win32 Release"

!ELSEIF  "$(CFG)" == "mp - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\appbiped.h
# End Source File
# Begin Source File

SOURCE=.\motion.h
# End Source File
# Begin Source File

SOURCE=.\motstruc.h
# End Source File
# Begin Source File

SOURCE=.\mp.h
# End Source File
# Begin Source File

SOURCE=.\mplist.h
# End Source File
# Begin Source File

SOURCE=.\mpstack.h
# End Source File
# Begin Source File

SOURCE=.\mputil.h
# End Source File
# Begin Source File

SOURCE=.\multiped.h
# End Source File
# Begin Source File

SOURCE=.\qt.h
# End Source File
# End Group
# Begin Group "Asm Source Files"

# PROP Default_Filter "asm"
# End Group
# Begin Group "Asm Inc Files"

# PROP Default_Filter "inc"
# End Group
# End Target
# End Project
