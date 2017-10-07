xcopy r:\prj\thief2\src\*.c . /D
xcopy r:\prj\thief2\src\*.cpp . /D
xcopy r:\prj\thief2\src\*.h .   /D
xcopy r:\prj\thief2\src\*.rc . /D
xcopy r:\prj\thief2\src\*.lex . /D
xcopy r:\prj\thief2\src\*.y . /D
copy r:\prj\thief2\src\makefile . /D

xcopy r:\prj\thief2\src\actreact\*.c .\actreact /D
xcopy r:\prj\thief2\src\actreact\*.cpp .\actreact /D
xcopy r:\prj\thief2\src\actreact\*.h .\actreact   /D

xcopy r:\prj\thief2\src\ai\*.c .\ai /D
xcopy r:\prj\thief2\src\ai\*.cpp .\ai /D
xcopy r:\prj\thief2\src\ai\*.h .\ai   /D

xcopy r:\prj\thief2\src\csg\*.c .\csg /D
xcopy r:\prj\thief2\src\csg\*.cpp .\csg /D
xcopy r:\prj\thief2\src\csg\*.h .\csg   /D

xcopy r:\prj\thief2\src\dark\*.c .\dark /D
xcopy r:\prj\thief2\src\dark\*.cpp .\dark /D
xcopy r:\prj\thief2\src\dark\*.h .\dark   /D

xcopy r:\prj\thief2\src\editor\*.c .\editor /D
xcopy r:\prj\thief2\src\editor\*.cpp .\editor /D
xcopy r:\prj\thief2\src\editor\*.h .\editor   /D

xcopy r:\prj\thief2\src\engfeat\*.c .\engfeat /D
xcopy r:\prj\thief2\src\engfeat\*.cpp .\engfeat /D
xcopy r:\prj\thief2\src\engfeat\*.h .\engfeat   /D

xcopy r:\prj\thief2\src\framewrk\*.c .\framewrk /D
xcopy r:\prj\thief2\src\framewrk\*.cpp .\framewrk /D
xcopy r:\prj\thief2\src\framewrk\*.h .\framewrk   /D

xcopy r:\prj\thief2\src\motion\*.c .\motion /D
xcopy r:\prj\thief2\src\motion\*.cpp .\motion /D
xcopy r:\prj\thief2\src\motion\*.h .\motion   /D

xcopy r:\prj\thief2\src\object\*.c .\object /D
xcopy r:\prj\thief2\src\object\*.cpp .\object /D
xcopy r:\prj\thief2\src\object\*.h .\object   /D

xcopy r:\prj\thief2\src\physics\*.c .\physics /D
xcopy r:\prj\thief2\src\physics\*.cpp .\physics /D
xcopy r:\prj\thief2\src\physics\*.h .\physics   /D

xcopy r:\prj\thief2\src\portal\*.c .\portal /D
xcopy r:\prj\thief2\src\portal\*.cpp .\portal /D
xcopy r:\prj\thief2\src\portal\*.h .\portal   /D

xcopy r:\prj\thief2\src\render\*.c .\render /D
xcopy r:\prj\thief2\src\render\*.cpp .\render /D
xcopy r:\prj\thief2\src\render\*.h .\render   /D

xcopy r:\prj\thief2\src\script\*.c .\script /D
xcopy r:\prj\thief2\src\script\*.cpp .\script /D
xcopy r:\prj\thief2\src\script\*.h .\script   /D

xcopy r:\prj\thief2\src\shock\*.c .\shock /D
xcopy r:\prj\thief2\src\shock\*.cpp .\shock /D
xcopy r:\prj\thief2\src\shock\*.h .\shock   /D

xcopy r:\prj\thief2\src\sim\*.c .\sim /D
xcopy r:\prj\thief2\src\sim\*.cpp .\sim /D
xcopy r:\prj\thief2\src\sim\*.h .\sim   /D

xcopy r:\prj\thief2\src\sound\*.c .\sound /D
xcopy r:\prj\thief2\src\sound\*.cpp .\sound /D
xcopy r:\prj\thief2\src\sound\*.h .\sound   /D

xcopy r:\prj\thief2\src\ui\*.c .\ui /D
xcopy r:\prj\thief2\src\ui\*.cpp .\ui /D
xcopy r:\prj\thief2\src\ui\*.h .\ui   /D

if "%TARG%"=="deepc" goto copydeepc
goto skupcopyend

:copydeepc

copy r:\prj\thief2\src\deepc\actreact\*.c       .\deepc\actreact /D
copy r:\prj\thief2\src\deepc\actreact\*.cpp     .\deepc\actreact /D
copy r:\prj\thief2\src\deepc\actreact\*.h       .\deepc\actreact /D

copy r:\prj\thief2\src\deepc\ai\*.c             .\deepc\ai /D
copy r:\prj\thief2\src\deepc\ai\*.cpp           .\deepc\ai /D
copy r:\prj\thief2\src\deepc\ai\*.h             .\deepc\ai /D

copy r:\prj\thief2\src\deepc\editor\*.c         .\deepc\editor /D
copy r:\prj\thief2\src\deepc\editor\*.cpp       .\deepc\editor /D
copy r:\prj\thief2\src\deepc\editor\*.h         .\deepc\editor /D

copy r:\prj\thief2\src\deepc\engfeat\*.c        .\deepc\engfeat /D
copy r:\prj\thief2\src\deepc\engfeat\*.cpp      .\deepc\engfeat /D
copy r:\prj\thief2\src\deepc\engfeat\*.h        .\deepc\engfeat /D

copy r:\prj\thief2\src\deepc\game\*.c           .\deepc\game /D
copy r:\prj\thief2\src\deepc\game\*.cpp         .\deepc\game /D
copy r:\prj\thief2\src\deepc\game\*.h           .\deepc\game /D

copy r:\prj\thief2\src\deepc\input\*.c          .\deepc\input /D 
copy r:\prj\thief2\src\deepc\input\*.cpp        .\deepc\input /D 
copy r:\prj\thief2\src\deepc\input\*.h          .\deepc\input /D 

copy r:\prj\thief2\src\deepc\motion\*.c        .\deepc\motion /D
copy r:\prj\thief2\src\deepc\motion\*.cpp      .\deepc\motion /D
copy r:\prj\thief2\src\deepc\motion\*.h        .\deepc\motion /D

copy r:\prj\thief2\src\deepc\mp\*.c            .\deepc\mp /D 
copy r:\prj\thief2\src\deepc\mp\*.cpp          .\deepc\mp /D 
copy r:\prj\thief2\src\deepc\mp\*.h            .\deepc\mp /D 

copy r:\prj\thief2\src\deepc\object\*.c        .\deepc\object /D 
copy r:\prj\thief2\src\deepc\object\*.cpp      .\deepc\object /D 
copy r:\prj\thief2\src\deepc\object\*.h        .\deepc\object /D 

copy r:\prj\thief2\src\deepc\player\*.c        .\deepc\player /D 
copy r:\prj\thief2\src\deepc\player\*.cpp      .\deepc\player /D 
copy r:\prj\thief2\src\deepc\player\*.h        .\deepc\player /D 

copy r:\prj\thief2\src\deepc\render\*.c        .\deepc\render /D 
copy r:\prj\thief2\src\deepc\render\*.cpp      .\deepc\render /D 
copy r:\prj\thief2\src\deepc\render\*.h        .\deepc\render /D 

copy r:\prj\thief2\src\deepc\scripts\*.c       .\deepc\scripts /D 
copy r:\prj\thief2\src\deepc\scripts\*.cpp     .\deepc\scripts /D 
copy r:\prj\thief2\src\deepc\scripts\*.h       .\deepc\scripts /D 

copy r:\prj\thief2\src\deepc\sound\*.c        .\deepc\sound /D
copy r:\prj\thief2\src\deepc\sound\*.cpp      .\deepc\sound /D
copy r:\prj\thief2\src\deepc\sound\*.h        .\deepc\sound /D

copy r:\prj\thief2\src\deepc\ui\*.c          .\deepc\ui /D 
copy r:\prj\thief2\src\deepc\ui\*.cpp        .\deepc\ui /D 
copy r:\prj\thief2\src\deepc\ui\*.h          .\deepc\ui /D 

copy r:\prj\thief2\src\deepc\weapon\*.c       .\deepc\weapon /D 
copy r:\prj\thief2\src\deepc\weapon\*.cpp     .\deepc\weapon /D 
copy r:\prj\thief2\src\deepc\weapon\*.h       .\deepc\weapon /D 

goto skupcopyend

:skupcopyend
