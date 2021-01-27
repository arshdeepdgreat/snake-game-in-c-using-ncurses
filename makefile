candr:main.cpp ui.cpp game.cpp snake.cpp food.cpp
	g++ main.cpp ui.cpp game.cpp snake.cpp food.cpp -l ncurses -o slither && ./slither
clear:
	rm -f slither