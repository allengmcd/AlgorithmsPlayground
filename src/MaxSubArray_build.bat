@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
cl  -FC -Zi ..\src\MaxSubArray.c
popd
