#Makefile

CC = gcc
CFLAGS = -Wall -Wextra -O3 
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -fsanitize=address

SRC = main.c graphicsEngine.c initVulkan.c
OBJ = $(SRC:.c=.o)

all: main

main: $(OBJ)

.PHONY: clean

clean:
	rm main *.o

#END
