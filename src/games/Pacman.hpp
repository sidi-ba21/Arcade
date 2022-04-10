/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** Pacman
*/

#include "IGames.hpp"
#include "../objects/IObject.hpp"
#include "../objects/Object.hpp"
#include "../objects/Text.hpp"

namespace Arcade {

    class Pacman : public IGames {
        public:
            Pacman();
            ~Pacman() = default;
            void init_map();
            void init_score();
            bool check_ennemy(std::pair<float, float> pos);
            void move(Arcade::Button);
            void movements();
            void make_invincible();
            void isstart();
            void move_ghosts(int);
            int getScore() override {
                return _score;
            }
            std::vector<std::shared_ptr<Arcade::IObject>> play(Arcade::Button button) override;
            std::vector<std::shared_ptr<Arcade::IObject>> allObj();
            bool endGame() override;
        protected:
        private:
            int _score;
            int _inc;
            int _times;
            bool end_game;
            int _lives;
            int _direction;
            std::vector<std::shared_ptr<Arcade::Object>> _obj;
            std::vector<std::shared_ptr<Arcade::Object>> _bigobj;
            std::vector<std::shared_ptr<Arcade::Object>> _Ghosts;
          //  std::shared_ptr::<Arcade::Object> _pacman;
            std::vector<std::shared_ptr<Arcade::Text>> _text;
            std::pair<std::size_t, std::size_t> map_size;
    };
    
    extern "C" Pacman *entryPoint() {
        return new Pacman;
    };
}
