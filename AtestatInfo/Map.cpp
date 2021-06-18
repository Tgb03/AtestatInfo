#include "Map.h"

#include "Camera.h"
#include "App.h"

#include <iostream>

Map::Map(sf::Vector2i size, App* app) : shape(sf::Quads, 4)
{
	int i, j;

	// add elements to the tiles vector
	for (i = 0; i < size.x; ++i)
		for (j = 0; j < size.y; ++j) {
			Map::tiles.push_back(true);
			Map::parsed.push_back(false);
		}

	// remember sizes:
	Map::size = size;

	Map::app = app;

	Map::end = {size.x - 1, size.y - 1};
}

sf::Vector2i Map::get_size()
{
	return Map::size;
}

bool Map::get_walkable(sf::Vector2i pos)
{
	auto vector_pos = convert_pos(pos);

	if (vector_pos < 0 || vector_pos > Map::tiles.size() - 1)
		return false;

	return Map::tiles.at(vector_pos);
}

std::vector<sf::Vector2i> Map::get_adjacent(sf::Vector2i pos)
{
	std::vector<sf::Vector2i> result;

	if (pos.x > 0)
		result.push_back({ pos.x - 1, pos.y });
	if (pos.x < Map::size.x - 1)
		result.push_back({ pos.x + 1, pos.y });
	if (pos.y > 0)
		result.push_back({ pos.x, pos.y - 1 });
	if (pos.y < Map::size.y - 1)
		result.push_back({ pos.x, pos.y + 1 });

	return result;
}

int Map::convert_pos(sf::Vector2i pos)
{
	return pos.x + pos.y * Map::size.x;
}

sf::Vector2i Map::convert_pos(int id)
{
	return sf::Vector2i(id % Map::size.x, id / Map::size.x);
}

void Map::update_path(std::vector<sf::Vector2i> path)
{
	Map::path = path;
}

void Map::reset_search()
{
	for (int i = 0; i < Map::parsed.size(); ++i)
		Map::parsed[i] = false;
}

void Map::render(Camera* camera) {
	int i, j;

	for (i = 0; i < Map::size.x; ++i)
		for (j = 0; j < Map::size.y; ++j) {
			Map::shape[0].position = sf::Vector2f(i * tile_size.x, j * tile_size.y);
			Map::shape[1].position = sf::Vector2f((i + 1) * tile_size.x - 1, j * tile_size.y);
			Map::shape[2].position = sf::Vector2f((i + 1) * tile_size.x - 1, (j + 1) * tile_size.y - 1);
			Map::shape[3].position = sf::Vector2f(i * tile_size.x, (j + 1) * tile_size.y - 1);

			if (Map::get_walkable(sf::Vector2i(i, j))) {
				Map::set_vertex_color(&(Map::shape), sf::Color(255, 255, 255));

				if (Map::parsed[Map::convert_pos({ i, j })])
					Map::set_vertex_color(&(Map::shape), sf::Color(sf::Color::Yellow));

				if (std::find(Map::path.begin(), Map::path.end(), sf::Vector2i(i, j)) != Map::path.end())
					Map::set_vertex_color(&(Map::shape), sf::Color(sf::Color::Cyan));

				if (Map::start == sf::Vector2i(i, j))
					Map::set_vertex_color(&(Map::shape), sf::Color::Green);

				if (Map::end == sf::Vector2i(i, j))
					Map::set_vertex_color(&(Map::shape), sf::Color::Red);
			} else
				Map::set_vertex_color(&(Map::shape), sf::Color(50, 50, 50));

			camera->render_app(&(Map::shape));
		}

	

	auto mouse_pos = Map::app->get_window()->mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition(*(Map::app->get_window()))));

	mouse_pos.x += 512;

	Map::shape[0].position = sf::Vector2f(mouse_pos);
	Map::shape[1].position = sf::Vector2f(mouse_pos.x + 64, mouse_pos.y);
	Map::shape[2].position = sf::Vector2f(mouse_pos.x + 64, mouse_pos.y + 64);
	Map::shape[3].position = sf::Vector2f(mouse_pos.x, mouse_pos.y + 64);

	Map::set_vertex_color(&(Map::shape), sf::Color::Yellow);

	camera->render_ui(&(Map::shape));
}

void Map::set_vertex_color(sf::VertexArray* arr, sf::Color color) {
	for (int i = 0; i < arr->getVertexCount(); ++i)
		arr[0][i].color = color;
}

void Map::logic() {

	auto mouse_pos = Map::app->get_window()->mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition(*(Map::app->get_window()))));

	mouse_pos.x -= 512;

	auto mouse_id = Map::convert_pos({(int)mouse_pos.x / (int)Map::tile_size.x, (int)mouse_pos.y / (int)Map::tile_size.y});

	if (mouse_id < 0 || mouse_id >= Map::tiles.size() || mouse_pos.x < 0 || mouse_pos.x > 2048 - 512)
		return;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		Map::tiles.at(mouse_id) = false;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		Map::tiles.at(mouse_id) = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Map::end != Map::convert_pos(mouse_id)) {
		Map::start = Map::convert_pos(mouse_id);
		Map::tiles.at(mouse_id) = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && Map::start != Map::convert_pos(mouse_id)) {
		Map::end = Map::convert_pos(mouse_id);
		Map::tiles.at(mouse_id) = true;
	}
}

sf::Vector2i Map::get_start()
{
	return Map::start;
}

bool Map::is_end(sf::Vector2i position)
{
	if (Map::get_walkable(position))
		Map::parsed[Map::convert_pos(position)] = true;

	return Map::end == position;
}
