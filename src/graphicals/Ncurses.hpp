/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "IGraphic.hpp"
#include <ncurses.h>
#include "../objects/Sound.hpp"
#include "../objects/Object.hpp"
#include "../objects/Text.hpp"

namespace Arcade {

    std::map<int, Arcade::Button> Key_list = {
		{27, Button::ESCAPE},
		{10, Button::ENTER},
		{'r', Button::RESTART},
		{'z', Button::UP},
		{'q', Button::LEFT},
		{'s', Button::DOWN},
		{'d', Button::RIGHT},
		{KEY_F(2), Button::PREV_GAME},
		{KEY_F(3), Button::NEXT_GAME},
		{KEY_F(4), Button::PREV_LIB},
		{KEY_F(5), Button::NEXT_LIB},
		{0404, Button::LEFT},
		{0405, Button::RIGHT},
		{0403, Button::UP},
		{0402, Button::DOWN}
    };

    class Ncurses final : public AGraphic {
        public:
            Ncurses();
            ~Ncurses();
            void drawObject(Arcade::Object *) override;
            void drawText(Arcade::Text *) override;
            void clear();
            void update();
            Arcade::Button getEvent() override;
        protected:
        private:
    };
    
    extern "C" Ncurses *entryPoint() {
        return new Ncurses;
    };

}

#endif /* !NCURSES_HPP_ */
