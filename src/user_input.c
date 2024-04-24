#include "curse_helper.h"
#include <ncurses.h>

int main(void)
{
    START_CURSES;

    // get screen size
    
    int y_max, x_max;

    getmaxyx(stdscr, y_max, x_max);

    WINDOW* input_win = newwin(3, x_max - 12, y_max - 5, 5);

    box(input_win, 0, 0);

    refresh();
    wrefresh(input_win);

    keypad(input_win, true);

    int c = wgetch(input_win);
    if (c == KEY_UP)
    {
        mvwprintw(input_win, 1, 1, "You pressed keyup");
        wrefresh(input_win);
    }

    END_CURSES;
}
