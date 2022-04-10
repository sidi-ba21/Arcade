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
            bool check_ennemy();
            void move(Arcade::Button);
            void movements(std::shared_ptr<Arcade::Object>, int dir);
            void movementsGhost(std::shared_ptr<Arcade::Object>, int dir);
            void eat_food();
            void move_ghosts();
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
            int _nb_food;
            int _times;
            bool end_game;
            int _lives;
            int _direction;
            int _dir_ghost[4];
            std::vector<std::shared_ptr<Arcade::Object>> _obj;
            std::vector<std::shared_ptr<Arcade::Object>> _player;
            std::vector<std::shared_ptr<Arcade::Object>> _food;
            std::vector<std::shared_ptr<Arcade::Object>> _Ghosts;
            std::vector<std::string> _map;
            std::vector<std::shared_ptr<Arcade::Text>> _text;
            std::pair<std::size_t, std::size_t> map_size;
    };
    
    extern "C" Pacman *entryPoint() {
        return new Pacman;
    };
}
