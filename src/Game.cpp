#include "Game.hpp"

Game::Game(App *app) : View(app) {
}

void Game::handle_event() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				get_app()->set_running(false);
				break;
			default: break;
		}
	}
}

void Game::update(double dt) {
}

void Game::paint(SDL_Renderer * rend) {
	SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(rend);
}

Game::~Game() {
}
