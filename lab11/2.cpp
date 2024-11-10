#include <iostream>
#include <vector>

using namespace std;

class Graph{
public:
    int V;
    vector<vector<int>> adj;
    vector<int> discovery;
    vector<int> h;
    vector<int> finish;
    vector<int> parent;
    vector<bool> visited;
    vector<bool> isArticulationPoint;
    int time;

    Graph(int V) : V(V), adj(V), discovery(V, -1), h(V, -1), finish(V, -1), parent(V, -1), visited(V, false), isArticulationPoint(V, false), time(0) {}

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findArticulationPoints() {
        for(int i=0; i<V; i++){
            if(!visited[i]){
                DFS(i);
            }
        }
        
        bool found=false;
        for(int i=0; i<V; i++){
            if(isArticulationPoint[i]){
                cout<<"Cut vertex: "<<i<<endl;
                found=true;
            }
        }
        
        if(!found){
            cout<<"none"<<endl;
        }
    }

private:
    void DFS(int u){
        visited[u]=true;
        discovery[u]= h[u] = ++time;
        int children = 0;

        for (int v : adj[u]){
            if(!visited[v]){
                parent[v]=u;
                children++;
                DFS(v);

                h[u]=min(h[u], h[v]);

                if(parent[u]==-1 && children > 1) {
                    isArticulationPoint[u]=true;
                }

                if(parent[u] != -1 && h[v] >= discovery[u]) {
                    isArticulationPoint[u]=true;
                }
            } else if(v != parent[u]){
                h[u]=min(h[u], discovery[v]);
            }
        }
    }
};

int main() {
    int V, E;
    cout<<"Enter the number of vertices: ";
    cin>>V;
    Graph g(V);

    cout<<"Enter the number of edges: ";
    cin>>E;

    cout<<"Enter the edges (u v):"<<endl;
    for(int i=0; i < E; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v);
    }

    g.findArticulationPoints();

    return 0;
}
