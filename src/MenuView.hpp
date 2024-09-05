#pragma once

#include "View.hpp"

#include "App.hpp"
#include "Button.hpp"

class Button;

class MenuView : public View {
	private:
		Button *play_button;
	public:
		MenuView(App *app);
		Button *get_play_button() { return play_button; }
		void handle_event(SDL_Event event) override;
		void update(double dt) override;
		void paint(SDL_Renderer *rend) override;
		~MenuView();
};