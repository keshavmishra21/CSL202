#include <iostream>
#include <vector>
using namespace std;

class Graph{
    public: 
    int V;
    vector<vector<int>> adjList;
    vector<int> discovery;
    vector<int> h;
    vector<int> finish;
    vector<int> parent;
    vector<bool> visited;
    int time;

    Graph(int V) : V(V), adjList(V), discovery(V, -1), h(V, -1), finish(V, -1), parent(V, -1), visited(V, false), time(0) {}
    
    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(){
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs_visit(i);
            }
        }
    }

    private:
    void dfs_visit(int i){
        time=time+1;
        discovery[i]=time;
        h[i]=time;
        visited[i]=true;
        for(auto v: adjList[i]){
            if(!visited[v]){
                parent[v]=i;
                dfs_visit(v);

                h[i] = min(h[i], h[v]);
                
                if(h[v]>discovery[i]){
                    cout<<"Cut Edge: "<<i<<" "<<v<<endl;
                }
            }
            else if(v!=parent[i]){
                h[i] = min(h[i], discovery[v]);
            }
        }
        time=time+1;
        finish[i]=time;
    }
};

int main(){
    int v;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    int e;
    cout<<"Enter the number of edges: ";
    cin>>e;
    Graph g(v);
    int u, x;
    cout<<"Enter the edges:"<<endl;
    for(int i=0; i<e; i++){
        cin>>u>>x;
        g.addEdge(u, x);
    }
    g.dfs();
    return 0;
}