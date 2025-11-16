//
// Created by Naveed on 13/11/2025.
//

/* Exercise 3: Warehouse inventory system
You're a manager managing a warehouse inventory system where you organize item prices (in dollars) into a binary search tree (BST).
The system helps you efficiently manage items by categorizing prices above the average ($13.73) on the right side and
prices below the average on the left side of the tree giving you powerful tools to analyze and update your inventory seamlessly.

11.0	13.5	9.5	12.5	14.0	15.5	8.0	10.5	11.5	13.0	15.5	18.0	17.5	19.0	17.0

Write a program in C++ and perform following task:
a. Display prices in sorted order
b. Display the number of items priced above the average.
c. Display the number of items priced below the average.

Add the following functions in above scenario.

d. Display the highest price.
e. Display the lowest price.
f. Search for a price provided by the user.
g. Delete a price provided by the user.
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct Node
{
    double price;
    Node* left;
    Node* right;

    Node(double p) : price(p), left(nullptr), right(nullptr)
    {
    }
};

Node* insertNode(Node* root, double val)
{
    if (!root) return new Node(val);
    if (val < root->price) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val); // duplicates go right
    return root;
}

void inorder(Node* root)
{
    if (!root) return;
    inorder(root->left);
    printf("%.2f ", root->price);
    inorder(root->right);
}

int countAbove(Node* root, double avg)
{
    if (!root) return 0;
    int c = (root->price > avg) ? 1 : 0;
    return c + countAbove(root->left, avg) + countAbove(root->right, avg);
}

int countBelow(Node* root, double avg)
{
    if (!root) return 0;
    int c = (root->price < avg) ? 1 : 0;
    return c + countBelow(root->left, avg) + countBelow(root->right, avg);
}

Node* findMin(Node* root)
{
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* findMax(Node* root)
{
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

bool approxEqual(double a, double b, double eps = 1e-6)
{
    return fabs(a - b) < eps;
}

bool searchNode(Node* root, double key)
{
    if (!root) return false;
    if (approxEqual(root->price, key)) return true;
    if (key < root->price) return searchNode(root->left, key);
    return searchNode(root->right, key);
}

Node* deleteNode(Node* root, double key)
{
    if (!root) return nullptr;
    if (key < root->price - 1e-6)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->price + 1e-6)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // found node to delete
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
            root->price = succ->price;
            root->right = deleteNode(root->right, succ->price);
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
    double values[] = {
        11.0, 13.5, 9.5, 12.5, 14.0, 15.5, 8.0, 10.5, 11.5, 13.0, 15.5, 18.0, 17.5, 19.0, 17.0
    };
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; ++i)
        root = insertNode(root, values[i]);

    const double AVG = 13.73;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Display prices (sorted)\n";
        cout << "2. Count items priced above average\n";
        cout << "3. Count items priced below average\n";
        cout << "4. Display highest price\n";
        cout << "5. Display lowest price\n";
        cout << "6. Search for a price\n";
        cout << "7. Delete a price\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";

        int choice;
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1)
        {
            cout << "Prices (sorted): ";
            inorder(root);
            cout << "\n";
        }
        else if (choice == 2)
        {
            cout << "Above average (" << AVG << "): " << countAbove(root, AVG) << "\n";
        }
        else if (choice == 3)
        {
            cout << "Below average (" << AVG << "): " << countBelow(root, AVG) << "\n";
        }
        else if (choice == 4)
        {
            Node* mx = findMax(root);
            if (mx) printf("Highest price: %.2f\n", mx->price);
            else cout << "Tree is empty.\n";
        }
        else if (choice == 5)
        {
            Node* mn = findMin(root);
            if (mn) printf("Lowest price: %.2f\n", mn->price);
            else cout << "Tree is empty.\n";
        }
        else if (choice == 6)
        {
            cout << "Enter price to search: ";
            double key;
            if (!(cin >> key))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input.\n";
                continue;
            }
            cout << (searchNode(root, key) ? "Found\n" : "Not found\n");
        }
        else if (choice == 7)
        {
            cout << "Enter price to delete: ";
            double key;
            if (!(cin >> key))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input.\n";
                continue;
            }
            if (searchNode(root, key))
            {
                root = deleteNode(root, key);
                cout << "Deleted. In-order now: ";
                inorder(root);
                cout << "\n";
            }
            else
            {
                cout << "Price not found.\n";
            }
        }
        else if (choice == 8)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Select 1-8.\n";
        }
    }

    freeTree(root);
}