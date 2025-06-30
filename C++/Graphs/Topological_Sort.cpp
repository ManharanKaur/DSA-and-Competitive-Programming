#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Graph
{
private:
    int V; // Number of vertices
    vector<vector<int> > adj; // Adjacency list
    bool isDirected;

    void topological_Sort_Util(int v, vector<bool> & visited, stack<int> &s){
        // Mark the current node as visited
        visited[v] = true;

        for(int i : adj[v])
            if(!visited[i])
                topological_Sort_Util(i, visited, s);

        // Push current vertex to stack which stores Topological Sort
        s.push(v);
    }

public:
    Graph(int V, bool direct = false){
        this->V = V;
        adj.resize(V);
        isDirected = direct;
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        if(!isDirected) adj[v].push_back(u);
    }

    void topological_Sort(){
        stack <int> S; // Stack to store topo sort order
        vector<bool> visited(V, false); // Mark all vertices as not visited

        // call helper function for each unvisited vertex
        for(int i = 0; i < V; i++)
            if(!visited[i])
                topological_Sort_Util(i, visited, S);
            
        while(!S.empty()){
            cout << S.top() << " ";
            S.pop();
        }
        cout << endl;
    }

    void Kahns_Algorithm(){
        vector<int> indegree(V, 0); // Initialize indegree of all vertices as 0

        // Calculate indegree of all vertices
        for(int u = 0; u < V; u++)
            for(int v : adj[u])
                indegree[v]++;
        
        // Create a queue and enqueue all vertices with indegree 0
        queue<int> Q;
        for(int i = 0; i < V; i++)
            if(indegree[i] == 0)
                Q.push(i);

        vector<int> topo_order;
        int count = 0;

        // Process vertices in topological order
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            topo_order.push_back(u);

            // Decrease indegree of all adjacent vertices by 1 and push to queue if indegree becomes 0
            for (int v : adj[u])
                if(--indegree[v] == 0)
                    Q.push(v);
            count++;
        }

        // Check if there was a cycle
        if (count != V) {
            cout << "There exists a cycle in the graph, topological sorting is not possible.\n";
        } else {
            // Print topological order
            for (int i : topo_order) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

};


int main(){
    Graph G(9,true);
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