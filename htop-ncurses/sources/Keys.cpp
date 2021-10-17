/*
** EPITECH PROJECT, 2021
** htop-ncurses
** File description:
** Keys
*/

#include "Htop.hpp"

void Htop::stop(void)
{
    _run = false;
}

void Htop::f2(void)
{
    if (_page == MAIN) {
        _page = SETUP;
        _cursor = {0, 0};
    } else {
        _page = MAIN;
    }
}

void Htop::up(void)
{
    if (!_cursor.y) return;
    --_cursor.y;
}

void Htop::down(void)
{
    ++_cursor.y;
}

void Htop::left(void)
{
    if (!_cursor.x) return;
    --_cursor.x;
}

void Htop::right(void)
{
    ++_cursor.x;
}

void Htop::enter(void)
{
    _enter = !_enter;
}

void Htop::keys(void)
{
    void (Htop::*effect[])(void) = {&Htop::stop, &Htop::f2, &Htop::up,
    &Htop::down, &Htop::left, &Htop::right, &Htop::enter};
    int keys[] = {113, 81, 65, 66, 68, 67, 10};

    // mvprintw(30, 20, "key;%d\n", _key);
    // if (_key == 10)
    //     mvprintw(31, 20, "here\n");
    _key = getch();
    _before = _cursor;
    for (int e = 0; e < 7; ++e) {
        if (_key == keys[e])
            (this->*effect[e])();
    }
}