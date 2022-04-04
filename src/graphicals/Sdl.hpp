/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** Sdl
*/

#include "IGraphic.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_ttf.h>
#include "../objeccts/Sound.hpp"
#include "../objeccts/Object.hpp"
#include "../objeccts/Text.hpp"

namespace Arcade {

class SDL final : public AGraphic {
    public:
        SDL();
        ~SDL();
        void drawObject(Arcade::Object *) override;
        void drawText(Arcade::Text *) override;
        void clear();
        void update();
        Arcade::Button getEvent();
    protected:
    private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Event m_event;
    SDL_Surface *m_surface;
    TTF_Font *m_font;
};

extern "C" SDL *entry_point() {
    return new SDL;
};

}
