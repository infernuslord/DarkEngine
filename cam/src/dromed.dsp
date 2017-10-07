# Microsoft Developer Studio Project File - Name="Dromed" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Dromed - Win32 Opt No Precompiled Header
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "dromed.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dromed.mak" CFG="Dromed - Win32 Opt No Precompiled Header"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Dromed - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Dromed - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Dromed - Win32 Opt" (based on "Win32 (x86) Application")
!MESSAGE "Dromed - Win32 Opt No Precompiled Header" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /Zp1 /W3 /O2 /I "." /I ".\actreact" /I ".\ai" /I ".\csg" /I ".\dark" /I ".\editor" /I ".\engfeat" /I ".\framewrk" /I ".\motion" /I ".\object" /I ".\physics" /I ".\portal" /I ".\render" /I ".\script" /I ".\shock" /I ".\sim" /I ".\sound" /I ".\ui" /I "..\..\tech\h\win32" /I "..\..\cam\h" /I "..\..\tech\h" /I "..\..\3rdsrc\dx70\include" /I "..\..\3rdsrc\h" /I "..\..\tech\libsrc\lg" /I "..\..\tech\libsrc\lgalloc" /I "..\..\tech\libsrc\compapis" /I "..\..\tech\libsrc\comtools" /I "..\..\tech\libsrc\darkloop" /I "..\..\tech\libsrc\tagfile" /I "..\..\tech\libsrc\matrix" /I "..\..\tech\libsrc\cpptools" /I "..\..\tech\libsrc\sdesc" /I "..\..\tech\libsrc\mprintf" /I "..\..\tech\libsrc\r3d" /I "..\..\tech\libsrc\config" /I "..\..\tech\libsrc\md" /I "..\..\tech\libsrc\fix" /I "..\..\tech\libsrc\prof" /I "..\..\tech\libsrc\g2" /I "..\..\tech\libsrc\dev2d" /I "..\..\tech\libsrc\namedres" /I "..\..\tech\libsrc\res" /I "..\..\tech\libsrc\mp" /I "..\..\tech\libsrc\mm" /I "..\..\tech\libsrc\inputbnd" /I "..\..\tech\libsrc\ui" /I "..\..\tech\winsrc\input" /I "..\..\tech\libsrc\dstruct" /I "..\..\tech\libsrc\gadget" /I "..\..\tech\libsrc\font" /I "..\..\tech\libsrc\sndsrc" /I "..\..\tech\libsrc\sound" /I "..\..\tech\libsrc\lgd3d" /I "..\..\tech\libsrc\timer" /I "..\..\tech\libsrc\gfile" /I "..\..\tech\libsrc\recorder" /I "..\..\tech\libsrc\star" /I "..\..\tech\libsrc\dump" /I "..\..\tech\libsrc\random" /I "..\..\tech\libsrc\net" /I "..\..\tech\libsrc\rnd" /FI"types.h" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D STRICT=1 /D "EDITOR" /D "PLAYTEST" /D "NEW_NETWORK_ENABLED" /D "THIEF" /D "PROPERTY_BLAME" /YX /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 entrywin.lib r3d.lib star.lib skel.lib mp.lib md.lib dump.lib vec2.lib prof.lib gfile.lib darkloop.lib lgd3d.lib mm.lib script.lib sndsrc.lib ref.lib sdesc.lib arq.lib inputbnd.lib input.lib namedres.lib net.lib random.lib tagfile.lib mprintf.lib lg.lib lgalloc.lib matrix.lib fix.lib dstruct.lib cpptools.lib comtools.lib templgen.lib compapis.lib appcore.lib config.lib res.lib gameshel.lib timer.lib rnd.lib recorder.lib dev2d.lib g2.lib font.lib dispdev.lib sound.lib sndutil.lib actmovie.lib quartz.lib measure.lib strmbase.lib ui.lib gadget.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib comctl32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /Zp1 /MT /W3 /Gm /Gi /ZI /Od /I "." /I ".\actreact" /I ".\ai" /I ".\csg" /I ".\editor" /I ".\engfeat" /I ".\framewrk" /I ".\motion" /I ".\object" /I ".\physics" /I ".\portal" /I ".\render" /I ".\script" /I ".\shock" /I ".\sim" /I ".\sound" /I ".\ui" /I ".\dark" /I "..\..\tech\h\win32" /I "..\..\cam\h" /I "..\..\tech\h" /I "..\..\3rdsrc\dx70\include" /I "..\..\3rdsrc\h" /I "..\..\tech\libsrc\lg" /I "..\..\tech\libsrc\lgalloc" /I "..\..\tech\libsrc\compapis" /I "..\..\tech\libsrc\comtools" /I "..\..\tech\libsrc\darkloop" /I "..\..\tech\libsrc\tagfile" /I "..\..\tech\libsrc\matrix" /I "..\..\tech\libsrc\cpptools" /I "..\..\tech\libsrc\sdesc" /I "..\..\tech\libsrc\mprintf" /I "..\..\tech\libsrc\r3d" /I "..\..\tech\libsrc\config" /I "..\..\tech\libsrc\md" /I "..\..\tech\libsrc\fix" /I "..\..\tech\libsrc\prof" /I "..\..\tech\libsrc\g2" /I "..\..\tech\libsrc\dev2d" /I "..\..\tech\libsrc\namedres" /I "..\..\tech\libsrc\res" /I "..\..\tech\libsrc\mp" /I "..\..\tech\libsrc\mm" /I "..\..\tech\libsrc\inputbnd" /I "..\..\tech\libsrc\ui" /I "..\..\tech\winsrc\input" /I "..\..\tech\libsrc\dstruct" /I "..\..\tech\libsrc\gadget" /I "..\..\tech\libsrc\font" /I "..\..\tech\libsrc\sndsrc" /I "..\..\tech\libsrc\sound" /I "..\..\tech\libsrc\lgd3d" /I "..\..\tech\libsrc\timer" /I "..\..\tech\libsrc\gfile" /I "..\..\tech\libsrc\recorder" /I "..\..\tech\libsrc\star" /I "..\..\tech\libsrc\dump" /I "..\..\tech\libsrc\random" /I "..\..\tech\libsrc\net" /I "..\..\tech\libsrc\rnd" /FI"pch.h" /FI"types.h" /D "DEBUG" /D "_DEBUG" /D "DBG_ON" /D "WARN_ON" /D "SPEW_ON" /D "RGB_LIGHTING" /D "BIG_LIGHTMAPS" /D "SOFTWARE_RGB" /D "SCHEMA_LOADING" /D "__MSVC" /D "REPORT" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D STRICT=1 /D "EDITOR" /D "PLAYTEST" /D "NEW_NETWORK_ENABLED" /D "THIEF" /D "PROPERTY_BLAME" /Yu"pch.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 entrywin.lib r3d.lib star.lib skel.lib mp.lib md.lib dump.lib vec2.lib prof.lib gfile.lib darkloop.lib lgd3d.lib mm.lib script.lib sndsrc.lib ref.lib sdesc.lib arq.lib inputbnd.lib input.lib namedres.lib net.lib random.lib tagfile.lib mprintf.lib lg.lib lgalloc.lib matrix.lib fix.lib dstruct.lib cpptools.lib comtools.lib templgen.lib compapis.lib appcore.lib config.lib res.lib gameshel.lib timer.lib rnd.lib recorder.lib dev2d.lib g2.lib font.lib dispdev.lib sound.lib sndutil.lib actmovie.lib quartz.lib measure.lib strmbase.lib ui.lib gadget.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib comctl32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"darked.exe" /pdbtype:sept /libpath:"\prj\thief2\lib\win32\v60\a611\dbg" /libpath:"r:\prj\thief2\lib\win32\v60\a611\dbg" /libpath:"\prj\tech\lib\win32\v60\a611\dbg" /libpath:"x:\prj\tech\lib\win32\v60\a611\dbg"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Dromed___Win32_Opt"
# PROP BASE Intermediate_Dir "Dromed___Win32_Opt"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Opt"
# PROP Intermediate_Dir "Opt"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /Zp1 /MT /W3 /Gm /Gi /ZI /Od /I "." /I ".\actreact" /I ".\ai" /I ".\csg" /I ".\editor" /I ".\engfeat" /I ".\framewrk" /I ".\motion" /I ".\object" /I ".\physics" /I ".\portal" /I ".\render" /I ".\script" /I ".\shock" /I ".\sim" /I ".\sound" /I ".\ui" /I ".\dark" /I "..\..\tech\h\win32" /I "..\..\cam\h" /I "..\..\tech\h" /I "..\..\3rdsrc\dx70\include" /I "..\..\3rdsrc\h" /I "..\..\tech\libsrc\lg" /I "..\..\tech\libsrc\lgalloc" /I "..\..\tech\libsrc\compapis" /I "..\..\tech\libsrc\comtools" /I "..\..\tech\libsrc\darkloop" /I "..\..\tech\libsrc\tagfile" /I "..\..\tech\libsrc\matrix" /I "..\..\tech\libsrc\cpptools" /I "..\..\tech\libsrc\sdesc" /I "..\..\tech\libsrc\mprintf" /I "..\..\tech\libsrc\r3d" /I "..\..\tech\libsrc\config" /I "..\..\tech\libsrc\md" /I "..\..\tech\libsrc\fix" /I "..\..\tech\libsrc\prof" /I "..\..\tech\libsrc\g2" /I "..\..\tech\libsrc\dev2d" /I "..\..\tech\libsrc\namedres" /I "..\..\tech\libsrc\res" /I "..\..\tech\libsrc\mp" /I "..\..\tech\libsrc\mm" /I "..\..\tech\libsrc\inputbnd" /I "..\..\tech\libsrc\ui" /I "..\..\tech\winsrc\input" /I "..\..\tech\libsrc\dstruct" /I "..\..\tech\libsrc\gadget" /I "..\..\tech\libsrc\font" /I "..\..\tech\libsrc\sndsrc" /I "..\..\tech\libsrc\sound" /I "..\..\tech\libsrc\lgd3d" /I "..\..\tech\libsrc\timer" /I "..\..\tech\libsrc\gfile" /I "..\..\tech\libsrc\recorder" /I "..\..\tech\libsrc\star" /I "..\..\tech\libsrc\dump" /I "..\..\tech\libsrc\random" /I "..\..\tech\libsrc\net" /I "..\..\tech\libsrc\rnd" /FI"pch.h" /FI"types.h" /D "DEBUG" /D "_DEBUG" /D "DBG_ON" /D "WARN_ON" /D "SPEW_ON" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D STRICT=1 /D "EDITOR" /D "PLAYTEST" /D "NEW_NETWORK_ENABLED" /D "THIEF" /D "RGB_LIGHTING" /D "SCHEMA_LOADING" /D "__MSVC" /Yu"pch.h" /FD /GZ /c
# ADD CPP /nologo /Zp1 /MT /W3 /Gi /O2 /I "." /I ".\actreact" /I ".\ai" /I ".\csg" /I ".\editor" /I ".\engfeat" /I ".\framewrk" /I ".\motion" /I ".\object" /I ".\physics" /I ".\portal" /I ".\render" /I ".\script" /I ".\shock" /I ".\sim" /I ".\sound" /I ".\ui" /I ".\dark" /I "..\..\tech\h\win32" /I "..\..\cam\h" /I "..\..\tech\h" /I "..\..\3rdsrc\dx70\include" /I "..\..\3rdsrc\h" /I "..\..\tech\libsrc\lg" /I "..\..\tech\libsrc\lgalloc" /I "..\..\tech\libsrc\compapis" /I "..\..\tech\libsrc\comtools" /I "..\..\tech\libsrc\darkloop" /I "..\..\tech\libsrc\tagfile" /I "..\..\tech\libsrc\matrix" /I "..\..\tech\libsrc\cpptools" /I "..\..\tech\libsrc\sdesc" /I "..\..\tech\libsrc\mprintf" /I "..\..\tech\libsrc\r3d" /I "..\..\tech\libsrc\config" /I "..\..\tech\libsrc\md" /I "..\..\tech\libsrc\fix" /I "..\..\tech\libsrc\prof" /I "..\..\tech\libsrc\g2" /I "..\..\tech\libsrc\dev2d" /I "..\..\tech\libsrc\namedres" /I "..\..\tech\libsrc\res" /I "..\..\tech\libsrc\mp" /I "..\..\tech\libsrc\mm" /I "..\..\tech\libsrc\inputbnd" /I "..\..\tech\libsrc\ui" /I "..\..\tech\winsrc\input" /I "..\..\tech\libsrc\dstruct" /I "..\..\tech\libsrc\gadget" /I "..\..\tech\libsrc\font" /I "..\..\tech\libsrc\sndsrc" /I "..\..\tech\libsrc\sound" /I "..\..\tech\libsrc\lgd3d" /I "..\..\tech\libsrc\timer" /I "..\..\tech\libsrc\gfile" /I "..\..\tech\libsrc\recorder" /I "..\..\tech\libsrc\star" /I "..\..\tech\libsrc\dump" /I "..\..\tech\libsrc\random" /I "..\..\tech\libsrc\net" /I "..\..\tech\libsrc\rnd" /FI"pch.h" /FI"types.h" /D "RGB_LIGHTING" /D "BIG_LIGHTMAPS" /D "SOFTWARE_RGB" /D "SCHEMA_LOADING" /D "__MSVC" /D "REPORT" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D STRICT=1 /D "EDITOR" /D "PLAYTEST" /D "NEW_NETWORK_ENABLED" /D "THIEF" /D "PROPERTY_BLAME" /FR /Yu"pch.h" /FD /c
# SUBTRACT CPP /Z<none>
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 entrywin.lib r3d.lib star.lib skel.lib mp.lib md.lib dump.lib vec2.lib prof.lib gfile.lib darkloop.lib lgd3d.lib mm.lib script.lib sndsrc.lib ref.lib sdesc.lib arq.lib inputbnd.lib input.lib namedres.lib net.lib random.lib tagfile.lib mprintf.lib lg.lib lgalloc.lib matrix.lib fix.lib dstruct.lib cpptools.lib comtools.lib templgen.lib compapis.lib appcore.lib config.lib res.lib gameshel.lib timer.lib rnd.lib recorder.lib dev2d.lib g2.lib font.lib dispdev.lib sound.lib sndutil.lib actmovie.lib quartz.lib measure.lib strmbase.lib ui.lib gadget.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib comctl32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"darked.exe" /pdbtype:sept /libpath:"\prj\thief2\lib\win32\v60\a611\dbg" /libpath:"r:\prj\thief2\lib\win32\v60\a611\dbg" /libpath:"\prj\tech\lib\win32\v60\a611\dbg" /libpath:"x:\prj\tech\lib\win32\v60\a611\dbg"
# ADD LINK32 entrywin.lib r3d.lib star.lib skel.lib mp.lib md.lib dump.lib vec2.lib prof.lib gfile.lib darkloop.lib lgd3d.lib mm.lib script.lib sndsrc.lib ref.lib sdesc.lib arq.lib inputbnd.lib input.lib namedres.lib net.lib random.lib tagfile.lib mprintf.lib lg.lib lgalloc.lib matrix.lib fix.lib dstruct.lib cpptools.lib comtools.lib templgen.lib compapis.lib appcore.lib config.lib res.lib gameshel.lib timer.lib rnd.lib recorder.lib dev2d.lib g2.lib font.lib dispdev.lib sound.lib sndutil.lib actmovie.lib quartz.lib measure.lib strmbase.lib ui.lib gadget.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib comctl32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"optdarked.exe" /pdbtype:sept /libpath:"\prj\thief2\lib\win32\v60\a611\opt" /libpath:"r:\prj\thief2\lib\win32\v60\a611\opt" /libpath:"\prj\tech\lib\win32\v60\a611\opt" /libpath:"x:\prj\tech\lib\win32\v60\a611\opt"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Dromed___Win32_Opt_No_Precompiled_Header"
# PROP BASE Intermediate_Dir "Dromed___Win32_Opt_No_Precompiled_Header"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Opt_No_Precompiled_Header"
# PROP Intermediate_Dir "Opt_No_Precompiled_Header"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /Zp1 /MT /W3 /Gi /Zd /O2 /I "." /I ".\actreact" /I ".\ai" /I ".\csg" /I ".\editor" /I ".\engfeat" /I ".\framewrk" /I ".\motion" /I ".\object" /I ".\physics" /I ".\portal" /I ".\render" /I ".\script" /I ".\shock" /I ".\sim" /I ".\sound" /I ".\ui" /I ".\dark" /I "..\..\tech\h\win32" /I "..\..\cam\h" /I "..\..\tech\h" /I "..\..\3rdsrc\dx70\include" /I "..\..\3rdsrc\h" /I "..\..\tech\libsrc\lg" /I "..\..\tech\libsrc\lgalloc" /I "..\..\tech\libsrc\compapis" /I "..\..\tech\libsrc\comtools" /I "..\..\tech\libsrc\darkloop" /I "..\..\tech\libsrc\tagfile" /I "..\..\tech\libsrc\matrix" /I "..\..\tech\libsrc\cpptools" /I "..\..\tech\libsrc\sdesc" /I "..\..\tech\libsrc\mprintf" /I "..\..\tech\libsrc\r3d" /I "..\..\tech\libsrc\config" /I "..\..\tech\libsrc\md" /I "..\..\tech\libsrc\fix" /I "..\..\tech\libsrc\prof" /I "..\..\tech\libsrc\g2" /I "..\..\tech\libsrc\dev2d" /I "..\..\tech\libsrc\namedres" /I "..\..\tech\libsrc\res" /I "..\..\tech\libsrc\mp" /I "..\..\tech\libsrc\mm" /I "..\..\tech\libsrc\inputbnd" /I "..\..\tech\libsrc\ui" /I "..\..\tech\winsrc\input" /I "..\..\tech\libsrc\dstruct" /I "..\..\tech\libsrc\gadget" /I "..\..\tech\libsrc\font" /I "..\..\tech\libsrc\sndsrc" /I "..\..\tech\libsrc\sound" /I "..\..\tech\libsrc\lgd3d" /I "..\..\tech\libsrc\timer" /I "..\..\tech\libsrc\gfile" /I "..\..\tech\libsrc\recorder" /I "..\..\tech\libsrc\star" /I "..\..\tech\libsrc\dump" /I "..\..\tech\libsrc\random" /I "..\..\tech\libsrc\net" /I "..\..\tech\libsrc\rnd" /FI"pch.h" /FI"types.h" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D STRICT=1 /D "EDITOR" /D "PLAYTEST" /D "NEW_NETWORK_ENABLED" /D "THIEF" /D "RGB_LIGHTING" /D "BIG_LIGHTMAPS" /D "SOFTWARE_RGB" /D "SCHEMA_LOADING" /D "__MSVC" /D "REPORT" /Yu"pch.h" /FD /c
# ADD CPP /nologo /Zp1 /MT /W3 /Gi /Od /I "." /I ".\actreact" /I ".\ai" /I ".\csg" /I ".\editor" /I ".\engfeat" /I ".\framewrk" /I ".\motion" /I ".\object" /I ".\physics" /I ".\portal" /I ".\render" /I ".\script" /I ".\shock" /I ".\sim" /I ".\sound" /I ".\ui" /I ".\dark" /I "..\..\tech\h\win32" /I "..\..\cam\h" /I "..\..\tech\h" /I "..\..\3rdsrc\dx70\include" /I "..\..\3rdsrc\h" /I "..\..\tech\libsrc\lg" /I "..\..\tech\libsrc\lgalloc" /I "..\..\tech\libsrc\compapis" /I "..\..\tech\libsrc\comtools" /I "..\..\tech\libsrc\darkloop" /I "..\..\tech\libsrc\tagfile" /I "..\..\tech\libsrc\matrix" /I "..\..\tech\libsrc\cpptools" /I "..\..\tech\libsrc\sdesc" /I "..\..\tech\libsrc\mprintf" /I "..\..\tech\libsrc\r3d" /I "..\..\tech\libsrc\config" /I "..\..\tech\libsrc\md" /I "..\..\tech\libsrc\fix" /I "..\..\tech\libsrc\prof" /I "..\..\tech\libsrc\g2" /I "..\..\tech\libsrc\dev2d" /I "..\..\tech\libsrc\namedres" /I "..\..\tech\libsrc\res" /I "..\..\tech\libsrc\mp" /I "..\..\tech\libsrc\mm" /I "..\..\tech\libsrc\inputbnd" /I "..\..\tech\libsrc\ui" /I "..\..\tech\winsrc\input" /I "..\..\tech\libsrc\dstruct" /I "..\..\tech\libsrc\gadget" /I "..\..\tech\libsrc\font" /I "..\..\tech\libsrc\sndsrc" /I "..\..\tech\libsrc\sound" /I "..\..\tech\libsrc\lgd3d" /I "..\..\tech\libsrc\timer" /I "..\..\tech\libsrc\gfile" /I "..\..\tech\libsrc\recorder" /I "..\..\tech\libsrc\star" /I "..\..\tech\libsrc\dump" /I "..\..\tech\libsrc\random" /I "..\..\tech\libsrc\net" /I "..\..\tech\libsrc\rnd" /FI"types.h" /D "RGB_LIGHTING" /D "BIG_LIGHTMAPS" /D "SOFTWARE_RGB" /D "SCHEMA_LOADING" /D "__MSVC" /D "REPORT" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D STRICT=1 /D "EDITOR" /D "PLAYTEST" /D "NEW_NETWORK_ENABLED" /D "THIEF" /D "PROPERTY_BLAME" /FR /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"dromed.bsc"
LINK32=link.exe
# ADD BASE LINK32 entrywin.lib r3d.lib star.lib skel.lib mp.lib md.lib dump.lib vec2.lib prof.lib gfile.lib darkloop.lib lgd3d.lib mm.lib script.lib sndsrc.lib ref.lib sdesc.lib arq.lib inputbnd.lib input.lib namedres.lib net.lib random.lib tagfile.lib mprintf.lib lg.lib lgalloc.lib matrix.lib fix.lib dstruct.lib cpptools.lib comtools.lib templgen.lib compapis.lib appcore.lib config.lib res.lib gameshel.lib timer.lib rnd.lib recorder.lib dev2d.lib g2.lib font.lib dispdev.lib sound.lib sndutil.lib actmovie.lib quartz.lib measure.lib strmbase.lib ui.lib gadget.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib comctl32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"optdarked.exe" /pdbtype:sept /libpath:"\prj\thief2\lib\win32\v60\a611\opt" /libpath:"r:\prj\thief2\lib\win32\v60\a611\opt" /libpath:"\prj\tech\lib\win32\v60\a611\opt" /libpath:"x:\prj\tech\lib\win32\v60\a611\opt"
# ADD LINK32 entrywin.lib r3d.lib star.lib skel.lib mp.lib md.lib dump.lib vec2.lib prof.lib gfile.lib darkloop.lib lgd3d.lib mm.lib script.lib sndsrc.lib ref.lib sdesc.lib arq.lib inputbnd.lib input.lib namedres.lib net.lib random.lib tagfile.lib mprintf.lib lg.lib lgalloc.lib matrix.lib fix.lib dstruct.lib cpptools.lib comtools.lib templgen.lib compapis.lib appcore.lib config.lib res.lib gameshel.lib timer.lib rnd.lib recorder.lib dev2d.lib g2.lib font.lib dispdev.lib sound.lib sndutil.lib actmovie.lib quartz.lib measure.lib strmbase.lib ui.lib gadget.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib comctl32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"optnopchdarked.exe" /pdbtype:sept /libpath:"\prj\thief2\lib\win32\v60\a611\opt" /libpath:"r:\prj\thief2\lib\win32\v60\a611\opt" /libpath:"\prj\tech\lib\win32\v60\a611\opt" /libpath:"x:\prj\tech\lib\win32\v60\a611\opt"

!ENDIF 

# Begin Target

# Name "Dromed - Win32 Release"
# Name "Dromed - Win32 Debug"
# Name "Dromed - Win32 Opt"
# Name "Dromed - Win32 Opt No Precompiled Header"
# Begin Group "Act/React"

# PROP Default_Filter ""
# Begin Group "Act/React Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\actreact\Aredit.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Arloop.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Contag8r.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Ctactbas.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Dumbprox.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Medg8rid.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Mediag8r.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Perig8id.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Periog8r.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Pg8rbase.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Pg8rnull.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Pg8rtype.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Propag8n.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Propag8r.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Prpag8n_.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Prpag8r_.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Radiag8r.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Reacbase.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Reactio_.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Reaction.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Reactype.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Receptro.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Sensbase.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Senstype.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Ssrcbase.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Ssrclife.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Ssrctype.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimbase.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimguid.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimprop.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimqfct.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimsen_.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimsens.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimsrc.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimsrc_.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimtype.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimul8_.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimul8r.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimuli.h
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimuli_.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\actreact\Arloop.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Contag8r.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Dumbprox.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Mediag8r.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Periog8r.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Pg8rnull.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Propag8n.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Propag8r.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Radiag8r.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Reaction.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Ssrclife.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimbase.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimguid.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\actreact\Stimsens.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimsrc.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimul8r.cpp
# End Source File
# Begin Source File

SOURCE=.\actreact\Stimuli.cpp
# End Source File
# End Group
# Begin Group "AI"

# PROP Default_Filter ""
# Begin Group "AI Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ai\Ai.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactcst.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactfol.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactfrb.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactinv.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactjr.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactjs.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactjsc.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactlch.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactloc.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactmot.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactmov.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactmrk.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactori.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactprx.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactps.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactrng.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactseq.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactsnd.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiacttyp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactwnd.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactwt.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aialert.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aialtrsp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapi.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapiabl.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapiact.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapiatr.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapibhv.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapicmp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapidbq.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapiiai.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapiinf.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapimov.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapinet.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapipth.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapisnd.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiapisns.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiavoid.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiaware.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasabl.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasact.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasatm.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasatr.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasbhv.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aibascmp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasctm.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasmrg.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aibassns.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aibdyrsp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicamera.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbhtoh.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicblink.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrbkp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrclo.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrfle.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbridl.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrlct.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrloc.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrmds.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrmod.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrmpr.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrnew.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrngd.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrsht.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrstl.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrstr.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrtyp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrvan.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrwnd.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbtrsp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicdummy.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicmds.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicnvabl.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicnvapi.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicnvman.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicnvrse.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicombat.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicpinit.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aicretsz.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aictlsig.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aidbdraw.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aidbgcmp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aideath.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aidebug.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aidefend.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aidetect.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aidev.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aidfndpt.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aidist.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aidodgep.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aidoormr.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aie3bhv.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiflee.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aifollow.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aifreeze.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aigests.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aigoal.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiground.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiguard.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiguid.h
# End Source File
# Begin Source File

SOURCE=.\Ai\Aigunact.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiidle.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiinform.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiinvest.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiinvtyp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Ailisten.h
# End Source File
# Begin Source File

SOURCE=.\ai\Ailoop.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiman.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aimanbhv.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aimove.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aimovsug.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aimplyr.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aimttest.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aimultcb.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aincbdmg.h
# End Source File
# Begin Source File

SOURCE=.\ai\Ainet.h
# End Source File
# Begin Source File

SOURCE=.\ai\Ainoncbt.h
# End Source File
# Begin Source File

SOURCE=.\ai\Ainonhst.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiokbits.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipath.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipathdb.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipatrol.h
# End Source File
# Begin Source File

SOURCE=.\Ai\aiphycst.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprabil.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprattr.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprconv.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprcore.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprdev.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprops.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiproxy.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprrngd.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprutil.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipsdscr.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthbas.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthcst.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthdbg.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthedg.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthfnd.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthloc.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthobb.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthqry.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthtyp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthzon.h
# End Source File
# Begin Source File

SOURCE=.\Ai\Aiqdeath.h
# End Source File
# Begin Source File

SOURCE=.\ai\Airecovr.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aireport.h
# End Source File
# Begin Source File

SOURCE=.\ai\Airngwpn.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aisched.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiscrabl.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiscrm.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiscrpt.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiscrt.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aisgtcst.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aisignal.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aisndtyp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aisnsdev.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aisound.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aistdmrg.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aistnapi.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aistun.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aisubabl.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aisubcb.h
# End Source File
# Begin Source File

SOURCE=.\Ai\Aisuslnk.h
# End Source File
# Begin Source File

SOURCE=.\Ai\Aisusrsp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aitagtyp.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiteams.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aitest.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aithreat.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aitrace.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aitrginf.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aitrig.h
# End Source File
# Begin Source File

SOURCE=.\Ai\Aiturbs.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiturret.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aitype.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiutils.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aivision.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiwatch.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiwr.h
# End Source File
# Begin Source File

SOURCE=.\ai\Aiwtctyp.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ai\Ai.cpp
# End Source File
# Begin Source File

SOURCE=.\Ai\Aiactcst.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ai\Aiactfol.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactfrb.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactinv.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactjr.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactjs.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactjsc.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactlch.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactloc.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactmot.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactmov.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactmrk.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactnet.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactori.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactprx.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactps.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactrng.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactseq.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactsnd.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactwnd.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiactwt.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aialtrsp.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiavoid.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiaware.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasabl.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasact.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasatm.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasbhv.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasctm.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aibasmrg.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aibassns.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aibdyrsp.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicamera.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbhtoh.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrbkp.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrclo.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrfle.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbridl.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrloc.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrmod.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrmpr.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrnew.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrngd.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrsht.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrstl.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrstr.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrvan.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ai\Aicbrwnd.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicbtrsp.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicdummy.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicmds.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicnvabl.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicnvman.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicnvrse.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicombat.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicpinit.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aicretsz.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aidbdraw.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aidbgcmp.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aideath.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aidebug.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aidefend.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aidetect.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aidev.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aidodgep.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aidoormr.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aie3bhv.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiflee.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aifollow.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aifreeze.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aigoal.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiground.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiguard.cpp
# End Source File
# Begin Source File

SOURCE=.\Ai\Aigunact.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiidle.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiinform.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiinvest.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Ailisten.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiman.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aimove.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aimovmot.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aimovsug.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aimplyr.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aimttest.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aimultcb.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aincbdmg.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Ainet.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Ainetman.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Ainoncbt.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aipath.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aipathdb.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aipatrol.cpp
# End Source File
# Begin Source File

SOURCE=.\Ai\aiphycst.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprabil.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprattr.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprconv.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprcore.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# ADD CPP /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD BASE CPP /Yu
# ADD CPP /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# ADD BASE CPP /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ai\Aiprdev.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprops.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiproxy.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprrngd.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiprutil.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthcst.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthdbg.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthedg.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthfnd.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthloc.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthobb.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aipthzon.cpp
# End Source File
# Begin Source File

SOURCE=.\Ai\Aiqdeath.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Airecovr.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aireport.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiscrabl.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aisgtcst.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aisnsdev.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aisound.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aistdmrg.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aistun.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aisubabl.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aisubcb.cpp
# End Source File
# Begin Source File

SOURCE=.\Ai\Aisuslnk.cpp
# End Source File
# Begin Source File

SOURCE=.\Ai\Aisusrsp.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aitagtyp.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiteams.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aitest.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aithreat.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aitrig.cpp
# End Source File
# Begin Source File

SOURCE=.\Ai\Aiturbs.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiturret.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiutils.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiwatch.cpp
# End Source File
# Begin Source File

SOURCE=.\ai\Aiwr.cpp
# End Source File
# End Group
# Begin Group "CSG"

# PROP Default_Filter ""
# Begin Group "CSG Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\csg\Bspdata.h
# End Source File
# Begin Source File

SOURCE=.\csg\Csg.h
# End Source File
# Begin Source File

SOURCE=.\csg\Csgalloc.h
# End Source File
# Begin Source File

SOURCE=.\csg\Csgbbox.h
# End Source File
# Begin Source File

SOURCE=.\csg\Csgcheck.h
# End Source File
# Begin Source File

SOURCE=.\csg\Csgmerge.h
# End Source File
# Begin Source File

SOURCE=.\csg\Csgutil.h
# End Source File
# Begin Source File

SOURCE=.\csg\Hep.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\csg\Bspdata.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csg.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csgalloc.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csgbbox.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csgbuild.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csgcheck.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csgclip.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csgcube.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csgdecal.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csgemit.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csgfind.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csgmedia.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csgmerge.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Csgutil.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\csg\Hep.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# End Group
# Begin Group "Dark"

# PROP Default_Filter ""
# Begin Group "Dark Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\dark\Afpfiles.h
# End Source File
# Begin Source File

SOURCE=.\dark\Bowscrpt.h
# End Source File
# Begin Source File

SOURCE=.\dark\Brethiid.h
# End Source File
# Begin Source File

SOURCE=.\dark\Brethprp.h
# End Source File
# Begin Source File

SOURCE=.\dark\Ccrhuman.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crappa.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crbowarm.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crbugbst.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crburrik.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crconsta.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crcraymn.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crcutty.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crfrog.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crhumand.h
# End Source File
# Begin Source File

SOURCE=.\Dark\Crjoint.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crplyarm.h
# End Source File
# Begin Source File

SOURCE=.\Dark\Crrobot.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crrope.h
# End Source File
# Begin Source File

SOURCE=.\Dark\Crsmrbt.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crspider.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crspidsm.h
# End Source File
# Begin Source File

SOURCE=.\Dark\crspirob.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crsweel.h
# End Source File
# Begin Source File

SOURCE=.\dark\Crzombie.h
# End Source File
# Begin Source File

SOURCE=.\dark\Daicam.h
# End Source File
# Begin Source File

SOURCE=.\dark\Daielem.h
# End Source File
# Begin Source File

SOURCE=.\dark\Daifrog.h
# End Source File
# Begin Source File

SOURCE=.\dark\Darkai.h
# End Source File
# Begin Source File

SOURCE=.\dark\Dbrfguid.h
# End Source File
# Begin Source File

SOURCE=.\dark\Diffscrm.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drk_bind.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkafp.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkamap.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkbndui.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkbook.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkbreth.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkchkcd.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkcmbat.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkcolor.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkcret.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkdebrf.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkdiff.h
# End Source File
# Begin Source File

SOURCE=.\Dark\drkfixpr.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkgame.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkgoalr.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkgoalt.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkienum.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkinit.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkinv.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkinvid.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkinvpr.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkinvsc.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkinvui.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkldout.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drklinks.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkloop.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkloot.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkloot_.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkmenu.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkmisid.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkmislp.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkmiss.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkmsg.h
# End Source File
# Begin Source File

SOURCE=.\Dark\Drknetap.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkpanid.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkpanl.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkplinv.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkpwscr.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkpwups.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkreact.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkrend.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkreprt.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkrphlp.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkrutil.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drksave.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drksavui.h
# End Source File
# Begin Source File

SOURCE=.\Dark\drkscrm.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkscrpt.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkscrs.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drksound.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkstats.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkuires.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkuiscr.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkvo.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkwbdy.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkwbow.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkwbow_.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkwswd.h
# End Source File
# Begin Source File

SOURCE=.\dark\Drkwswd_.h
# End Source File
# Begin Source File

SOURCE=.\dark\Eidosafp.h
# End Source File
# Begin Source File

SOURCE=.\dark\Filepanl.h
# End Source File
# Begin Source File

SOURCE=.\dark\Gadslide.h
# End Source File
# Begin Source File

SOURCE=.\dark\Invtype.h
# End Source File
# Begin Source File

SOURCE=.\dark\Lootiid.h
# End Source File
# Begin Source File

SOURCE=.\dark\Lootprop.h
# End Source File
# Begin Source File

SOURCE=.\Dark\Meshprop.h
# End Source File
# Begin Source File

SOURCE=.\dark\Metagame.h
# End Source File
# Begin Source File

SOURCE=.\dark\Metaguid.h
# End Source File
# Begin Source File

SOURCE=.\dark\Pickbase.h
# End Source File
# Begin Source File

SOURCE=.\dark\Picklock.h
# End Source File
# Begin Source File

SOURCE=.\Dark\Pickscrm.h
# End Source File
# Begin Source File

SOURCE=.\dark\Pickscrs.h
# End Source File
# Begin Source File

SOURCE=.\dark\Plyscrpt.h
# End Source File
# Begin Source File

SOURCE=.\dark\Statbar.h
# End Source File
# Begin Source File

SOURCE=.\dark\Stubfile.h
# End Source File
# Begin Source File

SOURCE=.\dark\Vismeter.h
# End Source File
# Begin Source File

SOURCE=.\dark\Weapscpt.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\dark\Bowscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Ccrappa.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Ccrbug.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Ccrcray.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Ccrhuman.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Crappa.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Crbowarm.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Crbugbst.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Crburrik.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Crconsta.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Crcraymn.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Crcutty.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Crfrog.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Crhumand.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Dark\Crjoint.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Crplyarm.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Dark\Crrobot.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Crrope.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Dark\Crsmrbt.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Crspider.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Crspidsm.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Dark\crspirob.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Crsweel.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Crzombie.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Daicam.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Daielem.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Daifrog.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Darkai.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drk_bind.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkamap.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkbook.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkbreth.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkchkcd.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkcmbat.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkcolor.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkcret.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkdebrf.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkdiff.cpp
# End Source File
# Begin Source File

SOURCE=.\Dark\drkfixpr.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkgame.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkgoalr.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkinit.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Drkinv.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Drkinvpr.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkinvsc.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkinvui.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkldout.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drklinks.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkloop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Drkloot.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkmenu.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkmislp.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkmiss.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkmsg.cpp
# End Source File
# Begin Source File

SOURCE=.\Dark\Drknetap.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkoptmn.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkpanl.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkplinv.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkpwscr.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkpwups.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkreact.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkrend.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Drkreprt.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkrloop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Drkrutil.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drksave.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drksavui.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkscrs.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drksloop.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drksound.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkstats.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkuires.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkuiscr.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# ADD CPP /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD BASE CPP /Yu
# ADD CPP /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# ADD BASE CPP /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Drkvo.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkwbdy.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkwbow.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkwbow_.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Drkwswd.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Drkwswd_.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Eidosafp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Filepanl.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Gadslide.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Lootprop.cpp
# End Source File
# Begin Source File

SOURCE=.\Dark\Meshprop.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Metagame.cpp
# End Source File
# Begin Source File

SOURCE=.\Dark\Pick.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dark\Picklock.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Pickscrs.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Plyscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Statbar.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Vismeter.cpp
# End Source File
# Begin Source File

SOURCE=.\dark\Weapscpt.cpp
# End Source File
# End Group
# Begin Group "Editor"

# PROP Default_Filter ""
# Begin Group "Editor Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\editor\Areapnp.h
# End Source File
# Begin Source File

SOURCE=.\editor\Autovbr.h
# End Source File
# Begin Source File

SOURCE=.\editor\Bldstair.h
# End Source File
# Begin Source File

SOURCE=.\editor\Brestore.h
# End Source File
# Begin Source File

SOURCE=.\editor\Brinfo.h
# End Source File
# Begin Source File

SOURCE=.\editor\Brlist.h
# End Source File
# Begin Source File

SOURCE=.\editor\Brloop.h
# End Source File
# Begin Source File

SOURCE=.\editor\Brobjpro.h
# End Source File
# Begin Source File

SOURCE=.\EDITOR\BRPROPLG.H
# End Source File
# Begin Source File

SOURCE=.\editor\Brquery.h
# End Source File
# Begin Source File

SOURCE=.\editor\Brrend.h
# End Source File
# Begin Source File

SOURCE=.\editor\Brtypes.h
# End Source File
# Begin Source File

SOURCE=.\editor\Brundo.h
# End Source File
# Begin Source File

SOURCE=.\editor\Brushgfh.h
# End Source File
# Begin Source File

SOURCE=.\editor\Cmdbutts.h
# End Source File
# Begin Source File

SOURCE=.\editor\Csgbrush.h
# End Source File
# Begin Source File

SOURCE=.\editor\Cvtbrush.h
# End Source File
# Begin Source File

SOURCE=.\editor\Cyclegad.h
# End Source File
# Begin Source File

SOURCE=.\editor\Doorblok.h
# End Source File
# Begin Source File

SOURCE=.\editor\Dragbox.h
# End Source File
# Begin Source File

SOURCE=.\editor\Edinhst.h
# End Source File
# Begin Source File

SOURCE=.\editor\Edinhtyp.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editapp.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editbr.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editbr_.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editbrs.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editgeo_.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editgeom.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editinh.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editlink.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editmode.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editobj.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editplst.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editprop.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editprst.h
# End Source File
# Begin Source File

SOURCE=.\editor\Editsave.h
# End Source File
# Begin Source File

SOURCE=.\editor\Edittul_.h
# End Source File
# Begin Source File

SOURCE=.\editor\Edlinkst.h
# End Source File
# Begin Source File

SOURCE=.\editor\Edlnktyp.h
# End Source File
# Begin Source File

SOURCE=.\editor\Edmedmo.h
# End Source File
# Begin Source File

SOURCE=.\editor\Edmedmos.h
# End Source File
# Begin Source File

SOURCE=.\editor\Edmedmot.h
# End Source File
# Begin Source File

SOURCE=.\editor\Famedit.h
# End Source File
# Begin Source File

SOURCE=.\editor\Filemenu.h
# End Source File
# Begin Source File

SOURCE=.\editor\Fvaredit.h
# End Source File
# Begin Source File

SOURCE=.\editor\Ged_csg.h
# End Source File
# Begin Source File

SOURCE=.\editor\Ged_line.h
# End Source File
# Begin Source File

SOURCE=.\editor\Ged_rend.h
# End Source File
# Begin Source File

SOURCE=.\editor\Ged_rmap.h
# End Source File
# Begin Source File

SOURCE=.\editor\Ged_room.h
# End Source File
# Begin Source File

SOURCE=.\editor\Ged_undo.h
# End Source File
# Begin Source File

SOURCE=.\editor\Gedit.h
# End Source File
# Begin Source File

SOURCE=.\editor\Gedmedmo.h
# End Source File
# Begin Source File

SOURCE=.\editor\Gfhfrobs.h
# End Source File
# Begin Source File

SOURCE=.\editor\Gridsnap.h
# End Source File
# Begin Source File

SOURCE=.\editor\Hilight.h
# End Source File
# Begin Source File

SOURCE=.\editor\Isdesced.h
# End Source File
# Begin Source File

SOURCE=.\editor\Isdescst.h
# End Source File
# Begin Source File

SOURCE=.\editor\Isdescty.h
# End Source File
# Begin Source File

SOURCE=.\editor\Lgslider.h
# End Source File
# Begin Source File

SOURCE=.\editor\Linkdraw.h
# End Source File
# Begin Source File

SOURCE=.\editor\Linkedit.h
# End Source File
# Begin Source File

SOURCE=.\editor\Lnktrai_.h
# End Source File
# Begin Source File

SOURCE=.\editor\Lnktrait.h
# End Source File
# Begin Source File

SOURCE=.\editor\Medflbox.h
# End Source File
# Begin Source File

SOURCE=.\editor\Mediface.h
# End Source File
# Begin Source File

SOURCE=.\editor\Medmenu.h
# End Source File
# Begin Source File

SOURCE=.\editor\Medplay.h
# End Source File
# Begin Source File

SOURCE=.\editor\Menus.h
# End Source File
# Begin Source File

SOURCE=.\editor\Modalui.h
# End Source File
# Begin Source File

SOURCE=.\editor\Motedit.h
# End Source File
# Begin Source File

SOURCE=.\editor\Motedit_.h
# End Source File
# Begin Source File

SOURCE=.\editor\Namenum.h
# End Source File
# Begin Source File

SOURCE=.\editor\Objedit.h
# End Source File
# Begin Source File

SOURCE=.\editor\Objhistp.h
# End Source File
# Begin Source File

SOURCE=.\editor\Otreeed.h
# End Source File
# Begin Source File

SOURCE=.\editor\Pnptool_.h
# End Source File
# Begin Source File

SOURCE=.\editor\Pnptools.h
# End Source File
# Begin Source File

SOURCE=.\editor\Pnpvslid.h
# End Source File
# Begin Source File

SOURCE=.\editor\Preload.h
# End Source File
# Begin Source File

SOURCE=.\editor\Primal.h
# End Source File
# Begin Source File

SOURCE=.\editor\Primals.h
# End Source File
# Begin Source File

SOURCE=.\editor\Primfast.h
# End Source File
# Begin Source File

SOURCE=.\editor\Primshap.h
# End Source File
# Begin Source File

SOURCE=.\editor\Prompts.h
# End Source File
# Begin Source File

SOURCE=.\editor\Proped.h
# End Source File
# Begin Source File

SOURCE=.\editor\Proptest.h
# End Source File
# Begin Source File

SOURCE=.\Editor\Psdialog.h
# End Source File
# Begin Source File

SOURCE=.\editor\Quesedit.h
# End Source File
# Begin Source File

SOURCE=.\editor\Rendtest.h
# End Source File
# Begin Source File

SOURCE=.\Editor\Roomtowr.h
# End Source File
# Begin Source File

SOURCE=.\editor\Saveload.h
# End Source File
# Begin Source File

SOURCE=.\editor\Scrnedit.h
# End Source File
# Begin Source File

SOURCE=.\editor\Scrpted.h
# End Source File
# Begin Source File

SOURCE=.\editor\Sdesedit.h
# End Source File
# Begin Source File

SOURCE=.\editor\Sdesedst.h
# End Source File
# Begin Source File

SOURCE=.\editor\Sdesparm.h
# End Source File
# Begin Source File

SOURCE=.\editor\Simpwrap.h
# End Source File
# Begin Source File

SOURCE=.\editor\Status.h
# End Source File
# Begin Source File

SOURCE=.\editor\Stupidui.h
# End Source File
# Begin Source File

SOURCE=.\editor\Swappnp.h
# End Source File
# Begin Source File

SOURCE=.\editor\Swaptool.h
# End Source File
# Begin Source File

SOURCE=.\editor\Txtpnp.h
# End Source File
# Begin Source File

SOURCE=.\editor\Txtrpal.h
# End Source File
# Begin Source File

SOURCE=.\editor\Uiedit.h
# End Source File
# Begin Source File

SOURCE=.\editor\Undoredo.h
# End Source File
# Begin Source File

SOURCE=.\editor\Userpnp.h
# End Source File
# Begin Source File

SOURCE=.\editor\Vbr_math.h
# End Source File
# Begin Source File

SOURCE=.\editor\Vbrush.h
# End Source File
# Begin Source File

SOURCE=.\editor\Viewmgr.h
# End Source File
# Begin Source File

SOURCE=.\editor\Viewmgr_.h
# End Source File
# Begin Source File

SOURCE=.\editor\Vmwincfg.h
# End Source File
# Begin Source File

SOURCE=.\editor\Vslider.h
# End Source File
# Begin Source File

SOURCE=.\editor\Vsliderg.h
# End Source File
# Begin Source File

SOURCE=.\editor\Vumanui.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\editor\Alignpnp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Arcmd.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Areapnp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Autovbr.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Bldstair.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Brinfo.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Brlist.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Brloop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Brobjpro.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Brprop.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Brquery.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Brrend.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Brundo.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Brushgfh.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Cmdbutts.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Convpred.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Cvtbrush.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Cyclegad.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Doorblok.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Dragbox.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Editapp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Editbr.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Editgeom.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Editlink.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Editmode.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Editobj.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Editplst.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Editprop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Editsave.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Edmedmo.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Famedit.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Filemenu.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Flowpnp.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Fvaredit.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Ged_csg.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Ged_line.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Ged_rend.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Ged_rmap.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Ged_room.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Ged_undo.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Gedit.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Gedmedmo.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Gfhfrobs.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Gridpnp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Gridsnap.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Hilight.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Isdesced.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Lgslider.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Lightpnp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Linkdraw.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Linkedit.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Lnktrait.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Medflbox.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Mediface.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Medmenu.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Medplay.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Menus.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Modalui.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Motedit.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Namenum.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Objed.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Objedit.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Objhistp.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Objpnp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Otreeed.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Phproped.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Pnpslide.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Pnptools.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Preload.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Primal.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Primshap.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Prompts.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Proped.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Proptest.cpp
# End Source File
# Begin Source File

SOURCE=.\Editor\Psdialog.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Quesedit.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Rendtest.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Roompnp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Editor\Roomtowr.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Saveload.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Scrnedit.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Scrpted.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Sdesparm.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Simpwrap.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Status.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Strprped.cpp
# End Source File
# Begin Source File

SOURCE=.\editor\Stupidui.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Swappnp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Swapregs.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Swaptool.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Txtpnp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Txtrpal.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Uiedit.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Undoredo.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Userpnp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Vbr_math.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Vbrush.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Viewmgr.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Vmwincfg.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Vslider.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\editor\Vumanui.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# End Group
# Begin Group "Engine Features"

# PROP Default_Filter ""
# Begin Group "Engine Features Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\engfeat\Amapguid.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Automap.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Autoprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Campaign.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Cmpgniid.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Cmpgnmsg.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Combprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Contain.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Contiid.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Contprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Culpable.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Dmgbase.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Dmgguid.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Dmgmodel.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Dmgmodl_.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Dmgprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Engfeat.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Engfloop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Engfprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Flinder.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Frobctrl.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Frobprop.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Gunanim.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Gunapi.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Gunbase.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Gunflash.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Gunprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Hpprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Inv_hack.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Inv_rend.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Invlimb.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Invrguid.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Invrndpr.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Keyprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Keysys.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Keytype.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Lockprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Media.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Mediaop.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Nzprutil.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Ownprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Pick.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Preldprp.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Projbase.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Projlink.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Projprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Propreac.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Quesfile.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Quesloop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Quesreac.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Quest.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Questapi.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Questiid.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Questprp.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Qvpropid.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Simpdmg_.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Simpldmg.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Susprop.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Tfint.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Trapprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Tweqbase.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Tweqctrl.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Tweqenum.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Tweqexp.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Tweqflgs.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Tweqprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Tweqrep.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Twqprop_.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weapbow.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weapcb.h
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Weapguid.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weaphalo.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weaphit.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weapon.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weapprop.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weapreac.h
# End Source File
# Begin Source File

SOURCE=.\engfeat\X10guish.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\engfeat\Automap.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\engfeat\Campaign.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Contain.cpp
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Contprop.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Dmgmodel.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Dmgprop.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Dmgreact.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Engfeat.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Flinder.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Frobctrl.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Frobprop.cpp
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Gunflash.cpp
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Gunprop.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Hpprop.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Inv_hack.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\engfeat\Inv_rend.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\engfeat\Invlimb.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Invrndpr.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Keysys.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Lockprop.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Ownprop.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Pick.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Preldprp.cpp
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Projlink.cpp
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Projprop.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Propreac.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Quesloop.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Quesreac.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Quest.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Questprp.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Simpdmg.cpp
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Susprop.cpp
# End Source File
# Begin Source File

SOURCE=.\Engfeat\Trapprop.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Tweqctrl.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Tweqprop.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Tweqrep.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weapbow.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\engfeat\Weapcb.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weaphalo.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weaphit.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weapon.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weapprop.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\Weapreac.cpp
# End Source File
# Begin Source File

SOURCE=.\engfeat\X10guish.cpp
# End Source File
# End Group
# Begin Group "Framework"

# PROP Default_Filter ""
# Begin Group "Framework Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\framewrk\2dapp.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Appname.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Backup.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Basemode.h
# End Source File
# Begin Source File

SOURCE=.\Framewrk\buftagf.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Cdconst.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Cdguid.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Cdplayer.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Cfgtool.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Chainevt.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Command.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Contexts.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Ctag.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Ctagnet.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Ctagset.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dappsink.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dbasemsg.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dbfile.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dbtagfil.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dbtype.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Diskfree.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dispapp.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dispbase.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dlgloop.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dlgmode.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dpshell.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dspchdef.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dspchiid.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dwordset.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dxload.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dxwrndlg.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Fastflts.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Fcytagdb.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Filetool.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Filevar.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Fixtime.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Fltang.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Fvarloop.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gameapp.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gamecam.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gameinfo.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gamemode.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gamemsg.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gamescrn.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gamespec.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gamestr.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gametabl.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gametool.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gen_bind.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Hchkthrd.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Idispat_.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Idispatc.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Imgsrc.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Imgsrcid.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Inetstat.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Init.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\lgdispatch.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Loopapp.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Loopmsg.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Lr_cache.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Lres_.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Lresdisk.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Lreshash.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Lresname.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Lress.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Lrestok.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Matrixc.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Namemap.h
# End Source File
# Begin Source File

SOURCE=.\Framewrk\Netapp.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Netloop.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Netmsg.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Netsim.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Netsynch.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Netvoice.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Pickgame.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\R3app.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Rand.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Report.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Reprthlp.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Reputil.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Resapp.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Resdata.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Resdefs2.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Resloop.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Resource.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Respaths.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Rn_cnvrt.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Scrndump.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Subscrip.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tag.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagbase.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagconst.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagdbdat.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagdbin.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagdbkey.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagdbkst.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagdbout.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagdbt.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagpatch.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagremap.h
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagtype.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\framewrk\2dapp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Appname.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Backup.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Basemode.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Framewrk\buftagf.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Cdplayer.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Cfgtool.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Chainevt.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Command.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Ctag.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# ADD CPP /D "NO_PCH"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD BASE CPP /D "NO_PCH"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /D "NO_PCH"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# ADD BASE CPP /D "NO_PCH"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /D "NO_PCH"
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Ctagnet.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Ctagset.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# ADD CPP /D "NO_PCH"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD BASE CPP /D "NO_PCH"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /D "NO_PCH"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# ADD BASE CPP /D "NO_PCH"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /D "NO_PCH"
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Dappsink.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dbfile.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Diskfree.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Dispatch.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dlgloop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Dlgmode.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Dxload.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Dxwrndlg.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Fcytagdb.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Filetool.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Filevar.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Fltang.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gameapp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Gameiid.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Gameinfo.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Gamemode.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Gamescrn.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gamestr.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gametool.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Gen_bind.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Hchkthrd.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Hybtable.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Imgsrc.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Init.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Initedit.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Initgame.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Loopapp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Lr_cache.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Lresdisk.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Lreshash.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Lresname.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Main.cpp
# End Source File
# Begin Source File

SOURCE=.\Framewrk\Missblat.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Missdiff.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Misstrip.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Namemap.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Netman.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# ADD CPP /D "NO_PCH"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD BASE CPP /D "NO_PCH"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /D "NO_PCH"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# ADD BASE CPP /D "NO_PCH"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /D "NO_PCH"
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Netmsg.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Netprops.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Netsim.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Netsynch.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Netvoice.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Pickgame.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\R3app.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Rand.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Report.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Reprthlp.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Reputil.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Resapp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Resdata.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Resloop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Rn_cnvrt.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1
# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1
# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\framewrk\Scrndump.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Subscrip.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagdbdat.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagdbin.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagdbkey.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagdbkst.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagdbout.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagpatch.cpp
# End Source File
# Begin Source File

SOURCE=.\framewrk\Tagremap.cpp
# End Source File
# End Group
# Begin Group "Motion"

# PROP Default_Filter ""
# Begin Group "Motion Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\motion\Biploop.h
# End Source File
# Begin Source File

SOURCE=.\motion\Cbllmapi.h
# End Source File
# Begin Source File

SOURCE=.\motion\Cbllmtyp.h
# End Source File
# Begin Source File

SOURCE=.\motion\Crattach.h
# End Source File
# Begin Source File

SOURCE=.\motion\Creatapi.h
# End Source File
# Begin Source File

SOURCE=.\motion\Creatext.h
# End Source File
# Begin Source File

SOURCE=.\motion\Creatur_.h
# End Source File
# Begin Source File

SOURCE=.\motion\Creature.h
# End Source File
# Begin Source File

SOURCE=.\motion\Cretprop.h
# End Source File
# Begin Source File

SOURCE=.\motion\Crettype.h
# End Source File
# Begin Source File

SOURCE=.\motion\Crexp.h
# End Source File
# Begin Source File

SOURCE=.\motion\Crjoint.h
# End Source File
# Begin Source File

SOURCE=.\Motion\Crwpnapi.h
# End Source File
# Begin Source File

SOURCE=.\Motion\Crwpnlst.h
# End Source File
# Begin Source File

SOURCE=.\Motion\Crwpnlup.h
# End Source File
# Begin Source File

SOURCE=.\motion\Imotiid.h
# End Source File
# Begin Source File

SOURCE=.\motion\Imottab.h
# End Source File
# Begin Source File

SOURCE=.\motion\Locobase.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mclntapi.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mcoord.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mctype.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mctype_.h
# End Source File
# Begin Source File

SOURCE=.\motion\Meshapi.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mmanuver.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mmnvrfac.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mmresapi.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motbase.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motdb.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motdb_.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motdbase.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motdbtyp.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motdesc.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motdmng_.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motdmnge.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motmngr.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motorapi.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motprop.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motrtype.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motschem.h
# End Source File
# Begin Source File

SOURCE=.\motion\Motset.h
# End Source File
# Begin Source File

SOURCE=.\Motion\mottype.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mputil.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mschbase.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mschtok.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mschtype.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mschutil.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mschyacc.h
# End Source File
# Begin Source File

SOURCE=.\Motion\mseltype.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mskilset.h
# End Source File
# Begin Source File

SOURCE=.\Motion\Mskltree.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mskltype.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mtagvals.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mvrflags.h
# End Source File
# Begin Source File

SOURCE=.\motion\Mvrutils.h
# End Source File
# Begin Source File

SOURCE=.\motion\Puppet.h
# End Source File
# Begin Source File

SOURCE=.\motion\Pupprop.h
# End Source File
# Begin Source File

SOURCE=.\Motion\Skildtab.h
# End Source File
# Begin Source File

SOURCE=.\Motion\Skillset.h
# End Source File
# Begin Source File

SOURCE=.\Motion\Skilltab.h
# End Source File
# Begin Source File

SOURCE=.\Motion\Skilltyp.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\motion\Biploop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\motion\Cerebllm.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Crattach.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Creature.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Cretprop.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Crexp.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Crjoint.cpp
# End Source File
# Begin Source File

SOURCE=.\Motion\Crwpnapi.cpp
# End Source File
# Begin Source File

SOURCE=.\Motion\Crwpnlst.cpp
# End Source File
# Begin Source File

SOURCE=.\Motion\Crwpnlup.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Mcoord.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Motdb.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Motdesc.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Motdmnge.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\motion\Motmngr.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Motprop.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Motschem.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Motset.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Mputil.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Mschutil.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Mschyacc.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\motion\Mskilset.cpp
# End Source File
# Begin Source File

SOURCE=.\Motion\Mskltree.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Mvrcmbat.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Mvrflags.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Mvrflbow.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Mvrgact.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Mvrglide.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\motion\Mvrgloco.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Mvrplyr.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Mvrsngle.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Mvrtport.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\motion\Mvrutils.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Puppet.cpp
# End Source File
# Begin Source File

SOURCE=.\motion\Pupprop.cpp
# End Source File
# Begin Source File

SOURCE=.\Motion\Skildtab.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\motion\Skillset.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Motion\Skilltab.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Object System"

# PROP Default_Filter ""
# Begin Group "Object System Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\object\Autolink.h
# End Source File
# Begin Source File

SOURCE=.\object\Bintrait.h
# End Source File
# Begin Source File

SOURCE=.\object\Comparrb.h
# End Source File
# Begin Source File

SOURCE=.\object\Comparry.h
# End Source File
# Begin Source File

SOURCE=.\object\Dataops.h
# End Source File
# Begin Source File

SOURCE=.\object\Dataops_.h
# End Source File
# Begin Source File

SOURCE=.\object\Dataopst.h
# End Source File
# Begin Source File

SOURCE=.\object\Datopiid.h
# End Source File
# Begin Source File

SOURCE=.\object\Dlistsim.h
# End Source File
# Begin Source File

SOURCE=.\object\Donorq.h
# End Source File
# Begin Source File

SOURCE=.\object\Donorq_.h
# End Source File
# Begin Source File

SOURCE=.\object\Edittool.h
# End Source File
# Begin Source File

SOURCE=.\object\Edtraist.h
# End Source File
# Begin Source File

SOURCE=.\object\Edtrait.h
# End Source File
# Begin Source File

SOURCE=.\object\Edtraity.h
# End Source File
# Begin Source File

SOURCE=.\object\Etooliid.h
# End Source File
# Begin Source File

SOURCE=.\Object\Gunguid.h
# End Source File
# Begin Source File

SOURCE=.\object\Iobjed.h
# End Source File
# Begin Source File

SOURCE=.\object\Iobjnet.h
# End Source File
# Begin Source File

SOURCE=.\object\Iobjsys.h
# End Source File
# Begin Source File

SOURCE=.\object\Iobjsys_.h
# End Source File
# Begin Source File

SOURCE=.\object\Label.h
# End Source File
# Begin Source File

SOURCE=.\object\Lazyagg.h
# End Source File
# Begin Source File

SOURCE=.\object\Link.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkarry.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkbase.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkboth.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkdat_.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkdb_.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkedst.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkguid.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkid.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkint.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkintb.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkknow.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkloop.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkman.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkman_.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkprop.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkqdb.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkqdb_.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkset.h
# End Source File
# Begin Source File

SOURCE=.\object\Linksto_.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkstor.h
# End Source File
# Begin Source File

SOURCE=.\object\Linktype.h
# End Source File
# Begin Source File

SOURCE=.\object\Linkview.h
# End Source File
# Begin Source File

SOURCE=.\object\Listset.h
# End Source File
# Begin Source File

SOURCE=.\object\Lnkbyobj.h
# End Source File
# Begin Source File

SOURCE=.\object\Lnkdtabl.h
# End Source File
# Begin Source File

SOURCE=.\object\Lnkquer_.h
# End Source File
# Begin Source File

SOURCE=.\object\Lnkquery.h
# End Source File
# Begin Source File

SOURCE=.\object\Lnkremap.h
# End Source File
# Begin Source File

SOURCE=.\object\Lststtem.h
# End Source File
# Begin Source File

SOURCE=.\object\Nameprop.h
# End Source File
# Begin Source File

SOURCE=.\object\Netman.h
# End Source File
# Begin Source File

SOURCE=.\object\Netmniid.h
# End Source File
# Begin Source File

SOURCE=.\object\Netnotif.h
# End Source File
# Begin Source File

SOURCE=.\object\Netprops.h
# End Source File
# Begin Source File

SOURCE=.\object\Nettypes.h
# End Source File
# Begin Source File

SOURCE=.\object\Objdef.h
# End Source File
# Begin Source File

SOURCE=.\object\Objedbas.h
# End Source File
# Begin Source File

SOURCE=.\object\Objediid.h
# End Source File
# Begin Source File

SOURCE=.\object\Objedtyp.h
# End Source File
# Begin Source File

SOURCE=.\object\Objlpars.h
# End Source File
# Begin Source File

SOURCE=.\object\Objnotif.h
# End Source File
# Begin Source File

SOURCE=.\object\Objproxy.h
# End Source File
# Begin Source File

SOURCE=.\object\Objquer_.h
# End Source File
# Begin Source File

SOURCE=.\object\Objquery.h
# End Source File
# Begin Source File

SOURCE=.\object\Objremap.h
# End Source File
# Begin Source File

SOURCE=.\object\Objstat.h
# End Source File
# Begin Source File

SOURCE=.\object\Objsys.h
# End Source File
# Begin Source File

SOURCE=.\object\Objtype.h
# End Source File
# Begin Source File

SOURCE=.\object\Osetlnkq.h
# End Source File
# Begin Source File

SOURCE=.\object\Osysbase.h
# End Source File
# Begin Source File

SOURCE=.\object\Osystype.h
# End Source File
# Begin Source File

SOURCE=.\object\Otreebas.h
# End Source File
# Begin Source File

SOURCE=.\object\Otreetyp.h
# End Source File
# Begin Source File

SOURCE=.\object\Pfaceiid.h
# End Source File
# Begin Source File

SOURCE=.\object\Pfacinit.h
# End Source File
# Begin Source File

SOURCE=.\object\Prcniter.h
# End Source File
# Begin Source File

SOURCE=.\object\Proparry.h
# End Source File
# Begin Source File

SOURCE=.\object\Propbase.h
# End Source File
# Begin Source File

SOURCE=.\object\Propbig.h
# End Source File
# Begin Source File

SOURCE=.\object\Propbigb.h
# End Source File
# Begin Source File

SOURCE=.\object\propbit.h
# End Source File
# Begin Source File

SOURCE=.\object\Propbool.h
# End Source File
# Begin Source File

SOURCE=.\object\Propcary.h
# End Source File
# Begin Source File

SOURCE=.\object\Propcomp.h
# End Source File
# Begin Source File

SOURCE=.\object\Propdb.h
# End Source File
# Begin Source File

SOURCE=.\object\Propdef.h
# End Source File
# Begin Source File

SOURCE=.\object\Propert_.h
# End Source File
# Begin Source File

SOURCE=.\object\Property.h
# End Source File
# Begin Source File

SOURCE=.\object\Propfac_.h
# End Source File
# Begin Source File

SOURCE=.\object\Propface.h
# End Source File
# Begin Source File

SOURCE=.\object\Propguid.h
# End Source File
# Begin Source File

SOURCE=.\object\Prophash.h
# End Source File
# Begin Source File

SOURCE=.\object\Propid.h
# End Source File
# Begin Source File

SOURCE=.\object\Propimp.h
# End Source File
# Begin Source File

SOURCE=.\object\Propinst.h
# End Source File
# Begin Source File

SOURCE=.\object\Propinv.h
# End Source File
# Begin Source File

SOURCE=.\object\Propinvc.h
# End Source File
# Begin Source File

SOURCE=.\object\Propinvs.h
# End Source File
# Begin Source File

SOURCE=.\object\Propknow.h
# End Source File
# Begin Source File

SOURCE=.\object\Proplink.h
# End Source File
# Begin Source File

SOURCE=.\object\Proplist.h
# End Source File
# Begin Source File

SOURCE=.\object\Proplnk_.h
# End Source File
# Begin Source File

SOURCE=.\object\Propman.h
# End Source File
# Begin Source File

SOURCE=.\object\Propman_.h
# End Source File
# Begin Source File

SOURCE=.\object\Propmix.h
# End Source File
# Begin Source File

SOURCE=.\object\Propname.h
# End Source File
# Begin Source File

SOURCE=.\object\Propnet.h
# End Source File
# Begin Source File

SOURCE=.\object\Propnull.h
# End Source File
# Begin Source File

SOURCE=.\object\Propobsv.h
# End Source File
# Begin Source File

SOURCE=.\object\Propraw.h
# End Source File
# Begin Source File

SOURCE=.\object\Propraw_.h
# End Source File
# Begin Source File

SOURCE=.\object\Propscpt.h
# End Source File
# Begin Source File

SOURCE=.\object\Propsimp.h
# End Source File
# Begin Source File

SOURCE=.\object\Propsprs.h
# End Source File
# Begin Source File

SOURCE=.\object\Propstat.h
# End Source File
# Begin Source File

SOURCE=.\object\Propsto_.h
# End Source File
# Begin Source File

SOURCE=.\object\Propstor.h
# End Source File
# Begin Source File

SOURCE=.\object\Proptype.h
# End Source File
# Begin Source File

SOURCE=.\object\Propval_.h
# End Source File
# Begin Source File

SOURCE=.\object\Prpstats.h
# End Source File
# Begin Source File

SOURCE=.\object\Pstordel.h
# End Source File
# Begin Source File

SOURCE=.\object\Querynul.h
# End Source File
# Begin Source File

SOURCE=.\object\Relatio_.h
# End Source File
# Begin Source File

SOURCE=.\object\Relation.h
# End Source File
# Begin Source File

SOURCE=.\object\Reldeleg.h
# End Source File
# Begin Source File

SOURCE=.\object\Relinver.h
# End Source File
# Begin Source File

SOURCE=.\object\Relnull.h
# End Source File
# Begin Source File

SOURCE=.\object\Reltype.h
# End Source File
# Begin Source File

SOURCE=.\object\Sdesc.h
# End Source File
# Begin Source File

SOURCE=.\object\Strprop_.h
# End Source File
# Begin Source File

SOURCE=.\object\Tcachiid.h
# End Source File
# Begin Source File

SOURCE=.\object\Traisrch.h
# End Source File
# Begin Source File

SOURCE=.\object\Trait.h
# End Source File
# Begin Source File

SOURCE=.\object\Trait_.h
# End Source File
# Begin Source File

SOURCE=.\object\Traitbas.h
# End Source File
# Begin Source File

SOURCE=.\object\Traitiid.h
# End Source File
# Begin Source File

SOURCE=.\object\Traitln_.h
# End Source File
# Begin Source File

SOURCE=.\object\Traitlnk.h
# End Source File
# Begin Source File

SOURCE=.\object\Traitma_.h
# End Source File
# Begin Source File

SOURCE=.\object\Traitman.h
# End Source File
# Begin Source File

SOURCE=.\object\Traitnul.h
# End Source File
# Begin Source File

SOURCE=.\object\Traitpr_.h
# End Source File
# Begin Source File

SOURCE=.\object\Traitprp.h
# End Source File
# Begin Source File

SOURCE=.\object\Traitqdb.h
# End Source File
# Begin Source File

SOURCE=.\object\Traittyp.h
# End Source File
# Begin Source File

SOURCE=.\object\Trcache.h
# End Source File
# Begin Source File

SOURCE=.\object\Trcache_.h
# End Source File
# Begin Source File

SOURCE=.\object\Trcachui.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\object\Bintrait.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Dataops.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Donorq.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Edittool.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Link.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Linkarry.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Linkboth.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Linkdata.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Linkdb.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Linkguid.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object\Linkloop.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object\Linkman.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Linkprop.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Linkqdb.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Linkset.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Linkstor.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Lnkbyobj.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Lnkquery.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Nameprop.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Objlpars.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Objproxy.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Objquery.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Objremap.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Objsys.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD CPP /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object\Osetlnkq.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Prcniter.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Propbig.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object\Propbit.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object\Propdb.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Property.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Propface.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Propguid.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object\Prophash.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object\Propimp.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object\Proplink.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Proplist.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object\Propman.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD CPP /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object\Propmix.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Propnull.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Propobsv.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Propsave.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Propstor.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Querynul.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Relation.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Relinver.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Relnull.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Strprop.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Traisrch.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Trait.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Traitiid.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object\Traitlnk.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Traitman.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Traitnul.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Traitprp.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Traitq.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Traitqdb.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Trcache.cpp
# End Source File
# Begin Source File

SOURCE=.\object\Trcachui.cpp
# End Source File
# End Group
# Begin Group "Physics"

# PROP Default_Filter ""
# Begin Group "Physics Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Physics\Cattype.h
# End Source File
# Begin Source File

SOURCE=.\physics\Collide.h
# End Source File
# Begin Source File

SOURCE=.\physics\Collprop.h
# End Source File
# Begin Source File

SOURCE=.\Physics\Gunproj.h
# End Source File
# Begin Source File

SOURCE=.\Physics\Gunvhot.h
# End Source File
# Begin Source File

SOURCE=.\physics\Objmedia.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phclimb.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phclsn.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phcollev.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phconst.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phcontct.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phcore.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phctrl.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phdbg.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phdyn.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phflist.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phlisbas.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phlistn_.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phlistyp.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmedtr.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmoapi.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmod.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmodata.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmodbsp.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmodobb.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmods.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmodsph.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmodutl.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmotion.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmsg.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmterr.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmtprop.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phmtscpt.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phnet.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phoprop.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phpos.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phppscpt.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phprop.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phprops.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phref.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phreport.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phscrpt.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phscrt.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phsubmod.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phterr.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phtxtprp.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phutils.h
# End Source File
# Begin Source File

SOURCE=.\physics\Physapi.h
# End Source File
# Begin Source File

SOURCE=.\physics\Physcast.h
# End Source File
# Begin Source File

SOURCE=.\physics\Physloop.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phystest.h
# End Source File
# Begin Source File

SOURCE=.\physics\Phystyp2.h
# End Source File
# Begin Source File

SOURCE=.\Physics\Spherchk.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Physics\Collide.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Collprop.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Gunproj.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Gunvhot.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Objmedia.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phclimb.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phclsn.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phcontct.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\phcore.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phctrl.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phdyn.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phflist.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phlisten.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmedtr.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmoapi.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmod.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmodata.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Physics\Phmodbsp.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmodobb.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmods.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmodsph.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmodutl.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmotion.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmsg.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmterr.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmtprop.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phmtscpt.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phnet.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phoprop.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phppscpt.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phprop.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phprops.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phref.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phreport.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phsubmod.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phterr.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phtxtprp.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phutils.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Physapi.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Physcast.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Physloop.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Phystest.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\Spherchk.cpp
# End Source File
# End Group
# Begin Group "Portal"

# PROP Default_Filter ""
# Begin Group "Portal ASM files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\portal\Ptfloat.asm

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Ptlinear.asm

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Ptmap.asm

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Ptmap_8.asm

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Ptmap_n.asm

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Ptmapper.asm

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Ptpersp.asm

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Ptsurf.asm

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# Begin Custom Build - Assembling $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\portal\Ptsurf.asm
InputName=Ptsurf

"$(OutDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo /c /Cp /Zd /X /Ddbg_on /Dwarn_on /Dspew_on /DDBG_ON /DWARN_ON /DSPEW_ON /DCDECL_ASM=1 /D_MSC_VER=800 /D_WIN32=1 /DWIN32=1 /Fo$(OutDir)\$(InputName).obj /I"..\..\tech\inc"  /I"..\..\tech\libsrc\lg" /I"..\..\tech\libsrc\lgalloc" /I"..\..\tech\libsrc\fix" /I"C:\Program Files (x86)\Microsoft Visual Studio\VC98\Include" $(InputPath) > $(IntDir)\ml.rsp 
	ml.exe @$(IntDir)\ml.rsp 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Assembling $(InputPath)
IntDir=.\Opt
OutDir=.\Opt
InputPath=.\portal\Ptsurf.asm
InputName=Ptsurf

"$(OutDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo /c /Cp /Zd /X /Ddbg_on /Dwarn_on /Dspew_on /DDBG_ON /DWARN_ON /DSPEW_ON /DCDECL_ASM=1 /D_MSC_VER=800 /D_WIN32=1 /DWIN32=1 /Fo$(OutDir)\$(InputName).obj /I"..\..\tech\inc"  /I"..\..\tech\libsrc\lg" /I"..\..\tech\libsrc\lgalloc" /I"..\..\tech\libsrc\fix" /I"C:\Program Files (x86)\Microsoft Visual Studio\VC98\Include" $(InputPath) > $(IntDir)\ml.rsp 
	ml.exe @$(IntDir)\ml.rsp 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# Begin Custom Build - Assembling $(InputPath)
IntDir=.\Opt_No_Precompiled_Header
OutDir=.\Opt_No_Precompiled_Header
InputPath=.\portal\Ptsurf.asm
InputName=Ptsurf

"$(OutDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo /c /Cp /Zd /X /Ddbg_on /Dwarn_on /Dspew_on /DDBG_ON /DWARN_ON /DSPEW_ON /DCDECL_ASM=1 /D_MSC_VER=800 /D_WIN32=1 /DWIN32=1 /Fo$(OutDir)\$(InputName).obj /I"..\..\tech\inc"  /I"..\..\tech\libsrc\lg" /I"..\..\tech\libsrc\lgalloc" /I"..\..\tech\libsrc\fix" /I"C:\Program Files (x86)\Microsoft Visual Studio\VC98\Include" $(InputPath) > $(IntDir)\ml.rsp 
	ml.exe @$(IntDir)\ml.rsp 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Ptsurf16.asm

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# Begin Custom Build - Assembling $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\portal\Ptsurf16.asm
InputName=Ptsurf16

"$(OutDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo /c /Cp /Zd /X /Ddbg_on /Dwarn_on /Dspew_on /DDBG_ON /DWARN_ON /DSPEW_ON /DCDECL_ASM=1 /D_MSC_VER=800 /D_WIN32=1 /DWIN32=1 /Fo$(OutDir)\$(InputName).obj /I"..\..\tech\inc"  /I"..\..\tech\libsrc\lg" /I"..\..\tech\libsrc\lgalloc" /I"..\..\tech\libsrc\fix" /I"..\..\tech\libsrc\dev2d" /I"C:\Program Files (x86)\Microsoft Visual Studio\VC98\Include" $(InputPath) > $(IntDir)\ml.rsp 
	ml.exe @$(IntDir)\ml.rsp 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Assembling $(InputPath)
IntDir=.\Opt
OutDir=.\Opt
InputPath=.\portal\Ptsurf16.asm
InputName=Ptsurf16

"$(OutDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo /c /Cp /Zd /X /Ddbg_on /Dwarn_on /Dspew_on /DDBG_ON /DWARN_ON /DSPEW_ON /DCDECL_ASM=1 /D_MSC_VER=800 /D_WIN32=1 /DWIN32=1 /Fo$(OutDir)\$(InputName).obj /I"..\..\tech\inc"  /I"..\..\tech\libsrc\lg" /I"..\..\tech\libsrc\lgalloc" /I"..\..\tech\libsrc\fix" /I"..\..\tech\libsrc\dev2d" /I"C:\Program Files (x86)\Microsoft Visual Studio\VC98\Include" $(InputPath) > $(IntDir)\ml.rsp 
	ml.exe @$(IntDir)\ml.rsp 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# Begin Custom Build - Assembling $(InputPath)
IntDir=.\Opt_No_Precompiled_Header
OutDir=.\Opt_No_Precompiled_Header
InputPath=.\portal\Ptsurf16.asm
InputName=Ptsurf16

"$(OutDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo /c /Cp /Zd /X /Ddbg_on /Dwarn_on /Dspew_on /DDBG_ON /DWARN_ON /DSPEW_ON /DCDECL_ASM=1 /D_MSC_VER=800 /D_WIN32=1 /DWIN32=1 /Fo$(OutDir)\$(InputName).obj /I"..\..\tech\inc"  /I"..\..\tech\libsrc\lg" /I"..\..\tech\libsrc\lgalloc" /I"..\..\tech\libsrc\fix" /I"..\..\tech\libsrc\dev2d" /I"C:\Program Files (x86)\Microsoft Visual Studio\VC98\Include" $(InputPath) > $(IntDir)\ml.rsp 
	ml.exe @$(IntDir)\ml.rsp 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Portal Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\portal\Animlit.h
# End Source File
# Begin Source File

SOURCE=.\portal\Bspsphr.h
# End Source File
# Begin Source File

SOURCE=.\portal\Char.h
# End Source File
# Begin Source File

SOURCE=.\portal\Mapper.h
# End Source File
# Begin Source File

SOURCE=.\portal\Oracle.h
# End Source File
# Begin Source File

SOURCE=.\portal\Oracle_.h
# End Source File
# Begin Source File

SOURCE=.\portal\Ourobj.h
# End Source File
# Begin Source File

SOURCE=.\portal\Perfcore.h
# End Source File
# Begin Source File

SOURCE=.\portal\Point.h
# End Source File
# Begin Source File

SOURCE=.\portal\Port.h
# End Source File
# Begin Source File

SOURCE=.\portal\Portal.h
# End Source File
# Begin Source File

SOURCE=.\portal\Portal_.h
# End Source File
# Begin Source File

SOURCE=.\portal\Portclip.h
# End Source File
# Begin Source File

SOURCE=.\portal\Portdraw.h
# End Source File
# Begin Source File

SOURCE=.\portal\Porthw.h
# End Source File
# Begin Source File

SOURCE=.\portal\Portsky.h
# End Source File
# Begin Source File

SOURCE=.\portal\Portwatr.h
# End Source File
# Begin Source File

SOURCE=.\portal\Profile.h
# End Source File
# Begin Source File

SOURCE=.\portal\Pt.h
# End Source File
# Begin Source File

SOURCE=.\portal\Pt_align.h
# End Source File
# Begin Source File

SOURCE=.\portal\Pt_asm.h
# End Source File
# Begin Source File

SOURCE=.\portal\Pt_clut.h
# End Source File
# Begin Source File

SOURCE=.\portal\Ptmap.h
# End Source File
# Begin Source File

SOURCE=.\portal\Ptmapper.h
# End Source File
# Begin Source File

SOURCE=.\portal\Ptsurf.h
# End Source File
# Begin Source File

SOURCE=.\portal\Recip.h
# End Source File
# Begin Source File

SOURCE=.\portal\Wr.h
# End Source File
# Begin Source File

SOURCE=.\portal\Wrcast_.h
# End Source File
# Begin Source File

SOURCE=.\portal\Wrdb.h
# End Source File
# Begin Source File

SOURCE=.\portal\Wrdbrend.h
# End Source File
# Begin Source File

SOURCE=.\portal\Wrfunc.h
# End Source File
# Begin Source File

SOURCE=.\portal\Wrlimit.h
# End Source File
# Begin Source File

SOURCE=.\portal\Wrobj.h
# End Source File
# Begin Source File

SOURCE=.\portal\Wrtype.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\portal\Animlit.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Bspsphr.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Char.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Duv.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Mapper.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Memtest.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Merge.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Oracle.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Perfcore.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Perftest.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Portal.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Portbg.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Portclip.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Portdata.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Portdraw.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Porthw.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Portlit.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Portmain.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Portpick.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Portsky.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Portsurf.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Portwatr.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Pt_clut.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Pt_main.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Pt_mem.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Ptdrawhw.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Surfaces.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Wrcast.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Wrdb.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Wrdbg.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\portal\Wrfunc.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# End Group
# Begin Group "Rendering"

# PROP Default_Filter ""
# Begin Group "Rendering Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\render\Anim_txt.h
# End Source File
# Begin Source File

SOURCE=.\render\Animlgt.h
# End Source File
# Begin Source File

SOURCE=.\render\Animlgte.h
# End Source File
# Begin Source File

SOURCE=.\render\Animlgts.h
# End Source File
# Begin Source File

SOURCE=.\render\Animlgtt.h
# End Source File
# Begin Source File

SOURCE=.\render\Animtext.h
# End Source File
# Begin Source File

SOURCE=.\render\Antxloop.h
# End Source File
# Begin Source File

SOURCE=.\render\Antxscpt.h
# End Source File
# Begin Source File

SOURCE=.\render\Antxtype.h
# End Source File
# Begin Source File

SOURCE=.\render\Bsppinfo.h
# End Source File
# Begin Source File

SOURCE=.\render\Camera.h
# End Source File
# Begin Source File

SOURCE=.\Render\Camovl.h
# End Source File
# Begin Source File

SOURCE=.\Render\Celstobj.h
# End Source File
# Begin Source File

SOURCE=.\Render\Cloudobj.h
# End Source File
# Begin Source File

SOURCE=.\Render\Corona.h
# End Source File
# Begin Source File

SOURCE=.\Render\Coronag.h
# End Source File
# Begin Source File

SOURCE=.\render\Ctimer.h
# End Source File
# Begin Source File

SOURCE=.\render\Ctrast.h
# End Source File
# Begin Source File

SOURCE=.\render\Disploop.h
# End Source File
# Begin Source File

SOURCE=.\Render\Distobj.h
# End Source File
# Begin Source File

SOURCE=.\render\Dyniid.h
# End Source File
# Begin Source File

SOURCE=.\render\Dyntex.h
# End Source File
# Begin Source File

SOURCE=.\render\Elitprop.h
# End Source File
# Begin Source File

SOURCE=.\Render\Face.h
# End Source File
# Begin Source File

SOURCE=.\Render\Faceg.h
# End Source File
# Begin Source File

SOURCE=.\render\Family.h
# End Source File
# Begin Source File

SOURCE=.\render\Family_.h
# End Source File
# Begin Source File

SOURCE=.\render\Fas.h
# End Source File
# Begin Source File

SOURCE=.\render\Fasprop.h
# End Source File
# Begin Source File

SOURCE=.\render\Fastype.h
# End Source File
# Begin Source File

SOURCE=.\render\Fxdisk.h
# End Source File
# Begin Source File

SOURCE=.\render\Fxspan.h
# End Source File
# Begin Source File

SOURCE=.\render\Fxspans.h
# End Source File
# Begin Source File

SOURCE=.\render\Fxspant.h
# End Source File
# Begin Source File

SOURCE=.\render\Gamma.h
# End Source File
# Begin Source File

SOURCE=.\render\Gfxprop.h
# End Source File
# Begin Source File

SOURCE=.\render\H2ocolid.h
# End Source File
# Begin Source File

SOURCE=.\render\H2ocolor.h
# End Source File
# Begin Source File

SOURCE=.\render\Hdskbase.h
# End Source File
# Begin Source File

SOURCE=.\render\Hdskprop.h
# End Source File
# Begin Source File

SOURCE=.\render\Hud.h
# End Source File
# Begin Source File

SOURCE=.\render\Light.h
# End Source File
# Begin Source File

SOURCE=.\render\Litdbg.h
# End Source File
# Begin Source File

SOURCE=.\render\Litnet.h
# End Source File
# Begin Source File

SOURCE=.\render\Litprop.h
# End Source File
# Begin Source File

SOURCE=.\render\Litprops.h
# End Source File
# Begin Source File

SOURCE=.\render\Litpropt.h
# End Source File
# Begin Source File

SOURCE=.\render\Medmotn.h
# End Source File
# Begin Source File

SOURCE=.\render\Medmotns.h
# End Source File
# Begin Source File

SOURCE=.\render\Medmotnt.h
# End Source File
# Begin Source File

SOURCE=.\render\Meshatt.h
# End Source File
# Begin Source File

SOURCE=.\render\Meshatts.h
# End Source File
# Begin Source File

SOURCE=.\render\Meshray.h
# End Source File
# Begin Source File

SOURCE=.\Render\Meshtex.h
# End Source File
# Begin Source File

SOURCE=.\Render\Meshtexg.h
# End Source File
# Begin Source File

SOURCE=.\render\Meshtype.h
# End Source File
# Begin Source File

SOURCE=.\render\Mipmap.h
# End Source File
# Begin Source File

SOURCE=.\render\Missrend.h
# End Source File
# Begin Source File

SOURCE=.\render\Mlight.h
# End Source File
# Begin Source File

SOURCE=.\render\Mnamprop.h
# End Source File
# Begin Source File

SOURCE=.\render\Mnumprop.h
# End Source File
# Begin Source File

SOURCE=.\render\Objcast.h
# End Source File
# Begin Source File

SOURCE=.\render\Objlight.h
# End Source File
# Begin Source File

SOURCE=.\render\Objmodel.h
# End Source File
# Begin Source File

SOURCE=.\render\Objscale.h
# End Source File
# Begin Source File

SOURCE=.\render\Objshape.h
# End Source File
# Begin Source File

SOURCE=.\render\Objslit.h
# End Source File
# Begin Source File

SOURCE=.\render\Objtxtrp.h
# End Source File
# Begin Source File

SOURCE=.\render\Palette.h
# End Source File
# Begin Source File

SOURCE=.\render\Palmgr.h
# End Source File
# Begin Source File

SOURCE=.\render\Partgrp.h
# End Source File
# Begin Source File

SOURCE=.\render\Particle.h
# End Source File
# Begin Source File

SOURCE=.\render\Partprop.h
# End Source File
# Begin Source File

SOURCE=.\render\Parttype.h
# End Source File
# Begin Source File

SOURCE=.\render\Pgroup.h
# End Source File
# Begin Source File

SOURCE=.\render\Pgrpprop.h
# End Source File
# Begin Source File

SOURCE=.\render\Portapp.h
# End Source File
# Begin Source File

SOURCE=.\render\Porthlpr.h
# End Source File
# Begin Source File

SOURCE=.\render\Render.h
# End Source File
# Begin Source File

SOURCE=.\render\Rendloop.h
# End Source File
# Begin Source File

SOURCE=.\render\Rendobj.h
# End Source File
# Begin Source File

SOURCE=.\render\Rendphys.h
# End Source File
# Begin Source File

SOURCE=.\render\Rendprop.h
# End Source File
# Begin Source File

SOURCE=.\render\Rendptst.h
# End Source File
# Begin Source File

SOURCE=.\render\Rndflash.h
# End Source File
# Begin Source File

SOURCE=.\render\Robjbase.h
# End Source File
# Begin Source File

SOURCE=.\render\Robjtype.h
# End Source File
# Begin Source File

SOURCE=.\render\Scalprop.h
# End Source File
# Begin Source File

SOURCE=.\render\Scrnguid.h
# End Source File
# Begin Source File

SOURCE=.\render\Scrnloop.h
# End Source File
# Begin Source File

SOURCE=.\render\Scrnman.h
# End Source File
# Begin Source File

SOURCE=.\render\Scrnmode.h
# End Source File
# Begin Source File

SOURCE=.\render\Scrnovls.h
# End Source File
# Begin Source File

SOURCE=.\render\Scrnstr.h
# End Source File
# Begin Source File

SOURCE=.\Render\Skyint.h
# End Source File
# Begin Source File

SOURCE=.\Render\Skyobj.h
# End Source File
# Begin Source File

SOURCE=.\Render\skyrend.h
# End Source File
# Begin Source File

SOURCE=.\render\Slitprop.h
# End Source File
# Begin Source File

SOURCE=.\render\Sphrcst.h
# End Source File
# Begin Source File

SOURCE=.\render\Sphrcsts.h
# End Source File
# Begin Source File

SOURCE=.\render\Sphrcstt.h
# End Source File
# Begin Source File

SOURCE=.\render\Sprkprop.h
# End Source File
# Begin Source File

SOURCE=.\render\Sprks.h
# End Source File
# Begin Source File

SOURCE=.\render\Sprkt.h
# End Source File
# Begin Source File

SOURCE=.\render\Starhack.h
# End Source File
# Begin Source File

SOURCE=.\Render\Starobj.h
# End Source File
# Begin Source File

SOURCE=.\render\Tanimiid.h
# End Source File
# Begin Source File

SOURCE=.\render\Tanimprp.h
# End Source File
# Begin Source File

SOURCE=.\render\Texmem.h
# End Source File
# Begin Source File

SOURCE=.\render\Texprop.h
# End Source File
# Begin Source File

SOURCE=.\render\Texsave.h
# End Source File
# Begin Source File

SOURCE=.\render\Textarch.h
# End Source File
# Begin Source File

SOURCE=.\render\Textrgfh.h
# End Source File
# Begin Source File

SOURCE=.\render\Texture.h
# End Source File
# Begin Source File

SOURCE=.\Render\weather.h
# End Source File
# Begin Source File

SOURCE=.\Render\Weatherg.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\render\Anim_txt.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Animlgt.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Antxloop.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Antxscpt.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Camera.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Render\camovl.cpp
# End Source File
# Begin Source File

SOURCE=.\Render\Celstobj.cpp
# End Source File
# Begin Source File

SOURCE=.\Render\cloudobj.cpp
# End Source File
# Begin Source File

SOURCE=.\Render\Corona.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Ctimer.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Ctrast.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Disploop.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Render\Distobj.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Dyntex.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Elitprop.cpp
# End Source File
# Begin Source File

SOURCE=.\Render\Face.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Family.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Fas.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Fasprop.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Fxdisk.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Fxspan.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Gfxprop.cpp
# End Source File
# Begin Source File

SOURCE=.\render\H2ocolor.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Hdskprop.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Hud.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Litnet.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Litprop.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Medmotn.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Meshatt.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Meshray.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Render\Meshtex.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Mipmap.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Missrend.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Mlight.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Mnamprop.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Mnumprop.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD CPP /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Objcast.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Objlight.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Objmodel.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Objshape.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Objtxtrp.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Palette.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Palmgr.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Particle.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Partprop.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Pgroup.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Pgrpprop.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Portapp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Porthlpr.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Render.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Rendloop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Rendobj.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Rendphys.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Rendprop.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Rendptst.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Rndflash.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Scalprop.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Scrnloop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Scrnman.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Scrnmode.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Scrnovls.cpp
# End Source File
# Begin Source File

SOURCE=.\Render\Skyobj.cpp
# End Source File
# Begin Source File

SOURCE=.\Render\skyrend.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Slitprop.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Sphrcst.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Sprkprop.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Starhack.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Render\Starobj.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Tanimprp.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Texmem.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Texprop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\render\Texsave.cpp
# End Source File
# Begin Source File

SOURCE=.\render\Textarch.cpp
# End Source File
# Begin Source File

SOURCE=.\Render\weather.cpp
# End Source File
# End Group
# Begin Group "Script"

# PROP Default_Filter ""
# Begin Group "Script Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\script\Arscrm.h
# End Source File
# Begin Source File

SOURCE=.\script\Arscrp.h
# End Source File
# Begin Source File

SOURCE=.\script\Arscrs.h
# End Source File
# Begin Source File

SOURCE=.\script\Arscrt.h
# End Source File
# Begin Source File

SOURCE=.\script\Atkscrpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Bodscrpt.h
# End Source File
# Begin Source File

SOURCE=.\Script\Camscrs.h
# End Source File
# Begin Source File

SOURCE=.\script\Cdscript.h
# End Source File
# Begin Source File

SOURCE=.\script\Contscpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Contscrm.h
# End Source File
# Begin Source File

SOURCE=.\script\Contscrs.h
# End Source File
# Begin Source File

SOURCE=.\script\Damgscrm.h
# End Source File
# Begin Source File

SOURCE=.\script\Damgscrp.h
# End Source File
# Begin Source File

SOURCE=.\script\Damgscrs.h
# End Source File
# Begin Source File

SOURCE=.\script\Datascrs.h
# End Source File
# Begin Source File

SOURCE=.\script\Drscrpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Engscrpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Frobscrm.h
# End Source File
# Begin Source File

SOURCE=.\script\Frobscrp.h
# End Source File
# Begin Source File

SOURCE=.\script\Frobscrt.h
# End Source File
# Begin Source File

SOURCE=.\script\Keyscpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Linkscpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Litscrpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Lockscpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Miscrprt.h
# End Source File
# Begin Source File

SOURCE=.\Script\Mtscrpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Netscrpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Objscrm.h
# End Source File
# Begin Source File

SOURCE=.\script\Objscrpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Objscrt.h
# End Source File
# Begin Source File

SOURCE=.\script\Pgrpscpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Pupscrpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Quesscpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Repscrpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Rooscrpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Scrptcmd.h
# End Source File
# Begin Source File

SOURCE=.\script\Scrptne_.h
# End Source File
# Begin Source File

SOURCE=.\script\Scrptpr_.h
# End Source File
# Begin Source File

SOURCE=.\script\Scrptprp.h
# End Source File
# Begin Source File

SOURCE=.\script\Scrptst.h
# End Source File
# Begin Source File

SOURCE=.\script\Simscrm.h
# End Source File
# Begin Source File

SOURCE=.\script\Sndscrp_.h
# End Source File
# Begin Source File

SOURCE=.\script\Sndscrpt.h
# End Source File
# Begin Source File

SOURCE=.\script\Twqscrpt.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\script\Arscript.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Atkscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Bodscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\Script\Camscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Cdscript.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Contscrs.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Datascrs.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Dmgscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Drscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Engscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Keyscpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Linkscpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Litscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Lockscpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Miscrprt.cpp
# End Source File
# Begin Source File

SOURCE=.\Script\Mtscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Netscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Objscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Pgrpscpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Propscpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Pupscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Quesscpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Rooscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Scrptcmd.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Scrptnet.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Scrptprp.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Scrptst.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Sndscrpt.cpp
# End Source File
# Begin Source File

SOURCE=.\script\Twqscrpt.cpp
# End Source File
# End Group
# Begin Group "Sim"

# PROP Default_Filter ""
# Begin Group "Sim Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\sim\Avatar.h
# End Source File
# Begin Source File

SOURCE=.\sim\Bow.h
# End Source File
# Begin Source File

SOURCE=.\sim\Doorphys.h
# End Source File
# Begin Source File

SOURCE=.\sim\Doorprop.h
# End Source File
# Begin Source File

SOURCE=.\sim\Doorrep.h
# End Source File
# Begin Source File

SOURCE=.\sim\Eosapp.h
# End Source File
# Begin Source File

SOURCE=.\sim\Flowarch.h
# End Source File
# Begin Source File

SOURCE=.\sim\Flowprid.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghost.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostapi.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostcfg.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostflg.h
# End Source File
# Begin Source File

SOURCE=.\sim\ghosthst.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostint.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostlst.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostmot.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostmsg.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostmvr.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostphy.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostrcv.h
# End Source File
# Begin Source File

SOURCE=.\sim\ghostshk.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostsnd.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghosttyp.h
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostwep.h
# End Source File
# Begin Source File

SOURCE=.\sim\Headmove.h
# End Source File
# Begin Source File

SOURCE=.\sim\Iavatar.h
# End Source File
# Begin Source File

SOURCE=.\sim\Iobjnet_.h
# End Source File
# Begin Source File

SOURCE=.\sim\Objdb.h
# End Source File
# Begin Source File

SOURCE=.\sim\Objhp.h
# End Source File
# Begin Source File

SOURCE=.\sim\Objloop.h
# End Source File
# Begin Source File

SOURCE=.\sim\Objmagic.h
# End Source File
# Begin Source File

SOURCE=.\sim\Objmsg.h
# End Source File
# Begin Source File

SOURCE=.\sim\Objowner.h
# End Source File
# Begin Source File

SOURCE=.\sim\Objpos.h
# End Source File
# Begin Source File

SOURCE=.\sim\Player.h
# End Source File
# Begin Source File

SOURCE=.\sim\Playrobj.h
# End Source File
# Begin Source File

SOURCE=.\sim\Playtest.h
# End Source File
# Begin Source File

SOURCE=.\sim\Plyablt_.h
# End Source File
# Begin Source File

SOURCE=.\sim\Plyablty.h
# End Source File
# Begin Source File

SOURCE=.\sim\Plycbllm.h
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrbase.h
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrhdlr.h
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrloop.h
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrmode.h
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrmov.h
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrspd.h
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrtype.h
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrvmot.h
# End Source File
# Begin Source File

SOURCE=.\Sim\Plyskill.h
# End Source File
# Begin Source File

SOURCE=.\sim\Posiid.h
# End Source File
# Begin Source File

SOURCE=.\sim\Posprop.h
# End Source File
# Begin Source File

SOURCE=.\sim\Prjctile.h
# End Source File
# Begin Source File

SOURCE=.\sim\Room.h
# End Source File
# Begin Source File

SOURCE=.\sim\Roombase.h
# End Source File
# Begin Source File

SOURCE=.\sim\Roomeax.h
# End Source File
# Begin Source File

SOURCE=.\sim\Roomloop.h
# End Source File
# Begin Source File

SOURCE=.\sim\Roompa.h
# End Source File
# Begin Source File

SOURCE=.\sim\Roomprop.h
# End Source File
# Begin Source File

SOURCE=.\sim\Rooms.h
# End Source File
# Begin Source File

SOURCE=.\sim\Roomsys.h
# End Source File
# Begin Source File

SOURCE=.\sim\Roomutil.h
# End Source File
# Begin Source File

SOURCE=.\sim\Rpathfnd.h
# End Source File
# Begin Source File

SOURCE=.\sim\Rpaths.h
# End Source File
# Begin Source File

SOURCE=.\sim\Rportal.h
# End Source File
# Begin Source File

SOURCE=.\sim\Simbase.h
# End Source File
# Begin Source File

SOURCE=.\sim\Simdef.h
# End Source File
# Begin Source File

SOURCE=.\sim\Simflags.h
# End Source File
# Begin Source File

SOURCE=.\sim\Simloop.h
# End Source File
# Begin Source File

SOURCE=.\sim\Simman.h
# End Source File
# Begin Source File

SOURCE=.\sim\Simmanid.h
# End Source File
# Begin Source File

SOURCE=.\sim\Simstate.h
# End Source File
# Begin Source File

SOURCE=.\sim\Simtbase.h
# End Source File
# Begin Source File

SOURCE=.\sim\Simtime.h
# End Source File
# Begin Source File

SOURCE=.\sim\Simtloop.h
# End Source File
# Begin Source File

SOURCE=.\sim\Wrbsp.h
# End Source File
# Begin Source File

SOURCE=.\sim\Wrcell.h
# End Source File
# Begin Source File

SOURCE=.\sim\Wrloop.h
# End Source File
# Begin Source File

SOURCE=.\sim\Wrmem.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\sim\Avatar.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Doorphys.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Doorprop.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Doorrep.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Eosapp.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sim\Flowarch.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Ghost.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\ghosthst.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostlst.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostlup.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostmsg.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostphy.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostrcv.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\ghostshk.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostsnd.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Ghostwep.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Headmove.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sim\Objloop.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Objnet.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Objpos.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Objtool.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Playtest.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# ADD CPP /D "NO_PCH"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD BASE CPP /D "NO_PCH"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /D "NO_PCH"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# ADD BASE CPP /D "NO_PCH"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /D "NO_PCH"
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sim\Plyablty.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Plycbllm.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrhdlr.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrloop.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrmode.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrmov.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Plyrvmot.cpp
# End Source File
# Begin Source File

SOURCE=.\Sim\Plyskill.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sim\Prjctile.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Room.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Roomcore.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Roomeax.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Roomloop.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Roompa.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Roomprop.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Rooms.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Roomutil.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Rpathfnd.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Rpaths.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Rportal.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Simloop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sim\Simman.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Simstate.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sim\Simtime.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Wrbsp.cpp
# End Source File
# Begin Source File

SOURCE=.\sim\Wrcell.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sim\Wrloop.cpp
# End Source File
# End Group
# Begin Group "Sound"

# PROP Default_Filter ""
# Begin Group "Sound Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\sound\Ambbase.h
# End Source File
# Begin Source File

SOURCE=.\sound\Ambient.h
# End Source File
# Begin Source File

SOURCE=.\sound\Ambient_.h
# End Source File
# Begin Source File

SOURCE=.\sound\Ambprop.h
# End Source File
# Begin Source File

SOURCE=.\sound\Appsfx.h
# End Source File
# Begin Source File

SOURCE=.\sound\Appsfxi.h
# End Source File
# Begin Source File

SOURCE=.\sound\Auxsnd.h
# End Source File
# Begin Source File

SOURCE=.\sound\Esnd.h
# End Source File
# Begin Source File

SOURCE=.\sound\Esndglue.h
# End Source File
# Begin Source File

SOURCE=.\sound\Esndprid.h
# End Source File
# Begin Source File

SOURCE=.\sound\Esndprop.h
# End Source File
# Begin Source File

SOURCE=.\sound\Esndreac.h
# End Source File
# Begin Source File

SOURCE=.\sound\Metasnd.h
# End Source File
# Begin Source File

SOURCE=.\sound\Psnd.h
# End Source File
# Begin Source File

SOURCE=.\sound\Psndapi.h
# End Source File
# Begin Source File

SOURCE=.\sound\Psndinfo.h
# End Source File
# Begin Source File

SOURCE=.\sound\Psndinst.h
# End Source File
# Begin Source File

SOURCE=.\sound\Schbase.h
# End Source File
# Begin Source File

SOURCE=.\sound\Schdb.h
# End Source File
# Begin Source File

SOURCE=.\sound\Schema.h
# End Source File
# Begin Source File

SOURCE=.\sound\Schema_.h
# End Source File
# Begin Source File

SOURCE=.\sound\Schfile.h
# End Source File
# Begin Source File

SOURCE=.\sound\Schloop.h
# End Source File
# Begin Source File

SOURCE=.\sound\Schmsg.h
# End Source File
# Begin Source File

SOURCE=.\sound\Schprop.h
# End Source File
# Begin Source File

SOURCE=.\sound\Schsamps.h
# End Source File
# Begin Source File

SOURCE=.\sound\Schtok.h
# End Source File
# Begin Source File

SOURCE=.\sound\Schtype.h
# End Source File
# Begin Source File

SOURCE=.\sound\Schyacc.h
# End Source File
# Begin Source File

SOURCE=.\sound\Sndapp.h
# End Source File
# Begin Source File

SOURCE=.\SOUND\sndframe.h
# End Source File
# Begin Source File

SOURCE=.\sound\Sndgen.h
# End Source File
# Begin Source File

SOURCE=.\sound\Sndloop.h
# End Source File
# Begin Source File

SOURCE=.\sound\Sndnet.h
# End Source File
# Begin Source File

SOURCE=.\sound\Sndprop.h
# End Source File
# Begin Source File

SOURCE=.\sound\Song.h
# End Source File
# Begin Source File

SOURCE=.\sound\Songedtr.h
# End Source File
# Begin Source File

SOURCE=.\sound\Songfile.h
# End Source File
# Begin Source File

SOURCE=.\sound\Songi.h
# End Source File
# Begin Source File

SOURCE=.\sound\Songid.h
# End Source File
# Begin Source File

SOURCE=.\sound\Songmiss.h
# End Source File
# Begin Source File

SOURCE=.\sound\Songplr.h
# End Source File
# Begin Source File

SOURCE=.\sound\Songplri.h
# End Source File
# Begin Source File

SOURCE=.\sound\Songutil.h
# End Source File
# Begin Source File

SOURCE=.\sound\Spchbase.h
# End Source File
# Begin Source File

SOURCE=.\sound\Spchdom.h
# End Source File
# Begin Source File

SOURCE=.\sound\Spchglue.h
# End Source File
# Begin Source File

SOURCE=.\sound\Spchprop.h
# End Source File
# Begin Source File

SOURCE=.\sound\Spchreq.h
# End Source File
# Begin Source File

SOURCE=.\sound\Spcht.h
# End Source File
# Begin Source File

SOURCE=.\sound\Spchtype.h
# End Source File
# Begin Source File

SOURCE=.\sound\Spchvoc.h
# End Source File
# Begin Source File

SOURCE=.\sound\Speech.h
# End Source File
# Begin Source File

SOURCE=.\sound\Vocore.h
# End Source File
# Begin Source File

SOURCE=.\sound\Vocprop.h
# End Source File
# Begin Source File

SOURCE=.\sound\Voguid.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\sound\Ambient.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sound\Ambprop.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Appsfx.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Auxsnd.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Esnd.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Esndprop.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Esndreac.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Metasnd.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Psnd.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Psndapi.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Psndinst.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Schdb.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Schema.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Schfile.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Schloop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sound\Schmsg.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Schprop.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Schsamps.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Schyacc.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\SOUND\sndframe.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Sndgen.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Sndloop.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Sndnet.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Sndprop.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Songedtr.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Songfile.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Songi.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Songid.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Songmiss.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Songplri.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Songutil.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Spchdom.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Spchprop.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Spchreq.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sound\Spchvoc.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Speech.cpp
# End Source File
# Begin Source File

SOURCE=.\sound\Vocore.cpp
# End Source File
# End Group
# Begin Group "UI"

# PROP Default_Filter ""
# Begin Group "UI Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ui\Bugterm.h
# End Source File
# Begin Source File

SOURCE=.\ui\Buttpanl.h
# End Source File
# Begin Source File

SOURCE=.\ui\Ccompose.h
# End Source File
# Begin Source File

SOURCE=.\ui\Cmdterm.h
# End Source File
# Begin Source File

SOURCE=.\ui\Ged_win.h
# End Source File
# Begin Source File

SOURCE=.\ui\Joypoll.h
# End Source File
# Begin Source File

SOURCE=.\ui\Keyiid.h
# End Source File
# Begin Source File

SOURCE=.\ui\Movie.h
# End Source File
# Begin Source File

SOURCE=.\ui\Panlguid.h
# End Source File
# Begin Source File

SOURCE=.\ui\Panlmode.h
# End Source File
# Begin Source File

SOURCE=.\ui\Panltool.h
# End Source File
# Begin Source File

SOURCE=.\ui\Pnltulid.h
# End Source File
# Begin Source File

SOURCE=.\ui\Uiamov.h
# End Source File
# Begin Source File

SOURCE=.\ui\Uianim.h
# End Source File
# Begin Source File

SOURCE=.\ui\Uiapp.h
# End Source File
# Begin Source File

SOURCE=.\ui\Uigame.h
# End Source File
# Begin Source File

SOURCE=.\ui\Uiloop.h
# End Source File
# Begin Source File

SOURCE=.\ui\Winui.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ui\Bugterm.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ui\Buttpanl.cpp
# End Source File
# Begin Source File

SOURCE=.\ui\Cmdterm.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ui\Ged_win.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ui\Joypoll.cpp
# End Source File
# Begin Source File

SOURCE=.\ui\Movie.cpp
# End Source File
# Begin Source File

SOURCE=.\ui\Panlmode.cpp
# End Source File
# Begin Source File

SOURCE=.\ui\Panltool.cpp
# End Source File
# Begin Source File

SOURCE=.\ui\Uiamov.cpp
# End Source File
# Begin Source File

SOURCE=.\ui\Uianim.cpp
# End Source File
# Begin Source File

SOURCE=.\ui\Uiapp.cpp
# End Source File
# Begin Source File

SOURCE=.\ui\Uigame.cpp
# End Source File
# Begin Source File

SOURCE=.\ui\Uiloop.cpp
# End Source File
# Begin Source File

SOURCE=.\ui\Winui.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# End Group
# Begin Group "Win32"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\win32\Inclex.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# ADD CPP /w /W0 /D "YY_STATIC"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# ADD CPP /w /W0 /D "YY_STATIC"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD BASE CPP /w /W0 /D "YY_STATIC"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /w /W0 /D "YY_STATIC"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP Exclude_From_Build 1
# ADD BASE CPP /w /W0 /D "YY_STATIC"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /w /W0 /D "YY_STATIC"
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Win32\Linklex.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\win32\Mschlex.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# ADD CPP /w /W0 /D "YY_STATIC"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# ADD CPP /w /W0 /I ".\deepc\motion" /D "YY_STATIC"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD BASE CPP /w /W0 /I ".\deepc\motion" /D "YY_STATIC"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /w /W0 /I ".\deepc\motion" /D "YY_STATIC"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# ADD BASE CPP /w /W0 /I ".\deepc\motion" /D "YY_STATIC"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /w /W0 /I ".\deepc\motion" /D "YY_STATIC"
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\win32\Schlex.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# ADD CPP /w /W0 /D "YY_STATIC"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# ADD CPP /w /W0 /D "YY_STATIC"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD BASE CPP /w /W0 /D "YY_STATIC"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /w /W0 /D "YY_STATIC"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# ADD BASE CPP /w /W0 /D "YY_STATIC"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /w /W0 /D "YY_STATIC"
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\win32\Songlex.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

# ADD CPP /w /W0 /D "YY_STATIC"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# ADD CPP /w /W0 /D "YY_STATIC"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD BASE CPP /w /W0 /D "YY_STATIC"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /w /W0 /D "YY_STATIC"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# ADD BASE CPP /w /W0 /D "YY_STATIC"
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /w /W0 /D "YY_STATIC"
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# End Group
# Begin Group "_root"

# PROP Default_Filter ""
# Begin Group "Root Includes"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=.\_animtxt.h
# End Source File
# Begin Source File

SOURCE=.\_editgeo.h
# End Source File
# Begin Source File

SOURCE=.\Chatiid.h
# End Source File
# Begin Source File

SOURCE=.\Chevkind.h
# End Source File
# Begin Source File

SOURCE=.\Dialogs.h
# End Source File
# Begin Source File

SOURCE=.\Findhack.h
# End Source File
# Begin Source File

SOURCE=.\Frezreac.h
# End Source File
# Begin Source File

SOURCE=.\GIDPROP.H
# End Source File
# Begin Source File

SOURCE=.\GLOBALID.H
# End Source File
# Begin Source File

SOURCE=.\Gstrguid.h
# End Source File
# Begin Source File

SOURCE=.\Gtooliid.h
# End Source File
# Begin Source File

SOURCE=.\Inctab.h
# End Source File
# Begin Source File

SOURCE=.\Inctok.h
# End Source File
# Begin Source File

SOURCE=.\KEYCMD.H
# End Source File
# Begin Source File

SOURCE=.\lgversion.h
# End Source File
# Begin Source File

SOURCE=.\linksave.h
# End Source File
# Begin Source File

SOURCE=.\Miscdbg.h
# End Source File
# Begin Source File

SOURCE=.\NANODEF.H
# End Source File
# Begin Source File

SOURCE=.\PACKETS.H
# End Source File
# Begin Source File

SOURCE=.\pch.h
# End Source File
# Begin Source File

SOURCE=.\Persloop.h
# End Source File
# Begin Source File

SOURCE=.\Reg.h
# End Source File
# Begin Source File

SOURCE=.\Sampapp.h
# End Source File
# Begin Source File

SOURCE=.\Samploop.h
# End Source File
# Begin Source File

SOURCE=.\Sampprop.h
# End Source File
# Begin Source File

SOURCE=.\Songtok.h
# End Source File
# Begin Source File

SOURCE=.\Testloop.h
# End Source File
# Begin Source File

SOURCE=.\Testmode.h
# End Source File
# Begin Source File

SOURCE=.\Version.h
# End Source File
# Begin Source File

SOURCE=.\Vhot.h
# End Source File
# Begin Source File

SOURCE=.\Vismsg.h
# End Source File
# End Group
# Begin Group "Root Docs"

# PROP Default_Filter ".txt"
# End Group
# Begin Group "Resources"

# PROP Default_Filter ".rc,.res"
# Begin Source File

SOURCE=.\dark.rc

!IF  "$(CFG)" == "Dromed - Win32 Release"

# ADD BASE RSC /l 0x816
# ADD RSC /l 0x816 /i ".\framewrk"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# ADD BASE RSC /l 0x816
# ADD RSC /l 0x816 /i ".\framewrk"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD BASE RSC /l 0x816
# ADD RSC /l 0x816 /i ".\framewrk"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# ADD BASE RSC /l 0x816
# ADD RSC /l 0x816 /i ".\framewrk"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dialogs.rc
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\shock.rc
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Source File

SOURCE=.\Camguids.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Darktabl.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Frezreac.cpp
# End Source File
# Begin Source File

SOURCE=.\Gentable.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gidprop.cpp
# End Source File
# Begin Source File

SOURCE=.\Goof.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Inc.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\inclex.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Inctab.cpp
# End Source File
# Begin Source File

SOURCE=.\keycmd.c
# End Source File
# Begin Source File

SOURCE=.\Killme.cpp
# End Source File
# Begin Source File

SOURCE=.\oldasfx.c
# End Source File
# Begin Source File

SOURCE=.\pch.cpp

!IF  "$(CFG)" == "Dromed - Win32 Release"

# ADD CPP /Yc"pch.h"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# ADD CPP /Yc"pch.h"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# ADD CPP /Yc"pch.h"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# PROP Exclude_From_Build 1
# ADD BASE CPP /Yc"pch.h"
# ADD CPP /Yc"pch.h"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Songyacc.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Testloop.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Testmode.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Version.c

!IF  "$(CFG)" == "Dromed - Win32 Release"

!ELSEIF  "$(CFG)" == "Dromed - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Dromed - Win32 Opt No Precompiled Header"

# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
