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
            int getScore() override {
                return _score;
            }
            std::vector<std::shared_ptr<Arcade::IObject>> play(Arcade::Button button) override;
            std::vector<std::shared_ptr<Arcade::IObject>> allObj();
            bool endGame() override;
        protected:
        private:
            int _score{0};
            int _inc{1};
            int _times{0};
            bool end_game;
            std::size_t _lengthSnake{2};
            int _direction{-1};
            bool _ispause{false};
            std::vector<std::shared_ptr<Arcade::Object>> _obj;
            std::vector<std::shared_ptr<Arcade::Object>> _wall;
            std::vector<std::shared_ptr<Arcade::Object>> _snake;
            std::vector<std::shared_ptr<Arcade::Object>> _food;
            std::vector<std::shared_ptr<Arcade::Text>> _text;
            std::pair<std::size_t, std::size_t> map_size;
    };
    
    extern "C" Snake *entryPoint() {
        return new Snake;
    };

}

#endif /* !SNAKE_HPP_ */
