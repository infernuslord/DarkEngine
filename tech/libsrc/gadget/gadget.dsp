# Microsoft Developer Studio Project File - Name="gadget" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=gadget - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "gadget.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "gadget.mak" CFG="gadget - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "gadget - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "gadget - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "gadget - Win32 Release"

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

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

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

# Name "gadget - Win32 Release"
# Name "gadget - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\drawelem.c
DEP_CPP_DRAWE=\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\config\cfgdbg.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
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
	"..\lg\lgsprntf.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\namedres\datasrc.h"\
	"..\res\lzw.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\ui\cursors.h"\
	"..\ui\region.h"\
	"..\ui\slab.h"\
	".\drawelem.h"\
	".\gadbase.h"\
	".\gadbox.h"\
	".\gadbutt.h"\
	".\gadget.h"\
	".\gadmenu.h"\
	".\gadscale.h"\
	".\guistyle.h"\
	".\lgadover.h"\
	".\util2d.h"\
	".\utilcomp.h"\
	
NODEP_CPP_DRAWE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gadblist.c
DEP_CPP_GADBL=\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
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
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\namedres\datasrc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\ui\cursors.h"\
	"..\ui\event.h"\
	"..\ui\region.h"\
	"..\ui\slab.h"\
	".\drawelem.h"\
	".\gadbase.h"\
	".\gadblist.h"\
	".\gadbox.h"\
	".\gadbutt.h"\
	".\gadget.h"\
	".\gadmenu.h"\
	".\gadscale.h"\
	".\guistyle.h"\
	".\lgadover.h"\
	".\uibutton.h"\
	".\uigadget.h"\
	
NODEP_CPP_GADBL=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gadget.c
DEP_CPP_GADGE=\
	"..\..\h\_dstruct.h"\
	"..\..\h\fixreal.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\..\winsrc\input\keydefs.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\comtools.h"\
	"..\config\cfg.h"\
	"..\config\cfgdbg.h"\
	"..\config\config.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\hash.h"\
	"..\dstruct\rect.h"\
	"..\fix\altfix.h"\
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
	"..\lg\lgsprntf.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\namedres\datasrc.h"\
	"..\res\lzw.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\ui\cursors.h"\
	"..\ui\event.h"\
	"..\ui\hotkey.h"\
	"..\ui\region.h"\
	"..\ui\slab.h"\
	".\drawelem.h"\
	".\gadbase.h"\
	".\gadbox.h"\
	".\gadbutt.h"\
	".\gadget.h"\
	".\gadgint.h"\
	".\gadmenu.h"\
	".\gadscale.h"\
	".\gcompose.h"\
	".\guistyle.h"\
	".\lgadover.h"\
	".\uibutton.h"\
	".\uigadget.h"\
	".\util2d.h"\
	".\utilcomp.h"\
	
NODEP_CPP_GADGE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gadtext.c
DEP_CPP_GADTE=\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
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
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\namedres\datasrc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\ui\cursors.h"\
	"..\ui\event.h"\
	"..\ui\region.h"\
	"..\ui\slab.h"\
	".\drawelem.h"\
	".\gadbase.h"\
	".\gadbox.h"\
	".\gadbutt.h"\
	".\gadget.h"\
	".\gadmenu.h"\
	".\gadscale.h"\
	".\gadtext.h"\
	".\guistyle.h"\
	".\lgadover.h"\
	".\uibutton.h"\
	".\uigadget.h"\
	".\uitexted.h"\
	
NODEP_CPP_GADTE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gcompose.c
DEP_CPP_GCOMP=\
	"..\..\h\2dres.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\compapis\2d.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\gfile\gfile.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\gcompose.h"\
	
NODEP_CPP_GCOMP=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\guistyle.c
DEP_CPP_GUIST=\
	"..\..\h\2dres.h"\
	"..\..\h\prikind.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\gfile\gfile.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\guistyle.h"\
	
NODEP_CPP_GUIST=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uibutton.c
DEP_CPP_UIBUT=\
	"..\..\h\2dres.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\..\winsrc\input\keydefs.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\config\cfgdbg.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
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
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\namedres\datasrc.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\ui\cursors.h"\
	"..\ui\event.h"\
	"..\ui\region.h"\
	"..\ui\slab.h"\
	".\drawelem.h"\
	".\gadbase.h"\
	".\gadbox.h"\
	".\gadbutt.h"\
	".\gadget.h"\
	".\gadgint.h"\
	".\gadmenu.h"\
	".\gadscale.h"\
	".\gcompose.h"\
	".\guistyle.h"\
	".\lgadover.h"\
	".\uibutton.h"\
	".\uigadget.h"\
	
NODEP_CPP_UIBUT=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uitexted.c
DEP_CPP_UITEX=\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\..\winsrc\input\keydefs.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\config\cfgdbg.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
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
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\namedres\datasrc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\ui\cursors.h"\
	"..\ui\event.h"\
	"..\ui\region.h"\
	"..\ui\slab.h"\
	".\drawelem.h"\
	".\gadbase.h"\
	".\gadbox.h"\
	".\gadbutt.h"\
	".\gadget.h"\
	".\gadgint.h"\
	".\gadmenu.h"\
	".\gadscale.h"\
	".\gadtext.h"\
	".\gcompose.h"\
	".\guistyle.h"\
	".\lgadover.h"\
	".\uibutton.h"\
	".\uigadget.h"\
	".\uitexted.h"\
	
NODEP_CPP_UITEX=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\util2d.c
DEP_CPP_UTIL2=\
	"..\..\h\2dres.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\comtools.h"\
	"..\config\cfgdbg.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
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
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\namedres\datasrc.h"\
	"..\recorder\fdesc.h"\
	"..\res\lzw.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\ui\cursors.h"\
	"..\ui\region.h"\
	"..\ui\slab.h"\
	".\drawelem.h"\
	".\gadbase.h"\
	".\gadbox.h"\
	".\gadbutt.h"\
	".\gadget.h"\
	".\gadmenu.h"\
	".\gadscale.h"\
	".\guistyle.h"\
	".\lgadover.h"\
	".\util2d.h"\
	".\utilcomp.h"\
	
NODEP_CPP_UTIL2=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\drawelem.h
# End Source File
# Begin Source File

SOURCE=.\gadbase.h
# End Source File
# Begin Source File

SOURCE=.\gadblist.h
# End Source File
# Begin Source File

SOURCE=.\gadbox.h
# End Source File
# Begin Source File

SOURCE=.\gadbutt.h
# End Source File
# Begin Source File

SOURCE=.\gadget.h
# End Source File
# Begin Source File

SOURCE=.\gadgint.h
# End Source File
# Begin Source File

SOURCE=.\gadint.h
# End Source File
# Begin Source File

SOURCE=.\gadmenu.h
# End Source File
# Begin Source File

SOURCE=.\gadscale.h
# End Source File
# Begin Source File

SOURCE=.\gadtext.h
# End Source File
# Begin Source File

SOURCE=.\gcompose.h
# End Source File
# Begin Source File

SOURCE=.\guistyle.h
# End Source File
# Begin Source File

SOURCE=.\lgadover.h
# End Source File
# Begin Source File

SOURCE=.\uibutton.h
# End Source File
# Begin Source File

SOURCE=.\uigadget.h
# End Source File
# Begin Source File

SOURCE=.\uitexted.h
# End Source File
# Begin Source File

SOURCE=.\util2d.h
# End Source File
# Begin Source File

SOURCE=.\utilcomp.h
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
