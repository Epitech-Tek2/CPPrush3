/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** SystemInfos
*/

#include "SystemInfos.hpp"

SystemInfos::SystemInfos()
{
    std::ifstream in;
    std::string unparsed_line;


    in.open("/proc/version");

    if (in.is_open() == false)
        throw ("Wait, where are the files needed?");
    std::getline(in, unparsed_line);

    _systemname = unparsed_line.substr(0, unparsed_line.find(' '));
    unparsed_line.erase(0, unparsed_line.find(' ') + 1);
    unparsed_line.erase(0, unparsed_line.find(' ') + 1);
    _kernelversion = unparsed_line.substr(0, unparsed_line.find(' '));

    in.close();
}

SystemInfos::~SystemInfos()
{
}

const std::string &SystemInfos::getSystemName() const {return _systemname;}

const std::string &SystemInfos::getKernelVersion() const {return _kernelversion;}