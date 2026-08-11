@echo off
REM Run this INSIDE your local clone of the wtlab repo (the folder that has a .git folder in it).
REM It moves everything currently in the repo into a "previous" folder, then adds
REM the new pr1..pr8 folders (copied alongside this script) and commits.
REM
REM Usage:
REM   1. cd into your local wtlab repo clone (Command Prompt or PowerShell)
REM   2. copy this script + the pr1..pr8 folders into that repo folder
REM   3. run:  reorganize.bat
REM   4. review with: git status
REM   5. push:  git push

setlocal enabledelayedexpansion

if not exist ".git" (
    echo Run this from inside your local wtlab repo folder ^(the one containing .git^). Aborting.
    exit /b 1
)

if not exist "previous" mkdir previous

REM move files
for %%F in (*) do (
    set "skip=0"
    if /I "%%F"=="reorganize.bat" set skip=1
    if /I "%%F"=="reorganize.sh" set skip=1
    if !skip! == 0 (
        git mv "%%F" "previous\%%F" 2>nul || move "%%F" "previous\%%F" >nul
    )
)

REM move folders (except .git, previous, pr1..pr8)
for /d %%D in (*) do (
    set "skip=0"
    if /I "%%D"==".git" set skip=1
    if /I "%%D"=="previous" set skip=1
    if /I "%%D"=="pr1" set skip=1
    if /I "%%D"=="pr2" set skip=1
    if /I "%%D"=="pr3" set skip=1
    if /I "%%D"=="pr4" set skip=1
    if /I "%%D"=="pr5" set skip=1
    if /I "%%D"=="pr6" set skip=1
    if /I "%%D"=="pr7" set skip=1
    if /I "%%D"=="pr8" set skip=1
    if !skip! == 0 (
        git mv "%%D" "previous\%%D" 2>nul || move "%%D" "previous\%%D" >nul
    )
)

git add -A
git commit -m "Reorganize: move existing files into previous/, add pr1-pr8 practicals"

echo Done. Review with "git status", then push with "git push".
