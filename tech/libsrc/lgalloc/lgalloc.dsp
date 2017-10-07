# Microsoft Developer Studio Project File - Name="lgalloc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=lgalloc - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "lgalloc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "lgalloc.mak" CFG="lgalloc - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "lgalloc - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "lgalloc - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lgalloc - Win32 Release"

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

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

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
# ADD CPP /nologo /Zp1 /ML /W3 /Gm /GX /ZI /Od /I "..\comtools" /I ".\\" /I "..\..\h" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lg" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I ".\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_WINDOWS" /YX"..\..\types.h" /FD /FI /GZ "..\..\h\types.h" /c
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

# Name "lgalloc - Win32 Release"
# Name "lgalloc - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\allcguid.cpp
DEP_CPP_ALLCG=\
	".\allcguid.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dbgalloc.cpp
DEP_CPP_DBGAL=\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\hashfns.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\stktrace.h"\
	"..\mprintf\mprintf.h"\
	".\allocapi.h"\
	".\dbgalloc.h"\
	".\fastmutx.h"\
	".\memall.h"\
	".\membase.h"\
	".\memcore.h"\
	
NODEP_CPP_DBGAL=\
	"..\lg\dbgmacro.h"\
	".\memmacro.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\heap.cpp
DEP_CPP_HEAP_=\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\mprintf\mprintf.h"\
	".\allocapi.h"\
	".\heap.h"\
	".\heaptool.h"\
	".\memall.h"\
	".\membase.h"\
	
NODEP_CPP_HEAP_=\
	"..\lg\dbgmacro.h"\
	".\memmacro.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\memall.c
DEP_CPP_MEMAL=\
	"..\..\h\_lg.h"\
	"..\lg\dbg.h"\
	".\mallocdb.h"\
	".\memall.h"\
	
NODEP_CPP_MEMAL=\
	"..\lg\dbgmacro.h"\
	".\memmacro.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\membase.cpp
DEP_CPP_MEMBA=\
	"..\comtools\comtools.h"\
	".\allocapi.h"\
	".\membase.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\memcore.cpp
DEP_CPP_MEMCO=\
	"..\comtools\comtools.h"\
	"..\lg\coremutx.h"\
	"..\lg\timings.h"\
	"..\mprintf\mprintf.h"\
	".\allocapi.h"\
	".\dbgalloc.h"\
	".\fastmutx.h"\
	".\heap.h"\
	".\heaptool.h"\
	".\membase.h"\
	".\memcore.h"\
	".\memtimer.h"\
	".\multpool.h"\
	".\nullallc.h"\
	".\poolimp.h"\
	".\primallc.h"\
	".\stdalloc.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\memtest.cpp
DEP_CPP_MEMTE=\
	"..\comtools\comtools.h"\
	".\allocapi.h"\
	".\allocovr.h"\
	".\mallocdb.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\memtimer.cpp
DEP_CPP_MEMTI=\
	"..\comtools\comtools.h"\
	"..\lg\timings.h"\
	"..\mprintf\mprintf.h"\
	".\allocapi.h"\
	".\fastmutx.h"\
	".\membase.h"\
	".\memcore.h"\
	".\memtimer.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\multpool.cpp
DEP_CPP_MULTP=\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	".\allocapi.h"\
	".\heaptool.h"\
	".\memall.h"\
	".\membase.h"\
	".\multpool.h"\
	".\poolimp.h"\
	
NODEP_CPP_MULTP=\
	"..\lg\dbgmacro.h"\
	".\memmacro.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\nonover.cpp
DEP_CPP_NONOV=\
	".\mallocdb.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\nullallc.cpp
DEP_CPP_NULLA=\
	".\nullallc.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pool.cpp
DEP_CPP_POOL_=\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	".\heaptool.h"\
	".\memall.h"\
	".\pool.h"\
	".\poolimp.h"\
	
NODEP_CPP_POOL_=\
	"..\lg\dbgmacro.h"\
	".\memmacro.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\poolimp.cpp
DEP_CPP_POOLI=\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\stktrace.h"\
	".\heaptool.h"\
	".\memall.h"\
	".\pool.h"\
	".\poolimp.h"\
	".\virtmem.h"\
	
NODEP_CPP_POOLI=\
	"..\lg\dbgmacro.h"\
	".\memmacro.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\primallc.cpp
DEP_CPP_PRIMA=\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	".\allocapi.h"\
	".\fastmutx.h"\
	".\memall.h"\
	".\membase.h"\
	".\memcore.h"\
	".\primallc.h"\
	
NODEP_CPP_PRIMA=\
	"..\lg\dbgmacro.h"\
	".\memmacro.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\stdalloc.cpp
DEP_CPP_STDAL=\
	"..\comtools\comtools.h"\
	".\allocapi.h"\
	".\membase.h"\
	".\stdalloc.h"\
	

!IF  "$(CFG)" == "lgalloc - Win32 Release"

!ELSEIF  "$(CFG)" == "lgalloc - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\allcguid.h
# End Source File
# Begin Source File

SOURCE=.\allocapi.h
# End Source File
# Begin Source File

SOURCE=.\allocovr.h
# End Source File
# Begin Source File

SOURCE=.\dbgalloc.h
# End Source File
# Begin Source File

SOURCE=.\dbmem.h
# End Source File
# Begin Source File

SOURCE=.\fastmutx.h
# End Source File
# Begin Source File

SOURCE=.\heap.h
# End Source File
# Begin Source File

SOURCE=.\heaptool.h
# End Source File
# Begin Source File

SOURCE=.\mallocdb.h
# End Source File
# Begin Source File

SOURCE=.\memall.h
# End Source File
# Begin Source File

SOURCE=.\membase.h
# End Source File
# Begin Source File

SOURCE=.\memcore.h
# End Source File
# Begin Source File

SOURCE=.\memtimer.h
# End Source File
# Begin Source File

SOURCE=.\multpool.h
# End Source File
# Begin Source File

SOURCE=.\nullallc.h
# End Source File
# Begin Source File

SOURCE=.\pool.h
# End Source File
# Begin Source File

SOURCE=.\poolimp.h
# End Source File
# Begin Source File

SOURCE=.\primallc.h
# End Source File
# Begin Source File

SOURCE=.\stdalloc.h
# End Source File
# Begin Source File

SOURCE=.\undbmem.h
# End Source File
# Begin Source File

SOURCE=.\virtmem.h
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
