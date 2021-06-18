#pragma once

#include <SFML/Graphics.hpp>

class Camera;

class UserInterface
{
public:

	UserInterface();

	void render(Camera* camera);

private:

	sf::Font font;
	
	sf::Text text_title;
	sf::Text text_legend;
	sf::Text text_visualize;
	//sf::Text calculate_text;

	sf::RectangleShape rectangle_name;
	sf::RectangleShape rectangle_legend;
	sf::RectangleShape rectangle_box1;
	sf::RectangleShape rectangle_visualize;
};

