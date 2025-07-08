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

public:
    BinaryTree() {
        root = NULL;
    }

    void buildFromLevelOrder() {
        queue<Node*> q;
        cout << "Enter data for root: ";
        int data;
        cin >> data;

        if (data == -1) {
            root = NULL;
            return;
        }

        root = new Node(data);
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            cout << "Enter left node for " << temp->data << ": ";
            int leftData;
            cin >> leftData;

            if (leftData != -1) {
                temp->left = new Node(leftData);
                q.push(temp->left);
            }

            cout << "Enter right node for " << temp->data << ": ";
            int rightData;
            cin >> rightData;

            if (rightData != -1) {
                temp->right = new Node(rightData);
                q.push(temp->right);
            }
        }
    }
};

int main() {
    BinaryTree bt;

    bt.buildFromLevelOrder();

    return 0;
}
