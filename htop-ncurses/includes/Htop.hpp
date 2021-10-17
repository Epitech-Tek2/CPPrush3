/*
** EPITECH PROJECT, 2021
** htop-ncurses
** File description:
** htop
*/

#ifndef HTOP_HPP_
#define HTOP_HPP_

// struct Cursor {
//     size_t x;
//     size_t y;
// };

#include <iostream>
#include <curses.h>
#include <string>
#include "Module.hpp"

class Htop {
    public:
        Htop();
        Htop(Htop const& htop) = delete;
        virtual ~Htop();

        void keys(void);

        void stop(void);
        void f2(void);
        void echap(void);
        void up(void);
        void left(void);
        void right(void);
        void down(void);
        void enter(void);

        void operator=(Htop const& target) = delete;
    protected:
        bool _run;
        int _key;
        bool _enter;
        size_t _page;
        Cursor _cursor;
        Cursor _before;
};

#endif /* !HTOP_HPP_ */
