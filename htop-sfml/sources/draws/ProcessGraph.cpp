/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** ProcessGraph
*/

#include "ProcessGraph.hpp"

ProcessGraph::ProcessGraph() noexcept
{
    WindowManager manager;

    _graph.setSize({(float)percent(90), 20});
    _graph.setFillColor(GREEN_COLOR);
    _graph.setPosition(30, 650);
    _maxGraph.setSize({(float)percent(90) - (float)percent(80), 20});
    _maxGraph.setFillColor(RED_COLOR);
    _maxGraph.setPosition(30, 650);
}

void ProcessGraph::DrawGraph(sf::RenderWindow& window) const noexcept
{
    window.draw(_graph);
    window.draw(_maxGraph);
}