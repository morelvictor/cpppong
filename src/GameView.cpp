#include "GameView.hpp"

#include "constants.h"
#include <SDL.h>

void GameView::reset() {
	int win_width = app->get_width();
	int win_height = app->get_height();
	// reset all positions and speed
	player_left->set_y((win_height - DFL_RACK_HEIGHT) / 2);
	player_left->set_dy(0);

	player_right->set_y((win_height - DFL_RACK_HEIGHT) / 2);
	player_right->set_dy(0);

	ball->set_x((win_width - ball->get_width()) / 2);
	ball->set_y((win_height - ball->get_height()) / 2);
	ball->set_dx(DFL_BALL_X_SPEED);
	ball->set_dy(DFL_BALL_Y_SPEED);
}

GameView::GameView(App *app) : View(app) {
	int win_width = app->get_width();
	player_left = new Player(this, SPACE_RACK_BORDER, SDL_SCANCODE_Q, SDL_SCANCODE_A);
	player_right = new Player(this, win_width - SPACE_RACK_BORDER - DFL_RACK_WIDTH, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);
	ball = new Ball(this);
}

void GameView::handle_event(SDL_Event event) {
	player_left->handle_event(event);
	player_right->handle_event(event);
	ball->handle_event(event);
}

void GameView::update(double dt) {
	player_left->update(dt);
	player_right->update(dt);
	ball->update(dt);
}

void GameView::paint(SDL_Renderer * rend) {
	player_left->draw(rend);
	player_right->draw(rend);
	ball->draw(rend);
}

void GameView::show_score() {
	printf("Left: %d, Right: %d\n", player_left->get_points(), player_right->get_points());
}

void GameView::ball_touch_left() {
	player_right->add_point();
	show_score();
	reset();
}

void GameView::ball_touch_right() {
	player_left->add_point();
	show_score();
	reset();
}

GameView::~GameView() {
}
