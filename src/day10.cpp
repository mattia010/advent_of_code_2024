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
            m->p_matrix[index] = line.at(i) - '0';
            ++index;
        }
    }
    return m;
}

bool* Day10::calc_trailhead_score_matrix(matrix *m, int trailhead_pos, bool *p_bool_matrix) {
    if (trailhead_pos < 0 || trailhead_pos >= m->rows * m->columns) {
        throw std::invalid_argument("pos out of bounds");
    }
    if (m->p_matrix[trailhead_pos] == MAX_HEIGHT) {
        p_bool_matrix[trailhead_pos] = true;
        return p_bool_matrix;
    }
    if (trailhead_pos >= m->columns && 
            m->p_matrix[trailhead_pos - m->columns] == m->p_matrix[trailhead_pos] + 1) {
        calc_trailhead_score_matrix(m, trailhead_pos - m->columns, p_bool_matrix);
    }
    if (trailhead_pos <= m->rows * m->columns - 1 - m->columns && 
            m->p_matrix[trailhead_pos + m->columns] == m->p_matrix[trailhead_pos] + 1) {
        calc_trailhead_score_matrix(m, trailhead_pos + m->columns, p_bool_matrix);
    }
    if (trailhead_pos % m->columns > 0 && 
            m->p_matrix[trailhead_pos - 1] == m->p_matrix[trailhead_pos] + 1) {
        calc_trailhead_score_matrix(m, trailhead_pos - 1, p_bool_matrix);
    }
    if (trailhead_pos % m->columns < m->columns - 1 && 
            m->p_matrix[trailhead_pos + 1] == m->p_matrix[trailhead_pos] + 1) {
        calc_trailhead_score_matrix(m, trailhead_pos + 1, p_bool_matrix);
    }
    return p_bool_matrix;
}

int Day10::calc_trailhead_score(matrix *m, int trailhead_pos) {
    if (trailhead_pos < 0 || trailhead_pos >= m->rows * m->columns) {
        throw std::invalid_argument("pos out of bounds");
    }

    bool *p_bool_matrix = new bool[m->rows * m->columns];
    for (int i = 0; i < m->rows * m->columns; ++i) {
        p_bool_matrix[i] = false;
    }
    calc_trailhead_score_matrix(m, trailhead_pos, p_bool_matrix);
    int score = 0;
    for (int i = 0; i < m->rows * m->columns; ++i) {
        if (p_bool_matrix[i]) {
            ++score;
        }
    }
    return score;
}

int Day10::calc_sum_trailheads_scores(matrix *m) {
    int res = 0;
    for (int i = 0; i < m->rows * m->columns; ++i) {
        if (m->p_matrix[i] == 0) {
            res += calc_trailhead_score(m, i);
        }
    }
    return res;
}

int Day10::calc_trailhead_rating(matrix *m, int trailhead_pos) {
    if (trailhead_pos < 0 || trailhead_pos >= m->rows * m->columns) {
        throw std::invalid_argument("pos out of bounds");
    }
    if (m->p_matrix[trailhead_pos] == MAX_HEIGHT) {
        return 1;
    }
    int scoreUp = 0;
    if (trailhead_pos >= m->columns && 
            m->p_matrix[trailhead_pos - m->columns] == m->p_matrix[trailhead_pos] + 1) {
        scoreUp = calc_trailhead_rating(m, trailhead_pos - m->columns);
    }
    int scoreDown = 0;
    if (trailhead_pos <= m->rows * m->columns - 1 - m->columns && 
            m->p_matrix[trailhead_pos + m->columns] == m->p_matrix[trailhead_pos] + 1) {
        scoreDown = calc_trailhead_rating(m, trailhead_pos + m->columns);
    }
    int scoreLeft = 0;
    if (trailhead_pos % m->columns > 0 && 
            m->p_matrix[trailhead_pos - 1] == m->p_matrix[trailhead_pos] + 1) {
        scoreLeft = calc_trailhead_rating(m, trailhead_pos - 1);
    }
    int scoreRight = 0;
    if (trailhead_pos % m->columns < m->columns - 1 && 
            m->p_matrix[trailhead_pos + 1] == m->p_matrix[trailhead_pos] + 1) {
        scoreRight = calc_trailhead_rating(m, trailhead_pos + 1);
    }
    return scoreUp + scoreDown + scoreLeft + scoreRight;
}

int Day10::calc_sum_trailheads_ratings(matrix *m) {
    int res = 0;
    for (int i = 0; i < m->rows * m->columns; ++i) {
        if (m->p_matrix[i] == 0) {
            res += calc_trailhead_rating(m, i);
        }
    }
    return res;
}