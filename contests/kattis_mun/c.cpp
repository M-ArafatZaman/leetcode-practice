#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

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


string searchValue(map <string, string>& m, string value) {
    string ans = "-1";

    for (auto n : m) {
        if (n.second == value) {
            return n.first;
        }
    }

    return "-1";
}



/// @brief This function is used to run EACH test case
/// @param _t This parameter is used to indicate the i-th test case
void run_test_case(string m) {
    map <string, string> codes = { {"A", ".-"}, {"B", "-..."}, {"C", "-.-."}, {"D", "-.."}, {"E", "."}, {"F", "..-."}, {"G", "--."}, {"H", "...."}, {"I", ".."}, {"J", ".---"}, {"K", "-.-"}, {"L", ".-.."}, {"M", "--"}, {"N", "-."}, {"O", "---"}, {"P", ".--."}, {"Q", "--.-"}, {"R", ".-."}, {"S", "..."}, {"T", "-"}, {"U", "..-"}, {"V", "...-"}, {"W", ".--"}, {"X","-..-"}, {"Y", "-.--"}, {"Z", "--.."}, {"_", "..--"}, {",", ".-.-"}, {".", "---."}, {"?", "----"} };

    // FENDSVTSLHW.EDATS,EULAY

    vector<size_t> nums;
    string morse;
    string _i = "";

    for (auto i : m) {
        _i = i;
        morse += codes[_i];
        nums.push_back( codes[_i].length() );
    }
    reverse(nums.begin(), nums.end());

    string finalUncoded;
    int pos = 0;
    string mCode;

    for (auto j : nums) {
        mCode = morse.substr(pos, j);
        pos = pos + j;
        finalUncoded += searchValue(codes, mCode);
    }

    cout << finalUncoded << "\n";


    return;
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /* int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        run_test_case(i);
    }; */

    string s;

    while (getline(cin, s)) {

        if (s.empty()) {
            break;
        }
        run_test_case(s);
    }

    return 0;
}

