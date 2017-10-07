# Microsoft Developer Studio Project File - Name="comtools" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=comtools - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "comtools.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "comtools.mak" CFG="comtools - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "comtools - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "comtools - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "comtools - Win32 Release"

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

!ELSEIF  "$(CFG)" == "comtools - Win32 Debug"

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

# Name "comtools - Win32 Release"
# Name "comtools - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\comconn.cpp
DEP_CPP_COMCO=\
	"..\..\h\prikind.h"\
	"..\cpptools\dynarray.h"\
	"..\cpptools\pdynarr.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\comconn.h"\
	".\comtools.h"\
	
NODEP_CPP_COMCO=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "comtools - Win32 Release"

!ELSEIF  "$(CFG)" == "comtools - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\comtools.cpp

!IF  "$(CFG)" == "comtools - Win32 Release"

!ELSEIF  "$(CFG)" == "comtools - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genagg.cpp
DEP_CPP_GENAG=\
	"..\..\h\prikind.h"\
	"..\cpptools\dlist.h"\
	"..\cpptools\dynarray.h"\
	"..\cpptools\hashfunc.h"\
	"..\cpptools\hashset.h"\
	"..\cpptools\hshstimp.h"\
	"..\cpptools\pdynarr.h"\
	"..\cpptools\str.h"\
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
	".\aggmemb.h"\
	".\comtools.h"\
	".\constrid.h"\
	".\genagg.h"\
	".\interset.h"\
	".\objcguid.h"\
	".\objcoll.h"\
	".\pguidset.h"\
	".\pintarr.h"\
	
NODEP_CPP_GENAG=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "comtools - Win32 Release"

!ELSEIF  "$(CFG)" == "comtools - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\geniset.cpp
DEP_CPP_GENIS=\
	"..\cpptools\dlist.h"\
	"..\cpptools\hashfunc.h"\
	"..\cpptools\hashset.h"\
	"..\cpptools\hshstimp.h"\
	"..\cpptools\str.h"\
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
	".\comtools.h"\
	".\geniset.h"\
	".\interset.h"\
	".\objcguid.h"\
	".\objcoll.h"\
	
NODEP_CPP_GENIS=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "comtools - Win32 Release"

!ELSEIF  "$(CFG)" == "comtools - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\interset.cpp
DEP_CPP_INTER=\
	"..\cpptools\dlist.h"\
	"..\cpptools\dlisttem.h"\
	"..\cpptools\hashfunc.h"\
	"..\cpptools\hashset.h"\
	"..\cpptools\hshstimp.h"\
	"..\cpptools\hshsttem.h"\
	"..\cpptools\str.h"\
	"..\cpptools\templexp.h"\
	"..\lg\dbg.h"\
	"..\lg\hashfns.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\lgalloc\pool.h"\
	".\comtools.h"\
	".\interset.h"\
	".\objcguid.h"\
	".\objcoll.h"\
	
NODEP_CPP_INTER=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "comtools - Win32 Release"

!ELSEIF  "$(CFG)" == "comtools - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pguidset.cpp
DEP_CPP_PGUID=\
	"..\..\h\prikind.h"\
	"..\cpptools\dynarray.h"\
	"..\cpptools\pdynarr.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\comtools.h"\
	".\constrid.h"\
	".\pguidset.h"\
	
NODEP_CPP_PGUID=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "comtools - Win32 Release"

!ELSEIF  "$(CFG)" == "comtools - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pintarr.cpp
DEP_CPP_PINTA=\
	"..\..\h\prikind.h"\
	"..\cpptools\dynarray.h"\
	"..\cpptools\pdynarr.h"\
	"..\cpptools\str.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\comtools.h"\
	".\pguidset.h"\
	".\pintarr.h"\
	
NODEP_CPP_PINTA=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "comtools - Win32 Release"

!ELSEIF  "$(CFG)" == "comtools - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\aggmemb.h
# End Source File
# Begin Source File

SOURCE=.\comconn.h
# End Source File
# Begin Source File

SOURCE=.\comtools.h
# End Source File
# Begin Source File

SOURCE=.\constrid.h
# End Source File
# Begin Source File

SOURCE=.\genagg.h
# End Source File
# Begin Source File

SOURCE=.\geniset.h
# End Source File
# Begin Source File

SOURCE=.\interset.h
# End Source File
# Begin Source File

SOURCE=.\objcguid.h
# End Source File
# Begin Source File

SOURCE=.\objcoll.h
# End Source File
# Begin Source File

SOURCE=.\pguidset.h
# End Source File
# Begin Source File

SOURCE=.\pintarr.h
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
