#pragma once
#include <SFML/Graphics.hpp>
#include "HelpFunctions.h"

class Wall : public sf::Drawable
{
public:
	Wall(sf::Vector2f pos, sf::Vector2f wh, sf::Vector2f normal = sf::Vector2f(0,1));
	sf::Vector2f getNormal() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;
	float getRadius() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::RectangleShape shape;
	float radius;
	sf::Vector2f normal;
};