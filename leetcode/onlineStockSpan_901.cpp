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

template <class T, class S>
void print_map(map<T, S>& _m) {
    cout << "{ ";
    for (auto & n : _m) {
        cout << n.first << " = " << n.second << ", ";
    }
    cout << "\b }" << endl;
}

#define PI = 3.141592653589793

// https://leetcode.com/problems/online-stock-span/
class StockSpanner {
public:
    vector<int> stocks;
    vector<int> spans;

    StockSpanner() {
        // Pass
    };
    
    int next(int price) {
        stocks.push_back(price);
        int span = 1;

        if (stocks.size() == 1) {
            spans.push_back(span);
            return 1;
        };

        int curr_index = stocks.size() - 1;
        // Keep going back until index goes below 0
        while (curr_index > 0) {
            if (price >= stocks[curr_index-1]) {
                span += spans[curr_index-1];
                curr_index -= spans[curr_index-1];
            } else {
                spans.push_back(span);
                return span;
            }
        };
        spans.push_back(span);
        return span;
    };

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    StockSpanner stockSpanner = StockSpanner();
    cout << stockSpanner.next(100) << endl; // return 1
    cout << stockSpanner.next(80) << endl;  // return 1
    cout << stockSpanner.next(60) << endl;  // return 1
    cout << stockSpanner.next(70) << endl;  // return 2
    cout << stockSpanner.next(60) << endl;  // return 1
    cout << stockSpanner.next(75) << endl;  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    cout << stockSpanner.next(85) << endl;  // return 6


    
    return 0;
}

