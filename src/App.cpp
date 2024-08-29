#include "App.hpp"

#include <iostream>
#include <SDL.h>
#include <chrono>
#include "Game.hpp"
#include "constants.h"

using namespace std;

App::App() {
	if(SDL_Init(SDL_INIT_VIDEO)) {
		cout << "Problem at SDL initialisation" << endl;
	}

	win = SDL_CreateWindow(APP_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DFL_WIN_WIDTH, DFL_WIN_HEIGHT, 0);
	if (!win) {
		cout << "Problem at window creation" << endl;
	}

	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!rend) {
		cout << "Problem at renderer creation" << endl;
	}

	view = new Game(this);
	old_view = view;
}

void App::run() {
	int fps = 1;
	double dt = 0;
	auto last_fps = chrono::high_resolution_clock::now();
	while(running) {
		fps++;
		auto start_time = chrono::high_resolution_clock::now();

		chrono::duration<double> fps_dt = start_time - last_fps;
		if(fps_dt.count() > 1) {
			last_fps = start_time;
			cout << fps << endl;
			fps = 0;
		}

		// Free the memory of the old view
		if(old_view != view) {
			delete old_view;
			old_view = view;
		}
		
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					running = false;
					break;
				default: break;
			}

			view->handle_event(event);
		}
		
		view->update(dt);
		view->paint(rend);
		SDL_RenderPresent(rend);

		auto end_time = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed_time = end_time - start_time;
		dt = elapsed_time.count();
	}

}

void App::clean() {
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

App::~App() {

}