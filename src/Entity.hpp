#pragma once

#include <SDL.h>

class Game;

class Entity {
	protected:
		double x, y;
		double width, height;
		Game *game;

	public:
		Entity(double x, double y, double width, double height, Game *game);
		virtual void handle_event(SDL_Event event) = 0;
		virtual void update(double dt) = 0;
		virtual void draw(SDL_Renderer *rend) = 0;
		~Entity();
};