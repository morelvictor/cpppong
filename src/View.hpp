#pragma once

#include "App.hpp"
#include <SDL.h>

class App;

class View {
	protected:
		App *app;

	public:
		View(App *app);
		virtual void handle_event(SDL_Event event) = 0;
		virtual void update(double dt) = 0;
		virtual void paint(SDL_Renderer *rend) = 0;
		App *get_app() { return app; }
		virtual ~View() = 0;
};