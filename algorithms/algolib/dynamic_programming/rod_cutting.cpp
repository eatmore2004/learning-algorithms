//
// Created by Andrey on 9/25/2023.
//

#include "rod_cutting.h"

namespace rod_cutting{
    std::vector<int> *p;
    std::vector<int> r(11, -1);
    std::vector<int> s(11, -1);

    int cut(int n) {
        r[0] = 0;
        for (int j = 1; j <= n; ++j) {
            int result = -1;
            for (int i = 1; i <= j; ++i) {
                int candidate = p->at(i-1) + r[j - i];
                if (candidate > result) {
                    result = candidate;
                    s[j] = i;
                }
            }
            r[j] = result;
        }
        return r[n];
    }

    int cut_rod(int length, std::vector<int> prices) {
        p = &prices;
        return cut(length);
    }
}