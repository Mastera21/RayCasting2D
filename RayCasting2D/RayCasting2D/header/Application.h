#pragma once
//C system headers

//C++ system headers
#include <vector>
//Other libraries headers
 
//Own components headers
#include "../header/Wall.h"
//Forward declarations

#define numWalls 4

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
private:
	std::vector<Wall> _walls{};

};

