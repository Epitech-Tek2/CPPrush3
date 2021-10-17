/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** TitleSection
*/

#include "TitleSection.hpp"

TitleSection::TitleSection(std::string const& title, sf::Color color,
    sf::Vector2f position) noexcept
{
    _title = new Text{title, color, {100, 100}, 14};
    _title->setPosition(position);
}

void TitleSection::DrawTitle(WindowManager& manager) const noexcept
{
    manager._window.draw(_title->getText());
}