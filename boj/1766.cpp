#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

using indegree = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;

void print(vector<vector<int>> & v) {
	cout << "vector===\n";
	for(int i = 1; i <= v.size(); i++) {
		cout << i << ":";
		for(int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}	
		cout << endl;
	}
	cout << endl;
}

bool visited[32001]{0};

void dfs(vector<vector<int>>& v, queue<int>& lst, int cur) {
	visited[cur] = true;
	int outdegree = v[cur].size();
	for(int i = outdegree-1; i >= 0; i--) {
		if (!visited[v[cur][i]]) {
			dfs(v, lst, v[cur][i]);
		}
	}
	lst.push(cur);
}

auto topological_sort(vector<vector<int>>& v, indegree& pq) {
	queue<int> result;
	while (!pq.empty()) {
		auto [indegree, key] = pq.top();
		pq.pop();
		if (!visited[key]) {
			dfs(v, result, key);
		}
	}
	return result;
}

void print(const map<int, int>& m) {
	for(const auto& itr : m) {
		cout << "key:" << itr.first << ", value:" << itr.second << endl;
	}
}
void print(indegree pq) {
	cout << "queue status\n";
	while(!pq.empty()) {
		auto [a,b] = pq.top();
		pq.pop();
		cout << a << " " << b << endl;
	}
	cout << endl;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> v;
	map<int, int> indegrees;
	indegree  pq;
	for(int i = 0; i <= n; i++) {
		v.emplace_back(vector<int>());
		indegrees[i+1] = 0;
	}
	indegrees.erase(indegrees.find(n+1)); 
	while(m--) {
		int a, b;
		cin >> a >> b;
		// a번은 b번보다 먼저 풀어야함
		v[b].emplace_back(a);
		if (indegrees.find(a) == indegrees.end()) {
			indegrees[a] = 1;
		} else {
			indegrees[a]++;
		}
	}

	for(const auto& itr : indegrees) {
		pq.emplace(itr.second, itr.first);
	}

	print(pq);
	for(int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	auto result = topological_sort(v, pq);
	while(!result.empty()) {
		cout << result.front() << " ";
		result.pop();
	}
	return 0;
}
