#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

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


class LUPrefix {
    private:
        vector<int> a;
        int l = 0;
public:
    LUPrefix(int n) {
        for (int i = 0; i < n; ++i) {
            a.push_back(0);
        }
    }
    
    void upload(int video) {
        a[video-1] = 1;
    }
    
    int longest() {
        for (int i = l; i < a.size(); ++i) {
            if (a[i] == 1) {
                ++l;
            } else {
                break;
            }
        }

        return l;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests

    LUPrefix* obj = new LUPrefix(4);
    obj->upload(3);
    int param_2 = obj->longest();

    
    return 0;
}

