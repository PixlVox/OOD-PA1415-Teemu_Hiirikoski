#include "Menu.h"

void Menu::detectKey()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->current++;
		this->menuSprite[2].setPosition(400, 350);
		if (current > 1)
		{
			current = 0;
			this->menuSprite[2].setPosition(400, 280);
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->current--;
		this->menuSprite[2].setPosition(400, 280);
		if (current < 0)
		{
			current = 1;
			this->menuSprite[2].setPosition(400, 350);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		this->done = this->current;
	}
}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for each (sf::Sprite var in this->menuSprite)
	{
		target.draw(var, states);
	}
	target.draw(this->background, states);
}

Menu::Menu()
{
	this->menuTexture.loadFromFile("Textures\Menu\NewGameButton.png");
	this->menuSprite[0].setTexture(this->menuTexture);
	this->menuSprite[0].setPosition(sf::Vector2f(400, 350));

	this->menuTexture.loadFromFile("Textures\Menu\ExitButton.png");
	this->menuSprite[1].setTexture(this->menuTexture);
	this->menuSprite[1].setPosition(sf::Vector2f(400, 280));

	this->menuTexture.loadFromFile("Textures\Menu\ButtonHighlight.png");
	this->menuSprite[2].setTexture(this->menuTexture);
	this->menuSprite[2].setPosition(sf::Vector2f(400, 350));

	this->background.setSize(sf::Vector2f(1920, 1080));
	this->background.setFillColor(sf::Color::Black);

	this->current = 0;
	this->done = -1;
}

int Menu::update()
{
	if (this->done != -1)
	{
		this->done = -1;
	}
	this->detectKey();
	return this->done;
}
