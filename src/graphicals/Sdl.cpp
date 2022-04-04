/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** Sdl
*/

#include "Sdl.hpp"

Arcade::SDL::SDL()
{
    SDL_Init( SDL_INIT_VIDEO );
    TTF_Init();
    m_window = SDL_CreateWindow( "Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 720, SDL_WINDOW_SHOWN );
    m_surface = SDL_GetWindowSurface( m_window );
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

Arcade::SDL::~SDL()
{
    SDL_FreeSurface(m_surface);
    m_surface = NULL;
    SDL_DestroyRenderer(m_renderer);
    m_renderer = NULL;
    SDL_DestroyWindow(m_window);
    m_window = NULL;
    SDL_Quit();
}

void Arcade::SDL::drawObject(Arcade::Object *obj)
{
    SDL_Surface *temp = IMG_Load(obj->getPath().c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, temp);
    SDL_Rect rect = {obj->getPos().first, obj->getPos().second, 0, 0};

    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    SDL_BlitSurface(temp, NULL, m_surface, &rect);
    SDL_FreeSurface(temp);
    SDL_DestroyTexture(texture);
}

static SDL_Color conv_color(Arcade::Color color)
{
    if (color == Arcade::BLACK)
        return {0, 0, 0};
    if (color == Arcade::RED)
        return {255, 0, 0};
    if (color == Arcade::GREEN)
        return {0, 255, 0};
    if (color == Arcade::YELLOW)
        return {255, 255, 0};
    if (color == Arcade::BLUE)
        return {0, 0, 255};
    if (color == Arcade::MAGENTA)
        return {255, 0, 255};
    if (color == Arcade::CYAN)
        return {0, 255, 255};
    if (color == Arcade::WHITE)
        return {255, 255, 255};
}

void Arcade::SDL::drawText(Arcade::Text *text)
{
    SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);
    SDL_Surface *temp;
    m_font = TTF_OpenFont("", 15);
    SDL_Rect rect = {0, 0, text->getPos().first, text->getPos().second};
    temp = TTF_RenderText_Solid(m_font, text->getText().c_str(), conv_color(text->getColor()));
    SDL_RenderCopy(m_renderer, texture, &rect, NULL);
}

void Arcade::SDL::clear()
{
    SDL_RenderClear(m_renderer);
}

void Arcade::SDL::update()
{
    SDL_UpdateWindowSurface(m_window);
}

Arcade::Button Arcade::SDL::getEvent()
{
    while (SDL_PollEvent(&m_event) != 0) {
        if (m_event.type == SDL_QUIT)
            this->~SDL();
    }
}