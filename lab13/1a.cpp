#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[v] < rank[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

vector<vector<int>> minimumSpanningTree(vector<vector<int>> &edges, int n) {
    sort(edges.begin(), edges.end(), cmp);
    
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    vector<vector<int>> mst;

    for (int i = 0; i < edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if (u != v) {
            mst.push_back(edges[i]);
            unionSet(u, v, parent, rank);
        }
    }
    return mst;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    cout << "Enter the edges (u, v, weight) one by one:\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<vector<int>> mst = minimumSpanningTree(edges, n);

    cout << "The edges in the Minimum Spanning Tree are:\n";
    for (auto &edge : mst) {
        cout << edge[0] << " - " << edge[1] << " with weight " << edge[2] << endl;
    }

    return 0;
}
