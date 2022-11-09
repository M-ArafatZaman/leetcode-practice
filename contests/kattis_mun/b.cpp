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

int getNonZeroProducts(int x) {

    int prod = 1;
    int digit;
    while (x > 0) {
        digit = x % 10;
        x = x / 10;

        if (digit != 0) {
            prod = prod * digit;
        }

    }

    return prod;

}  

/// @brief This function is used to run EACH test case
/// @param _t This parameter is used to indicate the i-th test case
void run_test_case(int _t = 0) {
    
    // Here _t is the input
    int prod = _t;

    while (prod > 9 ) {
        prod = getNonZeroProducts(prod);
    }
    
    cout << prod;


    return;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;

    cin >> x;

    run_test_case(x);

    return 0;
}

