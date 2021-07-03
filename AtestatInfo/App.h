#pragma once

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Camera.h"
#include "UserInterface.h"

#include "Dijkstra.h"
#include "AStar.h"

enum class Algorithm{Dijkstra, AStar, Count};

class App
{
public:

	App();

	// main function for the app
	bool tick();

	sf::RenderWindow* get_window();

private:

	Algorithm selection;

	sf::RenderWindow window;

	// classes required
	Map map;
	Camera camera;
	UserInterface ui;

	// renders everything on screen
	void render_tick();

	// logic for the app
	bool logic_tick();

	// framerate:
	int frame_rate;

	// logic tick speed (if it is 0, game runs as fast as possible)
	int logic_speed;

	// clocks:
	sf::Clock render_clock;
	sf::Clock logic_clock;

};

