#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

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
        int minStoneSum(vector<int>& piles, int k) {
            priority_queue<int> P(piles.begin(), piles.end());
            
            while ( k > 0) {
                int a = P.top();
                P.pop();
                P.push(a - floor(a/2));
                k--;
            }

            int s = 0;
            while (!P.empty()) {
                s += P.top();
                P.pop();
            }
    
            return s;
        }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;
    vector<int> piles = {5,4,9};
    int k = 2;
    cout << solver.minStoneSum(piles, k) << endl; 


    
    return 0;
}

