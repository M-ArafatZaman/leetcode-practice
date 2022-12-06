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

template <class T, class S>
void print_map(map<T, S>& _m) {
    cout << "{ ";
    for (auto & n : _m) {
        cout << n.first << " = " << n.second << ", ";
    }
    cout << "\b }" << endl;
}

#define PI = 3.141592653589793

class Solution {
    public: 
        int subarrayLCM(vector<int>& nums, int k) {
            int count = 0;
            int n = nums.size();
            vector<int> a(n, 0);
            vector<int> gcf(n, 0);

            for (int i = 0; i < n; ++i) {
                if (isDivisible(k, nums[i])) {
                    // Go greedy
                    if (i == 0) {
                        a[i] = 1;
                        continue;
                    }

                    a[i] = a[i-1]+1;

                    if (nums[i] == k) ++count;
    
                } else {
                    if (a[i-1] > 1) {
                        count += a[i-1];
                    }
                }
            };

            int _last = n-1;
            count += a[_last] > 1 ? a[_last] : 0;

            return count;
        }

        bool isDivisible(int a, int b) {
            return a % b == 0;
        }

        bool isGCF(int gcf , int a, int b) {
            return a % gcf == 0 && b % gcf == 0;
        }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;

    vector<int> a = {3,6,2,7,1};
    int k = 6;

    cout << solver.subarrayLCM(a, k);

    
    return 0;
}

