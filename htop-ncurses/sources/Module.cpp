/*
** EPITECH PROJECT, 2021
** htop-ncurses
** File description:
** module
*/

#include "Module.hpp"

Module::Module()
 : _prefix("prefix: "), _content("content"), _suffix("suffix"), _colorP(0), _colorC(0), _y(3), _x(3), _display(CONTENT), _set(NULL)
{}

Module::Module(size_t y, size_t x, std::string const &content, size_t colorC,
std::string const &prefix, size_t colorP, method display, std::string const &suffix,
void (Module::*set)(void))
 : _prefix(prefix), _content(content), _suffix(suffix), _colorP(colorP), _colorC(colorC),
 _y(y), _x(x), _display(display), _set(set)
{}

Module::~Module(){}

void Module::displayGraph(void)
{
    float pourcent = std::atof(_content.c_str());
    size_t nbmax = (COLS / 3) - 6;
    size_t nb = (nbmax * pourcent) / 100;

    attron(COLOR_PAIR(15) | A_BOLD);
    mvprintw(_y, _x + _prefix.size(), "[");
    attroff(COLOR_PAIR(15) | A_BOLD);
    attron(_colorC);
    for (size_t e = 0; e < nbmax; ++e) {
        if (e < nb)
            printw("|");
        else
            printw(" ");
    }
    attroff(_colorC);
    printw("%s%%", _content.c_str());
    attron(COLOR_PAIR(15) | A_BOLD);
    printw("]");
    attroff(COLOR_PAIR(15) | A_BOLD);
}

void Module::displayContent(void)
{
    attron(_colorC);
    mvprintw(_y, _x + _prefix.size() + 2, _content.c_str());
    attroff(_colorC);
}

void Module::displayUpon(size_t upon)
{
    attron(_colorC);
    mvprintw(_y, _x, _content.c_str());
    for (size_t e = _x + _content.size(); e < upon; ++e)
        printw(" ");
    attroff(_colorC);
}

void Module::display(void)
{
    if (!_prefix.empty()) {
        attron(COLOR_PAIR(_colorP));
        mvprintw(_y, _x, "%s: ", _prefix.c_str());
        attroff(COLOR_PAIR(_colorP));
    }
    if (_display == CONTENT) {
        displayContent();
    } else if (_display == GRAPH) {
        displayGraph();
    }
    if (!_suffix.empty()) {
        attron(COLOR_PAIR(_colorP));
        mvprintw(_y, _x + _prefix.size() + _content.size() + 4, _suffix.c_str());
        attroff(COLOR_PAIR(_colorP));
    }
}

void Module::display(size_t y, size_t x)
{
    _y = y;
    _x = x;
    if (_set)
        (this->*_set)();
    if (!_prefix.empty()) {
        attron(COLOR_PAIR(_colorP));
        mvprintw(_y, _x, "%s: ", _prefix.c_str());
        attroff(COLOR_PAIR(_colorP));
    }
    if (_display == CONTENT) {
        displayContent();
    } else if (_display == GRAPH) {
        displayGraph();
    }
    if (!_suffix.empty()) {
        attron(COLOR_PAIR(_colorP));
        mvprintw(_y, _x + _prefix.size() + _content.size() + 3, _suffix.c_str());
        attroff(COLOR_PAIR(_colorP));
    }
}

void Module::displaySetup(bool over, size_t y, size_t x, size_t upon, bool enter)
{
    if (over) {
        attron(COLOR_PAIR((enter) ? 7 : 15) | A_STANDOUT);
    } else
        attron(COLOR_PAIR(15));
    mvprintw(y, x, _prefix.c_str());
    if (_display == GRAPH)
        printw("  [Bar]");
    else if (_display == CONTENT)
        printw(" [Text]");
    for (size_t e = x + _prefix.size() + 7; e < upon; ++e)
        printw(" ");
    if (over)
        attroff(COLOR_PAIR((enter) ? 7 : 15) | A_STANDOUT);
    else
        attroff(COLOR_PAIR(15));
}

size_t Module::getY(void) const
{
    return (_y);
}

size_t Module::getX(void) const
{
    return (_x);
}

void Module::setMemUsed(void)
{
    _content = Module::memParse(std::to_string(mem_used));
}

void Module::setMemFree(void)
{
    _content = Module::memParse(std::to_string(mem_free));
}

void Module::setMemMem(void)
{
    std::ostringstream str;

    str << std::setprecision(2) << std::fixed << (mem_used * 100.0 / mem_total);
    _content = str.str();
}

void Module::setTime(void)
{
    std::ostringstream str;

    str << std::setfill('0') << std::setw(2) << _hour;
    str << ":" << std::setfill('0') << std::setw(2) << _minute;
    str << ":" <<std::setfill('0') << std::setw(2) << _seconds;
    _content = str.str();
}

void Module::setActivity(void)
{
    std::ostringstream str;

    str << std::setprecision(2) << std::fixed << activity;
    _content = str.str();
}

static void printTouch(const char *touch, const char *effect)
{
    attron(COLOR_PAIR(6) | A_STANDOUT);
    printw(touch);
    attroff(COLOR_PAIR(6) | A_STANDOUT);
    attron(COLOR_PAIR(15));
    printw(effect);
    attroff(COLOR_PAIR(15));
}

void Module::displayHelp(bool setup) const
{
    mvprintw(LINES - 1, 0, "");
    printTouch(" Q ", " QUIT ");
    if (!setup)
        printTouch(" F2 ", " SETUP ");
    if (setup) {
        printTouch(" F2 ", " QUIT SETUP ");
        printTouch(" -> ", " MOVE RIGHT ");
        printTouch(" | ", " MOVE UP ");
        printTouch(" | ", " MOVE DOWN ");
        printTouch(" <- ", " MOVE LEFT ");
        printTouch(" ENTER ", " SELECT ");
    }
}

std::string Module::memParse(std::string mem)
{
    size_t n = 0;

    for (int e = mem.size() - 1; e >= 0; --e, ++n) {
        if (n == 2 && e) {
            mem.insert(e, 1, '.');
            n = 0;
        }
    }
    return (mem);
}