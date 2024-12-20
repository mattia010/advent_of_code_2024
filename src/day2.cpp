#include "src/day2.hpp"

unsigned long day2::solve_part1(std::string filepath) {
    std::ifstream in(filepath, std::ios_base::in);
    std::string line;
    std::vector<unsigned long> q;
    unsigned long el, res = 0;
    bool is_safe;
    while (std::getline(in, line)) {
        is_safe = true;
        q.clear();
        std::istringstream is(line);
        while (is >> el) {
            q.push_back(el);
        }
        if (q.size() >= 2) {
            bool is_decr = q.at(0) > q.at(1);
            for (unsigned long i = 0; i < q.size() - 1; ++i) {
                if ((q.at(i) > q.at(i+1) && !is_decr) || (q.at(i) < q.at(i+1) && is_decr)) {
                    is_safe = false;
                    break;
                }
                if (abs(q.at(i) - q.at(i+1)) < 1 || abs(q.at(i) - q.at(i+1)) > 3) {
                    is_safe = false;
                    break;
                }
            }
        }
        if (is_safe) {
            ++res;
        }
    }
    return res;
}

unsigned long day2::solve_part2(std::string filepath) {
    std::ifstream in(filepath, std::ios_base::in);
    std::string line;
    std::vector<unsigned long> q;
    unsigned long el, res = 0;
    unsigned int bad_levels;
    while (std::getline(in, line)) {
        q.clear();
        bad_levels = 0;
        std::istringstream is(line);
        while (is >> el) {
            q.push_back(el);
        }

        if (q.size() == 2 && (q.at(0) == q.at(1))) {
            ++bad_levels;
        } 
        if (q.size() > 2) {
            bool is_decr = true;
            for (unsigned long i = 0; i < q.size() - 1; ++i) {
                if (q.at(i) != q.at(i+1)) {
                    is_decr = q.at(i) > q.at(i+1);
                }
            }
            for (unsigned long i = 0; i < q.size() - 1; ++i) {
                if (q.at(i) == q.at(i+1)) {
                    ++bad_levels;
                    continue;
                }
                if (((q.at(i) > q.at(i+1)) && (!is_decr)) || ((q.at(i) < q.at(i+1)) && is_decr)) {
                    ++bad_levels;
                    continue;
                }
                unsigned long tmp;
                if (q.at(i) > q.at(i+1)) {
                    tmp = q.at(i) - q.at(i+1);
                } else {
                    tmp = q.at(i+1) - q.at(i);
                }
                if (tmp < 1 || tmp > 3) {
                    ++bad_levels;
                    continue;
                }
            }
        }
        if (bad_levels <= 1) {
            ++res;
        }
    }
    return res;
}