#include <iostream>
#include <queue>
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
private:
    Node* root;

    Node* buildTree() {
        int val;
        cout << "Enter data (-1 for NULL): ";
        cin >> val;

        if (val == -1) {
            return NULL;
        }

        Node* newNode = new Node(val);

        cout << "Enter left child of " << val << endl;
        newNode->left = buildTree();

        cout << "Enter right child of " << val << endl;
        newNode->right = buildTree();

        return newNode;
    }

    void inorder(Node* root) {
        if (root == NULL) {
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (root == NULL) {
            return;
        }

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (root == NULL) {
            return;
        }

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

public:
    BinaryTree() {
        root = NULL;
    }

    void create() {
        root = buildTree();
    }

    void printInorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void printPreorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    void printPostorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree bt;
    bt.create();

    bt.printInorder();
    bt.printPreorder();
    bt.printPostorder();

    return 0;
}
