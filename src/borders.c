#include <ncurses.h>

int main(void)
{
    initscr();

    // cbreak(); -> similar to raw
    // raw();    -> ctrl+c doesn't work
    // noecho(); -> when you type it doesn't echo your keys

    int height, width, start_y, start_x;

    height = 10;
    width = 20;
    start_y = start_x = 10;

    WINDOW* win = newwin(height, width, start_y, start_x);
    refresh();


    //box(win, 0, 0); -> pretty border
    
    //box(win, (int)'c', (int)'c'); -> border with 'c' 
    
    int left, right, top, bottom, tlc, trc, blc, brc;

    left = right = 103;
    top = bottom = 104;
    tlc = trc = blc = brc = (int)'c';

    wborder(win, left, right, top, bottom, tlc, trc, blc, brc);

    //Move in window then print
    mvwprintw(win, 1, 1, "Test");

    //Move cursor inside window
    wmove(win, 2, 2);

    wprintw(win, "Test 2");

    wrefresh(win);

    getch();
    getch();

    endwin();
}
