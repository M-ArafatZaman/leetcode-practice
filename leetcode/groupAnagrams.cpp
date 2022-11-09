#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <utility>

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
    map<string, map<char, int>> dp;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> ans;

        for (auto i : strs) {
            string t = i;
            sort(t.begin(), t.end());

            ans[t].push_back(i);
            
        }

        vector<vector<string>> _ans;

        for (auto k : ans) {
            _ans.push_back(k.second);
        }

        return _ans;
    };
    
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;

    vector<string> b = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = solver.groupAnagrams(b);

    for (auto & i : ans) {
        print_v(i);
    }


    map<char, int> a = {{'e', 2}, {'a', 3}, {'t', 6}};
    map<char, int> c = {{'e', 2}, {'a', 3}, {'t', 6}};
    
    //cout << solver.areMapsEqual(a, c) ;

    return 0;
}

