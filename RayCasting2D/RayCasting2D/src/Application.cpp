#include "../header/Application.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Application::init() {
	_window.create(sf::VideoMode(1000, 800), "RayCasting2D");
	_window.setFramerateLimit(60);

	_shape.setRadius(10.f);
	_shape.setFillColor(sf::Color::Green);
	_shape.setPosition(_window.getSize().x / 2, _window.getSize().y / 2);
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
	_window.draw(_shape);
	_window.display();
}
