/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** Pacman
*/

#include "Pacman.hpp"

static const char pacman_map[] = "assets/pacman/map.txt";
static const char pacman[] = "assets/pacman/pacman.png";
static const char pacman_ghost[] = "assets/pacman/ghosts.png";
static const char pacman_gum[] = "assets/pacman/gum.png";
static const char terrain[] = "assets/pacman/terrain.png";
static int pos = 0;
static std::vector<std::string> map;

Arcade::Pacman::Pacman()
{
    _direction = -1;
    _inc = 1;
    _lives = 5;
    _times = 0;
    _score = 0;
    end_game = false;
    init_map();
    init_score();
}

void Arcade::Pacman::init_map()
{
    std::ifstream file(pacman_map);
    std::string tmp;
    int y = 0;
    int i = 0;

    if (!file.is_open())
        throw std::exception();
    while (std::getline(file, tmp)) {
        map.push_back(tmp);
        if (y == 0)
            map_size.first = tmp.size();
        for (int x = 0; tmp[x] != '\0'; x++) {
            if (tmp[x] == '#')
                _obj.emplace_back(std::make_shared<Arcade::Object>(terrain, tmp[x], Arcade::Color::WHITE, (float)x, (float)y));
            else if (tmp[x] == '.')
                _obj.emplace_back(std::make_shared<Arcade::Object>(pacman_gum, tmp[x], Arcade::Color::YELLOW,(float)x, (float)y));
            else if (tmp[x] == '0')
                _obj.emplace_back(std::make_shared<Arcade::Object>(pacman_gum, tmp[x], Arcade::Color::YELLOW,(float)x, (float)y));
            else if (tmp[x] == 'F')
                _obj.emplace_back(std::make_shared<Arcade::Object>(pacman_ghost, tmp[x], Arcade::Color::WHITE,(float)x, (float)y));
            else if (tmp[x] == 'P') {
                pos = _obj.size();
                _obj.emplace_back(std::make_shared<Arcade::Object>(pacman, tmp[x], Arcade::Color::YELLOW,(float)x, (float)y));
            }

        }
        y++;
    }
    map_size.second = y;
}

void Arcade::Pacman::init_score()
{
    _score = 0;
    _text.emplace_back(std::make_shared<Arcade::Text>("SCORE", Arcade::Color::WHITE, 700.f, 150.f));
    _text.emplace_back(std::make_shared<Arcade::Text>(std::to_string(_score), Arcade::Color::WHITE, 750.f, 280.f));
}

void Arcade::Pacman::move(Arcade::Button dir)
{
    //if ((dir == Button::DOWN && _direction != Button::UP) ||
    //(dir == Button::LEFT && _direction != Button::RIGHT) ||
    //(dir == Button::RIGHT && _direction != Button::LEFT) ||
    //(dir == Button::UP && _direction != Button::DOWN))
    _direction = dir;
}

void Arcade::Pacman::move_ghosts(int num)
{
    std::pair<float, float> temp = {0, 0};
    for (int i = 0; i < _Ghosts.size(); i++) {
        temp = _Ghosts[i]->getPos();
       // _Ghosts[i]->setPos(temp.first, temp.second - 1);
    }
}

void Arcade::Pacman::isstart()
{
    _times++;
    if (_times > 10) {
        //printf("move start\n");
        for (int i = 0; i < _Ghosts.size(); i++)
            move_ghosts(i);
    }
}

void Arcade::Pacman::movements()
{
    //auto it = _Ghosts.begin();

    std::pair<float, float> const temp = _obj[pos]->getPos();

    if (_direction == Button::LEFT) {
        _obj[pos]->setPos(_obj[pos]->getPos().first - 1, _obj[pos]->getPos().second);
    }
    else if (_direction == Button::RIGHT) {
        _obj[pos]->setPos(_obj[pos]->getPos().first + 1, _obj[pos]->getPos().second);
    }
    else if (_direction == Button::UP) {
        _obj[pos]->setPos(_obj[pos]->getPos().first, _obj[pos]->getPos().second - 1);
    }
    else if (_direction == Button::DOWN) {
            _obj[pos]->setPos(_obj[pos]->getPos().first, _obj[pos]->getPos().second + 1);
    }
    //if (map[_obj[pos]->getPos().first][_obj[pos]->getPos().second] == '#')
    //    _obj[pos]->setPos(temp.first, temp.second);
    //isstart();
}

bool Arcade::Pacman::check_ennemy(std::pair<float, float> pos)
{
    std::pair<float, float> temp;

    for (int i = 0; i < _Ghosts.size(); i++) {
        temp = _Ghosts[i]->getPos();
        if (pos.first == temp.first && pos.second == temp.second)
            return true;
    }
    return false;
}

std::vector<std::shared_ptr<Arcade::IObject>> Arcade::Pacman::play(Arcade::Button button)
{
    move(button);
    movements();
    _text.back()->setText(std::to_string(_score));
   /* if (!check_ennemy( _obj[pos]->getPos()))
        printf("fantome touché\n");*/
    return (allObj());
}

std::vector<std::shared_ptr<Arcade::IObject>> Arcade::Pacman::allObj()
{
    std::vector<std::shared_ptr<Arcade::IObject>> obj;
    for (auto &elem : _obj)
        obj.push_back(elem);
    for (auto &elem : _Ghosts)
        obj.push_back(elem);
    for (auto &elem : _text)
        obj.push_back(elem);
    return (obj);
}

bool Arcade::Pacman::endGame()
{
    return true;
}