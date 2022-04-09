/*
** EPITECH PROJECT, 2022
** Sfml
** File description:
** Sfml
*/

#include "Sfml.hpp"
#include "unistd.h"
#include <thread>
#include <iostream>

static const int coef_w_obj = 15;
static const int coef_h_obj = 20;

void Arcade::Sfml::createWindow()
{
    _window.create(sf::VideoMode(1920, 1080), "Arcade {SFML}");
    _window.setFramerateLimit(60);
    _window.setKeyRepeatEnabled(true);
    if (!_font.loadFromFile("assets/font.ttf"))
        throw GraphicsError("Failed to load a font");
}

Arcade::Sfml::Sfml()
{
}

Arcade::Sfml::~Sfml()
{
    if (_window.isOpen())
        _window.close();
}

void Arcade::Sfml::drawBackground(std::string path)
{
    if(!_texture.loadFromFile(path.c_str()))
        throw GraphicsError("Failed to load a texture");
    sf::Sprite sprite(_texture);
    sprite.setPosition(0, 0);
    _window.draw(sprite);
}

void Arcade::Sfml::drawObject(Arcade::Object *obj)
{
    if(!_texture.loadFromFile(obj->getPath().c_str()))
        throw GraphicsError("Failed to load a texture");
    sf::Sprite sprite(_texture);
    sprite.setPosition(600 + obj->getPos().first * coef_w_obj, 365 + obj->getPos().second * coef_h_obj);
    sprite.scale(0.5f, 0.5f);
    _window.draw(sprite);
}

void Arcade::Sfml::drawText(Arcade::Text *text)
{
    sf::Text txt;

    txt.setFont(_font);
    txt.setString(text->getText());
    txt.setCharacterSize(25);
    txt.setPosition(text->getPos().first, text->getPos().second);
    txt.setFillColor(sfmlColor[text->getColor()]);
    _window.draw(txt);
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

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Resized) {
            sf::FloatRect area(0, 0, event.size.width, event.size.height);
            _window.setView(sf::View(area));
            return (Arcade::Button::NOTHING);
        }
        if (event.type == sf::Event::Closed)
            return (Button::ESCAPE);
        if (event.type == sf::Event::KeyPressed) {
            if (Key_list.find(event.key.code) != Key_list.end())
                return Key_list[event.key.code];
        }
    }
    return (Arcade::Button::NOTHING);
}
/*
int main(int ac, char **av)
{
    std::string tmp;
    Arcade::Sfml test;
    Arcade::Snake snake;
    while (1) {
        auto input = test.getEvent();
        if (input == Arcade::Button::ESCAPE) {
            test.clear();
            break;
        }
        test.clear();
        auto buff = snake.play(input);
        for (auto &tmp : buff)
            test.draw(tmp);
        test.update();
        usleep(60000);
    }
    return (0);
}
*/