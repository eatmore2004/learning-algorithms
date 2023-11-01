project(algolib)

set(HEADER_FILES dynamic_programming/shortest_paths.h
        dynamic_programming/rod_cutting.h)
set(SOURCE_FILES dynamic_programming/shortest_paths.cpp
        dynamic_programming/rod_cutting.cpp
        dynamic_programming/path_count.cpp
        dynamic_programming/path_count.h
        dynamic_programming/warshall.cpp
        dynamic_programming/warshall.h
        dynamic_programming/floyd.cpp
        dynamic_programming/floyd.h
        dynamic_programming/reliable_shortest_paths.cpp
        dynamic_programming/reliable_shortest_paths.h
        dynamic_programming/expr_solver.cpp
        dynamic_programming/expr_solver.h
        dynamic_programming/matrix_chain_mult.cpp
        dynamic_programming/matrix_chain_mult.h
        dynamic_programming/find_lcs.cpp
        dynamic_programming/find_lcs.h
        dynamic_programming/optimal_bst.cpp
        dynamic_programming/optimal_bst.h
        dynamic_programming/optimal_bst.cpp
        dynamic_programming/backpack.cpp
        dynamic_programming/backpack.h
        dynamic_programming/backpack.h
)

add_library(algolib_lib ${HEADER_FILES} ${SOURCE_FILES})