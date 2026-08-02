#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
KRUSKAL'S ALGORITHM (Minimum Spanning Tree - MST)
Main Idea
Suppose we have a connected, weighted, undirected graph.

Our goal is to connect all vertices with:
1. Minimum possible total edge weight.
2. No cycles.
3. Exactly (V - 1) edges.

Instead of growing the tree from a vertex (like Prim's),
Kruskal grows the tree by selecting EDGES.

Observation :-

To obtain the minimum total weight:
Always choose the smallest available edge first.
But...
If adding an edge creates a cycle, skip that edge.

Otherwise,
include it in the MST.

How do we detect a cycle efficiently?

Use Disjoint Set Union (Union-Find).

Initially:
Every vertex belongs to its own set.
For every edge (u, v):
Step 1:
    Find the ultimate parent of u.
Step 2:
    Find the ultimate parent of v.
Case 1:
    Parents are different
Meaning:
    u and v belong to different components.
Adding this edge cannot form a cycle.
=> Include edge in MST.
=> Merge both components.
Case 2:
    Parents are same
Meaning:
u and v are already connected.
Adding this edge would create a cycle.
=> Ignore the edge.

Algorithm

1. Store every edge as:
   {weight, u, v}
2. Sort all edges in increasing order of weight.
3. Initialize DSU.
4. Traverse every edge in sorted order.
5. If endpoints belong to different sets:
      - Add edge weight to answer.
      - Union both sets.
6. Ignore edges whose endpoints already belong to the same set.
7. When all edges are processed,
   answer = weight of Minimum Spanning Tree.
Time Complexity
Sorting edges:
O(E log E)
DSU operations:
O(E × α(V))
Overall:
O(E log E)
Since sorting dominates.
Space Complexity
DSU:
O(V)
Edges:
O(E)
Total:
O(V + E)
*/
// Disjoint Set (Union-Find)

class DSU
{
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {

        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

// Kruskal's Algorithm

int kruskalMST(int V, vector<vector<int>> &edges)
{
    sort(edges.begin(), edges.end());
    DSU ds(V);
    int mstWeight = 0;

    for (auto &edge : edges)
    {

        int wt = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (ds.findUPar(u) != ds.findUPar(v))
        {
            mstWeight += wt;
            ds.unionBySize(u, v);
        }
    }

    return mstWeight;
}

int main()
{

    int V = 4;
    // {wt, u, v}
    vector<vector<int>> edges = {
        {10, 0, 1},
        {6, 0, 3},
        {5, 0, 2},
        {15, 1, 3},
        {4, 2, 3}};

    cout << "Weight of MST = " << kruskalMST(V, edges);

    return 0;
}