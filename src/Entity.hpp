#pragma once

#include <SDL.h>

class View;

class Entity {
	protected:
		double x, y;
		double dx, dy;
		double width, height;
		View *view;

	public:
		Entity(View *view, double x, double y, double width, double height);
		void scale_speed(double sx, double sy) { dx *= sx; dy *= sy; }
		void set_x(double x) { this->x = x; }
		void set_y(double y) { this->y = y; }
		void set_dx(double dx) { this->dx = dx; }
		void set_dy(double dy) { this->dy = dy; }
		double get_x() { return x; }
		double get_y() { return y; }
		double get_width() { return width; }
		double get_height() { return height; }
		virtual void handle_event(SDL_Event event) {}
		virtual void update(double dt) {}
		virtual void draw(SDL_Renderer *rend);
		~Entity();
};