#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <utility>
#include <queue>

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


#define PSI pair<string, int>

struct Comparer {
    bool operator()(PSI a, PSI b) {
        if (a.second == b.second) {
            // Sort lexicographically
            return a.first > b.first;
        } else {
            return a.second < b.second;
        }
    }
};

// https://leetcode.com/problems/top-k-frequent-words/
class Solution {
    public: 
        vector<string> topKFrequent(vector<string>& words, int k) {
            unordered_map<string, int> a;

            for (const auto & i : words) {
                
                ++a[i];
            }
            
            priority_queue<PSI, vector<PSI>, Comparer> PQ;

            for (const auto & j : a) {
                PQ.push(j);
            }

            vector<string> ans;

            for (int i = 0; i < k; ++i) {
                ans.push_back(PQ.top().first);
                PQ.pop();
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

    vector<string> a = {"the","day","is","sunny","the","the","the","sunny","is","is"};

    vector<string> output = solver.topKFrequent(a, 4);

    print_v(output);
    
    return 0;
}

