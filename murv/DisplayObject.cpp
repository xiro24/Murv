/*display object*/

#include "DisplayObject.h"
#include "TextureManager.h"

DisplayObject::DisplayObject(const char* texturesheet,int x,int y) {
	
	objTex = TextureManager::LoadTexture(texturesheet);
	
	xpos = x;
	ypos = y;
}


/*movement*/
void DisplayObject::Update() {

	/*xpos=86;
	ypos=86;*/
	
	srcRect.h = 32;
	srcRect.w =32;
	
	srcRect.x = 0;
	srcRect.y = 0;
	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w*2;
	destRect.h = srcRect.h*2;
}

void DisplayObject::Render() {
	SDL_RenderCopy(Display::renderer,objTex,&srcRect,&destRect);
}