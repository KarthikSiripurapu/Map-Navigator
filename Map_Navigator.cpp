#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int N = 57;
vector<pair<int, int>> adj[N];

void dijkstra(int source) {
    vector<int> distance(N, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    distance[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        pair<int,int> current = pq.top();
        pq.pop();

        int dist = current.first;
        int u = current.second;

        if (dist > distance[u]) continue;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    for (int i = 1; i <= 56; i++) {
        if (i == source) continue;
        cout << "Shortest distance from Station " << source 
             << " to Station " << i << " is ";
        if (distance[i] == INT_MAX) cout << "unreachable\n";
        else cout << distance[i] << "\n";
    }
}

int main() {
    int edges[][2] = {
        {1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},
        {9,28},{28,29},{29,30},{30,31},{31,32},{32,33},{33,34},{34,35},
        {35,43},{43,42},{42,41},{41,40},{40,39},{39,38},{38,37},{37,36},
        {9,10},{10,11},{11,12},{12,13},{13,14},{14,15},{15,16},{16,17},
        {17,48},{48,49},{49,50},{50,51},{51,52},{52,53},{53,54},{54,55},{55,56},
        {17,47},{47,46},{46,45},{45,44},{44,35},
        {17,18},{18,19},{19,20},{20,21},{21,22},{22,23},{23,24},{24,25},
        {25,26},{26,27}
    };

    int numEdges = sizeof(edges)/sizeof(edges[0]);

    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(make_pair(v, 1));
        adj[v].push_back(make_pair(u, 1));
    }

    int source;
    cout << "Enter the source station (1 - 56): ";
    cin >> source;

    if (source < 1 || source > 56) {
        cout << "Invalid source station!\n";
        return 0;
    }

    dijkstra(source);

    return 0;
}