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

// https://leetcode.com/problems/house-robber/description/
class Solution {
public:
    int rob(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        if (n == 0) return 0;
        dp[0] = nums[0];
        if (n == 1) return dp[0];
        dp[1] = max(nums[0], nums[1]);
        if (n == 2) return dp[1];

        for (int i = 2; i < n; ++i) {
            dp[i] = max( dp[i-2] + nums[i], dp[i-1] );
        }

        return dp[n-1];
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

