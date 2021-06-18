#pragma once

#include "SFML/Graphics.hpp"
#include "Map.h"

class Dijkstra
{
public:

	Dijkstra(Map* map);

	std::vector <sf::Vector2i> generate();
	
private:

	// return minimum element from queue
	sf::Vector2i extract_min_in_queue();

	std::vector <std::vector <sf::Vector2i>> previous;
	std::vector <std::vector <int>> distance;

	std::vector <sf::Vector2i> queue;

	Map* map;
	sf::Vector2i map_size;

};

