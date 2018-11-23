#ifndef Display_hpp
#define Display_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#undef main

class Display {
	public:
		Display();
		virtual ~Display();
		
		void init(const char* title, int xpos, int ypos, int width, int height ,bool fullscreen);
		
		void handleEvents();
		void update();
		void render();
		void clean();
		
		static SDL_Renderer *renderer;
		static SDL_Event event;
		bool  running(){return isRunning;}
		
	private:
		int count=0;
		bool isRunning;
		SDL_Window *window;
};


#endif