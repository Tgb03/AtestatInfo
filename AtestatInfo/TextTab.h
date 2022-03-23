#pragma once

#include <SFML/Graphics.hpp>

class Camera;

class TextTab
{
public:

	TextTab(std::string fileName, sf::Font* font, bool show_when_hovered = false, bool show_background = false);
	TextTab(std::string, sf::Vector2i render_pos, sf::Font* font, bool show_when_hovered = false, bool show_background = false);
	void render(Camera*, sf::Vector2i pos = {0,0});

protected:

	bool show_when_hovered;
	bool show_background;

	sf::Vector2i position;
	sf::Font* font;
	sf::Text text;

	sf::RectangleShape background;

};

