#pragma once

#include <SFML/Graphics.hpp>

class App;

enum ButtonStates{pressed, hold, released, none};

class Button
{
public:

	Button(sf::Vector2i, sf::Vector2i, App*);

	bool IsHovered();
	ButtonStates getState();

	void checkPress();

protected:

	sf::Vector2i pos1;
	sf::Vector2i pos2;

	App* app;

	ButtonStates buttonState;

};

