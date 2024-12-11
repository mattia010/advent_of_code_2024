#ifndef DAY10_H_
#define DAY10_H_

#include <string>
#include <fstream>
#include <sstream>
#include <iostream> // tmp

namespace Day10 {
    constexpr unsigned short MAX_HEIGHT = 9;

    struct matrix {
        int *p_matrix;
        int rows;
        int columns;

        matrix(int *p_matrix_in, int rows_in, int columns_in) : p_matrix{p_matrix_in}, rows{rows_in}, columns{columns_in} {} 
    };
    matrix* parseInput(std::string filepath);
    bool* calc_trailhead_score_matrix(matrix *m, int trailhead_pos, bool*p_bool_matrix);
    int calc_trailhead_score(matrix *m, int trailhead_pos);
    int calc_sum_trailheads_scores(matrix *m);
    int calc_trailhead_rating(matrix *m, int trailhead_pos);
    int calc_sum_trailheads_ratings(matrix *m);
}

#endif