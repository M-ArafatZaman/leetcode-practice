#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <climits>

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

struct Element {
    int index;
    int val;
    int oVal;
    Element(int i, int v, int o): index(i), val(v), oVal(o) {}
};

bool comparator(Element a, Element b) {
    if (a.val < b.val) {
        return true;
    
    } else if (a.val == b.val && a.oVal < b.oVal) {
        return true;
    
    } else {
        return false;
    }
}


// https://leetcode.com/problems/find-k-closest-elements/
class Solution {
    public: 
        vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            int n = arr.size();
            //vector<int> finalArr(k, 0);
            vector<int> finalArr;
            vector<Element> prefix = prefixDist(arr, x);

            sort(prefix.begin(), prefix.end(), comparator);

            for (int j = 0; j < k; ++j ) {
                //finalArr[j] = prefix[j].oVal;
                finalArr.push_back(prefix[j].oVal);
            }

            sort(finalArr.begin(), finalArr.end());
            

            return finalArr;
        };

        // Generate a prefix Distribution
        vector<Element> prefixDist(vector<int>& arr, int x) {
            vector<Element> ans;
            int dist;

            for (vector<int>::iterator it = arr.begin(); it < arr.end(); ++it) {
                dist = (int)distance(arr.begin(), it);    
                Element a(dist, abs(*it - x), *it);
                ans.push_back(a);
            }

            return ans;
        }

};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;
    int t;
    cin >> t;

    vector<int> a = {1,2,3,4,5};
    vector<int> ans = solver.findClosestElements(a, 4, t);
    print_v(ans);

    /* vector<int>::iterator b = a.begin();
    a.insert(b, 10);

    print_v(a); */

    
    return 0;
}

