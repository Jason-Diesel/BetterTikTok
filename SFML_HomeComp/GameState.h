#pragma once
#include <SFML/Graphics.hpp>
enum class State{ MENU, NO_CHANGE, EXIT, GAME, GAME_OVER, NEW_START, HIGHSCORE_LIST, CREDITS };

class GameState {
private:

protected:
	static const int WIDTH = 1920;
	static const int HEIGHT = 1080;
	//static const int WIDTH = 1080;
	//static const int HEIGHT = 1920;
	sf::RenderWindow window;
	bool done = false;
public:
	GameState(std::string title = "Game");
	virtual ~GameState();
	virtual State update(float dt) = 0;
	virtual void render() = 0;
	virtual void handleEvents();
};