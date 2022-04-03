/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include <stdio.h>
#include "src/graphicals/IGraphics.hpp"

extern "C" Arcade::IGraphics *Arcade::IGraphics::entryPoint()
{
    return new Arcade::IGraphics;
}

