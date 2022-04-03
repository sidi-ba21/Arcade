/*
** EPITECH PROJECT, 2022
** IGraphic
** File description:
** Igraphic
*/

#include <iostream>

#ifndef IGRAPHICS_HPP_
#define IGRAPHICS_HPP_

namespace Arcade 
{
    class IGraphics {
        public:
            IGraphics() { puts("pass"); }
            ~IGraphics();
            IGraphics *entryPoint();
            int print(std::string str) 
            {
                std::cout << str << std::endl;
                return 9;
            }
        protected:
        private:
    };
}

#endif /* !IGRAPHIC_HPP_ */
