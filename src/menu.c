#include "curse_helper.h"
#include <ncurses.h>
#include <stdio.h>

#define ARRAY_LEN(xs) sizeof(xs) / sizeof(xs[0])

#define CLAMP(x, low, high)  (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

int main(void)
{
    START_CURSES;

    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    WINDOW* menuwin = newwin(6, x_max - 12, y_max - 8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);


    keypad(menuwin, true);
    const char* choices[3] = 
    {
        "Walk",
        "Jog",
        "Run",
    };

    int choice;
    int highlight = 0;

    while (true) 
    {
        for (size_t i = 0; i < ARRAY_LEN(choices); i++)
        {
            if (i == (size_t)highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, "%s", choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        int arr_len = ARRAY_LEN(choices);
        switch(choice)
        {
            case (int)'k':
            {
                highlight = CLAMP(highlight - 1, 0, arr_len - 1);
                break;
            }
            case (int)'j':
                highlight = CLAMP(highlight + 1, 0, arr_len - 1);
                break;
            default:
                break;
        }

        if (choice == 10)
            break;
    }

    END_CURSES;
}
