#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl 

template <class T> void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

#define PI = 3.141592653589793

const string END_L = "\n";

/// @brief This function is used to run EACH test case
/// @param _t This parameter is used to indicate the i-th test case
void run_test_case(int _t = 0) {

    string alphabets = "abcdefghijklmnopqrstuvwxyz";

    int n;
    long long int code;
    int encodeNo;
    int lastDigit;
    string s;

    cin >> n;
    cin >> code;

    while (code > 0) {
        lastDigit = code % 10;

        if (lastDigit == 0) {
            code = code / 10;
            lastDigit = code % 100;
            code = code / 100;
        } else {
            code = code / 10;
        }
        s = alphabets[lastDigit-1] + s;
    }

    cout << s << END_L;

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

