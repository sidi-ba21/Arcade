/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** Sdl
*/

#include "Sdl.hpp"

static const int coef_w_obj = 15;
static const int coef_h_obj = 20;

void Arcade::Sdl::createWindow()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    _font = TTF_OpenFont("assets/font.ttf", 40);
    if (!_font)
        throw GraphicsError("Failed to load font");
    _window = SDL_CreateWindow( "Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN );
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

Arcade::Sdl::Sdl()
{
    _window = nullptr;
    _renderer = nullptr;
    _font = nullptr;
}

Arcade::Sdl::~Sdl()
{
    
    if (_renderer != nullptr)
        SDL_DestroyRenderer(_renderer);
    if (_window != nullptr)
        SDL_DestroyWindow(_window);
    if (_font != nullptr)
        TTF_CloseFont(_font);
    IMG_Quit();
    TTF_Quit();
 //   Mix_CloseAudio();
    SDL_Quit();
}

void Arcade::Sdl::drawObject(Arcade::Object *obj)
{
    SDL_Surface *surface = IMG_Load(obj->getPath().c_str());
    SDL_Texture *temp = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_Rect rect {};
    int h, w;
    rect.w = 1 * coef_w_obj;
    rect.h = 1 * coef_h_obj;
    rect.x = obj->getPos().first * coef_w_obj;
    rect.y = obj->getPos().second * coef_h_obj;
    SDL_RenderCopy(_renderer, temp, NULL, &rect);
    SDL_DestroyTexture(temp);
}

void Arcade::Sdl::drawText(Arcade::Text *text)
{
    SDL_Texture *texture {};
    SDL_Surface *temp = TTF_RenderText_Solid(_font, text->getText().c_str(),
    Arcade::sdlColor[text->getColor()]);
    SDL_Rect rect = {};
    int h, w;

    texture = SDL_CreateTextureFromSurface(_renderer, temp);
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    rect.w = w;
    rect.h = h;
    rect.x = text->getPos().first;
    rect.y = text->getPos().second;
    SDL_RenderCopy(_renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(temp);
}

void Arcade::Sdl::clear()
{
    SDL_RenderClear(_renderer);
}

void Arcade::Sdl::update()
{
    SDL_RenderPresent(_renderer);
}

Arcade::Button Arcade::Sdl::getEvent()
{
    SDL_Event event {};

    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT)
            return (Button::ESCAPE);
        if (event.type == SDL_KEYDOWN) {
            if (Key_list.find(event.key.keysym.sym) != Key_list.end())
                return Key_list[event.key.keysym.sym];
        }
    }
    return (Arcade::Button::NOTHING);
}
/*
int main(int ac, char **av)
{
    std::string tmp;
    Arcade::Sdl test;
    Arcade::Snake snake;
    while (1) {
        auto input = test.getEvent();
        if (input == Arcade::Button::ESCAPE) {
            test.clear();
            break;
        }
        test.clear();
        auto buff = snake.play(input);
        for (auto &tmp : buff)
            test.draw(tmp);
        test.update();
    }
    return (0);
}
*/