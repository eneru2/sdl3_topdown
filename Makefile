compile: build run

build:
	gcc ./src/main.c -o ./out/sdl_game.exe -lSDL3

run:
	./out/sdl_game.exe