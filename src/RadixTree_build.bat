@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
cl  -FC -Zi ..\src\RadixTree.c
popd
