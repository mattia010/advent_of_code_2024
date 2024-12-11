aoc: main day10
	g++ bin/day10.o bin/main.o -o bin/aoc.out

main:
	g++ -c src/main.cpp -o bin/main.o

day10:	src/day10.cpp src/day10.hpp
	g++ -c src/day10.cpp -o bin/day10.o
