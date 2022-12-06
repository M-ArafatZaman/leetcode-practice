#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

/**
 * This is a template file for CodeForces competitive programming
 * Author: @ Mohammad Arafat Zaman 
*/

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl 

template <class T> void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}" << endl; }

template <class T, class S> void print_map(map<T, S>& _m) { cout << "{ "; for (auto & n : _m) { cout << n.first << " = " << n.second << ", "; } cout << "\b }" << endl; }

#define PI = 3.141592653589793

/// @brief This function is used to run EACH test case
/// @param _t This parameter is used to indicate the i-th test case
void run_test_case(int _t = 0) {
    



    return;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        run_test_case(i);
    };

    return 0;
}

