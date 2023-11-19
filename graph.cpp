#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Node;

struct CompareNodes {
    bool operator()(const Node& p1, const Node& p2) const {
        return p1.second > p2.second;
    }
};

vector<int> dijkstra(const vector<vector<int>>& graph, int source) {
    int n = graph.size();

    vector<int> distances(n, INT_MAX);
    distances[source] = 0;

    priority_queue<Node, vector<Node>, CompareNodes> pq;
    pq.push(make_pair(source, 0));

    while (!pq.empty()) {
        int current = pq.top().first;
        int currentDistance = pq.top().second;

        pq.pop();

        if (currentDistance > distances[current]) continue;

        for (int neighbor = 0; neighbor < n; ++neighbor) {
            if (graph[current][neighbor] != INT_MAX) {
                int newDistance = currentDistance + graph[current][neighbor];

                if (newDistance < distances[neighbor]) {
                    distances[neighbor] = newDistance;
                    pq.push(make_pair(neighbor, newDistance));
                }
            }
        }
    }

    return distances;
}

int main() {
    vector<vector<int>> graph = {
        {INT_MAX, 4, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 1, 7},
        {INT_MAX, INT_MAX, INT_MAX, 2},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX}
    };

    int source = 0;

    vector<int> distances = dijkstra(graph, source);

    cout << "Shortest distances from source " << source << ":" << endl;
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
