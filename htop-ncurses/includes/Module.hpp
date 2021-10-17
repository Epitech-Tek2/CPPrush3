/*
** EPITECH PROJECT, 2021
** htop-ncurses
** File description:
** Module
*/

#ifndef MODULE_HPP_
#define MODULE_HPP_

#include <iostream>
#include <ncurses.h>
#include <sstream>
#include "../../Data/includes/SystemInfos.hpp"
#include "../../Data/includes/Date.hpp"
#include "../../Data/includes/NetInfos.hpp"
#include "../../Data/includes/CoreInfos.hpp"
#include "../../Data/includes/UserInfos.hpp"
#include "../../interfaces/IMonitorModule.hpp"

enum method {
    CONTENT,
    GRAPH,
};

enum PAGES {
    MAIN,
    SETUP,
};

struct Cursor {
    size_t x;
    size_t y;
};

class Module : public IMonitorModule
{
    public:
        Module();
        Module(size_t y, size_t x, std::string const &content, size_t colorC,
        std::string const &prefix = "", size_t colorP = 1, method display = CONTENT,
        std::string const &suffix = "", void (Module::*set)(void) = NULL);
        virtual ~Module();

        void displayHelp(bool setup) const; 
        void displayGraph(void);
        void displayContent(void);
        void display();
        void display(size_t y, size_t x);
        void displayUpon(size_t upon);
        void displaySetup(bool over, size_t y, size_t x, size_t upon, bool enter);

        size_t getY(void) const;
        size_t getX(void) const;

        static std::string memParse(std::string mem);
        virtual void setMemUsed(void);
        virtual void setMemFree(void);
        virtual void setMemMem(void);
        virtual void setTime(void);
        virtual void setActivity(void);
    private:
        std::string _prefix;
        std::string _content;
        std::string _suffix;
        size_t _colorP;
        size_t _colorC;
        size_t _y;
        size_t _x;
        method _display;
        void (Module::*_set)(void);
};

#endif /* !MODULE_HPP_ */
