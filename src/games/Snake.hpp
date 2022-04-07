/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "IGames.hpp"
#include "../objects/IObject.hpp"
#include "../objects/Object.hpp"
#include "../objects/Text.hpp"


namespace Arcade {

class Snake : public IGames {
    public:
        Snake();
        ~Snake() = default;
        void init_map();
        void init_food();
        void init_score();
        void gen_food();
        bool food_check(std::pair<float, float> pos);
        void move(Arcade::Button);
        void movements();
        bool is_food(float x, float y);
        std::vector<std::shared_ptr<Arcade::IObject>> play(Arcade::Button button) override;
        std::vector<std::shared_ptr<Arcade::IObject>> allObj();
        bool endGame();
    protected:
    private:
        int _score;
        int _inc;
        int _times;
        bool end_game;
        std::size_t _lengthSnake;
        int _direction;
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
