#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class Graph{
public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void DFS(int v, unordered_map<int, bool> &visited, vector<int> &parent, vector<pair<int, int>> &edges){
        visited[v] = true;

        for (int neighbor : adj[v]) {
            edges.push_back({v, neighbor});
            if (!visited[neighbor]) {
                parent[neighbor]=v;
                cout<<v<<" "<<neighbor<<" Tree Edge"<<endl;
                DFS(neighbor, visited, parent, edges);
            }
            else if(parent[v] == neighbor){
                    cout<<v<<" "<<neighbor<<" Back Edge"<< endl;
                }
               else if (visited[neighbor] && parent[v] != neighbor) {
                
                if (find(adj[neighbor].begin(), adj[neighbor].end(), v) != adj[neighbor].end()) {
                    cout << v << " " << neighbor << " Forward Edge" << endl;
                } else {
                    cout << v << " " << neighbor << " Cross Edge" << endl;
                }
            }
            
        }
    }

    void DFSUtil(){
        unordered_map<int,bool> visited;
        vector<int> parent(adj.size() + 1, -1);
        vector<pair<int, int>> edges;
        for (auto entry : adj){
            int v=entry.first;
            if (!visited[v]){
                DFS(v, visited, parent, edges);
            }
        }
        cout<<"Tree Forest Edges:"<<endl;
        for(auto edge : edges){
            cout<<edge.first<<"-"<<edge.second<<endl;
        }
    }
};

int main(){
    int u, v;
    Graph g;
    cout<<"Enter the edges for the adjacency list(1 indexed), enter -1 -1 to stop: "<<endl;
    while(true){
        cin>>u>>v;
        if(u == -1 && v == -1){
            break;
        }
        g.addEdge(u, v);
    }
    vector<pair<int,int>> treeEdges;
    g.DFSUtil();
    
}