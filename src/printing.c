#include <curses.h>

int main(void)
{
    const char* msg = "Hello World";
    // Initializes screen
    // Sets up memory and clears the screen
    initscr();

    /* ------------------------------------------------------------------ */
    
    int x, y;
    x = 10;
    y = 5;

    //moves the cursor to specified location.
    move(y, x); 

    // prints a string (const char *) to a window
    printw("%s\n", msg);

    // refreshes the screen to match whats in memory
    refresh();

    //waits for user input, returns int value of that key
    int c = getch();
    clear();

    mvprintw(0, 0, "\n%d", c);

    /* ------------------------------------------------------------------ */

    getch();

    // deallocates memory and ends ncurses
    endwin();
}
