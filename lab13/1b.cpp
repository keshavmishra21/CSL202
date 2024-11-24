#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <climits>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n - 1; i++) {
        int mini = INT_MAX;
        int u = -1;

        for (int v = 0; v < n; v++) {
            if (!mst[v] && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (!mst[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 1; i < n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> edges(m);
    cout << "Enter the edges (u, v, weight) one by one:\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
    }

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);

    cout << "The edges in the Minimum Spanning Tree are:\n";
    for (auto &edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " with weight " << edge.second << endl;
    }

    return 0;
}
