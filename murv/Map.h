/**/
#pragma once
#include "Murv.hpp"

class Map {
	public:
		Map();
		~Map();
		void LoadMap(int arr[24][24]);
		void DrawMap();
		
	private:
		
		SDL_Rect src,dest;
		SDL_Texture* grass;
		SDL_Texture* rock;
		SDL_Texture* water;
		SDL_Texture* strpathg;
		
		int map[24][24];
};