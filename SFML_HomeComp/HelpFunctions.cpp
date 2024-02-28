#include "HelpFunctions.h"

sf::Vector2f Normalize(sf::Vector2f vec)
{
    float l = getLenght(vec, sf::Vector2f(0,0));
    return sf::Vector2f(vec.x / l, vec.y / l);
}

float getLenght(const sf::Vector2f& a, const sf::Vector2f& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
