#include "Player.hpp"
#include "Game.hpp"
#include "constants.h"


Player::Player(Game *game, double x, SDL_Scancode key_up, SDL_Scancode key_down) : Entity(game, x, 0, DFL_RACK_WIDTH, DFL_RACK_HEIGHT){
	int win_height;
	SDL_GetWindowSize(game->get_app()->get_window(), nullptr, &win_height);
	y = (win_height - DFL_RACK_HEIGHT) / 2;
	this->key_up = key_up;
	this->key_down = key_down;
}

void Player::handle_event(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		SDL_Scancode key_pressed = event.key.keysym.scancode;
		if(key_pressed == key_up) {
			go_up = 1;
			return;
		}

		if(key_pressed == key_down) {
			go_down = 1;
			return;
		}
	}

	if (event.type == SDL_KEYUP) {
		SDL_Scancode key_released = event.key.keysym.scancode;
		if(key_released == key_up) {
			go_up = 0;
			return;
		}

		if(key_released == key_down) {
			go_down = 0;
			return;
		}
	}
}

void Player::update(double dt) {
}

void Player::draw(SDL_Renderer *rend) {
	SDL_Rect rect = { (int) x, (int) y, (int) width, (int) height};
	SDL_SetRenderDrawColor(rend, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(rend, &rect);
}

Player::~Player() {
}