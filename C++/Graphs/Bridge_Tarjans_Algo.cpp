// Tarjan's Algorithm is used to find all bridges (critical connections) in an undirected graph.

// A bridge is an EDGE whose removal increases the number of connected components.
// In other words, removing that edge disconnects some part of the graph.

// Concept:
// We perform DFS and maintain two values for every node:

// 1. tin[node] (time of insertion):
//    - The time when the node is visited for the first time in DFS.
//    - Represents the discovery order of nodes.

// 2. low[node]:
//    - The smallest discovery time reachable from this node.
//    - It tells whether this node/subtree can reach any ancestor using a back edge.

// During DFS:

// Case 1: Neighbor is already visited
// It means we found a back edge.
// Update low value using the neighbor's discovery time.

// low[node] = min(low[node], tin[neighbor])

// Case 2: Neighbor is not visited
// First visit the neighbor using DFS.

// After returning from DFS:
// Update current node's low value using child's low value.
//
// low[node] = min(low[node], low[child])

// Bridge Condition:
// For an edge (node -> child):

// If:
//      low[child] > tin[node]

// Then:
//      child cannot reach any ancestor of node.

// Therefore, the only connection between node and child subtree
// is this edge, making it a bridge.

// Important:
// The parent edge is ignored during DFS because it is the edge
// through which we reached the current node.

// Time Complexity:
// O(V + E)
// - Every node is visited once.
// - Every edge is processed once.

// Space Complexity:
// O(V + E)
// - Adjacency list storage.
// - DFS recursion stack.
// - tin and low arrays.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> tin, low, vis;
vector<pair<int, int>> bridges;
int timer = 0;

void dfs(int node, int parent)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for (int neighbour : adj[node])
    {
        if (neighbour == parent)
            continue;

        if (vis[neighbour])
        {
            low[node] = min(low[node], tin[neighbour]);
        }
        else
        {
            dfs(neighbour, node);

            low[node] = min(low[node], low[neighbour]);

            if (low[neighbour] > tin[node])
            {
                bridges.push_back({node, neighbour});
            }
        }
    }
}

int main()
{
    int V = 5;

    adj.resize(V);

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(0);
    adj[0].push_back(2);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    tin.assign(V, -1);
    low.assign(V, -1);
    vis.assign(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, -1);
    }

    cout << "Bridges:\n";
    for (auto &bridge : bridges)
    {
        cout << bridge.first << " - " << bridge.second << '\n';
    }

    return 0;
}