#include <bits/stdc++.h>
using namespace std;



int main() {

    int r, f;

    cin >> r >> f;

    float rps = 180/r;
    float ang = 0 + (rps * f);
    int ang2 = (int)floor(ang) % 360;

    if (abs(ang - ang2) > 1) {
        ang = (ang2 % 360) + (float)(ang - (float)a);
    }


    if (ang > 270 || ang < 90) {
        cout << "up" << endl;
    } else {
        cout << "down" << endl;
    }
    

    return 0;
};