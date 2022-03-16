#pragma once
//C system headers

//C++ system headers
#include <vector>
//Other libraries headers
 
//Own components headers
#include "../header/Wall.h"
#include "../header/Line.h"
//Forward declarations

#define numWalls 4
#define lines 100

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
	void drawRays();
	bool requestForExit(sf::Event& e);
private:
	sf::RenderWindow _window;
	sf::Vector2f _mousePos;
	sf::VertexArray _rayLines;
private:
	std::vector<Wall> _walls{};
	std::vector<Line> _rays{};
};

