/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "IObject.hpp"

namespace Arcade {

class Text : public IObject {
    public:
        Text(std::string text, Arcade::Color color, float x, float y):
            _text(text), _color(color), _textPos(std::make_pair(x, y)) {};
        ~Text() override = default;

        std::string getText() const {
            return _text;
        };
        Arcade::Color getColor() const {
            return _color;
        };
        std::pair<float, float> getPos() const {
            return _textPos;
        };

        void setText(std::string text) {
            _text = std::move(text);
        };
        void setColor(Arcade::Color color) {
            _color = color;
        };
        void setPos(float x, float y) {
            _textPos.first = x;
            _textPos.second = y;
        };

    protected:
    private:
    std::string _text;
    Arcade::Color _color;
    std::pair<float, float> _textPos;
};

}

#endif /* !TEXT_HPP_ */
