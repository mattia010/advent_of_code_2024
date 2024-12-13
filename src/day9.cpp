#include "src/day9.hpp"

#include <iostream>

std::vector<unsigned long long>* day9::parseInput(std::string filepath) {
    std::ifstream in(filepath, std::ios_base::in);
    std::vector<unsigned long long>* p_stones = new std::vector<unsigned long long>;
    unsigned long long num;
    while (in >> num) {
        p_stones->push_back(num);
    }
    return p_stones;
}

unsigned long long day9::countStones(std::vector<unsigned long long> *p_stones, int blinks) {
    std::vector<memo*> *p_memos = new std::vector<memo*>;
    unsigned long long 
res = 0;
    for (auto it = p_stones->begin(); it != p_stones->end(); ++it) {
        res += countStones(*it, blinks, p_memos);
    }
    return res;
}

unsigned long long day9::countStones(unsigned long long stone, int blinks, std::vector<memo*> *p_memos) {
    if (blinks == 0) {
        return 1;
    }
    for (auto it = p_memos->begin(); it != p_memos->end(); ++it) {
        if ((*it)->stone == stone && (*it)->blinks == blinks) {
            return (*it)->res;
        }
    }

    unsigned long long 
res = 0;
    if (stone == 0) {
        res = countStones(1, blinks-1, p_memos);
        p_memos->push_back(new memo(stone, blinks, res));
        return res;
    } else {
        int digits = 0;
        unsigned long long tmp_num = stone;
        while (tmp_num != 0) {
            tmp_num = tmp_num / 10;
            ++digits;
        }
        if (digits % 2 == 0) {
            unsigned long long left = floor(stone / pow(10, digits / 2)); 
            unsigned long long right = stone - left * pow(10, digits / 2);
            res = countStones(left, blinks-1, p_memos) + countStones(right, blinks-1, p_memos);
            p_memos->push_back(new memo(stone, blinks, res));
            return res;
        } else {
            res = countStones(stone * 2024, blinks-1, p_memos);
            p_memos->push_back(new memo(stone, blinks, res));
            return res;
        }
    }
}