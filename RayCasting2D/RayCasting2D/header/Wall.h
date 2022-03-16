#pragma once

//C system headers

//C++ system headers

//Other libraries headers
#include <SFML/Graphics.hpp>

//Own components headers

//Forward declarations

class Wall {
public:
	Wall();
	Wall(const sf::Vector2f& start, const sf::Vector2f& end);
	void setPos(const sf::Vector2f& start, const sf::Vector2f& end);
	void draw(sf::RenderWindow& window);
	void clear();

	sf::Vector2f getStart() const;
	sf::Vector2f getEnd() const;
private:
	sf::Vector2f _start;
	sf::Vector2f _end;
	sf::VertexArray _arr;
};

