#include <vector>
#include <iostream>
#include "algolib/dynamic_programming/find_lcs.h"


int main() {
    std::cout << find_lcs::solve("ABCBDAB", "BDCABA") << std::endl;
    return 0;
}