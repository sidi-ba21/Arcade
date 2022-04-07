/*
** EPITECH PROJECT, 2022
** Sfml
** File description:
** Sfml
*/


#include "IGraphic.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../objects/Sound.hpp"
#include "../objects/Object.hpp"
#include "../objects/Text.hpp"

#ifndef SFML_HPP_
#define SFML_HPP_

namespace Arcade {

    std::map<Arcade::Color, sf::Color> sfmlColor {
        {Arcade::Color::BLACK, sf::Color::Black},
        {Arcade::Color::RED, sf::Color::Red},
        {Arcade::Color::GREEN, sf::Color::Green},
        {Arcade::Color::YELLOW, sf::Color::Yellow},
        {Arcade::Color::BLUE, sf::Color::Blue},
        {Arcade::Color::MAGENTA, sf::Color::Magenta},
        {Arcade::Color::CYAN, sf::Color::Cyan},
        {Arcade::Color::WHITE, sf::Color::White}
    };

    class Sfml final : public AGraphic {
        public:
            Sfml();
            ~Sfml();
            void drawObject(Arcade::Object *) override;
            void drawText(Arcade::Text *) override;
            void clear();
            void update();
            Arcade::Button getEvent() override;
        protected:
        private:
            sf::RenderWindow _window{};
            sf::Font _font{};
            sf::Texture _texture{};
            sf::SoundBuffer _sound{};
            sf::Event _event{};
    };

    extern "C" Sfml *entryPoint() {
        return new Sfml;
    };
}

#endif /* !SFML_HPP_ */
