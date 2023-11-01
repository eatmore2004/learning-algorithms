//
// Created by Andrey on 10/9/2023.
//

#include <climits>
#include "optimal_bst.h"

namespace optimal_bst {
    int solve(std::vector<double> p, std::vector<double> q, int n) {
        std::vector<std::vector<double>> e(n + 2, std::vector<double>(n + 1, 0));
        std::vector<std::vector<double>> w(n + 2, std::vector<double>(n + 1, 0));
        std::vector<std::vector<int>> root(n + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= n + 1; ++i) {
            e[i][i - 1] = q[i - 1];
            w[i][i - 1] = q[i - 1];
        }

        for (int l = 1; l <= n; ++l) {
            for (int i = 1; i <= n - l + 1; ++i) {
                int j = i + l - 1;
                e[i][j] = INT_MAX;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                for (int r = i; r <= j; ++r) {
                    double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                    if (t < e[i][j]) {
                        e[i][j] = t;
                        root[i][j] = r;
                    }
                }
            }
        }

        return e[1][n];
    }
}
