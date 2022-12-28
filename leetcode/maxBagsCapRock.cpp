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

struct Bag {
    int cap;
    int rock;
    Bag(int c, int r): cap(c), rock(r) {};
};

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<Bag> Bags;

        // CONTAIN CAP AND ROCKS IN A bag
        for (int i = 0; i < n; ++i) {
            Bags.push_back(Bag(capacity[i], rocks[i]));
        };

        // Custom sorter
        struct {
            bool operator()(Bag& a, Bag& b) {
                return a.cap - a.rock < b.cap - b.rock;
            };
        } Comparator;

        // Sort Bags
        sort(Bags.begin(), Bags.end(), Comparator);

        int filled = 0;
        // Fill bags
        for (auto bag : Bags) {
            while (additionalRocks > 0 && bag.rock < bag.cap) {
                bag.rock += 1;
                additionalRocks -= 1;
            }
            if (bag.rock >= bag.cap) {
                filled++;
                continue;
            };
        };

        return filled;
    }


};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;
    vector<int> cap = {91,54,63,99,24,45,78};
    vector<int> rocks = {35,32,45,98,6,1,25};
    int ADD_ROCKS = 17;
    cout << solver.maximumBags(cap, rocks, ADD_ROCKS) << endl;

    
    return 0;
}

