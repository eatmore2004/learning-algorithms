//
// Created by Andrey on 10/2/2023.
//

#include <algorithm>
#include "find_lcs.h"

namespace find_lcs{
    std::vector<std::vector<std::string>> *arrows;
    std::vector<std::vector<int>>  *lengths;
    std::string *result = new std::string();

    void lcs_length(std::string s1, std::string s2){
        arrows = new std::vector<std::vector<std::string>>(
                s1.size() + 1, std::vector<std::string>(s2.size() + 1, "top"));
        lengths = new std::vector<std::vector<int>>(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));

        for(int i = 1; i < s1.size() + 1; i++){
            for(int j = 1; j < s2.size() + 1; j++){
                if(s1[i - 1] == s2[j - 1]){
                    (*lengths)[i][j] = (*lengths)[i - 1][j - 1] + 1;
                    (*arrows)[i][j] = "diagonal";
                } else if((*lengths)[i - 1][j] >= (*lengths)[i][j - 1]){
                    (*lengths)[i][j] = (*lengths)[i - 1][j];
                    (*arrows)[i][j] = "top";
                } else {
                    (*lengths)[i][j] = (*lengths)[i][j - 1];
                    (*arrows)[i][j] = "left";
                }
            }
        }
    }

    void lcs_to_str(std::string s1,std::string s2,int i, int j) {
        if (!i || !j) return;

        if (arrows->at(i).at(j) == "diagonal") {
            lcs_to_str(s1, s2, i - 1, j - 1);
            result->push_back(s1[i-1]);
        } else if (arrows->at(i).at(j) == "top") {
            lcs_to_str(s1, s2, i - 1, j);
        } else {
            lcs_to_str(s1, s2, i, j - 1);
        }
    }

    std::string solve(std::string s1, std::string s2) {
        result->clear();
        lcs_length(s1, s2);
        lcs_to_str(s1,s2,s1.size(),s2.size());
        return result->c_str();
    }
}