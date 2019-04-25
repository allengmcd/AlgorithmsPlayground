@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
RadixTree_test.exe
popd
