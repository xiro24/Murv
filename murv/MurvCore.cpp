#include "Display.hpp"

Display *display = nullptr;

int main(int argc, const char* argv[]) {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	
	Uint32 framestart;
	int frameTime;
	
	display = new Display();
	
	/*system("start cmd.exe /c dir c:\\");*/
	display->init("title",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,400,false);
	while (display->running()){
		
		framestart =SDL_GetTicks();
		
		
		display->handleEvents();
		display->update();
		display->render();
		
		frameTime = SDL_GetTicks() - framestart;
		
		if (frameDelay > frameTime){
			SDL_Delay(frameDelay-frameTime);
		}
	}
	display->clean();
	return 0;
}