#pragma once

#include "TextTab.h"

#include "Camera.h"

class AlgorithmDescription :
    public TextTab
{
public:

    AlgorithmDescription(std::string fileName, sf::Font* font);

    void render(Camera* camera);
    void changeAlgorithm(int newId);

private:
    
    std::vector <std::string> segmentedList;

};

