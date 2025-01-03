#ifndef DAY11_H_
#define DAY11_H_

#include <vector>
#include <cmath>
#include <string>
#include <fstream>

namespace day11 {
    struct memo {
        unsigned long long stone;
        int blinks;
        unsigned long long res;

        memo(unsigned long long stone_param, int blinks_param, unsigned long long res_param) : stone{stone_param}, blinks{blinks_param}, res{res_param} {}
    };

    std::vector<unsigned long long>* parse_input(std::string filepath);
    unsigned long long count_stones(std::vector<unsigned long long> *p_stones, int blinks);
    unsigned long long count_stones(unsigned long long stone, int blinks, std::vector<memo*> *p_memos);
}

#endif