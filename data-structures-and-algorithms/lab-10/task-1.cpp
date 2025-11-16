//
// Created by Naveed on 13/11/2025.
//

/* Exercise 1: Library Management System
Write a program in C++ to manage a large collection of books in order to efficiently organize and search for specific books having IDs and create following functions.
1.	Insert: To insert books in binary search tree in following order:
{25,17,38,12,22,45,32,9,50,19,28,40}
2.	Traverse: To print pre-order, in-order and post-order traversal
3.	Search: To search for a specific book id. If found then print “Found” else “Not found”
4.	Delete: To delete an element from binary search tree.
*/

#include <iostream>
#include <limits>
using namespace std;

struct Node
{
    int id;
    Node* left;
    Node* right;

    Node(int v) : id(v), left(nullptr), right(nullptr)
    {
    }
};

Node* insertNode(Node* root, int val)
{
    if (!root) return new Node(val);
    if (val < root->id) root->left = insertNode(root->left, val);
    else if (val > root->id) root->right = insertNode(root->right, val);
    return root;
}

void preorder(Node* root)
{
    if (!root) return;
    cout << root->id << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if (!root) return;
    inorder(root->left);
    cout << root->id << " ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->id << " ";
}

bool searchNode(Node* root, int key)
{
    if (!root) return false;
    if (root->id == key) return true;
    if (key < root->id) return searchNode(root->left, key);
    return searchNode(root->right, key);
}

Node* findMin(Node* root)
{
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key)
{
    if (!root) return nullptr;
    if (key < root->id) root->left = deleteNode(root->left, key);
    else if (key > root->id) root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left)
        {
            Node* r = root->right;
            delete root;
            return r;
        }
        else if (!root->right)
        {
            Node* l = root->left;
            delete root;
            return l;
        }
        else
        {
            Node* succ = findMin(root->right);
            root->id = succ->id;
            root->right = deleteNode(root->right, succ->id);
        }
    }
    return root;
}

void freeTree(Node* root)
{
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main()
{
    Node* root = nullptr;
    int values[] = {25, 17, 38, 12, 22, 45, 32, 9, 50, 19, 28, 40};
    for (int v : values) root = insertNode(root, v);

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Traverse\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        int choice;
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1)
        {
            cout << "Pre-order: ";
            preorder(root);
            cout << "\nIn-order: ";
            inorder(root);
            cout << "\nPost-order: ";
            postorder(root);
            cout << "\n";
        }
        else if (choice == 2)
        {
            cout << "Enter id to search: ";
            int key;
            if (!(cin >> key))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid id.\n";
                continue;
            }
            cout << (searchNode(root, key) ? "Found\n" : "Not found\n");
        }
        else if (choice == 3)
        {
            cout << "Enter id to delete: ";
            int key;
            if (!(cin >> key))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid id.\n";
                continue;
            }
            root = deleteNode(root, key);
            cout << "In-order after deletion: ";
            inorder(root);
            cout << "\n";
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Select 1-4.\n";
        }
    }

    freeTree(root);
}
