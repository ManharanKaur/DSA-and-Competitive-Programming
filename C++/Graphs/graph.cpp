#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


class Graph{
    int V; // Number of vertices
    vector<vector<int> > adj; // adjacency list
    bool isDirected;

    // helper function for DFS
    void DFSUtil(int v, vector<bool> &visited){
        visited[v] = true;
        cout << v << " ";

        for(int node : adj[v])
            if(!visited[node])
                DFSUtil(node, visited);
        
    }

public:
    Graph(int V, bool direct = false){
        this->V = V; // Number of vertices
        adj.resize(V); // Initialize adjacency list
        isDirected = direct;
    }

    // Function to add edge to graph
    void addEdge(int u, int v){
        adj[u].push_back(v); // Add v to u's adjacency list
        if(!isDirected) // If graph is undirected 
            adj[v].push_back(u); // Add u to v's adjacency list
    }

    // BFS for disconnected graph
    void BFS_Disconnected(){
        vector<bool> visited(V, false); // keep track of visited nodes
        queue<int> q; 
        for (int i = 0; i < V; i++){
            if (!visited[i]){ // only if node is not visited, start BFS
                q.push(i);
                visited[i] = true;

                cout << "BFDS from component " << i << ": ";
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    cout << node << " ";

                    // visit all adjacent vertices of node
                    for(int v: adj[node]){
                        if (!visited[v]){
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
                cout << endl;
            }
        }
    }

    // BFS from a given source
    void BFS(int start){
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS from node " << start << ": ";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout << node << " ";
            for(int v: adj[node]){
                if (!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    // DFS iterative
    void DFS_Iterative(int start, vector<bool> &visited){
        stack<int> s;
        s.push(start);
        while(!s.empty()){
            int node = s.top();
            s.pop();

            // if the node is not visited, proceed
            if (!visited[node]){
                visited[node] = true;
                cout << node << " ";

                // Push all adjacent vertices of node to the stack
                // reverse adj list to maintain original DFS order
                for(auto it = adj[node].rbegin(); it != adj[node].rend(); ++it){
                    int v = *it; 
                    if (!visited[v]){
                        s.push(v);
                    }
                }
            }
        }
        cout << endl;
    }

    // DFS for Disconnected graph to traverse all nodes
    void DFS_Disconnected(){
        vector <bool> visited(V, false);

        for (int i = 0; i < V; i++){
            if (!visited[i]){
                cout << "DFS from node " << i << ": ";
                DFSUtil(i,visited);
                cout << endl;
            }
        }
    }

    // DFS from a single node
    void DFS(int start){
        vector <bool> visited(V, false);
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main(){
    Graph g(6,true); 
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "BFS on whole graph: \n";
    g.BFS_Disconnected();

    cout << "\nBFS from node 5: \n";
    g.BFS(5);
    
    cout << "\nDFS on whole graph: \n";
    g.DFS_Disconnected();

    cout << "\nDFS from node 5: \n";
    g.DFS(5);

    
}