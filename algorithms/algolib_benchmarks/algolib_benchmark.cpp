#include "benchmark/benchmark.h"
#include "dynamic_programming/shortest_paths.h"
#include "dynamic_programming/rod_cutting.h"
#include "dynamic_programming/path_count.h"
#include "dynamic_programming/warshall.h"
#include "dynamic_programming/floyd.h"
#include "dynamic_programming/reliable_shortest_paths.h"
#include "dynamic_programming/expr_solver.h"
#include "dynamic_programming/matrix_chain_mult.h"
#include "dynamic_programming/find_lcs.h"
#include "dynamic_programming/backpack.h"
#include "dynamic_programming/optimal_bst.h"

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
        shortest_paths::find_shortest_path(1, 3, graph);
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

static void BM_Reliable_shortest_paths(benchmark::State& state) {
    std::vector<std::vector<reliable_shortest_paths::edge>> graph = {
            {{4, 2}},
            {{0, 1}, {2, 1}, {5, 3}, {4,4}, {3,15}},
            {{5, 1}},
            {},
            {{3, 3}, {7,1}},
            {{3, 5}, {6, 2}},
            {{3, 2}},
            {{3, 1}}
    };
    for (auto _ : state) {
        reliable_shortest_paths::solve(1, 3, 4, graph);
    }
}

static void BM_Expression_solver(benchmark::State& state) {
    for (auto _ : state) {
        expr_solver::solve(std::vector<int>{2,1,1,0,3});
    }
}


static void BM_Matrix_chain(benchmark::State& state) {
    for (auto _ : state) {
        matrix_chain_mult::get_mult_order(std::vector<int>{30,35,15,5,10,20,25});
    }
}

static void BM_LCS(benchmark::State& state) {
    for (auto _ : state) {
        find_lcs::solve("ABCBDAB", "BDCABA");
    }
}

static void BM_OptimalBST(benchmark::State& state){
    std::vector<double> p = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
    std::vector<double> q = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
    for (auto _ : state) {
        optimal_bst::solve(p, q, 4);
    }
}

static void BM_UnlimitedBackpack(benchmark::State& state) {
    std::vector<int> weights = {1, 2, 3, 4, 6};
    std::vector<int> prices = {1, 3, 4, 5, 100};
    for (auto _ : state) {
        backpack::unlimited_solve(5, 13, weights, prices);
    }
}

static void BM_SimpleBackpack(benchmark::State& state) {
    std::vector<int> weights = {3, 4, 5, 8, 9};
    std::vector<int> prices = {1, 6, 4, 7, 6};
    for (auto _ : state) {
        backpack::simple_solve(5, 13, weights, prices);
    }
}



BENCHMARK(BM_Rod_cutting);
BENCHMARK(BM_Shortest_path);
BENCHMARK(BM_Path_count);
BENCHMARK(BM_Warshall);
BENCHMARK(BM_Floyd);
BENCHMARK(BM_Reliable_shortest_paths);
BENCHMARK(BM_Expression_solver);
BENCHMARK(BM_Matrix_chain);
BENCHMARK(BM_LCS);
BENCHMARK(BM_OptimalBST);
BENCHMARK(BM_UnlimitedBackpack);
BENCHMARK(BM_SimpleBackpack);

BENCHMARK_MAIN();