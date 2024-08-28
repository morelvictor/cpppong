#pragma once

#include "Entity.hpp"

class Game;

class Player : public Entity {
	public:
		Player(double x, Game *game);
		void handle_event(SDL_Event event) override;
		void update(double dt) override;
		void draw(SDL_Renderer *rend) override;
		~Player();
};