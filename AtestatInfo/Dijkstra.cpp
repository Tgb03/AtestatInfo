#include "Dijkstra.h"

//#include <iostream>

Dijkstra::Dijkstra(Map* map) {
	
	// get size
	Dijkstra::map_size = map->get_size();

	for (int i = 0; i < Dijkstra::map_size.x; ++i) {
		std::vector <int> temp1;
		std::vector <sf::Vector2i> temp2;
		for (int j = 0; j < Dijkstra::map_size.y; ++j) {
			temp1.push_back(Dijkstra::map_size.x * Dijkstra::map_size.y + 1); // infinite
			temp2.push_back({ -1, -1 }); // null

			if (map->get_walkable({i, j}))
				Dijkstra::queue.push_back({ i, j });
		}

		Dijkstra::distance.push_back(temp1);
		Dijkstra::previous.push_back(temp2);
	}

	Dijkstra::distance[map->get_start().x][map->get_start().y]= 0;

	Dijkstra::map = map;

	Dijkstra::map->reset_search();
}

std::vector <sf::Vector2i> Dijkstra::generate() {
	// Euclid for Dijkstra

	sf::Vector2i pos = { -1, -1 };

	while (Dijkstra::queue.size() && !Dijkstra::map->is_end(pos)) {
		pos = Dijkstra::extract_min_in_queue();
		auto neighbours = Dijkstra::map->get_adjacent(pos);

		for (auto neighbour : neighbours) {
			int tempDistance = Dijkstra::distance[pos.x][pos.y] + 1;
			if (tempDistance < Dijkstra::distance[neighbour.x][neighbour.y]) {
				Dijkstra::distance[neighbour.x][neighbour.y] = tempDistance;
				Dijkstra::previous[neighbour.x][neighbour.y] = pos;
			}
		}
	}
	 
	// extract path from map
	std::vector <sf::Vector2i> path;

	while (pos != sf::Vector2i(-1, -1)) {
		path.push_back(pos);
		pos = Dijkstra::previous[pos.x][pos.y];
	}

	//std::cout << path.size() << " ";
	return path;
}

sf::Vector2i Dijkstra::extract_min_in_queue()
{

	float min_value = std::numeric_limits<float>::infinity();
	sf::Vector2i min_pos = { -1, -1 };

	for (auto elem : Dijkstra::queue)
		if (Dijkstra::distance[elem.x][elem.y] < min_value) {
			min_value = Dijkstra::distance[elem.x][elem.y];
			min_pos = elem;
		}

	// before returning remove from queue value
	Dijkstra::queue.erase(std::remove(Dijkstra::queue.begin(), Dijkstra::queue.end(), min_pos), Dijkstra::queue.end());

	return min_pos;
}
