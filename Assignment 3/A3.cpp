#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m, source;
	cout << "Enter the total number of vertices in the graph : ";
	cin >> n;

	cout << "Enter the total number of edges in the graph : ";
	cin >> m;

	vector<pair<int, int>> graph[n + 1];

	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cout << "Enter the vertices between whom the edge is to be formed "
				"(u,v) and the weight/cost of the edge : ";
		cin >> u >> v >> wt;
		graph[u].push_back({ v, wt });
		graph[v].push_back({ u, wt });
	}
	cout
	<< "Enter the source vertex from which the distance is to be calculated : ";
	cin >> source;

	vector<int> dist(n + 1, INT_MAX);
	dist[source] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, source });

	while (!pq.empty()) {
		int predist = pq.top().first;
		int pre = pq.top().second;
		pq.pop();
		for (auto it : graph[pre]) {
			int node = it.first;
			int currdist = it.second;
			if (dist[node] > dist[pre] + currdist) {
				dist[node] = dist[pre] + currdist;
				pq.push({ dist[node], node });
			}
		}
	}
	cout << endl;
	cout << "--------------//////-----------------" << endl;
	cout << "Distance from " << source << " are: " << endl;
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
	cout << "\n";
	return 0;
}