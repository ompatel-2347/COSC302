// Challenge 02: Closest Numbers
// Name:  Om Patel opatel11

// Brief description: This program takes n integers in any order and finds
// two elements that have the smallest absolute distance between them

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {

    int inputSize;
    vector <int> vec;

    while (cin >> inputSize) {

        for (int i = 0; i < inputSize; i++) {
            int input;
            cin >> input;
            vec.push_back(input);
        }

        sort(vec.begin(), vec.end());
        int smallestDiff = vec[1] - vec[0];
        vector <int> indexVec;

        for (int i = 0; i < inputSize-1; i++) {
            int diff = abs(vec[i+1] - vec[i]);

            if (diff < smallestDiff) {
                smallestDiff = diff;
                indexVec.clear();
                indexVec.push_back(i);
                indexVec.push_back(i+1);
            } else if (diff == smallestDiff) {
                indexVec.push_back(i);
                indexVec.push_back(i+1);
            }

        }

        for (size_t i = 0; i < indexVec.size(); i+=2) {
            cout << vec[indexVec[i]] << " " << vec[indexVec[i+1]];
            if (i != indexVec.size()-2) {
                cout << " ";
            }
        }
        cout << endl;
        vec.clear();
    }

    return EXIT_SUCCESS;
}
