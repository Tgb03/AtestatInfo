#include "TextTab.h"

#include <sstream>
#include <fstream>

#include "Camera.h"

TextTab::TextTab(std::string fileName, sf::Font* font, bool show_when_hovered, bool show_background)
{

	TextTab::font = font;

	sf::Vector2i render_pos;

	std::ifstream file;
	file.open(fileName);

	file >> render_pos.x >> render_pos.y;

	std::string text_string, line;
	while (std::getline(file, line))
		text_string.append(line + "\n");

	TextTab::text.setFont(*(TextTab::font));
	TextTab::text.setCharacterSize(32);
	TextTab::text.setString(text_string);
	TextTab::text.setFillColor(sf::Color(255, 255, 255, 255));
	TextTab::text.setPosition(sf::Vector2f(render_pos));

	// calculate size of background
	sf::FloatRect backgroundRect = text.getLocalBounds();
	sf::Vector2f backgroundSize = sf::Vector2f(backgroundRect.width + 10, backgroundRect.height + 10);

	render_pos.x -= 5;

	TextTab::background.setFillColor(sf::Color(173, 216, 230));
	TextTab::background.setPosition(sf::Vector2f(render_pos));
	TextTab::background.setSize(backgroundSize);

	TextTab::show_when_hovered = show_when_hovered;
	TextTab::show_background = show_background;
}

TextTab::TextTab(std::string text_string, sf::Vector2i render_pos, sf::Font* font, bool show_when_hovered, bool show_background)
{
	TextTab::font = font;

	TextTab::text.setFont(*(TextTab::font));
	TextTab::text.setCharacterSize(20);
	TextTab::text.setString(text_string);
	TextTab::text.setFillColor(sf::Color(255, 255, 255, 255));
	TextTab::text.setPosition(sf::Vector2f(render_pos));

	// calculate size of background
	int lines = 0;
	int maxSizeLine = 0;

	std::istringstream iss(text_string);
	std::string line;
	while (std::getline(iss, line)) {
		lines++;
		if (line.size() > maxSizeLine)
			maxSizeLine = line.size();
	}

	sf::Vector2i background_size = { maxSizeLine * 10, lines * 20 };

	render_pos.x -= 5;

	TextTab::background.setFillColor(sf::Color(173, 216, 230));
	TextTab::background.setPosition(sf::Vector2f(render_pos));
	TextTab::background.setSize(sf::Vector2f(background_size));

	TextTab::show_when_hovered = show_when_hovered;
	TextTab::show_background = show_background;
}

void TextTab::render(Camera* camera, sf::Vector2i mouse_position)
{
	if (show_background)
		camera->render_ui(&(TextTab::background));
	camera->render_ui(&(TextTab::text));
}
