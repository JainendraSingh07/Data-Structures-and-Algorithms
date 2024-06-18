#include <iostream>
#include <queue>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void levelOrder(Node *root) {
    if (root == NULL) return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node *current = q.front();
        q.pop();
        
        cout << current->data << " ";
        
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}


int main() {

    Node *root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(6);
    root->right->right->left->right = new Node(4);
    levelOrder(root);
    
    return 0;
}
