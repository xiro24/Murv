/*Key control*/
#pragma once

#include <iostream>
#include "../../Display.hpp"
#include "../SpriteComponent.h"

class Keyboard : public Components {
	public:
		TransformComponents *transform;
		
		void init() override {
			transform = &entity->getComponent<TransformComponents>();
		}
		/*FIX THIS*/
		void update() override {
			/*keypressed*/
			if (Display::event.type == SDL_KEYDOWN) {
				switch (Display::event.key.keysym.sym) {
					case SDLK_w:
						transform->velocity.y = -1;
					break;
					case SDLK_a:
						transform->velocity.x = -1;
					break;
					case SDLK_d:
						transform->velocity.x = 1;
					break;
					case SDLK_s:
						transform->velocity.y = 1;
					break;
				}
			}
			/*keyreleased*/
			if (Display::event.type == SDL_KEYUP) {
				switch (Display::event.key.keysym.sym) {
					case SDLK_w:
						transform->velocity.y = 0;
					break;
					case SDLK_a:
						transform->velocity.x = 0;
					break;
					case SDLK_d:
						transform->velocity.x = 0;
					break;
					case SDLK_s:
						transform->velocity.y = 0;
					break;
				}
			}
		}
};