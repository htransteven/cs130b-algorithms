#include <iostream>
#include <vector>
#include <algorithm>
#include "../global_inputs.h"

using namespace std;

vector<int> dnc_merge_sort(vector<int> data) {
    if(data.size() == 1) return vector<int>(data);
    if(data.size() == 2) {
        if(data.front() > data.back()) {
            return vector<int>{data.at(data.size() - 1), data.at(0)};
        }
        return vector<int>(data);
    }
    
    int mid = data.size() / 2;
    vector<int> left(data.begin(), data.begin() + mid);
    vector<int> right(data.begin() + mid, data.end());
    vector<int> left_merged = dnc_merge_sort(left);
    vector<int> right_merged = dnc_merge_sort(right);
    
    vector<int> result;

    int l = 0, r = 0;
    while(l < left_merged.size() && r < right_merged.size()) {
        if(left_merged.at(l) <= right_merged.at(r)) {
            result.push_back(left_merged.at(l));
            l++;
        } else {
            result.push_back(right_merged.at(r));
            r++;
        }
    }

    while(l < left_merged.size()) {
        result.push_back(left_merged.at(l));
        l++;
    }
    while(r < right_merged.size()) {
        result.push_back(right_merged.at(r));
        r++;
    }

    return result;
}