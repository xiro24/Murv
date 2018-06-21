#include <iostream>
#include <stdlib.h>
#include "Murv.hpp"
#include "TextureManager.h"
#include "DisplayObject.h"
#include "Map.h"

DisplayObject* player;
Map* map;
SDL_Renderer* Display::renderer = nullptr;


int w, h;

Display::Display() 
{}
Display::~Display()
{}

void Display::init(const char* title, int xpos, int ypos, int width, int height ,bool fullscreen)
{
	
	int flags =0;
	
	if (fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING)<0) {
		std::cout << "SDL could not initialise!";
	} else if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialised...." << std::endl;
		
		window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
		if (window) {
			std::cout << "Window created" << std::endl;
		}
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		
		
		
		if (renderer) {
			SDL_SetRenderDrawColor(renderer,34,139,34,255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	} else {
		isRunning = false;
	}
	map= new Map();
	player = new DisplayObject("images/pixil-frame-0.png",0,0);
	/*texture = TextureManager::LoadTexture("images/pixil-frame-0.png",renderer);*/
		
		/*image = IMG_Load("images/pixil-frame-0.png");
		texture = SDL_CreateTextureFromSurface(renderer, image);
		*/
		/*gets the full width and height of the image
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);*/
		/*frees the image since it has already loaded into the program
		SDL_FreeSurface(image);*/
}

void Display::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	
switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Display::update()
{
	player->Update();
}

void Display::render()
{
	/*this resets each frame buddy*/
	SDL_RenderClear(renderer);
	map->DrawMap();
	/*SDL_RenderCopy(renderer, texture, 0, &destR);*/
	player->Render();
	SDL_RenderPresent(renderer);
	
	
}

void Display::clean()
{
	/*SDL_DestroyTexture(texture);*/
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
