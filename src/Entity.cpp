#include "Entity.hpp"

Entity::Entity(View *view, double x, double y, double width, double height) {
	this->x = x;
	this->y = y;
	this->dx = this->dy = 0;
	this->width = width;
	this->height = height;
	this->view = view;
}

void Entity::draw(SDL_Renderer * rend) {
	SDL_Rect rect = { (int) x, (int) y, (int) width, (int) height};
	SDL_SetRenderDrawColor(rend, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(rend, &rect);
}

Entity::~Entity() {
}
