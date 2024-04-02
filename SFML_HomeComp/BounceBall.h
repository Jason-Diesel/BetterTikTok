#pragma once
#include <SFML/Graphics.hpp>
#include "HelpFunctions.h"
#include "Wall.h"

class BounceBall : public sf::Drawable
{
public:
	BounceBall(sf::Vector2f pos, sf::Vector2f wh, sf::Vector2f vel);
	void update(float dt);
	void move(sf::Vector2f dir);
	void checkCollisionWithWalls(std::vector<Wall>& walls, sf::Window& win);
	sf::Vector2f getPosition();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::RectangleShape shape;
	double c[3] = { 0, 0, 0 };
	sf::Color color;
	//For testing with shit
	sf::Vector2f lastPosition;
	sf::Vector2f velocity;

	float radius;
};