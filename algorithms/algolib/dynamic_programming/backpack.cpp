//
// Created by Andrey on 10/29/2023.
//

#include <iostream>
#include "backpack.h"

namespace backpack{

    std::vector<std::vector<int>> get_answers_matrix(int n, int w, std::vector<int> weights, std::vector<int> costs){
        std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(n + 1,
                                                                         std::vector<int>(w + 1, 0));

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < w + 1; ++j) {
                if(weights[i - 1] <= j){
                    int new_weight = j - weights[i - 1];
                    dp[i][j] = std::max(
                            dp[i - 1][j],
                            dp[i - 1][new_weight] + costs[i - 1]
                    );
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp;
    }

    void simp_rec(int n, int w, std::vector<std::vector<int>> answers, std::vector<int> *weights, std::vector<int> *result){
        if (answers[n][w] == 0) return;
        if (answers[n - 1][w] == answers[n][w]) {
            simp_rec(n - 1, w, answers, weights, result);
        } else {
            result->push_back(n);
            simp_rec(n - 1, w - weights->at(n - 1), answers, weights, result);
        }
    }

    void unlim_rec(int n, int w, std::vector<std::vector<int>> answers, std::vector<int> *weights, std::vector<int> *result){
        if (answers[n][w] == 0) return;
        if (answers[n - 1][w] == answers[n][w]) {
            unlim_rec(n - 1, w, answers, weights, result);
        } else {
            result->push_back(n);
            if(answers[n][w - weights->at(n - 1)] >= weights->at(n - 1))
                unlim_rec(n, w - weights->at(n - 1), answers, weights, result);
            else
                unlim_rec(n - 1, w - weights->at(n - 1), answers, weights, result);
        }
    }

    std::vector<int> simple_solve(int n, int w, std::vector<int> weights, std::vector<int> costs){
        std::vector<std::vector<int>> answers = get_answers_matrix(n, w, weights, costs);
        std::vector<int> result;
        simp_rec(n, w, answers, &weights, &result);
        return result;
    }

    std::vector<int> unlimited_solve(int n, int w, std::vector<int> weights, std::vector<int> costs){
        std::vector<std::vector<int>> answers = get_answers_matrix(n, w, weights, costs);
        std::vector<int> result;
        result.clear();
        unlim_rec(n, w, answers, &weights, &result);
        return result;
    }

}
