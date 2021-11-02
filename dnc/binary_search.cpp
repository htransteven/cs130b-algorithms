#include <iostream>
#include <fstream>
#include "string"
#include <vector>
#include "../global_inputs.h"
#include "merge_sort.h"

using namespace std;

int target;
int dataLength = 0;
vector<int> numbers;

int dnc_binary_search(vector<int> data, int target, int low, int high) {
    int mid = (high + low) / 2;
    if(mid >= data.size()) return -1;
    if(verbose) cout << "comparing " << data.at(mid) << " to " << target << endl;
    if(data.at(mid) == target) return mid;
    if(high == low) return -1;
    if(data.at(mid) > target) return dnc_binary_search(data, target, low + 1, mid);
    return dnc_binary_search(data, target, mid + 1, high);
}

int main (int argc, char* argv[]) {
    if(!load_global_inputs(argc, argv, NULL)) return 1;

    if(input_file_name.length() > 0) {
        ifstream inputFile(input_file_name);
        if(!inputFile.is_open()) {
            cerr << "failed to open" << input_file_name << endl;
            return 1;
        }
        string line;
        getline(inputFile, line);
        target = stoi(line);

        while(getline(inputFile, line)) {
            numbers.push_back(stoi(line));
        }

        dataLength = numbers.size();

        inputFile.close();
    } else {
        cout << "Number of integers: ";
        cin >> dataLength;
        int num;
        for(int i = 0; i < dataLength; i++) {
            cout << "Enter integer " << i << ": ";
            cin >> num;
            numbers.push_back(num);
        }

        cout << "Search for integer: " << endl;
        cin >> target;
    }

    vector<int> sorted = dnc_merge_sort(numbers);
    
    cout << "Divide and Conquer: Binary Search" << endl;
    cout << "Parameters:" << endl;
    cout << "\tInput Data: ";
    for(int i: numbers) {
        cout << i << " ";
    }
    cout << endl;
    cout << "\tSorted Data (merge sort): ";
    for(int i: sorted) {
        cout << i << " ";
    }
    cout << endl;
    cout << "\tData size: " << dataLength << " integers" << endl;
    cout << "\tSearching for: " << target << endl;

    int foundIndex = dnc_binary_search(sorted, target, 0, sorted.size());
    if(foundIndex == -1) {
        cout << target << " was not found in data" << endl;
    } else {
        cout << target << " was found in data at index " << foundIndex << endl;
    }

    return 0;
}