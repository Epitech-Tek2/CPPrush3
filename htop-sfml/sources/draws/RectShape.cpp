/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** Shape
*/

#include "RectShape.hpp"
#include "WindowManager.hpp"
#include "Itop.hpp"

#define TITLE_SECTION(n) {_rectangleShape.getPosition().x + 20, _rectangleShape.getPosition().y - n }

RectShape::RectShape(sf::Vector2f position, sf::Vector2f size, sf::Color color, int thickness) noexcept
{
    _rectangleShape.setSize(size);
    _rectangleShape.setFillColor(color);
    _rectangleShape.setOutlineColor(EDGE_COLOR);
    _rectangleShape.setOutlineThickness(thickness);
    _rectangleShape.setPosition(position);
}

// Getter
sf::RectangleShape& RectShape::getRectShape() noexcept
{
    return (_rectangleShape);
}

sf::Text RectShape::getData() const noexcept
{
    return (_data->getText());
}

sf::Text RectShape::getTitle() const noexcept
{
    return (_title->getText());
}

// Setter
void RectShape::setStyle(sf::Color color, int thickness, sf::Color edgeColor,
    sf::Vector2f size, sf::Vector2f position) noexcept
{
    _rectangleShape.setFillColor(color);
    _rectangleShape.setOutlineThickness(thickness);
    _rectangleShape.setOutlineColor(edgeColor);
    _rectangleShape.setSize(size);
    _rectangleShape.setPosition(position);
}

void RectShape::setTitleColumn(std::string const& title) noexcept
{
    _title = new Text(title, RED_TXT, TITLE_SECTION(-10), 16);
}

void RectShape::setDataColumn(std::string const& data) noexcept
{
    _data = new Text(data, BLUE_TXT, TITLE_SECTION(-30), 16, false);
}

void RectShape::FullRect(int nbr)
{
    WindowManager manager;

    _rectRed = new RectShape({30, 500}, {315 + (float)nbr, 90}, RED_COLOR, 0);
    _rectGreen = new RectShape({30, 500}, {(float)percent(90), 90}, GREEN_COLOR, 0);
}

void RectShape::drawFullRect(sf::RenderWindow &window)
{
    window.draw(_rectGreen->getRectShape());
    window.draw(_rectRed->getRectShape());
}