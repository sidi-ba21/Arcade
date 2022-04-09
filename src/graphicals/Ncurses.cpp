/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"
#include <cmath>
#include <unistd.h>

void Arcade::Ncurses::createWindow()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr, TRUE);
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

Arcade::Ncurses::Ncurses()
{
}

Arcade::Ncurses::~Ncurses()
{
    endwin();
}

void Arcade::Ncurses::drawBackground(std::string)
{

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
    mvwprintw(stdscr, round(text->getPos().second) / 25, round(text->getPos().first) / 10, text->getText().c_str());
    attroff(COLOR_PAIR(text->getColor()));
}
void Arcade::Ncurses::clear()
{
    wclear(stdscr);
}
void Arcade::Ncurses::update()
{
    wrefresh(stdscr);
    usleep(60000);
}

Arcade::Button Arcade::Ncurses::getEvent()
{
    int event = getch();
    Arcade::Button button = NOTHING;

    while (event != ERR) {
        if (Key_list.find(event) != Key_list.end())
            button = Key_list[event];
        event = getch();
    }
    return button;
}