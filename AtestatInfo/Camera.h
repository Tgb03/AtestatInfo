#pragma once

#include <SFML/Graphics.hpp>

class Camera
{
public:

	// inits the camera
	Camera(sf::RenderTarget* target);

	void render_app(sf::Drawable* drawable);
	void render_ui(sf::Drawable* drawable);

	void resize(sf::Vector2i size);
	
private: 

	sf::RenderTarget* window;

	// views:
	sf::View view_UserInterface;
	sf::View view_AppInterface;

	sf::View* UserInterface;
	sf::View* AppInterface;
};

