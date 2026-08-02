// -------------------- BELLMAN-FORD ALGORITHM --------------------

// Bellman-Ford Algorithm finds the shortest distance from a single source vertex to every other vertex.

// Unlike Dijkstra's Algorithm, Bellman-Ford works even if the graph contains NEGATIVE edge weights.

// It can also detect whether a NEGATIVE WEIGHT CYCLE exists.

// Main Idea:
// Repeatedly relax every edge.
// Every relaxation tries to improve the shortest distance of the destination vertex.

// Why V-1 iterations?
// In the worst case, the shortest path between two vertices can contain at most (V-1) edges.
// Therefore, relaxing all edges (V-1) times guarantees that all shortest distances are found.

// After V-1 iterations, perform one more relaxation.
// If any distance still decreases, then a negative weight cycle exists.

// Algorithm:
// 1. Initialize distance of every vertex as INF.
// 2. Set distance[source] = 0.
// 3. Repeat (V-1) times:
//      - Traverse every edge (u -> v).
//      - If distance[u] + weight < distance[v], update distance[v].
// 4. Traverse every edge one more time.
//      - If any distance still decreases, report a negative weight cycle.
// 5. Otherwise, distance[] stores the shortest distances.

// Time Complexity : O(V * E)
// Space Complexity: O(V)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Edge
{
public:
    int v, wt;

    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

bool hasNegativeCycle(vector<vector<Edge>> &g, vector<int> &dist, int V)
{
    for (int u = 0; u < V; u++)
    {
        if (dist[u] == INT_MAX)
            continue;

        for (Edge e : g[u])
        {
            if (dist[e.v] > dist[u] + e.wt)
                return true;
        }
    }
    return false;
}

void bellmanFord(int src, vector<vector<Edge>> &g, int V)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (Edge e : g[u])
            {
                if (dist[e.v] > dist[u] + e.wt)
                    dist[e.v] = dist[u] + e.wt;
            }
        }
    }
    if (hasNegativeCycle(g, dist, V))
    {
        cout << "Negative Weight Cycle Exists\n";
        return;
    }
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    int V = 5;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));
    g[1].push_back(Edge(2, -4));
    g[2].push_back(Edge(3, 2));
    g[3].push_back(Edge(4, 4));
    g[4].push_back(Edge(1, -1));

    bellmanFord(0, g, V);

    return 0;
}