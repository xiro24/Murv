#pragma once

#include "ECS.h"
#include "../Vector2D.h"

class TransformComponents : public Components {

public:
	
	Vector2D position;
	Vector2D velocity;
	
	int speed=3;
	
	TransformComponents() {
		position.x =0.0f;
		position.y=0.0f;
	}
	
	TransformComponents(float x, float y) {
		position.x =x;
		position.y =y;
		
	}
	int x() {
		return position.x;
	}
		
	int y() {
		return position.y;
	}
	
	void init() override {
		velocity.x =0;
		velocity.y =0;
	}
	
	void update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
		
	}
	
	void setPos(float x, float y) {
		position.x = x;
		position.y = y;
	}
};