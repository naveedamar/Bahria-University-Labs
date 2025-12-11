//
// Created by Naveed on 11/12/2025.
//

/*Exercise 1: LinkedIn Network of Faculty Members
Consider the given graph as LinkedIn network of faculty members of XYZ University. Your
goal is to create a system that allows users to explore direct connections within the network,
provides useful insights for collaboration opportunities within the university community.
 Implement the given LinkedIn network of faculty members as a graph using the
adjacency list representation.
 Apply BFS traversal starting from a specified user (node) in the network to identify direct
connections.
 Calculates and displays the average number of connections per user within the LinkedIn
network
 Identifies influential users within the network based on the number of connections they
have and their role as bridges between different groups of faculty members.
(Assume >=3 direct link as influential user)
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    int numUsers;
    vector<vector<int>> adjList;

public:
    Graph(int n)
    {
        numUsers = n;
        adjList.resize(n);
    }

    void addConnection(int u, int v)
    {
        if (u >= 0 && u < numUsers && v >= 0 && v < numUsers)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    const vector<vector<int>>& getAdjList() const
    {
        return adjList;
    }

    int getNumUsers() const
    {
        return numUsers;
    }
};

void performBFS(const Graph& graph, int startNode, const vector<string>& userNames)
{
    if (startNode < 0 || startNode >= graph.getNumUsers())
    {
        cout << "Invalid start user." << endl;
        return;
    }

    cout << "\n--- BFS Traversal starting from " << userNames[startNode] << " ---" << endl;

    vector<bool> visited(graph.getNumUsers(), false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout << "Traversal Order: ";
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << userNames[current] << " ";

        for (int neighbor : graph.getAdjList()[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << "\n------------------------------------------" << endl;
}

void calculateAverageConnections(const Graph& graph)
{
    if (graph.getNumUsers() == 0)
    {
        cout << "The network is empty." << endl;
        return;
    }

    double totalConnections = 0;
    const auto& adjList = graph.getAdjList();
    for (const auto& connections : adjList)
    {
        totalConnections += connections.size();
    }

    double average = totalConnections / graph.getNumUsers();
    cout << "\n--- Network Analysis ---" << endl;
    cout << "Average number of connections per user: " << average << endl;
    cout << "------------------------" << endl;
}

void findInfluentialUsers(const Graph& graph, const vector<string>& userNames)
{
    cout << "\n--- Influential Users (>= 3 connections) ---" << endl;
    bool found = false;
    const auto& adjList = graph.getAdjList();
    for (int i = 0; i < graph.getNumUsers(); ++i)
    {
        if (adjList[i].size() >= 3)
        {
            cout << "- " << userNames[i] << " (" << adjList[i].size() << " connections)" << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No influential users found in the network." << endl;
    }
    cout << "--------------------------------------------" << endl;
}

int main()
{
    vector<string> userNames = {
        "Dr. Ali", "Dr. Sara", "Dr. John", "Dr. Fatima",
        "Dr. David", "Dr. Muneeb", "Dr. Izhan"
    };
    int numUsers = userNames.size();

    Graph network(numUsers);

    network.addConnection(0, 1);
    network.addConnection(0, 2);
    network.addConnection(0, 3);
    network.addConnection(1, 4);
    network.addConnection(2, 3);
    network.addConnection(5, 6);

    performBFS(network, 0, userNames);
    calculateAverageConnections(network);
    findInfluentialUsers(network, userNames);
}
