@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
cl  -FC -Zi ..\src\RadixTree_test.c
popd
