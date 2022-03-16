#pragma once

//C system headers

//C++ system headers

//Other libraries headers
#include <SFML/Graphics.hpp>

//Own components headers

//Forward declarations

#define PI 3.14f

class Line {
public:
	Line() = default;
	Line(const float& x, const float& y);
	void reset(const sf::Vector2f& mousePos);
	void checkForWall(const sf::Vector2f& startPosWall, const sf::Vector2f& endPosWall, const sf::Vector2f& mousePos);
	float position(const sf::Vector2f& x1, const sf::Vector2f& x2, const sf::Vector2f& x3, const sf::Vector2f& x4);
	sf::Vector2f getPositionPoint() const;
private:
	sf::Vector2f _positionPoint;
	sf::Vector2f _relativePositionPoint;
};