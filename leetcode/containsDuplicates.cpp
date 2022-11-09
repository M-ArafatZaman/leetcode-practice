#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>

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


void printMap(unordered_map<int, int>& a) {
    cout << "{ ";
    for (auto& k: a) {
        cout << k.first << " = " << k.second << ",";
    }
    cout << "}" << endl;
}


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> a;
        k++;

        // Generate initial list
        for (int i = 0; i < min(n, k); ++i) {
            a[nums[i]]++;
        }
        for (int j = 0; j < n; ++j) {
            
            if (j-k >= 0) {
                a[nums[j-k]]--;
                a[nums[j]]++;
            }
            
            if (a[nums[j]] > 1) {
                return true;
            }
        }
        
        return false;
        
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;

    vector<int> a = {1,2,3,1};

    int k = 3;
    print_v(a);
    cout << solver.containsNearbyDuplicate(a, k);


    
    return 0;
}

