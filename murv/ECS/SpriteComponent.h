/**/
#pragma once

#include "ECS.h"
#include "TransformComponents.h"
#include "../TextureManager.h"
#include "SDL2/SDL.h"

class SpriteComponent : public Components  {
	private:
		TransformComponents *transform;
		SDL_Texture *texture;
		SDL_Rect srcRect, destRect;
		
	public:
		SpriteComponent() = default;
		SpriteComponent(const char* path) {
			setTexture(path);
		}
		
		void setTexture(const char* path) {
			texture = TextureManager::LoadTexture(path);
		}
		
		void init() override {
			transform = &entity->getComponent<TransformComponents>();
			
			/*cut*/
			srcRect.x = srcRect.y =0;
			/*zoom*/
			srcRect.w = srcRect.h =32;
			/*scale*/
			destRect.w = destRect.h = 64;
		}
		
		void update() override {
			destRect.x = (int)transform->position.x;
			destRect.y = (int)transform->position.y;
		}
		
		void draw() override {
			TextureManager::Draw(texture,srcRect,destRect);
		}
};