#include "App.h"

App::App() : window(sf::VideoMode(2048, 1024), "Pathfinder"),
			map({ 48,32 }, this),
			camera(&window)
{
	App::frame_rate = 120;
	App::logic_speed = 120;

	App::selection = Algorithm::Dijkstra;
	AlgorithmStrings = {"Dijsktra", "AStar", "Greedy-BFS", "Random"};

	App::ui.setUsedAlgorithm(App::getAlgorithmString(), 0);

	App::Buttons.push_back(Button({ 0, 705 }, { 300, 769 }, this));
	App::Buttons.push_back(Button({ 310, 705 }, { 500, 769 }, this));
	App::Buttons.push_back(Button({ 0, 773 }, {512, 1024}, this));

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

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Z) {
				App::change_algorithm();
			}
			if (event.key.code == sf::Keyboard::Space) {
				pathfinder();
			}
		}

	}

	for (std::size_t i = 0; i < Buttons.size(); i++)
		Buttons[i].checkPress();

	// test buttons:
	if (App::Buttons[0].getState() == ButtonStates::pressed)
		App::pathfinder();

	if (App::Buttons[1].getState() == ButtonStates::pressed)
		App::change_algorithm();

	if (App::Buttons[2].getState() == ButtonStates::pressed)
		App::ui.changeLegend();

	return true;
}

void App::render_tick() {
	window.clear();

	// render everything inside this:
	
	App::map.render(&(App::camera));
	
	App::ui.render(&(App::camera));

	for (auto textTab : TextTabs)
		textTab.render(&(App::camera), sf::Vector2i(App::window.mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition(*(App::get_window()))))));
	
	// render ends

	window.display();
}

void App::pathfinder() {
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
	case Algorithm::GreedyBestFirstSearch: {
		GreedyBestFirstSearch greedybestFirstSearch(&(App::map));
		App::map.update_path(greedybestFirstSearch.generate());
		break;
	}
	case Algorithm::Random: {
		Random random(&(App::map));
		App::map.update_path(random.generate());
		break;
	}
	default:
		break;
	}
}

void App::change_algorithm()
{
	int n_value = 1 + static_cast<int>(App::selection);

	if (n_value == static_cast<int>(Algorithm::Count))
		n_value = 0;

	App::selection = static_cast<Algorithm>(n_value);

	App::ui.setUsedAlgorithm(App::getAlgorithmString(), n_value);
}
