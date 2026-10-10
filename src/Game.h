
#ifndef SFML_GAME_H
#define SFML_GAME_H

#include <SFML/Graphics.hpp>

enum GameState { GAME, MENU, QUIT };


class Game
{
public:
	GameState state;
	bool hasStateChanged;
	Game(sf::RenderWindow& window);
	~Game();
	bool init();
	void update(float dt);
	void LateUpdate();
	void render();
	void mouseButtonPressed(const sf::Event::MouseButtonPressed* event);
	void mouseButtonReleased(const sf::Event::MouseButtonReleased* event);
	void keyPressed(const sf::Event::KeyPressed* event);
	void keyReleased(const sf::Event::KeyReleased* event);
	void NewAnimal();
	void DragSprite(sf::Sprite* sprite);


private:
	sf::RenderWindow& window;

	//sf::Texture background_texture;
	//sf::Sprite background = sf::Sprite(background_texture);

	sf::Texture* background_texture = new sf::Texture("../Data/Images/WhackaMole Worksheet/background.png");
	sf::Sprite* background = new sf::Sprite(*background_texture);
	
	sf::Sprite* Character;
	sf::Sprite* Passport;
	sf::Texture* Animals = new sf::Texture[3];
	sf::Texture* Passports = new sf::Texture[3];

	sf::Font* f = new sf::Font("../Data/Fonts/OpenSans-Bold.ttf");//path goes here;
    sf::Text* menu =  new sf::Text(*f);

    bool shouldACCEPT;
	
	sf::Sprite* dragged = nullptr;
};

#endif // SFML_GAME_H
