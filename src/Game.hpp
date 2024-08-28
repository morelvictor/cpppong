#pragma once

#include "View.hpp"
#include "Player.hpp"

class Game: public View {
	private:
		Player *player_left;
		Player *player_right;


	public:
		Game(App *app);
		void handle_event(SDL_Event event) override;
		void update(double dt) override;
		void paint(SDL_Renderer *rend) override;
		~Game() override;
};