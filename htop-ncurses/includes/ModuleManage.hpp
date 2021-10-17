/*
** EPITECH PROJECT, 2021
** htop-ncurses
** File description:
** ModuleManage
*/

#ifndef MODULEMANAGE_HPP_
#define MODULEMANAGE_HPP_

#include "Module.hpp"
#include "Htop.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include "../../Data/includes/SystemInfos.hpp"
#include "../../Data/includes/Date.hpp"
#include "../../Data/includes/NetInfos.hpp"
#include "../../Data/includes/CoreInfos.hpp"
#include "../../Data/includes/UserInfos.hpp"
#include "../../interfaces/IMonitorDisplay.hpp"

class ModuleManage : public Htop, public IMonitorDisplay
{
    public:
        ModuleManage(SystemInfos &system, Date &date, NetInfos &net,
        CoreInfos &core, UserInfos &user);
        virtual ~ModuleManage();

        void display(void);
        void displaySetup(void);

        virtual int run(void);

        void moveModule(void);
        void moveModuleToLeft(void);
        void moveModuleToRight(void);
        void moveModuleUpAndDown(void);

        void cursorLimitation(void);
    private:
        std::vector<Module> _mLeft;
        std::vector<Module> _mRight;
        std::vector<Module> _available;
        Module _help;
        Module _headerAvailable;
        Module _headerLeft;
        Module _headerRight;
};

#endif /* !MODULEMANAGE_HPP_ */
