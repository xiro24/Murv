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
	
	spriteSheet = TextureManager::LoadTexture("images/world.png");
	
	/*grass*/
	spriteCell[0].x = 0;
	spriteCell[0].y = 0;
	spriteCell[0].w = 32;
	spriteCell[0].h = 32;
	
	/*rock*/
	spriteCell[1].x = 64;
	spriteCell[1].y = 32;
	spriteCell[1].w = 32;
	spriteCell[1].h = 32;
	
	/*Defaults all tiles to zero*/
	int room[24][24];
	for (int row =0; row <24; row++) {
		for (int col =0 ; col <24 ; col++) {
			room[row][col] = 0;
		}
	}
	
	LoadMap(room);
	
	dest.w=dest.h=32;
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
				/*grass*/
					TextureManager::Draw(spriteSheet,spriteCell[0],dest);
				break;
				case 1:
				/*rock*/
					TextureManager::Draw(spriteSheet,spriteCell[1],dest);
				break;
				case 2:
				/*water*/
					TextureManager::Draw(spriteSheet,spriteCell[0],dest);
				break;
				case 3:
				/*strpathg*/
					TextureManager::Draw(spriteSheet,spriteCell[0],dest);
				break;
				default:
				break;
			}
		}
	}
	
}	