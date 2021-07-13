#include "UserInterface.h"

#include "Camera.h"

UserInterface::UserInterface() {
	UserInterface::font.loadFromFile("Data/arial_narrow_7.ttf");

	UserInterface::text_title.setFont(UserInterface::font);
	UserInterface::text_title.setCharacterSize(64);
	UserInterface::text_title.setFillColor(sf::Color::White);
	UserInterface::text_title.setString("Cautarea drumului");
	UserInterface::text_title.setPosition({ 10, 10 });

	UserInterface::text_legend.setFont(UserInterface::font);
	UserInterface::text_legend.setCharacterSize(32);
	UserInterface::text_legend.setFillColor(sf::Color::White);
	UserInterface::text_legend.setString("Legenda");
	UserInterface::text_legend.setPosition({ 10, 768 });

	UserInterface::algorithm_selected.setFont(UserInterface::font);
	UserInterface::algorithm_selected.setCharacterSize(48);
	UserInterface::algorithm_selected.setFillColor(sf::Color::White);
	UserInterface::algorithm_selected.setString("Algoritm utilizat: \n");
	UserInterface::algorithm_selected.setPosition({ 10, 80 });

	UserInterface::text_visualize.setFont(UserInterface::font);
	UserInterface::text_visualize.setCharacterSize(64);
	UserInterface::text_visualize.setFillColor(sf::Color::White);
	UserInterface::text_visualize.setString("Vizualizare");
	UserInterface::text_visualize.setPosition({ 10, 695 });

	UserInterface::text_symbology.setFont(UserInterface::font);
	UserInterface::text_symbology.setCharacterSize(33);
	UserInterface::text_symbology.setFillColor(sf::Color::White);
	UserInterface::text_symbology.setString(" Start Position \n End Position \n Path \n Parsed \n Walkable \n Not walkable");
	UserInterface::text_symbology.setPosition({ 45, 806 });

	UserInterface::rectangle_background.setFillColor(sf::Color(52, 73, 94, 255));
	UserInterface::rectangle_background.setPosition({ 0, 0 });
	UserInterface::rectangle_background.setSize({512, 1024});

	UserInterface::rectangle_legend.setFillColor(sf::Color(255, 255, 255, 30));
	UserInterface::rectangle_legend.setPosition({ 0, 773 });
	UserInterface::rectangle_legend.setSize({ 512, 251 });

	UserInterface::rectangle_visualize.setFillColor(sf::Color(255, 255, 255, 30));
	UserInterface::rectangle_visualize.setPosition({ 0, 705 });
	UserInterface::rectangle_visualize.setSize({ 300, 64 });

	UserInterface::symbology_green.setFillColor(sf::Color::Green);
	UserInterface::symbology_green.setPosition({ 10, 810 });
	UserInterface::symbology_green.setSize({ 32, 32 });

	UserInterface::symbology_red.setFillColor(sf::Color::Red);
	UserInterface::symbology_red.setPosition({ 10, 844 });
	UserInterface::symbology_red.setSize({ 32, 32 });

	UserInterface::symbology_cyan.setFillColor(sf::Color::Cyan);
	UserInterface::symbology_cyan.setPosition({ 10, 878 });
	UserInterface::symbology_cyan.setSize({ 32, 32 });

	UserInterface::symbology_yellow.setFillColor(sf::Color::Yellow);
	UserInterface::symbology_yellow.setPosition({ 10, 912 });
	UserInterface::symbology_yellow.setSize({ 32, 32 });

	UserInterface::symbology_white.setFillColor(sf::Color::White);
	UserInterface::symbology_white.setPosition({ 10, 946 });
	UserInterface::symbology_white.setSize({ 32, 32 });

	UserInterface::symbology_black.setFillColor(sf::Color(50, 50, 50));
	UserInterface::symbology_black.setPosition({ 10, 980 });
	UserInterface::symbology_black.setSize({ 32, 32 });
}

void UserInterface::render(Camera* camera) {

	camera->render_ui(&(UserInterface::rectangle_background));
	camera->render_ui(&(UserInterface::rectangle_legend));
	camera->render_ui(&(UserInterface::rectangle_visualize));

	camera->render_ui(&(UserInterface::symbology_green));
	camera->render_ui(&(UserInterface::symbology_red));
	camera->render_ui(&(UserInterface::symbology_cyan));
	camera->render_ui(&(UserInterface::symbology_yellow));

	camera->render_ui(&(UserInterface::symbology_white));
	camera->render_ui(&(UserInterface::symbology_black));

	camera->render_ui(&(UserInterface::text_symbology));
	
	camera->render_ui(&(UserInterface::text_legend));
	camera->render_ui(&(UserInterface::algorithm_selected));
	camera->render_ui(&(UserInterface::text_visualize));
	camera->render_ui(&(UserInterface::text_title));
}

void UserInterface::setUsedAlgorithm(std::string s)
{
	UserInterface::algorithm_selected.setString("Algoritmul utilizat: \n" + s);
}
