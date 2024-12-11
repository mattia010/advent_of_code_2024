#include <iostream>

#include <filesystem> // tmp

#include "day10.hpp"

int main(int argc, char* argv[]) {
    Day10::matrix *m = Day10::parseInput("inputs/day10");
    if (m) {
        std::cout << "Score sum: " << Day10::calc_sum_trailheads_scores(m) << std::endl;
        std::cout << "Ratings sum: " << Day10::calc_sum_trailheads_ratings(m) << std::endl;
    }
}