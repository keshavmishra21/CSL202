#include<iostream>
#include<vector>
#include<stack>
#include<climits>

using namespace std;

class Edge{
private:
    int to;
    int weight;

public:
    Edge(int destination, int weight) : to(destination), weight(weight) {}

    int getTo() const { return to; }
    int getWeight() const { return weight; }
};

using Graph = vector<vector<Edge>>;

void topologicalSort(int v, const Graph& graph, vector<bool>& visited, stack<int>& topoStack) {
    visited[v] = true;

    for (const Edge& edge : graph[v]) {
        if (!visited[edge.getTo()]) {
            topologicalSort(edge.getTo(), graph, visited, topoStack);
        }
    }

    topoStack.push(v);
}

vector<int> shortestPathDAG(const Graph& graph, int source){
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    stack<int> topoStack;

    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            topologicalSort(i, graph, visited, topoStack);
        }
    }

    dist[source] = 0;

    while(!topoStack.empty()){
        int u = topoStack.top();
        topoStack.pop();

        if(dist[u] != INT_MAX){
            for(const Edge& edge : graph[u]){
                int newDist = dist[u] + edge.getWeight();
                if(newDist < dist[edge.getTo()]){
                    dist[edge.getTo()] = newDist;
                }
            }
        }
    }

    return dist;
}

void addEdge(Graph& graph, int from, int to, int weight){
    graph[from].emplace_back(to, weight);
}

int main(){
    int n, m;
    cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; ++i){
        int from, to, weight;
        cin >> from >> to >> weight;
        addEdge(graph, from, to, weight);
    }

    int source;
    cin >> source;

    vector<int> distances = shortestPathDAG(graph, source);

    for (int i = 0; i < n; ++i){
        if (distances[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable" << endl;
        else
            cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
