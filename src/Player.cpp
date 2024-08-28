#include "Player.hpp"
#include "Game.hpp"
#include "constants.h"

Player::Player(double x, Game *game) : Entity(x, 0, DFL_RACK_WIDTH, DFL_RACK_HEIGHT, game){
	int win_height;
	SDL_GetWindowSize(game->get_app()->get_window(), nullptr, &win_height);
	y = (win_height - 100) / 2;
}

void Player::handle_event(SDL_Event event) {

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