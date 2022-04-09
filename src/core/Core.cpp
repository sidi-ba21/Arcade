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
        if (_all_lib.getInstance()->getName().compare("IGraphic") == 0)
            _lib_graphics.emplace_back(entry.path().string());
        if (_all_lib.getInstance()->getName().compare("IGames") == 0)
            _lib_games.emplace_back(entry.path().string());
    }
    if (_lib_graphics.empty())
        throw GraphicsError("No graphical lib available.");
    if (_lib_games.empty())
        throw GraphicsError("No game lib available");
}

void Arcade::Core::display_lib()
{
    std::cout << "Graphicals:" << std::endl;
    for (auto &tmp : _lib_graphics)
        std::cout << tmp.substr(tmp.find_last_of("/\\") + 1) << std::endl;
    std::cout << "Games:" << std::endl;
    for (auto &tmp : _lib_games)
        std::cout << tmp.substr(tmp.find_last_of("/\\") + 1) << std::endl;
    for (auto &it : _lib_graphics) {
        if (it.substr(it.find_last_of("/\\") + 1).compare(_path.substr(_path.find_last_of("/\\") + 1)) == 0)
            break;
        it_graphics++;
    }
    if (it_graphics == _lib_graphics.size())
        throw GraphicsError("2nd argument is not a graphic library");
}

Arcade::Core::Core(std::string &pathname) : _path(pathname)
{
    load_file();
    display_lib();
    _display.Dynamic_loader(_lib_graphics[it_graphics]);
    _game.Dynamic_loader(_lib_games[it_games]);
    std::cout << "Enter your name: " << std::flush;
    std::getline(std::cin, _name);
    core_loop();
}

void Arcade::Core::core_loop()
{
    _display.getInstance()->createWindow();
    Arcade::Button input = _display.getInstance()->getEvent();
    menu();
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