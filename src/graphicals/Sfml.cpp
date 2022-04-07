/*
** EPITECH PROJECT, 2022
** Sfml
** File description:
** Sfml
*/

#include "Sfml.hpp"

static const int coef_w_obj = 13;
static const int coef_h_obj = 16;

Arcade::Sfml::Sfml()
{
    _window.create(sf::VideoMode(1920, 1080), "Arcade {Sfml}");
    _window.setFramerateLimit(60);
    _window.setKeyRepeatEnabled(true);
    if (!_font.loadFromFile("assets/font.ttf"))
        throw GraphicsError("Failed to load font");
}

Arcade::Sfml::~Sfml()
{
    _window.close();
}

void Arcade::Sfml::drawObject(Arcade::Object *obj)
{
    ///
}

void Arcade::Sfml::drawText(Arcade::Text *text)
{
    ///
}

void Arcade::Sfml::clear()
{
    _window.clear(sf::Color::Black);
}

void Arcade::Sfml::update()
{
    _window.display();
}

Arcade::Button Arcade::Sfml::getEvent()
{
    sf::Event event;
    sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Resized) {
            _window.setView(sf::View(visibleArea));
            return (Arcade::Button::NOTHING);
        }
        if (event.type == sf::Event::Closed)
            return (ESCAPE);
        if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::Up)
            return (Arcade::Button::UP);
        if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Left)
            return (Arcade::Button::LEFT);
        if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
            return (Arcade::Button::RIGHT);
        if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
            return (Arcade::Button::DOWN);
    }
    return (Arcade::Button::NOTHING);
}