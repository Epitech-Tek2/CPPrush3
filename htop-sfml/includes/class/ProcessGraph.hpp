/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** ProcessGraph
*/

#pragma once

#include "Itop.hpp"
#include "WindowManager.hpp"

class ProcessGraph {
    public:
        ProcessGraph() noexcept;
        ~ProcessGraph() = default;

        void DrawGraph(sf::RenderWindow& window) const noexcept;

    protected:
    private:
        sf::RectangleShape _graph;
        sf::RectangleShape _maxGraph;
};