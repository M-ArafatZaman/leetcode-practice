#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl 

template <class T> void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}" << endl; }

template <typename T>
T maxVec(vector<T>& nums) {
    T highest = nums[0];

    for (vector<int>::iterator it = nums.begin()+1; it < nums.end(); ++it) {
        if (*it > highest) highest = *it;
    }

    return highest;
}

template <typename T>
T minVec(vector<T>& nums) {
    T lowest = nums[0];

    for (vector<int>::iterator it = nums.begin()+1; it < nums.end(); ++it) {
        if (*it < lowest) lowest = *it;
    }

    return lowest;
}

#define PI = 3.141592653589793

/// @brief This function is used to run EACH test case
/// @param _t This parameter is used to indicate the i-th test case
void run_test_case(int _t = 0) {
    int r, e, c;

    cin >> r >> e >> c;

    int profit = e - c;

    if (profit > r) {
        cout << "advertise\n";
    } else if (profit < r) {
        cout << "do not advertise\n";
    } else {
        cout << "does not matter\n";
    }

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

