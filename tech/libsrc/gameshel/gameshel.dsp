# Microsoft Developer Studio Project File - Name="gameshel" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=gameshel - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "gameshel.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "gameshel.mak" CFG="gameshel - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "gameshel - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "gameshel - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "gameshel - Win32 Release"

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

!ELSEIF  "$(CFG)" == "gameshel - Win32 Debug"

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

# Name "gameshel - Win32 Release"
# Name "gameshel - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\dgshell.cpp
DEP_CPP_DGSHE=\
	"..\..\h\prikind.h"\
	"..\compapis\gshelapi.h"\
	"..\compapis\gshlguid.h"\
	"..\compapis\pumpenum.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comconn.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\cpptools\dynarray.h"\
	"..\cpptools\pdynarr.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\dgshell.h"\
	
NODEP_CPP_DGSHE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gameshel - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "gameshel - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wgscreat.cpp
DEP_CPP_WGSCR=\
	"..\..\h\prikind.h"\
	"..\compapis\gshelapi.h"\
	"..\compapis\gshlguid.h"\
	"..\compapis\indevapi.h"\
	"..\compapis\indvguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comconn.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\cpptools\dynarray.h"\
	"..\cpptools\pdynarr.h"\
	"..\dispdev\wdispapi.h"\
	"..\dispdev\wdspguid.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	".\wgshell.h"\
	".\wgshelmt.h"\
	".\winput.h"\
	".\winshapi.h"\
	".\wnshguid.h"\
	
NODEP_CPP_WGSCR=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gameshel - Win32 Release"

!ELSEIF  "$(CFG)" == "gameshel - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wgshell.cpp
DEP_CPP_WGSHE=\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\appapi.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\gshelapi.h"\
	"..\compapis\gshlguid.h"\
	"..\compapis\indevapi.h"\
	"..\compapis\indvguid.h"\
	"..\compapis\movconst.h"\
	"..\compapis\movieapi.h"\
	"..\compapis\moviguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comconn.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\cpptools\dynarray.h"\
	"..\cpptools\filekind.h"\
	"..\cpptools\filespec.h"\
	"..\cpptools\pdynarr.h"\
	"..\dispdev\wdispapi.h"\
	"..\dispdev\wdspguid.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	".\wgshell.h"\
	".\winput.h"\
	".\winshapi.h"\
	".\wnshguid.h"\
	
NODEP_CPP_WGSHE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gameshel - Win32 Release"

!ELSEIF  "$(CFG)" == "gameshel - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wgshelmt.cpp
DEP_CPP_WGSHEL=\
	"..\..\h\prikind.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\gshelapi.h"\
	"..\compapis\gshlguid.h"\
	"..\compapis\indevapi.h"\
	"..\compapis\indvguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comconn.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\cpptools\dynarray.h"\
	"..\cpptools\pdynarr.h"\
	"..\dispdev\wdispapi.h"\
	"..\dispdev\wdspguid.h"\
	"..\lg\coremutx.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	".\wgshell.h"\
	".\wgshelmt.h"\
	".\winput.h"\
	".\winshapi.h"\
	".\wnshguid.h"\
	
NODEP_CPP_WGSHEL=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gameshel - Win32 Release"

!ELSEIF  "$(CFG)" == "gameshel - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\winput.cpp
DEP_CPP_WINPU=\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\gshelapi.h"\
	"..\compapis\gshlguid.h"\
	"..\compapis\indevapi.h"\
	"..\compapis\indvguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comconn.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\cpptools\dynarray.h"\
	"..\cpptools\pdynarr.h"\
	"..\dispdev\wdispapi.h"\
	"..\dispdev\wdspguid.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\nec98.h"\
	".\wgshell.h"\
	".\winput.h"\
	".\winshapi.h"\
	".\wnshguid.h"\
	
NODEP_CPP_WINPU=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gameshel - Win32 Release"

!ELSEIF  "$(CFG)" == "gameshel - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\dgshell.h
# End Source File
# Begin Source File

SOURCE=.\nec98.h
# End Source File
# Begin Source File

SOURCE=.\wgshell.h
# End Source File
# Begin Source File

SOURCE=.\wgshelmt.h
# End Source File
# Begin Source File

SOURCE=.\winput.h
# End Source File
# Begin Source File

SOURCE=.\winshapi.h
# End Source File
# Begin Source File

SOURCE=.\wnshguid.h
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
