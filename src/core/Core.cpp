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
    Arcade::Object test();
    load_file();
    _display.Dynamic_loader(_path);
    _display.getInstance()->print(_path);
}

void Arcade::Core::core_loop()
{
    while (1)
    {
        
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