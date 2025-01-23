#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node* left; // Pointer to left node
    Node* right; // Pointer to right node
    Node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Inorder Traversal (DFS)
void Inorder(Node *root){
    if (root != nullptr)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
    
}

// Preorder Traversal (DFS)
void Preorder(Node *root){
    if (root != nullptr)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
    
}

// Postorder Traversal (DFS)
void Postorder(Node *root){
    if (root != nullptr)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
    
}

// Level Order Traversal (BFS)
void Level_Order(Node *root){
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

int height(Node* root){
    if(root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int height_diameter(Node* root, int& dia){
    if (root == nullptr) 
        return 0;

    // Recursively get heights of left and right subtrees
    int leftHeight = height_diameter(root->left, dia);
    int rightHeight = height_diameter(root->right, dia);

    // update diameter
    dia = max(dia, leftHeight + rightHeight + 1);

    return 1 + max(leftHeight, rightHeight);

}

int diameter(Node* root){
    int dia = 0;
    height_diameter(root, dia);
    return dia;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
         1
        / \
      2     3
     / \   / \
    4   5 6   7       */

    cout << "Inorder Traversal: \n";
    Inorder(root);
    cout << "\n";

    cout << "Preorder Traversal: \n";
    Preorder(root);
    cout << "\n";

    cout << "Postorder Traversal: \n";
    Postorder(root);
    cout << "\n";

    cout << "Level Order Traversal: \n";
    Level_Order(root);
    cout << "\n";

    cout << "Height of tree: " << height(root);
    cout << "\n";

    cout << "Diameter of tree: " << diameter(root);
    cout << "\n";
}