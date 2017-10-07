# Microsoft Developer Studio Project File - Name="g2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=g2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "g2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "g2.mak" CFG="g2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "g2 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "g2 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "g2 - Win32 Release"

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

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

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

# Name "g2 - Win32 Release"
# Name "g2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\area.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\blend.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cc816.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\chkply.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clip.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clplin.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\co88.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cominit.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dlh816.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\drytmap.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16fl8ll.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16fl8s.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16lm.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16pm.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16s.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8fl8l.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8fl8ll.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8fl8s.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8il.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8l.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8lin.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8lm.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8lo2wc.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8nnic.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8o2wic.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8pm.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8s.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8sply.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2circ.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2d.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2el.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2makewr.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2ov.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2poly.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2ring.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2rot.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2tm.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gen16il.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gen8il.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genf16l.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genf16s.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genfl8l.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genfl8s.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genil.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genlil.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genline.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genlm.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genply.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genrast.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genrsds.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genrsdtm.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gens.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gensil.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gensply.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\golftmap.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\grtm.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\grwater.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\init.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lh816.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lht816.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lmap.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lo816.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lo88.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\o88.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\permap.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\plyshell.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\point.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pt_duv.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pt_grad.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pt_main.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pt_map.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\r88.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rastel.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\raster.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\scshell.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\setdrv.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\shadhack.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\shadtmap.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\svgainit.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\t816oc.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\t88oc.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tf.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmapd.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmsetup.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\trifan.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\trigrad.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\trirast.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\blncon.h
# End Source File
# Begin Source File

SOURCE=.\blnfcn.h
# End Source File
# Begin Source File

SOURCE=.\buffer.h
# End Source File
# Begin Source File

SOURCE=.\f16tf.h
# End Source File
# Begin Source File

SOURCE=.\fl8lf.h
# End Source File
# Begin Source File

SOURCE=.\fl8lin.h
# End Source File
# Begin Source File

SOURCE=.\fl8sf.h
# End Source File
# Begin Source File

SOURCE=.\fl8tf.h
# End Source File
# Begin Source File

SOURCE=.\flat16.h
# End Source File
# Begin Source File

SOURCE=.\flat8.h
# End Source File
# Begin Source File

SOURCE=.\frame.h
# End Source File
# Begin Source File

SOURCE=.\g2.h
# End Source File
# Begin Source File

SOURCE=.\g2clip.h
# End Source File
# Begin Source File

SOURCE=.\g2d.h
# End Source File
# Begin Source File

SOURCE=.\g2makewr.h
# End Source File
# Begin Source File

SOURCE=.\g2pt.h
# End Source File
# Begin Source File

SOURCE=.\g2spoint.h
# End Source File
# Begin Source File

SOURCE=.\g2tm.h
# End Source File
# Begin Source File

SOURCE=.\general.h
# End Source File
# Begin Source File

SOURCE=.\genrast.h
# End Source File
# Begin Source File

SOURCE=.\gensf.h
# End Source File
# Begin Source File

SOURCE=.\gentf.h
# End Source File
# Begin Source File

SOURCE=.\grchkply.h
# End Source File
# Begin Source File

SOURCE=.\grcurv.h
# End Source File
# Begin Source File

SOURCE=.\grlin.h
# End Source File
# Begin Source File

SOURCE=.\grply.h
# End Source File
# Begin Source File

SOURCE=.\grscale.h
# End Source File
# Begin Source File

SOURCE=.\grtm.h
# End Source File
# Begin Source File

SOURCE=.\icanvas.h
# End Source File
# Begin Source File

SOURCE=.\ilfunc.h
# End Source File
# Begin Source File

SOURCE=.\init.h
# End Source File
# Begin Source File

SOURCE=.\lftype.h
# End Source File
# Begin Source File

SOURCE=.\mathmac.h
# End Source File
# Begin Source File

SOURCE=.\permap.h
# End Source File
# Begin Source File

SOURCE=.\pftype.h
# End Source File
# Begin Source File

SOURCE=.\plyparam.h
# End Source File
# Begin Source File

SOURCE=.\plyrast.h
# End Source File
# Begin Source File

SOURCE=.\plyshell.h
# End Source File
# Begin Source File

SOURCE=.\plytyp.h
# End Source File
# Begin Source File

SOURCE=.\point.h
# End Source File
# Begin Source File

SOURCE=.\poly.h
# End Source File
# Begin Source File

SOURCE=.\polyint.h
# End Source File
# Begin Source File

SOURCE=.\profile.h
# End Source File
# Begin Source File

SOURCE=.\pt.h
# End Source File
# Begin Source File

SOURCE=.\pt_asm.h
# End Source File
# Begin Source File

SOURCE=.\ptmap.h
# End Source File
# Begin Source File

SOURCE=.\ptmapper.h
# End Source File
# Begin Source File

SOURCE=.\rastel.h
# End Source File
# Begin Source File

SOURCE=.\raster.h
# End Source File
# Begin Source File

SOURCE=.\recip.h
# End Source File
# Begin Source File

SOURCE=.\scale.h
# End Source File
# Begin Source File

SOURCE=.\scancvt.h
# End Source File
# Begin Source File

SOURCE=.\scshell.h
# End Source File
# Begin Source File

SOURCE=.\setdrv.h
# End Source File
# Begin Source File

SOURCE=.\sftype.h
# End Source File
# Begin Source File

SOURCE=.\swarn.h
# End Source File
# Begin Source File

SOURCE=.\tftype.h
# End Source File
# Begin Source File

SOURCE=.\tmapd.h
# End Source File
# Begin Source File

SOURCE=.\tmapf.h
# End Source File
# Begin Source File

SOURCE=.\tmapfcn.h
# End Source File
# Begin Source File

SOURCE=.\tmaps.h
# End Source File
# Begin Source File

SOURCE=.\trirast.h
# End Source File
# Begin Source File

SOURCE=.\water.h
# End Source File
# End Group
# Begin Group "Asm Source Files"

# PROP Default_Filter "asm"
# Begin Source File

SOURCE=.\chkedgeb.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\chkedges.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\co88il.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8lo2wi.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8nni.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8o2ni.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8o2wi.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lo816il.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lo88il.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\n88il.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\o2w88i.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\o88bil.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\o88il.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptfloat.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptlinear.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptmap.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptmap_8.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptmap_n.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptmapper.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptpersp.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uvgrad.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Asm Inc Files"

# PROP Default_Filter "inc"
# Begin Source File

SOURCE=.\g2spoint.inc
# End Source File
# Begin Source File

SOURCE=.\icanvas.inc
# End Source File
# Begin Source File

SOURCE=.\plyparam.inc
# End Source File
# Begin Source File

SOURCE=.\plyrast.inc
# End Source File
# Begin Source File

SOURCE=.\plytyp.inc
# End Source File
# Begin Source File

SOURCE=.\tmapd.inc
# End Source File
# Begin Source File

SOURCE=.\tmaps.inc
# End Source File
# End Group
# Begin Group "Asm Tbl Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\f16cnv.tbl
# End Source File
# Begin Source File

SOURCE=.\f16llmf.tbl
# End Source File
# Begin Source File

SOURCE=.\f16lmf.tbl
# End Source File
# Begin Source File

SOURCE=.\f16sf.tbl
# End Source File
# Begin Source File

SOURCE=.\f16usf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8cnv.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8llmf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8lmf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8sf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8ulf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8usf.tbl
# End Source File
# Begin Source File

SOURCE=.\gencnv.tbl
# End Source File
# Begin Source File

SOURCE=.\genllmf.tbl
# End Source File
# Begin Source File

SOURCE=.\genlmf.tbl
# End Source File
# Begin Source File

SOURCE=.\gensf.tbl
# End Source File
# Begin Source File

SOURCE=.\genusf.tbl
# End Source File
# End Group
# End Target
# End Project
