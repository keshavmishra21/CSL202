#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transposeAdjList(const vector<vector<int>>& adjList) {
    int vertices = adjList.size();
    vector<vector<int>> transposedList(vertices);

    for (int u = 0; u < vertices; ++u) {
        for (int v : adjList[u]) {
            transposedList[v].push_back(u);
        }
    }

    return transposedList;
}

void printAdjList(const vector<vector<int>>& adjList) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); ++i) {
        cout << i + 1 << ": ";
        for (int j : adjList[i]) {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> transposeAdjMatrix(const vector<vector<int>>& adjMatrix) {
    int vertices = adjMatrix.size();
    vector<vector<int>> transposedMatrix(vertices, vector<int>(vertices, 0));

    for (int u = 0; u < vertices; ++u) {
        for (int v = 0; v < vertices; ++v) {
            if (adjMatrix[u][v] == 1) {
                transposedMatrix[v][u] = 1;
            }
        }
    }

    return transposedMatrix;
}

void printAdjMatrix(const vector<vector<int>>& adjMatrix) {
    cout << "Adjacency Matrix:" << endl;
    for (const auto& row : adjMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    vector<vector<int>> adjList(vertices);
    cout << "Enter the adjacency list (enter -1 to end each list):" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << "Neighbors of vertex " << (i + 1) << ": ";
        int neighbor;
        while (true) {
            cin >> neighbor;
            if (neighbor == -1) break;
            adjList[i].push_back(neighbor - 1);
        }
    }

    vector<vector<int>> transposedList = transposeAdjList(adjList);
    cout << "Transposed Graph (Adjacency List):" << endl;
    printAdjList(transposedList);

    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));
    cout << "Enter the adjacency matrix (0 or 1):" << endl;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cin >> adjMatrix[i][j];
        }
    }

    vector<vector<int>> transposedMatrix = transposeAdjMatrix(adjMatrix);
    cout << "Transposed Graph (Adjacency Matrix):" << endl;
    printAdjMatrix(transposedMatrix);

    return 0;
}
