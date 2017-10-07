# Microsoft Developer Studio Project File - Name="timer" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=timer - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "timer.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "timer.mak" CFG="timer - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "timer - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "timer - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "timer - Win32 Release"

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

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

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

# Name "timer - Win32 Release"
# Name "timer - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\tmail.c
DEP_CPP_TMAIL=\
	"..\..\h\ail.h"\
	"..\fix\fix.h"\
	".\tmdecl.h"\
	".\tmftab.h"\
	
NODEP_CPP_TMAIL=\
	"..\..\h\x32.h"\
	

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmftab.c
DEP_CPP_TMFTA=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\tmdecl.h"\
	".\tmftab.h"\
	
NODEP_CPP_TMFTA=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmlibt.c
DEP_CPP_TMLIB=\
	"..\fix\fix.h"\
	".\tmdecl.h"\
	".\tmftab.h"\
	

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmrt.c
DEP_CPP_TMRT_=\
	"..\fix\fix.h"\
	".\timer.h"\
	

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmwin32.c
DEP_CPP_TMWIN=\
	"..\..\h\inttype.h"\
	"..\compapis\appagg.h"\
	"..\compapis\gshelapi.h"\
	"..\compapis\gshlguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\recapi.h"\
	"..\compapis\recguid.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\tmdecl.h"\
	".\tmftab.h"\
	
NODEP_CPP_TMWIN=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\timer.h
# End Source File
# Begin Source File

SOURCE=.\tmdecl.h
# End Source File
# Begin Source File

SOURCE=.\tmftab.h
# End Source File
# Begin Source File

SOURCE=.\tmgr.h
# End Source File
# Begin Source File

SOURCE=.\tminit.h
# End Source File
# Begin Source File

SOURCE=.\tmmac.h
# End Source File
# End Group
# Begin Group "Asm Source Files"

# PROP Default_Filter "asm"
# Begin Source File

SOURCE=.\tmact.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmadd.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmclose.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmd.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmdeact.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmfast.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tminit.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmphnd.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmrate.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmrem.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmsden.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmsfreq.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmsper.asm

!IF  "$(CFG)" == "timer - Win32 Release"

!ELSEIF  "$(CFG)" == "timer - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Asm Inc Files"

# PROP Default_Filter "inc"
# Begin Source File

SOURCE=.\pic.inc
# End Source File
# Begin Source File

SOURCE=.\tmd.inc
# End Source File
# Begin Source File

SOURCE=.\tmdecl.inc
# End Source File
# Begin Source File

SOURCE=.\tmflag.inc
# End Source File
# Begin Source File

SOURCE=.\tmftab.inc
# End Source File
# Begin Source File

SOURCE=.\tmhnd.inc
# End Source File
# Begin Source File

SOURCE=.\tmlow.inc
# End Source File
# Begin Source File

SOURCE=.\tmrec.inc
# End Source File
# Begin Source File

SOURCE=.\tmreg.inc
# End Source File
# End Group
# End Target
# End Project
