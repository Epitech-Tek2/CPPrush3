/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

class IMonitorDisplay {
    public:
        virtual ~IMonitorDisplay() = default;

        virtual int run(void) = 0;
};

#endif /* !IMONITORDISPLAY_HPP_ */
