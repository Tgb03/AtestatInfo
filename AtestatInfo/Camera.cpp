#include "Camera.h"

Camera::Camera(sf::RenderTarget* target) {
	Camera::window = target;

	Camera::view_AppInterface.reset(sf::FloatRect(0.f, 0.f, 2048.f, 1024.f));
	Camera::view_UserInterface.reset(sf::FloatRect(0.f, 0.f, 2048.f, 1024.f));

	Camera::view_AppInterface.setViewport(sf::FloatRect(0.f, 0.f, 0.25f, 1.f));
	Camera::view_AppInterface.setViewport(sf::FloatRect(0.25f, 0.f, 1.f, 1.f));
}

void Camera::render_app(sf::Drawable* drawable)
{
	Camera::window->setView(Camera::view_AppInterface);
	Camera::window->draw(*drawable);
}

void Camera::render_ui(sf::Drawable* drawable)
{
	Camera::window->setView(Camera::view_UserInterface);
	Camera::window->draw(*drawable);
}

void Camera::resize(sf::Vector2i size) {
	Camera::view_AppInterface.reset(sf::FloatRect(0.f, 0.f, size.x, size.y));
	Camera::view_UserInterface.reset(sf::FloatRect(0.f, 0.f, size.x, size.y));
}
