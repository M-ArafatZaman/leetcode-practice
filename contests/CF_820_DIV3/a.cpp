#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl 

template <class T> void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

#define PI = 3.141592653589793

/// @brief This function is used to run EACH test case
/// @param _t This parameter is used to indicate the i-th test case
void run_test_case(int _t = 0) {
    
    long int a, b, c;

    cin >> a >> b >> c;

    int time_1 = abs( a - 1 );
    int time_2 = c > b ? abs( (c-b) + c - 1 ) : abs(b-1);

    if (time_1 < time_2 || a == 1 ) 
        cout << 1 << endl;
    else if (time_1 > time_2) 
        cout << 2 << endl;
    else
        cout << 3 << endl;


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

