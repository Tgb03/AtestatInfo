#include "AlgorithmDescription.h"

#include <sstream>

AlgorithmDescription::AlgorithmDescription(std::string fileName, sf::Font* font) : 
	TextTab{fileName, font}
{
	
	std::string segment;
	std::stringstream text(TextTab::text.getString());
	while (std::getline(text, segment, '|'))
		segmentedList.push_back(segment);

	if (segmentedList.size() > 0)
		TextTab::text.setString(segmentedList[0]);

	TextTab::show_when_hovered = false;
}

void AlgorithmDescription::render(Camera* camera)
{
	TextTab::render(camera);

}

void AlgorithmDescription::changeAlgorithm(int newId)
{
	TextTab::text.setString(segmentedList[newId]);
}
