#include <iostream>
using namespace std;

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;

        if (root->val >= low && root->val <= high) sum += root->val;

        if (root->left != nullptr) sum += rangeSumBST(root->left, low, high);
        if (root->right != nullptr) sum += rangeSumBST(root->right, low, high);

        return sum;
    }
};

int main() {

    Solution solver;

    TreeNode* a = new TreeNode(10);
    TreeNode* al = new TreeNode(5);
    TreeNode* ar = new TreeNode(15);
    TreeNode* all = new TreeNode(3);
    TreeNode* alr = new TreeNode(7);
    TreeNode* arr = new TreeNode(18);

    a->left = al;
    a->right = ar;

    al->left = all;
    al->right = alr;

    ar->right = arr;

    cout << solver.rangeSumBST(a, 7, 15) << endl;


    return 0;
}