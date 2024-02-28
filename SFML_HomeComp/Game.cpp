#include "Game.h"

Game::Game():
bounceRec(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(50,50), sf::Vector2f(0, 10))
{
	//TODO : change these so it's right with bounceRec
	//walls.push_back(Wall(sf::Vector2f(0, HEIGHT/2), sf::Vector2f(20, HEIGHT)));
	//walls.push_back(Wall(sf::Vector2f(WIDTH, HEIGHT/2), sf::Vector2f(20, HEIGHT)));
	//walls.push_back(Wall(sf::Vector2f(WIDTH/2, 0), sf::Vector2f(WIDTH, 20)));
	//walls.push_back(Wall(sf::Vector2f(WIDTH/4 - 20, HEIGHT - 200), sf::Vector2f(WIDTH/2 - 50, 50)));
	//walls.push_back(Wall(sf::Vector2f(WIDTH/4 * 3 + 20, HEIGHT - 200), sf::Vector2f(WIDTH / 2 - 50, 50)));

	//Test wall
	walls.push_back(Wall(sf::Vector2f(WIDTH/2, 600), sf::Vector2f(30,30)));

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
	static bool pressed = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && !pressed)
	{
		pressed = true;
		bounceRec.update(dt);
		bounceRec.checkCollisionWithWalls(walls);
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		pressed = false;
	}

	return State::NO_CHANGE;
}

void Game::render()
{
	window.clear();

	for (int i = 0; i < walls.size(); i++)
	{
 		window.draw(walls[i]);
	}
	window.draw(bounceRec);

	window.display();
}

