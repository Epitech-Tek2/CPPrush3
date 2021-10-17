/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Date
*/

#ifndef DATE_HPP_
#define DATE_HPP_

#include <sstream>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <chrono>
#include <atomic>
#include <string>
#include <fstream>
#include <thread>

extern std::atomic<int>_hour;
extern std::atomic<int>_minute;
extern std::atomic<int>_seconds;

void updateTime(std::atomic<bool> &is_running);

class Date {
    public:
        Date();
        ~Date();


        const std::string &getTime() const;
        const std::string &getDate() const;
        void setTime(const int &, const int &, const int &);
    protected:
    private:
        std::string _date;
        std::ostringstream os;
        std::string _time;
};

#endif /* !DATE_HPP_ */
