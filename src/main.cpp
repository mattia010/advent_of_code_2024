#include <iostream>

#include <filesystem> // tmp

#include "src/day10.hpp"
#include "src/day11.hpp"

int main(int argc, char *argv[])
{
    std::vector<unsigned long long> *day11in = day11::parseInput("inputs/day11");
    std::cout << "Number of stones: " << day11::countStones(day11in, 75) << std::endl;

    day10::matrix *m = day10::parseInput("inputs/day10");
    if (m)
    {
        std::cout << "Score sum: " << day10::calc_sum_trailheads_scores(m) << std::endl;
        std::cout << "Ratings sum: " << day10::calc_sum_trailheads_ratings(m) << std::endl;
    }
}