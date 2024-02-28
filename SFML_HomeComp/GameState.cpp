#include "GameState.h"

GameState::GameState(std::string title) :
	window(sf::VideoMode(WIDTH, HEIGHT), title)
{
}

GameState::~GameState()
{
}

void GameState::handleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			done = true;
		}
	}
}
