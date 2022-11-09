#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

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

    const long long _MOD = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int minPower = sqrt(n);
        int sum = 0, curr;

        for (int i = minPower; i >= 0; --i) {
            curr = (int)pow(2, i);
            if (sum + curr <= n) {
                sum += curr;
                powers.insert(powers.begin(), curr);
            }
        }

        vector<int> prefixArr = prefix(powers);
        vector<int> ans;

        // Queries
        long long int p;
        for (auto& a : queries) {
            int i = a[0], j = a[1];
            
            if (i == j) {
                p = powers[j] % _MOD;
                ans.push_back(powers[j] % _MOD);
            } else if (i == 0) {
                p = prefixArr[j] % _MOD;
                ans.push_back(p);
            } else {
                p = (prefixArr[j]/prefixArr[i-1]) % _MOD;
                ans.push_back(p);
            }
        };

        return ans;
    }

    vector<int> prefix(vector<int>& a) {
        vector<int> ans = {a[0]};
        long long int p;

        for (int i = 1; i < a.size(); ++i) {
            p = ((long long)ans[i-1] * (long long)a[i]) % _MOD;
            ans.push_back(p);
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
    vector<vector<int>> a = {{5,5},{4,4},{0,1},{1,5},{4,6},{6,6},{5,6},{0,3},{5,5},{5,6},{1,2},{3,5},{3,6},{5,5},{4,4},{1,1},{2,4},{4,5},{4,4},{5,6},{0,4},{3,3},{0,4},{0,5},{4,4},{5,5},{4,6},{4,5},{0,4},{6,6},{6,6},{6,6},{2,2},{0,5},{1,4},{0,3},{2,4},{5,5},{6,6},{2,2},{2,3},{5,5},{0,6},{3,3},{6,6},{4,4},{0,0},{0,2},{6,6},{6,6},{3,6},{0,4},{6,6},{2,2},{4,6}};

    vector<int> b =  solver.productQueries(919, a);

    print_v(b);

    
    return 0;
}

