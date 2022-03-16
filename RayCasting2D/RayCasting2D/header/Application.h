#pragma once

//C system headers

//C++ system headers
 
//Other libraries headers
#include <SFML/Graphics.hpp>
//Own components headers

//Forward declarations

class Application{
public:
	Application(const Application&) = delete;
	static Application& Get() {
		static Application instance;
		return instance;
	}
	static void run() {
		Get().Irun();
	}
private:
	Application() = default;
	int32_t init();
	void deinit();
	void update(sf::Event& e);
	void main();
	void Irun();
	void handleEvent();
	void draw();
	bool requestForExit(sf::Event& e);
private:
	sf::RenderWindow _window;
	sf::CircleShape _shape;
};

