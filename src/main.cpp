#include <SFML/Graphics.hpp>
#include "Simulation.h"

int main()
{
	Simulation s;
	s.run();

	return 0;
	// sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "SFML works!" );
	// sf::CircleShape shape( 100.f );
	// shape.setFillColor( sf::Color::Green );

	// while ( window.isOpen() )
	// {
	// 	while ( const std::optional event = window.pollEvent() )
	// 	{
	// 		if ( event->is<sf::Event::Closed>() )
	// 			window.close();
	// 	}

	// 	window.clear();
	// 	window.draw( shape );
	// 	window.display();
	// }
}
