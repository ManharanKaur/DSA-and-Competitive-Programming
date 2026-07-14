#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
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

    void dfs(int curr, vector<bool> &visited, stack<int> &s);
    void topological_Sort();
    void Kahns_Algorithm();
};

void Graph::dfs(int curr, vector<bool> &visited, stack<int> &s)
{
    visited[curr] = true;
    for (int v : l[curr])
        if (!visited[v])
            dfs(v, visited, s);
    s.push(curr);
}

void Graph::topological_Sort()
{
    vector<bool> visited(V, false);
    stack<int> s;
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i, visited, s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// -------------------- KAHN'S ALGORITHM --------------------

// Kahn's Algorithm is used to find the Topological Ordering of a Directed Acyclic Graph (DAG) using BFS.

// Main Idea:
// A vertex can be processed only when all of its incoming edges (dependencies) have already been processed.

// We use "indegree" to know how many dependencies each vertex still has.

// indegree[node] = Number of incoming edges to that node.

// Algorithm:
// 1. Calculate indegree of every vertex.
// 2. Push all vertices with indegree = 0 into a queue.
//    (These vertices have no dependencies.)
// 3. Repeat until queue becomes empty:
//      - Remove one vertex from the queue.
//      - Add it to the answer.
//      - Remove all its outgoing edges.
//      - For every removed edge, decrease indegree of the neighbour.
//      - If a neighbour's indegree becomes 0,
//        push it into the queue.
// 4. If every vertex is processed, the graph is a DAG.
//    Otherwise, a cycle exists.

// Time Complexity : O(V + E)
// Space Complexity: O(V)
void Graph::Kahns_Algorithm()
{
    vector<int> res;

    // 1. Calculate indegree of every vertex.
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++)
    {
        for (int v : l[u])
        {
            indegree[v]++;
        }
    }

    queue<int> q;
    // 2. Push all vertices with indegree = 0 into a queue.
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for (int v : l[curr])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    if (res.size() != V)
        cout << "Cycle detected! Topological ordering is not possible." << endl;
    else
    {
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
}

int main()
{
    Graph G(9);
    G.addEdge(0, 1);
    G.addEdge(1, 2);
    G.addEdge(2, 3);
    G.addEdge(3, 5);
    G.addEdge(3, 7);
    G.addEdge(5, 8);
    G.addEdge(7, 8);
    G.addEdge(6, 4);
    G.addEdge(4, 2);

    cout << "\nNormal Topological Sort: \n";
    G.topological_Sort();

    cout << "\nTopological sort using Kahn's Algorithm: \n";
    G.Kahns_Algorithm();
}