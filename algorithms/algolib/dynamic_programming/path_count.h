//
// Created by Andrey on 9/25/2023.
//

#ifndef ALGORITHMS_PATH_COUNT_H
#define ALGORITHMS_PATH_COUNT_H

#include <vector>

namespace path_count {
    struct edge {
        int dest, weight;
    };
    int count_paths(int vertex_start, int vertex_end, std::vector<std::vector<int>> graph);
}

#endif //ALGORITHMS_PATH_COUNT_H
