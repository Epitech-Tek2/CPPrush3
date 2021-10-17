/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** Shortcuts
*/

#include "Text.hpp"
#include "Shortcuts.hpp"
#include "../macro.hpp"
#include "WindowManager.hpp"

Shortcuts::Shortcuts() noexcept
{
    WindowManager manager;

    _shortcutD = new Text{"C-d", BLUE_TXT, {20, (float)percentY(96)}, 14};
    _shortcutDDesc = new Text{": Exit", ORANGE_COLOR, {50, (float)percentY(96)}, 14};
    _shortcutH = new Text{"C-h", BLUE_TXT, {130, (float)percentY(96)}, 14};
    _shortcutHDesc = new Text{": Help", ORANGE_COLOR, {160, (float)percentY(96)}, 14};
    _shortcutF = new Text{"C-f", BLUE_TXT, {290, (float)percentY(96)}, 14};
    _shortcutFDesc = new Text{": Fullscreen", ORANGE_COLOR, {320, (float)percentY(96)}, 14};
    _shortcutFStatus = new Text{"  (OFF)", RED_COLOR, {410, (float)percentY(96)}, 14};
}

void Shortcuts::drawShortcuts(WindowManager& manager) const noexcept
{
    manager._window.draw(_shortcutD->getText());
    manager._window.draw(_shortcutDDesc->getText());
    manager._window.draw(_shortcutH->getText());
    manager._window.draw(_shortcutHDesc->getText());
    manager._window.draw(_shortcutF->getText());
    manager._window.draw(_shortcutFDesc->getText());
    manager._window.draw(_shortcutFStatus->getText());
}