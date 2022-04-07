/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "IGraphic.hpp"
#include "../objects/Sound.hpp"
#include "../objects/Object.hpp"
#include "../objects/Text.hpp"

namespace Arcade {

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
    
    extern "C" Ncurses *entry_point() {
        return new Ncurses;
    };

}

#endif /* !NCURSES_HPP_ */
