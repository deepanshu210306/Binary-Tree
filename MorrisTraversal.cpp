#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> morrisInorder(Node* root) {
    vector<int> result;
    Node* current = root;

    while (current != nullptr) {

        if (current->left == nullptr) {
            result.push_back(current->data);
            current = current->right;
        }
        else {
            Node* predecessor = current->left;

            // Find rightmost node in left subtree
            while (predecessor->right != nullptr &&
                   predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                // Create thread
                predecessor->right = current;
                current = current->left;
            }
            else {
                // Remove thread
                predecessor->right = nullptr;
                result.push_back(current->data);
                current = current->right;
            }
        }
    }

    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = morrisInorder(root);

    cout << "Morris Inorder Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}