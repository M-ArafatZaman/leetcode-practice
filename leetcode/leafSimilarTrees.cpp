#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

/**
 * This is a template file for all leetcode problems
 * Author: @ Mohammad Arafat Zaman
*/

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl 

template <class T> void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}" << endl; }

template <class T, class S> void print_map(map<T, S>& _m) { cout << "{ "; for (auto & n : _m) { cout << n.first << " = " << n.second << ", "; } cout << "\b }" << endl; }

#define PI = 3.141592653589793

// https://leetcode.com/problems/leaf-similar-trees/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> getVal(TreeNode* node) {
        vector<int> left;
        vector<int> right;
        if (node->left != nullptr) left = getVal(node->left);
        if (node->right != nullptr) right = getVal(node->right);
        

        if (left.empty() && right.empty()) {
            left.push_back(node->val);
        } else {
            left.insert(left.end(), right.begin(), right.end());
        }

        return left;
    };
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1 = getVal(root1);
        vector<int> leaf2 = getVal(root2);
        return (bool)(leaf1 == leaf2);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;
    vector<int> a = {1,2,3};
    vector<int> b = {1,3,2};

    TreeNode* t1 = new TreeNode(1);
    TreeNode* t1l = new TreeNode(2);
    TreeNode* t1r = new TreeNode(3);
    t1->left = t1l;
    t1->right = t1r;

    TreeNode* t2 = new TreeNode(1);
    TreeNode* t2l = new TreeNode(3);
    TreeNode* t2r = new TreeNode(2);
    t2->left = t2l;
    t2->right = t2r;

    cout << solver.leafSimilar(t1, t2) << endl;
    
    return 0;
}

