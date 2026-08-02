/*
UNION FIND / DISJOINT SET (DSU)

Purpose:
Efficiently manages a collection of disjoint (non-overlapping) sets.

Main Operations:
1. Find(x)   -> Returns the representative (ultimate parent) of x's set.
2. Union(u,v)-> Merges the sets containing u and v.

Time Complexity:

With Path Compression + Union by Rank/Size:
Nearly O(1) per operation
More precisely: O(α(N))
where α(N) is the Inverse Ackermann Function,
which grows so slowly that it is less than 5
for any practical value of N.

Applications:-
- Detect cycle in an undirected graph
- Kruskal's Minimum Spanning Tree
- Number of connected components
- Dynamic connectivity problems
- Network connectivity
- Grouping similar objects

Data Structures

parent[i]-
Stores the immediate parent of node i.

size[i]-
Stores the size of the tree rooted at i.
Used in Union by Size.

rank[i]-
Approximate height of the tree.
Used in Union by Rank instead of size.

Use either Size OR Rank.
Most implementations prefer Size because it is simpler.

Operations:
1. findUPar(node)
   - Returns the ultimate (root) parent of the node.
   - Uses Path Compression to flatten the tree.

2. unionBySize(u, v)
   - Merges two sets.
   - Smaller tree is attached under the larger tree.

Time Complexity:
- find()        : O(α(N))
- unionBySize() : O(α(N))

α(N) = Inverse Ackermann Function
(Practically constant time.)

*/
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    // Constructor
    // Creates 'n+1' nodes numbered from 0 to n.
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        // Initially every node is its own parent.
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // Finds the ultimate parent of a node.
    // Path Compression:
    // Every visited node directly points to the root.
    int findUPar(int node)
    {
        // Base case:
        // If node is its own parent, then it is the ultimate parent.
        if (node == parent[node])
            return node;

        // Recursively find the root and compress the path.
        return parent[node] = findUPar(parent[node]);
    }

    // Merges two sets using Union by Size.
    void unionBySize(int u, int v)
    {

        // Find ultimate parents.
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // Already in same set.
        if (ulp_u == ulp_v)
            return;

        // Attach smaller tree under larger tree.
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{

    // Nodes: 0 to 7
    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);

    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // Check whether 3 and 7 belong to the same set.
    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same Set\n";
    else
        cout << "Different Sets\n";

    // Merge the two sets.
    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same Set\n";
    else
        cout << "Different Sets\n";

    return 0;
}