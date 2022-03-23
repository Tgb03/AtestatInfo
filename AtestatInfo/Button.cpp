#include "Button.h"

#include "App.h"

Button::Button(sf::Vector2i pos1, sf::Vector2i pos2, App* app)
{
	Button::pos1 = pos1;
	Button::pos2 = pos2;

	Button::buttonState = ButtonStates::none;
	Button::app = app;
}

bool Button::IsHovered()
{
	sf::Vector2i mousePos = sf::Vector2i(app->get_window()->mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition(*(app->get_window())))));

	return Button::pos1.x < mousePos.x && mousePos.x < Button::pos2.x &&
		   Button::pos1.y < mousePos.y && mousePos.y < Button::pos2.y;
}

ButtonStates Button::getState()
{
	return Button::buttonState;
}

void Button::checkPress() 
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Button::IsHovered())
	{ 
		// button is pressed:
		if (Button::buttonState == ButtonStates::none || Button::buttonState == ButtonStates::released)
			Button::buttonState = ButtonStates::pressed;

		else
			Button::buttonState = ButtonStates::hold;
	}
	else {
		if (Button::buttonState == ButtonStates::hold || Button::buttonState == ButtonStates::pressed)
			Button::buttonState = ButtonStates::released;

		else 
			Button::buttonState = ButtonStates::none;
	}
}
