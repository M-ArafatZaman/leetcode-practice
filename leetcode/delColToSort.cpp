#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

/**
 * This is a template file for all leetcode problems
 * Author: @ Mohammad Arafat Zaman
*/

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl 

template <class T> void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}" << endl; }

template <class T, class S> void print_map(map<T, S>& _m) { cout << "{ "; for (auto & n : _m) { cout << n.first << " = " << n.second << ", "; } cout << "\b }" << endl; }

#define PI = 3.141592653589793


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int r = strs.size();
        if (r == 1) {
            return 0;
        };

        int c = strs[0].size();
        int toDel = 0;
        for (int _c = 0; _c < c; ++_c) {
            // Iterate through each col
            int last = -1;
            for (int _r = 0; _r < r; ++_r) {
                // Iterate through each row
                if ((int)strs[_r][_c] >= last) {
                    last = (int)strs[_r][_c];
                } else {
                    toDel += 1;
                    break;
                }
            }
        };

        return toDel;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;


    
    return 0;
}

