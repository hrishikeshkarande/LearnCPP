# Rule to make our program when
# ’drawMaze.o’ and ’main.o’ are compiled:
main: drawMaze.o main.o
	g++ drawMaze.o main.o -o main -l ncursesw

# Rule for dependency 'main.o':
main.o: main.cpp drawMaze.h
	g++ -c main.cpp -std=c++17

# Rule for dependency 'drawMaze.o':
drawMaze.o: drawMaze.cpp drawMaze.h
	g++ -c drawMaze.cpp -std=c++17