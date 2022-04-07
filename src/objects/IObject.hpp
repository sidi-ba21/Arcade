/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IObject
*/

#ifndef IOBJECT_HPP_
#define IOBJECT_HPP_

#include <string>
#include <utility>
#include <vector>

namespace Arcade {

class IObject {
    public:
        virtual ~IObject() = default;
};

enum Color {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

enum Button {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ENTER,
        ESCAPE,
        NOTHING
    };
}

#endif /* !IOBJECT_HPP_ */
