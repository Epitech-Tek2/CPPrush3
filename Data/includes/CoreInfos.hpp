/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** CoreInfos
*/

#ifndef COREINFOS_HPP_
#define COREINFOS_HPP_

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <atomic>
#include <chrono>
#include <thread>


extern std::atomic<float>activity;
extern std::atomic<long unsigned int>mem_used;
extern std::atomic<long unsigned int>mem_free;
extern std::atomic<long unsigned int>mem_total;

void updateCore(std::atomic<bool> &is_running);
class CoreInfos {
    public:
        CoreInfos();
        ~CoreInfos();

        const std::string &getModel() const;
        const std::string &getFrequency() const;
        const int &getNbCore() const;
    protected:
    private:
        std::string _model;
        std::string _frequency;
        int nb_core;

};

#endif /* !COREINFOS_HPP_ */
