#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Graph{
public:
    unordered_map<int, vector<int>> adj;

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    bool isCyclicUtil(int v, unordered_map<int, int> &visited){
        visited[v] = 1;

        for (int neighbor : adj[v]){
            if (visited[neighbor] == 0){
                if (isCyclicUtil(neighbor, visited)){
                    return true;
                }
            }
            else if (visited[neighbor] == 1){
                return true;
            }
        }

        visited[v] = 2;
        return false;
    }

    bool isCyclic(){
        unordered_map<int, int> visited;

        for(auto entry : adj){
            int v = entry.first;
            if(visited[v] == 0){
                if (isCyclicUtil(v, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    int vertices;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    int u, v;
    Graph g;
    cout<<"Enter the edges for the adjacency list (1 indexed), enter -1 -1 to stop: " << endl;
    while(true){
        cin>>u>>v;
        if(u == -1 && v == -1){
            break;
        }
        g.addEdge(u, v);
    }

    if(g.isCyclic()){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }

    return 0;
}
