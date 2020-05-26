OBJS = ./../src/*.cpp ./../libs/3D_vector_math/src/*.cpp ./../libs/SDL2_gfx/*.c

OBJ_NAME = main

all : $(OBJS)
	g++ $(OBJS) -IC:\cpp_projects\libs\SDL2_MinGW_32Bit\include -LC:\cpp_projects\libs\SDL2_MinGW_32Bit\lib -lmingw32 -lSDL2main -lSDL2 -Ofast -o $(OBJ_NAME)