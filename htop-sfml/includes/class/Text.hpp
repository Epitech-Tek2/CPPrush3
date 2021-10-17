/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** Text
*/

#pragma once

#include <SFML/Graphics.hpp>

class Text {
    public:
        Text(){};
        Text(std::string str, sf::Color color, sf::Vector2f position, int size, bool bold = true);
        virtual ~Text() = default;
        sf::Text& getText() noexcept;
        void drawText(sf::RenderWindow &window);
        void initText();

        void setPosition(sf::Vector2f position) noexcept;

    protected:
        sf::Text _text;
        sf::Font _font;
        Text *tabText[3];
};