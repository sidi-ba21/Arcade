/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#include "DLLoader.hpp"
#include "Error.hpp"
#include "../games/IGames.hpp"
#include "../graphicals/IGraphic.hpp"
#include "../IDisplayModule.hpp"
#include <vector>

#ifndef CORE_HPP_
#define CORE_HPP_

namespace Arcade 
{
    class Core {
        public:
            Core(std::string &pathname);
            ~Core();
            void load_file();
            void display_lib();
            void core_loop();
            void menu();
            void switch_lib(Arcade::Button &input);
            void next_game();
            void prev_game();
            void next_display();
            void prev_display();
            void restart_game();
            void exit();
        protected:
        private:
            std::string _path;
            std::string _name;
            DLLoader<Arcade::IDisplayModule> _all_lib;
            std::vector<std::string> _lib_graphics;
            std::vector<std::string> _lib_games;
            std::size_t it_graphics{0};
            std::size_t it_games{0};
            DLLoader<Arcade::IGames> _game;
            DLLoader<Arcade::IGraphic> _display;
    };
}

#endif /* !CORE_HPP_ */
