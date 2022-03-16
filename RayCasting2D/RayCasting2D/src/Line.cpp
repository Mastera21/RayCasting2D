#include "../header/Line.h"
//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

Line::Line(const float& x, const float& y) {
	_relativePositionPoint = sf::Vector2f(x, y) * 3000.f;
}
void Line::reset(const sf::Vector2f& mousePos) {
	_positionPoint = mousePos + _relativePositionPoint;
}
float Line::position(const sf::Vector2f& x1, const sf::Vector2f& x2, const sf::Vector2f& x3, const sf::Vector2f& x4) {
	return (x1.x - x2.x) * (x3.y - x4.y) - (x1.y - x2.y) * (x3.x - x4.x);
}
void Line::checkForWall(const sf::Vector2f& startPosWall, const sf::Vector2f& endPosWall, const sf::Vector2f& mousePos) {
	const sf::Vector2f x1 = mousePos;
	const sf::Vector2f x2 = _positionPoint;
	const sf::Vector2f x3 = startPosWall;
	const sf::Vector2f x4 = endPosWall;

	const float distance = position(x1, x2, x3, x4);

	if (distance == 0) {
		return;
	}

	const float t = ((x1.x - x3.x) * (x3.y - x4.y) - (x1.y - x3.y) * (x3.x - x4.x)) / distance;
	const float u = -((x1.x - x2.x) * (x1.y - x3.y) - (x1.y - x2.y) * (x1.x - x3.x)) / distance;

	if (t > 0 && t < 1 && u > 0 && u < 1) {
		_positionPoint.x = x1.x + t * (x2.x - x1.x);
		_positionPoint.y = x1.y + t * (x2.y - x1.y);
	}
}
sf::Vector2f Line::getPositionPoint() const {
	return _positionPoint;
}