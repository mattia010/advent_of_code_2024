#include "day5.hpp"

unsigned long day5::solve_part1(std::string filepath) {
    std::ifstream in(filepath, std::ios_base::in);
    std::string line, keyStr, valueStr;
    std::istringstream is;
    unsigned long res = 0;

    std::unordered_map<unsigned long, std::vector<unsigned long>> rules;
    while (std::getline(in, line) && line != "") {
        is = std::istringstream(line);
        std::getline(is, keyStr, '|');
        std::getline(is, valueStr, '|');
        rules[std::stoul(keyStr)].push_back(std::stoul(valueStr));
    }

    std::vector<unsigned long> update;
    while (std::getline(in, line)) {
        update.clear();
        is = std::istringstream(line);
        while (std::getline(is, valueStr, ',')) {
            update.push_back(std::stoul(valueStr));
        }
        if (day5::is_update_correctly_ordered(rules, update)) {
            res += update.at(update.size() / 2);
        }
    }
    return res;
}

unsigned long day5::solve_part2(std::string filepath) {
    std::ifstream in(filepath, std::ios_base::in);
    std::string line, keyStr, valueStr;
    std::istringstream is;
    unsigned long res = 0;

    std::unordered_map<unsigned long, std::vector<unsigned long>> m;
    while (std::getline(in, line) && line != "") {
        is = std::istringstream(line);
        std::getline(is, keyStr, '|');
        std::getline(is, valueStr, '|');
        m[std::stoul(keyStr)].push_back(std::stoul(valueStr));
    }

    std::vector<unsigned long> v;
    while (std::getline(in, line)) {
        v.clear();
        is = std::istringstream(line);
        while (std::getline(is, valueStr, ',')) {
            v.push_back(std::stoul(valueStr));
        }
        if (!day5::is_update_correctly_ordered(m, v)) {
            day5::order_update(m, &v);
            res += v.at(v.size() / 2);
        }
    }
    return res;
}

bool day5::is_update_correctly_ordered(std::unordered_map<unsigned long, std::vector<unsigned long>> m, std::vector<unsigned long> l) {
    for (unsigned long i = 0; i < l.size() - 1; ++i) {
        if(std::find(m[l.at(i)].begin(), m[l.at(i)].end(), l.at(i+1)) == m[l.at(i)].end()) {
            return false;
        } 
    }
    return true;
}

std::vector<unsigned long>* day5::order_update(std::unordered_map<unsigned long, std::vector<unsigned long>> m, std::vector<unsigned long>* l) {
    long j;
    unsigned long value;
    for (long i = 1; i < l->size(); ++i) {
        j = i-1;
        value = l->at(i);
        while (j >= 0 && (std::find(m[value].begin(), m[value].end(), l->at(j)) != m[value].end())) {
            l->at(j+1) = l->at(j);
            --j;
        }
        l->at(j+1) = value;
    }
    return l;
} 