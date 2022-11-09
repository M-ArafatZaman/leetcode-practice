#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl 

template <class T> void print_v(vector<T> &v) { cout << "{ "; for (auto x : v) cout << x << ","; cout << "\b }" << endl; }

template <typename T>
T maxVec(vector<T>& nums) {
    T highest = nums[0];

    for (vector<int>::iterator it = nums.begin()+1; it < nums.end(); ++it) {
        if (*it > highest) highest = *it;
    }

    return highest;
}

template <typename T>
T minVec(vector<T>& nums) {
    T lowest = nums[0];

    for (vector<int>::iterator it = nums.begin()+1; it < nums.end(); ++it) {
        if (*it < lowest) lowest = *it;
    }

    return lowest;
}

#define PI = 3.141592653589793


class Solution {
    public: 
        vector<int> goodIndices(vector<int>& nums, int k) {
            vector<int> ans;
            vector<int> nonIncreasing = normalizeNonIncreasing(nums);
            vector<int> nonDecreasing = normalizeNonDecreasing(nums);
            int n = nums.size();
            if (2*k >= n) return ans;

            for (int i = k; i < n-k; ++i) {
                if (k <= nonIncreasing[i-1] && k <= nonDecreasing[i+k]) {
                    ans.push_back(i);
                }

            }

            return ans;
        }

        // Prefix algorithm
        vector<int> normalizeNonIncreasing(vector<int>& nums) {
            vector<int> ans = {1};
            int n = nums.size();
            int count = 1;

            for (int i = 1; i < n; ++i) {
                if (nums[i] <= nums[i-1]) {
                    ++count;
                } else {
                    count = 1;
                }
                ans.push_back(count);
            }

            return ans;
        }

        vector<int> normalizeNonDecreasing(vector<int>& nums) {
            vector<int> ans = {1};
            int n = nums.size();
            int count = 1;

            for (int i = 1; i < n; ++i) {
                if (nums[i] >= nums[i-1]) {
                    ++count;
                } else {
                    count = 1;
                }
                ans.push_back(count);
            }

            return ans;
        }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    // Run tests
    Solution solver;

    vector<int> a = {2,1,1,1,3,4,1};

    vector<int> ans = solver.goodIndices(a, 2);
    print_v(ans);

    
    return 0;
}

