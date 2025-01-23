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
    if(root == nullptr)
        root = new Node(key);

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
    if(root->data < key) search(root->left, key);
    if(root->data > key) search(root->right, key);
}


Node * getsuccessor(Node* temp){
    temp = temp->right;
    while(temp != nullptr && temp->left != nullptr)
        temp = temp->left;
    return temp;
}

void delete_(Node* root, int key){
    if (root == nullptr) return; // base case
    
    if(root->data > key) delete_(root->left, key);
    else if(root->data < key) delete_(root->right, key);
    else{
        // if root has no children
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return;
        }
        // if root has one child
        else if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return;
        }
        else if (root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return;
        }
        // if root has two children
        else{
            // find inorder successor
            Node * temp = getsuccessor(root);

            // copy the inorder successor's data to the root
            root->data = temp->data;

            // delete the inorder successor
            delete_(root->right, temp->data);
        }
    }

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

    delete_(root, 70);
    Inorder(root);
    cout << endl;

}