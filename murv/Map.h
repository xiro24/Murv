/**/
#pragma once
#include "Display.hpp"

class Map {
	public:
		Map();
		~Map();
		void LoadMap(int arr[24][24]);
		void DrawMap();
		
	private:
		
		SDL_Rect dest;
		SDL_Rect spriteCell[4];
		SDL_Texture* spriteSheet;
		
		int map[24][24];
};