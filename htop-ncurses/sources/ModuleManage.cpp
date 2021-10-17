/*
** EPITECH PROJECT, 2021
** htop-ncurses
** File description:
** ModuleManage
*/

#include "ModuleManage.hpp"

ModuleManage::ModuleManage(SystemInfos &system, Date &date, NetInfos &net,
CoreInfos &core, UserInfos &user)
{
    _mLeft = {
        Module(2, 3, user.getHostName(), COLOR_PAIR(15) | A_BOLD, "Hostname", 6),
        Module(3, 3, user.getUserName(), COLOR_PAIR(15) | A_BOLD, "Username", 6),
        Module(4, 3, system.getSystemName(), COLOR_PAIR(15) | A_BOLD, "Operating System", 6),
        Module(5, 3, system.getKernelVersion(), COLOR_PAIR(15) | A_BOLD, "Kernel version", 6),
        Module(6, 3, Module::memParse(std::to_string(mem_used)),
        COLOR_PAIR(14) | A_BOLD, "Used Memory", 6, CONTENT, "KB", &Module::setMemUsed),
        Module(7, 3, Module::memParse(std::to_string(mem_free)),
        COLOR_PAIR(14) | A_BOLD, "Free Memory", 6, CONTENT, "KB", &Module::setMemFree),
        Module(8, 3, Module::memParse(std::to_string(mem_total)),
        COLOR_PAIR(14) | A_BOLD, "Total Memory", 6, CONTENT, "KB"),
        Module(9, 3, std::to_string(mem_used * 100 / mem_total),
        COLOR_PAIR(2) | A_BOLD, "Memory usage", 6, GRAPH, "", &Module::setMemMem),
    };
    date.setTime(_hour, _minute,_seconds);
    _mRight = {
        Module(2, 30, net.getNet(), COLOR_PAIR(15) | A_BOLD, "Net", 6),
        Module(3, 30, date.getDate(), COLOR_PAIR(15) | A_BOLD, "Date", 6),
        Module(4, 30, date.getTime(), COLOR_PAIR(15) | A_BOLD, "Time", 6, CONTENT, "",
        &Module::setTime),
        Module(5, 30, core.getFrequency(), COLOR_PAIR(14) | A_BOLD, "Frequency",
        6, CONTENT, "Hz"),
        Module(6, 30, core.getModel(), COLOR_PAIR(15) | A_BOLD, "Model", 6),
        Module(7, 30, std::to_string(core.getNbCore()), COLOR_PAIR(14) | A_BOLD,
        "Number of Core", 6),
        Module(8, 30, std::to_string(activity), COLOR_PAIR(2) | A_BOLD,
        "Average", 6, GRAPH, "", &Module::setActivity),
    };
    _available = {};
    _headerLeft = Module(LINES / 2.5, 3, "COLUMN LEFT", COLOR_PAIR(6) | A_REVERSE);
    _headerRight = Module(LINES / 2.5, (COLS / 3) + 3, "COLUMN RIGHT", COLOR_PAIR(6) | A_REVERSE);
    _headerAvailable = Module(LINES / 2.5, (COLS / 3) * 2 + 3, "AVAILABLE", COLOR_PAIR(6) | A_REVERSE);
}

ModuleManage::~ModuleManage(){}

int ModuleManage::run(void)
{
    while (_run) {
        clear();
        curs_set(0);
        refresh();
        display();
        keys();
        noecho();
    }
    return (0);
}

void ModuleManage::display(void)
{
    if (_page == SETUP) {
        cursorLimitation();
        if (_enter)
            moveModule();
        displaySetup();
    }
    _help.displayHelp(_page);
    for (size_t e = 0; e < _mLeft.size(); ++e) {
        _mLeft[e].display(2 + e, 3);
    }
    for (size_t e = 0; e < _mRight.size(); ++e) {
        _mRight[e].display(2 + e, COLS / 2 + 3);
    }
}

void ModuleManage::moveModuleToLeft(void)
{
    if (_before.x == 2) {
        if (_before.y >= _mRight.size()) {
            _mRight.push_back(_available[_before.y]);
            ++_cursor.y;
        }
        else
            _mRight.insert(_mRight.begin() + _before.y, _available[_before.y]);
        _available.erase(_available.begin() + _before.y);
    } else if (_before.x == 1) {
        if (_before.y >= _mLeft.size()) {
            _mLeft.push_back(_mRight[_before.y]);
            ++_cursor.y;
        } else
            _mLeft.insert(_mLeft.begin() + _before.y, _mRight[_before.y]);
        _mRight.erase(_mRight.begin() + _before.y);
    }
}

void ModuleManage::moveModuleToRight(void)
{
    if (_before.x == 0) {
        if (_before.y >= _mRight.size()) {
            _mRight.push_back(_mLeft[_before.y]);
            ++_cursor.y;
        } else
            _mRight.insert(_mRight.begin() +_before.y, _mLeft[_before.y]);
        _mLeft.erase(_mLeft.begin() + _before.y);
    } else if (_before.x == 1) {
        if (_before.y >= _available.size()) {
            _available.push_back(_mRight[_before.y]);
            ++_cursor.y;
        } else
            _available.insert(_available.begin() + _before.y, _mRight[_before.y]);
        _mRight.erase(_mRight.begin() + _before.y);
    }
}

void ModuleManage::moveModuleUpAndDown(void)
{
    if (_cursor.x == 0)
        std::swap(_mLeft[_before.y], _mLeft[_cursor.y]);
    else if (_cursor.x == 1)
        std::swap(_mRight[_before.y], _mRight[_cursor.y]);
    else
        std::swap(_available[_before.y], _available[_cursor.y]);
}

void ModuleManage::moveModule(void)
{
    if (_before.x - _cursor.x == 1) {
        moveModuleToLeft();
    } else if (_cursor.x - _before.x == 1) {
        moveModuleToRight();
    } else if (_before.y != _cursor.y) {
        moveModuleUpAndDown();
    }
}

void ModuleManage::displaySetup(void)
{
    _headerLeft.displayUpon((COLS / 3) - 1);
    for (size_t e = 0; e < _mLeft.size(); ++e) {
        _mLeft[e].displaySetup((_cursor.x == 0 && _cursor.y == e), (LINES / 2.5) + e + 1,
        3, (COLS / 3) - 1, _enter);
    }
    _headerRight.displayUpon((COLS / 3) * 2 - 1);
    for (size_t e = 0; e < _mRight.size(); ++e) {
        _mRight[e].displaySetup((_cursor.x == 1 && _cursor.y == e), LINES / 2.5 + e + 1,
        (COLS / 3) + 3, (COLS / 3) * 2 - 1, _enter);
    }
    _headerAvailable.displayUpon(COLS - 3);
    for (size_t e = 0; e < _available.size(); ++e) {
        _available[e].displaySetup((_cursor.x == 2 && _cursor.y == e), LINES / 2.5 + e + 1,
        (COLS / 3) * 2 + 3, COLS - 3, _enter);
    }
}

void ModuleManage::cursorLimitation(void)
{
    if (!_enter && _cursor.x == 1 && !_mRight.size())
        (_before.x == 0) ? ++_cursor.x : --_cursor.x;
    if (_cursor.x > 2) _cursor.x = 2;
    if (_cursor.x == 2 && !_available.size() && !_enter) _cursor.x = 1;
    if (_cursor.x == 0 && _cursor.y >= _mLeft.size())
        _cursor.y = _mLeft.size() - 1;
    if (_cursor.x == 1 && _cursor.y >= _mRight.size())
        _cursor.y = _mRight.size() - 1;
    if (_cursor.x == 2 && _cursor.y >= _available.size())
        _cursor.y = _available.size() - 1;
}
