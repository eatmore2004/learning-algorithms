project(algolib)

set(HEADER_FILES shortest_paths.h
        rod_cutting.h)
set(SOURCE_FILES shortest_paths.cpp
        rod_cutting.cpp
        path_count.cpp
        path_count.h
        warshall.cpp
        warshall.h
        floyd.cpp
        floyd.h
        reliable_shortest_paths.cpp
        reliable_shortest_paths.h)

add_library(algolib_lib ${HEADER_FILES} ${SOURCE_FILES})