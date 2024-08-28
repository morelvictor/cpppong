#include "App.hpp"

#include <iostream>
#include <SDL.h>
#include "Game.hpp"

using namespace std;

App::App() {
	if(SDL_Init(SDL_INIT_VIDEO)) {
		cout << "Problem at SDL initialisation" << endl;
	}

	win = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	if (!win) {
		cout << "Problem at window creation" << endl;
	}

	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if(!rend) {
		cout << "Problem at renderer creation" << endl;
	}

	view = new Game(this);
	old_view = view;
}

void App::run() {
	double dt = 1;
	while(running) {
		// Free the memory of the old view
		if(old_view != view) {
			delete old_view;
			old_view = view;
		}
		view->handle_event();
		view->update(dt);
		view->paint(rend);
		SDL_RenderPresent(rend);
	}
}

void App::clean() {
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

App::~App() {

}