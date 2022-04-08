/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

#include <vector>
#include <memory>
#include "../objects/IObject.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include "../IDisplayModule.hpp"

namespace Arcade {

class IGames : public IDisplayModule {
    public:
        virtual ~IGames() = default;
        virtual std::vector<std::shared_ptr<Arcade::IObject>> play(Arcade::Button button) = 0;
        const  std::string &getName() override {
            return _name;
        }
       // virtual int getScore() = 0;
//        virtual void reset() = 0;
       // virtual void highScore() = 0;
        protected:
            const std::string _name { "IGames" };
};

}

#endif /* !IGAMES_HPP_ */