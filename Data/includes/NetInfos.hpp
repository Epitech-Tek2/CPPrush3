/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** NetInfos
*/

#ifndef NETINFOS_HPP_
#define NETINFOS_HPP_

#include <string>
#include <fstream>
#include <iostream>

class NetInfos {
    public:
        NetInfos();
        ~NetInfos();

    const std::string &getNet() const;
    protected:
    private:
    std::string _net;
};

#endif /* !NETINFOS_HPP_ */
