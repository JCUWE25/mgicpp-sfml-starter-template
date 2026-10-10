
#include "Game.h"
#include <iostream>



Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL)); //seeds random number generator with the current time
}

Game::~Game()
{
	delete[] Animals;
	delete[] Passports;
	delete Character;
	delete Passport;
}

// We call this once after the game class is instantiated
bool Game::init()
{
	
	//VISITORS
	Animals[0].loadFromFile("../Data/Images/Critter Crossing/elephant.png");
	Animals[1].loadFromFile("../Data/Images/Critter Crossing/moose.png");
	Animals[2].loadFromFile("../Data/Images/Critter Crossing/penguin.png");
	Character = new sf::Sprite(Animals[0]);
	//POSSIBLE PASSPORTS
	Passports[0].loadFromFile("../Data/Images/Critter Crossing/elephant passport.png");
	Passports[1].loadFromFile("../Data/Images/Critter Crossing/moose passport.png");
	Passports[2].loadFromFile("../Data/Images/Critter Crossing/penguin passport.png");
	Passport = new sf::Sprite(Passports[0]);

	NewAnimal();

	menu->setPosition({ 100, 100 });
	menu->setString("does it work");
	
	state = MENU;
  return true;
}

// Update runs after event polling and before rendering
// use it for everything that needs to update between frames
void Game::update(float dt)
{
	
if (hasStateChanged)
	{

	switch(state)
	{
	case MENU:
		std::cout << "menu";


		break;
	case GAME:
		std::cout << "game";
//&Game::DragSprite();
		
		break;
	case QUIT:
		std::cout << "quit";
		break;

	}
	hasStateChanged = false;
	}
}

void Game::LateUpdate()
{
	
}



// Runs after update, use it to tell the window what to draw this frame
void Game::render()
{
	switch(state)
	{
	case MENU:
			break;
	case GAME:
		window.draw(*background);
		window.draw(*menu);
		window.draw(*Character);
		window.draw(*Passport);
		break;
	case QUIT:
		break;
	}
	
}

//Called by event polling when a MouseButtonPressed event is found
void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
	// Event contains mouse position and which button was clicked

	// Don't need to extract position to a variable like this, this is just to show you it's a Vector2i
	sf::Vector2i position = event->position;

	// You can tell which button was pressed by comparing it to SFML's definitions of mouse buttons
	if (event->button == sf::Mouse::Button::Left)
	{
		sf::Vector2f click = static_cast<sf::Vector2f>(event->position);
		if(Passport->getGlobalBounds().contains(click))
		{
			dragged = Passport;
		}
		//Left mouse button was pressed
	}
}

//Called by event polling when a MouseButtonReleased event is found
void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
	//Works the same as MouseButtonPressed
	if (event->button == sf::Mouse::Button::Left)
	{
		//Left mouse button was released
	}
}

// Called by event polling when a KeyPressed event is found
void Game::keyPressed(const sf::Event::KeyPressed* event)
{
	// You can tell which button was pressed by the scancode to SFML's definitions of keyboard keys
	if (event->scancode == sf::Keyboard::Scancode::W)
	{
		// W was pressed
	}

	switch (state)
	{
	case MENU:
		if (event->scancode == sf::Keyboard::Scancode::Enter)
		{
			state = GAME;
			hasStateChanged = true;

		}


		break;
	case GAME:
		if(event->scancode == sf::Keyboard::Scancode::Q)
		{
		
		state = QUIT;
			hasStateChanged = true;
		
		}


		break;
	case QUIT:
		if(event->scancode == sf::Keyboard::Scancode::Enter)
		{
			state = MENU;
			hasStateChanged = true;

		}

		break;

	}

}



// Called by event polling when a KeyReleased event is found
void Game::keyReleased(const sf::Event::KeyReleased* event)
{
	// Works the same way as KeyPressed
	if (event->scancode == sf::Keyboard::Scancode::W)
	{
		// W was released
	}

}

void Game::NewAnimal()
{
	int animalINDEX = rand() % 3;
	int passportINDEX = rand() % 3;

	if(animalINDEX == passportINDEX)
	{
		shouldACCEPT = true;
	}
	else
	{
		shouldACCEPT = false;
	}
	Character->setTexture(Animals[animalINDEX], true);
	Character->setPosition(sf::Vector2f(window.getSize().x/ 12, window.getSize().y/ 12));
	Character->setScale({ 1.8, 1.8 });
	
	Passport->setTexture(Passports[passportINDEX]);
	Passport->setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 3));
	Passport->setScale({ 0.6, 0.6 });
}

void Game::DragSprite(sf::Sprite* sprite)
{

	if (sprite != nullptr) 
	{
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);
	//	sf::Vector2f drag_offset = ;

		sf::Vector2f drag_position = mouse_positionf; //- drag_offset;
		sprite->setPosition({drag_position.x, drag_position.y});
	}

}




