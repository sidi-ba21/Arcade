/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#pragma once

#include "DLLoader.hpp"
#include "Error.hpp"
#include "../games/IGames.hpp"
#include "../graphicals/IGraphic.hpp"
#include "../IDisplayModule.hpp"
#include "Menu.hpp"
#include "Score.hpp"
#include <vector>

#ifndef CORE_HPP_
#define CORE_HPP_

namespace Arcade 
{
    class Core {
        public:
            Core(std::string &pathname);
            ~Core() = default;
            void load_file();
            void display_lib();
            void core_loop();
            void switch_lib(Arcade::Button &input);
            void next_game();
            void prev_game();
            void next_display();
            void prev_display();
            void restart_game();
            void init_menu();
            void draw_menu(std::string);
            void menu_move(Arcade::Button event);
            void setScore();
            void highScore();
            void endGame();
            void exit();
        protected:
        private:
            std::string _path;
            std::string _name;
            std::vector<std::string> _lib_graphics;
            std::vector<std::string> _lib_games;
            std::size_t it_graphics{0};
            std::size_t it_games{0};
            DLLoader<Arcade::IGames> _game;
            DLLoader<Arcade::IGraphic> _display;
            DLLoader<Arcade::IDisplayModule> _all_lib;
            Menu _menu;
            std::shared_ptr<Text>_highScore {
                std::make_shared<Text>("NOT AVAILABLE", Arcade::Color::GREEN, 1600.f, 100.f)};
            bool _is_menu{false};
            bool _pause{false};
            Score _score;
    };
}

#endif /* !CORE_HPP_ */
