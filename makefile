CXX = clang++
CXXFLAGS = -O3 -g -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system
SRC = $(wildcard ./src/*.cpp ./src/*/*.cpp)
OBJ = $(SRC:.cpp=.o)

all: a.out

a.out: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

dev: CXXFLAGS += -fsanitize=address,leak
dev: a.out

clean:
	rm -f $(OBJ) a.out
