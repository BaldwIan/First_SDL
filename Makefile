OBJS = main.cpp game.cpp TextureManager.cpp GameObject.cpp Map.cpp

OBJ_NAME = SDLFirst

INCLUDE_PATH = \Users\Monka2e\Development\SDL2_MinGW_32Bit\include
LIB_PATH = \Users\Monka2e\Development\SDL2_MinGW_32Bit\lib

all : $(OBJS)
	g++ $(OBJS) -IC:$(INCLUDE_PATH) -LC:$(LIB_PATH) -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o $(OBJ_NAME)