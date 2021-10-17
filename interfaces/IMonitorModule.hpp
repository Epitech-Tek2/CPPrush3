/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

class IMonitorModule {
    public:
        virtual ~IMonitorModule() = default;

        virtual void setMemUsed(void) = 0;
        virtual void setMemFree(void) = 0;
        virtual void setMemMem(void) = 0;
        virtual void setTime(void) = 0;
        virtual void setActivity(void) = 0;
};

#endif /* !IMONITORMODULE_HPP_ */
