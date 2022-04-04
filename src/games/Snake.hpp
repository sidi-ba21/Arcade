/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "IGames.hpp"
#include "../objeccts/IObject.hpp"
#include "../objeccts/Object.hpp"
#include "../objeccts/Text.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <exception>
#include <vector>

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
        ~Snake() = default;
        void init_map();
        void init_food();
        void gen_food();
        bool food_check(std::pair<float, float> pos);
        void move(Arcade::Move);
        void eat_food(Arcade::Move);
        void movements(Arcade::Move);
        void play();
        bool endGame();
    protected:
    private:
        int _score;
        bool end_game;
        std::size_t _lengthSnake;
        std::pair<std::size_t, std::size_t> _pos_snake;
        std::pair<std::size_t, std::size_t> _pos_food;
        std::vector<std::shared_ptr<Arcade::Object>> _obj;
        std::vector<std::shared_ptr<Arcade::Object>> _snake;
        std::vector<std::shared_ptr<Arcade::Text>> _text;
        std::pair<std::size_t, std::size_t> map_size;
};

extern "C" Snake *entry_point() {
    return new Snake;
};

}

#endif /* !SNAKE_HPP_ */
