/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** WindowManager
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Itop.hpp"

class WindowManager : public Itop
{
    public:
        WindowManager(unsigned int width = 1920 / 3, unsigned int height = 740) noexcept;
        WindowManager(WindowManager const& windowManager) = delete;
        virtual ~WindowManager() = default;

        // Getter
        sf::RenderWindow& getWindow() noexcept;
        sf::Event& getEvent() noexcept;

        void manageEvent() noexcept;

        void operator=(WindowManager const& target) = delete;

        sf::RenderWindow _window;
        sf::Event _event;
};