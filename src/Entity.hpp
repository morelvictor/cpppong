#pragma once

#include <SDL.h>

class Game;

class Entity {
	protected:
		double x, y;
		double dx, dy;
		double width, height;
		Game *game;

	public:
		Entity(Game *game, double x, double y, double width, double height);
		void scale_speed(double sx, double sy) { dx *= sx; dy *= sy; }
		void set_x(double x) { this->x = x; }
		void set_y(double y) { this->y = y; }
		void set_dx(double dx) { this->dx = dx; }
		void set_dy(double dy) { this->dy = dy; }
		double get_x() { return x; }
		double get_y() { return y; }
		double get_width() { return width; }
		double get_height() { return height; }
		virtual void handle_event(SDL_Event event);
		virtual void update(double dt) = 0;
		virtual void draw(SDL_Renderer *rend);
		~Entity();
};