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

    // for undirected graph
    bool isCyclicUtil(int v, vector<bool> &visited, int parent){ 
        visited[v] = true;

        // check for adjacent vertices
        for(int u : adj[v]){
            if(!visited[u]){
                if(isCyclicUtil(u, visited, v))
                    return true;
            }
            // If the neighbor is visited and is not the parent, there is a cycle
            else if (u != parent)
                return true;
        }
        return false;
    }

    // for directed graph
    bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack){
        visited[v] = true;
        recStack[v] = true;

        // check for adjacent vertices
        for(int u : adj[v]){
            // If the adjacent vertex is not visited, recursively call DFS
            // or
            // If the adjacent vertex is in the recursion stack, there is a cycle
            if((!visited[u] && isCyclicUtil(u, visited, recStack)) || recStack[u])
                return true;
        }

        // If no cycle is found, remove the vertex from the recursion stack
        recStack[v] = false;
        return false;
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

    bool hasCycleUndirected(){
        vector<bool> visited(V, false);

        // check for cycle in each component of graph
        for (int i = 0; i < V; i++)
            if (!visited[i])
                if (isCyclicUtil(i, visited, -1))
                    return true;
        
        return false;
    }

    bool hasCycleDirected(){
        vector<bool> visited(V, false); // Mark all vertices as not visited
        vector<bool> recStack(V, false); // Recursion stack

        // Call the recursive helper function to detect cycle
        for (int i = 0; i < V; i++) {
            if (!visited[i] && isCyclicUtil(i, visited, recStack)) { 
                return true; 
            }
        }
        return false; 
    }

    bool has_cycle(){
        return isDirected ? hasCycleDirected() : hasCycleUndirected();
    }
};





int main(){
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

    cout << "\nUndirected Graph: " << (G.has_cycle() ? "true" : "false") << endl;

    Graph H(9,true);
    H.addEdge(0, 1);
    H.addEdge(1, 2);
    H.addEdge(2, 3);
    H.addEdge(3, 5);
    H.addEdge(3, 7);
    H.addEdge(5, 8);
    H.addEdge(7, 8);
    H.addEdge(6, 4);
    H.addEdge(4, 2);

    cout << "\nDirected Graph: " << (H.has_cycle() ? "true" : "false") << endl;

}