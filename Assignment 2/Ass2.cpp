#include <bits/stdc++.h>
using namespace std;

int ans = 0;

int heuristicFunction(vector<vector<int>>& initialState, vector<vector<int>>& finalState) {
	int cost = 0;
	vector<pair<int, int>> ini(9);
	vector<pair<int, int>> fin(9);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ini[initialState[i][j]] = { i, j };
			fin[finalState[i][j]] = { i, j };
		}
	}
	for (int i = 0; i < 9; i++) {
		cost += abs(ini[i].first - fin[i].first);
		cost += abs(ini[i].second - fin[i].second);
	}
	return cost;
}

void solve(int cost, vector<vector<int>>& initialState, vector<vector<int>>& finalState) {
	cout << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << initialState[i][j] << " ";
		}
		cout << endl;
	}
	if (initialState == finalState) {
		ans = cost;
		return;
	}
	int x, y;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (initialState[i][j] == 0) {
				x = i;
				y = j;
			}
		}
	}
	vector<array<int, 3>> v;
	if ((x + 1) < 3) {
		swap(initialState[x + 1][y], initialState[x][y]);
		int c = heuristicFunction(initialState, finalState);
		swap(initialState[x + 1][y], initialState[x][y]);
		array<int, 3> sa = { c, x + 1, y };
		v.push_back(sa);
	}
	if ((x - 1) >= 0) {
		swap(initialState[x - 1][y], initialState[x][y]);
		int c = heuristicFunction(initialState, finalState);
		swap(initialState[x - 1][y], initialState[x][y]);
		array<int, 3> sa = { c, x - 1, y };
		v.push_back(sa);
	}
	if ((y + 1) < 3) {
		swap(initialState[x][y + 1], initialState[x][y]);
		int c = heuristicFunction(initialState, finalState);
		swap(initialState[x][y + 1], initialState[x][y]);
		array<int, 3> sa = { c, x, y + 1 };
		v.push_back(sa);
	}
	if ((y - 1) >= 0) {
		swap(initialState[x][y - 1], initialState[x][y]);
		int c = heuristicFunction(initialState, finalState);
		swap(initialState[x][y - 1], initialState[x][y]);
		array<int, 3> sa = { c, x, y - 1 };
		v.push_back(sa);
	}
	sort(v.begin(), v.end());
	swap(initialState[x][y], initialState[v[0][1]][v[0][2]]);
	solve(cost + 1, initialState, finalState);
}

int main() {
	cout << "Enter the 8 puzzle problem in the form of 3 x 3 Matrix : ";

	vector<vector<int>> initialState(3, vector<int>(3, 0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> initialState[i][j];
		}
	}

	vector<vector<int>> finalState = { { 1, 2, 3 }, { 8, 0, 4 }, { 7, 6, 5 } };
	int cost = 0;

	cout << endl;

	cout << "--------------- TRACING SHORTEST PATH TO REACH THE FINAL "
			"STATE---------------------"
		 << endl;

	solve(cost, initialState, finalState);
	cout << endl;
	cout << "The cost of solving this problem is : " << ans << endl;
	cout << endl;
	return 0;
}