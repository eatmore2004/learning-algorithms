//
// Created by Andrey on 9/27/2023.
//

#ifndef ALGORITHMS_RELIABLE_SHORTEST_PATHS_H
#define ALGORITHMS_RELIABLE_SHORTEST_PATHS_H

#include <vector>
#define INF 100000

namespace reliable_shortest_paths{
    struct edge {
        int dest, weight;
    };
    std::vector<int> solve(int vertex_start, int vertex_end, int max_steps, std::vector<std::vector<reliable_shortest_paths::edge>> graph);
}

#endif //ALGORITHMS_RELIABLE_SHORTEST_PATHS_H
