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
    noecho();
    timeout(10);
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
    mvwprintw(stdscr, round(obj->getPos().second), round(obj->getPos().first) * 2, tmp);
    attroff(COLOR_PAIR(obj->getColor()));
}

void Arcade::Ncurses::drawText(Arcade::Text *text)
{
    attron(COLOR_PAIR(text->getColor()));
    mvwprintw(stdscr, round(text->getPos().second), round(text->getPos().first), text->getText().c_str());
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
    return Arcade::Button::ENTER;
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
            else if (tmp[x] == '0')
                obj.emplace_back(std::make_shared<Arcade::Object>(av[1], tmp[x], Arcade::Color::GREEN, (float)x, (float)y));
            else if (tmp[x] == 'F')
                obj.emplace_back(std::make_shared<Arcade::Object>(av[1], tmp[x], Arcade::Color::RED, (float)x, (float)y));
        }
        y++;
    }
    for (auto const &temp : obj) {
            test.drawObject(temp.get());
    }
    test.clear();
    while (1) {
        test.drawObject(obj.front().get());
        test.update();
    }
    return (0);
}