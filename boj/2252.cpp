#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;


bool visited[32001];

void print(const vector<int>& v) {
	cout << "vector===\n";
	for(auto& itr : v) {
		cout << itr << " ";
	}
	cout << endl;
}

void DFS(int cur, vector<vector<int>>& edges, forward_list<int>& lst) {
	visited[cur] = true;
	int outdegree = edges[cur].size();
	for(int i = 0; i < outdegree; i++) {
		int visit = edges[cur][i];
		if (!visited[visit])
			DFS(visit, edges, lst);
	}
	lst.push_front(cur);
}

auto  topological_sort(int n, vector<vector<int>>& edges) {
	forward_list<int> lst;
	for(int i = 1; i <= n; i++) {
		if (!visited[i])  {
			DFS(i, edges, lst);
		}
	}

	return lst;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> edges;
	for(int i = 0; i <= n; i++) {
		edges.emplace_back(vector<int>());
	}
	for(int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		edges[from].emplace_back(to);
	}
	auto result = topological_sort(n, edges);
	for(const auto& r : result) {
		cout << r << " ";
	}
	return 0;
}
