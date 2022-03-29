/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "IGames.hpp"
#include <algorithm>

namespace Arcade {

enum Move {
    left,
    right,
    up,
    down
};

class Snake : public IGames {
    public:
        Snake();
        ~Snake();
        void init_snake();
        void init_map();
        void init_food();
        void move(Arcade::Move);

        bool endGame();
    protected:
    private:
        int _score;
        bool end_game;
        std::size_t _lengthSnake;
        std::pair<std::size_t, std::size_t> _pos_snake;
        std::pair<std::size_t, std::size_t> _pos_food;
        
};
extern "C" Snake *entry_point();

}

#endif /* !SNAKE_HPP_ */
