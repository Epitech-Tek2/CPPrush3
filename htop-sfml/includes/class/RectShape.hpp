/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** RectShape
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Itop.hpp"
#include "WindowManager.hpp"
#include "Text.hpp"

class RectShape : public Itop
{
    public:
        RectShape(sf::Vector2f position = {10, 10}, sf::Vector2f size = {50, 50},
            sf::Color fillColor = sf::Color::Transparent, int thickness = 1) noexcept;
        RectShape(RectShape const& rectShape) noexcept;
        virtual ~RectShape() = default;

        // Getter
        sf::RectangleShape& getRectShape() noexcept;
        sf::Text getTitle() const noexcept;
        sf::Text getData() const noexcept;

        // Setter
        void setStyle(sf::Color color, int thickness, sf::Color edgeColor,
            sf::Vector2f size, sf::Vector2f position) noexcept;
        void setTitleColumn(std::string const& title) noexcept;
        void setDataColumn(std::string const& title) noexcept;

        void operator=(RectShape const& target) = delete;
        void FullRect(int nbr);
        void drawFullRect(sf::RenderWindow &window);

    private:
        sf::RectangleShape _rectangleShape;
        RectShape *_rectGreen;
        RectShape *_rectRed;

    protected:
        Text *_title;
        Text *_data;
};