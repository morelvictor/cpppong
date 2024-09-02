#include "Ball.hpp"
#include "constants.h"
#include "Game.hpp"
#include <SDL.h>

#include <iostream>
using namespace std;

CollisionSide Ball::collide(Entity * entity, double nx, double ny) {
	SDL_Rect n_ball_rect = { (int) nx, (int) ny, (int) width, (int) height };
	SDL_Rect racket_rect = { (int) entity->get_x(), (int) entity->get_y(), (int) entity->get_width(), (int) entity->get_height() };

	if(SDL_HasIntersection(&n_ball_rect, &racket_rect)) {
		SDL_Rect nx_ball_rect = { (int) nx, (int) y, (int) width, (int) height };
		SDL_Rect ny_ball_rect = { (int) x, (int) ny, (int) width, (int) height };

		if(SDL_HasIntersection(&nx_ball_rect, &racket_rect)) {
			if (dx > 0) {
				cout << "RIGHT" << endl;
				return RIGHT;
			} else {
				cout << "LEFT" << endl;
				return LEFT;
			}
		}

		if(SDL_HasIntersection(&ny_ball_rect, &racket_rect)) {
			if (dy < 0) {
				cout << "TOP" << endl;
				return TOP;
			} else {
				cout << "BOTTOM" << endl;
				return BOTTOM;
			}
		}
	}

	return NONE;
}

Ball::Ball(Game *game) : Entity(game, 0, 0, DFL_BALL_RADIUS * 2, DFL_BALL_RADIUS * 2){
	int win_width = game->get_app()->get_width();
	int win_height = game->get_app()->get_height();
	x = (win_width - width) / 2;
	y = (win_height - height) / 2;

	dx = DFL_BALL_X_SPEED;
	dy = DFL_BALL_Y_SPEED;
}

void Ball::update(double dt){
	double nx = x + dx * dt;
	double ny = y + dy * dt;

	if (nx < 0) {
		game->ball_touch_left();
		return;
	}

	if(nx >= game->get_app()->get_width()) {
		game->ball_touch_right();
		return;
	}

	if (ny < 0 || ny + height >= game->get_app()->get_height()) {
		scale_speed(1, -1);
	}

	Player *target = x < game->get_app()->get_width() / 2 ? game->get_player_left() : game->get_player_right();
	switch (collide(target, nx, ny)) {
		case LEFT:
		case RIGHT:
			dx *= -1;
			break;
		case TOP:
		case BOTTOM:
			dy *= -1;
			break;
		default:
			break;
	}
	

	x += dx * dt;
	y += dy * dt;
}

Ball::~Ball() {
}
