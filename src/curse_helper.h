#pragma once

#include <ncurses.h>

#define START_CURSES \
    do { \
        initscr();\
        noecho();\
    }\
    while(0)\

#define START_CURSES_RAW \
    do { \
        initscr();\
        raw();\
        noecho();\
    }\
    while(0)\

#define END_CURSES\
    do { \
        getch();\
        endwin();\
    }\
    while(0)
