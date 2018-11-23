OBJS = Display.cpp Display.hpp MurvCore.cpp TextureManager.h TextureManager.cpp DisplayObject.h DisplayObject.cpp Map.h Map.cpp Vector2D.h Vector2D.cpp
ECS = ECS/MainComponent.h ECS/ECS.h ECS/TransformComponents.h ECS/SpriteComponent.h
Controls = ECS/Controls/Keyboard.h
INCLUDE_PATH = -I..\DEV\include
LIBRARY_PATH = -L..\DEV\lib
COMPILE_FLAG = -w 
FINISHED_COMFILE_FLAG = -Wl,-subsystem,windows
LINKER_FLAG = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
OTHER = -std=c++11
OBJ_NAME = Murv
CC = g++

all : $(OBJS)
	$(CC) $(OBJS) $(Controls) $(ECS) $(INCLUDE_PATH) $(LIBRARY_PATH) $(COMPILE_FLAG) $(LINKER_FLAG) $(OTHER)  -o $(OBJ_NAME)
	
clean:
	rm $(OBJ_NAME)