#pragma once

#include "Entity.hpp"

#include <SDL.h>

class GameView;

class Player : public Entity {
	private:
		int go_up, go_down = 0;
		SDL_Scancode key_up, key_down;
		int points = 0;
		void update_speed();
		void update_position(double dt);
	public:
		Player(GameView *game, double x, SDL_Scancode key_up, SDL_Scancode key_down);
		void handle_event(SDL_Event event) override;
		void update(double dt) override;
		void add_point() { points ++; }
		int get_points() { return points; }
		~Player();
};
