//
// Created by Andrey on 9/19/2023.
//

#ifndef ALGORITHMS_SHORTEST_PATHS_H
#define ALGORITHMS_SHORTEST_PATHS_H

#include <vector>
#include <algorithm>
#include <unordered_set>

namespace shortest_paths {
    struct edge {
        int dest, weight;
    };
    int find_shortest_path(int vertex_start, int vertex_end, std::vector<std::vector<shortest_paths::edge>> graph);
}

#endif //ALGORITHMS_SHORTEST_PATHS_H
