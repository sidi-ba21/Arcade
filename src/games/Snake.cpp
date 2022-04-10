/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"
#include <unistd.h>

static const char snake_map[] = "assets/snake/map.txt";
static const char snake_down[] = "assets/snake/head_down.png";
static const char snake_up[] = "assets/snake/head_up.png";
static const char snake_left[] = "assets/snake/head_left.png";
static const char snake_right[] = "assets/snake/head_right.png";
static const char snake_body[] = "assets/snake/snake_body.png";
static const char snake_food[] = "assets/snake/food.png";
static const char snake_food_bonus[] = "assets/snake/snake_food_bonus.png";
static const char wall[] = "assets/snake/wall.png";
static const char sol[] = "assets/snake/SOL.png";

Arcade::Snake::Snake()
{
    init_map();
    init_food();
    gen_food();
    init_score();
}

void Arcade::Snake::init_map()
{
    std::ifstream file(snake_map);
    std::string tmp;
    int y = 0;
    int i = 0;

    if (!file.is_open())
        throw std::exception();
    while (std::getline(file, tmp)) {
        if (y == 0)
            map_size.first = tmp.size();
        for (int x = 0; tmp[x] != '\0'; x++) {
            if (tmp[x] == '#')
                _wall.emplace_back(std::make_shared<Arcade::Object>(wall, tmp[x], Arcade::Color::CYAN, (float)x, (float)y));
            else if (tmp[x] == '0') {
                if (_snake.empty() == true)
                    _snake.emplace_back(std::make_shared<Arcade::Object>(snake_right, tmp[x], Arcade::Color::GREEN, (float)x, (float)y));
                else
                    _snake.emplace_back(std::make_shared<Arcade::Object>(snake_body, tmp[x], Arcade::Color::GREEN, (float)x, (float)y));
                _obj.emplace_back(std::make_shared<Arcade::Object>(sol, ' ', Arcade::Color::GREEN, (float)x, (float)y));
            }
            if (tmp[x] == ' ')
                _obj.emplace_back(std::make_shared<Arcade::Object>(sol, tmp[x], Arcade::Color::BLACK, (float)x, (float)y));
        }
        y++;
    }
    map_size.second = y;
}

void Arcade::Snake::init_food()
{
    _obj.emplace_back(std::make_shared<Arcade::Object>(snake_food, 'F', Arcade::Color::RED, 0, 0));
}

void Arcade::Snake::init_score()
{
    _text.emplace_back(std::make_shared<Arcade::Text>("SCORE", Arcade::Color::GREEN, 920.f, 250.f));
    _text.emplace_back(std::make_shared<Arcade::Text>(std::to_string(_score), Arcade::Color::GREEN, 948.f, 300.f));
}

bool Arcade::Snake::food_check(std::pair<float, float> pos)
{
    int i = 0;
	if (pos.first == 0 && pos.second == 0)
		return false;
	while (i <= _lengthSnake - 1) {
		if (_snake[i]->getPos().first == pos.first
		    && _snake[i]->getPos().second == pos.second)
			return (false);
		i++;
	}
    for (auto tmp : _wall) {
        auto pos_wall = tmp->getPos();
        if (pos.first == pos_wall.first && pos.second == pos_wall.second)
            return false;
    }
	return (true);
}

void Arcade::Snake::gen_food()
{
    auto pos = std::make_pair(0.0, 0.0);

    _times++;
    srand(time(NULL));
    while (food_check(pos) != true) {
        pos.first = (float)(rand() % (map_size.first - 2) + 1);
        pos.second = (float)(rand() % (map_size.second - 2) + 1);
    }
    _obj.back()->setPos(pos.first, pos.second);
    if (_times % 5 == 0) {
        _obj.back()->setPath(snake_food_bonus);
        _inc = 3;
    }
    else if (_obj.back()->getPath().compare(snake_food) != 0) {
        _obj.back()->setPath(snake_food);
        _inc = 1;
    }
}

bool Arcade::Snake::is_food(float x, float y)
{
    if (_obj.back()->getPos().first == x &&
    _obj.back()->getPos().second == y) {
        _score += _inc;
        _lengthSnake++;
        gen_food();
        return true;
    }
    return false;
}

void Arcade::Snake::move(Arcade::Button dir)
{    
    if (dir == Button::PAUSE) {
        if  (!_ispause)
            _ispause = true;
        else
            _ispause = false;
    }
    if ((dir == Button::DOWN && _direction != Button::UP) ||
    (dir == Button::LEFT && _direction != Button::RIGHT) ||
    (dir == Button::RIGHT && _direction != Button::LEFT) ||
    (dir == Button::UP && _direction != Button::DOWN))
        _direction = dir;
}

void Arcade::Snake::movements()
{
    auto it = _snake.begin();
    float x = 0;
    float y = 0;

    if (_direction == Button::LEFT) {
        x = it->get()->getPos().first - 1;
        y = it->get()->getPos().second;
        _snake.front()->setPath(snake_body);
        _snake.insert(it, std::make_shared<Arcade::Object>(snake_left, '0', Arcade::Color::GREEN, (float)x, (float)y));
        if (!is_food(x, y))
            _snake.pop_back();
    }
    else if (_direction == Button::RIGHT) {
        x = it->get()->getPos().first + 1;
        y = it->get()->getPos().second;
        _snake.front()->setPath(snake_body);
        _snake.insert(it, std::make_shared<Arcade::Object>(snake_right, '0', Arcade::Color::GREEN, (float)x, (float)y));
        if (!is_food(x, y))
            _snake.pop_back();
    }
    else if (_direction == Button::UP) {
        x = it->get()->getPos().first;
        y = it->get()->getPos().second - 1;
        _snake.front()->setPath(snake_body);
        _snake.insert(it, std::make_shared<Arcade::Object>(snake_up, '0', Arcade::Color::GREEN, (float)x, (float)y));
        if (!is_food(x, y))
            _snake.pop_back();
    }
    else if (_direction == Button::DOWN) {
        x = it->get()->getPos().first;
        y = it->get()->getPos().second + 1;
        _snake.front()->setPath(snake_body);
        _snake.insert(it, std::make_shared<Arcade::Object>(snake_down, '0', Arcade::Color::GREEN, (float)x, (float)y));
        if (!is_food(x, y))
            _snake.pop_back();
    }
}

std::vector<std::shared_ptr<Arcade::IObject>> Arcade::Snake::play(Arcade::Button button)
{
    move(button);
    if (!_ispause)
        movements();
    _text.back()->setText(std::to_string(_score));
    return (allObj());
}

std::vector<std::shared_ptr<Arcade::IObject>> Arcade::Snake::allObj()
{
    std::vector<std::shared_ptr<Arcade::IObject>> obj;
    for (auto &elem : _obj)
        obj.emplace_back(elem);
    for (auto &elem : _wall)
        obj.emplace_back(elem);
    for (auto &elem : _snake)
        obj.emplace_back(elem);
    for (auto &tmp : _text)
        obj.emplace_back(tmp);
    return (obj);
}

bool Arcade::Snake::endGame()
{
    auto pos_snake = _snake.front()->getPos();
    for (auto tmp : _wall) {
        auto pos = tmp->getPos();
        if (pos.first == pos_snake.first && pos.second == pos_snake.second)
            return true;
    }
    for (int i = 1; i < _lengthSnake; i++) {
        if (pos_snake.first == _snake[i].get()->getPos().first
        && pos_snake.second == _snake[i].get()->getPos().second)
            return true;
    }
    return false;
}