#include "linker.h"
#include "include.h"

#include "gui/tabs.h"


// static fields
sf::Font Res::s_font;
sf::Text Res::s_text;


int main()
{
	
	Res::init();

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Chip8", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(120);


	TabView tab_view;

#ifdef _WIN32
	ShowWindow(GetConsoleWindow(), SW_HIDE); //SW_RESTORE to bring back
#endif

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			//if (window.hasFocus())
				tab_view.handleEvent(event);
			if (event.type == sf::Event::Closed)
				window.close();
		}
		tab_view.process();

		tab_view.render(window);


		window.display();
	}

	return 0;
}