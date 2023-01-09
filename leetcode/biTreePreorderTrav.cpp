#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

/**
 * This is a template file for all leetcode problems
 * Author: @ Mohammad Arafat Zaman
*/

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl 

template <class T> void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}" << endl; }

template <class T, class S> void print_map(map<T, S>& _m) { cout << "{ "; for (auto & n : _m) { cout << n.first << " = " << n.second << ", "; } cout << "\b }" << endl; }

#define PI = 3.141592653589793


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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> left;
        vector<int> right;
        // Check left
        if (root != nullptr && root->left != nullptr) {
            left = preorderTraversal(root->left);
        }
        // Check right
        if (root != nullptr && root->right != nullptr) {
            right = preorderTraversal(root->right);
        }
        // Inorder traversal
        if (root != nullptr) {
            left.insert(left.begin(), root->val);
        }
        left.insert(left.end(), right.begin(), right.end());

        return left;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;


    
    return 0;
}

