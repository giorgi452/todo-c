@echo off
set APP_NAME=TodoC
set VERSION=1.0
set OUTPUT_DIR=build\bin
set ZIP_NAME=%APP_NAME%_%VERSION%_windows.zip

cd %OUTPUT_DIR%
tar -a -cf ..\..\%ZIP_NAME% *
echo Packaged: %ZIP_NAME%

