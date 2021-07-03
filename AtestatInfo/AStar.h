#pragma once

#include "SFML/Graphics.hpp"
#include "Map.h"

class AStar
{
public:

	AStar(Map* map);

	std::vector <sf::Vector2i> generate();

private:

	std::vector <sf::Vector2i> trace_path();

	// return minimum element from queue
	sf::Vector2i extract_min_in_queue();

	std::vector <std::vector <sf::Vector2i>> previous;

	std::vector <sf::Vector2i> open_list;
	std::vector <sf::Vector2i> closed_list;

	std::vector <std::vector <int>> f, g, h;

	Map* map;
	sf::Vector2i map_size;

};


