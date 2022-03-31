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

        std::string getPath() const {return this->_path;};
        unsigned char getSymbol() const {return this->_symbol;};
        Arcade::Color getColor() const {return this->_color;};
        std::pair<float, float> getPos() const {return this->_objPos;};

        std::string setPath(std::string newpath) {this->_path = newpath;};
        unsigned char setSymbol(unsigned char newsymbol) {this->_symbol = newsymbol;};
        Arcade::Color setColor(Arcade::Color newcol) {this->_color = newcol;};
        void setPos(std::pair<float, float> pos) {
            this->_objPos.first = pos.first;
            this->_objPos.second = pos.second;
        };
    protected:
    private:
    std::pair<float, float> _objPos;
    std::string _path;
    Arcade::Color _color;
    unsigned char _symbol;
};
}

#endif /* !OBJECT_HPP_ */
