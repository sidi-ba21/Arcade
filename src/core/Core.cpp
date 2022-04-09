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
#include <unistd.h>

void Arcade::Core::load_file()
{
    namespace fs = std::experimental::filesystem;

    for (const auto & entry : fs::directory_iterator("./lib")) {
        _all_lib.Dynamic_loader(entry.path());
        auto path = entry.path().string();
        if (_all_lib.getInstance()->getName().compare("IGraphic") == 0)
            _lib_graphics.emplace_back(entry.path().string());
        else if (_all_lib.getInstance()->getName().compare("IGames") == 0)
            _lib_games.emplace_back(entry.path().string());
    }
    if (_lib_graphics.empty())
        throw GraphicsError("No graphical lib available.");
    if (_lib_games.empty())
        throw GraphicsError("No game lib available");
}

Arcade::Core::Core(std::string &pathname) : _path(pathname)
{
    std::string str = std::string("./lib/arcade_nibbler.so");
    load_file();
    it_graphics = 0;
    it_games = 0;
    std::cout << _path << std::endl;
    std::cout << "Graphicals:" << std::endl;
    for (auto &tmp : _lib_graphics)
        std::cout << tmp.substr(tmp.find_last_of("/\\") + 1) << std::endl;
    std::cout << "Games:" << std::endl;
    for (auto &tmp : _lib_games)
        std::cout << tmp.substr(tmp.find_last_of("/\\") + 1) << std::endl;
    _display.Dynamic_loader(_path);
    _game.Dynamic_loader(str);
    for (auto &it : _lib_graphics) {
        if (it.compare(_path) != 0)
            it_graphics++;
    }
    std::cout << "Enter your name: " << std::flush;
    std::getline(std::cin, _name);
    core_loop();
}

void Arcade::Core::core_loop()
{
    _display.getInstance()->createWindow();
    Arcade::Button input = _display.getInstance()->getEvent();

    while (input != Arcade::Button::ESCAPE) {
        switch_lib(input);
        _display.getInstance()->clear();
        auto buff = _game.getInstance()->play(input);
        for (auto &tmp : buff)
            _display.getInstance()->draw(tmp);
        _display.getInstance()->update();
        usleep(60000);
        input = _display.getInstance()->getEvent();
    }
    _display.getInstance()->clear();
}

void Arcade::Core::menu()
{

}

void Arcade::Core::switch_lib(Arcade::Button &input)
{
    if (input == Arcade::Button::PREV_GAME)
        prev_game();
    if (input == Arcade::Button::NEXT_GAME)
        next_game();
    if (input == Arcade::Button::PREV_LIB)
        prev_display();
    if (input == Arcade::Button::NEXT_LIB)
        next_display();
}

void Arcade::Core::next_game()
{
    if (_lib_games.size() <= 1)
        return;
    it_games = (it_games + 1) % _lib_games.size();
    _game.Dynamic_loader(_lib_games[it_games]);
}

void Arcade::Core::prev_game()
{
    if (_lib_games.size() <= 1)
        return;
    if (it_games == 0)
        it_games = _lib_games.size() - 1;
    else
        it_games = (it_games - 1) % _lib_games.size();
    _game.Dynamic_loader(_lib_games[it_games]);
}

void Arcade::Core::next_display()
{
    if (_lib_graphics.size() <= 1)
        return;
    it_graphics = (it_graphics + 1) % _lib_graphics.size();
    _display.Dynamic_loader(_lib_graphics[it_graphics]);
    _display.getInstance()->createWindow();
}

void Arcade::Core::prev_display()
{
    if (_lib_graphics.size() <= 1)
        return;
    if (it_graphics == 0)
        it_graphics = _lib_graphics.size() - 1;
    else
        it_graphics = (it_graphics - 1) % _lib_graphics.size();
    _display.Dynamic_loader(_lib_graphics[it_graphics]);
    _display.getInstance()->createWindow();
}

Arcade::Core::~Core()
{

}