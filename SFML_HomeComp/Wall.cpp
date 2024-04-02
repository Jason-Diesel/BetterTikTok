#include "Wall.h"

Wall::Wall(sf::Vector2f pos, sf::Vector2f wh, sf::Vector2f normal)
{
	shape.setFillColor(sf::Color::Blue);
	sf::Vector2f origin = sf::Vector2f(wh.x / 2, wh.y / 2);
	shape.setOrigin(origin);
	shape.setPosition(pos);
	shape.setSize(wh);

	HitBox.setFillColor(sf::Color(255, 0, 0, 100));
	HitBox.setOrigin(origin);
	HitBox.setPosition(pos);
	HitBox.setSize(sf::Vector2f(0,0));

	this->normal = Normalize(normal);

	this->radius = getLenght(wh, sf::Vector2f(0, 0));


}

sf::Vector2f Wall::getNormal() const
{
	return this->normal;
}

sf::Vector2f Wall::getPosition() const
{
	return this->shape.getPosition();
}

sf::Vector2f Wall::getSize() const
{
	return this->shape.getSize();
}

float Wall::getRadius() const
{
	return this->radius;
}

void Wall::setColor(sf::Color color)
{
	this->shape.setFillColor(color);
}

void Wall::setHitBoxSize(float width, float height)
{
	HitBox.setSize(sf::Vector2f(width * 2, height));
	HitBox.setOrigin(HitBox.getSize().x / 2, HitBox.getSize().y / 2);
}

void Wall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(HitBox);
	target.draw(shape);
}
