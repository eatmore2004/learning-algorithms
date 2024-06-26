#include "gtest/gtest.h"
#include "dynamic_programming/shortest_paths.h"
#include "dynamic_programming/rod_cutting.h"
#include "dynamic_programming/path_count.h"
#include "dynamic_programming/warshall.h"
#include "dynamic_programming/floyd.h"
#include "dynamic_programming/reliable_shortest_paths.h"
#include "dynamic_programming/expr_solver.h"
#include "dynamic_programming/matrix_chain_mult.h"
#include "dynamic_programming/find_lcs.h"
#include "dynamic_programming/optimal_bst.h"
#include "dynamic_programming/backpack.h"
#include <vector>

TEST(rod_cutting, cut_rod) {
    std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    EXPECT_EQ(rod_cutting::cut_rod(8, prices), 22);
    EXPECT_EQ(rod_cutting::cut_rod(7, prices), 18);
    EXPECT_EQ(rod_cutting::cut_rod(6, prices), 17);
    EXPECT_EQ(rod_cutting::cut_rod(5, prices), 13);
    EXPECT_EQ(rod_cutting::cut_rod(4, prices), 10);
    EXPECT_EQ(rod_cutting::cut_rod(3, prices), 8);
    EXPECT_EQ(rod_cutting::cut_rod(2, prices), 5);
}

TEST(shortest_paths, find_shortest_path) {

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

    EXPECT_EQ(shortest_paths::find_shortest_path(1, 3, graph), 5);
    EXPECT_EQ(shortest_paths::find_shortest_path(1, 4, graph), 3);
    EXPECT_EQ(shortest_paths::find_shortest_path(1, 7, graph), 4);
}

TEST(path_count, count_paths) {

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

    EXPECT_EQ(path_count::count_paths(0, 7, reversed_edges_graph), 5);
    EXPECT_EQ(path_count::count_paths(1, 7, reversed_edges_graph), 5);
    EXPECT_EQ(path_count::count_paths(2, 7, reversed_edges_graph), 1);
    EXPECT_EQ(path_count::count_paths(0, 1, reversed_edges_graph), 1);
    EXPECT_EQ(path_count::count_paths(0, 5, reversed_edges_graph), 3);
    EXPECT_EQ(path_count::count_paths(1, 4, reversed_edges_graph), 2);
}

TEST(warshall, solve){
    std::vector<std::vector<int>> matrix = {
            {0,1,0,0},
            {0,0,0,1},
            {0,0,0,0},
            {1,0,1,0}
    };
    std::vector<std::vector<int>> result_matrix = {
            {1,1,1,1},
            {1,1,1,1},
            {0,0,0,0},
            {1,1,1,1}
    };

    EXPECT_EQ(warshall::solve(matrix), result_matrix);
}

TEST(floyd,solve){
    const int max = 10000;
    std::vector<std::vector<int>> matrix = {
            {0,max,3,max},
            {2,0,max,max},
            {max,7,0,1},
            {6,max,max,0}
    };
    std::vector<std::vector<int>> result_matrix = {
            {0,10,3,4},
            {2,0,5,6},
            {7,7,0,1},
            {6,16,9,0}
    };
    EXPECT_EQ(floyd::solve(matrix), result_matrix);
}

TEST(reliable_shortest_paths,solve){
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

    std::vector<int> result = reliable_shortest_paths::solve(1, 3, 4, graph);
    std::vector<int> expected = {INF, 15, 7, 6, 5};

    EXPECT_EQ(result, expected);
}

TEST(expr_solver,solve){
    EXPECT_EQ(expr_solver::solve(std::vector<int>{2,1,1,0,3}), 12);
    EXPECT_EQ(expr_solver::solve(std::vector<int>{2,10,1,0,3}), 63);
    EXPECT_EQ(expr_solver::solve(std::vector<int>{10,20,30,50,0}), 300000);
    EXPECT_EQ(expr_solver::solve(std::vector<int>{0,0,0,0,0}), 0);
    EXPECT_EQ(expr_solver::solve(std::vector<int>{0,1,0,0,1,0}), 2);
}

TEST(matrix_chain_mult, solve){
    std::vector<int> sizes = {30, 35, 15, 5, 10, 20, 25};
    EXPECT_EQ(matrix_chain_mult::get_mult_order(sizes), "(( A1 ( A2  A3 ))(( A4  A5 ) A6 ))");
}

TEST(lcs_length, solve){
    EXPECT_EQ(find_lcs::solve("ABCBDAB", "BDCABA"), "BCBA");
    EXPECT_EQ(find_lcs::solve("ACGGAGTGCGCGGAAGCCGGCCGAA", "GTTCGGAATGCCGTTGCTCTGTAA"), "GTCGGAAGCCGGCCGAA");
}

TEST(optimal_bst, solve){
    std::vector<double> p = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
    std::vector<double> q = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
    EXPECT_EQ(optimal_bst::solve(p, q, 4), 1);
}

TEST(backpack_simple, solve){
    std::vector<int> weights = {3, 4, 5, 8, 9};
    std::vector<int> prices = {1, 6, 4, 7, 6};
    EXPECT_EQ(backpack::simple_solve(5, 13, weights, prices), (std::vector<int>{4,2}));
}

TEST(backpack_unlimited, solve){
    std::vector<int> weights = {1, 2, 3, 4, 6};
    std::vector<int> prices = {1, 3, 4, 5, 100};
    EXPECT_EQ(backpack::unlimited_solve(5, 13, weights, prices), (std::vector<int>{5,5,1}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}