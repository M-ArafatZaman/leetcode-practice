#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>

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
    int distinctAverages(vector<int>& nums) {

        if (nums.size() == 2) return 1;

        sort(nums.begin(), nums.end());
        unordered_map<float, int> avg;

        while (nums.size() > 0) {
            int _min = nums[0];
            int _max = nums[nums.size()-1];

            float _avg = (_min + _max)/2.0;
            ++avg[_avg];

            nums.erase(nums.begin());
            nums.erase(nums.end()-1);

        };

        // Get the last map element
        int count = 0;
        for (const auto& i : avg) {
            ++count;
        }

        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;
    vector<int> a = {9,5,7,8,7,9,8,2,0,7};

    cout << solver.distinctAverages(a);
/* 
    print_v(a);
    a.erase(a.begin());
    print_v(a); */

    
    return 0;
}

