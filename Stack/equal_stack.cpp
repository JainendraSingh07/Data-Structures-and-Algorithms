/*
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they are all the same height, then return the height.

Example




There are  and  cylinders in the three stacks, with their heights in the three arrays. Remove the top 2 cylinders from  (heights = [1, 2]) and from  (heights = [1, 1]) so that the three stacks all are 2 units tall. Return  as the answer.

Note: An empty stack is still a stack.

Function Description

Complete the equalStacks function in the editor below.

equalStacks has the following parameters:

int h1[n1]: the first array of heights
int h2[n2]: the second array of heights
int h3[n3]: the third array of heights
Returns

int: the height of the stacks when they are equalized
Input Format

The first line contains three space-separated integers, , , and , the numbers of cylinders in stacks , , and . The subsequent lines describe the respective heights of each cylinder in a stack from top to bottom:

The second line contains  space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.
The third line contains  space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.
The fourth line contains  space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.
Constraints

Sample Input

STDIN       Function
-----       --------
5 3 4       h1[] size n1 = 5, h2[] size n2 = 3, h3[] size n3 = 4  
3 2 1 1 1   h1 = [3, 2, 1, 1, 1]
4 3 2       h2 = [4, 3, 2]
1 1 4 1     h3 = [1, 1, 4, 1]
Sample Output

5
*/

#include <iostream>
#include <vector>
#include <numeric>  // for accumulate

using namespace std;

// Function to calculate the maximum possible equal height of three stacks
#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void topView(Node* root) {
    if (root == NULL) return;
    
    // Map to store the first node at each horizontal distance
    map<int, int> topNodes;
    // Queue to perform level-order traversal, storing pairs of nodes and their horizontal distance
    queue<pair<Node*, int>> q;
    
    q.push({root, 0});
    
    while (!q.empty()) {
        Node* current = q.front().first;
        int hd = q.front().second;
        q.pop();
        
        // If this horizontal distance is being seen for the first time
        if (topNodes.find(hd) == topNodes.end()) {
            topNodes[hd] = current->data;
        }
        
        if (current->left != NULL) {
            q.push({current->left, hd - 1});
        }
        
        if (current->right != NULL) {
            q.push({current->right, hd + 1});
        }
    }
    
    // Print the top view nodes in order of their horizontal distance
    for (auto it : topNodes) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(6);
    root->right->right->left->right = new Node(4);

    topView(root);
    
    return 0;
}
