/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#pragma once

#include "../objects/IObject.hpp"
#include "../objects/Object.hpp"
#include "../objects/Text.hpp"
#include "../objects/Sound.hpp"
#include "../core/Error.hpp"
#include <memory>
#include <map>
#include "../IDisplayModule.hpp"

namespace Arcade {

    class IGraphic : public IDisplayModule {
        public:
            virtual ~IGraphic() = default;
            virtual void draw(std::shared_ptr<Arcade::IObject> obj) = 0;
            virtual void clear() = 0;
            virtual void update() = 0;
            virtual Arcade::Button getEvent() = 0;
            virtual void createWindow() = 0;
            virtual void drawBackground(std::string) = 0;
            const  std::string &getName() override {
                return _name;
            }
        protected:
            const std::string _name { "IGraphic" };
    };
    
    class AGraphic : public IGraphic {
        public:
        virtual ~AGraphic() = default;
        void draw(std::shared_ptr<Arcade::IObject> obj) override final {
            if (dynamic_cast<Arcade::Object*>(obj.get()) != nullptr)
                drawObject(dynamic_cast<Arcade::Object *>(obj.get()));
            else if (dynamic_cast<Arcade::Text*>(obj.get()) != nullptr)
                drawText(dynamic_cast<Arcade::Text*>(obj.get()));
            else if (dynamic_cast<Arcade::Sound *>(obj.get()) != nullptr)
                playSound(dynamic_cast<Arcade::Sound*>(obj.get()));
        }
        virtual void playSound(Arcade::Sound *) = 0;
        virtual void drawObject(Arcade::Object *) = 0;
        virtual void drawText(Arcade::Text *) = 0;
    };

}

#endif /* !IGRAPHIC_HPP_ */
