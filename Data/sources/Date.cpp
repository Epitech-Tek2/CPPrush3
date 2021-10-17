/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Date
*/

#include "Date.hpp"

std::atomic<int>_hour;
std::atomic<int>_minute;
std::atomic<int>_seconds;

void updateTime(std::atomic<bool> &is_running)
{
    const auto wait_duration = std::chrono::milliseconds(1000);

    while (is_running) {
        auto _time = std::chrono::system_clock::now();
        std::time_t my_time = std::chrono::system_clock::to_time_t(_time);
        std::string temp = std::ctime(&my_time);
        temp.erase(0, 11);


        std::string hour = temp.substr(0, 2);
        temp.erase(0, 3);
        _hour.store(std::atoi(hour.c_str()));


        std::string minutes = temp.substr(0, 2);
        temp.erase(0, 3);
        _minute.store(std::atoi(minutes.c_str()));

        std::string seconds = temp.substr(0, 2);
        _seconds.store(std::atoi(seconds.c_str()));

        std::this_thread::sleep_for(wait_duration);
    }
}


Date::Date()
{
    auto time = std::chrono::system_clock::now();
    std::time_t my_time = std::chrono::system_clock::to_time_t(time);
    std::string temp = std::ctime(&my_time);

    _date = temp.substr(0, 10);
}

Date::~Date()
{
}


const std::string &Date::getTime() const {return _time;}
const std::string &Date::getDate() const {return _date;}
void Date::setTime(const int &hour, const int &minute, const int &second)
{
    os << std::setfill('0') << std::setw(2) << hour;
    os << ":" << std::setfill('0') << std::setw(2) << minute;
    os << ":" <<std::setfill('0') << std::setw(2) << second << "\n";
    _time = os.str();
    os.str("");
}
