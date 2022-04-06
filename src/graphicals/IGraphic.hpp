/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#pragma once

#include "../objeccts/IObject.hpp"
#include "../objeccts/Object.hpp"
#include "../objeccts/Text.hpp"
#include "../objeccts/Sound.hpp"
#include <memory>

namespace Arcade {

class IGraphic {
    public:
        virtual ~IGraphic() = default;
        virtual void draw(std::shared_ptr<Arcade::IObject> obj) = 0;
        virtual void clear() = 0;
        virtual void update() = 0;
        virtual Arcade::Button getEvent() = 0;
    protected:
    private:
};

class AGraphic : public IGraphic {
    public:
    virtual ~AGraphic() = default;
    void draw(std::shared_ptr<Arcade::IObject> obj) override final {
        if (dynamic_cast<Arcade::Object*>(obj.get()) != nullptr)
            drawObject(dynamic_cast<Arcade::Object *>(obj.get()));
        else if (dynamic_cast<Arcade::Text*>(obj.get()) != nullptr)
            drawText(dynamic_cast<Arcade::Text*>(obj.get()));
    }

    void playSound(Arcade::Sound *) {

    }

    virtual void drawObject(Arcade::Object *) = 0;
    virtual void drawText(Arcade::Text *) = 0;
};

}

#endif /* !IGRAPHIC_HPP_ */
