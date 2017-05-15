#include "Portal.h"
#include <iostream>

Portal::Portal(int x, int y) {

	this->texture.loadFromFile("Textures//Tiles//Portal_64x64.png");

	this->body.setTexture(&this->texture);
	this->body.setTextureRect(sf::IntRect(0, 0, 64, 64));
	this->body.setSize(sf::Vector2f(64.0f, 64.0f));
	this->body.setPosition(x, y);

	this->nrOfFramesX = this->texture.getSize().x / 64;
	this->currentFrameX = 0;

	this->timer = 0.0f;

}

Portal::~Portal() {



}

sf::RectangleShape Portal::getBody(void) {

	return this->body;

}

void Portal::updateAnimation(float deltaTime) {

	this->timer += deltaTime;

	if (this->timer >= 0.25f) {
		
		if (this->currentFrameX >= this->nrOfFramesX) {

			this->currentFrameX = 0;

		}

		currentFrameX++;
		this->body.setTextureRect(sf::IntRect((64 * this->currentFrameX), 0, 64, 64));
		this->timer = 0.0f;

	}

}