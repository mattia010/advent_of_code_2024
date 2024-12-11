#include "day10.hpp"

Day10::matrix* Day10::parseInput(std::string filepath) {
    std::ifstream in(filepath, std::ios_base::in);
    std::string line;
    if (!std::getline(in, line)) {
        return nullptr;
    }
    int columns = line.length();
    int rows = 1;
    while (std::getline(in, line)) {
        if (line.length() != columns) {
            return nullptr;
        }
        ++rows;
    }
    int *p_matrix = new int[rows * columns];
    matrix *m = new matrix(p_matrix, rows, columns);
    
    in.clear();
    in.seekg(0, std::ios::beg);
    int index = 0;
    while (std::getline(in, line)) {
        for (int i = 0; i < m->columns; ++i) {
            m->p_matrix[index] = line.at(i);
            ++index;
        }
    }
    return m;
}

int Day10::calc_trailhead_score(matrix *m, int pos) {
    if (m->p_matrix[pos] == MAX_HEIGHT) {
        return 1;
    }
    int scoreUp;
    // PARALLELIZZABILI
    if (pos >= m->columns && m->p_matrix[pos - m->columns] == m->p_matrix[pos] + 1) {
        scoreUp = calc_trailhead_score(m, pos - m->columns);
    }
    int scoreDown;
    if (pos <= m->rows * m->columns - 1 - m->columns && m->p_matrix[pos + m->columns] == m->p_matrix[pos] + 1) {
        scoreDown = calc_trailhead_score(m, pos + m->columns);
    }
    int scoreLeft;
    if (pos % m->columns > 0 && m->p_matrix[pos - 1] == m->p_matrix[pos] + 1) {
        scoreLeft = calc_trailhead_score(m, pos - 1);
    }
    int scoreRight;
    if (pos % m->columns < m->columns - 1 && m->p_matrix[pos + 1] == m->p_matrix[pos] + 1) {
        scoreRight = calc_trailhead_score(m, pos + 1);
    }
    return scoreUp + scoreDown + scoreLeft + scoreRight;
}

int Day10::calc_sum_trailheads_score(matrix *m) {
    int res = 0;
    for (unsigned short i = 0; i < m->rows * m->columns; ++i) {
        if (m->p_matrix[i] == 0) {
            res += calc_trailhead_score(m, i);
        }
    }
    return res;
}