#include "curse_helper.h"
#include <curses.h>
#define CLAMP(x, low, high)  (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

typedef struct {
    WINDOW* win;
    int x;
    int y;
    int x_max;
    int y_max;
    char c;
    int color;
} Player;

void move_up(Player* player)
{
    player->y = CLAMP(player->y - 1, 1, player->y_max - 2);
}

void move_down(Player* player)
{
    player->y = CLAMP(player->y + 1, 1, player->y_max - 2);
}

void move_left(Player* player)
{
    player->x = CLAMP(player->x - 1, 1, player->x_max - 2);
}

void move_right(Player* player)
{
    player->x = CLAMP(player->x + 1, 1, player->x_max - 2);
}

void display(Player* player)
{
    init_pair(1, player->color, COLOR_BLACK);
    wattron(player->win, COLOR_PAIR(1));
    mvwaddch(player->win, player->y, player->x, player->c);
}

int get_move(Player* player)
{
    int choice = wgetch(player->win);

    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    wattron(player->win, COLOR_PAIR(2));
    mvwaddch(player->win, player->y, player->x, '.');
    switch (choice)
    {
        case KEY_UP:
            move_up(player);
            break;
        case KEY_DOWN:
            move_down(player);
            break;
        case KEY_LEFT:
            move_left(player);
            break;
        case KEY_RIGHT:
            move_right(player);
            break;
    }
    return choice;
}


int main(void)
{
    START_CURSES;

    // get screen size
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    curs_set(0);

    WINDOW* playwin = newwin(20, 50, (y_max / 2) - 10, 10);
    box(playwin, 0, 0);
    keypad(playwin, true);

    start_color();
    Player player = {
        .x = 1,
        .y = 1,
        .color = COLOR_CYAN,
        .win = playwin,
        .x_max = getmaxx(playwin),
        .y_max = getmaxy(playwin),
        .c = '*',
    };


    do {
        display(&player);
        wrefresh(playwin);
    } while(get_move(&player) != 'x');

    refresh();
    wrefresh(playwin);

    END_CURSES;
    return 0;
}
