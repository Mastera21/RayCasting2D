#include "../header/Application.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Application::init() {
	_window.create(sf::VideoMode(1000, 800), "RayCasting2D");
	_window.setFramerateLimit(60);

	for (int i = 0; i < numWalls; i++) {
		Wall wall;
		_walls.push_back(wall);
	}
	_walls[0].setPos(sf::Vector2f(150, 300), sf::Vector2f(200, 100));
	_walls[1].setPos(sf::Vector2f(500, 300), sf::Vector2f(500, 400));
	_walls[2].setPos(sf::Vector2f(700, 200), sf::Vector2f(500, 600));
	_walls[3].setPos(sf::Vector2f(300, 700), sf::Vector2f(300, 300));

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
}
void Application::handleEvent() {

}
void Application::draw() {
	_window.clear();
	for (int i = 0; i < _walls.size(); i++) {
		_walls[i].draw(_window);
	}
	_window.display();
}
