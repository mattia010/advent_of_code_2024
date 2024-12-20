#ifndef DAY5_H_
#define DAY5_H_

#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iostream>

namespace day5 {
    unsigned long solve_part1(std::string filepath);
    unsigned long solve_part2(std::string filepath);
    bool is_update_correctly_ordered(std::unordered_map<unsigned long, std::vector<unsigned long>> m, std::vector<unsigned long> l);
    std::vector<unsigned long>* order_update(std::unordered_map<unsigned long, std::vector<unsigned long>> m, std::vector<unsigned long>* l);
}

#endif