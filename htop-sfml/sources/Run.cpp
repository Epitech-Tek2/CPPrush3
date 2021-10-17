/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** run
*/

#include "Itop.hpp"
#include "WindowManager.hpp"
#include "RectShape.hpp"
#include "Text.hpp"
#include "TableRectShape.hpp"
#include "Shortcuts.hpp"
#include "TitleSection.hpp"
#include "ProcessGraph.hpp"

int Itop::run() noexcept
{
    WindowManager manager;
    TableRectShape table;
    RectShape graph{{(float)(percent(35) + 20), 10}, {(float)percent(65) - 30, 600}};
    RectShape fullrect;
    fullrect.FullRect(30);
    ProcessGraph processGraph;
    Shortcuts shortcuts;
    sf::RectangleShape shape;
    shape.setPosition(30, 440);
    shape.setSize({140, 20});
    shape.setFillColor(BACKGROUND_COLOR);
    Text processor{"Processor Gauge", RED_TXT, {35, 625}, 16};
    Text memoryUse{"60%", {8, 201, 132}, {190, 535}, 16};
    Text memoryFree{"40%", {8, 201, 132}, {480, 535}, 16};

    table.InitTableShapeRect(manager);
    while (manager._window.isOpen()) {
        manager.manageEvent();
        manager._window.clear(BACKGROUND_COLOR);
        table.DrawTable(manager._window);
        processGraph.DrawGraph(manager._window);
        shortcuts.drawShortcuts(manager);
        fullrect.drawFullRect(manager._window);
        manager._window.draw(processor.getText());
        manager._window.draw(memoryUse.getText());
        manager._window.draw(memoryFree.getText());
        manager._window.draw(shape);
        manager._window.draw(Text("Memory Gauge", RED_TXT, {40, 440}, 16).getText());
        manager._window.display();
    }
    return (0);
}