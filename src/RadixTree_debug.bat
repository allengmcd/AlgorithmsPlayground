@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
devenv RadixTree.exe
popd