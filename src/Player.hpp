#pragma once

#include "Entity.hpp"

#include <SDL.h>

class Game;

class Player : public Entity {
	private:
		int go_up, go_down = 0;
		SDL_Scancode key_up, key_down;
		void update_speed();
		void update_position(double dt);
	public:
		Player(Game *game, double x, SDL_Scancode key_up, SDL_Scancode key_down);
		void handle_event(SDL_Event event) override;
		void update(double dt) override;
		void draw(SDL_Renderer *rend) override;
		~Player();
};