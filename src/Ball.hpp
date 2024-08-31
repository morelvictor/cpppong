#pragma once

#include "Entity.hpp"

enum CollisionSide { NONE, TOP, RIGHT, BOTTOM, LEFT };

class Ball : public Entity {
	private:
		CollisionSide collide(Entity *entity, double nx, double ny);

	public:
		Ball(Game *game);
		void update(double dt) override;
		~Ball();
};