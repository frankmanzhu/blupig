/*
 * renju-parallel
 * Copyright (C) 2016 Yunzhu Li
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INCLUDE_AI_NEGAMAX_H_
#define INCLUDE_AI_NEGAMAX_H_

#include <vector>

class RenjuAINegamax {
 public:
    RenjuAINegamax();
    ~RenjuAINegamax();

    static int negamax(char *gs, int player, int depth,
                       int *move_r, int *move_c);

    static int heuristicNegamax(char *gs, int player, int depth,
                                int *move_r, int *move_c);

 private:
    // A move (candidate)
    struct Move {
        int heuristic_val;
        int r;
        int c;

        // Overloads < for sorting
        bool operator<(Move other) const {
            return heuristic_val > other.heuristic_val;
        }
    };

    // Search possible moves based on a given state, sorted by heuristic values.
    static std::vector<Move> *searchMovesOrdered(char *gs, int player);
};

#endif  // INCLUDE_AI_NEGAMAX_H_