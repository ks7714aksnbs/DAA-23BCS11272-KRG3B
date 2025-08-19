#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;
    BinaryTree(): root(nullptr) {}

    Node* insert(Node* root, int x) {
        if (!root) return new Node(x);
        if (!root->left) root->left = insert(root->left, x);
        else root->right = insert(root->right, x);
        return root;
    }

    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void levelorder(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* t = q.front(); q.pop();
            cout << t->data << " ";
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
    }
};

int main() {
    BinaryTree bt;
    bt.root = bt.insert(bt.root, 1);
    bt.insert(bt.root, 2);
    bt.insert(bt.root, 3);
    bt.insert(bt.root, 4);
    bt.insert(bt.root, 5);

    cout << "Preorder: "; bt.preorder(bt.root); cout << "\n";
    cout << "Inorder: "; bt.inorder(bt.root); cout << "\n";
    cout << "Postorder: "; bt.postorder(bt.root); cout << "\n";
    cout << "Levelorder: "; bt.levelorder(bt.root); cout << "\n";
}

