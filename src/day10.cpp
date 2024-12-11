#include "day10.hpp"

int Day10::calc_trailhead_score(unsigned short *p_matrix, int rows, int columns, int pos) {
    if (p_matrix[pos] == MAX_HEIGHT) {
        return 1;
    }
    int scoreUp;
    // PARALLELIZZABILI
    if (pos >= columns && p_matrix[pos - columns] == p_matrix[pos] + 1) {
        scoreUp = calc_trailhead_score(p_matrix, rows, columns, pos - columns);
    }
    int scoreDown;
    if (pos <= rows * columns - 1 - columns && p_matrix[pos + columns] == p_matrix[pos] + 1) {
        scoreDown = calc_trailhead_score(p_matrix, rows, columns, pos + columns);
    }
    int scoreLeft;
    if (pos % columns > 0 && p_matrix[pos - 1] == p_matrix[pos] + 1) {
        scoreLeft = calc_trailhead_score(p_matrix, rows, columns, pos - 1);
    }
    int scoreRight;
    if (pos % columns < columns - 1 && p_matrix[pos + 1] == p_matrix[pos] + 1) {
        scoreRight = calc_trailhead_score(p_matrix, rows, columns, pos + 1);
    }
    return scoreUp + scoreDown + scoreLeft + scoreRight;
}

int Day10::calc_sum_trailheads_score(unsigned short *p_matrix, int rows, int columns) {
    int res = 0;
    for (unsigned short i = 0; i < rows * columns; ++i) {
        if (p_matrix[i] == 0) {
            res += calc_trailhead_score(p_matrix, rows, columns, i);
        }
    }
    return res;
}