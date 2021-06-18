#include "UserInterface.h"

#include "Camera.h"

UserInterface::UserInterface() {
	UserInterface::font.loadFromFile("Data/arial_narrow_7.ttf");

	UserInterface::text_title.setFont(UserInterface::font);
	UserInterface::text_title.setCharacterSize(64);
	UserInterface::text_title.setFillColor(sf::Color::White);
	UserInterface::text_title.setString("Pathfinding");
	UserInterface::text_title.setPosition({ 10, 10 });

	UserInterface::text_legend.setFont(UserInterface::font);
	UserInterface::text_legend.setCharacterSize(32);
	UserInterface::text_legend.setFillColor(sf::Color::Black);
	UserInterface::text_legend.setString("Legend");
	UserInterface::text_legend.setPosition({ 10, 768 });

	UserInterface::text_visualize.setFont(UserInterface::font);
	UserInterface::text_visualize.setCharacterSize(64);
	UserInterface::text_visualize.setFillColor(sf::Color::Black);
	UserInterface::text_visualize.setString("Visualize");
	UserInterface::text_visualize.setPosition({ 10, 695 });

	UserInterface::rectangle_name.setFillColor(sf::Color(50, 50, 50, 50));
	UserInterface::rectangle_name.setPosition({ 10, 25 });
	UserInterface::rectangle_name.setSize({290, 64});

	UserInterface::rectangle_legend.setFillColor(sf::Color(255, 255, 255, 255));
	UserInterface::rectangle_legend.setPosition({ 0, 773 });
	UserInterface::rectangle_legend.setSize({ 512, 251 });

	UserInterface::rectangle_visualize.setFillColor(sf::Color(255, 255, 255, 255));
	UserInterface::rectangle_visualize.setPosition({ 0, 705 });
	UserInterface::rectangle_visualize.setSize({ 256, 64 });
}

void UserInterface::render(Camera* camera) {

	camera->render_ui(&(UserInterface::rectangle_name));
	camera->render_ui(&(UserInterface::rectangle_legend));
	camera->render_ui(&(UserInterface::rectangle_visualize));

	camera->render_ui(&(UserInterface::text_legend));
	camera->render_ui(&(UserInterface::text_visualize));
	camera->render_ui(&(UserInterface::text_title));
}