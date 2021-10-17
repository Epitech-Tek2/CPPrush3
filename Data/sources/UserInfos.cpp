/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** UserInfos
*/

#include <cstdlib>
#include "UserInfos.hpp"

UserInfos::UserInfos()
{
    _username = std::getenv("USER");
    std::ifstream host_file;
    host_file.open("/proc/sys/kernel/hostname");
    std::getline(host_file, _hostname);
}

UserInfos::~UserInfos()
{
}

const std::string &UserInfos::getUserName() const {return _username;}

const std::string &UserInfos::getHostName() const {return _hostname;}