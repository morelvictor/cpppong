#pragma once

#include "Entity.hpp"
#include "MenuView.hpp"

#define B_MENU_WIDTH 100
#define B_MENU_HEIGHT 100

class Button : public Entity {
	private:
		bool selected = false;
		void (*on_clicked)(App *app);
		char *label;
	public:
		Button(View *view, void (*on_clicked)(App *), char *, int x, int y, int width, int height);
		void handle_event(SDL_Event event) override;
		void update(double dt) override;
		void draw(SDL_Renderer *rend) override;
		~Button();
};