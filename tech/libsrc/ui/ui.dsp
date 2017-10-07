# Microsoft Developer Studio Project File - Name="ui" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=ui - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ui.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ui.mak" CFG="ui - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ui - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ui - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ui - Win32 Release"

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

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

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
# ADD CPP /nologo /Zp1 /ML /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\h" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\comtools" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lg" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I ".\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_WINDOWS" /YX"..\..\types.h" /FD /FI "..\..\h\types.h" /GZ /c
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

# Name "ui - Win32 Release"
# Name "ui - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\butarray.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\curdrw.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cursors.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\event.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gadgets.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hotkey.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\menu.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\plain.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pushbutt.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\qboxgadg.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\region.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\slab.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\slider.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\textgadg.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\texttool.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tng.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngbarry.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngfont.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngmenu.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngplain.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngpushb.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngqbox.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngslidr.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngtextg.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uires.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vmouse.c

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\barrykey.h
# End Source File
# Begin Source File

SOURCE=.\butarray.h
# End Source File
# Begin Source File

SOURCE=.\curdat.h
# End Source File
# Begin Source File

SOURCE=.\cursors.h
# End Source File
# Begin Source File

SOURCE=.\curtyp.h
# End Source File
# Begin Source File

SOURCE=.\event.h
# End Source File
# Begin Source File

SOURCE=.\fakefont.h
# End Source File
# Begin Source File

SOURCE=.\gadgets.h
# End Source File
# Begin Source File

SOURCE=.\hotkey.h
# End Source File
# Begin Source File

SOURCE=.\libdbg.h
# End Source File
# Begin Source File

SOURCE=.\menu.h
# End Source File
# Begin Source File

SOURCE=.\plain.h
# End Source File
# Begin Source File

SOURCE=.\pushbutt.h
# End Source File
# Begin Source File

SOURCE=.\qboxgadg.h
# End Source File
# Begin Source File

SOURCE=.\region.h
# End Source File
# Begin Source File

SOURCE=.\slab.h
# End Source File
# Begin Source File

SOURCE=.\slider.h
# End Source File
# Begin Source File

SOURCE=.\textgadg.h
# End Source File
# Begin Source File

SOURCE=.\texttool.h
# End Source File
# Begin Source File

SOURCE=.\tng.h
# End Source File
# Begin Source File

SOURCE=.\tngapp.h
# End Source File
# Begin Source File

SOURCE=.\tngbarry.h
# End Source File
# Begin Source File

SOURCE=.\tngfont.h
# End Source File
# Begin Source File

SOURCE=.\tngmenu.h
# End Source File
# Begin Source File

SOURCE=.\tngplain.h
# End Source File
# Begin Source File

SOURCE=.\tngpushb.h
# End Source File
# Begin Source File

SOURCE=.\tngqbox.h
# End Source File
# Begin Source File

SOURCE=.\tngslidr.h
# End Source File
# Begin Source File

SOURCE=.\tngtextg.h
# End Source File
# Begin Source File

SOURCE=.\uires.h
# End Source File
# Begin Source File

SOURCE=.\vmouse.h
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
