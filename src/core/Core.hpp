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
            void core_loop();
            void menu();
            void next_game();
            void prev_game();
            void next_display();
            void prev_display();
            void restart_game();
            void exit();
        protected:
        private:
            std::string _path;
            std::vector<std::string> _lib_graphics;
            std::vector<std::string> _lib_games;
            DLLoader<Arcade::IGames> _game;
            DLLoader<Arcade::IGraphic> _display;
            DLLoader<Arcade::IDisplayModule> _all_lib;
    };
}

#endif /* !CORE_HPP_ */
