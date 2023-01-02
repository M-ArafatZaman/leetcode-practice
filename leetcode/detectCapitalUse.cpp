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
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;

        // test
        if (!isUpper(word[0])) {           
            for (int i = 1; i < word.size(); ++i) {
                if (isUpper(word[i])) return false;
            }

            return true;

        } else if (isUpper(word[0]) && isUpper(word[1])) {
        // TEST
            for (int i = 1; i < word.size(); ++i) {
                if (!isUpper(word[i])) return false;
            }

            return true;
        } else {
        // Test
            for (int i = 1; i < word.size(); ++i) {
                if (isUpper(word[i])) return false;
            }

            return true;
        }
        
    }

    bool isUpper(char a) {
        int A = (int)'A';
        int Z = (int)'Z';
        int _a = (int)a;

        if (_a >= A and _a <= Z) {
            return true;
        } else {
            return false;
        }
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

