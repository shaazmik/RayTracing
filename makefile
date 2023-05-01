all:
	g++ ./src/main.cpp ./src/Vector/vector.cpp ./src/general.cpp ./src/Coordinate_System/coordinate.cpp ./src/Sphere/sphere.cpp  -o a.out  -lsfml-graphics -lsfml-window -lsfml-system