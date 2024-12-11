#include <iostream>

#include "day10.hpp"

int main(int argc, char* argv[]) {
    Day10::matrix *m = Day10::parseInput("../inputs/day10");
    if (m) {
        std::cout << "Score sum: " << Day10::calc_sum_trailheads_score(m) << std::endl;
    }
}