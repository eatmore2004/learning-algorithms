//
// Created by Andrey on 9/19/2023.
//

#include "shortest_paths.h"

using namespace std;

namespace shortest_paths{
    void dfs(int i, vector<int> *sorted_vertices, unordered_set<int> *visited, const vector<vector<edge>>& graph) {
        visited->insert(i);
        for (auto &j : graph[i]) {
            if (visited->find(j.dest) == visited -> end()){
                dfs(j.dest, sorted_vertices, visited, graph);
            }
        }
        sorted_vertices->push_back(i);
    }

    vector<int> topological_sort(const vector<vector<edge>>& graph) {
        unordered_set<int> visited;
        vector<int> sorted_vertices;
        for(int i = 0; i < graph.size(); i++) {
            if(visited.find(i) == visited.end()) {
                dfs(i,&sorted_vertices, &visited, graph);
            }
        }
        reverse(sorted_vertices.begin(), sorted_vertices.end());
        return sorted_vertices;
    }

    int min_distance(int vertex_start, int vertex_end, vector<vector<edge>> graph) {

        vector<int> sorted_vertices = topological_sort(graph);
        vector<int> distance(graph.size(), INT_MAX);
        distance[vertex_start] = 0;

        for (int vertex : sorted_vertices) {
            for (auto &edge : graph[vertex]) {
                if (distance[edge.dest] == INT_MAX) {
                    distance[edge.dest] = distance[vertex] + edge.weight;
                }else{
                    distance[edge.dest] = min(distance[edge.dest], distance[vertex] + edge.weight);
                }
            }
        }

        return distance[vertex_end];
    }

    int find_shortest_path(int vertex_start, int vertex_end, vector<vector<edge>> graph) {
        int result = min_distance(vertex_start, vertex_end, graph);
        return result;
    }
}