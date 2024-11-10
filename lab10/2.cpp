#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Graph {
public:
    unordered_map<int, vector<int>> adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topologicalSortUtil(int v, unordered_map<int, bool> &visited, stack<int> &Stack) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, Stack);
            }
        }
        Stack.push(v);
    }

    void topologicalSort(){
        unordered_map<int, bool> visited;
        stack<int> Stack;

        for(auto entry : adj) {
            int v = entry.first;
            if (!visited[v]) {
                topologicalSortUtil(v, visited, Stack);
            }
        }

        cout << "Topological Sorting: ";
        while (!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
        cout << endl;
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

    cout << "Topological Order of the given DAG:"<<endl;
    g.topologicalSort();

    return 0;
}
