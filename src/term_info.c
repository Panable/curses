#include "curse_helper.h"
#include <curses.h>

int main(void) 
{
    START_CURSES;

    // WINDOW* win = newwin(10, 20, 10, 10);

    WINDOW* win = stdscr;
    
    int y, x;
    int y_beg, x_beg;
    int y_max, x_max;



    getyx(win, y, x);
    getbegyx(win, y_beg, x_beg);
    getmaxyx(win, y_max, x_max);

    //printw("%d, %d, %d, %d, %d, %d", y, x, y_beg, x_beg, y_max, x_max);
    
    mvprintw(y_max / 2, x_max / 2, "hello");

    END_CURSES;
}
