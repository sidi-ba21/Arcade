/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** Sdl
*/

#include "Sdl.hpp"

static const int coef_w_obj = 13;
static const int coef_h_obj = 20;
Arcade::SDL::SDL()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    m_font = TTF_OpenFont("assets/font.ttf", 15);
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
    int coef = 15.5;

    texture = SDL_CreateTextureFromSurface(m_renderer, temp);
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    rect.w = w * coef;
    rect.h = h * coef;
    rect.x = text->getPos().first * coef;
    rect.y = text->getPos().second * coef;
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
//   std::pair<float, float> pos = player->getPos();

    while (SDL_PollEvent(&m_event) != 0) {
        if (m_event.type == SDL_QUIT)
            return (ESCAPE);
    /*    if (m_event.key.keysym.sym == SDLK_z || m_event.key.keysym.sym == SDLK_UP)
            player->setPos(pos.first, pos.second - 1);
        if (m_event.key.keysym.sym == SDLK_q || m_event.key.keysym.sym == SDLK_LEFT)
            player->setPos(pos.first - 1, pos.second);
        if (m_event.key.keysym.sym == SDLK_d || m_event.key.keysym.sym == SDLK_RIGHT)
            player->setPos(pos.first + 1, pos.second);
        if (m_event.key.keysym.sym == SDLK_s || m_event.key.keysym.sym == SDLK_DOWN)
            player->setPos(pos.first, pos.second + 1);

*/
    }
}

int main(int ac, char **av)
{
    std::ifstream file(av[1]);
    std::string tmp;
    Arcade::SDL test;
    std::vector<std::shared_ptr<Arcade::Object>> obj;
    int y = 0;
    if (!file.is_open())
        return 84;
    while (std::getline(file, tmp)) {
        for (int x = 0; tmp[x] != '\0'; x++) {
            if (tmp[x] == '#')
                obj.emplace_back(std::make_shared<Arcade::Object>("assets/snake/wall.png", tmp[x], Arcade::Color::CYAN, (float)x, (float)y));
            else if (tmp[x] == '0')
                obj.emplace_back(std::make_shared<Arcade::Object>("assets/snake/snake_body.png", tmp[x], Arcade::Color::GREEN, (float)x, (float)y));
            else if (tmp[x] == 'F')
                obj.emplace_back(std::make_shared<Arcade::Object>("assets/snake/snake_food_bonus.png", tmp[x], Arcade::Color::RED, (float)x, (float)y));
            else if (tmp[x] == ' ')
                obj.emplace_back(std::make_shared<Arcade::Object>("assets/snake/SOL.png", tmp[x], Arcade::Color::BLACK, (float)x, (float)y));
        }
        y++;
    }
    std::vector<std::shared_ptr<Arcade::Text>> text;
    //text.emplace_back(std::make_shared<Arcade::Text>("SCORE"), Arcade::Color::WHITE, 800.f, 250.f);
    //text.emplace_back(std::make_shared<Arcade::Text>("0"), Arcade::Color::WHITE, 830.f, 280.f);
    while (1) {
        auto buff = obj;
        auto txt = text;
        auto input = test.getEvent();
        if (input == Arcade::Button::ESCAPE) {
            test.clear();
            break;
        }
        if (!buff.empty()) {
            for (auto &temp : buff) {
                test.draw(temp);
            }
        //    for (auto &temp2 : text) {
        //        test.draw(temp2);
        //    }
            test.update();
        }
    }
    return (0);
}