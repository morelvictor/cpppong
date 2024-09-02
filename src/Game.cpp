#include "Game.hpp"

#include "constants.h"
#include <SDL.h>

void Game::reset() {
	int win_width = app->get_width();
	int win_height = app->get_height();
	// reset all positions and speed
	player_left->set_y((win_height - DFL_RACK_HEIGHT) / 2);
	player_left->set_dy(0);

	player_right->set_y((win_height - DFL_RACK_HEIGHT) / 2);
	player_right->set_dy(0);

	ball->set_x((win_width - ball->get_width()) / 2);
	ball->set_y((win_height - ball->get_height()) / 2);
}

Game::Game(App *app) : View(app) {
	int win_width = app->get_width();
	player_left = new Player(this, SPACE_RACK_BORDER, SDL_SCANCODE_Q, SDL_SCANCODE_A);
	player_right = new Player(this, win_width - SPACE_RACK_BORDER - DFL_RACK_WIDTH, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);
	ball = new Ball(this);
}

void Game::handle_event(SDL_Event event) {
	player_left->handle_event(event);
	player_right->handle_event(event);
	ball->handle_event(event);
}

void Game::update(double dt) {
	player_left->update(dt);
	player_right->update(dt);
	ball->update(dt);
}

void Game::paint(SDL_Renderer * rend) {
	SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(rend);

	player_left->draw(rend);
	player_right->draw(rend);
	ball->draw(rend);
}

void Game::ball_touch_left() {
	reset();
}

void Game::ball_touch_right() {
	reset();
}

Game::~Game() {
}
