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


class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> people;
        
        // Init
        for (int i = 0; i < n; i++) {
            people.push_back(i);
        }

        // Create disjoint sets
        for (vector<int> j : dislikes) {
            int p1 = j[0];
            int p2 = j[1];

            int curr_i = p1-1;

            while (curr_i != people[curr_i]) {
                curr_i = people[curr_i];
            }

            people[curr_i] = p2-1;
        }

        // Count disjoint sets
        int sets = countSets(people);
        print_v(people);
        DEBUG(sets);

        return sets >= 2;
    };

    int countSets(vector<int>& a) {
        int n = a.size();

        // Count heads
        int sets; 
        for (int i = 0; i < n; ++i) {
            if (a[i] == i) sets++;
        }

        return sets;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;
    vector<vector<int>> a = {{1,2}, {1,3}, {2,4}};

    cout << solver.possibleBipartition(5, a);


    
    return 0;
}

