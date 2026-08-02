
// ========================= PRIM'S ALGORITHM =========================
// Goal:
// -----
// Find the Minimum Spanning Tree (MST) of a connected, undirected,
// weighted graph.

// A Minimum Spanning Tree is a set of V-1 edges that:
// 1. Connects all vertices.
// 2. Has no cycles.
// 3. Has minimum possible total weight.

// IDEA

// Suppose some vertices are already included in the MST.

// Now among ALL edges that:
//     - start from a visited vertex
//     - end at an unvisited vertex

// pick the edge having the minimum weight.

// Add that edge and repeat until every vertex is included.

// This is a greedy algorithm because at every step we choose the
// cheapest possible edge.

// DATA STRUCTURES

// 1. visited[]
//    visited[i] = true if vertex i is already in MST.

// 2. Min Priority Queue
//    Stores:
//        {edgeWeight, vertex}

//    The smallest weight edge is always removed first.

// 3. mstWeight
//    Stores total weight of MST.

// WORKING

// 1. Start from any vertex (usually 0).

// 2. Push
//        {0, start}
//    into the priority queue.

//    Weight is 0 because the first node is not connected by any edge.

// 3. While priority queue is not empty:

//       a) Extract the minimum weight edge.

//       b) If vertex is already visited,
//             ignore it.

//       c) Otherwise
//             include it in MST
//             add its weight to answer.

//       d) Visit all neighbours.

//          If neighbour is not visited,
//          push

//             {edgeWeight, neighbour}

//          into priority queue.

// 4. Repeat until queue becomes empty.

// TIME COMPLEXITY

// Priority Queue operations:
//         O(log V)

// Every edge may be pushed once.

// Overall:
//         O(E log V)

// Space:
//         O(V + E)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// adjacency list:
// graph[u] = { {v, weight}, {v, weight}, ... }

int primMST(vector<vector<pair<int, int>>> &graph, int V)
{
    // Min Heap
    // {weight, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Marks whether vertex is already included in MST
    vector<bool> visited(V, false);

    int mstWeight = 0;

    // Start from vertex 0
    pq.push({0, 0});

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Ignore duplicate entries
        if (visited[node])
            continue;

        // Include current node in MST
        visited[node] = true;

        // Add edge weight to answer
        mstWeight += wt;

        // Traverse all neighbours
        for (auto neighbour : graph[node])
        {
            int adjNode = neighbour.first;
            int edgeWeight = neighbour.second;

            // Only consider unvisited vertices
            if (!visited[adjNode])
                pq.push({edgeWeight, adjNode});
        }
    }

    return mstWeight;
}

int main()
{
    int V = 5;

    vector<vector<pair<int, int>>> graph(V);

    graph[0].push_back({1, 2});
    graph[0].push_back({3, 6});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 8});
    graph[1].push_back({4, 5});
    graph[2].push_back({1, 3});
    graph[2].push_back({4, 7});
    graph[3].push_back({0, 6});
    graph[3].push_back({1, 8});
    graph[4].push_back({1, 5});
    graph[4].push_back({2, 7});

    cout << "Weight of Minimum Spanning Tree: " << primMST(graph, V) << endl;

    return 0;
}