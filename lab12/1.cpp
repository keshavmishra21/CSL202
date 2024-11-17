#include<iostream>
#include<vector>
#include<queue>
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

vector<int> dijkstra(const Graph& graph, int start){
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        pair<int, int> current = pq.top();
        pq.pop();

        int currentDist = current.first;
        int currentNode = current.second;

        if(currentDist > dist[currentNode]) continue;

        for(const Edge& edge : graph[currentNode]){
            int newDist = currentDist + edge.getWeight();
            if (newDist < dist[edge.getTo()]) {
                dist[edge.getTo()] = newDist;
                pq.push(make_pair(newDist, edge.getTo()));
            }
        }
    }

    return dist;
}

void addEdge(Graph& graph, int from, int to, int weight){
    graph[from].push_back(Edge(to, weight));
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

    int start;
    cin >> start;

    vector<int> distances = dijkstra(graph, start);

    for(int i = 0; i < n; ++i){
        if (distances[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable" << endl;
        else
            cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
