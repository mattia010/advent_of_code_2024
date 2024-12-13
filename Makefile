INCLUDE_DIR = .

aoc: main day9 day10
	g++ -I"$(INCLUDE_DIR)" bin/day9.o bin/day10.o bin/main.o -o bin/aoc.out

main:
	g++ -I"$(INCLUDE_DIR)" -c src/main.cpp -o bin/main.o

day9:	src/day9.cpp src/day9.hpp
	g++ -I"$(INCLUDE_DIR)" -c src/day9.cpp -o bin/day9.o

day10:	src/day10.cpp src/day10.hpp
	g++ -I"$(INCLUDE_DIR)" -c src/day10.cpp -o bin/day10.o
