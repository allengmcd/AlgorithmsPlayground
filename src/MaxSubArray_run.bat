@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
MaxSubArray.exe
popd
