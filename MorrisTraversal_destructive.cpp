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
        left = NULL;
        right = NULL;
    }
};

vector<int> morrisTraversal(Node* root) {
    Node* current = root;
    vector<int> result;

    while (current != NULL) {
        if (current->left == NULL) {
            result.push_back(current->data);
            current = current->right;
        } else {
            Node* leftChild = current->left;

            while (leftChild->right != NULL) {
                leftChild = leftChild->right;
            }

            leftChild->right = current;

            Node* temp = current;
            current = current->left;
            temp->left = NULL;
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

    vector<int> result = morrisTraversal(root);

    cout << "Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}