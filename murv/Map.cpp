/*map.cpp*/
#include "Map.h"
#include "TextureManager.h"


/*int room[24][24] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};*/

Map::Map() {
	
	grass = TextureManager::LoadTexture("images/pixil-frame-0.png");
	rock = TextureManager::LoadTexture("images/pixil-frame-0.png");
	water = TextureManager::LoadTexture("images/pixil-frame-0.png");
	strpathg = TextureManager::LoadTexture("images/pixil-frame-0.png");
	
	/*Defaults all tiles to zero*/
	int room[24][24];
	for (int row =0; row <24; row++) {
		for (int col =0 ; col <24 ; col++) {
			room[row][col] = 0;
		}
	}
	
	LoadMap(room);
	
	src.x=src.y=0;
	src.w=dest.w=32;
	src.h=dest.h=32;
	dest.x=dest.y =0;

}

void Map::LoadMap(int arr[24][24]) {
	for (int row =0; row <24; row++) {
		for (int col =0 ; col <24 ; col++) {
			map[row][col] = arr[row][col];
		}
	}
	
}

void Map::DrawMap() {
	int type=0;
	for (int row =0; row <24; row++) {
		for (int col =0 ; col <24 ; col++) {
			type = map[row][col];
			dest.x=col*32;
			dest.y=row*32;
			switch(type) {
				case 0:
					TextureManager::Draw(grass,src,dest);
				break;
				case 1:
					TextureManager::Draw(rock,src,dest);
				break;
				case 2:
					TextureManager::Draw(water,src,dest);
				break;
				case 3:
					TextureManager::Draw(strpathg,src,dest);
				break;
				default:
				break;
			}
		}
	}
	
}	