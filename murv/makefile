OBJS = Murv.cpp Murv.hpp MurvCore.cpp TextureManager.h TextureManager.cpp DisplayObject.h DisplayObject.cpp Map.h Map.cpp
INCLUDE_PATH = -IC:\Users\lay00\Documents\cpp-projects\dev\i686-w64-mingw32\include
LIBRARY_PATH = -LC:\Users\lay00\Documents\cpp-projects\dev\i686-w64-mingw32\lib
COMPILE_FLAG = -w 
FINISHED_COMFILE_FLAG = -Wl,-subsystem,windows
LINKER_FLAG = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
OTHER = -std=c++11
OBJ_NAME = Murv
CC = g++

all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATH) $(LIBRARY_PATH) $(COMPILE_FLAG) $(LINKER_FLAG) $(OTHER)  -o $(OBJ_NAME)
	
clean:
	rm $(OBJ_NAME)