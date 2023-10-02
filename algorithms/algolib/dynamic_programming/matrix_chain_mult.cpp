//
// Created by Andrey on 10/2/2023.
//

#include "matrix_chain_mult.h"


namespace matrix_chain_mult{

    std::vector<std::vector<int>> matrix_chain_order(std::vector<int> sizes){
        int count = sizes.size() - 1;
        std::vector<std::vector<int>> dp(count, std::vector<int>(count, 0));
        std::vector<std::vector<int>> recovery(count, std::vector<int>(count, 0));

        for(int length = 2; length < count + 1; length++){
            for(int i = 0; i < count - length + 1; i++){
                int j = i + length - 1;
                dp[i][j] = INT_MAX;

                for(int k = i; k < j; k++){
                    int q = dp[i][k] + dp[k + 1][j] + sizes[i] * sizes[k + 1] * sizes[j + 1];
                    if(q < dp[i][j]){
                        dp[i][j] = q;
                        recovery[i][j] = k;
                    }
                }
            }
        }

        return recovery;
    }


    void print_rec(std::vector<std::vector<int>> rec, int i, int j, std::string *result) {
        if (i == j) {
            *result += " A" + std::to_string(i + 1) + " ";
        } else {
            *result += "(";
            print_rec(rec, i, rec[i][j], result);
            print_rec(rec, rec[i][j] + 1, j, result);
            *result += ")";
        }
    }

    std::string get_mult_order(std::vector<int> sizes){
        std::vector<std::vector<int>> recovery = matrix_chain_order(sizes);
        std::string *result = new std::string();
        print_rec(recovery, 0, sizes.size() - 2, result);
        return result->c_str();
    }


}