//
// Created by Naveed on 11/12/2025.
//

/*Exercise 2: Transportation network of cities
Construct a program that models a simple transportation network of cities connected by roads. Each city is represented as a node
(vertex), and each road connecting two cities is represented as an edge. Your Program have the following functionalities.
•	represent this network using an adjacency list,
•	perform BFS to explore the connectivity.
Graph Construction
Create a graph with following cities City1,city2,city3,city4,city5,city6

Add roads between the cities
City1 is connected with city2
City2 is connected with city5 and city6 City3 is connected with city4
City4 is connected with city5
City6 is connected with city1 and city5
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Graph
{
private:
    int numCities;
    vector<vector<int>> adjList;

public:
    Graph(int n)
    {
        numCities = n;
        adjList.resize(n);
    }

    void addRoad(int u, int v)
    {
        if (u >= 0 && u < numCities && v >= 0 && v < numCities)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printGraph()
    {
        cout << "--- Transportation Network Structure ---" << endl;
        for (int i = 0; i < numCities; i++)
        {
            cout << "City" << (i + 1) << " --> ";
            for (int neighbor : adjList[i])
            {
                cout << "City" << (neighbor + 1) << " ";
            }
            cout << endl;
        }
        cout << "--------------------------------------" << endl;
    }

    void performBFS(int startNode)
    {
        if (startNode < 0 || startNode >= numCities)
        {
            cout << "Invalid start city." << endl;
            return;
        }

        cout << "\n--- BFS Traversal starting from City" << (startNode + 1) << " ---" << endl;

        vector<bool> visited(numCities, false);
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        cout << "Connectivity: ";
        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            cout << "City" << (current + 1) << " ";

            for (int neighbor : adjList[current])
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
};

int main()
{
    Graph cityNetwork(6);

    cityNetwork.addRoad(0, 1);
    cityNetwork.addRoad(1, 4);
    cityNetwork.addRoad(1, 5);
    cityNetwork.addRoad(2, 3);
    cityNetwork.addRoad(3, 4);
    cityNetwork.addRoad(5, 0);
    cityNetwork.addRoad(5, 4);

    cityNetwork.printGraph();
    cityNetwork.performBFS(0);
}
