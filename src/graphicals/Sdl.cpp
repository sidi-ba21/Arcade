/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** Sdl
*/

#include "Sdl.hpp"

static const int coef_w_obj = 13;
static const int coef_h_obj = 16;
Arcade::SDL::SDL()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    m_font = TTF_OpenFont("assets/font.ttf", 40);
    m_window = SDL_CreateWindow( "Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 600, SDL_WINDOW_SHOWN );
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

Arcade::SDL::~SDL()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    TTF_CloseFont(m_font);
    IMG_Quit();
    TTF_Quit();
 //   Mix_CloseAudio();
    SDL_Quit();
}

void Arcade::SDL::drawObject(Arcade::Object *obj)
{
    SDL_Surface *surface = IMG_Load(obj->getPath().c_str());
    SDL_Texture *temp = SDL_CreateTextureFromSurface(m_renderer, surface);
    SDL_Rect rect {};
    int h, w;
    rect.w = 1 * coef_w_obj;
    rect.h = 1 * coef_h_obj;
    rect.x = obj->getPos().first * coef_w_obj;
    rect.y = obj->getPos().second * coef_h_obj;
    SDL_RenderCopy(m_renderer, temp, NULL, &rect);
    SDL_DestroyTexture(temp);
}

void Arcade::SDL::drawText(Arcade::Text *text)
{
    SDL_Texture *texture {};
    SDL_Surface *temp = TTF_RenderText_Solid(m_font, text->getText().c_str(),
    Arcade::sdlColor[text->getColor()]);
    SDL_Rect rect = {};
    int h, w;

    texture = SDL_CreateTextureFromSurface(m_renderer, temp);
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    rect.w = w;
    rect.h = h;
    rect.x = text->getPos().first;
    rect.y = text->getPos().second;
    SDL_RenderCopy(m_renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(temp);
}

void Arcade::SDL::clear()
{
    SDL_RenderClear(m_renderer);
}

void Arcade::SDL::update()
{
    SDL_RenderPresent(m_renderer);
}

Arcade::Button Arcade::SDL::getEvent()
{
    SDL_Event event;

    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT)
            return (ESCAPE);
        if (event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_UP)
            return (Arcade::Button::UP);
        if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_LEFT)
            return (Arcade::Button::LEFT);
        if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
            return (Arcade::Button::RIGHT);
        if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
            return (Arcade::Button::DOWN);
    }
    return (Arcade::Button::NOTHING);
}
/*
int main(int ac, char **av)
{
    std::string tmp;
    Arcade::SDL test;
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