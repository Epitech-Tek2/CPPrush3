/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** UserInfos
*/

#ifndef USERINFOS_HPP_
#define USERINFOS_HPP_

#include <string>
#include <iostream>
#include <fstream>

class UserInfos{
    public:
        UserInfos();
        ~UserInfos();

        const std::string &getUserName() const;
        const std::string &getHostName() const;
    protected:
    private:
        std::string _username;
        std::string _hostname;
};

#endif /* !USERINFOS_HPP_ */
