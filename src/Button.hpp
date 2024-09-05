#pragma once

#include "Entity.hpp"
#include "MenuView.hpp"

class Button : public Entity {
	private:
		bool selected = false;
		void (*on_clicked)(App *app);
	public:
		Button(View *view, void (*on_clicked)(App *));
		void handle_event(SDL_Event event) override;
		void update(double dt) override;
		void draw(SDL_Renderer *rend) override;
		~Button();
};