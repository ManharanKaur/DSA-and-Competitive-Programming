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
    }

    bool isCycle(int curr, vector<bool> &vis, vector<bool> &recPath);
};

bool Graph::isCycle(int curr, vector<bool> &vis, vector<bool> &recPath)
{
    vis[curr] = true;
    recPath[curr] = true;

    for (int v : l[curr])
    {
        if (!vis[v])
        {
            if (isCycle(v, vis, recPath))
                return true;
        }
        else if (recPath[v])
            return true;
    }
    recPath[curr] = false;
    return false;
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
}