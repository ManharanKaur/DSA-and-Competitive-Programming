#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool undirectedCycleDFS(int src, int par, vector<bool> &visited);
    bool isCycleDFS();
    bool undirectedCycleBFS(int src, vector<bool> &visited);
    bool isCycleBFS();
};

bool Graph::undirectedCycleDFS(int src, int par, vector<bool> &vis)
{
    vis[src] = true;
    list<int> neighbours = l[src];

    for (int v : neighbours)
    {
        if (!vis[v])
        {
            if (undirectedCycleDFS(v, src, vis))
                return true;
        }
        else if (v != par)
            return true;
    }
    return false;
}

bool Graph::isCycleDFS()
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (undirectedCycleDFS(i, -1, visited))
                return true;
        }
    }
    return false;
}

bool Graph::undirectedCycleBFS(int src, vector<bool> &vis)
{
    queue<pair<int, int>> q;

    q.push({src, -1});
    vis[src] = true;

    while (!q.empty())
    {
        int u = q.front().first;
        int par = q.front().second;
        q.pop();

        list<int> neighbours = l[src];
        for (int v : neighbours)
        {
            if (!vis[v])
            {
                q.push({v, u});
                vis[v] = true;
            }
            else if (v != par)
                return true;
        }
    }
    return false;
}

bool Graph::isCycleBFS()
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (undirectedCycleBFS(i, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
}