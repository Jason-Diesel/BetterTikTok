#include "BounceBall.h"
#include <iostream>

BounceBall::BounceBall(sf::Vector2f pos, sf::Vector2f wh, sf::Vector2f vel)
{
	shape.setFillColor(sf::Color::Red);
	shape.setSize(wh);
	shape.setOrigin(wh.x / 2, wh.y / 2);
	shape.setPosition(pos);
	this->velocity = vel;

	radius = sqrt(((wh.x / 2) * (wh.x / 2) + (wh.y / 2) * (wh.y / 2)));
}

void BounceBall::update(float dt)
{
	//move(velocity * dt);
	move(sf::Vector2f(0, 240));
}

void BounceBall::move(sf::Vector2f dir)
{
	this->lastPosition = shape.getPosition();
	shape.move(dir);
}

void BounceBall::checkCollisionWithWalls(const std::vector<Wall>& walls)
{
	for (int i = 0; i < walls.size(); i++)
	{
		float l1 = getLenght(walls[i].getPosition(), shape.getPosition());
		sf::Vector2f contact_normal(0, 0);
		sf::Vector2f contanct_point(0, 0);

		sf::Vector2f rayDirection = Normalize(shape.getPosition() - lastPosition);
		sf::Vector2f invdir(1.0f / rayDirection.x, 1.0f / rayDirection.y);
		sf::Vector2f t_near((walls[i].getPosition() - lastPosition).x * invdir.x, (walls[i].getPosition() - lastPosition).y * invdir.y);
		sf::Vector2f t_far(walls[i].getPosition() + walls[i].getSize() - lastPosition)* invdir;
	}
}

void BounceBall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
}

