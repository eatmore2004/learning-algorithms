#include "benchmark/benchmark.h"
#include "shortest_paths.h"
#include "rod_cutting.h"
#include "path_count.h"
#include "warshall.h"
#include "floyd.h"

static void BM_Shortest_path(benchmark::State& state) {

    std::vector<std::vector<shortest_paths::edge>> graph = {
            {{4, 2}},
            {{0, 1}, {2, 1}, {5, 3}, {4,4}},
            {{5, 1}},
            {},
            {{3, 3}, {7,1}},
            {{3, 5}, {6, 2}},
            {{3, 2}},
            {{3, 1}}
    };

    for (auto _ : state) {
        for (int i = 0; i < 7; ++i) {
            shortest_paths::find_shortest_path(1, i, graph);
        }
    }
}

static void BM_Rod_cutting(benchmark::State& state) {
    std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    for (auto _ : state) {
        for (int i = 0; i < prices.size(); ++i) {
            rod_cutting::cut_rod(i, prices);
        }
    }
}

static void BM_Path_count(benchmark::State& state) {
    std::vector<std::vector<int>> reversed_edges_graph = {
            {},
            {0},
            {1},
            {1},
            {1,3},
            {3,4},
            {2,3},
            {5,6}
    };
    for (auto _ : state) {
        for (int i = 0; i < reversed_edges_graph.size(); ++i)
            path_count::count_paths(i, reversed_edges_graph.size(), reversed_edges_graph);

    }
}

static void BM_Warshall(benchmark::State& state) {
    std::vector<std::vector<int>> matrix = {
            {0,1,0,0},
            {0,0,0,1},
            {0,0,0,0},
            {1,0,1,0}
    };
    for (auto _ : state) {
        warshall::solve(matrix);
    }
}

static void BM_Floyd(benchmark::State& state) {
    const int max = 10000;
    std::vector<std::vector<int>> matrix = {
            {0,max,3,max},
            {2,0,max,max},
            {max,7,0,1},
            {6,max,max,0}
    };
    for (auto _ : state) {
        floyd::solve(matrix);
    }
}


BENCHMARK(BM_Rod_cutting);
BENCHMARK(BM_Shortest_path);
BENCHMARK(BM_Path_count);
BENCHMARK(BM_Warshall);
BENCHMARK(BM_Floyd);

BENCHMARK_MAIN();