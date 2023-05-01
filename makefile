all:
	g++ ./src/main.cpp ./src/Vector/vector.cpp -o a.out -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system

dev:
	g++ ./src/main.cpp ./src/Vector/vector.cpp -o a.out -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system -fsanitize=address,leak
