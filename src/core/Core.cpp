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

//int dloader(std::string file)
//{
//    int (*ptr)(char *);
//    void *handle = dlopen(file.c_str(), RTLD_LOCAL | RTLD_NOW);
//    *(void **) (&ptr) = dlsym(handle, "entryPoint");
//    printf("ptr = %x\n", ptr);
//    ptr((char *)"test");
//    dlclose(handle);
//    return 0;
//}

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
    load_file();
    _display.Dynamic_loader(_path);
    _display.getInstance()->print(_path);
    //ptr((char *)"test");
    //_game.Dynamic_loader(_path);
    //dloader(_lib.at(1).c_str());
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