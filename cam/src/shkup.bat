co shkupcpy.bat
call shkupcpy
co shkupbld.bat
call shkupbld
copy r:\prj\cam\skup\shock\cam\src\shockhyb.exe r:\prj\shock\release
copy r:\prj\shock\scripts\*.osm r:\prj\shock\release\scripts
copy r:\prj\cam\src\shock.cfg r:\prj\cam\release
copy r:\prj\cam\release\*.cfg r:\prj\shock\release
copy r:\prj\cam\release\*.dll r:\prj\shock\release