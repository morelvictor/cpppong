#include "Game.hpp"

#include "constants.h"

Game::Game(App *app) : View(app) {
	int win_width;
	SDL_GetWindowSize(app->get_window(), &win_width, nullptr);
	player_left = new Player(this, SPACE_RACK_BORDER, SDL_SCANCODE_Q, SDL_SCANCODE_A);
	player_right = new Player(this, win_width - SPACE_RACK_BORDER - DFL_RACK_WIDTH, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);
}

void Game::handle_event(SDL_Event event) {
	player_left->handle_event(event);
	player_right->handle_event(event);
}

void Game::update(double dt) {
	player_left->update(dt);
	player_right->update(dt);
}

void Game::paint(SDL_Renderer * rend) {
	SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(rend);

	player_left->draw(rend);
	player_right->draw(rend);
}

Game::~Game() {
}
