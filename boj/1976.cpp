#include <iostream>
using namespace std;
int parent[202];

int find_parent(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find_parent(parent[n]);
}

void union_parent(int x, int y) {
	int a = find_parent(x);
	int b = find_parent(y);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main(int argc, char *argv[])
{
	int n,m;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (num) 
					union_parent(i, j);
		}
	}

	// 여행 계획
	int num;
	cin >> num;
	int root = find_parent(num);

	for(int i = 1; i < m; i++) {
		cin >> num;
		if (root != find_parent(num)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}
