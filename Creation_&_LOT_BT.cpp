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

public:
    BinaryTree() {
        root = NULL;
    }

    void create() {
        root = buildTree();
    }

    void levelOrderTraversal() {
        if (root == NULL) {
            return;
        }

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp == NULL) {
                cout << endl;
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                cout << temp->data << " ";

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }
    }
};

int main() {
    BinaryTree bt;

    bt.create();

    cout << "Level Order Traversal with level separation:" << endl;
    bt.levelOrderTraversal();

    return 0;
}
