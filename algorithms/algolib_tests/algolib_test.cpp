#include "gtest/gtest.h"
#include "shortest_paths.h"
#include "rod_cutting.h"
#include "path_count.h"
#include "warshall.h"
#include "floyd.h"
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


