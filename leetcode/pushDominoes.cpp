#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl 

template <class T> void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}" << endl; }

template <class T, class S>
void print_map(map<T, S>& _m) {
    cout << "{ ";
    for (auto & n : _m) {
        cout << n.first << " = " << n.second << ", ";
    }
    cout << "\b }" << endl;
}

#define PI = 3.141592653589793

// https://leetcode.com/problems/push-dominoes/

class Solution {
public:
    string pushDominoes(string dominoes) {
        string finalString = dominoes;
        int prevL = -1, prevR = -1;
        char curr;
        int mid;
        for (int i = 0; i < dominoes.size(); ++i) {
            curr = dominoes[i];

            if (curr == '.') {
                continue;

            } else if (curr == 'L') {
            // For every Left
                
                if (i == 0) continue;

                if (prevR != -1) {
                    int dist = (i-prevR) - 1;
                    mid = dist/2;

                    int rDist = prevR + mid;
                    int lDist = i - mid;

                    // Set L's
                    for (int l = i; l >= lDist; --l) {
                        finalString[l] = 'L';
                    }
                    // Set R's
                    for (int r = prevR; r <= rDist; ++r) {
                        finalString[r] = 'R';
                    }

                    // Destroy R
                    prevR = -1;
                
                } else {
                    for (int k = i-1; k >= 0; --k) {
                        if (finalString[k] != '.') break;
                        finalString[k] = 'L';
                    }
                }

            } else if (curr == 'R') {
            // For every right

                if (i == dominoes.size()-1) continue;
    
                // If prevR is still defined, update curr
                if (prevR != -1) {
                    for (; prevR < i; ++prevR) {
                        finalString[prevR] = 'R';
                    }
                } 
                
                // Update right
                prevR = i;

            }

        }

        // If prevR is not destroyed, that means there is still an R left to account for
        for (int j = prevR; j < finalString.size(); ++j) {
            finalString[j] = 'R';
        }

        return finalString;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;

    string str;
    cin >> str;

    cout << solver.pushDominoes(str);

    
    return 0;
}

