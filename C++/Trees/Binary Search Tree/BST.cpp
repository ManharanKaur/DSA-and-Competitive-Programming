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
        left = NULL;
        right = NULL;
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

//Level order Traversal
void LevelOrder(Node* root){
    if(root == nullptr){
        cout << "Empty Tree1\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}


// Function to insert a new key into the BST
void insert(Node* root, int key){
    if(root == nullptr){
        root = new Node(key);
        return;
    }

    while(1){
        if(key < root->data){
            if(root->left == nullptr){
                root->left = new Node(key);
                break;
            }
            else
                root = root->left;
        }
        else if (key >= root->data){
            if(root->right == nullptr){
                root->right = new Node(key);
                break;
            }
            else
                root = root->right;
        }
    }
}

void search(Node* root, int key){
    if(root == NULL){
        cout << key << " NOT FOUND in the tree\n";
        return;
    }
    if(root->data == key){
        cout << key << " FOUND in the tree\n";
    }
    if(root->data < key) search(root->right, key);
    if(root->data > key) search(root->left, key);
}


Node * getsuccessor(Node* temp){
    temp = temp->right;
    while(temp != nullptr && temp->left != nullptr)
        temp = temp->left;
    return temp;
}

Node *deleteNode(Node *root, int key){
    if (root == nullptr)
        return root; // Base case: the tree is empty

    // Recursively traverse the tree to find the node to delete
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else{
        // Node found

        // Case 1: Node has no children (leaf node)
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        // Case 2: Node has one child
        else if (root->left == nullptr){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr){
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has two children
        else{
            // Find the inorder successor (smallest node in the right subtree)
            Node *temp = getsuccessor(root->right);

            // Replace root's value with the inorder successor's value
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}


int main(){
    int A[] = {50,60,40,70,30,80,20,90,10};
    int len = sizeof(A)/sizeof(int);
    Node * root = new Node(A[0]);
    for (int i = 1; i < len; i++)
    {
        insert(root,A[i]);
    }
    Inorder(root);
    cout << endl;
    LevelOrder(root);
    cout << endl;
    search(root,40);
    search(root,45);

    Node * new_root = deleteNode(root, 70);
    Inorder(new_root);
    cout << endl;

}