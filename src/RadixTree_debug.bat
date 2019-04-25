@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
devenv RadixTree_test.exe
popd