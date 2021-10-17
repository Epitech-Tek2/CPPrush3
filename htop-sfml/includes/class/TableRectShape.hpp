/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** TableRectShape
*/

#pragma once

#include "RectShape.hpp"
#include "TitleSection.hpp"

class TableRectShape : public RectShape
{
    public:
        TableRectShape(unsigned int height, unsigned int width, unsigned int columnWidth[],
            unsigned int column = 1, sf::Vector2f position = {10, 10}) noexcept;
        TableRectShape(TableRectShape const& tableRectShape) = delete;
        TableRectShape() = default;
        virtual ~TableRectShape() = default;

        void DrawShapes(sf::RenderWindow& window) const noexcept;
        void DrawTable(sf::RenderWindow& window) noexcept;

        void InitTableShapeRect(WindowManager& manager) noexcept;

        void setTitleSection(std::string const& title) noexcept;

        void operator=(TableRectShape const& target) = delete;

    protected:
        RectShape *_columnShape;
        unsigned int _column;
        TableRectShape *_tableShapes[TABLE_NBR];
        Text *_title;
        Text *_titleSection;
    private:
};