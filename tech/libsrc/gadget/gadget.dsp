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

# Name "gadget - Win32 Release"
# Name "gadget - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\drawelem.c

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gadblist.c

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gadget.c

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gadtext.c

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gcompose.c

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\guistyle.c

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uibutton.c

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uitexted.c

!IF  "$(CFG)" == "gadget - Win32 Release"

!ELSEIF  "$(CFG)" == "gadget - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\util2d.c

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
