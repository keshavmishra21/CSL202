#include <iostream>
#include <vector>
#include <queue>
#include<unordered_map>
using namespace std;

void bfs(const vector<vector<int>>& adjList, int startVertex, unordered_map<int, bool> &visited) {
    queue<int> q;
    vector<int> bfsTree;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        bfsTree.push_back(currentVertex + 1);

        for (int neighbor : adjList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << "BFS Traversal: ";
    for (int vertex : bfsTree) {
        cout << vertex << " ";
    }
    cout << endl;
}

int main() {
    int vertices;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;

    vector<vector<int>> adjList(vertices);
    cout<<"Enter the adjacency list (enter -1 to end each list):"<<endl;
    for(int i=0; i<vertices; ++i){
        cout << "Neighbors of vertex " << (i + 1) << ": ";
        int neighbor;
        while (true) {
            cin >> neighbor;
            if (neighbor == -1) break;
            adjList[i].push_back(neighbor - 1);
        }
    }

    unordered_map<int, bool> visited;
    for(int i=0; i<vertices; i++){
        if(!visited[i]){
        bfs(adjList, i, visited);
        }
    }
    return 0;
}
