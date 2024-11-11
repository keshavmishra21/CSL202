#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createAdjList(vector<vector<int>> &edges, int vertices) {
    vector<vector<int>> adjList(vertices);
    
    for(auto edge : edges){
        int u = edge[0] - 1;
        int v = edge[1] - 1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    return adjList;
}

void printAdjList(vector<vector<int>> &adjList) {
    cout << "Adjacency List:" << endl;
    for(int i = 0; i < adjList.size(); i++){
        cout << i + 1 << ": ";
        for (int j : adjList[i]) {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> createAdjMatrix(vector<vector<int>> &edges, int vertices){
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));
    
    for (auto edge : edges) {
        int u = edge[0] - 1;
        int v = edge[1] - 1;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    return adjMatrix;
}

void printAdjMatrix(vector<vector<int>> &adjMatrix) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < adjMatrix.size(); i++) {
        for (int j = 0; j < adjMatrix[i].size(); j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices, edgesCount;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    
    cout << "Enter number of edges: ";
    cin >> edgesCount;

    vector<vector<int>> edges(edgesCount, vector<int>(2));

    cout << "Enter the edges (u v):" << endl;
    for(int i=0; i<edgesCount; i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> adjList = createAdjList(edges, vertices);
    printAdjList(adjList);

    vector<vector<int>> adjMatrix = createAdjMatrix(edges, vertices);
    printAdjMatrix(adjMatrix);

    return 0;
}
