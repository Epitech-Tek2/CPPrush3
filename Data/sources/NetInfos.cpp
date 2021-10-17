/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** NetInfos
*/

#include "NetInfos.hpp"

NetInfos::NetInfos()
{
    std::ifstream net_file;

    net_file.open("/proc/net/route");

    std::string line;
    for (int i = 0; i < 2; i++)
        std::getline(net_file, line);
    _net = line.substr(0, line.find("\t"));
    net_file.close();
}

NetInfos::~NetInfos()
{
}

const std::string &NetInfos::getNet() const {return _net;}
