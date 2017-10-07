# Microsoft Developer Studio Project File - Name="recorder" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=recorder - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "recorder.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "recorder.mak" CFG="recorder - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "recorder - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "recorder - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "recorder - Win32 Release"

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
# ADD CPP /nologo /Zp1 /MT /W3 /GX /O2 /I "." /I "..\..\h" /I "..\lg" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\comtools" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I "..\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR /YX"..\..\types.h" /FI "..\..\h\types.h" /c
# SUBTRACT CPP /X /u
# ADD BASE RSC /l 0x816 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "recorder - Win32 Debug"

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

# Name "recorder - Win32 Release"
# Name "recorder - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\recdata.cpp
DEP_CPP_RECDA=\
	"..\compapis\recapi.h"\
	"..\compapis\recguid.h"\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	
NODEP_CPP_RECDA=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "recorder - Win32 Release"

!ELSEIF  "$(CFG)" == "recorder - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\recorder.cpp
DEP_CPP_RECOR=\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\appapi.h"\
	"..\compapis\recapi.h"\
	"..\compapis\recguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\cpptools\dynarray.h"\
	"..\cpptools\filekind.h"\
	"..\cpptools\filepath.h"\
	"..\cpptools\filespec.h"\
	"..\cpptools\fnamutil.h"\
	"..\cpptools\hashfunc.h"\
	"..\cpptools\hashset.h"\
	"..\cpptools\hshstimp.h"\
	"..\cpptools\str.h"\
	"..\lg\dbg.h"\
	"..\lg\hashfns.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\lgalloc\pool.h"\
	".\recorder.h"\
	".\recprmpt.h"\
	
NODEP_CPP_RECOR=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "recorder - Win32 Release"

!ELSEIF  "$(CFG)" == "recorder - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\recprmpt.cpp
DEP_CPP_RECPR=\
	".\recprmpt.h"\
	

!IF  "$(CFG)" == "recorder - Win32 Release"

!ELSEIF  "$(CFG)" == "recorder - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rectempl.cpp
DEP_CPP_RECTE=\
	"..\compapis\recapi.h"\
	"..\compapis\recguid.h"\
	"..\comtools\comtools.h"\
	"..\cpptools\dynarray.h"\
	"..\cpptools\filekind.h"\
	"..\cpptools\filespec.h"\
	"..\cpptools\hashfunc.h"\
	"..\cpptools\hashset.h"\
	"..\cpptools\hshstimp.h"\
	"..\cpptools\hshsttem.h"\
	"..\lg\dbg.h"\
	"..\lg\hashfns.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\lgalloc\pool.h"\
	".\recorder.h"\
	
NODEP_CPP_RECTE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "recorder - Win32 Release"

!ELSEIF  "$(CFG)" == "recorder - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rectest.cpp
DEP_CPP_RECTES=\
	"..\compapis\appagg.h"\
	"..\compapis\recapi.h"\
	"..\compapis\recguid.h"\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	
NODEP_CPP_RECTES=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "recorder - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "recorder - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\fdesc.h
# End Source File
# Begin Source File

SOURCE=.\recorder.h
# End Source File
# Begin Source File

SOURCE=.\recprmpt.h
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
