#ifndef DAY1_H_
#define DAY1_H_
    
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <algorithm>

namespace day1 {
    std::array<std::vector<unsigned long>, 2> parse_input(std::string filepath);
    unsigned long count_total_distance(std::vector<unsigned long> l1, std::vector<unsigned long> l2);
    unsigned long similarity_score(std::vector<unsigned long> l1, std::vector<unsigned long> l2);
    unsigned long solve_part1(std::string filepath);
    unsigned long solve_part2(std::string filepath);
}

#endif