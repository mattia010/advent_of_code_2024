#ifndef DAY4_H_
#define DAY4_H_

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

namespace day4 {
    unsigned long solve_part1(std::string filepath);
    unsigned long solve_part2(std::string filepath);
    std::pair<std::vector<char>, unsigned long> parse_input(std::string filepath);
    unsigned long count_pattern_occ(std::pair<std::vector<char>, unsigned long> pair, std::string pattern);
    unsigned long count_pattern_occ(std::pair<std::vector<char>, unsigned long> pair, std::string pattern, unsigned long pos);
    unsigned long count_x_pattern_occ(std::pair<std::vector<char>, unsigned long> pair, std::string pattern);
    bool is_x_pattern_present(std::pair<std::vector<char>, unsigned long> pair, std::string pattern, unsigned long pos);
}

#endif