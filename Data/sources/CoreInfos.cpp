/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** CoreInfos
*/

#include "CoreInfos.hpp"

std::atomic<float>activity;


CoreInfos::CoreInfos()
{
    std::ifstream in;
    std::string unparsed_line;

    in.open("/proc/cpuinfo");

    if (in.is_open() == false)
        throw ("Wait, where are the files needed?");


    for (int i = 0; i < 13; i++) {
        std::getline(in, unparsed_line);
        if (unparsed_line.compare(0, 10, "model name") == 0)
            _model = unparsed_line.substr(13);

        if (unparsed_line.compare(0, 7, "cpu MHz") == 0)
            _frequency = unparsed_line.substr(11);

        if (unparsed_line.compare(0, 9, "cpu cores") == 0)
            nb_core = std::atoi(unparsed_line.substr(12).c_str());
    }
}

CoreInfos::~CoreInfos()
{
}

const std::string &CoreInfos::getModel() const {return _model;}
const std::string &CoreInfos::getFrequency() const {return _frequency;}
const int &CoreInfos::getNbCore() const {return nb_core;}

void updateCore(std::atomic<bool> &is_running)
{
    const auto wait_duration = std::chrono::milliseconds(1000);

    while (is_running) {
        std::ifstream cpu_file;
        cpu_file.open("/proc/stat");
        std::string line;
        std::getline(cpu_file, line);
        line.erase(0, 5);
        float values[5];
        float values2[5];

        float nb = std::atof(line.substr(0, line.find(' ')).c_str());
        line.erase(0, line.find(' ') + 1);
        values[0] = nb;

        nb = std::atof(line.substr(0, line.find(' ')).c_str());
        line.erase(0, line.find(' ') + 1);
        values[1] = nb;

        nb = std::atof(line.substr(0, line.find(' ')).c_str());
        line.erase(0, line.find(' ') + 1);
        values[2] = nb;

        nb = std::atof(line.substr(0, line.find(' ')).c_str());
        line.erase(0, line.find(' ') + 1);
        values[3] = nb;

        nb = std::atof(line.substr(0, line.find(' ')).c_str());
        line.erase(0, line.find(' ') + 1);
        values[4] = nb;

        cpu_file.close();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        cpu_file.open("/proc/stat");
        std::getline(cpu_file, line);
        line.erase(0, 5);

        nb = std::atof(line.substr(0, line.find(' ')).c_str());
        line.erase(0, line.find(' ') + 1);
        values2[0] = nb;

        nb = std::atof(line.substr(0, line.find(' ')).c_str());
        line.erase(0, line.find(' ') + 1);
        values2[1] = nb;

        nb = std::atof(line.substr(0, line.find(' ')).c_str());
        line.erase(0, line.find(' ') + 1);
        values2[2] = nb;

        nb = std::atof(line.substr(0, line.find(' ')).c_str());
        line.erase(0, line.find(' ') + 1);
        values2[3] = nb;

        nb = std::atof(line.substr(0, line.find(' ')).c_str());
        line.erase(0, line.find(' ') + 1);
        values2[4] = nb;

        cpu_file.close();

        float active_time = (values2[0] + values2[1] + values2[2]) - (values[0] + values[1] + values[2]);
        float idle_time = (values2[3] + values2[4]) - (values[3] + values[4]);
        float total_time = active_time + idle_time;

        activity.store((100.f * active_time) / total_time);

        std::this_thread::sleep_for(wait_duration);
    }
}