#!/bin/bash

root=$PWD

files="
$root/code/main.cpp
"

includes="
-I/usr/local/include/
"

libs="
-L/usr/local/lib
-lm
-lX11

-lSDL2
-lSDL2main
-lSDL2_image
"

binary=$root/build/sandbox
flags="-O0 -g3"

mkdir -p $root/build/
clang $files $includes $flags $libs -o $binary