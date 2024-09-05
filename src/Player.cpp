#include "Player.hpp"
#include "GameView.hpp"
#include "constants.h"


void Player::update_speed() {
	if(go_up && !go_down) { dy = -DFL_RACK_SPEED; return; }
	if(go_down && !go_up) { dy = DFL_RACK_SPEED; return; }
	dy = 0;
}

void Player::update_position(double dt) {
	int win_height = view->get_app()->get_height();
	if(y + dy * dt >= 0 && y + height + dy * dt < win_height) {
		y += dy * dt;
	} else {
		if(dy < 0) {
			y = 0;
		}

		if(dy > 0) {
			y = win_height - height - 1;
		}
	}
}

Player::Player(GameView *game, double x, SDL_Scancode key_up, SDL_Scancode key_down) : Entity(game, x, 0, DFL_RACK_WIDTH, DFL_RACK_HEIGHT){
	int win_height = game->get_app()->get_height();
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
	update_speed();
	update_position(dt);
}

Player::~Player() {
}