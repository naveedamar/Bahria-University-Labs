//
// Created by Naveed on 13/11/2025.
//

/*Exercise 2: Word Search Puzzle game
You are a game developer working on a word search puzzle game. To efficiently manage the dictionary of words used in the game, you decide to implement a binary search tree (BST).
1.	Insert: To insert words in binary search tree in following order:
{"kiwi", "dog", "banana", "apple", "cat", "grape", "peach", "lemon", "orange", "raspberry", "strawberry", "zebra"}
2.	Traverse: To print pre-order, in-order and post-order traversal
3.	Search: To search for a specific word. If found then print “Found” else “Not found”
4.	Delete: To delete an element from binary search tree.
5.	Word_length: To display the length of word specified.
 */

#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string key;
    Node* left;
    Node* right;

    Node(const string& k) : key(k), left(nullptr), right(nullptr)
    {
    }
};

Node* insertNode(Node* root, const string& key)
{
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertNode(root->left, key);
    else if (key > root->key) root->right = insertNode(root->right, key);
    return root;
}

void preorder(Node* root)
{
    if (!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

bool searchNode(Node* root, const string& key)
{
    if (!root) return false;
    if (key == root->key) return true;
    if (key < root->key) return searchNode(root->left, key);
    return searchNode(root->right, key);
}

Node* findMin(Node* root)
{
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, const string& key)
{
    if (!root) return nullptr;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else
    {
        // node found
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
            root->key = succ->key;
            root->right = deleteNode(root->right, succ->key);
        }
    }
    return root;
}

int main()
{
    Node* root = nullptr;
    string words[] = {
        "kiwi", "dog", "banana", "apple", "cat", "grape", "peach", "lemon", "orange", "raspberry", "strawberry", "zebra"
    };
    for (const string& w : words) root = insertNode(root, w);

    while (true)
    {
        cout << "\nMenu:\n1. Traverse\n2. Search\n3. Delete\n4. Word_length\n5. Exit\nChoose option: ";
        int opt;
        if (!(cin >> opt)) break;

        if (opt == 1)
        {
            cout << "Choose traversal: 1=Pre-order 2=In-order 3=Post-order: ";
            int t;
            cin >> t;
            if (t == 1)
            {
                preorder(root);
                cout << "\n";
            }
            else if (t == 2)
            {
                inorder(root);
                cout << "\n";
            }
            else if (t == 3)
            {
                postorder(root);
                cout << "\n";
            }
            else cout << "Invalid traversal option\n";
        }
        else if (opt == 2)
        {
            cout << "Enter word to search: ";
            string w;
            cin >> w;
            cout << (searchNode(root, w) ? "Found\n" : "Not found\n");
        }
        else if (opt == 3)
        {
            cout << "Enter word to delete: ";
            string w;
            cin >> w;
            if (searchNode(root, w))
            {
                root = deleteNode(root, w);
                cout << "Deleted\n";
            }
            else cout << "Not found\n";
        }
        else if (opt == 4)
        {
            cout << "Enter word: ";
            string w;
            cin >> w;
            if (searchNode(root, w)) cout << "Length: " << w.length() << "\n";
            else cout << "Not found\n";
        }
        else if (opt == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid option\n";
        }
    }
}
