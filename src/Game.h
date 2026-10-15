
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

    //BG
	sf::Texture* background_texture = new sf::Texture("../Data/Images/WhackaMole Worksheet/background.png");
	sf::Sprite* background = new sf::Sprite(*background_texture);
	//REJECT BUTTON
	sf::Texture* RstampButton_Texture = new sf::Texture("../Data/Images/Critter Crossing/reject button.png");
	sf::Sprite* RstampButton = new sf::Sprite(*RstampButton_Texture);
	//REJECT STAMP
	sf::Texture* Rstamp_Texture = new sf::Texture("../Data/Images/Critter Crossing/reject.png");
	sf::Sprite* Rstamp = new sf::Sprite(*Rstamp_Texture);
	// ACCEPT STAMP
    sf::Texture* Astamp_Texture = new sf::Texture("../Data/Images/Critter Crossing/accept.png");
	sf::Sprite* Astamp = new sf::Sprite(*Astamp_Texture);
	// ACCEPT BUTTON
	sf::Texture* AstampButton_Texture = new sf::Texture("../Data/Images/Critter Crossing/accept button.png");
	sf::Sprite* AstampButton = new sf::Sprite(*AstampButton_Texture);
	
	sf::Sprite* Character;
	sf::Sprite* Passport;
	sf::Texture* Animals = new sf::Texture[3];
	sf::Texture* Passports = new sf::Texture[3];

	sf::Font* f = new sf::Font("../Data/Fonts/OpenSans-Bold.ttf");//path goes here;
    sf::Text* menu =  new sf::Text(*f);

    bool shouldACCEPT;
	bool StampsVisible;
	bool DoubleClick;
	bool Passport_R;
	bool Passport_A;
	bool ClickStampR;
	bool ClickStampA;
	bool PassportAccepted;
	
	sf::Vector2f drag_offset;
	sf::Sprite* dragged = nullptr;
};

#endif // SFML_GAME_H
