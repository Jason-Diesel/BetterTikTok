#include "BounceBall.h"
#include <iostream>

BounceBall::BounceBall(sf::Vector2f pos, sf::Vector2f wh, sf::Vector2f vel)
{
	shape.setFillColor(sf::Color::Red);
	shape.setSize(wh);
	shape.setOrigin(wh.x / 2, wh.y / 2);
	shape.setPosition(pos);
	this->velocity = vel;
	this->lastPosition = pos;
	radius = sqrt(((wh.x / 2) * (wh.x / 2) + (wh.y / 2) * (wh.y / 2)));
	color.r = c[0];
	color.g = 0;
	color.b = 0;
}

void BounceBall::update(float dt)
{
	c[0] += dt * 1 * 0.9;
	c[1] += dt * 3 * 0.9;
	c[2] += dt * 7 * 0.9;

	color.r = static_cast<int>((sin(c[0]) + 1.0) * 127.5);
	color.g = static_cast<int>((sin(c[1]) + 1.0) * 127.5);
	color.b = static_cast<int>((sin(c[2]) + 1.0) * 127.5);
	shape.setFillColor(color);
	move(velocity * dt);
	//move(sf::Vector2f(0, 240));
}

void BounceBall::move(sf::Vector2f dir)
{
	this->lastPosition = shape.getPosition();
	shape.move(dir);
}

void BounceBall::checkCollisionWithWalls(std::vector<Wall>& walls, sf::Window& win)
{
	for (int i = 0; i < walls.size(); i++)
	{
		//The Box
		float wallXMin = walls[i].getPosition().x - (walls[i].getSize().x / 2) - (this->shape.getSize().x/2);
		float wallXMax = walls[i].getPosition().x + (walls[i].getSize().x / 2) + (this->shape.getSize().x/2);

		float wallYMin = walls[i].getPosition().y - (walls[i].getSize().y / 2) - (this->shape.getSize().y/2);
		float wallYMax = walls[i].getPosition().y + (walls[i].getSize().y / 2) + (this->shape.getSize().y/2);

		//The Ray
		sf::Vector2f direction = Normalize(shape.getPosition() - this->lastPosition);
		if (direction.x == 0)
		{
			direction.x += 0.0001f;
		}
		if (direction.y == 0)
		{
			direction.y += 0.0001f;
		}
		sf::Vector2f origin = this->lastPosition;
		const float maxLenght = getLenght(shape.getPosition(), this->lastPosition);
		
		float txMin = (wallXMin - origin.x) / direction.x;
		float txMax = (wallXMax - origin.x) / direction.x;
		if (txMin > txMax) std::swap(txMin, txMax);

		float tyMin = (wallYMin - origin.y) / direction.y;
		float tyMax = (wallYMax - origin.y) / direction.y;
		if (tyMin > tyMax) std::swap(tyMin, tyMax);

		if ((txMin > tyMax) || (tyMin > txMax)) { continue; };

		if (tyMin > txMin) txMin = tyMin;
		if (tyMax < txMax) txMax = tyMax;

		float T = std::max(txMin, tyMin);
		if (T <= maxLenght && T > 0)
		{
			//calculate normal
			sf::Vector2f point = this->lastPosition + direction * T;
			sf::Vector2f nNormal;
			//do shit in case of floating point error 
			if (abs(wallXMin - point.x) < 0.0001)
			{
				nNormal = sf::Vector2f(1,0);
			}
			else if (abs(wallXMax - point.x) < 0.0001)
			{
				nNormal = sf::Vector2f(-1, 0);
			}
			else if (abs(wallYMin - point.y) < 0.0001)
			{
				nNormal = sf::Vector2f(0, 1);
			}
			else if (abs(wallYMax - point.y) < 0.0001)
			{
				nNormal = sf::Vector2f(0, -1);
			}
			else
			{
				std::cout << "error" << std::endl;
			}
			//set position
			shape.setPosition(this->lastPosition + direction * T);
			//change velocity
			velocity = velocity - (2 * DotProduct(velocity, nNormal)) * nNormal;
		}
	}
}

sf::Vector2f BounceBall::getPosition()
{
	return this->shape.getPosition();
}

void BounceBall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
}

