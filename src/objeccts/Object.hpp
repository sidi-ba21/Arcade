/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "IObject.hpp"

namespace Arcade {

class Object : public IObject {
    public:
        Object(std::string path, unsigned char symbol, Arcade::Color color,
        float x, float y);
        ~Object() override = default;

        std::string getPath() const;
        unsigned char getSymbol() const;
        Arcade::Color getColor() const;
        std::pair<float, float> getPos() const;

        std::string setPath() const;
        unsigned char setSymbol() const;
        Arcade::Color setColor() const;
        std::pair<float, float> setPos() const;
    protected:
    private:
    std::pair<float, float> _objPos;
    std::string _path;
    Arcade::Color _color;
    unsigned char _symbol;
};

}

#endif /* !OBJECT_HPP_ */
