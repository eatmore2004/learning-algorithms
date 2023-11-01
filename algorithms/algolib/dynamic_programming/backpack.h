//
// Created by Andrey on 10/29/2023.
//

#ifndef ALGORITHMS_BACKPACK_H
#define ALGORITHMS_BACKPACK_H

#include <vector>

namespace backpack {
    std::vector<int> simple_solve(int n, int w, std::vector<int> weights, std::vector<int> costs);
    std::vector<int> unlimited_solve(int n, int w, std::vector<int> weights, std::vector<int> costs);
}

#endif //ALGORITHMS_BACKPACK_H
