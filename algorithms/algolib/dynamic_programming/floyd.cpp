//
// Created by Andrey on 9/27/2023.
//

#include "floyd.h"

namespace floyd{
    std::vector<std::vector<int>> solve(std::vector<std::vector<int>> matrix){
        std::vector<std::vector<int>> result = matrix;
        for (int k = 0; k < matrix.size(); ++k) {
            for (int i = 0; i < matrix.size(); ++i) {
                for (int j = 0; j < matrix.size(); ++j) {
                    result[i][j] = std::min(result[i][j], result[i][k] + result[k][j]);
                }
            }
        }
        return result;
    }
}