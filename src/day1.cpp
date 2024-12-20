#include "src/day1.hpp"

std::array<std::vector<unsigned long>, 2> day1::parse_input(std::string filepath) {
    std::ifstream in(filepath, std::ios_base::in);
    std::vector<unsigned long> l1 = std::vector<unsigned long>();
    std::vector<unsigned long> l2 = std::vector<unsigned long>();
    unsigned long x, y;
    while (in >> x && in >> y) {
        l1.push_back(x);
        l2.push_back(y);
    }
    return std::array<std::vector<unsigned long>, 2>{l1, l2};
}

unsigned long day1::count_total_distance(std::vector<unsigned long> l1, std::vector<unsigned long> l2) {
    if (l1.size() != l2.size()) {
        throw std::invalid_argument("two lists have different dimensions");
    }
    std::sort(l1.begin(), l1.end());
    std::sort(l2.begin(), l2.end());
    unsigned long res = 0;
    for (unsigned long i = 0; i < l1.size(); ++i) {
        if (l1.at(i) > l2.at(i)) {
            res += l1.at(i) - l2.at(i);
        } else {
            res += l2.at(i) - l1.at(i);
        }
    }
    return res;
}

unsigned long day1::similarity_score(std::vector<unsigned long> l1, std::vector<unsigned long> l2) {
    if (l1.size() != l2.size()) {
        throw std::invalid_argument("two lists have different dimensions");
    }
    std::sort(l1.begin(), l1.end());
    std::sort(l2.begin(), l2.end());
    unsigned long x = 0, y = 0, el;
    unsigned int occ1, occ2, res = 0;
    while (x < l1.size() && y < l2.size()) {
        while (x < l1.size() && y < l2.size() && l1.at(x) != l2.at(y)) {
            l1.at(x) < l2.at(y) ? ++x : ++y;
        }
        occ1 = 0;
        occ2 = 0;
        el = l1.at(x);
        while (x < l1.size() && l1.at(x) == el) {
            ++occ1;
            ++x;
        }
        while (y < l2.size() && l2.at(y) == el) {
            ++occ2;
            ++y;
        }
        res += el * occ1 * occ2;
    }
    return res;
}

unsigned long day1::solve_part1(std::string filepath) {
    std::array<std::vector<unsigned long>, 2> in = day1::parse_input(filepath);
    return count_total_distance(in.at(0), in.at(1));
}

unsigned long day1::solve_part2(std::string filepath) {
    std::array<std::vector<unsigned long>, 2> in = day1::parse_input(filepath);
    return similarity_score(in.at(0), in.at(1));
}