# Microsoft Developer Studio Project File - Name="res" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=res - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "res.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "res.mak" CFG="res - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "res - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "res - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "res - Win32 Release"

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

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

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

# Name "res - Win32 Release"
# Name "res - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\lzw.cpp
DEP_CPP_LZW_C=\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	".\lzw.h"\
	
NODEP_CPP_LZW_C=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lzwfd2bf.cpp
DEP_CPP_LZWFD=\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\lzw.h"\
	
NODEP_CPP_LZWFD=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pkzip.cpp
DEP_CPP_PKZIP=\
	"..\cpptools\dynfunc.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\implode.h"\
	".\lzw.h"\
	".\pkzip.h"\
	
NODEP_CPP_PKZIP=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\refacc.cpp
DEP_CPP_REFAC=\
	"..\..\h\_res.h"\
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
	".\lzw.h"\
	".\pkzip.h"\
	".\res.h"\
	".\res_.h"\
	".\resthred.h"\
	".\restypes.h"\
	
NODEP_CPP_REFAC=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\res.cpp
DEP_CPP_RES_C=\
	"..\..\h\_res.h"\
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
	".\lzw.h"\
	".\res.h"\
	".\res_.h"\
	".\restypes.h"\
	
NODEP_CPP_RES_C=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resacc.cpp
DEP_CPP_RESAC=\
	"..\..\h\_res.h"\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\cpptools\hashfunc.h"\
	"..\cpptools\hashset.h"\
	"..\cpptools\hshstimp.h"\
	"..\lg\dbg.h"\
	"..\lg\hashfns.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\lgalloc\pool.h"\
	".\res.h"\
	".\res_.h"\
	".\resarq.h"\
	".\resthred.h"\
	".\restypes.h"\
	
NODEP_CPP_RESAC=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resagg.c
DEP_CPP_RESAG=\
	"..\..\h\_res.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\config\config.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\res.h"\
	".\res_.h"\
	".\resagg.h"\
	".\resguid.h"\
	".\restypes.h"\
	
NODEP_CPP_RESAG=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resarq.cpp
DEP_CPP_RESAR=\
	"..\..\h\_res.h"\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\arqapi.h"\
	"..\compapis\arqguid.h"\
	"..\comtools\comtools.h"\
	"..\cpptools\hashfunc.h"\
	"..\cpptools\hashset.h"\
	"..\cpptools\hshstimp.h"\
	"..\cpptools\hshsttem.h"\
	"..\lg\dbg.h"\
	"..\lg\hashfns.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\dbmem.h"\
	"..\lgalloc\memall.h"\
	"..\lgalloc\pool.h"\
	".\res.h"\
	".\res_.h"\
	".\resarq.h"\
	".\resthred.h"\
	".\restypes.h"\
	
NODEP_CPP_RESAR=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resbuild.cpp
DEP_CPP_RESBU=\
	"..\..\h\_res.h"\
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
	".\lzw.h"\
	".\pkzip.h"\
	".\res.h"\
	".\res_.h"\
	".\restypes.h"\
	
NODEP_CPP_RESBU=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rescache.cpp
DEP_CPP_RESCA=\
	"..\..\h\prikind.h"\
	"..\compapis\cacheapi.h"\
	"..\compapis\cachguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\cpptools\dlist.h"\
	"..\cpptools\dynarray.h"\
	"..\cpptools\hashfunc.h"\
	"..\cpptools\hashset.h"\
	"..\cpptools\hshstimp.h"\
	"..\cpptools\hshsttem.h"\
	"..\cpptools\templexp.h"\
	"..\lg\dbg.h"\
	"..\lg\hashfns.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\dbmem.h"\
	"..\lgalloc\memall.h"\
	"..\lgalloc\pool.h"\
	"..\lgalloc\undbmem.h"\
	"..\mprintf\mprintf.h"\
	".\rescache.h"\
	".\resthred.h"\
	
NODEP_CPP_RESCA=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rescback.cpp
DEP_CPP_RESCB=\
	"..\..\h\_res.h"\
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
	".\res.h"\
	".\res_.h"\
	".\restypes.h"\
	
NODEP_CPP_RESCB=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rescum.cpp
DEP_CPP_RESCU=\
	"..\..\h\_res.h"\
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
	".\res.h"\
	".\res_.h"\
	".\restypes.h"\
	
NODEP_CPP_RESCU=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resexblk.cpp
DEP_CPP_RESEX=\
	"..\..\h\_res.h"\
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
	".\lzw.h"\
	".\res.h"\
	".\res_.h"\
	".\resthred.h"\
	".\restypes.h"\
	
NODEP_CPP_RESEX=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resfile.cpp
DEP_CPP_RESFI=\
	"..\..\h\_res.h"\
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
	".\res.h"\
	".\res_.h"\
	".\resthred.h"\
	".\restypes.h"\
	
NODEP_CPP_RESFI=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resguid.c
DEP_CPP_RESGU=\
	"..\comtools\comtools.h"\
	".\resguid.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resload.cpp
DEP_CPP_RESLO=\
	"..\..\h\_res.h"\
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
	".\lzw.h"\
	".\pkzip.h"\
	".\res.h"\
	".\res_.h"\
	".\restypes.h"\
	
NODEP_CPP_RESLO=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resmake.cpp
DEP_CPP_RESMA=\
	"..\..\h\_res.h"\
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
	".\res.h"\
	".\res_.h"\
	".\restypes.h"\
	
NODEP_CPP_RESMA=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resmem.cpp
DEP_CPP_RESME=\
	"..\..\h\_res.h"\
	"..\..\h\prikind.h"\
	"..\compapis\cacheapi.h"\
	"..\compapis\cachguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\cpptools\dynarray.h"\
	"..\lg\coremutx.h"\
	"..\lg\dbg.h"\
	"..\lg\hashfns.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\memstat.h"\
	"..\lgalloc\allocapi.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	".\res.h"\
	".\res_.h"\
	".\rescache.h"\
	".\resthred.h"\
	".\restypes.h"\
	
NODEP_CPP_RESME=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resmisc.cpp
DEP_CPP_RESMI=\
	"..\..\h\_res.h"\
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
	".\res.h"\
	".\res_.h"\
	".\restypes.h"\
	
NODEP_CPP_RESMI=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resthred.cpp
DEP_CPP_RESTH=\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	".\resthred.h"\
	
NODEP_CPP_RESTH=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\restypes.cpp
DEP_CPP_RESTY=\
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
	".\res.h"\
	".\restypes.h"\
	
NODEP_CPP_RESTY=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "res - Win32 Release"

!ELSEIF  "$(CFG)" == "res - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\implode.h
# End Source File
# Begin Source File

SOURCE=.\lzw.h
# End Source File
# Begin Source File

SOURCE=.\pkzip.h
# End Source File
# Begin Source File

SOURCE=.\res.h
# End Source File
# Begin Source File

SOURCE=.\res_.h
# End Source File
# Begin Source File

SOURCE=.\resagg.h
# End Source File
# Begin Source File

SOURCE=.\resarq.h
# End Source File
# Begin Source File

SOURCE=.\rescache.h
# End Source File
# Begin Source File

SOURCE=.\resguid.h
# End Source File
# Begin Source File

SOURCE=.\resimpl.h
# End Source File
# Begin Source File

SOURCE=.\resrect.h
# End Source File
# Begin Source File

SOURCE=.\resthred.h
# End Source File
# Begin Source File

SOURCE=.\restypes.h
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
