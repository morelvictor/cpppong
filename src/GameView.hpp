#pragma once

#include "View.hpp"
#include "Player.hpp"
#include "Ball.hpp"

class GameView: public View {
	private:
		Player *player_left;
		Player *player_right;
		Ball *ball;
		void reset();

	public:
		GameView(App *app);
		void handle_event(SDL_Event event) override;
		void update(double dt) override;
		void paint(SDL_Renderer *rend) override;
		Player *get_player_left() { return player_left; }
		Player *get_player_right() { return player_right; }
		void ball_touch_left();
		void ball_touch_right();
		~GameView() override;
};