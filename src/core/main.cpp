/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <dlfcn.h>
#include <iostream>
#include "DLLoader.hpp"
#include "Core.hpp"

void basic_error(int ac, char **av)
{
    if (ac != 2)
        throw FileWrongError("ARCADE: Usage: ./arcade ./lib/lib_arcade_xxx.so");
}

int main(int ac, char **av)
{
    try {
        basic_error(ac, av);
        std::string str = std::string(av[1]);
        Arcade::Core test(str);
    } catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    return 0;
}