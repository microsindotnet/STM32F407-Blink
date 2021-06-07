@call clean.bat

@SET PROJECTFOLDER=STM32F407-Blink
@SET PROJECTNAME=STM32F407-Blink
@SET ARCHIVE=%PROJECTNAME%.zip
@SET EXCLUDE1=doc
@SET EXCLUDE2=docs

@if exist %MyDocFolder% goto Backup
@goto ErrMyDocFolder

:Backup
@SET ARCHIVEFOLDER=%MyDocFolder%\FLOPPI\STM32\%PROJECTNAME%
@if not exist %ARCHIVEFOLDER% mkdir %ARCHIVEFOLDER%
@rem SET SERVERFOLDER=\\server\KOMAG\WORK\ANDREY_WORK\%PROJECTFOLDER%
SET SERVERFOLDER=P:\!MyDoc\floppi\STM32\%PROJECTNAME%
@if not exist %SERVERFOLDER% mkdir %SERVERFOLDER%
@SET ZIP="%ProgramFiles(x86)%/7-Zip/7z.exe" a -xr!%EXCLUDE1% -xr!%EXCLUDE2%
@if not exist %ZIP% goto ErrZip
%ZIP% %ARCHIVE% ../%PROJECTFOLDER%
@move /Y %ARCHIVE% %ARCHIVEFOLDER%
@autoname /pattern:YYMMDDhhmmss %ARCHIVEFOLDER%\%ARCHIVE%
@xcopy /A /M /Y %ARCHIVEFOLDER%\*.* "%SERVERFOLDER%\"
@goto exit

:ErrMyDocFolder
@echo MyDocFolder env variable not found!..
@pause
@goto exit

:ErrZip
@echo %ZIP% not found!..
@pause
@goto exit

:exit