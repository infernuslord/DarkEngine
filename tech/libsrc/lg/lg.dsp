# Microsoft Developer Studio Project File - Name="lg" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=lg - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "lg.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "lg.mak" CFG="lg - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "lg - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "lg - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lg - Win32 Release"

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

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

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

# Name "lg - Win32 Release"
# Name "lg - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\appagg.cpp
DEP_CPP_APPAG=\
	"..\compapis\appagg.h"\
	"..\comtools\comtools.h"\
	"..\lgalloc\memall.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	
NODEP_CPP_APPAG=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\breakkey.cpp
DEP_CPP_BREAK=\
	"..\lgalloc\memall.h"\
	".\breakkey.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	
NODEP_CPP_BREAK=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bugtrak.c
DEP_CPP_BUGTR=\
	"..\..\h\lgerror.h"\
	"..\dstruct\array.h"\
	"..\lgalloc\memall.h"\
	".\bugtrak.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	".\lgsprntf.h"\
	
NODEP_CPP_BUGTR=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	".\env.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\codewrit.cpp
DEP_CPP_CODEW=\
	"..\lgalloc\memall.h"\
	".\codewrit.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	
NODEP_CPP_CODEW=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\coremutx.cpp
DEP_CPP_COREM=\
	".\coremutx.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\crc32.cpp
DEP_CPP_CRC32=\
	".\crc32.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\datapath.cpp
DEP_CPP_DATAP=\
	"..\lgalloc\memall.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lgdatapath.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	
NODEP_CPP_DATAP=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dbg.c
DEP_CPP_DBG_C=\
	"..\..\h\lgerror.h"\
	"..\..\h\nameconv.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\..\winsrc\input\keydefs.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	".\coremutx.h"\
	".\dbg.h"\
	".\lgassert.h"\
	".\lglog.h"\
	".\lgsprntf.h"\
	
NODEP_CPP_DBG_C=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dbgcfg.c
DEP_CPP_DBGCF=\
	"..\..\h\lgerror.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\..\winsrc\input\keydefs.h"\
	"..\mprintf\mprintf.h"\
	".\dbg.h"\
	".\lgdatapath.h"\
	
NODEP_CPP_DBGCF=\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dbgpp.cc
# End Source File
# Begin Source File

SOURCE=.\dpathdir.c
DEP_CPP_DPATH=\
	"..\lgalloc\memall.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lgdatapath.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	
NODEP_CPP_DPATH=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dptest.cpp
DEP_CPP_DPTES=\
	"..\compapis\appagg.h"\
	"..\compapis\appapi.h"\
	"..\comtools\comtools.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lgdatapath.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	
NODEP_CPP_DPTES=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\exit.c
DEP_CPP_EXIT_=\
	"..\lgalloc\memall.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	
NODEP_CPP_EXIT_=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\findfile.cpp
DEP_CPP_FINDF=\
	".\findfile.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hashfns.cpp
DEP_CPP_HASHF=\
	"..\lgalloc\memall.h"\
	".\dbg.h"\
	".\hashfns.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	
NODEP_CPP_HASHF=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lgassert.cpp
DEP_CPP_LGASS=\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	".\coremutx.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	
NODEP_CPP_LGASS=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lglog.cpp
DEP_CPP_LGLOG=\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	".\coremutx.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	
NODEP_CPP_LGLOG=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lgprntf.c
DEP_CPP_LGPRN=\
	"..\lgalloc\memall.h"\
	".\dbg.h"\
	".\lgsprntf.h"\
	".\tmpalloc.h"\
	
NODEP_CPP_LGPRN=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lgsprntf.c
DEP_CPP_LGSPR=\
	"..\fix\fix.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\memgrow.c

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\memreq.cpp
DEP_CPP_MEMRE=\
	"..\lgalloc\memall.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	".\memreq.h"\
	
NODEP_CPP_MEMRE=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\memstat.c
DEP_CPP_MEMST=\
	"..\..\h\_lg.h"\
	"..\..\h\dpmi.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	".\memstat.h"\
	
NODEP_CPP_MEMST=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\stack.c
DEP_CPP_STACK=\
	"..\lgalloc\memall.h"\
	".\dbg.h"\
	
NODEP_CPP_STACK=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\stktrace.cpp
DEP_CPP_STKTR=\
	".\stktrace.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\thrdtool.cpp
DEP_CPP_THRDT=\
	"..\lgalloc\memall.h"\
	".\dbg.h"\
	".\lg.h"\
	".\lgalt.h"\
	".\lgassert.h"\
	".\lglocmsg.h"\
	".\lglog.h"\
	".\thrdtool.h"\
	
NODEP_CPP_THRDT=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\timings.cpp
DEP_CPP_TIMIN=\
	"..\mprintf\mprintf.h"\
	".\timings.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmpalloc.c
DEP_CPP_TMPAL=\
	"..\..\h\_lg.h"\
	"..\lgalloc\memall.h"\
	".\dbg.h"\
	".\tmpalloc.h"\
	
NODEP_CPP_TMPAL=\
	"..\lgalloc\memmacro.h"\
	".\dbgmacro.h"\
	

!IF  "$(CFG)" == "lg - Win32 Release"

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\breakkey.h
# End Source File
# Begin Source File

SOURCE=.\bugtrak.h
# End Source File
# Begin Source File

SOURCE=.\codewrit.h
# End Source File
# Begin Source File

SOURCE=.\coremutx.h
# End Source File
# Begin Source File

SOURCE=.\crc32.h
# End Source File
# Begin Source File

SOURCE=.\dbg.h
# End Source File
# Begin Source File

SOURCE=.\dbgpp.h
# End Source File
# Begin Source File

SOURCE=.\findfile.h
# End Source File
# Begin Source File

SOURCE=.\hashfns.h
# End Source File
# Begin Source File

SOURCE=.\lg.h
# End Source File
# Begin Source File

SOURCE=.\lgalt.h
# End Source File
# Begin Source File

SOURCE=.\lgassert.h
# End Source File
# Begin Source File

SOURCE=.\lgdatapath.h
# End Source File
# Begin Source File

SOURCE=.\lglocmsg.h
# End Source File
# Begin Source File

SOURCE=.\lglog.h
# End Source File
# Begin Source File

SOURCE=.\lgprntf.h
# End Source File
# Begin Source File

SOURCE=.\lgsprntf.h
# End Source File
# Begin Source File

SOURCE=.\memreq.h
# End Source File
# Begin Source File

SOURCE=.\memstat.h
# End Source File
# Begin Source File

SOURCE=.\stktrace.h
# End Source File
# Begin Source File

SOURCE=.\thrdtool.h
# End Source File
# Begin Source File

SOURCE=.\timings.h
# End Source File
# Begin Source File

SOURCE=.\tmpalloc.h
# End Source File
# End Group
# Begin Group "Asm Source Files"

# PROP Default_Filter "asm"
# Begin Source File

SOURCE=.\oheapwal.asm

!IF  "$(CFG)" == "lg - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "lg - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Asm Inc Files"

# PROP Default_Filter "inc"
# Begin Source File

SOURCE=.\dbg.inc
# End Source File
# Begin Source File

SOURCE=.\dbgmacro.inc
# End Source File
# Begin Source File

SOURCE=.\lg.inc
# End Source File
# Begin Source File

SOURCE=.\memmacro.inc
# End Source File
# End Group
# End Target
# End Project
