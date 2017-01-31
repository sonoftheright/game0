@echo off
if not defined DevEnvDir (
    call vcvarsall.bat
)
call cl -Ox systemstest.cpp