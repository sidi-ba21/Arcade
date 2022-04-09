/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#include "Core.hpp"
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
        if (entry.path().string().compare("./lib/.gitkeep") != 0) {
            _all_lib.Dynamic_loader(entry.path());
            auto path = entry.path().string();
            if (_all_lib.getInstance()->getName().compare("IGraphic") == 0)
                _lib_graphics.emplace_back(entry.path().string());
            else if (_all_lib.getInstance()->getName().compare("IGames") == 0)
                _lib_games.emplace_back(entry.path().string());
        }
    }
    if (_lib_graphics.empty())
        throw GraphicsError("No graphical lib available.");
    if (_lib_games.empty())
        throw GraphicsError("No game lib available");
}

void Arcade::Core::init_menu()
{
    _menu.addObj(std::make_shared<Arcade::Text>("LIBRARIES :", Arcade::Color::WHITE, 300.f, 465.f));
    for (int i = 0; i < _lib_graphics.size(); i++) {
        if (i == it_graphics)
            _menu.addLib(std::make_shared<Arcade::Text>(_lib_graphics[i], Arcade::Color::RED, 250.f , 565.f + (float)(i * 50)));
        else
            _menu.addLib(std::make_shared<Arcade::Text>(_lib_graphics[i], Arcade::Color::WHITE, 250.f , 565.f + (float)(i * 50)));
    }
    _menu.addObj(std::make_shared<Arcade::Text>("GAMES :", Arcade::Color::CYAN, 900.f, 400.f));
    for (int i = 0; i < _lib_games.size(); i++) {
        if (it_games == i)
            _menu.addGame(std::make_shared<Arcade::Text>(_lib_games[i], Arcade::Color::RED, 850.f , 500.f + (float)(i * 50)));
        else
            _menu.addGame(std::make_shared<Arcade::Text>(_lib_games[i], Arcade::Color::CYAN, 850.f , 500.f + (float)(i * 50)));
    }
}

void Arcade::Core::menu_move(Arcade::Button event)
{
    if (event == Arcade::Button::UP || event == Arcade::Button::PREV_GAME)
        prev_game();
    else if (event == Arcade::Button::DOWN || event == Arcade::Button::NEXT_GAME)
        next_game();
    else if (event == Arcade::Button::PREV_LIB)
        prev_display();
    else if (event == Arcade::Button::NEXT_LIB)
        next_display();
    else if (event == Arcade::Button::ENTER)
        _is_menu = false;
}

Arcade::Core::Core(std::string &pathname) : _path(pathname)
{
    std::string str = std::string("./lib/arcade_nibbler.so");
    load_file();
    it_graphics = 0;
    it_games = 0;
    _is_menu = true;
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
//    std::cout << "Enter your name: " << std::flush;
//    std::getline(std::cin, _name);
    init_menu();
    core_loop();
}

void Arcade::Core::draw_menu()
{
    _display.getInstance()->clear();
    _display.getInstance()->drawBackground();
    auto temp = _menu.getMenu();
    for (auto &tmp : temp)
        _display.getInstance()->draw(tmp);
    _display.getInstance()->update();
}

void Arcade::Core::core_loop()
{
    _display.getInstance()->createWindow();
    while (1) {
        Arcade::Button input = _display.getInstance()->getEvent();
        if (input == Arcade::Button::ESCAPE) {
            _display.getInstance()->clear();
            break;
        }
        else if (_is_menu == true) {
            menu_move(input);
            draw_menu();
        }
        else if (input == Arcade::Button::PREV_GAME)
            prev_game();
        else if (input == Arcade::Button::NEXT_GAME)
            next_game();
        else if (input == Arcade::Button::PREV_LIB)
            prev_display();
        else if (input == Arcade::Button::NEXT_LIB)
            next_display();
        else {
            _display.getInstance()->clear();
            _display.getInstance()->drawBackground();
            auto buff = _game.getInstance()->play(input);
            for (auto &tmp : buff)
                _display.getInstance()->draw(tmp);
            _display.getInstance()->update();
        }
//        usleep(60000);
    }
}

void Arcade::Core::menu()
{

}

void Arcade::Core::next_game()
{
    if (_lib_games.size() <= 1)
        return;
    it_games = (it_games + 1) % _lib_games.size();
    _game.Dynamic_loader(_lib_games[it_games]);
    _menu.getGame()[it_games].get()->setColor(Arcade::Color::RED);
    _menu.getGame()[(it_games - 1) % _lib_games.size()].get()->setColor(Arcade::Color::CYAN);
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
    _menu.getGame()[it_games].get()->setColor(Arcade::Color::RED);
    _menu.getGame()[(it_games + 1) % _lib_games.size()].get()->setColor(Arcade::Color::CYAN);
}

void Arcade::Core::next_display()
{
    if (_lib_graphics.size() <= 1)
        return;
    it_graphics = (it_graphics + 1) % _lib_graphics.size();
    _display.Dynamic_loader(_lib_graphics[it_graphics]);
    _display.getInstance()->createWindow();
    _menu.getLib()[it_graphics]->setColor(Arcade::Color::RED);
    _menu.getLib()[(it_graphics - 1) % _lib_graphics.size()].get()->setColor(Arcade::Color::WHITE);
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
    _menu.getLib()[it_graphics]->setColor(Arcade::Color::RED);
    _menu.getLib()[(it_graphics + 1) % _lib_graphics.size()].get()->setColor(Arcade::Color::WHITE);
}

Arcade::Core::~Core()
{

}