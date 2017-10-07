# Microsoft Developer Studio Project File - Name="r3d" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=r3d - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "r3d.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "r3d.mak" CFG="r3d - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "r3d - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "r3d - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "r3d - Win32 Release"

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

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

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

# Name "r3d - Win32 Release"
# Name "r3d - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\block.c
DEP_CPP_BLOCK=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\_xfrm.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_BLOCK=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clip.c
DEP_CPP_CLIP_=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\clipcon_.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primfunc.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clipclip.c
DEP_CPP_CLIPC=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\clip.h"\
	".\clip_.h"\
	".\clipcon.h"\
	".\clipcon_.h"\
	".\clipoff.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_CLIPC=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clipglob.c
DEP_CPP_CLIPG=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	".\_test.h"\
	".\clip.h"\
	".\clip_.h"\
	".\clipcon.h"\
	".\clipcon_.h"\
	".\clipoff.h"\
	".\clipprim.h"\
	".\cliptab.h"\
	".\clipu.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xform.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_CLIPG=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clipplan.c
DEP_CPP_CLIPP=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\clip.h"\
	".\clip_.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\clipu.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\space.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_CLIPP=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clipproj.c
DEP_CPP_CLIPPR=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\clip.h"\
	".\clip_.h"\
	".\clipcon.h"\
	".\clipcon_.h"\
	".\clipoff.h"\
	".\clipprim.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_CLIPPR=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cliptest.c
DEP_CPP_CLIPT=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\clipcon_.h"\
	".\clipprim.h"\
	".\cliptab.h"\
	".\clipu.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clipunsc.c
DEP_CPP_CLIPU=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\clip.h"\
	".\clip_.h"\
	".\clipcon.h"\
	".\clipcon_.h"\
	".\clipoff.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_CLIPU=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ctxtguts.c
DEP_CPP_CTXTG=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\_xfrm.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxtguts.h"\
	".\ctxts.h"\
	".\prim.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\space.h"\
	".\view.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_CTXTG=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ctxtmang.c
DEP_CPP_CTXTM=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_ctxt.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxtguts.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3dctxt.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_CTXTM=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ctxtmult.c
DEP_CPP_CTXTMU=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_ctxt.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3dctxt.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\frame.c
DEP_CPP_FRAME=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_ctxt.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3dctxt.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_FRAME=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\init.c
DEP_CPP_INIT_=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_ctxt.h"\
	".\_test.h"\
	".\_xfrm.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3dctxt.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_INIT_=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object.c
DEP_CPP_OBJEC=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\_xfrm.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\object.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_OBJEC=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\polytest.c
DEP_CPP_POLYT=\
	"..\..\h\fault.h"\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\r3d.h"\
	".\r3ds.h"\
	
NODEP_CPP_POLYT=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\prim.c
DEP_CPP_PRIM_=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\prim.h"\
	".\primcon.h"\
	".\primcon_.h"\
	".\primfunc.h"\
	".\primtab.h"\
	".\primtab_.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\primconv.c
DEP_CPP_PRIMC=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\primconv.h"\
	".\r3ds.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\primd3d.c
DEP_CPP_PRIMD=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\prim.h"\
	".\primcon.h"\
	".\primcon_.h"\
	".\primfunc.h"\
	".\primtab.h"\
	".\primtab_.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\primface.c
DEP_CPP_PRIMF=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primface.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_PRIMF=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\primfunc.c
DEP_CPP_PRIMFU=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\clipcon_.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\prim.h"\
	".\primcon.h"\
	".\primcon_.h"\
	".\primfunc.h"\
	".\primpoly.h"\
	".\primtab.h"\
	".\primtab_.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_PRIMFU=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\primg2.c
DEP_CPP_PRIMG=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\g2\g2.h"\
	"..\lgd3d\lgd3d.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\timer\tmgr.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\prim.h"\
	".\primcon.h"\
	".\primcon_.h"\
	".\primconv.h"\
	".\primfunc.h"\
	".\primtab.h"\
	".\primtab_.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\primmisc.c
DEP_CPP_PRIMM=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\clipcon_.h"\
	".\clipprim.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\primtab_.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_PRIMM=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\primnull.c
DEP_CPP_PRIMN=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\primfunc.h"\
	".\r3ds.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\primpoly.c
DEP_CPP_PRIMP=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\clipprim.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\prim.h"\
	".\primcon.h"\
	".\primface.h"\
	".\primpoly.h"\
	".\primtab.h"\
	".\primtab_.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\space.c
DEP_CPP_SPACE=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\_xfrm.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\clipcon_.h"\
	".\clipprim.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\prim.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_SPACE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\utils.c
DEP_CPP_UTILS=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\prim.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\r3dutil.h"\
	".\xform.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_UTILS=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\view.c
DEP_CPP_VIEW_=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\_xfrm.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\view.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_VIEW_=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xfrmclip.c
DEP_CPP_XFRMC=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\_xfrm.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\clipcon_.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_XFRMC=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xfrmglob.c
DEP_CPP_XFRMG=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xform.h"\
	".\xfrmtab.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xfrmlin.c
DEP_CPP_XFRML=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\_xfrm.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_XFRML=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xfrmproj.c
DEP_CPP_XFRMP=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\_xfrm.h"\
	".\clip.h"\
	".\clip_.h"\
	".\clipcon.h"\
	".\clipcon_.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_XFRMP=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xfrmunsc.c
DEP_CPP_XFRMU=\
	"..\..\h\grspoint.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\_test.h"\
	".\_xfrm.h"\
	".\clip.h"\
	".\clipcon.h"\
	".\clipcon_.h"\
	".\cliptab.h"\
	".\ctxts.h"\
	".\primcon.h"\
	".\primtab.h"\
	".\r3ds.h"\
	".\xfrmtab.h"\
	
NODEP_CPP_XFRMU=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\_ctxt.h
# End Source File
# Begin Source File

SOURCE=.\_test.h
# End Source File
# Begin Source File

SOURCE=.\_xfrm.h
# End Source File
# Begin Source File

SOURCE=.\block.h
# End Source File
# Begin Source File

SOURCE=.\clip.h
# End Source File
# Begin Source File

SOURCE=.\clip_.h
# End Source File
# Begin Source File

SOURCE=.\clipcon.h
# End Source File
# Begin Source File

SOURCE=.\clipcon_.h
# End Source File
# Begin Source File

SOURCE=.\clipoff.h
# End Source File
# Begin Source File

SOURCE=.\clipplan.h
# End Source File
# Begin Source File

SOURCE=.\clipprim.h
# End Source File
# Begin Source File

SOURCE=.\cliptab.h
# End Source File
# Begin Source File

SOURCE=.\clipu.h
# End Source File
# Begin Source File

SOURCE=.\ctxtguts.h
# End Source File
# Begin Source File

SOURCE=.\ctxts.h
# End Source File
# Begin Source File

SOURCE=.\grnull.h
# End Source File
# Begin Source File

SOURCE=.\init.h
# End Source File
# Begin Source File

SOURCE=.\object.h
# End Source File
# Begin Source File

SOURCE=.\prim.h
# End Source File
# Begin Source File

SOURCE=.\primcon.h
# End Source File
# Begin Source File

SOURCE=.\primcon_.h
# End Source File
# Begin Source File

SOURCE=.\primconv.h
# End Source File
# Begin Source File

SOURCE=.\primface.h
# End Source File
# Begin Source File

SOURCE=.\primfunc.h
# End Source File
# Begin Source File

SOURCE=.\primpoly.h
# End Source File
# Begin Source File

SOURCE=.\primtab.h
# End Source File
# Begin Source File

SOURCE=.\primtab_.h
# End Source File
# Begin Source File

SOURCE=.\r3d.h
# End Source File
# Begin Source File

SOURCE=.\r3dctxt.h
# End Source File
# Begin Source File

SOURCE=.\r3ds.h
# End Source File
# Begin Source File

SOURCE=.\r3dutil.h
# End Source File
# Begin Source File

SOURCE=.\space.h
# End Source File
# Begin Source File

SOURCE=.\utils.h
# End Source File
# Begin Source File

SOURCE=.\view.h
# End Source File
# Begin Source File

SOURCE=.\xform.h
# End Source File
# Begin Source File

SOURCE=.\xfrmtab.h
# End Source File
# End Group
# Begin Group "Asm Source Files"

# PROP Default_Filter "asm"
# Begin Source File

SOURCE=.\projfast.asm

!IF  "$(CFG)" == "r3d - Win32 Release"

!ELSEIF  "$(CFG)" == "r3d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Asm Inc Files"

# PROP Default_Filter "inc"
# Begin Source File

SOURCE=.\ctxts.inc
# End Source File
# Begin Source File

SOURCE=.\r3spoint.inc
# End Source File
# End Group
# End Target
# End Project
