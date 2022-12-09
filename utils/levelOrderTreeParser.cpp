#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/// @brief A function to parse a tree from an array in leetcode style
/// @param arr - The array
/// @return - The root tree node
TreeNode* parseTree(vector<int>& arr) {
    TreeNode* root = new TreeNode();
    if (arr.size() == 0) return root;
    root->val = arr[0];

    // Parse using level order traversal
    queue<TreeNode*> nodes;
    nodes.push(root);
    for (int i = 1; i < arr.size(); ++i) {
        TreeNode* currNode = nodes.front();
        nodes.pop();
        
        // Parse the current node
        if (arr[i] != NULL) {
            TreeNode* leftChild = new TreeNode(arr[i]);
            currNode->left = leftChild;
            nodes.push(leftChild);
        }

        ++i;
        // Pre parse the next node (the right node)
        if (i < arr.size() && arr[i] != NULL) {
            TreeNode* rightChild = new TreeNode(arr[i]);
            currNode->right = rightChild;
            nodes.push(rightChild);
        }
    };

    return root;
};

int main() {
    vector<int> a = {4,2,6,1,3,5,7};

    return 0;
}
