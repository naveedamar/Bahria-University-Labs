//
// Created by Naveed on 12/10/2025.
//

/*Objective:
*Consider a web browser that keeps track of the pages a user visits in a session using a doubly linked list.
*Each node in the list represents a web page and contains the URL of the page, the title of the page, and pointers to the previous and next pages in the history.
*Write a program that implements the above scenario with the following functionalities
*i.	Insert the web page at the end of the double link list.
*ii. Display all pages in backward and forward directions.
*iii. Delete the web page from any position.
*/

#include <iostream>
#include <string>
using namespace std;

struct WebPage
{
    string url;
    string title;
    WebPage* next;
    WebPage* prev;

    WebPage(const string& u, const string& t)
        : url(u), title(t), next(nullptr), prev(nullptr)
    {
    }
};

void insertPage(WebPage*& head, WebPage*& tail, const string& url, const string& title)
{
    WebPage* page = new WebPage(url, title);
    if (!head)
    {
        head = tail = page;
    }
    else
    {
        tail->next = page;
        page->prev = tail;
        tail = page;
    }
}

void displayForward(WebPage* head)
{
    cout << "Browser History (Forward):\n";
    WebPage* curr = head;
    while (curr)
    {
        cout << curr->title << " - " << curr->url << endl;
        curr = curr->next;
    }
}

void displayBackward(WebPage* tail)
{
    cout << "Browser History (Backward):\n";
    WebPage* curr = tail;
    while (curr)
    {
        cout << curr->title << " - " << curr->url << endl;
        curr = curr->prev;
    }
}

void deletePage(WebPage*& head, WebPage*& tail, int pos)
{
    if (!head) return;
    WebPage* curr = head;
    int idx = 1;
    while (curr && idx < pos)
    {
        curr = curr->next;
        idx++;
    }
    if (!curr) return;
    if (curr->prev) curr->prev->next = curr->next;
    else head = curr->next;
    if (curr->next) curr->next->prev = curr->prev;
    else tail = curr->prev;
    delete curr;
}

void deleteAll(WebPage*& head, WebPage*& tail)
{
    WebPage* curr = head;
    while (curr)
    {
        WebPage* next = curr->next;
        delete curr;
        curr = next;
    }
    head = tail = nullptr;
}

int main()
{
    WebPage* head = nullptr;
    WebPage* tail = nullptr;
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert web page\n";
        cout << "2. Display history forward\n";
        cout << "3. Display history backward\n";
        cout << "4. Delete web page at position\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            string url, title;
            cout << "Enter URL: ";
            getline(cin, url);
            cout << "Enter Title: ";
            getline(cin, title);
            insertPage(head, tail, url, title);
        }
        else if (choice == 2)
        {
            displayForward(head);
        }
        else if (choice == 3)
        {
            displayBackward(tail);
        }
        else if (choice == 4)
        {
            int pos;
            cout << "Enter position to delete: ";
            cin >> pos;
            cin.ignore();
            deletePage(head, tail, pos);
        }
    }
    while (choice != 5);
    deleteAll(head, tail);
}
