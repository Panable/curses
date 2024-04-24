#include <curses.h>
#include <ncurses.h>
#define START_CURSES \
    do { \
        initscr();\
        raw();\
        noecho();\
    }\
    while(0)\

int main(void)
{
    START_CURSES;

    if (!has_colors())
        printw("Terminal does not support colors\n");
    else
        printw("Terminal does support colors\n");

    start_color();

    if (can_change_color())
        printw("Terminal supports color changing\n");
    else
        printw("Terminal does not support color changing\n");

    //init_color(COLOR_CYAN, 0-999, 0-999, 0-999); -> redefines color
    //init_color(COLOR_CYAN, 999, 0, 0);


    //id, foreground, background
    init_pair(1, COLOR_CYAN, COLOR_WHITE);
    attron(COLOR_PAIR(1));

    printw("Test\n");

    getch();
    endwin();
}
