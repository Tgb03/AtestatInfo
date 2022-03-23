#include "GreedyBestFirstSearch.h"

GreedyBestFirstSearch::GreedyBestFirstSearch(Map* map) {

	// get size
	GreedyBestFirstSearch::map_size = map->get_size();

	for (int i = 0; i < GreedyBestFirstSearch::map_size.x; ++i) {
		std::vector <int> temp1;
		std::vector <sf::Vector2i> temp2;
		for (int j = 0; j < GreedyBestFirstSearch::map_size.y; ++j) {
			temp1.push_back(-1); // null
			temp2.push_back({ -1, -1 }); // null

		}

		GreedyBestFirstSearch::distance.push_back(temp1);
		GreedyBestFirstSearch::previous.push_back(temp2);
	}

	GreedyBestFirstSearch::distance[map->get_start().x][map->get_start().y] = 0;

	GreedyBestFirstSearch::map = map;

	GreedyBestFirstSearch::map->reset_search();
}

std::vector <sf::Vector2i> GreedyBestFirstSearch::generate() {
	// euclid for Best First Search:
	auto Start = map->get_start();
	auto End = map->get_end();

	priorityQueue.push_back(Start);

	while (priorityQueue.size() > 0)
	{
		auto U = GreedyBestFirstSearch::extract_min_in_queue();

		if (map->is_end(U))
			break;
		else {
			auto neighbours = map->get_adjacent(U);

			for (auto neighbor : neighbours)
				if (distance[neighbor.x][neighbor.y] == -1) {
					distance[neighbor.x][neighbor.y] = std::abs(neighbor.x - End.x) + std::abs(neighbor.y - End.y);

					previous[neighbor.x][neighbor.y] = U;

					priorityQueue.push_back(neighbor);
				}
		}
	}

	// extract path from map
	std::vector <sf::Vector2i> path;

	auto pos = End;

	while (pos != sf::Vector2i(-1, -1)) {
		path.push_back(pos);
		pos = GreedyBestFirstSearch::previous[pos.x][pos.y];
	}

	//std::cout << path.size() << " ";
	return path;
}

sf::Vector2i GreedyBestFirstSearch::extract_min_in_queue()
{

	float min_value = std::numeric_limits<float>::infinity();
	sf::Vector2i min_pos = { -1, -1 };

	for (auto elem : GreedyBestFirstSearch::priorityQueue)
		if (GreedyBestFirstSearch::distance[elem.x][elem.y] < min_value) {
			min_value = GreedyBestFirstSearch::distance[elem.x][elem.y];
			min_pos = elem;
		}

	// before returning remove from queue value
	GreedyBestFirstSearch::priorityQueue.erase(std::remove(GreedyBestFirstSearch::priorityQueue.begin(), GreedyBestFirstSearch::priorityQueue.end(), min_pos), GreedyBestFirstSearch::priorityQueue.end());

	return min_pos;
}