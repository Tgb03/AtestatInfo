#include "Random.h"

Random::Random(Map* map) {

	// get size
	Random::map_size = map->get_size();

	for (int i = 0; i < Random::map_size.x; ++i) {
		std::vector <int> temp1;
		std::vector <sf::Vector2i> temp2;
		for (int j = 0; j < Random::map_size.y; ++j) {
			temp1.push_back(Random::map_size.x * Random::map_size.y + 1); // infinite
			temp2.push_back({ -1, -1 }); // null

			if (map->get_walkable({ i, j }))
				Random::queue.push_back({ i, j });
		}

		Random::distance.push_back(temp1);
		Random::previous.push_back(temp2);
	}

	Random::distance[map->get_start().x][map->get_start().y] = 0;

	Random::map = map;
}

std::vector <sf::Vector2i> Random::generate() {
	// Euclid for Random

	sf::Vector2i pos = { -1, -1 };

	while (Random::queue.size() && !Random::map->is_end(pos)) {
		pos = Random::extract_random_in_queue();
		if (pos == sf::Vector2i(-1, -1))
			return {};

		auto neighbours = Random::map->get_adjacent(pos);

		for (auto neighbour : neighbours) {
			int tempDistance = Random::distance[pos.x][pos.y] + 1;
			if (tempDistance < Random::distance[neighbour.x][neighbour.y]) {
				Random::distance[neighbour.x][neighbour.y] = tempDistance;
				Random::previous[neighbour.x][neighbour.y] = pos;
			}
		}
	}

	// extract path from map
	std::vector <sf::Vector2i> path;

	while (pos != sf::Vector2i(-1, -1)) {
		path.push_back(pos);
		pos = Random::previous[pos.x][pos.y];
	}

	//std::cout << path.size() << " ";
	return path;
}

sf::Vector2i Random::extract_random_in_queue()
{
	std::vector <sf::Vector2i> valid;

	for (auto elem : Random::queue)
		if (Random::distance[elem.x][elem.y] != Random::map_size.x * Random::map_size.y + 1)
			valid.push_back(elem);

	if (valid.size() == 0) return { -1, -1 };

	int id = std::rand() % valid.size();

	sf::Vector2i pos = valid.at(id);

	// before returning remove from queue value
	Random::queue.erase(std::remove(Random::queue.begin(), Random::queue.end(), pos), Random::queue.end());

	return pos;
}
