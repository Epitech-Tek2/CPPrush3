/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include <unistd.h>
#include <signal.h>
#include "SystemInfos.hpp"
#include "UserInfos.hpp"
#include "Date.hpp"
#include "CoreInfos.hpp"
#include "NetInfos.hpp"
#include "ModuleManage.hpp"
#include "Itop.hpp"


void updateRam(std::atomic<bool> &is_running);

int main(int ac, char **av)
{
    if (ac > 2) {
        std::cerr << "Too many arguments" << std::endl;
        return 84;
    }

    std::string launch_type = (std::string)av[1];

    if (launch_type.compare("-h") == 0) {
        std::cout << "[USAGE] ./MyGKrellm monitor_type" << std::endl
            << "\tmonitor_type = text OR graphical" << std::endl;
        return 0;
    }
    if (launch_type.compare("text") != 0 && launch_type.compare("graphical") != 0) {
        std::cerr << "Wrong launch mode detected" << std::endl;
        return 84;
    }

    SystemInfos sys;
    UserInfos users;
    Date date;
    CoreInfos core;
    NetInfos net;
    std::string new_arg = "";
    std::atomic<bool> is_running{true};
    std::thread update_time(updateTime, std::ref(is_running));
    std::thread update_core(updateCore, std::ref(is_running));
    std::thread update_ram(updateRam, std::ref(is_running));
    update_time.detach();
    update_core.detach();
    update_ram.detach();

    if (launch_type.compare("text") == 0) {
        ModuleManage monitor(sys, date, net, core, users);
        monitor.run();
        is_running = false;
    }
    if (launch_type.compare("graphical") == 0) {
        Itop monitor;
        monitor.run();
        is_running = false;
    }
    return 0;
}