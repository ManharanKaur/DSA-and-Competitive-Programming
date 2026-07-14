#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;  // Pointer to left node
    Node *right; // Pointer to right node
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Inorder Traversal (DFS)
void Inorder(Node *root)
{
    if (root != nullptr)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void Preorder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(Node *root)
{
    if (root != nullptr)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

void PreorderIterative(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *node = s.top();
        cout << node->data << " ";
        s.pop();

        // Push right child first so that left child is processed first
        if (node->right != nullptr)
            s.push(node->right);
        if (node->left != nullptr)
            s.push(node->left);
    }
}

void InorderIterative(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> s;
    Node *current = root;

    while (current != nullptr || !s.empty())
    {
        // Reach the leftmost node of the current node
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }

        // Current must be nullptr at this point
        current = s.top();
        s.pop();
        cout << current->data << " ";

        // Visit the right subtree
        current = current->right;
    }
}

void PostorderIterativeUsing_2_Stacks(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        Node *node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left child first so that right child is processed first
        if (node->left != nullptr)
            s1.push(node->left);
        if (node->right != nullptr)
            s1.push(node->right);
    }

    // Print all nodes in postorder
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

void PostorderIterativeUsing_1_Stack(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> s;
    Node *current = root;
    Node *lastVisited = nullptr;

    while (!s.empty() || current != nullptr)
    {
        if (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }
        else
        {
            Node *peekNode = s.top();
            // If right child exists and traversing node from left child, then move right
            if (peekNode->right != nullptr && lastVisited != peekNode->right)
            {
                current = peekNode->right;
            }
            else
            {
                cout << peekNode->data << " ";
                lastVisited = peekNode;
                s.pop();
            }
        }
    }
}

// Preorder, Postorder, Inorder Traversal in a single traversal
void PrePostInorder(Node *root)
{
    if (root == nullptr)
        return;

    stack<pair<Node *, int>> s;
    s.push({root, 1});

    string pre = "", in = "", post = "";

    while (!s.empty())
    {
        auto &top = s.top();
        Node *node = top.first;
        int &state = top.second;

        if (state == 1)
        {
            pre += to_string(node->data) + " ";
            state++;
            if (node->left != nullptr)
                s.push({node->left, 1});
        }
        else if (state == 2)
        {
            in += to_string(node->data) + " ";
            state++;
            if (node->right != nullptr)
                s.push({node->right, 1});
        }
        else
        {
            post += to_string(node->data) + " ";
            s.pop();
        }
    }

    cout << "Preorder: " << pre << endl;
    cout << "Inorder: " << in << endl;
    cout << "Postorder: " << post << endl;
}

// Level order Traversal
void LevelOrder(Node *root)
{
    if (root == nullptr)
    {
        cout << "Empty Tree1\n";
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

// Function to insert a new key into the BST
void insert(Node *root, int key)
{
    if (root == nullptr)
    {
        root = new Node(key);
        return;
    }

    while (1)
    {
        if (key < root->data)
        {
            if (root->left == nullptr)
            {
                root->left = new Node(key);
                break;
            }
            else
                root = root->left;
        }
        else if (key >= root->data)
        {
            if (root->right == nullptr)
            {
                root->right = new Node(key);
                break;
            }
            else
                root = root->right;
        }
    }
}

void search(Node *root, int key)
{
    if (root == NULL)
    {
        cout << key << " NOT FOUND in the tree\n";
        return;
    }
    if (root->data == key)
    {
        cout << key << " FOUND in the tree\n";
    }
    if (root->data < key)
        search(root->right, key);
    if (root->data > key)
        search(root->left, key);
}

Node *getsuccessor(Node *temp)
{
    temp = temp->right;
    while (temp != nullptr && temp->left != nullptr)
        temp = temp->left;
    return temp;
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
        return root; // Base case: the tree is empty

    // Recursively traverse the tree to find the node to delete
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node found

        // Case 1: Node has no children (leaf node)
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // Case 2: Node has one child
        else if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has two children
        else
        {
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

int main()
{
    int A[] = {50, 60, 40, 70, 30, 80, 20, 90, 10};
    int len = sizeof(A) / sizeof(int);
    Node *root = new Node(A[0]);
    for (int i = 1; i < len; i++)
    {
        insert(root, A[i]);
    }
    Inorder(root);
    cout << endl;
    LevelOrder(root);
    cout << endl;
    search(root, 40);
    search(root, 45);

    Node *new_root = deleteNode(root, 70);
    Inorder(new_root);
    cout << endl;
}