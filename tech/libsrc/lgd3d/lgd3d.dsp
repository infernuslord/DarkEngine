# Microsoft Developer Studio Project File - Name="lgd3d" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=lgd3d - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "lgd3d.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "lgd3d.mak" CFG="lgd3d - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "lgd3d - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "lgd3d - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lgd3d - Win32 Release"

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
# ADD CPP /nologo /Zp1 /MT /W3 /GX /O2 /I "." /I "..\..\h" /I "..\lg" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\comtools" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I "..\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "USE_D3D2_API" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "SHIP" /FR /YX"..\..\types.h" /FI "..\..\h\types.h" /c
# SUBTRACT CPP /X /u
# ADD BASE RSC /l 0x816 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "lgd3d - Win32 Debug"

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

# Name "lgd3d - Win32 Release"
# Name "lgd3d - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\blit.c
DEP_CPP_BLIT_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\setup.h"\
	

!IF  "$(CFG)" == "lgd3d - Win32 Release"

!ELSEIF  "$(CFG)" == "lgd3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clip.c
DEP_CPP_CLIP_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\d3dpoint.h"\
	
NODEP_CPP_CLIP_=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "lgd3d - Win32 Release"

!ELSEIF  "$(CFG)" == "lgd3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\comshell.c
DEP_CPP_COMSH=\
	"..\..\h\lgerror.h"\
	"..\..\winsrc\input\inpinit.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\compapis\appagg.h"\
	"..\compapis\appapi.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\gshelapi.h"\
	"..\compapis\gshlguid.h"\
	"..\compapis\pumpenum.h"\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\d3dtest.h"\
	
NODEP_CPP_COMSH=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "lgd3d - Win32 Release"

!ELSEIF  "$(CFG)" == "lgd3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\d3dtest.c
DEP_CPP_D3DTE=\
	"..\..\h\grspoint.h"\
	"..\..\h\grtb.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\r3d\r3ds.h"\
	".\lgd3d.h"\
	".\tmgr.h"\
	
NODEP_CPP_D3DTE=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "lgd3d - Win32 Release"

!ELSEIF  "$(CFG)" == "lgd3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\enum.cpp
DEP_CPP_ENUM_=\
	"..\..\h\grspoint.h"\
	"..\comtools\comtools.h"\
	"..\cpptools\dynfunc.h"\
	"..\dev2d\dev2d.h"\
	"..\dispdev\dddynf.h"\
	"..\fix\fix.h"\
	"..\g2\g2.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\r3d\r3ds.h"\
	".\lgd3d.h"\
	".\setup.h"\
	".\tmgr.h"\
	
NODEP_CPP_ENUM_=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "lgd3d - Win32 Release"

!ELSEIF  "$(CFG)" == "lgd3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render.c
DEP_CPP_RENDE=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\r3d\r3ds.h"\
	".\d3dmacs.h"\
	".\lgd3d.h"\
	".\setup.h"\
	".\tdrv.h"\
	".\texture.h"\
	".\tmgr.h"\
	
NODEP_CPP_RENDE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "lgd3d - Win32 Release"

!ELSEIF  "$(CFG)" == "lgd3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\setup.c
DEP_CPP_SETUP=\
	"..\..\h\grspoint.h"\
	"..\compapis\appagg.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dispdev\wdispapi.h"\
	"..\dispdev\wdspguid.h"\
	"..\fix\fix.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\r3d\r3ds.h"\
	".\lgd3d.h"\
	".\setup.h"\
	".\texture.h"\
	".\tmgr.h"\
	
NODEP_CPP_SETUP=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "lgd3d - Win32 Release"

!ELSEIF  "$(CFG)" == "lgd3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\texture.c
DEP_CPP_TEXTU=\
	"..\..\h\grspoint.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dispdev\cbchain.h"\
	"..\dispdev\wdispapi.h"\
	"..\dispdev\wdispcb.h"\
	"..\dispdev\wdspguid.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\r3d\r3ds.h"\
	".\lgd3d.h"\
	".\setup.h"\
	".\tdrv.h"\
	".\texture.h"\
	".\tmgr.h"\
	
NODEP_CPP_TEXTU=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "lgd3d - Win32 Release"

!ELSEIF  "$(CFG)" == "lgd3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmgr.c
DEP_CPP_TMGR_=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\r3d\r3ds.h"\
	".\tdrv.h"\
	".\tmgr.h"\
	
NODEP_CPP_TMGR_=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "lgd3d - Win32 Release"

!ELSEIF  "$(CFG)" == "lgd3d - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\d3dmacs.h
# End Source File
# Begin Source File

SOURCE=.\d3dpoint.h
# End Source File
# Begin Source File

SOURCE=.\d3dtest.h
# End Source File
# Begin Source File

SOURCE=.\lgd3d.h
# End Source File
# Begin Source File

SOURCE=.\lgss2p.h
# End Source File
# Begin Source File

SOURCE=.\setup.h
# End Source File
# Begin Source File

SOURCE=.\tdrv.h
# End Source File
# Begin Source File

SOURCE=.\texture.h
# End Source File
# Begin Source File

SOURCE=.\tmgr.h
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
