// -------------------- DIJKSTRA'S ALGORITHM --------------------

// Dijkstra's Algorithm finds the shortest distance from a single source vertex to every other vertex in a graph.

// Works only for graphs with NON-NEGATIVE edge weights.

// Main Idea:
// Always process the vertex that currently has the minimum known distance from the source.

// Once a vertex is processed with the smallest distance, its shortest distance is finalized.

// We use:
// 1. distance[] -> Stores shortest distance from source.
// 2. Priority Queue (Min Heap) -> Always gives the vertex with the minimum current distance.

// Algorithm:
// 1. Initialize distance of every vertex as INF.
// 2. Set distance[source] = 0.
// 3. Push (0, source) into the priority queue.
// 4. While the priority queue is not empty:
//      - Remove the vertex having the smallest distance.
//      - Traverse all of its neighbours.
//      - If a shorter path is found, update the neighbour's distance.
//      - Push the updated distance into the priority queue.
// 5. After the queue becomes empty, distance[] contains the shortest distance to every vertex.

// Time Complexity : O((V + E) log V)
// Space Complexity: O(V)
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Edge
{
public:
    int v;
    int wt;

    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

void dijkstra(int src, vector<vector<Edge>> &g, int V)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (Edge edge : g[u])
        {
            int v = edge.v;
            int wt = edge.wt;

            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}
int main()
{
    int V = 6;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));

    g[3].push_back(Edge(5, 1));

    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));
    dijkstra(0, g, V);
}