//
// Created by Naveed on 09/10/2025.
//

/*
 *Objective:
You are assigned the task of creating a news feed system for a social media platform using a singly linked list in C++.
Each post should be represented as a node containing both the post content and a timestamp.
Your program should support the following operations:
1.	Adding a new post to the begining of the feed
2.	Removing a post by its content
3.	Displaying all posts in chronological order
4.	Total Count of Posts
5.	Search a post by its content

In your main() function, please demonstrate the functionality by:
•	Adding seven posts on any topic of your choice
•	Removing two posts as requested by the user
•	Displaying all remaining posts to verify that the system operates correctly.
•	Display the total no. of posts.
•	Search any one post as requested by user
 */

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Post
{
    string content;
    string timestamp;
    Post* next;

    Post(const string& c) : content(c), next(nullptr)
    {
        time_t now = time(0);
        timestamp = ctime(&now);
        if (!timestamp.empty() && timestamp.back() == '\n') timestamp.pop_back();
    }
};

class NewsFeed
{
    Post* head;

public:
    NewsFeed() : head(nullptr)
    {
    }

    void addPost(const string& content)
    {
        Post* newPost = new Post(content);
        newPost->next = head;
        head = newPost;
    }

    bool removePost(const string& content)
    {
        Post *curr = head, *prev = nullptr;
        while (curr)
        {
            if (curr->content == content)
            {
                if (prev) prev->next = curr->next;
                else head = curr->next;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    void displayPosts() const
    {
        Post* curr = head;
        int idx = 1;
        while (curr)
        {
            cout << idx++ << ". [" << curr->timestamp << "] " << curr->content << endl;
            curr = curr->next;
        }
    }

    int countPosts() const
    {
        int count = 0;
        Post* curr = head;
        while (curr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }

    bool searchPost(const string& content) const
    {
        Post* curr = head;
        while (curr)
        {
            if (curr->content == content) return true;
            curr = curr->next;
        }
        return false;
    }

    ~NewsFeed()
    {
        while (head)
        {
            Post* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    NewsFeed feed;

    feed.addPost("C++ is powerful!");
    feed.addPost("AI is transforming the world.");
    feed.addPost("Stay hydrated.");
    feed.addPost("Read more books.");
    feed.addPost("Exercise daily.");
    feed.addPost("Learn new skills.");
    feed.addPost("Enjoy coding!");


    string remove1, remove2;
    cout << "Enter content of first post to remove: ";
    getline(cin, remove1);
    if (feed.removePost(remove1))
        cout << "Post removed.\n";
    else
        cout << "Post not found.\n";

    cout << "Enter content of second post to remove: ";
    getline(cin, remove2);
    if (feed.removePost(remove2))
        cout << "Post removed.\n";
    else
        cout << "Post not found.\n";

    cout << "\nRemaining posts in chronological order:\n";
    feed.displayPosts();

    cout << "\nTotal number of posts: " << feed.countPosts() << endl;

    string searchContent;
    cout << "Enter content to search: ";
    getline(cin, searchContent);
    if (feed.searchPost(searchContent))
        cout << "Post found.\n";
    else
        cout << "Post not found.\n";
}
