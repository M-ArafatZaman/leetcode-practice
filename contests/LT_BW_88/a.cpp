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

struct rData {
    int max;
    int min;
    int maxes;
    int mines;
    int mids;
    rData(int m, int n, int _m, int _n, int l): max(m), min(n), maxes(_m), mines(_n), mids(l) {};
};

class Solution {
    public: 
        bool equalFrequency(string word) {
            vector<int> alphabet(26, 0);

            for (auto s : word) {
                alphabet[s-'a'] += 1;
            }

            rData m = findMaxMin(alphabet);
            
            if (m.mids > 0) {return false;}
            if ((m.max - m.min == 1) && m.maxes == 1) {
                return true;
            } else if (m.max == 1 && m.min == 1) {
                return true;
            } else if (m.min == 1 && m.mines == 1) {
                return true;
            }

            
            return false;
        }

        // Max, min
        rData findMaxMin(vector<int>& a) {

            int HIGHEST = -1000;
            int LOWEST = 1000;
            int HIGHEST_C = 0;
            int LOWEST_C = 0;
            int MIDS = 0;
            int b;

            for (auto s: a) {
                if (s == 0) continue;
                if (s < LOWEST) { 
                    b = LOWEST;
                    LOWEST = s; 
                    if (b > LOWEST && b < HIGHEST) ++MIDS;
                    LOWEST_C = 0;
                }
                if (s == LOWEST) {
                    ++LOWEST_C;
                }
                if (s > HIGHEST) {
                    b = HIGHEST;
                    HIGHEST = s;
                    if (b > LOWEST && b < HIGHEST) ++MIDS;
                    HIGHEST_C = 0; 
                }
                if (s == HIGHEST) {
                    ++HIGHEST_C;
                }
                if (s > LOWEST && s < HIGHEST) {
                    ++MIDS;
                }
            }            

            rData p(HIGHEST, LOWEST, HIGHEST_C, LOWEST_C, MIDS);

            return p;
        }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;
    string a;
    cin >> a;

    cout << solver.equalFrequency(a);

    
    return 0;
}

