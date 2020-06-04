/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** ncurses bonus for the corewar project
*/

#include <stdlib.h>
#include <ncurses.h>
#include "chain_list.h"
#include "vm.h"
#include "console.h"


static void print_colors(int *x, int *y, unsigned char *aff_mem,
unsigned char *mem)
{
    char *hexa = "0123456789ABCDEF";

    for (int i = 0; i < 178; ++i)
        mvprintw(*y - 1, *x + i, "_");
    mvprintw(*y, (*x)++, "|");
    attroff(COLOR_PAIR(84));
    for (int i = 0; i < MEM_SIZE; ++i) {
        if (i % 176 == 0 && i != 0) {
            attron(COLOR_PAIR(84));
            mvprintw(*y, *x, "|");
            *y += 1;
            *x = 10;
            mvprintw(*y, (*x)++, "|");
            attroff(COLOR_PAIR(84));
        }
        attron(COLOR_PAIR(aff_mem[i]));
        mvprintw(*y, (*x)++, "%c%c", hexa[(mem[i] >> 4)], hexa[(mem[i] & 0xF)]);
        attroff(COLOR_PAIR(aff_mem[i]));
    }
}

void print_colorized_mem(unsigned char *aff_mem, unsigned char *mem)
{
    int x = 10;
    int y = 9;
    short box[2] = {COLOR_BLACK, COLOR_WHITE};

    init_pair(84, box[1], box[0]);
    attron(A_BOLD);
    attron(COLOR_PAIR(84));
    print_colors(&x, &y, aff_mem, mem);
    ++y;
    x = 10;
    attron(COLOR_PAIR(84));
    for (int i = 0; i < 178; ++i)
        mvprintw(y, x++, "_");
    attroff(COLOR_PAIR(84));
    attroff(A_BOLD);
    refresh();
}

void start_ncurses(list_t *champ)
{
    WINDOW *window = initscr();
    short color1[4] = {COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_GREEN};
    short color2[4] = {COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_GREEN};
    int i = 0;

    if (!window) {
        my_puterr("Failed to create window\n");
        exit(84);
    }
    nodelay(window, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    start_color();
    for (list_t *temp = champ; temp != NULL && i < 4; temp = temp->next) {
        init_pair(temp->id, color2[i], color1[i]);
        ++i;
    }
}
