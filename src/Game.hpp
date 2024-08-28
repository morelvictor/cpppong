#pragma once

#include "View.hpp"

class Game: public View {
	private:

	public:
		Game(App *app);
		void handle_event() override;
		void update(double dt) override;
		void paint(SDL_Renderer *rend) override;
		~Game() override;
};