@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
RadixTree.exe
popd
