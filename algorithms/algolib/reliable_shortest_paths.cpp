//
// Created by Andrey on 9/27/2023.
//

#include <climits>
#include "reliable_shortest_paths.h"

namespace reliable_shortest_paths{

    std::vector<int> solve(int start, int end, int steps, std::vector<std::vector<reliable_shortest_paths::edge>> graph){
        std::vector<std::vector<int>> distance(graph.size(), std::vector<int>(steps + 1, INF));

        distance[start][0] = 0;

        for(int i = 0; i < steps; i++){
            for(int j = 0; j < graph.size(); j++){
                for(auto &edge : graph[j]){
                    if(distance[j][i] != INF){
                        distance[edge.dest][i + 1] = std::min(distance[edge.dest][i + 1], distance[j][i] + edge.weight);
                    }
                }
            }
        }

        return distance[end];
    }
}
