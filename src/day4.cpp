#include "src/day4.hpp"

unsigned long day4::solve_part1(std::string filepath) {
    return day4::count_pattern_occ(day4::parse_input(filepath), "XMAS");
}

unsigned long day4::solve_part2(std::string filepath) {
    return day4::count_x_pattern_occ(day4::parse_input(filepath), "MAS");
}

std::pair<std::vector<char>, unsigned long> day4::parse_input(std::string filepath) {
    std::ifstream in(filepath);
    std::istringstream is;
    std::string line;
    char c;
    std::vector<char> m;
    unsigned long rows = 0;
    while (std::getline(in, line)) {
        ++rows;
        is = std::istringstream(line);
        while (is >> c) {
            m.push_back(c);
        }
    }
    unsigned long columns = m.size() / rows;
    return std::pair<std::vector<char>, unsigned long>(m, columns);
}

unsigned long day4::count_pattern_occ(std::pair<std::vector<char>, unsigned long> pair, std::string pattern) {
    unsigned long res = 0;
    for (unsigned long i = 0; i < pair.first.size(); ++i) {
        if (pair.first.at(i) == pattern.at(0)) {
            res += count_pattern_occ(pair, pattern, i);
        }
    }
    return res;
}

unsigned long day4::count_pattern_occ(std::pair<std::vector<char>, unsigned long> pair, std::string pattern, unsigned long pos) {
    if (pattern.length() == 0) {
        return 1;
    }
    bool up = pos >= (pattern.length() - 1) * pair.second;
    bool down = pos + ((pattern.length() - 1) * pair.second) < pair.first.size();
    bool left = pos % pair.second >= pattern.length() - 1;
    bool right = pos % pair.second + (pattern.length() - 1) < pair.second;
    unsigned long res = 0;
    if (up) {
        ++res;
        for (unsigned long i = 0; i < pattern.length(); ++i) {
            if (pair.first.at(pos - (i * pair.second)) != pattern.at(i)) {
                --res;
                break;
            }
        }
    }
    if (down) {
        ++res;
        for (unsigned long i = 0; i < pattern.length(); ++i) {
            if (pair.first.at(pos + (i * pair.second)) != pattern.at(i)) {
                --res;
                break;
            }
        }
    }
    if (left) {
        ++res;
        for (unsigned long i = 0; i < pattern.length(); ++i) {
            if (pair.first.at(pos - i) != pattern.at(i)) {
                --res;
                break;
            }
        }
    }
    if (right) {
        ++res;
        for (unsigned long i = 0; i < pattern.length(); ++i) {
            if (pair.first.at(pos + i) != pattern.at(i)) {
                --res;
                break;
            }
        }
    }

    if (up && left) {
        ++res;
        for (unsigned long i = 0; i < pattern.length(); ++i) {
            if (pair.first.at(pos - i - (i * pair.second)) != pattern.at(i)) {
                --res;
                break;
            }
        }
    }
    if (up && right) {
        ++res;
        for (unsigned long i = 0; i < pattern.length(); ++i) {
            if (pair.first.at(pos + i - (i * pair.second)) != pattern.at(i)) {
                --res;
                break;
            }
        }
    }
    if (down && left) {
        ++res;
        for (unsigned long i = 0; i < pattern.length(); ++i) {
            if (pair.first.at(pos - i + (i * pair.second)) != pattern.at(i)) {
                --res;
                break;
            }
        }
    }
    if (down && right) {
        ++res;
        for (unsigned long i = 0; i < pattern.length(); ++i) {
            if (pair.first.at(pos + i + (i * pair.second)) != pattern.at(i)) {
                --res;
                break;
            }
        }
    }
    return res;
}

unsigned long day4::count_x_pattern_occ(std::pair<std::vector<char>, unsigned long> pair, std::string pattern) {
    if (pattern.length() % 2 == 0) {
        return 0;
    }
    unsigned long res = 0;
    for (unsigned long i = 0; i < pair.first.size(); ++i) {
        res += is_x_pattern_present(pair, pattern, i);
    }
    return res;
}

bool day4::is_x_pattern_present(std::pair<std::vector<char>, unsigned long> pair, std::string pattern, unsigned long pos) {
    if (pattern.length() % 2 == 0) {
        return false;
    }
    bool std = true, rev = true;
    unsigned long curr_pos, half_length = pattern.size() / 2;
    if (half_length * pair.second > pos) {
        return false;
    }
    if (pos + half_length * pair.second >= pair.first.size()) {
        return false;
    }
    if (pos % pair.second < half_length) {
        return false;
    }
    if (pos % pair.second + half_length >= pair.second) {
        return false;
    }
    for (unsigned long i = 0; i < pattern.size(); ++i) {
        curr_pos = pos + i * (pair.second + 1) - ((pair.second + 1) * half_length);
        if (pair.first.at(curr_pos) != pattern.at(i)) {
            std = false;
        }
        if (pair.first.at(curr_pos) != pattern.at(pattern.size() - 1 - i)) {
            rev = false;
        }
        if (!std && !rev) {
            return false;
        }
    }
    std = true;
    rev = true;
    for (unsigned long i = 0; i < pattern.size(); ++i) {
        curr_pos = pos + i * (pair.second - 1) - ((pair.second - 1) * half_length);
        if (pair.first.at(curr_pos) != pattern.at(i)) {
            std = false;
        }
        if (pair.first.at(curr_pos) != pattern.at(pattern.size() - 1 - i)) {
            rev = false;
        }
        if (!std && !rev) {
            return false;
        }
    }
    return true;
}