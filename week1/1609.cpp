#include <queue>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 */

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            int prev;
            if (level % 2 == 0) {
                prev = INT_MIN;
            } else {
                prev = INT_MAX;
            }

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                int val = node->val;

                if (level % 2 == 0) {
                    if (val % 2 == 0 || val <= prev) {
                        return false;
                    }
                } else {
                    if (val % 2 == 1 || val >= prev) {
                        return false;
                    }
                }

                prev = val;

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            level++;
        }

        return true;
    }
};