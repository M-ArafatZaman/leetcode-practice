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

// https://leetcode.com/contest/biweekly-contest-89/
class Solution {
    public: 
        int countTime(string time) {
            int ways = 0;

            // Get first 
            int a = time[0], b = time[1], c = time[3], d = time[4];

            if (a != '?') a -= '0';
            if (b != '?') b -= '0';
            if (c != '?') c -= '0';
            if (d != '?') d -= '0';


            // Hours
            int hours = 1, minutes = 1;

            if (b == '?') {
                if (a == '?') {
                    hours = 24;
                } else if (a < 2) {
                    hours = 10;
                } else {
                    hours = 4;
                }

            } else if (a == '?') {
                hours = 2;
                if (b <= 3) ++hours;
            }

            // Minutes

            if (d == '?' && c == '?') {
                minutes = 60;
            } else if (c == '?') {
                minutes = 6;
            } else if (d == '?') {
                minutes = 10;
            }

            return hours * minutes;
        }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;
    cout << solver.countTime("?3:1?") << endl;
    

    return 0;
}

