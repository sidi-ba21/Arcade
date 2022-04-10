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


void Arcade::Core::load_file()
{
    namespace fs = std::experimental::filesystem;

    for (const auto & entry : fs::directory_iterator("./lib")) {
        if (entry.path().string().compare("./lib/.gitkeep") != 0) {
            _all_lib.Dynamic_loader(entry.path());
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
    for (int i = 0; i < _lib_graphics.size(); i++) {
        if (i == it_graphics)
            _menu.addLib(std::make_shared<Arcade::Text>(_lib_graphics[i], Arcade::Color::RED, 350.f , 515.f + (float)(i * 50)));
        else
            _menu.addLib(std::make_shared<Arcade::Text>(_lib_graphics[i], Arcade::Color::WHITE, 350.f , 515.f + (float)(i * 50)));
    }
    _menu.addLib(std::make_shared<Arcade::Text>("LIBRARIES :", Arcade::Color::WHITE, 400.f, 400.f));
    for (int i = 0; i < _lib_games.size(); i++) {
        if (it_games == i)
            _menu.addGame(std::make_shared<Arcade::Text>(_lib_games[i], Arcade::Color::RED, 850.f , 515.f + (float)(i * 50)));
        else
            _menu.addGame(std::make_shared<Arcade::Text>(_lib_games[i], Arcade::Color::CYAN, 850.f , 515.f + (float)(i * 50)));
    }
    _menu.addGame(std::make_shared<Arcade::Text>("GAMES :", Arcade::Color::CYAN, 900.f, 400.f));
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
    else if (event == Arcade::Button::ENTER) {
        _game.Dynamic_loader(_lib_games[it_games]);
        setScore();
        _is_menu = false;
    }
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
    init_menu();
    _display.Dynamic_loader(_lib_graphics[it_graphics]);
    std::cout << "Enter your name: " << std::flush;
    std::getline(std::cin, _name);
    _is_menu = true;
    core_loop();
}

void Arcade::Core::draw_menu(std::string path)
{
    _display.getInstance()->clear();
    _display.getInstance()->drawBackground(path);
    auto temp = _menu.getMenu();
    for (auto &tmp : temp)
        _display.getInstance()->draw(tmp);
    auto temp1 = _menu.getLib();
    if (_is_menu == true) {
        for (auto &tmp : temp1)
            _display.getInstance()->draw(tmp);
        auto temp2 = _menu.getGame();
        for (auto &tmp : temp2)
            _display.getInstance()->draw(tmp);
    }
}

void Arcade::Core::core_loop()
{
    _display.getInstance()->createWindow();
    Arcade::Button input = _display.getInstance()->getEvent();
    while (input != Arcade::Button::ESCAPE) {
        if (input == Arcade::Button::MENU)
            _is_menu = true;
        else if (_is_menu == true) {
            menu_move(input);
            draw_menu("assets/menu.jpg");
            _display.getInstance()->update();
        }
        //if (input == Arcade::Button::PAUSE)
        //    _pause = true;
        //if (_pause == true)
        else {
            endGame();
            switch_lib(input);
            draw_menu("assets/bg.jpg");
            highScore();
            auto buff = _game.getInstance()->play(input);
            for (auto &tmp : buff)
                _display.getInstance()->draw(tmp);
            _display.getInstance()->update();
        }
        input = _display.getInstance()->getEvent();
    }
    _display.getInstance()->clear();
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
    if (input == Arcade::Button::RESTART)
        _game.Dynamic_loader(_lib_games[it_games]);
}

void Arcade::Core::next_game()
{
    if (_lib_games.size() <= 1)
        return;
    it_games = (it_games + 1) % _lib_games.size();
    _game.Dynamic_loader(_lib_games[it_games]);
    _menu.getGame()[it_games].get()->setColor(Arcade::Color::RED);
    _menu.getGame()[(it_games - 1) % _lib_games.size()].get()->setColor(Arcade::Color::CYAN);
    setScore();
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
    setScore();
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

void Arcade::Core::setScore()
{
    _score.setPath(_lib_games[it_games].substr(
    _lib_games[it_games].find_last_of("/\\") + 1, 
    _lib_games[it_games].find_last_of(".so")) + ".txt");
    _score.loadScore();
}

void Arcade::Core::endGame()
{
    if (_game.getInstance()->endGame() == true) {
        _score.writeScore(_name, std::to_string(_game.getInstance()->getScore()));
        _game.Dynamic_loader(_lib_games[it_games]);
    }
}

void Arcade::Core::highScore()
{
    if (_score.getScore().compare("NOT AVAILABLE") == 0)
        _highScore.get()->setText("NOT AVAILABLE");
    else
        _highScore.get()->setText(_score.getName() + " " + _score.getScore());
    _display.getInstance()->draw(_highScore);
}