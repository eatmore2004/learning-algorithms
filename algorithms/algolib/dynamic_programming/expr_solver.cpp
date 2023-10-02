//
// Created by Andrey on 9/29/2023.
//


#include "expr_solver.h"

namespace expr_solver {

    int solve(std::vector<int> expr){
        std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(expr.size(),
                std::vector<int>(expr.size(), 0));

        for (int i = 0; i < expr.size(); ++i) {
            dp[i][i] = expr[i];
        }

        for (int i = 0; i < expr.size() - 1; ++i) {
            for (int j = i + 1; j < expr.size(); ++j) {
                for (int k = i; k < j; ++k) {
                    dp[i][j] = std::max(dp[i][j],
                                       std::max(dp[i][k] + dp[k + 1][j],
                                                dp[i][k] * dp[k + 1][j]));
                }
            }
        }
        
        return dp[0][expr.size() - 1];
    }

}
