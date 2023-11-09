#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0; int r = s.length();
        int d_low = '0', d_high = '9';
        int a_low = 'a', a_high = 'z';
        int A_low = 'A', A_high = 'Z';
        while ( l <= r ) {
            char l_c = tolower(s[l]);
            char r_c = tolower(s[r]);
            
            if (!( (l_c >= d_low && l_c <= d_high) || (l_c >= a_low && l_c <= a_high) || (l_c >= A_low && l_c <= A_high) )) {
                l++;
                continue;
            }
            if (!( (r_c >= d_low && r_c <= d_high) || (r_c >= a_low && r_c <= a_high) || (r_c >= A_low && r_c <= A_high) )) {
                r--;
                continue;
            }
            if (! (l_c >= d_low && l_c <= d_high) ) {
                l_c = tolower(s[l]);
            }
            if (! (r_c >= d_low && r_c <= d_high) ) {
                r_c = tolower(s[r]);
            }
            if (l_c != r_c) return false;
            l++; r--;
        }
        return true;
    }
};

int main() {
    Solution sol;

    string a = "ab2a";
    cout << sol.isPalindrome(a) << endl;

    return 0;
}