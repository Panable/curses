#!/bin/sh

set -xe

CC=cc
LIBS="-lncurses"
CFLAGS="-Wall -Wextra -std=c11 -pedantic -ggdb"

SRC="src/main.c"

bear -- $CC $CFLAGS -o build/curse $SRC $LIBS
