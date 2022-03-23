#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "Map.h"
#include "Camera.h"
#include "UserInterface.h"
#include "TextTab.h"
#include "AlgorithmDescription.h"
#include "Button.h"

#include "Dijkstra.h"
#include "AStar.h"
#include "Random.h"
#include "GreedyBestFirstSearch.h"

enum class Algorithm{Dijkstra, AStar, GreedyBestFirstSearch, Random, Count};

class App
{
public:

	App();

	// main function for the app
	bool tick();

	sf::RenderWindow* get_window();
	std::string getAlgorithmString();

private:
	
	std::vector <std::string> AlgorithmStrings;
	std::vector <TextTab> TextTabs;
	std::vector <Button> Buttons;

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

	// run pathfinder algorithm
	void pathfinder();

	// change algorithm:
	void change_algorithm();

	// framerate:
	int frame_rate;

	// logic tick speed (if it is 0, game runs as fast as possible)
	int logic_speed;

	// clocks:
	sf::Clock render_clock;
	sf::Clock logic_clock;

};

