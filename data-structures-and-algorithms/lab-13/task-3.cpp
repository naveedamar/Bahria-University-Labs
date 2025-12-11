//
// Created by Naveed on 11/12/2025.
//

/*Exercise 3: CodeConnect: Mutual Friends
We are building a social networking platform for a community of developers called CodeConnect. Each developer on the platform is represented
as a node in a graph, and friendships between developers are represented as edges connecting the nodes.
Your task is to design a C++ code to find mutual friends between two developers.
Let's say you have developers Ashir, Hammad, Sarim, Muneeb, and Izhan in the network. Here's how their friendships are represented:

> Ashir is friends with Hammad and Sarim.
> Hammad is friends with Ashir, Sarim, and Muneeb. Sarim is friends with Ashir, Hammad, Muneeb, and Izhan Muneeb is friends with Hammad, Sarim, and Izhan.
> Izhan is friends with Sarim and Muneeb.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Graph
{
private:
    int numDevelopers;
    vector<vector<int>> adjList;

public:
    Graph(int n)
    {
        numDevelopers = n;
        adjList.resize(n);
    }

    void addFriendship(int u, int v)
    {
        if (u >= 0 && u < numDevelopers && v >= 0 && v < numDevelopers)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    const vector<vector<int>>& getAdjList() const
    {
        return adjList;
    }
};

void findMutualFriends(int dev1, int dev2, const Graph& graph, const vector<string>& devNames)
{
    cout << "Finding mutual friends between " << devNames[dev1] << " and " << devNames[dev2] << ":" << endl;

    const auto& adjList = graph.getAdjList();
    const vector<int>& friends1 = adjList[dev1];
    const vector<int>& friends2 = adjList[dev2];

    vector<int> mutuals;

    for (int friend1 : friends1)
    {
        for (int friend2 : friends2)
        {
            if (friend1 == friend2)
            {
                mutuals.push_back(friend1);
                break;
            }
        }
    }

    if (mutuals.empty())
    {
        cout << "No mutual friends found." << endl;
    }
    else
    {
        cout << "Mutual Friends: ";
        for (size_t i = 0; i < mutuals.size(); ++i)
        {
            cout << devNames[mutuals[i]] << (i == mutuals.size() - 1 ? "" : ", ");
        }
        cout << endl;
    }
}

int main()
{
    vector<string> developers = {
        "Ashir", "Hammad", "Sarim", "Muneeb", "Izhan"
    };
    int numDevs = developers.size();
    Graph codeConnect(numDevs);

    codeConnect.addFriendship(0, 1);
    codeConnect.addFriendship(0, 2);
    codeConnect.addFriendship(1, 2);
    codeConnect.addFriendship(1, 3);
    codeConnect.addFriendship(2, 3);
    codeConnect.addFriendship(2, 4);
    codeConnect.addFriendship(3, 4);

    findMutualFriends(0, 3, codeConnect, developers);
    cout << endl;
    findMutualFriends(0, 4, codeConnect, developers);
}
