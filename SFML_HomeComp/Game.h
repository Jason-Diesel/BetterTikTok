#pragma once
#include "GameState.h"
#include "Wall.h"
#include "BounceBall.h"

class Game : public GameState
{
public:
	Game();
	virtual ~Game();
	State update(float dt);
	void render();
private:
	BounceBall bounceRec;
	std::vector<Wall> walls;
};
