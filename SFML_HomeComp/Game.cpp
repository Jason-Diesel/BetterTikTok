#include "Game.h"

Game::Game():
bounceRec(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(50,50), sf::Vector2f(700/2, 650/2)),
pressed(false),
stopDrawing(false)
{
	//TODO : change these so it's right with bounceRec
	walls.push_back(Wall(sf::Vector2f(0, HEIGHT/2), sf::Vector2f(20, HEIGHT), sf::Vector2f(1,0)));
	walls.push_back(Wall(sf::Vector2f(WIDTH, HEIGHT/2), sf::Vector2f(20, HEIGHT), sf::Vector2f(-1, 0)));
	walls.push_back(Wall(sf::Vector2f(WIDTH/2, 0), sf::Vector2f(WIDTH, 20), sf::Vector2f(0, 1)));

	walls.push_back(Wall(sf::Vector2f(WIDTH/4 - 20, HEIGHT - 200 - 12.5), sf::Vector2f(WIDTH/2 - 50, 25), sf::Vector2f(0, -1)));
	walls.push_back(Wall(sf::Vector2f(WIDTH/4 * 3 + 20, HEIGHT - 200 - 12.5), sf::Vector2f(WIDTH / 2 - 50, 25), sf::Vector2f(0, -1)));

	walls.push_back(Wall(sf::Vector2f(WIDTH / 2, HEIGHT), sf::Vector2f(WIDTH, 20), sf::Vector2f(0, 1)));
}

Game::~Game()
{
}

State Game::update(float dt)
{
	if (done)
	{
		return State::EXIT;
	}
	//Move Check BounceRec
	if (pressed)
	{
		bounceRec.update(dt);
		bounceRec.checkCollisionWithWalls(walls, window);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		pressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		stopDrawing = true;
	}
	else
	{
		stopDrawing = false;
	}

	return State::NO_CHANGE;
}

void Game::render()
{
	if (!pressed)
	{
		window.clear(sf::Color::Black);
	}

	if (!stopDrawing)
	{
		for (int i = 0; i < walls.size(); i++)
		{
			window.draw(walls[i]);
		}
		window.draw(bounceRec);

		window.display();
	}
}

