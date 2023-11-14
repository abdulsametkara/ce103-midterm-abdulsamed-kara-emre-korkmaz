@echo off
setlocal

REM Set the path to the .git/hooks directory
set HOOKS_DIR=.git/hooks

REM Check if .git/hooks directory exists
if not exist "%HOOKS_DIR%" (
    echo Error: .git/hooks directory not found.
    exit /b 1
)

REM Backup current pre-Cinema script if it exists
if exist "%HOOKS_DIR%\pre-Cinema" (
    echo Backing up current pre-Cinema script...
    rename "%HOOKS_DIR%\pre-Cinema" "pre-Cinema.backup"
)

REM Copy 1-pre-Cinema to .git/hooks directory and rename it to pre-Cinema
copy "1-pre-Cinema" "%HOOKS_DIR%\pre-Cinema"

echo Script has been copied successfully.

pause

