/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** SystemInfos
*/

#ifndef SYSTEMINFOS_HPP_
#define SYSTEMINFOS_HPP_

#include <string>
#include <iostream>
#include <fstream>

class SystemInfos {
    public:
        SystemInfos();
        ~SystemInfos();

        const std::string &getSystemName() const;
        const std::string &getKernelVersion() const;
    protected:
    private:
        std::string _systemname;
        std::string _kernelversion;
};

#endif /* !SYSTEMINFOS_HPP_ */
