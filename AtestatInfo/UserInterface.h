#pragma once

#include <SFML/Graphics.hpp>

#include "AlgorithmDescription.h"

class Camera;

class UserInterface
{
public:

	UserInterface();

	void render(Camera* camera);

	void setUsedAlgorithm(std::string s, int id);
	void changeLegend();

private:

	bool legendBool;

	sf::Font font;
	
	sf::Text text_title;
	sf::Text text_legend;
	sf::Text text_controls;
	sf::Text text_visualize;
	sf::Text text_change;

	sf::Text text_symbology;

	sf::Text algorithm_selected;
	std::string algorithm;

	sf::RectangleShape rectangle_background;
	sf::RectangleShape rectangle_legend;
	sf::RectangleShape rectangle_box1;
	sf::RectangleShape rectangle_visualize;
	sf::RectangleShape rectangle_change;

	sf::RectangleShape symbology_green;
	sf::RectangleShape symbology_red;
	sf::RectangleShape symbology_cyan;
	sf::RectangleShape symbology_yellow;

	sf::RectangleShape symbology_white;
	sf::RectangleShape symbology_black;

	AlgorithmDescription algorithmDescription;
};

