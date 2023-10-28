CC=g++
CFLAGS=-Wall -Wextra

LIB=-L"D:\ThemeParkDesigner\dependencies\GLFW\lib"
INC=-I"D:\ThemeParkDesigner\dependencies\GLFW\inc"

graphics: main.cpp graphicsEngine\graphics_engine.cpp
	${CC} ${CFLAGS} ${LIB} ${INC} main.cpp graphicsEngine\graphics_engine.cpp -o build\graphics.exe
	.\build\graphics.exe