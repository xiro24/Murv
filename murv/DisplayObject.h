/*displayobject*/
#pragma once
#include "Display.hpp"
#include "TextureManager.h"

class DisplayObject {
	public:
		DisplayObject(const char* texturesheet,int x,int y);
		~DisplayObject();
		
		void Update();
		void Render();
	private:
	
		int xpos;
		int ypos;
		
		SDL_Texture* objTex;
		SDL_Rect srcRect,destRect;

};