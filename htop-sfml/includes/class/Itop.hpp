/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** Itop
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../macro.hpp"
#include "../../Data/includes/SystemInfos.hpp"
#include "../../Data/includes/Date.hpp"
#include "../../Data/includes/NetInfos.hpp"
#include "../../Data/includes/CoreInfos.hpp"
#include "../../Data/includes/UserInfos.hpp"

class Itop
{
    public:
        Itop() = default;
        Itop(Itop const& htop) = delete;
        virtual ~Itop() = default;

        void drawContent() const noexcept;

        static int run() noexcept;

        void operator=(Itop const& target) = delete;
};