/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** Sdl
*/

#include "IGraphic.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "../objects/Sound.hpp"
#include "../objects/Object.hpp"
#include "../objects/Text.hpp"

namespace Arcade {

    std::map<Arcade::Color, SDL_Color> sdlColor {
        {Arcade::Color::BLACK, {0, 0, 0, 0}},
        {Arcade::Color::BLUE, {0, 0, 255, 0}},
        {Arcade::Color::RED, {255, 0, 0, 0}},
        {Arcade::Color::GREEN, {0, 255, 0, 0}},
        {Arcade::Color::YELLOW, {255, 255, 0, 0}},
        {Arcade::Color::MAGENTA, {255, 0, 255, 0}},
        {Arcade::Color::CYAN, {0, 255, 255, 0}},
        {Arcade::Color::WHITE, {255, 255, 255, 0}},
    };
    std::map<SDL_Keycode, Arcade::Button> Key_list = {
		{SDLK_ESCAPE, Button::ESCAPE},
		{SDLK_KP_ENTER, Button::ENTER},
		{SDLK_r, Button::RESTART},
		{SDLK_z, Button::UP},
		{SDLK_q, Button::LEFT},
		{SDLK_s, Button::DOWN},
		{SDLK_d, Button::RIGHT},
		{SDLK_F2, Button::PREV_GAME},
		{SDLK_F3, Button::NEXT_GAME},
		{SDLK_F4, Button::PREV_LIB},
		{SDLK_F5, Button::NEXT_LIB},
		{SDLK_LEFT, Button::LEFT},
		{SDLK_RIGHT, Button::RIGHT},
		{SDLK_UP, Button::UP},
		{SDLK_DOWN, Button::DOWN},
	};

    class Sdl final : public AGraphic {
        public:
            Sdl();
            ~Sdl();
            void drawObject(Arcade::Object *) override;
            void drawText(Arcade::Text *) override;
            void clear();
            void update();
            Arcade::Button getEvent() override;
        protected:
        private:
            SDL_Window *_window;
            SDL_Renderer *_renderer;
            SDL_Event _event;
            SDL_Surface *_surface;
            TTF_Font *_font;
    };

    extern "C" Sdl *entryPoint() {
        return new Sdl;
    };

}
