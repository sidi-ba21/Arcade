/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#include "Core.hpp"
#include "DLLoader.hpp"
#include <iostream>
#include <filesystem>
#include <experimental/filesystem>
#include <string>
#include "../objects/Object.hpp"
#include "../objects/IObject.hpp"
#include "../objects/Sound.hpp"
#include "../objects/Sprite.hpp"
#include "../objects/Text.hpp"

void Arcade::Core::load_file()
{
    namespace fs = std::experimental::filesystem;

    for (const auto & entry : fs::directory_iterator(fs::current_path().append("/lib"))) {
        _all_lib.Dynamic_loader(entry.path());
        if (_all_lib.getInstance()->getName().compare("graphical") == 0)
            _lib_graphics.emplace_back(entry.path());
        else if (_all_lib.getInstance()->getName().compare("game") == 0)
            _lib_games.emplace_back(entry.path());
    }
}

Arcade::Core::Core(std::string &pathname) : _path(pathname)
{
    std::string str = std::string("./lib/arcade_nibbler.so");
    load_file();
    std::cout << _path << std::endl;
    std::cout << "Graphicals:" << std::endl;
    for (auto &tmp : _lib_graphics)
        std::cout << tmp << std::endl;
    std::cout << "Games:" << std::endl;
    for (auto &tmp : _lib_games)
        std::cout << tmp << std::endl;
   // std::cout << _lib_graphics[2] << std::endl;
    _display.Dynamic_loader(_path);
   // std::cout << "success" << std::endl;
    _game.Dynamic_loader(str);
    core_loop();
}

void Arcade::Core::core_loop()
{
    std::string tmp;
    auto sdl = _display.getInstance();
    auto snake = _game.getInstance();
    while (1) {
        Arcade::Button input = sdl->getEvent();
        if (input == Arcade::Button::ESCAPE) {
            sdl->clear();
            break;
        }
        sdl->clear();
        auto buff = snake->play(input);
        for (auto &tmp : buff)
            sdl->draw(tmp);
        sdl->update();
    }
}

void Arcade::Core::menu()
{

}

void Arcade::Core::next_game()
{
}

void Arcade::Core::prev_game()
{
}

void Arcade::Core::next_display()
{
}

void Arcade::Core::prev_display()
{
}

Arcade::Core::~Core()
{

}