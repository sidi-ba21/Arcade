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

void Arcade::Core::load_file()
{
    namespace fs = std::experimental::filesystem;
    for (const auto & entry : fs::directory_iterator(fs::current_path().append("/lib"))) {
        //std::cout << entry.path() << std::endl;
        _lib.push_back(entry.path());
    }
}

Arcade::Core::Core(std::string &pathname) : _path(pathname)
{
    //std::string str = std::string("./arcade_sdl2.so");
    load_file();
    std::cout << _path << std::endl;
    std::cout << _lib[2] << std::endl;
    _display.Dynamic_loader(_path);
    _game.Dynamic_loader(_lib[2]);
    core_loop();
}

void Arcade::Core::core_loop()
{
    std::string tmp;
    auto sdl = _display.getInstance();
    auto snake = _game.getInstance();
    while (1) {
        std::cout << "pass1" << std::endl;
        Arcade::Button input = sdl->getEvent();
        std::cout << "pass2" << std::endl;
        if (input == Arcade::Button::ESCAPE) {
            sdl->clear();
            break;
        }
        std::cout << "pass3" << std::endl;
        sdl->clear();
        auto buff = snake->play(input);
        std::cout << "pass4" << std::endl;
        for (auto &tmp : buff)
            sdl->draw(tmp);
        std::cout << "pass5" << std::endl;
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