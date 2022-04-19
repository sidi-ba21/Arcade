/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** Pacman
*/

#include "Pacman.hpp"

static const char pacman_map[] = "assets/pacman/map.txt";
static const char player_right[] = "assets/pacman/pacman_right.png";
static const char player_left[] = "assets/pacman/pacman_left.png";
static const char player_up[] = "assets/pacman/pacman_up.png";
static const char player_down[] = "assets/pacman/pacman_down.png";
static const char pacman_ghost[] = "assets/pacman/ghosts.png";
static const char pacman_gum[] = "assets/pacman/gum.png";
static const char pacman_minigum[] = "assets/pacman/minigum.png";
static const char terrain[] = "assets/pacman/terrain.png";
static const char sol[] = "assets/pacman/SOL.png";
static const char ghost_red[] = "assets/pacman/red_ghost.png";
static const char ghost_blue[] = "assets/pacman/blue_ghost.png";
static const char ghost_pink[] = "assets/pacman/pink_ghost.png";
static const char ghost_yellow[] = "assets/pacman/yellow_ghost.png";

Arcade::Pacman::Pacman()
{ 
    _direction = -1;
    _inc = 1;
    _lives = 5;
    _times = 0;
    _score = 0;
    _nb_food = 0;
    for (int i = 0; i < 4; i++)
        _dir_ghost[i] = -1;
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
        _map.emplace_back(tmp);
        if (y == 0)
            map_size.first = tmp.size();
        for (int x = 0; tmp[x] != '\0'; x++) {
            if (tmp[x] == '#')
                _obj.emplace_back(std::make_shared<Arcade::Object>(sol, tmp[x], Arcade::Color::CYAN, (float)x, (float)y));
            else if (tmp[x] == '.') {
                _food.emplace_back(std::make_shared<Arcade::Object>(pacman_minigum, tmp[x], Arcade::Color::YELLOW,(float)x, (float)y));
                _obj.emplace_back(std::make_shared<Arcade::Object>(terrain, ' ', Arcade::Color::BLACK,(float)x, (float)y));
                _nb_food++;
            }
            else if (tmp[x] == 'O') {
                _food.emplace_back(std::make_shared<Arcade::Object>(pacman_gum, tmp[x], Arcade::Color::YELLOW,(float)x, (float)y));
                _obj.emplace_back(std::make_shared<Arcade::Object>(terrain, ' ', Arcade::Color::BLACK,(float)x, (float)y));
                _nb_food++;
            }
            else if (tmp[x] == 'P')
                _obj.emplace_back(std::make_shared<Arcade::Object>(terrain, tmp[x], Arcade::Color::BLACK,(float)x, (float)y));
            else if (tmp[x] == 'R') {
                _Ghosts.emplace_back(std::make_shared<Arcade::Object>(ghost_red, tmp[x], Arcade::Color::RED,(float)x, (float)y));
                _obj.emplace_back(std::make_shared<Arcade::Object>(terrain, ' ', Arcade::Color::BLACK,(float)x, (float)y));
            }
            else if (tmp[x] == 'B') {
                _Ghosts.emplace_back(std::make_shared<Arcade::Object>(ghost_blue, tmp[x], Arcade::Color::BLUE,(float)x, (float)y));
                _obj.emplace_back(std::make_shared<Arcade::Object>(terrain, ' ', Arcade::Color::BLACK,(float)x, (float)y));
            }
            else if (tmp[x] == 'G') {
                _Ghosts.emplace_back(std::make_shared<Arcade::Object>(ghost_yellow, tmp[x], Arcade::Color::GREEN,(float)x, (float)y));
                _obj.emplace_back(std::make_shared<Arcade::Object>(terrain, ' ', Arcade::Color::BLACK,(float)x, (float)y));
            }
            else if (tmp[x] == 'M') {
                _Ghosts.emplace_back(std::make_shared<Arcade::Object>(ghost_pink, tmp[x], Arcade::Color::MAGENTA,(float)x, (float)y));
                _obj.emplace_back(std::make_shared<Arcade::Object>(terrain, ' ', Arcade::Color::BLACK,(float)x, (float)y));
            }
            else if (tmp[x] == 'X') {
                _player.emplace_back(std::make_shared<Arcade::Object>(player_right, tmp[x], Arcade::Color::YELLOW,(float)x, (float)y));
                _obj.emplace_back(std::make_shared<Arcade::Object>(terrain, ' ', Arcade::Color::BLACK,(float)x, (float)y));
            }
            else
                _obj.emplace_back(std::make_shared<Arcade::Object>(terrain, ' ', Arcade::Color::BLACK,(float)x, (float)y));
        }
        y++;
    }
    map_size.second = y;
}

void Arcade::Pacman::init_score()
{
    _score = 0;
    _text.emplace_back(std::make_shared<Arcade::Text>("SCORE", Arcade::Color::GREEN, 920.f, 250.f));
    _text.emplace_back(std::make_shared<Arcade::Text>(std::to_string(_score), Arcade::Color::GREEN, 948.f, 300.f));
}

void Arcade::Pacman::move(Arcade::Button dir)
{
    if (dir == Button::PAUSE) {
        if  (!_ispause)
            _ispause = true;
        else
            _ispause = false;
    }
    if (dir == Button::DOWN || dir == Button::LEFT || dir == Button::RIGHT || dir == Button::UP)
        _direction = dir;
}

void Arcade::Pacman::move_ghosts()
{
    srand(time(NULL));
    for (int i = 0; i < _Ghosts.size(); i++) {
        if (_times == 0)
            _dir_ghost[i] = rand() % 4;
        movementsGhost(_Ghosts[i], _dir_ghost[i]);
    }
    _times = (_times + 1) % 30;
}

void Arcade::Pacman::movementsGhost(std::shared_ptr<Arcade::Object> obj, int dir)
{
    if (dir == Button::LEFT) {
        if (_map[obj.get()->getPos().second][obj.get()->getPos().first - 1] != '#' &&
            _map[obj.get()->getPos().second][obj.get()->getPos().first - 1] != 'P')
            obj->setPos(obj->getPos().first - 1, obj->getPos().second);
    }
    else if (dir == Button::RIGHT) {
        if (_map[obj.get()->getPos().second][obj.get()->getPos().first + 1] != '#' &&
            _map[obj.get()->getPos().second][obj.get()->getPos().first + 1] != 'P')
            obj->setPos(obj->getPos().first + 1, obj->getPos().second);
    }
    else if (dir == Button::UP) {
        if (_map[obj.get()->getPos().second - 1][obj.get()->getPos().first] != '#')
            obj->setPos(obj->getPos().first, obj->getPos().second - 1);
    }
    else if (dir == Button::DOWN) {
        if (_map[obj.get()->getPos().second + 1][obj.get()->getPos().first] != '#')
            obj->setPos(obj->getPos().first, obj->getPos().second + 1);
    }
}

void Arcade::Pacman::movements(std::shared_ptr<Arcade::Object> obj, int dir)
{
    if (dir == Button::LEFT) {
        if (_map[obj.get()->getPos().second][obj.get()->getPos().first - 1] != '#')
            obj->setPos(obj->getPos().first - 1, obj->getPos().second);
        obj->setPath(player_left);
    }
    else if (dir == Button::RIGHT) {
        if (_map[obj.get()->getPos().second][obj.get()->getPos().first + 1] != '#')
            obj->setPos(obj->getPos().first + 1, obj->getPos().second);
        obj->setPath(player_right);
    }
    else if (dir == Button::UP) {
        if (_map[obj.get()->getPos().second - 1][obj.get()->getPos().first] != '#')
            obj->setPos(obj->getPos().first, obj->getPos().second - 1);
        obj->setPath(player_up);
    }
    else if (dir == Button::DOWN) {
        if (_map[obj.get()->getPos().second + 1][obj.get()->getPos().first] != '#')
            obj->setPos(obj->getPos().first, obj->getPos().second + 1);
        obj->setPath(player_down);
    }
}

bool Arcade::Pacman::check_ennemy()
{
    std::pair<float, float> temp;
    std::pair<float, float> pos = _player.front()->getPos();

    for (int i = 0; i < _Ghosts.size(); i++) {
        temp = _Ghosts[i]->getPos();
        if (pos.first == temp.first && pos.second == temp.second)
            return true;
    }
    return false;
}

void Arcade::Pacman::eat_food()
{
    for (auto &tmp : _food) {
        if (tmp->getPos().first == _player.front()->getPos().first &&
            tmp->getPos().second == _player.front()->getPos().second) {
                tmp->setPath(terrain);
                tmp->setSymbol(' ');
                _nb_food--;
                return;
            }
    }
}

std::vector<std::shared_ptr<Arcade::IObject>> Arcade::Pacman::play(Arcade::Button button)
{
    move(button);
    if (_ispause)
        return allObj();
    movements(_player.front(), _direction);
    if (_map[_player.front()->getPos().second][_player.front()->getPos().first] == '.' ||
        _map[_player.front()->getPos().second][_player.front()->getPos().first] == 'O') {
        _map[_player.front()->getPos().second][_player.front()->getPos().first] = ' ';
        eat_food();
        _score++;
    }
    if (_map[_player.front()->getPos().second][_player.front()->getPos().first] == 'P') {
        if (_player.front()->getPos().first <= 0) {
            _player.front()->setPos(map_size.first - 1, _player.front()->getPos().second);
            move(Arcade::Button::LEFT);
        }
        else {
            _player.front()->setPos(1, _player.front()->getPos().second);
            move(Arcade::Button::RIGHT);
        }
        movements(_player.front(), _direction);
    }
    move_ghosts();
    _text.back()->setText(std::to_string(_score));
    return (allObj());
}

std::vector<std::shared_ptr<Arcade::IObject>> Arcade::Pacman::allObj()
{
    std::vector<std::shared_ptr<Arcade::IObject>> obj;
    for (auto &elem : _obj)
        obj.push_back(elem);
    for (auto &elem : _food)
        obj.push_back(elem);
    for (auto &elem : _Ghosts)
        obj.push_back(elem);
    for (auto &elem : _player)
        obj.push_back(elem);
    for (auto &elem : _text)
        obj.push_back(elem);
    return (obj);
}

bool Arcade::Pacman::endGame()
{
    if (check_ennemy() || _nb_food <= 0)
        return true;
    return false;
}