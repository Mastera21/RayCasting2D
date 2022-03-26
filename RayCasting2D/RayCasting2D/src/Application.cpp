#include "../header/Application.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Application::init() {
	_window.create(sf::VideoMode(1000, 800), "RayCasting2D");
	_window.setFramerateLimit(60);

	_walls.reserve(numWalls);
	for (int i = 0; i < numWalls; i++) {
		Wall wall;
		_walls.emplace_back(wall);
	}
	_walls[0].setPos(sf::Vector2f(150, 300), sf::Vector2f(200, 100));
	_walls[1].setPos(sf::Vector2f(500, 300), sf::Vector2f(500, 400));
	_walls[2].setPos(sf::Vector2f(700, 200), sf::Vector2f(500, 600));
	_walls[3].setPos(sf::Vector2f(300, 700), sf::Vector2f(300, 300));

	_rays.reserve(lines);
	const float step = 1.f / lines;
	for (float i = 0; i < lines; i += step) {
		const float x = cos(i);
		const float y = sin(i);
		_rays.emplace_back(x, y);
	}

	_rayLines.setPrimitiveType(sf::PrimitiveType::Lines);
	_rayLines.resize(2);
	_rayLines[0].color = sf::Color(255, 255, 255, 10);
	_rayLines[1].color = sf::Color(255, 255, 255, 10);

	return EXIT_SUCCESS;
}
void Application::Irun() {
	main();
}
void Application::main() {
	if (EXIT_SUCCESS != init()) {
		std::cerr << "Error, init() failed\n";
		return;
	}
	while (_window.isOpen()) {
		sf::Event e;
		update(e);
		draw();
	}
	deinit();
}
void Application::update(sf::Event& e) {
	while (_window.pollEvent(e)) {
		if (requestForExit(e)) {
			_window.close();
			break;
		}
	}
	handleEvent();
}
bool Application::requestForExit(sf::Event& e) {
	switch (e.type) {
	case sf::Event::Closed:
		_window.close();
		return true;
		break;
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			_window.close();
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}
void Application::deinit() {
	_window.close();
	_walls.clear();
	_rays.clear();
	_rayLines.clear();
}
inline void Application::handleEvent() {
	_mousePos = sf::Vector2f(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y);
	_rayLines[0].position = _mousePos;
}
void Application::drawRays() {
	for (int i = 0; i < _rays.size(); i++) {
		_rays[i].reset(_mousePos);
		for (int j = 0; j < _walls.size(); j++) {
			_rays[i].checkForWall(_walls[j].getStart(), _walls[j].getEnd(), _mousePos);
		}
		_rayLines[1].position = _rays[i].getPositionPoint();
		_window.draw(_rayLines);
	}
}
void Application::draw() {
	_window.clear();
	drawRays();
	for (int i = 0; i < _walls.size(); i++) {
		_walls[i].draw(_window);
	}
	_window.display();
}
