/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** TableRectShape
*/

#include "TableRectShape.hpp"
#include "Itop.hpp"

static float getLength(unsigned int width[], int n, unsigned int max)
{
    int i = 0;

    for (int x = 0; x <= n; x++) i += perc(width[x], max);
    return (i);
}

TableRectShape::TableRectShape(unsigned int height, unsigned int width,
    unsigned int columnWidth[], unsigned int column, sf::Vector2f position) noexcept :
    _columnShape{new RectShape[column]}, _column{column}
{
    static unsigned int idx = 0;
    static int idx_string = 0;
    std::string string[14] {"Hostname","Username","OS","Kernel version","Used Memory","Free Memory","Total Memory","Net","Date","Time","Model","Frequency", "Cores"};
    std::string value[14] {"debian", "clement", "Linux", "4.19.0-13-amd64", "72.86.856 KB", "7.19.524 KB", "79.22.960 KB", "enx00e04c7bf5eb", "Sun Jan 24", __TIME__, "Intel(R) Core(TM) i7-8550U CPU @ 1.80GHz", "1057.230 Hz", "4"};

    for (unsigned int i = 0; i != _column; i++, idx_string++) {
        _columnShape[i].setStyle(sf::Color::Transparent, 1, EDGE_COLOR, {(float)perc(columnWidth[i], width),
        (float)height}, {(i == 0) ? position.x : (getLength(columnWidth, i - 1, width) + position.x), position.y});
        _columnShape[i].setTitleColumn((idx_string <= 13) ? string[idx_string] : " ");
        _columnShape[i].setDataColumn((idx_string <= 13) ? value[idx_string] : " ");
    }
    idx++;
}

void TableRectShape::DrawShapes(sf::RenderWindow& window) const noexcept
{
    for (unsigned int i = 0; i != _column; i++) {
        window.draw(_columnShape[i].getRectShape());
        window.draw(_columnShape[i].getTitle());
        window.draw(_columnShape[i].getData());
    }
}

void TableRectShape::DrawTable(sf::RenderWindow& window) noexcept
{
    for (int i = 0; i != TABLE_NBR; i++) _tableShapes[i]->DrawShapes(window);
}

void TableRectShape::InitTableShapeRect(WindowManager& manager) noexcept
{
    unsigned int columnWidth[4] = {25, 25, 25, 25};
    unsigned int columnWidth3[3] = {40, 30, 30};
    unsigned int columnWidthTechnical[3] = {60, 25, 15};
    unsigned int ColumnBuySellGauge[1] = {100};

    _tableShapes[0] = new TableRectShape{80, percent(97), columnWidth, 4, {10, 10}};
    _tableShapes[1] = new TableRectShape{80, percent(97), columnWidth3, 3, {10, 110}};
    _tableShapes[2] = new TableRectShape{80, percent(97), columnWidth3, 3, {10, 210}};
    _tableShapes[3] = new TableRectShape{80, percent(97), columnWidthTechnical, 3, {10, 310}};
    _tableShapes[4] = new TableRectShape{160, percent(97), ColumnBuySellGauge, 1, {10, 450}};
}

void TableRectShape::setTitleSection(std::string const& title) noexcept
{
    _title = new TitleSection{title, RED_COLOR, _columnShape->getRectShape().getPosition()};
}