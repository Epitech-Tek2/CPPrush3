/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** Text
*/

#include "Text.hpp"
#include "Itop.hpp"
#include "WindowManager.hpp"

Text::Text(std::string str, sf::Color color, sf::Vector2f position, int size, bool bold)
{
    _font.loadFromFile("./htop-sfml/assets/arial.ttf");
    _text.setFont(_font);
    _text.setString(str);
    _text.setCharacterSize(size);
    _text.setFillColor(color);
    _text.setStyle(bold ? sf::Text::Bold : sf::Text::Regular);
    _text.setPosition(position);
}

sf::Text& Text::getText() noexcept
{
    return (_text);
}

void Text::setPosition(sf::Vector2f position) noexcept
{
    _text.setPosition(position);
}

void Text::initText()
{
    WindowManager manager;
    tabText[0] = new Text("Data", RED_COLOR, {(float)percent(90), 10}, 15);
    /*tabText[0] = new Text("Headline", RED_COLOR, {12, 10}, 15);
    tabText[0] = new Text("Sentiment", RED_COLOR, {12, 10}, 15);

    tabText[0] = new Text("Technical Indicator", RED_COLOR, {12, 10}, 15);
    tabText[0] = new Text("Value", RED_COLOR, {12, 10}, 15);
    tabText[0] = new Text("Signal", RED_COLOR, {12, 10}, 15);

    tabText[0] = new Text("Buy/Sell Gauge", RED_COLOR, {12, 10}, 15);

    tabText[0] = new Text("Blockchain Network", RED_COLOR, {12, 10}, 15);
    tabText[0] = new Text("Value", RED_COLOR, {12, 10}, 15);

    tabText[0] = new Text("Portfolio Stats", RED_COLOR, {12, 10}, 15);
    tabText[0] = new Text("Value", RED_COLOR, {12, 10}, 15);

    tabText[0] = new Text("Date", RED_COLOR, {12, 10}, 15);
    tabText[0] = new Text("Amount", RED_COLOR, {12, 10}, 15);
    tabText[0] = new Text("Amount", RED_COLOR, {12, 10}, 15);*/

}

void Text::drawText(sf::RenderWindow &window)
{
    window.draw(tabText[0]->getText());
}