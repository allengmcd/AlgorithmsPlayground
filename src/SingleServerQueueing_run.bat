@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
SingleServerQueueing.exe
popd
