#include <bits/stdc++.h>
#define N 1e5;
using namespace std;

class Graph {
	private:
	int vertices;
	int edges;
	vector<vector<int>> graph;

	public:
	Graph() {
		this->vertices = 0;
		this->edges = 0;
		graph.clear();
	}
	void createGraph() {
		cout << "Enter number of vertices: ";
		cin >> vertices;
		graph.resize(vertices + 1);
		cout << "Enter number of edges: ";
		cin >> edges;
		int u, v;
		for (int i = 0; i < edges; i++) {
			cout << "Enter sourceNode & destinationNode: ";
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}
	}
	void displayGraph() {
		for (int node = 0; node < vertices; node++) {
			cout << node << "->";
			for (int adjNode : graph[node]) {
				cout << adjNode << " ";
			}
			cout << endl;
		}
	}
	void dfs(int node, vector<int>& vis) {
		vis[node] = 1;
		cout << node << " ";
		for (auto it : graph[node]) {
			if (!vis[it]) {
				dfs(it, vis);
			}
		}
	}
	void DFS() {
		vector<int> visited(vertices + 1);
		int startNode;
		cout << "Enter the Starting Vertex of DFS: ";
		cin >> startNode;
		dfs(startNode, visited);

		for (int node = 0; node < vertices;
			 node++) // For Handling Disconnected Components
		{
			if (!visited[node]) {
				dfs(node, visited);
			}
		}
	}
	void bfs(int startNode, vector<int>& vis) {
		queue<int> q;
		q.push(startNode);

		vis[startNode] = 1;

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cout << node << " ";
			for (auto it : graph[node]) {
				if (!vis[it]) {
					vis[it] = 1;
					q.push(it);
				}
			}
		}
	}
	void BFS() {
		vector<int> visited(vertices + 1);
		int startNode;
		cout << "Enter the Starting Vertex of DFS: ";
		cin >> startNode;
		bfs(startNode, visited);

		for (int node = 0; node < vertices;
			 node++) // For Handling Disconnected Components
		{
			if (!visited[node]) {
				bfs(node, visited);
			}
		}
	}
};

int main() {
	Graph obj;
	int opt;
	while (true) {
		cout << " -------------------- MENU -------------------- " << endl;
		cout << " 1. Create a Graph " << endl;
		cout << " 2. Display a Graph " << endl;
		cout << " 3. Depth First Search (DFS) Algorithm " << endl;
		cout << " 4. Breadth First Search (BFS) Algorithm " << endl;
		cout << " 5. Exit " << endl;
		cout << " Enter the option: ";
		cin >> opt;
		switch (opt) {
		case 1: obj.createGraph(); break;
		case 2: obj.displayGraph(); break;
		case 3: obj.DFS(); break;
		case 4: obj.BFS(); break;
		case 5: exit(0);
		}
		cout << endl;
	}
	return 0;
}