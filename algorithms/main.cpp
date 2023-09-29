#include <vector>
#include <iostream>
#include "shortest_paths.h"
#include "rod_cutting.h"
#include "path_count.h"
#include "reliable_shortest_paths.h"
#include "warshall.h"
#include "floyd.h"
#include "expr_solver.h"

int main() {
    std::cout << expr_solver::solve(std::vector<int>{10,20,30,50,0}) << std::endl;
    return 0;
}