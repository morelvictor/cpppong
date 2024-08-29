#include "Entity.hpp"

Entity::Entity(Game *game, double x, double y, double width, double height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->game = game;
}

Entity::~Entity() {
}
