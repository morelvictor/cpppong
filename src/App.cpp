#include "App.hpp"

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <chrono>
#include "GameView.hpp"
#include "MenuView.hpp"
#include "constants.h"


App::App() {
	if(SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "Problem at SDL initialisation" << std::endl;
	}

	if (TTF_Init() < 0) {
		std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
	}

	font = TTF_OpenFont("/System/Library/Fonts/Supplemental/Arial Black.ttf", 24);
	if ( !font ) {
		std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
	}

	win = SDL_CreateWindow(APP_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DFL_WIN_WIDTH, DFL_WIN_HEIGHT, 0);
	if (!win) {
		std::cout << "Problem at window creation" << std::endl;
	}

	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!rend) {
		std::cout << "Problem at renderer creation" << std::endl;
	}

	SDL_GetWindowSize(win, &width, &height);
	view = new MenuView(this);
	old_view = view;
}

void App::run() {
	int fps = 1;
	double dt = 0;
	auto last_fps = std::chrono::high_resolution_clock::now();
	while(running) {
		SDL_GetWindowSize(win, &width, &height);
		fps++;
		auto start_time = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> fps_dt = start_time - last_fps;
		if(fps_dt.count() > 1) {
			last_fps = start_time;
			std::cout << "Fps: " << fps << std::endl;
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
		SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(rend);
		view->paint(rend);
		SDL_RenderPresent(rend);

		auto end_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed_time = end_time - start_time;
		dt = elapsed_time.count();
	}
}

void App::clean() {
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	TTF_CloseFont(font);
	SDL_Quit();
	delete view;
}

App::~App() {

}