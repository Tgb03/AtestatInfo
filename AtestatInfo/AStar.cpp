#include "AStar.h"

//#include <iostream>

AStar::AStar(Map* map) {
	
	AStar::map = map;

	for (int i = 0; i < AStar::map->get_size().x; ++i) {
		std::vector <int> val;
		std::vector <sf::Vector2i> vec;

		for (int j = 0; j < AStar::map->get_size().y; ++j) {
			val.push_back(0);
			vec.push_back({ -1, -1 });
		}

		AStar::previous.push_back(vec);
		
		AStar::f.push_back(val);
		AStar::g.push_back(val);
		AStar::h.push_back(val);
	}

}

std::vector <sf::Vector2i> AStar::generate() {
	 
	auto start = AStar::map->get_start();
	auto end = AStar::map->get_end();

	AStar::open_list.push_back(start);

	while (AStar::open_list.size()) {

		auto q = AStar::extract_min_in_queue();

		auto adjacent = AStar::map->get_adjacent(q);

		for (auto elem : adjacent) {
			
			// test if neighbour is the end
			if (AStar::map->is_end(elem)) {
				AStar::previous[elem.x][elem.y] = q;
				
				return AStar::trace_path();
			}
			
			int newG, newF;

			newG = AStar::g[q.x][q.y] + 1;
			
			if (AStar::h[elem.x][elem.y] == 0)
				AStar::h[elem.x][elem.y] = std::abs(end.x - elem.x) + std::abs(end.y - elem.y);
			
			newF = newG + AStar::h[elem.x][elem.y];

			if (!(newF > AStar::f[elem.x][elem.y] && (std::find(AStar::open_list.begin(), AStar::open_list.end(), elem) != AStar::open_list.end() || std::find(AStar::closed_list.begin(), AStar::closed_list.end(), elem) != AStar::closed_list.end()))) {

				AStar::g[elem.x][elem.y] = newG;
				AStar::f[elem.x][elem.y] = newF;

				AStar::previous[elem.x][elem.y] = q;

				AStar::open_list.erase(std::remove(AStar::open_list.begin(), AStar::open_list.end(), elem), AStar::open_list.end());

				AStar::open_list.push_back(elem);
			}

		}

		AStar::closed_list.push_back(q);
	}

	return AStar::trace_path();

}

std::vector<sf::Vector2i> AStar::trace_path()
{
	// extract path from map
	std::vector <sf::Vector2i> path;

	auto pos = AStar::map->get_end();

	while (pos != sf::Vector2i(-1, -1)) {
		path.push_back(pos);
		pos = AStar::previous[pos.x][pos.y];

		//std::cout << pos.x << " " << pos.y << "\n";
	}

	//std::cout << path.size() << " ";
	return path;
}

sf::Vector2i AStar::extract_min_in_queue()
{

	float min_value = std::numeric_limits<float>::infinity();
	sf::Vector2i min_pos = { -1, -1 };

	for (auto elem : AStar::open_list)
		if (AStar::f[elem.x][elem.y] < min_value) {
			min_value = AStar::f[elem.x][elem.y];
			min_pos = elem;
		}

	// before returning remove from queue value
	AStar::open_list.erase(std::remove(AStar::open_list.begin(), AStar::open_list.end(), min_pos), AStar::open_list.end());

	return min_pos;
}
