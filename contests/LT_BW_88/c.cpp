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


class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> nums3(n1*n2, 0);
        int ans = nums1[0] ^ nums2[0];

        if (n1 < n2) {
            for (int o = 0; o < n1; ++o) {
                for (int t =0; t < n2; ++t) {
                    if (o ==0 && t == 0) continue;
                    ans = ans ^ (nums1[o] ^ nums2[t]);
                }
            }
        } else  {
            for (int o = 0; o < n2; ++o) {
                for (int t =0; t < n1; ++t) {
                    if (o ==0 && t == 0) continue;
                    ans = ans ^ (nums2[o] ^ nums1[t]);
                }
            }
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

    
    return 0;
}

