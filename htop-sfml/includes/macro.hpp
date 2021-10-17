/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** macro
*/

#pragma once

// MACRO
#define percent(percentage) ((percentage * manager._window.getSize().x) / 100)
#define percentY(percentage) ((percentage * manager._window.getSize().y) / 100)
#define perc(percentage, max) ((percentage * max) / 100)
#define CTRLD_PRESSED (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
#define CTRLH_PRESSED (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::H))
#define DATA_TXT(i) {(!i) ? 0 : _data[i - 1]->getText().getPosition().x + 20, 10 }

// COLORS
#define BACKGROUND_COLOR {34, 58, 75}
#define EDGE_COLOR {45, 191, 159}
#define GREEN_COLOR {0, 144, 116}
#define RED_COLOR {202, 36, 48}
#define ORANGE_COLOR {255, 169, 91}
#define YELLOW_COLOR {237, 210, 98}
#define BLUE_TXT {47, 207, 251}
#define RED_TXT {255, 98, 93}

// DEFINE
#define TABLE_NBR 5