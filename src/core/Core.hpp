/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#include "DLLoader.hpp"
#include "Error.hpp"
#include "../games/IGames.hpp"
#include "../graphicals/IGraphics.hpp"
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
            std::vector<std::string> _lib;
            //DLLoader<Arcade::IGames> _game;
            DLLoader<Arcade::IGraphics> _display;
    };
}

#endif /* !CORE_HPP_ */
