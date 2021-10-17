/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** TitleSection
*/

#pragma once

#include "../macro.hpp"
#include "WindowManager.hpp"
#include "Text.hpp"

class TitleSection : public Text {
    public:
        TitleSection() noexcept;
        TitleSection(std::string const& title, sf::Color color = sf::Color(RED_COLOR),
            sf::Vector2f position = {100, 100}) noexcept;
        TitleSection(TitleSection const& other) = delete;
        virtual ~TitleSection() = default;

        void DrawTitle(WindowManager& manager) const noexcept;

        void operator=(TitleSection const& target) = delete;
    private:
        Text *_title;
};