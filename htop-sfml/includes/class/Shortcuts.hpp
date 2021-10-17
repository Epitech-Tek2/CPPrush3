/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** Shortcuts
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "WindowManager.hpp"
#include "Text.hpp"
#include "../macro.hpp"

class Shortcuts : public Text
{
    public:
        Shortcuts() noexcept;
        Shortcuts(std::string const& shortcutKey, std::string const& shortcutDesc,
            sf::Color colorKey = sf::Color(BLUE_TXT), sf::Color colorDesc = sf::Color(ORANGE_COLOR)) noexcept;
        Shortcuts(Shortcuts const& other) = delete;
        virtual ~Shortcuts() = default;

        void drawShortcuts(WindowManager& manager) const noexcept;

        Shortcuts& operator=(Shortcuts const& target) = delete;

    private:
        Text *_shortcutD;
        Text *_shortcutDDesc;
        Text *_shortcutH;
        Text *_shortcutHDesc;
        Text *_shortcutF;
        Text *_shortcutFDesc;
        Text *_shortcutFStatus;
};