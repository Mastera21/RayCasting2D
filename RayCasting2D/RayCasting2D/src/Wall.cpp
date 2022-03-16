#include "../header/Wall.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

Wall::Wall() {
	_start = sf::Vector2f(0, 0);
	_end = sf::Vector2f(0, 0);
	_arr.setPrimitiveType(sf::Lines);
}
Wall::Wall(const sf::Vector2f& start, const sf::Vector2f& end) : _start(start), _end(end) {
	_arr.append(_start);
	_arr.append(_end);
	_arr.setPrimitiveType(sf::Lines);
}
void Wall::setPos(const sf::Vector2f& start, const sf::Vector2f& end) {
	_start = start;
	_end = end;

	_arr.append(_start);
	_arr.append(_end);
}
void Wall::draw(sf::RenderWindow& window) {
	window.draw(_arr);
}
void Wall::clear() {
	_arr.clear();
}
sf::Vector2f Wall::getStart() const {
	return _start;
}
sf::Vector2f Wall::getEnd() const {
	return _end;
}
