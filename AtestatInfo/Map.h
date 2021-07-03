#pragma once

#include <SFML/Graphics.hpp>

class Camera;
class App;

// deals with the management of tiles
class Map
{
public:

	// constructor, takes as input the size
	Map(sf::Vector2i size, App* app);

	// returns the size of the map
	sf::Vector2i get_size();

	// returns if a tile is walkable
	bool get_walkable(sf::Vector2i pos);

	// returns adjacent tile positions
	std::vector <sf::Vector2i> get_adjacent(sf::Vector2i pos);

	// render map
	void render(Camera* camera);

	// logic for map
	void logic();

	// get start
	sf::Vector2i get_start();

	// is end test
	bool is_end(sf::Vector2i position);

	// get end position
	sf::Vector2i get_end();

	// converts map coords to vector position
	int convert_pos(sf::Vector2i);

	// converts vector position to map coords
	sf::Vector2i convert_pos(int);

	// updates path to show it:
	void update_path(std::vector<sf::Vector2i>);

	// reset which tiles were searched
	void reset_search();

private:

	App* app;

	// tile vector:
	// true means walkable
	// one dimensional for better memory management
	std::vector <bool> tiles;

	// set color of vertex to specific sf::Color
	void set_vertex_color(sf::VertexArray* arr, sf::Color color);

	// show path
	std::vector <sf::Vector2i> path;

	// parsed tiles
	std::vector <bool> parsed;

	// constants:

	// for rendering
	sf::VertexArray shape;

	// size of one tile
	sf::Vector2f tile_size = {32, 32};

	// size of the map
	sf::Vector2i size;

	// starting point
	sf::Vector2i start;

	// end point
	sf::Vector2i end;

};


