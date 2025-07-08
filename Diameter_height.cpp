#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    pair<int, int> diameterFast(Node* node) {
        if (node == NULL) {
            return make_pair(0, 0);
        }

        pair<int, int> left = diameterFast(node->left);
        pair<int, int> right = diameterFast(node->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int diameter() {
        return diameterFast(root).first;
    }
};

int main() {
    BinaryTree tree;

    // Example Tree:
    //       1
    //      / \
    //     2   3
    //    / \     
    //   4   5  

    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);

    cout << "Diameter of the binary tree is: " << tree.diameter() << endl;

    return 0;
}
