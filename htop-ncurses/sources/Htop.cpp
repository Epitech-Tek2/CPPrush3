/*
** EPITECH PROJECT, 2021
** htop-ncurses
** File description:
** Htop
*/

#include "Htop.hpp"

Htop::Htop() : _run(true), _key(-1), _enter(false), _page(0)
{
    initscr();
    timeout(2000);
    cbreak();
    keypad(nullptr, TRUE);
    start_color();
    for (int e = 1; e < 100; e++)
        init_pair(e, e, 0);
    _cursor = {0, 0};
}

Htop::~Htop()
{
    endwin();
}
