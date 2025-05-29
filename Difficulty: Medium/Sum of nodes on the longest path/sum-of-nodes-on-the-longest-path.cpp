/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    pair<int, int> helper(Node* node) {
        if (!node) return {0, 0};
    
        auto left = helper(node->left);
        auto right = helper(node->right);
    
        if (left.first > right.first)
            return {left.first + 1, left.second + node->data};
        else if (right.first > left.first)
            return {right.first + 1, right.second + node->data};
        else
            return {left.first + 1, max(left.second, right.second) + node->data};
    }

    int sumOfLongRootToLeafPath(Node *root) {
        return helper(root).second;
    }

};