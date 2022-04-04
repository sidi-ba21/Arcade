/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"

static const char snake_map[] = "../../assets/snake/map.txt";
static const char snake_down[] = "../../assets/snake/head_down.png";
static const char snake_up[] = "../../assets/snake/head_up.png";
static const char snake_left[] = "../../assets/snake/head_left.png";
static const char snake_right[] = "../../assets/snake/head_right.png";
static const char snake_body[] = "../../assets/snake/snake_body.png";
static const char snake_food[] = "../../assets/snake/snake_food.png";
static const char wall[] = "../../assets/snake/wall.png";
static const char sol[] = "../../assets/snake/SOL.png";

Arcade::Snake::Snake()
{
    _lengthSnake = 2;
    init_map();
    init_food();
    gen_food();
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
            map_size.first = tmp.size() + 1;
        for (int x = 0; tmp[x] != '\0'; x++) {
            if (tmp[x] == '#')
                _obj.emplace_back(std::make_shared<Arcade::Object>(wall, tmp[x], Arcade::Color::CYAN, (float)x, (float)y));
            else if (tmp[x] == '0') {
                if (_snake.empty() == true)
                    _snake.emplace_back(std::make_shared<Arcade::Object>(snake_right, tmp[x], Arcade::Color::GREEN, (float)x, (float)y));
                else
                    _snake.emplace_back(std::make_shared<Arcade::Object>(snake_body, tmp[x], Arcade::Color::GREEN, (float)x, (float)y));
            }
        }
        y++;
    }
    map_size.second = y;
}

void Arcade::Snake::init_food()
{
    _obj.emplace_back(std::make_shared<Arcade::Object>(snake_food, 'F', Arcade::Color::RED, 0, 0));
}

bool Arcade::Snake::food_check(std::pair<float, float> pos)
{
    int i = 0;
	if (pos.first == 0 && pos.second == 0)
		return false;
	while (i <= _lengthSnake - 1)
	{
		if (_snake[i]->getPos().first == pos.first
		    && _snake[i]->getPos().second == pos.second)
			return (false);
		i++;
	}
	return (true);
}

void Arcade::Snake::gen_food()
{
    auto pos = std::make_pair(0.0, 0.0);

    srand(time(NULL));
    while (food_check(pos) != true) {
        pos.first = (float)(rand() % map_size.first + 1);
        pos.second = (float)(rand() % map_size.second + 1);
    }
    _obj.end()->get()->setPos(pos.first, pos.second);
}

void Arcade::Snake::eat_food(Arcade::Move direction)
{
    auto it = _snake.begin();
    float x = 0;
    float y = 0;

    if (direction == Move::left) {
        x = it->get()->getPos().first - 1;
        y = it->get()->getPos().second;
        _snake.front()->setPath(snake_body);
        _snake.insert(it, std::make_shared<Arcade::Object>(snake_left, "0", Arcade::Color::GREEN, (float)x, (float)y));
    }
    else if (direction == Move::right) {
        x = it->get()->getPos().first + 1;
        y = it->get()->getPos().second;
        _snake.front()->setPath(snake_body);
        _snake.insert(it, std::make_shared<Arcade::Object>(snake_right, "0", Arcade::Color::GREEN, (float)x, (float)y));
    }
    else if (direction == Move::up) {
        x = it->get()->getPos().first;
        y = it->get()->getPos().second - 1;
        _snake.front()->setPath(snake_body);
        _snake.insert(it, std::make_shared<Arcade::Object>(snake_up, "0", Arcade::Color::GREEN, (float)x, (float)y));
    }
    else if (direction == Move::down) {
        x = it->get()->getPos().first;
        y = it->get()->getPos().second + 1;
        _snake.front()->setPath(snake_body);
        _snake.insert(it, std::make_shared<Arcade::Object>(snake_down, "0", Arcade::Color::GREEN, (float)x, (float)y));
    }
}

void Arcade::Snake::movements(Arcade::Move direction)
{
    auto it = _snake.begin();
    float x = 0;
    float y = 0;

    if (direction == Move::left) {
        x = it->get()->getPos().first - 1;
        y = it->get()->getPos().second;
        _snake.front()->setPath(snake_body);
        _snake.insert(it, std::make_shared<Arcade::Object>(snake_left, "0", Arcade::Color::GREEN, (float)x, (float)y));
        _snake.pop_back();
    }
    else if (direction == Move::right) {
        x = it->get()->getPos().first + 1;
        y = it->get()->getPos().second;
        _snake.front()->setPath(snake_body);
        _snake.insert(it, std::make_shared<Arcade::Object>(snake_right, "0", Arcade::Color::GREEN, (float)x, (float)y));
        _snake.pop_back();
    }
    else if (direction == Move::up) {
        x = it->get()->getPos().first;
        y = it->get()->getPos().second - 1;
        _snake.front()->setPath(snake_body);
        _snake.insert(it, std::make_shared<Arcade::Object>(snake_up, "0", Arcade::Color::GREEN, (float)x, (float)y));
        _snake.pop_back();
    }
    else if (direction == Move::down) {
        x = it->get()->getPos().first;
        y = it->get()->getPos().second + 1;
        _snake.front()->setPath(snake_body);
        _snake.insert(it, std::make_shared<Arcade::Object>(snake_down, "0", Arcade::Color::GREEN, (float)x, (float)y));
        _snake.pop_back();
    }
}

void Arcade::Snake::play()
{

}

bool Arcade::Snake::endGame()
{
    
}