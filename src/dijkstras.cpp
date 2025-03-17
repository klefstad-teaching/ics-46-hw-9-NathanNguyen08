#include "dijkstras.h"
#include <iostream>


using namespace std;

// Dijkstra Shortest Path
vector<int> dijkstra_shortest_path(const Graph &G, int source, vector<int> &previous) {
    int numVertices = G.size();
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);

    distances[source] = 0;
    previous[source] = UNDEFINED;

    priority_queue<pair<int,int>> minHeap;
    minHeap.push({source,0});

    while (!minHeap.empty()) {
        int u = minHeap.top().first;
        // cout << "test?" << endl;
        minHeap.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (Edge edge : G[u] ) {
            int v = edge.dst;
            int weight = edge.weight;

            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }

    return distances;
}

// Extracting the Shortest Path
vector<int> extract_shortest_path(const vector<int> &distances, const vector<int> &previous, int destination) {
    vector<int> path; 

    if (distances[destination] == INF) {
        return path;
    }

    for (int v = destination; v != UNDEFINED; v = previous[v]) {
        path.insert(path.begin(), v);
    }

    return path;
}

void print_path(const vector<int> &v, int total) {
    for (int node : v) {
        cout << node << " ";
    }

    cout << endl;
    cout << "Total cost is " << total << endl;
}
