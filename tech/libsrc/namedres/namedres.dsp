# Microsoft Developer Studio Project File - Name="namedres" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=namedres - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "namedres.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "namedres.mak" CFG="namedres - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "namedres - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "namedres - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "namedres - Win32 Release"

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

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

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

# Name "namedres - Win32 Release"
# Name "namedres - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\adler32.c

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\binrstyp.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bmp.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cel.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\defresm.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\defstfct.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\filestrm.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fonrstyp.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gif.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\imghack.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\imgrstyp.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\infblock.c

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\infcodes.c

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\inffast.c

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\inflate.c

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\inftrees.c

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\infutil.c

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mdlrstyp.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\palrstyp.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pathutil.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pcx.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resarq.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resimage.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resman.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resmanhs.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resmanx.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\respall.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resstat.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resstr.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resutil.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\search.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sndrstyp.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\storbase.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\storedir.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\storeman.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\storezip.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\strrstyp.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tga.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\zipstfct.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\zipstrm.cpp

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\zutil.c

!IF  "$(CFG)" == "namedres - Win32 Release"

!ELSEIF  "$(CFG)" == "namedres - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\binrstyp.h
# End Source File
# Begin Source File

SOURCE=.\datasrc.h
# End Source File
# Begin Source File

SOURCE=.\defresm.h
# End Source File
# Begin Source File

SOURCE=.\defstfct.h
# End Source File
# Begin Source File

SOURCE=.\dfrstype.h
# End Source File
# Begin Source File

SOURCE=.\filestrm.h
# End Source File
# Begin Source File

SOURCE=.\fonrstyp.h
# End Source File
# Begin Source File

SOURCE=.\imgrstyp.h
# End Source File
# Begin Source File

SOURCE=.\mdlrstyp.h
# End Source File
# Begin Source File

SOURCE=.\miprstyp.h
# End Source File
# Begin Source File

SOURCE=.\palrstyp.h
# End Source File
# Begin Source File

SOURCE=.\resapilg.h
# End Source File
# Begin Source File

SOURCE=.\resarq.h
# End Source File
# Begin Source File

SOURCE=.\resbase.h
# End Source File
# Begin Source File

SOURCE=.\resbastm.h
# End Source File
# Begin Source File

SOURCE=.\reshack.h
# End Source File
# Begin Source File

SOURCE=.\reshelp.h
# End Source File
# Begin Source File

SOURCE=.\resistr.h
# End Source File
# Begin Source File

SOURCE=.\resmanhs.h
# End Source File
# Begin Source File

SOURCE=.\resutil.h
# End Source File
# Begin Source File

SOURCE=.\rgmiptyp.h
# End Source File
# Begin Source File

SOURCE=.\search.h
# End Source File
# Begin Source File

SOURCE=.\sndrstyp.h
# End Source File
# Begin Source File

SOURCE=.\storcnst.h
# End Source File
# Begin Source File

SOURCE=.\storeapi.h
# End Source File
# Begin Source File

SOURCE=.\storeman.h
# End Source File
# Begin Source File

SOURCE=.\strrstyp.h
# End Source File
# Begin Source File

SOURCE=.\zipstfct.h
# End Source File
# Begin Source File

SOURCE=.\zipstrm.h
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
