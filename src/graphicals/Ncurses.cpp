/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"
#include <ncurses.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

Arcade::Ncurses::Ncurses()
{
    initscr();
    keypad(stdscr, TRUE);
    timeout(10);
    noecho();
    curs_set(FALSE);
    start_color();
    init_pair(0, BLACK, 0);
    init_pair(1, RED, 0);
    init_pair(2, GREEN, 0);
    init_pair(3, YELLOW, 0);
    init_pair(4, BLUE, 0);
    init_pair(5, MAGENTA, 0);
    init_pair(6, CYAN, 0);
    init_pair(7, WHITE, 0);
}

Arcade::Ncurses::~Ncurses()
{
    endwin();
}

void Arcade::Ncurses::drawObject(Arcade::Object *obj)
{
    char tmp[2];

    tmp[0] = static_cast<char>(obj->getSymbol());
    tmp[1] = '\0';
    attron(COLOR_PAIR(obj->getColor()));
    mvprintw(round(obj->getPos().second), round(obj->getPos().first), tmp);
    attroff(COLOR_PAIR(obj->getColor()));
}

void Arcade::Ncurses::drawText(Arcade::Text *text)
{
    attron(COLOR_PAIR(text->getColor()));
    mvprintw(round(text->getPos().second), round(text->getPos().first), text->getText().c_str());
    attroff(COLOR_PAIR(text->getColor()));
}
void Arcade::Ncurses::clear()
{
    wrefresh(stdscr);
}
void Arcade::Ncurses::update()
{
    wclear(stdscr);
}

Arcade::Button Arcade::Ncurses::getEvent()
{

}

int main(int ac, char **av)
{
    std::ifstream file(av[1]);
    std::string tmp;
    Arcade::Ncurses test;
    std::vector<std::shared_ptr<Arcade::Object>> obj;
    int y = 0;
    if (!file.is_open())
        return 84;
    while (std::getline(file, tmp)) {
        for (int x = 0; tmp[x] != '\0'; x++) {
            if (tmp[x] == '#')
                obj.emplace_back(std::make_shared<Arcade::Object>(av[1], tmp[x], Arcade::Color::CYAN, (float)x, (float)y));
            else if (tmp[x] == ' ')
                obj.emplace_back(std::make_shared<Arcade::Object>(av[1], tmp[x], Arcade::Color::BLACK, (float)x, (float)y));
            else if (tmp[x] == '0')
                obj.emplace_back(std::make_shared<Arcade::Object>(av[1], tmp[x], Arcade::Color::GREEN, (float)x, (float)y));
        }
        y++;
    }
    fprintf(stderr, "%d\n", y);
    while (1) {
        for (auto const &temp : obj) {
            test.drawObject(temp.get());
        }
    //    test.update();
    //    test.clear();
    }
    return (0);
}