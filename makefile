all:
	clang++ ./src/main.cpp ./src/Raytracing/Scene_objects/scene_objects.cpp ./src/Raytracing/quadratic_equation/quadratic_equation.cpp ./src/Graphics/pscolor.cpp ./src/Raytracing/raytracing.cpp ./src/Widget_manager/widget_manager.cpp ./src/Vector/vector.cpp ./src/Widget/widget.cpp ./src/log/log.cpp ./src/Graphics/graphics.cpp -o a.out -g -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system

dev:
	clang++ ./src/main.cpp ./src/Raytracing/Scene_objects/scene_objects.cpp ./src/Raytracing/quadratic_equation/quadratic_equation.cpp ./src/Graphics/pscolor.cpp ./src/Raytracing/raytracing.cpp ./src/Widget_manager/widget_manager.cpp ./src/Vector/vector.cpp ./src/Widget/widget.cpp ./src/log/log.cpp ./src/Graphics/graphics.cpp  -o a.out -g -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system -fsanitize=address,leak
