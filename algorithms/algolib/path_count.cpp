//
// Created by Andrey on 9/25/2023.
//

#include "path_count.h"

namespace path_count{
    int count_recursive(std::vector<std::vector<int>> graph, std::vector<int> d, int v) {
        if(d[v] != -1) {
            return d[v];
        }

        int result = 0;
        for(const auto& u : graph[v]) {
            result += count_recursive(graph, d, u);
        }

        d[v] = result;
        return result;
    }

    int count_paths(int vertex_start, int vertex_end, std::vector<std::vector<int>> graph_reversed){
        if(vertex_start == vertex_end) {
            return 1;
        }
        std::vector<int> d(graph_reversed.size(), -1);
        d[vertex_start] = 1;
        return count_recursive(graph_reversed, d, vertex_end);
    }
}