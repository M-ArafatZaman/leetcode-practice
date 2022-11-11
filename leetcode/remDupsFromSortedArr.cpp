#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <utility>

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

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/
class Solution {
    public: 
        int removeDuplicates(vector<int>& nums) {
            int n = nums.size();

            if (n == 0) return 0;
            
            int count = 0;
            int lastNum = nums[0];
            int i = 1; // Double pointer
            
            while (i < n) {
                if (nums[i] != lastNum) {
                    ++count;
                    lastNum = nums[i];
                    if (count != i) {
                        swap(nums[i], nums[count]);
                    }
                }
                ++i;
            };
            ++count;
            return count;
        }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;

    vector<int> a = {0,0,1,1,1,2,2,3,3,4};

    int k = solver.removeDuplicates(a);
    
    cout << k << endl;
    print_v(a);

    
    return 0;
}

