/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** WindowManager
*/

#include "WindowManager.hpp"

WindowManager::WindowManager(unsigned int width, unsigned int height) noexcept :
    _window{sf::VideoMode{width, height, 32}, "htop"} {}

sf::RenderWindow& WindowManager::getWindow() noexcept
{
    return (_window);
}

sf::Event& WindowManager::getEvent() noexcept
{
    return (_event);
}

void WindowManager::manageEvent() noexcept
{
    while (_window.pollEvent(_event)) {
        if (sf::Event::Closed == _event.type || CTRLD_PRESSED)
            _window.close();
    }
}