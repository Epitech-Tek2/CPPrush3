/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** RamInfos
*/

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <atomic>
#include <chrono>
#include <thread>

std::atomic<long unsigned int>mem_used;
std::atomic<long unsigned int>mem_free;
std::atomic<long unsigned int>mem_total;


void updateRam(std::atomic<bool> &is_running)
{
    const auto wait_duration = std::chrono::milliseconds(1000);


    while (is_running) {
        std::ifstream ram_file;
        std::string line;

        ram_file.open("/proc/meminfo");

        std::getline(ram_file, line);

        line.erase(0, 11);
        mem_total.store(std::atol(line.c_str()));

        std::getline(ram_file, line);
        line.erase(0, 10);
        mem_free.store(std::atol(line.c_str()));


        ram_file.close();

        mem_used.store(mem_total.load() - mem_free.load());
        std::this_thread::sleep_for(wait_duration);
    }
}
