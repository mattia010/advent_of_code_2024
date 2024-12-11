#ifndef DAY10_H_
#define DAY10_H_

#include <string>
#include <fstream>
#include <sstream>

namespace Day10 {
    constexpr unsigned short MAX_HEIGHT = 9;

    struct matrix {
        int *p_matrix;
        int rows;
        int columns;

        matrix(int *p_matrix_in, int rows_in, int columns_in) : p_matrix{p_matrix_in}, rows{rows_in}, columns{columns_in} {} 
    };
    matrix* parseInput(std::string filepath);
    int calc_trailhead_score(matrix *m, int pos);
    int calc_sum_trailheads_score(matrix *m);
}

#endif