/*
** EPITECH PROJECT, 2022
** Sfml
** File description:
** Sfml
*/


#include "IGraphic.hpp"
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

    std::map<sf::Keyboard::Key, Arcade::Button> Key_list = {
		{sf::Keyboard::Escape, Button::ESCAPE},
		{sf::Keyboard::Enter, Button::ENTER},
		{sf::Keyboard::R, Button::RESTART},
		{sf::Keyboard::Z, Button::UP},
		{sf::Keyboard::Q, Button::LEFT},
		{sf::Keyboard::S, Button::DOWN},
		{sf::Keyboard::D, Button::RIGHT},
		{sf::Keyboard::F2, Button::PREV_GAME},
		{sf::Keyboard::F3, Button::NEXT_GAME},
		{sf::Keyboard::F4, Button::PREV_LIB},
		{sf::Keyboard::F5, Button::NEXT_LIB},
		{sf::Keyboard::Left, Button::LEFT},
		{sf::Keyboard::Right, Button::RIGHT},
		{sf::Keyboard::Up, Button::UP},
		{sf::Keyboard::Down, Button::DOWN}
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
