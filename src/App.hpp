#pragma once

#include <SDL.h>
#include "View.hpp"

class View;

class App {
	private:
		SDL_Window *win;
		SDL_Renderer *rend;
		View *old_view;
		View *view;
		bool running = true;

	public:
		App();
		void run();
		void clean();
		View *get_old_view() { return old_view; }
		void set_view(View *new_view) { old_view = view; view = new_view; }
		void set_running(bool val) { running = val; }
		SDL_Window *get_window() { return win; }
		~App();
};