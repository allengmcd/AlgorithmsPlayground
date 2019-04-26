@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
devenv SingleServerQueueing.exe
popd