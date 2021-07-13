#include "App.h"

App::App() : window(sf::VideoMode(2048, 1024), "Pathfinder"),
			map({ 48,32 }, this),
			camera(&window)
{
	App::frame_rate = 120;
	App::logic_speed = 60;

	App::selection = Algorithm::Dijkstra;
	AlgorithmStrings = {"Dijsktra", "AStar"};

	App::ui.setUsedAlgorithm(App::getAlgorithmString());

}

bool App::tick()
{
	if (App::render_clock.getElapsedTime() >= sf::milliseconds(1000 / App::frame_rate)) {
		App::render_clock.restart();

		App::render_tick();
	}

	if (App::logic_speed && App::logic_clock.getElapsedTime() >= sf::milliseconds(1000 / App::logic_speed)) {
		App::logic_clock.restart();

		return App::logic_tick();
	}

	return true;
}

sf::RenderWindow* App::get_window()
{
	return &(App::window);
}

std::string App::getAlgorithmString()
{
	return AlgorithmStrings.at(static_cast<int>(App::selection));
}



bool App::logic_tick() {
	sf::Event event;

	App::map.logic();

	while (window.pollEvent(event)) {
		// "close requested" event
		if (event.type == sf::Event::Closed) {
			window.close();

			return false;
		}

		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Z) {
				int n_value = 1 + static_cast<int>(App::selection);

				if (n_value == static_cast<int>(Algorithm::Count))
					n_value = 0;

				App::selection = static_cast<Algorithm>(n_value);

				App::ui.setUsedAlgorithm(App::getAlgorithmString());
			}
			if (event.key.code == sf::Keyboard::Space) {
				App::map.reset_search();

				switch (App::selection)
				{
				case Algorithm::Dijkstra: {
					Dijkstra dijkstra(&(App::map));
					App::map.update_path(dijkstra.generate());
					break;
				}
				case Algorithm::AStar: {
					AStar astar(&(App::map));
					App::map.update_path(astar.generate());
					break;
				}
				default:
					break;
				}
			}
		//if (event.type == sf::Event::Resized)
		//	App::camera.resize(sf::Vector2i( event.size.width, event.size.height));
	}

	return true;
}

void App::render_tick() {
	window.clear();

	// render everything inside this:
	
	App::map.render(&(App::camera));
	
	App::ui.render(&(App::camera));
	
	// render ends

	window.display();
}