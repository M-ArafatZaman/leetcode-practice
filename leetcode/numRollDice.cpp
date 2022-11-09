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

//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
class Solution {
public:
    const long int MODU = 1e9+7;

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> dp(n+1);
        
        for (int i = n-1; i >= 0; --i) {
            if (i == n-1) {
                dp[i] = cost[i];
            
            } else if (i == n-2) {
                //dp[i] = cost[i] < cost[i+1] ? cost[i] : cost[i+1];
                dp[i] = cost[i];
            } else if (dp[i+2] < dp[i+1]) {
                dp[i] = dp[i+2] + cost[i];

            } else if (i > 0 && cost[i-1] < cost[i]) {
                
                dp[i] = dp[i+1] + cost[i-1];

            } else {
                dp[i] = dp[i+1] + cost[i];

            }
            
        }
        print_v(dp);
        return min(dp[0], dp[1]);
    }


    int numRollsToTarget(int n, int k, int target) {
        if (n*k < target) return 0;

        int ways = 0;

        ways += numRollsToTarget(n-1, k, target-1);

        return ways;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;

    int n, k, target;

    vector<int> a = {10,15,20};
    //vector<int> a = {1,100,1,1,1,100,1,1,100,1};
    //vector<int> a = {0,1,1,0};
    //vector<int> a = {0,1,2,0};
    print_v(a);
    int ans = solver.minCostClimbingStairs(a);

    cout << ans;
    
    return 0;
}

