#include "Entity.hpp"

Entity::Entity(double x, double y, double width, double height, Game *game) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->game = game;
}

Entity::~Entity() {
}
