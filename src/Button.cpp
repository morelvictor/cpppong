#include "Button.hpp"
#include "Entity.hpp"

#include <iostream>

using namespace std;

Button::Button(View *view, void (*on_clicked)(App *)) : Entity(view, 200, 200, 100, 100) {
	this->on_clicked = on_clicked;
}

void Button::handle_event(SDL_Event event) {
	if(event.type == SDL_MOUSEMOTION) {
		SDL_Point cursor = { event.motion.x, event.motion.y };
		SDL_Rect button = { (int) x, (int) y, (int) width, (int) height };
		selected = SDL_PointInRect(&cursor, &button);
	}

	if(selected) {
		if(event.type == SDL_MOUSEBUTTONDOWN) {
			if(event.button.button == SDL_BUTTON_LEFT) {
				on_clicked(view->get_app());
			}
		}
	}
}

void Button::update(double dt) {}

void Button::draw(SDL_Renderer * rend) {
	SDL_Rect rect = { (int) x, (int) y, (int) width, (int) height};
	if(selected) {
		SDL_SetRenderDrawColor(rend, 100, 100, 100, SDL_ALPHA_OPAQUE);
	} else {
		SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
	}
	SDL_RenderFillRect(rend, &rect);
}

Button::~Button() {
}
