#ifndef DAY10_H_
#define DAY10_H_

namespace Day10 {
    constexpr unsigned short MAX_HEIGHT = 9;

    int calc_trailhead_score(unsigned short *p_matrix, int rows, int columns, int pos);
    int calc_sum_trailheads_score(unsigned short *p_matrix, int rows, int columns);
}

#endif